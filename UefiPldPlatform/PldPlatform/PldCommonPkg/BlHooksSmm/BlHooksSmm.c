/** @file
  This module populates the communication area
  to pass info to payload, and registers a root
  SMI handler to clear APMC status.

  Copyright (c) 2014, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiSmm.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/HobLib.h>
#include <Protocol/SmmAccess2.h>
#include <Protocol/MpService.h>
#include <Guid/LoaderSmmInfoGuid.h>

#define SMRAM_SAVE_STATE_MAP_OFFSET           0xFC00  /// Save state offset from SMBASE
#define PLD_TO_LDR_SMM_SIG                    SIGNATURE_32('S', 'C', 'O', 'M')
#define BYTE_SIZE                             8

#pragma pack(1)
//
// Structure to share information with bootloader
//
typedef struct {
  UINT32  ApicId;
  UINT32  SmmBase;
} CPU_SMMBASE;

typedef struct {
  UINT32       Signature;
  UINT8        CpuEntry;  
  UINT8        Unused;
  UINT8        SmiCtrlRegType;
  UINT8        SmiCtrlRegWidth;
  UINT32       SmiCtrlRegAddr;
  UINT32       SmiCtrlRegVal;
  CPU_SMMBASE  SmmBase[];
} SMMBASE_INFO;
#pragma pack()

LOADER_SMM_INFO           mLdrSmmInfo;


/**
  Perform MMIO/IO clear ops on a given register

  @param[in]    RegType     MMIO/IO register
  @param[in]    RegWidth    Register width in bytes
  @param[in]    RegAddr     Address of the register
  @param[in]    BitPos      Bit position that has to be set/cleared/toggled
**/
VOID
SmiCtrlRegOpClear (
  IN  UINT8   RegType,
  IN  UINT8   RegWidth,
  IN  UINT32  RegAddr,
  IN  UINT8   BitPos
)
{
  switch (RegWidth) {
  case WIDE8:
    if (RegType == REG_TYPE_MEM) {
      MmioOr8 (RegAddr + (UINT32)RegWidth, BitPos);
    } else {
      IoOr8 (RegAddr + (UINT32)RegWidth, BitPos);
    }
    break;
  case WIDE16:
    if (RegType == REG_TYPE_MEM) {
      MmioOr16 (RegAddr + (UINT32)RegWidth, BitPos);
    } else {
      IoOr16 (RegAddr + (UINT32)RegWidth, BitPos);
    }
    break;
  case WIDE32:
    if (RegType == REG_TYPE_MEM) {
      MmioOr32 (RegAddr + (UINT32)RegWidth, BitPos);
    } else {
      IoWrite32 (RegAddr + (UINT32)RegWidth, BitPos);
    }
    break;
  }

}


/**
  Root handler for SMM Hooks.

  @retval EFI_SUCCESS             SMI handled successfully.
  @retval EFI_INTERRUPT_PENDING   SMI not handled.
**/
EFI_STATUS
EFIAPI
BlHooksSmmHandler (
  IN     EFI_HANDLE                                DispatchHandle,
  IN     CONST VOID                                *RegisterContext,
  IN OUT VOID                                      *CommBuffer,
  IN OUT UINTN                                     *CommBufferSize
  )
{
  //
  // Clear APMC Enable in SMI_STS register
  //
  SmiCtrlRegOpClear (mLdrSmmInfo.SmiCtrlReg.RegType,
                     mLdrSmmInfo.SmiCtrlReg.RegWidth,
                     mLdrSmmInfo.SmiCtrlReg.Address,
                     mLdrSmmInfo.SmiCtrlReg.SmiApmPos
                    );

  return EFI_SUCCESS;
}


