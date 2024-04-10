/** @file
  Software SMI handler implementation for bootloader.

  Copyright (c) 2011 - 2020, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#include <PiDxe.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/HobLib.h>
#include <Library/MtrrLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/PciLib.h>
#include <Guid/LoaderSmmInfoGuid.h>
#include <Protocol/SmmSwDispatch2.h>
#include <Protocol/SmmAccess2.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BlSmmCommunicationLib.h>
#include <Register/Intel/ArchitecturalMsr.h>

#define  EFI_MSR_SMRR_MASK           0xFFFFF000
#define  MSR_SMM_FEATURE_CONTROL     0x4E0

typedef struct {
  UINT32  Base;
  UINT32  Mask;
} SMRR_BASE_MASK;

LOADER_SMM_INFO   *mSmmInfo          = NULL;
UINT64            mSmmFeatureControl = 0;

/**
  Function to program SMRR base and mask.

  @param[in] ProcedureArgument  Pointer to SMRR_BASE_MASK structure.
**/
VOID
EFIAPI
ReprogramSmrrOnS3 (
  IN VOID  *ProcedureArgument
  )
{
  SMRR_BASE_MASK   *Input;
  Input = (SMRR_BASE_MASK *)ProcedureArgument;

  if (Input != NULL) {
    AsmWriteMsr64 (MSR_IA32_SMRR_PHYSBASE, Input->Base);
    AsmWriteMsr64 (MSR_IA32_SMRR_PHYSMASK, Input->Mask);
  }
}

/**
  Software SMI callback for restoring SMRR base and mask in S3 path.

  @param[in]      DispatchHandle  The unique handle assigned to this handler by SmiHandlerRegister().
  @param[in]      Context         Points to an optional handler context which was specified when the
                                  handler was registered.
  @param[in, out] CommBuffer      A pointer to a collection of data in memory that will
                                  be conveyed from a non-SMM environment into an SMM environment.
  @param[in, out] CommBufferSize  The size of the CommBuffer.

  @retval EFI_SUCCESS             The interrupt was handled successfully.

**/
EFI_STATUS
EFIAPI
BlSwSmiHandler (
  IN EFI_HANDLE                  DispatchHandle,
  IN CONST VOID                  *Context,
  IN OUT VOID                    *CommBuffer,
  IN OUT UINTN                   *CommBufferSize
  )
{
  EFI_STATUS            Status;
  SMRR_BASE_MASK        Arguments;
  UINTN                 Index;
  SMI_LOCK_REG          *SmiLockReg;

  if ((AsmReadMsr64 (MSR_IA32_SMRR_PHYSBASE) == 0) || ((AsmReadMsr64 (MSR_IA32_SMRR_PHYSMASK) & BIT11) == 0)) {

    if (mSmmInfo->SmmBase == 0) {
      return EFI_UNSUPPORTED;
    }

    //
    // SMRR size cannot be less than 4-KBytes
    // SMRR size must be of length 2^n
    // SMRR base alignment cannot be less than SMRR length
    //
    if ((mSmmInfo->SmmSize < SIZE_4KB) ||
        (mSmmInfo->SmmSize != GetPowerOfTwo32 (mSmmInfo->SmmSize)) ||
        ((mSmmInfo->SmmBase & ~(mSmmInfo->SmmSize - 1)) != mSmmInfo->SmmBase)) {
      return EFI_UNSUPPORTED;
    }
    //
    // Calculate smrr base, mask and pass them as arguments.
    //
    Arguments.Base = (mSmmInfo->SmmBase | MTRR_CACHE_WRITE_BACK);
    Arguments.Mask = (~(mSmmInfo->SmmSize - 1) & EFI_MSR_SMRR_MASK);

    //
    // Set SMRR valid bit
    //
    Arguments.Mask |= BIT11;

    //
    // Program smrr base and mask on BSP first.
    //
    ReprogramSmrrOnS3(&Arguments);
    for (Index = 0; Index < gSmst->NumberOfCpus; Index++) {
      if (Index != gSmst->CurrentlyExecutingCpu) {
        //
        // Call SmmStartupThisAp() to program SMRR on an AP.
        //
        Status = gSmst->SmmStartupThisAp (ReprogramSmrrOnS3, Index, (VOID *)&Arguments);
        if (EFI_ERROR(Status)) {
          DEBUG ((DEBUG_INFO, "Programming SMRR base on AP# %d failed with status: %r\n", Index, Status));
        }
      }
    }
  }

  if (mSmmFeatureControl == 0) {
    mSmmFeatureControl = AsmReadMsr64(MSR_SMM_FEATURE_CONTROL);
    if ((mSmmFeatureControl & 0x5) != 0x5) {
      //
      // Set Lock bit [BIT0] for this register and SMM code check enable bit [BIT2]
      //
      AsmWriteMsr64 (MSR_SMM_FEATURE_CONTROL, mSmmFeatureControl | 0x5);
    }
    mSmmFeatureControl = AsmReadMsr64(MSR_SMM_FEATURE_CONTROL);
  }

  //
  // Set SMM SMI lock in S3 path
  //
  SmiLockReg = &mSmmInfo->SmiLockReg;
  if ((SmiLockReg->RegWidth == WIDE32) && (SmiLockReg->Address != 0)) {
    if(SmiLockReg->RegType == REG_TYPE_MMIO) {
      MmioOr32 (SmiLockReg->Address, 1 << SmiLockReg->SmiLockPos);
    } else if (SmiLockReg->RegType == REG_TYPE_PCICFG) {
      PciOr32(SmiLockReg->Address, 1 << SmiLockReg->SmiLockPos);
    }
  }

  return EFI_SUCCESS;
}

