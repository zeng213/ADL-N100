/** @file
  TPM support library for bootloader.

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <PiPei.h>


#include <Guid/TcgEventHob.h>
#include <Guid/TpmInstance.h>
#include <Library/DebugLib.h>
#include <Library/Tpm2CommandLib.h>
#include <Library/Tpm2DeviceLib.h>
#include <Library/PcdLib.h>
#include <Protocol/Tcg2Protocol.h>
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
  EFI_STATUS                        Status;
  EFI_TCG2_EVENT_ALGORITHM_BITMAP   TpmHashAlgorithmBitmap;
  UINT32                            TpmActivePcrBanks;
  UINT32                            Tpm2PcrMask;
  UINT32                            NewTpm2PcrMask;

  DEBUG ((EFI_D_ERROR, "SyncPcrAllocationsAndPcrMask!\n"));


  //
  // Initialize TPM device
  //
  Status = Tpm2RequestUseTpm ();
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "TPM2 not detected!\n"));
    return;
  }

  //
  // Determine the current TPM support and the Platform PCR mask.
  //
  Status = Tpm2GetCapabilitySupportedAndActivePcrs (&TpmHashAlgorithmBitmap, &TpmActivePcrBanks);
  ASSERT_EFI_ERROR (Status);

  Tpm2PcrMask = PcdGet32 (PcdTpm2HashMask);
  if (Tpm2PcrMask == 0) {
    //
    // if PcdTPm2HashMask is zero, use ActivePcr setting
    //
    PcdSet32S (PcdTpm2HashMask, TpmActivePcrBanks);
    Tpm2PcrMask = TpmActivePcrBanks;
  }

  //
  // If there are any PCRs that claim support in the Platform mask that are
  // not supported by the TPM, update the mask.
  //
  if ((Tpm2PcrMask & TpmHashAlgorithmBitmap) != Tpm2PcrMask) {
    NewTpm2PcrMask = Tpm2PcrMask & TpmHashAlgorithmBitmap;

    DEBUG ((EFI_D_INFO, "%a - Updating PcdTpm2HashMask from 0x%X to 0x%X.\n", __FUNCTION__, Tpm2PcrMask, NewTpm2PcrMask));
    if (NewTpm2PcrMask == 0) {
      DEBUG ((EFI_D_ERROR, "%a - No viable PCRs supported! Please set a less restrictive value for PcdTpm2HashMask!\n", __FUNCTION__));
      ASSERT (FALSE);
    }

    Status = PcdSet32S (PcdTpm2HashMask, NewTpm2PcrMask);
    ASSERT_EFI_ERROR (Status);
  }
}


/**
  Set Firmware debugger status 
**/
VOID
SetFirmwareDebugPcd (
  UINT8 FwDebugInitialized
  )
{
  // Check if Firmware Deugger mode enabled
  if(FwDebugInitialized) {
    //
    // Extend platform state into TPM PCR[7]
    //
    PcdSetBoolS (PcdFirmwareDebuggerInitialized, TRUE);
  }
}