/**
  The driver entry point for SMM Firmware Volume Block Driver.

  The function does the necessary initialization work 
  Firmware Volume Block Driver.

  @param[in]  ImageHandle       The firmware allocated handle for the UEFI image.
  @param[in]  SystemTable       A pointer to the EFI system table.

  @retval     EFI_SUCCESS       This funtion always return EFI_SUCCESS.
  @retval     EFI_UNSUPPORTED   Return EFI_UNSUPPORTED if no hob info from bootloader is passed

**/
EFI_STATUS
EFIAPI
BlHooksSmmEntryPoint (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_SMRAM_DESCRIPTOR        SmramRanges[8];
  EFI_STATUS                  Status;
  EFI_SMM_ACCESS2_PROTOCOL    *SmmAccess;
  UINTN                       Size;
  UINTN                       SmramRangeCount;
  EFI_PROCESSOR_INFORMATION   ProcessorInfo;
  EFI_MP_SERVICES_PROTOCOL    *MpService;
  UINTN                       Index;
  SMMBASE_INFO                *SmmInfo;
  EFI_HANDLE                  VariableHandle;
  LOADER_SMM_INFO             *LdrSmmInfo;
  EFI_HOB_GUID_TYPE           *GuidHob;

  //
  // Get SMRAM info HOB
  //
  LdrSmmInfo = NULL;
  GuidHob = GetFirstGuidHob (&gSmmInformationGuid);
  if (GuidHob != NULL) {
    LdrSmmInfo = (VOID *) (GET_GUID_HOB_DATA(GuidHob));
  } else {
    DEBUG ((EFI_D_ERROR, "SMM INFO payload is NULL."));
    return EFI_UNSUPPORTED;
  }

  //
  // Store in a global variable for availability in SMM
  //
  CopyMem (&mLdrSmmInfo, (VOID *)LdrSmmInfo, sizeof(LOADER_SMM_INFO));

  //
  // Get SMM Access Protocol
  //
  Status = gBS->LocateProtocol (&gEfiSmmAccess2ProtocolGuid, NULL, (VOID **)&SmmAccess);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  //
  // Get SMRAM range information
  //
  Size   = sizeof(SmramRanges);
  Status = SmmAccess->GetCapabilities (SmmAccess, &Size, SmramRanges);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  SmramRangeCount = Size / sizeof (EFI_SMRAM_DESCRIPTOR);
  for (Index = 0; Index < SmramRangeCount; Index++) {
    if (SmramRanges[Index].PhysicalSize == SIZE_4KB) {
      break;
    }
  }

  if (Index == SmramRangeCount) {
    DEBUG ((EFI_D_WARN, "Cound not find SMRAM Region for communication\n"));
    return EFI_SUCCESS;
  }

  SmmInfo = (SMMBASE_INFO *)(UINTN)SmramRanges[Index].PhysicalStart;
  DEBUG ((EFI_D_WARN, "MX SMBASE = %p\n", SmmInfo));

  //
  // Populate the communication area
  //
  SmmInfo->Signature        = PLD_TO_LDR_SMM_SIG;
  SmmInfo->CpuEntry         = (UINT8)gSmst->NumberOfCpus;
  SmmInfo->SmiCtrlRegType   = LdrSmmInfo->SmiCtrlReg.RegType;
  SmmInfo->SmiCtrlRegWidth  = LdrSmmInfo->SmiCtrlReg.RegWidth;
  SmmInfo->SmiCtrlRegAddr   = LdrSmmInfo->SmiCtrlReg.Address;
  SmmInfo->SmiCtrlRegVal    = LdrSmmInfo->SmiCtrlReg.SmiGblPos | LdrSmmInfo->SmiCtrlReg.SmiApmPos | LdrSmmInfo->SmiCtrlReg.SmiEosPos;

  //
  // Lookup the MP Services Protocol
  //
  Status = gBS->LocateProtocol (
                  &gEfiMpServiceProtocolGuid,
                  NULL,
                  (VOID **)&MpService
                  );
  if (EFI_ERROR(Status)) {
    return Status;
  }


  for (Index = 0; Index < gSmst->NumberOfCpus; Index++) {
    //
    // Get the APIC ID for the CPU specified by CpuIndex
    //
    Status = MpService->GetProcessorInfo (
               MpService,
               Index,
               &ProcessorInfo
               );
    if (EFI_ERROR(Status)) {
      return Status;
    }

    SmmInfo->SmmBase[Index].ApicId  = (UINT32)ProcessorInfo.ProcessorId;
    SmmInfo->SmmBase[Index].SmmBase = (UINT32)(UINTN)gSmst->CpuSaveState[Index] - SMRAM_SAVE_STATE_MAP_OFFSET;

    DEBUG ((EFI_D_INFO, "CPU%d ID:%02X Base: %08X\n", Index, SmmInfo->SmmBase[Index].ApicId, SmmInfo->SmmBase[Index].SmmBase));

  }

  //
  // Register root SMI handler for SMM hooks
  //
  VariableHandle = NULL;
  Status = gSmst->SmiHandlerRegister (BlHooksSmmHandler, NULL, &VariableHandle);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  return EFI_SUCCESS;
}

