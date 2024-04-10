/** @file
  This file defines the hob structure for the Flash Map entries.

  Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __TCG2_SUPPORT__
#define __TCG2_SUPPORT__

/**
  Make sure that the current PCR allocations, the TPM supported PCRs,
  and the PcdTpm2HashMask are all in agreement.
**/
VOID
BlSupportSyncPcrAllocationsAndPcrMask (
  VOID
  );

/**
  Set Firmware debugger status 
**/
VOID
SetFirmwareDebugPcd (
  UINT8 FwDebugInitialized
  );
#endif