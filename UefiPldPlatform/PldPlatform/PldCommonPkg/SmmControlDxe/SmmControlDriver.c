/** @file
  This module produces the SMM COntrol2 Protocol
  
  Copyright (c) 2014 - 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/


#include <PiDxe.h>
#include <Protocol/SmmControl2.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/PcdLib.h>
#include <Library/IoLib.h>
#include <Library/HobLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Guid/LoaderSmmInfoGuid.h>
#include <Protocol/DxeSmmReadyToLock.h>
#include <Library/PciLib.h>

///
/// Handle for the SMM Control2 Protocol
///
EFI_HANDLE      mSmmControl2Handle = NULL;
SMI_CTRL_REG    mSmiCtrlReg;

#define SMM_DATA_PORT       0xB3
#define SMM_CONTROL_PORT    0xB2

/**
  Enables the PCH to generate SMIs.

  @retval EFI_SUCCESS              Enable Global Smi Bit completed
  @retval EFI_UNSUPPORTED          SMM reg type or reg width is not supported.
**/
EFI_STATUS 
ScSmmEnableGlobalSmiBit (
  VOID
  )
{
  UINT32  SmiEn;

  if ((mSmiCtrlReg.RegType != REG_TYPE_IO) || (mSmiCtrlReg.RegWidth != WIDE32)) {
    DEBUG ((DEBUG_INFO, "ERROR: not supported regtype (0x%x) or regwidth (0x%x)\n",\
      mSmiCtrlReg.RegType, mSmiCtrlReg.RegWidth));
    return EFI_UNSUPPORTED;
  }

  SmiEn = IoRead32 (mSmiCtrlReg.Address);
  if (((SmiEn & (1 << mSmiCtrlReg.SmiGblPos)) !=0) && ((SmiEn & (1 << mSmiCtrlReg.SmiApmPos)) !=0)) {
    return EFI_SUCCESS;
  }

  //
  // Set the "global SMI enable" bit and APM bit
  //
  SmiEn |= (1 << mSmiCtrlReg.SmiGblPos) | (1 << mSmiCtrlReg.SmiApmPos);
  IoWrite32 (mSmiCtrlReg.Address, SmiEn);

  return EFI_SUCCESS;
}

/**
  Generates an SMI using the parameters passed in.

  @param  This                A pointer to an instance of
                              EFI_SMM_CONTROL_PROTOCOL
  @param  ArgumentBuffer      The argument buffer
  @param  ArgumentBufferSize  The size of the argument buffer
  @param  Periodic            TRUE to indicate a periodical SMI
  @param  ActivationInterval  Interval of the periodical SMI

  @retval EFI_INVALID_PARAMETER  Periodic is TRUE or ArgumentBufferSize > 1
  @retval EFI_SUCCESS            SMI generated

**/
EFI_STATUS
EFIAPI
Activate (
  IN CONST EFI_SMM_CONTROL2_PROTOCOL     *This,
  IN OUT  UINT8                          *CommandPort       OPTIONAL,
  IN OUT  UINT8                          *DataPort          OPTIONAL,
  IN      BOOLEAN                        Periodic           OPTIONAL,
  IN      EFI_SMM_PERIOD                 ActivationInterval OPTIONAL
  )
{
  ScSmmEnableGlobalSmiBit ();

  if (Periodic) {
    return EFI_INVALID_PARAMETER;
  }
  
  //
  // Set APMC data before Generate the APMC SMI
  //
  IoWrite8 (SMM_DATA_PORT,    DataPort    == NULL ? 0 : *DataPort);
  IoWrite8 (SMM_CONTROL_PORT, CommandPort == NULL ? 0 : *CommandPort);
  return EFI_SUCCESS;
}

/**
  Clears an SMI.

  @param  This      Pointer to an instance of EFI_SMM_CONTROL_PROTOCOL
  @param  Periodic  TRUE to indicate a periodical SMI

  @return Return value from SmmClear ()

**/
EFI_STATUS
EFIAPI
Deactivate (
  IN CONST EFI_SMM_CONTROL2_PROTOCOL     *This,
  IN       BOOLEAN                       Periodic
  )
{
  if (Periodic) {
    return EFI_INVALID_PARAMETER;
  }

  DEBUG ((DEBUG_INFO, "   Smi Deactivate...\n"));

  //
  // Temporarily do nothing here
  //
  return EFI_SUCCESS;
}