/**
  The driver's entry point.

  It install callbacks for bootloader sw smi

  @param[in] ImageHandle  The firmware allocated handle for the EFI image.
  @param[in] SystemTable  A pointer to the EFI System Table.

  @retval EFI_SUCCESS     The entry point is executed successfully.
  @retval Others          Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
InitializeBlSwSmi (
  IN EFI_HANDLE                  ImageHandle,
  IN EFI_SYSTEM_TABLE            *SystemTable
  )
{
  EFI_STATUS                     Status;
  EFI_SMM_SW_DISPATCH2_PROTOCOL  *SwDispatch;
  EFI_SMM_SW_REGISTER_CONTEXT    SwContext;
  EFI_HANDLE                     SwHandle;
  LOADER_SMM_INFO                *LdrSmmInfo;
  EFI_HOB_GUID_TYPE              *GuidHob;
  BL_SMM_COMMUNICATION_INFO      BlSmmCommInfo;
  BL_SW_SMI_INFO                 BlSwSmi;

  //
  // Get Loader smm info hob and copy it for in SMM use.
  //
  LdrSmmInfo = NULL;
  GuidHob = GetFirstGuidHob (&gSmmInformationGuid);
  if (GuidHob != NULL) {
    LdrSmmInfo = (VOID *) (GET_GUID_HOB_DATA(GuidHob));
  } else {
    return EFI_NOT_FOUND;
  }

  //
  // Get the Sw dispatch protocol and register SMI callback functions.
  //
  Status = gSmst->SmmLocateProtocol (&gEfiSmmSwDispatch2ProtocolGuid, NULL, (VOID**)&SwDispatch);
  if (EFI_ERROR (Status)) {
    return Status;
  }

  Status = gSmst->SmmAllocatePool (EfiRuntimeServicesData, sizeof(LOADER_SMM_INFO), (VOID **)&mSmmInfo);
  if (EFI_ERROR (Status)) {
    return Status;
  }
  CopyMem (mSmmInfo, LdrSmmInfo, sizeof (LOADER_SMM_INFO));

  //
  // Sw SMI dispatcher will assign the sw smi number
  //
  SwContext.SwSmiInputValue = (UINTN) -1;

  Status = SwDispatch->Register (SwDispatch, BlSwSmiHandler, &SwContext, &SwHandle);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Registering software smi handler for bootloader failed with status: %r\n", Status));
    return Status;
  }

  Status = GetBlCommArea (&BlSmmCommInfo);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Finding bootloader communication buffer failed with status: %r\n", Status));
    return Status;
  }

  BlSwSmi.BlSwSmiHdr.Signature = BL_PLD_COMM_SIG;
  BlSwSmi.BlSwSmiHdr.Id = BL_SW_SMI_COMM_ID;
  BlSwSmi.BlSwSmiHdr.Count = 1;
  BlSwSmi.BlSwSmiHdr.TotalSize = sizeof(BL_SW_SMI_INFO);
  BlSwSmi.BlSwSmiHandlerInput = (UINT8)SwContext.SwSmiInputValue;

  Status = SetBlCommData (&BlSmmCommInfo, (VOID *)&BlSwSmi);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Adding data to communication buffer failed with status: %r\n", Status));
    return Status;
  }

  return EFI_SUCCESS;
}

