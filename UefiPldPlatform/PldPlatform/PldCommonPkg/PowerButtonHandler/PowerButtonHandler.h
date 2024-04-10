/** @file
  Header file for power button status handler module.

  Copyright (c) 2014 - 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __POWER_BUTTON_HANDLER_H__
#define __POWER_BUTTON_HANDLER_H__

#include <Uefi.h>

#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/IoLib.h>
#include <Library/HobLib.h>
#include <Guid/AcpiBoardInfoGuid.h>

//
// 100 milliseconds
//
#define POWER_BUTTON_EVENT_TIMEOUT  EFI_TIMER_PERIOD_MILLISECONDS(100)

#endif

