/** @file
  HECI driver

@copyright
  INTEL CONFIDENTIAL
  Copyright 2007 - 2023 Intel Corporation.

  The source code contained or described herein and all documents related to the
  source code ("Material") are owned by Intel Corporation or its suppliers or
  licensors. Title to the Material remains with Intel Corporation or its suppliers
  and licensors. The Material may contain trade secrets and proprietary and
  confidential information of Intel Corporation and its suppliers and licensors,
  and is protected by worldwide copyright and trade secret laws and treaty
  provisions. No part of the Material may be used, copied, reproduced, modified,
  published, uploaded, posted, transmitted, distributed, or disclosed in any way
  without Intel's prior express written permission.

  No license under any patent, copyright, trade secret or other intellectual
  property right is granted to or conferred upon you by disclosure or delivery
  of the Materials, either expressly, by implication, inducement, estoppel or
  otherwise. Any license under such intellectual property rights must be
  express and approved by Intel in writing.

  Unless otherwise agreed by Intel in writing, you may not remove or alter
  this notice or any other notice embedded in Materials by Intel or
  Intel's suppliers or licensors in any way.

  This file contains an 'Intel Peripheral Driver' and is uniquely identified as
  "Intel Reference Module" and is licensed for Intel CPUs and chipsets under
  the terms of your license agreement with Intel or your vendor. This file may
  be modified by the user, subject to additional terms of the license agreement.

@par Specification Reference:
**/

#include <PiDxe.h>
#include <Base.h>
#include <Uefi.h>
#include <Guid/EventGroup.h>
#include <Guid/EventLegacyBios.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/PerformanceLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/PerformanceLib.h>
#include <Library/S3BootScriptLib.h>
#include <IndustryStandard/Pci22.h>
#include <Library/TimerLib.h>
#include <Library/HobLib.h>
#include <HeciInit.h>
#include <HeciInitLib.h>


//
// Global driver data
//
GLOBAL_REMOVE_IF_UNREFERENCED HECI_INSTANCE         *mHeciContext;

#define PostCode(x)  



/**
  Timer handler to poll the key from serial.

  @param  Event                    Indicates the event that invoke this function.
  @param  Context                  Indicates the calling context.
**/
VOID
EFIAPI
TerminalConInTimerHandler (
  IN EFI_EVENT            Event,
  IN VOID                 *Context
  )
{    
  if (IoRead16 (0x1800) & BIT8) {
    DEBUG ((DEBUG_ERROR, "PWRBTN1 = 0x%08X\n", IoRead32 (0x1800)));
    IoOr16 (0x1800, 0);
    DEBUG ((DEBUG_ERROR, "PWRBTN2 = 0x%08X\n", IoRead32 (0x1800)));
    IoOr16 (0x1804, 0x1C00);
    IoOr16 (0x1804, 0x3C00);
    CpuDeadLoop ();
  }
}


/**
  HECI driver entry point used to initialize support for the HECI device.

  @param[in] ImageHandle          Standard entry point parameter.
  @param[in] SystemTable          Standard entry point parameter.

  @retval EFI_SUCCESS             Always return EFI_SUCCESS
**/
EFI_STATUS
EFIAPI
InitializeHeci (
  IN EFI_HANDLE                   ImageHandle,
  IN EFI_SYSTEM_TABLE             *SystemTable
  )
{
  EFI_STATUS          Status;
  EFI_EVENT           ReadyToBootEvent;
  
  DEBUG ((DEBUG_INFO, "ME-BIOS: HECI Protocol Entry.\n"));
  PostCode (0xE04);

  mHeciContext        = AllocateZeroPool (sizeof (HECI_INSTANCE));
  ///
  /// Initialize HECI protocol pointers
  ///
  if (mHeciContext == NULL) {
    Status = EFI_OUT_OF_RESOURCES;
    DEBUG ((DEBUG_ERROR, "ME-BIOS: HECI Protocol Exit - Error by lack of memory for HECI_INSTANCE.\n"));
    PostCode (0xE84);
    goto ErrExit;
  }
  mHeciContext->HeciCtlr.ResetHeci    = ResetHeciInterface;
  mHeciContext->HeciCtlr.SendwAck     = HeciSendwAck;
  mHeciContext->HeciCtlr.ReadMsg      = HeciReceive;
  mHeciContext->HeciCtlr.SendMsg      = HeciSend;
  mHeciContext->HeciCtlr.InitHeci     = HeciInitialize;
  mHeciContext->HeciCtlr.ReInitHeci   = HeciReInitialize;
  mHeciContext->HeciCtlr.MeResetWait  = MeResetWait;
  mHeciContext->HeciCtlr.GetMeStatus  = HeciGetMeStatus;
  mHeciContext->HeciCtlr.GetMeMode    = HeciGetMeMode;

  ///
  /// Initialize the HECI device
  ///
  Status = HeciInitialize (HECI1_DEVICE);  
  if (EFI_ERROR (Status)) {
    ///
    /// Don't install on ERR
    ///
    DEBUG ((DEBUG_ERROR, "ME-BIOS: HECI Protocol Exit - Error by HeciInitialize fail, Status: %r\n", Status));
    PostCode (0xEA4);
    goto ErrExit;
  }

  ///
  /// Install the HECI interface
  ///
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &mHeciContext->Handle,
                  &gHeciProtocolGuid,
                  &mHeciContext->HeciCtlr,
                  NULL
                  );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "ME-BIOS: HECI Protocol Exit - Error by install HECI protocol fail, Status: %r\n", Status));
    PostCode (0xEC4);
    goto ErrExit;
  }


  //
  // Register callback on the ready to boot event
  //
  ReadyToBootEvent = NULL;
  Status = EfiCreateEventReadyToBootEx (
                    TPL_CALLBACK,
                    OnMeEndOfPostEvent,
                    NULL,
                    &ReadyToBootEvent
                    );
  ASSERT_EFI_ERROR (Status);

      
ErrExit:
  return Status;
}
