/** @file
  This driver handles power button status.

  Copyright (c) 2014 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "PowerButtonHandler.h"

/**
  Timer handler to poll the key from serial.

  @param  Event                    Indicates the event that invoke this function.
  @param  Context                  Indicates the calling context.
**/
VOID
EFIAPI
PlatformTimerHandler (
  IN EFI_EVENT            Event,
  IN VOID                 *Context
  )
{
  UINTN             PmEvtReg;
  ACPI_BOARD_INFO   *pAcpiBoardInfo;

  pAcpiBoardInfo = (ACPI_BOARD_INFO *)Context;

  if (pAcpiBoardInfo == NULL) {
    return;
  }

  PmEvtReg  = (UINTN)pAcpiBoardInfo->PmEvtBase;
  
  //
  // Check PWRBTN status
  //
  if ((IoRead16 ((UINTN)pAcpiBoardInfo->PmEvtBase) & BIT8) != 0) {
    DEBUG ((DEBUG_INFO, "Power Button event was detected, shutting down the system !\n\n"));
    IoOr16 (PmEvtReg, BIT8);
    gRT->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL);
    CpuDeadLoop ();
  }  
}

/**
  Main entry for the power button handler module.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
PowerButtonEntry (
  IN EFI_HANDLE              ImageHandle,
  IN EFI_SYSTEM_TABLE        *SystemTable
  )
{
  EFI_STATUS          Status;
  EFI_EVENT           TimeoutEvt;
  EFI_HOB_GUID_TYPE  *GuidHob;
  ACPI_BOARD_INFO    *AcpiBoardInfoPtr;

  //
  // Find the acpi board information guid hob
  //
  GuidHob = GetFirstGuidHob (&gUefiAcpiBoardInfoGuid);
  if (GuidHob == NULL) {
    return EFI_NOT_FOUND;
  }

  AcpiBoardInfoPtr = (ACPI_BOARD_INFO *)GET_GUID_HOB_DATA (GuidHob);

  Status = gBS->CreateEvent (
                  EVT_TIMER | EVT_NOTIFY_SIGNAL,
                  TPL_NOTIFY,
                  PlatformTimerHandler,
                  AcpiBoardInfoPtr,
                  &TimeoutEvt
                  );
  if (EFI_ERROR(Status)) {
    return Status;
  }

  //
  // 100ms timer
  //
  Status = gBS->SetTimer (
                  TimeoutEvt,
                  TimerPeriodic,
                  POWER_BUTTON_EVENT_TIMEOUT
                  );
  if (EFI_ERROR(Status)) {
    return Status;
  }

  DEBUG ((DEBUG_INFO, "Successfully registered power button periodic timer event!\n"));

  return Status;
}

