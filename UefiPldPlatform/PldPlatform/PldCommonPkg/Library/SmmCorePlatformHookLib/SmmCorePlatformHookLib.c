/** @file
  Instance of SmmCorePlatformHookLib.

  Copyright (c) 2011 - 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiDxe.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/HobLib.h>
#include <Library/SmmCorePlatformHookLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Guid/LoaderSmmInfoGuid.h>

LOADER_SMM_INFO   *mSmmInfo     = NULL;

/**
  Performs platform specific tasks before invoking registered SMI handlers.

  This function performs platform specific tasks before invoking registered SMI handlers.

  @retval EFI_SUCCESS       The platform hook completes successfully.
  @retval Other values      The paltform hook cannot complete due to some error.

**/
EFI_STATUS
EFIAPI
PlatformHookBeforeSmmDispatch (
  VOID
  )
{
  return  EFI_SUCCESS;
}

/**
  Performs platform specific tasks after invoking registered SMI handlers.

  This function performs platform specific tasks after invoking registered SMI handlers.

  @retval EFI_SUCCESS       The platform hook completes successfully.
  @retval Other values      The paltform hook cannot complete due to some error.

**/
EFI_STATUS
EFIAPI
PlatformHookAfterSmmDispatch (
  VOID
  )
{
  EFI_STATUS           Status;
  EFI_HOB_GUID_TYPE    *GuidHob;
  LOADER_SMM_INFO      *LdrSmmInfo;

  if (mSmmInfo == NULL) {
    //
    // Get SMRAM info HOB
    //
    LdrSmmInfo = NULL;
    GuidHob = GetFirstGuidHob (&gSmmInformationGuid);
    if (GuidHob != NULL) {
      LdrSmmInfo = (VOID *) (GET_GUID_HOB_DATA(GuidHob));
      DEBUG ((DEBUG_INFO, "RegType   = 0x%x\n", LdrSmmInfo->SmiCtrlReg.RegType));
      DEBUG ((DEBUG_INFO, "RegWidth  = 0x%x\n", LdrSmmInfo->SmiCtrlReg.RegWidth));
      DEBUG ((DEBUG_INFO, "SmiGblPos = 0x%x\n", LdrSmmInfo->SmiCtrlReg.SmiGblPos));
      DEBUG ((DEBUG_INFO, "SmiApmPos = 0x%x\n", LdrSmmInfo->SmiCtrlReg.SmiApmPos));
      DEBUG ((DEBUG_INFO, "SmiEosPos = 0x%x\n", LdrSmmInfo->SmiCtrlReg.SmiEosPos));
      DEBUG ((DEBUG_INFO, "Address   = 0x%x\n", LdrSmmInfo->SmiCtrlReg.Address));
    }
    if ((GuidHob == NULL) || (LdrSmmInfo == NULL)) {
      return EFI_NOT_FOUND;
    }

    Status = gSmst->SmmAllocatePool (EfiRuntimeServicesData, sizeof(LOADER_SMM_INFO), (VOID **)&mSmmInfo);
    ASSERT_EFI_ERROR(Status);
    CopyMem (mSmmInfo, LdrSmmInfo, sizeof (LOADER_SMM_INFO));
  }

  //
  // Clear SMI status
  //
  if ((mSmmInfo->SmiStsReg.RegType == REG_TYPE_IO) && (mSmmInfo->SmiStsReg.RegWidth == WIDE32)) {
    if (mSmmInfo->SmiStsReg.Address != 0) {
      IoOr32 (mSmmInfo->SmiStsReg.Address, 0);
    }
  } else {
    DEBUG ((DEBUG_ERROR, "ERROR: not supported regtype (0x%x) or regwidth (0x%x)\n",\
      mSmmInfo->SmiStsReg.RegType, mSmmInfo->SmiStsReg.RegWidth));
  }

  //
  // Set EOS bit
  //
  if ((mSmmInfo->SmiCtrlReg.RegType == REG_TYPE_IO) && (mSmmInfo->SmiCtrlReg.RegWidth == WIDE32)) {
    IoOr32 (mSmmInfo->SmiCtrlReg.Address, 1 << mSmmInfo->SmiCtrlReg.SmiEosPos);
  } else {
    DEBUG ((DEBUG_ERROR, "ERROR: not supported regtype (0x%x) or regwidth (0x%x)\n",\
      mSmmInfo->SmiCtrlReg.RegType, mSmmInfo->SmiCtrlReg.RegWidth));
    return EFI_UNSUPPORTED;
  }

  return EFI_SUCCESS;
}
