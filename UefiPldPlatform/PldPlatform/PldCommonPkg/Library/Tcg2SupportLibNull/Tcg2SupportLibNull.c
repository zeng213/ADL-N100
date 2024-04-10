/** @file
  TPM support library for bootloader NULL implementation.

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Library/DebugLib.h>
#include <Library/Tcg2SupportLib.h>

/**
  Make sure that the current PCR allocations, the TPM supported PCRs,
  and the PcdTpm2HashMask are all in agreement.
**/
VOID
BlSupportSyncPcrAllocationsAndPcrMask (
  VOID
  )
{
  
}


/**
  Set Firmware debugger status
**/
VOID
SetFirmwareDebugPcd (
  UINT8 FwDebugInitialized
  )
{

}
