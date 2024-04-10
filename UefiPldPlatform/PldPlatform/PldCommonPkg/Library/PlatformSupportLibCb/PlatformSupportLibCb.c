/** @file
  Include all platform specific features which can be customized by IBV/OEM.

Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "PlatformSupportLibCb.h"

/**
  Find coreboot record with given Tag.

  @param  Tag                The tag id to be found

  @retval NULL              The Tag is not found.
  @retval Others            The poiter to the record found.

**/
VOID *
PlatformFindCbTag (
  IN  UINT32         Tag
  )
{
  struct cb_header   *Header;
  struct cb_record   *Record;
  UINT8              *TmpPtr;
  UINT8              *TagPtr;
  UINTN              Idx;

  Header = (struct cb_header *) GetParameterBase ();

  TagPtr = NULL;
  TmpPtr = (UINT8 *)Header + Header->header_bytes;
  for (Idx = 0; Idx < Header->table_entries; Idx++) {
    Record = (struct cb_record *)TmpPtr;
    if (Record->tag == Tag) {
      TagPtr = TmpPtr;
      break;
    }
    TmpPtr += Record->size;
  }

  return TagPtr;
}


/**
  Find the FSP information from coreboot.

  @param[out]  LdrFspInfo        ointer to the FSP information.

  @retval RETURN_SUCCESS     Successfully find the FSP information.
  @retval RETURN_NOT_FOUND   Failed to find the FSP information .

**/
RETURN_STATUS
ParseFspInfo (
  OUT LOADER_FSP_INFO      *LdrFspInfo
  )
{
  struct cb_fsp_info    *CbFspInfo;

  CbFspInfo = PlatformFindCbTag (CB_TAG_FSP_INFO);
  if (CbFspInfo == NULL) {
    DEBUG ((EFI_D_ERROR, "  NOT find FSP information from coreboot table\n"));
    return EFI_NOT_FOUND;
  }
  LdrFspInfo->VerifiedBoot = CbFspInfo->verified_boot;
  LdrFspInfo->MeasuredBoot = CbFspInfo->measure_boot;
  LdrFspInfo->FspsBase     = CbFspInfo->fsps_base;
  LdrFspInfo->FspHobList   = CbFspInfo->HobList;

  return EFI_SUCCESS;
}


/**
  Acquire the SMM information

  @param[out]  LdrSmmInfo    Pointer to SMM information

  @retval RETURN_SUCCESS     Successfully find out the memory table.
  @retval RETURN_INVALID_PARAMETER  Invalid input parameters.
  @retval RETURN_NOT_FOUND   Failed to find the memory table.

**/
RETURN_STATUS
EFIAPI
ParseSmmInfo (
  OUT LOADER_SMM_INFO           *LdrSmmInfo
  )
{
  struct cb_smm_region          *CbSmm;

  CbSmm = PlatformFindCbTag (CB_TAG_SMM_REGION);
  if (CbSmm == NULL) {
    DEBUG ((EFI_D_ERROR, "NOT SMRAM region info from coreboot table\n"));
    return RETURN_NOT_FOUND;
  }

  LdrSmmInfo->SmmBase = CbSmm->smm_base;
  LdrSmmInfo->SmmSize = CbSmm->smm_size;

  return RETURN_SUCCESS;
}


/**
  Find the Measured Boot Eventlog from coreboot.

  @param  TpmEventLog        Pointer to Tpm Event Log.

  @retval RETURN_SUCCESS     Successfully find the Event Log.
  @retval RETURN_NOT_FOUND   Failed to find the Event Log .

**/
RETURN_STATUS
ParseTpmEventLog (
  OUT TPM_EVENT_LOG_INFO    *TpmEventLog
  )
{
  struct cb_mb_event_log    *CbEvtLog;

  CbEvtLog = PlatformFindCbTag (CB_TAG_MB_EVENT_LOG);
  if (CbEvtLog == NULL) {
    DEBUG ((EFI_D_ERROR, "  NOT find Measured Boot Eventlog from coreboot table\n"));
    return EFI_NOT_FOUND;
  }

  TpmEventLog->Revision      = 0;
  TpmEventLog->Tcg12Lasa    = CbEvtLog->tcg1_2_lasa;
  TpmEventLog->Tcg12LastEvt = CbEvtLog->tcg1_2_last_evt;
  TpmEventLog->Tcg2Lasa     = CbEvtLog->tcg2_lasa;
  TpmEventLog->Tcg2LasaEven = CbEvtLog->tcg2_last_evt;

  return EFI_SUCCESS;
}