///
/// SMM COntrol2 Protocol instance
///
EFI_SMM_CONTROL2_PROTOCOL mSmmControl2 = {
  Activate,
  Deactivate,
  0
};


/**
  Lock SMI in this SMM ready to lock event.

  @param  Event   Pointer to this event
  @param  Context Event hanlder private data
 **/
VOID
EFIAPI
SmmControlReadyToLockCallBack (
  IN EFI_EVENT           Event,
  IN VOID                *Context
  )
{
  EFI_STATUS             Status;
  VOID                   *Interface;
  EFI_HOB_GUID_TYPE      *GuidHob;
  LOADER_SMM_INFO        *LdrSmmInfo;
  SMI_LOCK_REG           *SmiLockReg;

  //
  // Try to locate it because EfiCreateProtocolNotifyEvent will trigger it once when registration.
  // Just return if it is not found.
  //
  Status = gBS->LocateProtocol (&gEfiDxeSmmReadyToLockProtocolGuid, NULL, &Interface);
  if (EFI_ERROR (Status)) {
    return ;
  }

  //
  // Set SMM SMI lock
  //
  GuidHob = GetFirstGuidHob (&gSmmInformationGuid);
  if (GuidHob != NULL) {
    LdrSmmInfo = (VOID *) (GET_GUID_HOB_DATA(GuidHob));
    SmiLockReg = &LdrSmmInfo->SmiLockReg;
    if (((SmiLockReg->RegType != REG_TYPE_MMIO) && (SmiLockReg->RegType != REG_TYPE_PCICFG)) || (SmiLockReg->RegWidth != WIDE32)) {
        DEBUG ((DEBUG_ERROR, "ERROR: not supported SMI lock regtype (0x%x) or regwidth (0x%x)\n",\
        SmiLockReg->RegType, SmiLockReg->RegWidth));
    } else {
      if (SmiLockReg->Address != 0) {
        DEBUG ((DEBUG_INFO, "SMI LOCK is set.\n"));
        if(SmiLockReg->RegType == REG_TYPE_MMIO) {
          MmioOr32 (SmiLockReg->Address, 1 << SmiLockReg->SmiLockPos);
        } else if (SmiLockReg->RegType == REG_TYPE_PCICFG) {
          PciOr32(SmiLockReg->Address, 1 << SmiLockReg->SmiLockPos);
        }
      }
    }
  }

  gBS->CloseEvent (Event);
}


/**
  This is the constructor for the SMM Control protocol.

  This function installs EFI_SMM_CONTROL2_PROTOCOL.

  @param  ImageHandle Handle for the image of this driver
  @param  SystemTable Pointer to the EFI System Table

  @retval EFI_UNSUPPORTED There's no Intel ICH on this platform
  @return The status returned from InstallProtocolInterface().

**/
EFI_STATUS
EFIAPI
SmmControl2Init (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS           Status;
  EFI_HOB_GUID_TYPE    *GuidHob;
  LOADER_SMM_INFO      *LdrSmmInfo;
  VOID                 *Registration;
  EFI_EVENT            Event;

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
    CopyMem (&mSmiCtrlReg, &LdrSmmInfo->SmiCtrlReg, sizeof (mSmiCtrlReg));
  }
  ASSERT (LdrSmmInfo != NULL);

  //
  // Install our protocol interfaces on the device's handle
  //
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &mSmmControl2Handle,
                  &gEfiSmmControl2ProtocolGuid,  &mSmmControl2,
                  NULL
                  );
  ASSERT_EFI_ERROR (Status);

  //
  // Register SMM ready to lock callback
  //
  Event = EfiCreateProtocolNotifyEvent  (
            &gEfiDxeSmmReadyToLockProtocolGuid,
            TPL_CALLBACK,
            SmmControlReadyToLockCallBack,
            NULL,
            &Registration
            );
  ASSERT (Event != NULL);

  return Status;
}

