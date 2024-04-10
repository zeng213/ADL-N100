/** @file
  SMM SwDispatch2 Protocol.

  Copyright (c) 2010 - 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _SMM_SW_DISPATCH2_H
#define _SMM_SW_DISPATCH2_H

#include <PiDxe.h>
#include <Protocol/SmmSwDispatch2.h>
#include <Protocol/SmmCpu.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>

#define SMI_SW_HANDLER_SIGNATURE  SIGNATURE_32('s','s','w','h')
#define MAXIMUM_SWI_VALUE         0xFF

typedef struct {
  UINTN                          Signature;
  LIST_ENTRY                     Link;
  EFI_HANDLE                     DispatchHandle;
  UINTN                          SwSmiInputValue;
  UINTN                          DispatchFunction;
} EFI_SMM_SW_DISPATCH2_CONTEXT;

#endif

