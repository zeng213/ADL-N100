/** @file
  This module populates the communication area to pass info to payload.

  Copyright (c) 2019-2021, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiSmm.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Protocol/SmmAccess2.h>
#include <Protocol/MpService.h>
#include <Library/HobLib.h>
#include <Guid/LoaderSmmInfoGuid.h>
#include <Library/BlSmmCommunicationLib.h>

#if __GNUC__
typedef UINT32 EFIAPI (*REG_READ)  (IN UINTN);
#else
typedef UINT32 (*REG_READ)  (UINTN);
#endif

#define SMRAM_SAVE_STATE_MAP_OFFSET     0xFC00  /// Save state offset from SMBASE
#define SMM_BASE_INFO_SIG               SIGNATURE_32('S', 'C', 'O', 'M')
#define S3_SAVE_REG_SIG                 SIGNATURE_32('S', '3', 'S', 'R')

#define NUM_TYPE    2
#define NUM_WIDTH   3

const REG_READ mRegRead[NUM_TYPE][NUM_WIDTH] = {
  { (REG_READ) MmioRead8, (REG_READ) MmioRead16, (REG_READ) MmioRead32 },
  { (REG_READ) IoRead8, (REG_READ) IoRead16, (REG_READ) IoRead32 }
};

const UINT8 mWidthToIdx[NUM_WIDTH][2] = {
  { 0, WIDE8  },
  { 1, WIDE16 },
  { 2, WIDE32 }
};

/**
  Save regisder values for S3 purpose.

  The RegInfo like Address, Type, and Width are already
  populated by the bootloader. Here, only Value is updated
  to be used by bootloader in S3 resume path. 

  @param[in] BlSmmCommInfo Pointer to Bootloader smm communication info structure

  @retval     EFI_SUCCESS       Save reg Value success.
  @retval     EFI_NOT_FOUND     RegInfo not populated by bootloader
  @retval     EFI_UNSUPPORTED   Unsupported register
**/
EFI_STATUS
SaveRegforS3 (
  IN  BL_SMM_COMMUNICATION_INFO *BlSmmCommInfo
  )
{
  UINT8         Idx;
  UINT8         WidthIdx;
  S3_SAVE_REG   *S3SaveReg;
  UINT8         Type;
  UINT8         Width;

  S3SaveReg = (S3_SAVE_REG *) GetBlCommData (BlSmmCommInfo, S3_SAVE_REG_COMM_ID);

  if (S3SaveReg == NULL || S3SaveReg->S3SaveHdr.Id != S3_SAVE_REG_COMM_ID) {
    return EFI_NOT_FOUND;
  }

  for (Idx = 0; Idx < S3SaveReg->S3SaveHdr.Count; Idx++) {
    Type = S3SaveReg->RegInfo[Idx].Type;
    Width = S3SaveReg->RegInfo[Idx].Width;
    for (WidthIdx = 0; WidthIdx < NUM_WIDTH; WidthIdx++) {
      if (mWidthToIdx[WidthIdx][1] == Width) {
        Width = mWidthToIdx[WidthIdx][0];
        break;
      }
    }
    if (Type >= NUM_TYPE || Width >= NUM_WIDTH) {
      return EFI_INVALID_PARAMETER;
    }
    S3SaveReg->RegInfo[Idx].Val = mRegRead[Type][Width] (S3SaveReg->RegInfo[Idx].Addr);
  }

  return EFI_SUCCESS;
}

/**
  Save SMM rebase information to SMM communication region.

  The function detects SMM communication region for boot loader, if it is detected, it
  will save SMM rebase information to SMM communication region. Bootloader should consume
  these information in S3 path to restore smm base.

  @retval     EFI_SUCCESS       Save SMM rebase information success.
  @retval     Others            Failed to save SMM information.
**/
EFI_STATUS
SaveSmmInfo (
  VOID
  )
{
  EFI_STATUS                       Status;
  EFI_PROCESSOR_INFORMATION        ProcessorInfo;
  EFI_MP_SERVICES_PROTOCOL         *MpService;
  SMMBASE_INFO                     *SmmBaseInfo;
  BL_SMM_COMMUNICATION_INFO        BlSmmCommInfo;
  UINTN                            Index;

  Status = GetBlCommArea (&BlSmmCommInfo);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  SmmBaseInfo = (SMMBASE_INFO *) GetBlCommData (&BlSmmCommInfo, SMMBASE_INFO_COMM_ID);
  if (SmmBaseInfo == NULL) {
    return EFI_NOT_FOUND;
  }
  DEBUG ((DEBUG_INFO, "SMMBASE_INFO = %p\n", SmmBaseInfo));

  //
  // Save APIC ID and SMM base
  //
  Status = gBS->LocateProtocol (&gEfiMpServiceProtocolGuid, NULL, (VOID **)&MpService);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  for (Index = 0; Index < gSmst->NumberOfCpus; Index++) {
    Status = MpService->GetProcessorInfo (MpService, Index, &ProcessorInfo);
    if (EFI_ERROR(Status)) {
      return Status;
    }

    SmmBaseInfo->SmmBase[Index].ApicId  = (UINT32)ProcessorInfo.ProcessorId;
    SmmBaseInfo->SmmBase[Index].SmmBase = (UINT32)(UINTN)gSmst->CpuSaveState[Index] - SMRAM_SAVE_STATE_MAP_OFFSET;
    DEBUG ((EFI_D_INFO, "CPU%d ID:%02X Base: %08X\n", Index, SmmBaseInfo->SmmBase[Index].ApicId,
      SmmBaseInfo->SmmBase[Index].SmmBase));
  }

  Status = SaveRegforS3 (&BlSmmCommInfo);
  if (EFI_ERROR(Status)) {
      return Status;
  }

  return EFI_SUCCESS;
}