/**
  Find the Spi flash related info.

  @param  SpiFlashInfo        Pointer to Spi flash info structure.

  @retval RETURN_SUCCESS     Successfully find the info.
  @retval RETURN_NOT_FOUND   Failed to find the info .

**/
RETURN_STATUS
ParseSpiFlashInfo (
  OUT SPI_FLASH_INFO           *SpiFlashInfo
  )
{
  return RETURN_NOT_FOUND;
}


/**
  Parse platform specific information from bootloader.

  @retval RETURN_SUCCESS       The platform specific support succeeded.
  @retval RETURN_DEVICE_ERROR  The platform specific support could not be completed.

**/
EFI_STATUS
EFIAPI
ParsePlatformInfo (
  VOID
  )
{
  EFI_STATUS           Status;
  LOADER_FSP_INFO      LdrFspInfo;
  LOADER_FSP_INFO      *NewLdrFspInfo;
  LOADER_SMM_INFO      LdrSmmInfo;
  LOADER_SMM_INFO      *NewLdrSmmInfo;
  TPM_EVENT_LOG_INFO   TpmEventLog;
  TPM_EVENT_LOG_INFO   *NewTpmEventLog;
  SPI_FLASH_INFO       SpiFlashInfo;
  SPI_FLASH_INFO       *NewSpiFlashInfo;

  //
  // Create FSP information HOB
  //
  Status = ParseFspInfo (&LdrFspInfo);
  if (!EFI_ERROR (Status)) {
    NewLdrFspInfo = BuildGuidHob (&gLoaderFspInfoGuid, sizeof (LOADER_FSP_INFO));
    ASSERT (NewLdrFspInfo != NULL);
    CopyMem (NewLdrFspInfo, &LdrFspInfo, sizeof (LOADER_FSP_INFO));
    Status = PcdSet32S (PcdFspsBaseAddress, LdrFspInfo.FspsBase);
    ASSERT_EFI_ERROR (Status);
    DEBUG((EFI_D_INFO, " Get FSP hob success. FspsBase = 0x%x\n", LdrFspInfo.FspsBase));
    DEBUG((EFI_D_INFO, " Get FSP hob success. FspHobList = 0x%p\n", LdrFspInfo.FspHobList));
  }

  //
  // Create SMM information HOB
  //
  Status = ParseSmmInfo (&LdrSmmInfo);
  if (!EFI_ERROR (Status)) {
    NewLdrSmmInfo = BuildGuidHob (&gSmmInformationGuid, sizeof (LOADER_SMM_INFO));
    ASSERT (NewLdrSmmInfo != NULL);
    CopyMem (NewLdrSmmInfo, &LdrSmmInfo, sizeof (LOADER_SMM_INFO));
    DEBUG((EFI_D_INFO, " Get SMM info. smm_base = 0x%x\n", LdrSmmInfo.SmmBase));
    DEBUG((EFI_D_INFO, " smm_size = 0x%x\n", LdrSmmInfo.SmmSize));
  }

  //
  // Create TPM event log information HOB
  //
  Status = ParseTpmEventLog (&TpmEventLog);
  if (!EFI_ERROR (Status)) {
    NewTpmEventLog = BuildGuidHob (&gTpmEventLogInfoGuid, sizeof (TPM_EVENT_LOG_INFO));
    ASSERT (NewTpmEventLog != NULL);
    CopyMem (NewTpmEventLog, &TpmEventLog, sizeof (TPM_EVENT_LOG_INFO));
  }

  //
  // Create guid hob for system tables like acpi table and smbios table
  //
  Status = ParseSpiFlashInfo(&SpiFlashInfo);
  if (!EFI_ERROR (Status)) {
    NewSpiFlashInfo = BuildGuidHob (&gSpiFlashVariableInfoGuid, sizeof (SPI_FLASH_INFO));
    ASSERT (NewSpiFlashInfo != NULL);
    CopyMem (NewSpiFlashInfo, &SpiFlashInfo, sizeof (SPI_FLASH_INFO));
    DEBUG ((EFI_D_ERROR, "SPI flash base at 0x%x\n", SpiFlashInfo.SpiPciBase));
    DEBUG ((EFI_D_ERROR, "VarStoreBase=0x%x, length=0x%x\n", SpiFlashInfo.VariableStoreBase, SpiFlashInfo.VariableStoreSize));
  }
  return EFI_SUCCESS;
}

