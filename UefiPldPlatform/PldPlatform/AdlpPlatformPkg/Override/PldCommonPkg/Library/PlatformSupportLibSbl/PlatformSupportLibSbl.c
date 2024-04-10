/** @file
  This library will parse the Slim Bootloader to get required information.

  Copyright (c) 2014 - 2023, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiPei.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/IoLib.h>
#include <Library/HobLib.h>
#include <IndustryStandard/Acpi.h>
#include <Library/PlatformSupportLib.h>
#include <Library/BlParseLib.h>
#include <Guid/LoaderFspInfoGuid.h>
#include <Guid/LoaderSmmInfoGuid.h>
#include <Guid/SpiFlashInfoGuid.h>
#include <Guid/TpmEventLogInfoGuid.h>
#include <Guid/PerformanceInfoGuid.h>
#include <Guid/PciRootBridgeInfoGuid.h>
#include <Guid/SecureBootInfoGuid.h>
#include "LoaderPlatformInfoGuid.h"
#include "FlashMapInfoGuid.h"
#include "DeviceTableHobGuid.h"

#include <Guid/TpmInstance.h>
#include <Guid/fTpmInstance.h>
#include <Library/Tcg2SupportLib.h>
#include <Register/Intel/ArchitecturalMsr.h>

/**
  This function retrieves a GUIDed HOB data from Slim Bootloader.

  This function will search SBL HOB list to find the first GUIDed HOB that
  its GUID matches Guid.

  @param[in]  Guid        A pointer to HOB GUID to search.

  @retval NULL            Failed to find the GUID HOB.
  @retval others          GUIDed HOB data pointer.

**/
VOID *
PlatformGetGuidHobData (
  IN       EFI_GUID      *Guid
  )
{
  UINT8                  *GuidHob;
  CONST VOID             *HobList;

  HobList = GetParameterBase ();
  ASSERT (HobList != NULL);
  GuidHob = GetNextGuidHob (Guid, HobList);
  if (GuidHob != NULL) {
    return GET_GUID_HOB_DATA (GuidHob);
  }

  return NULL;
}

/**
  Acquire the FSP info

  @param[out]  LdrFspInfo    Pointer to the FSP info structure

  @retval RETURN_SUCCESS     Successfully find out the FSP info.
  @retval RETURN_NOT_FOUND   Failed to find the FSP info.

**/
RETURN_STATUS
EFIAPI
ParseFspInfo (
  OUT LOADER_FSP_INFO           *LdrFspInfo
  )
{
  LOADER_FSP_INFO               *FspInfo;
  LOADER_PLATFORM_INFO          *PlatformInfo;

  FspInfo = (LOADER_FSP_INFO *) PlatformGetGuidHobData (&gLoaderFspInfoGuid);
  if (FspInfo == NULL) {
    ASSERT (FALSE);
    return RETURN_NOT_FOUND;
  }

  PlatformInfo = (LOADER_PLATFORM_INFO *) PlatformGetGuidHobData (&gLoaderPlatformInfoGuid);
  if (PlatformInfo == NULL) {
    ASSERT (FALSE);
    return RETURN_NOT_FOUND;
  }

  // Get FspsBase and FspHobList, secureboot related thing will get from other hob.
  CopyMem (LdrFspInfo, FspInfo, sizeof (LOADER_FSP_INFO));

  LdrFspInfo->VerifiedBoot = ((PlatformInfo->LdrFeatures & FEATURE_VERIFIED_BOOT) == 0)?0:1;
  LdrFspInfo->MeasuredBoot = ((PlatformInfo->LdrFeatures & FEATURE_MEASURED_BOOT) == 0)?0:1;

  DEBUG((EFI_D_INFO, "VerifiedBoot 0x%x\n",LdrFspInfo->VerifiedBoot));
  DEBUG((EFI_D_INFO, "MeasuredBoot 0x%x\n",LdrFspInfo->MeasuredBoot));

  return RETURN_SUCCESS;
}

/**
  Acquire the SMM information

  @param[out]  LdrSmmInfo    Pointer to SMM information

  @retval RETURN_SUCCESS     Successfully find out the SMM info.
  @retval RETURN_NOT_FOUND   Failed to find the SMM info.

**/
RETURN_STATUS
EFIAPI
ParseSmmInfo (
  OUT LOADER_SMM_INFO           *LdrSmmInfo
  )
{
  LOADER_SMM_INFO               *SmmInfo;

  SmmInfo = (LOADER_SMM_INFO *) PlatformGetGuidHobData (&gSmmInformationGuid);
  if (SmmInfo == NULL) {
    ASSERT (FALSE);
    return RETURN_NOT_FOUND;
  }

  CopyMem (LdrSmmInfo, SmmInfo, sizeof (LOADER_SMM_INFO));

  return RETURN_SUCCESS;
}


/**
  Find the TPM event log

  @param  TpmEventLog        Pointer to Tpm Event Log.

  @retval RETURN_SUCCESS     Successfully find the Event Log.
  @retval RETURN_NOT_FOUND   Failed to find the Event Log .

**/
RETURN_STATUS
ParseTpmEventLog (
  OUT TPM_EVENT_LOG_INFO    *TpmEventLog
  )
{
  TPM_EVENT_LOG_INFO        *EventInfo;

  EventInfo = (TPM_EVENT_LOG_INFO *) PlatformGetGuidHobData (&gTpmEventLogInfoGuid);
  if (EventInfo == NULL) {
    return RETURN_NOT_FOUND;
  }

  CopyMem (TpmEventLog, EventInfo, sizeof (TPM_EVENT_LOG_INFO));

  return EFI_SUCCESS;
}



/**
  Gets component information from the flash map by partition.

  This function will look for the component matching the input signature
  in the flash map, if found, it will look for the component with back up
  flag based on the backup partition parmeter and will return the
  base address and size of the component.

  @param[in]  Signature         Signature of the component information required
  @param[in]  IsBackupPartition TRUE for Back up copy, FALSE for primary copy
  @param[out] Base              Base address of the component
  @param[out] Size              Size of the component

  @retval    EFI_SUCCESS    Found the component with the matching signature.
  @retval    EFI_NOT_FOUND  Component with the matching signature not found.

**/
EFI_STATUS
GetComponentInfo (
  IN  UINT32     Signature,
  IN  BOOLEAN    IsBackupPartition,
  OUT UINT32     *Base,
  OUT UINT32     *Size
  )
{
  UINTN                 Index;
  UINT32                MaxEntries;
  UINT32                PcdBase;
  UINT32                PcdSize;
  UINT32                RomBase;
  FLASH_MAP             *FlashMapPtr;
  EFI_STATUS            Status;
  FLASH_MAP_ENTRY_DESC  EntryDesc;

  PcdBase = 0;
  PcdSize = 0;
  Status = EFI_NOT_FOUND;

  FlashMapPtr = (FLASH_MAP *) PlatformGetGuidHobData (&gFlashMapInfoGuid);
  if (FlashMapPtr == NULL) {
    return RETURN_NOT_FOUND;
  }

  RomBase = (UINT32) (0x100000000ULL - FlashMapPtr->RomSize);
  MaxEntries = ((FlashMapPtr->Length - FLASH_MAP_HEADER_SIZE) / sizeof (FLASH_MAP_ENTRY_DESC));

  for (Index = 0; Index < MaxEntries; Index++) {
    EntryDesc = FlashMapPtr->EntryDesc[Index];
    //
    // Look for the component with desired signature
    //
    if (EntryDesc.Signature == 0xFFFFFFFF) {
      Status = EFI_NOT_FOUND;
      break;
    }
    if (EntryDesc.Signature == Signature) {
      //
      // Check if need to get back up copy
      // Back up copies can be identified with back up flag
      //
      if ( ((EntryDesc.Flags & FLASH_MAP_FLAGS_NON_REDUNDANT_REGION) != 0) ||
           (((IsBackupPartition ? FLASH_MAP_FLAGS_BACKUP : 0) ^ (EntryDesc.Flags & FLASH_MAP_FLAGS_BACKUP)) == 0) ) {
        PcdBase = (UINT32) (RomBase + EntryDesc.Offset);
        PcdSize = EntryDesc.Size;
        Status = EFI_SUCCESS;
        break;
      }
    }
  }

  //
  // If base and pcdbase are not 0, fill and return the value
  //
  if ((Base != NULL) && (PcdBase != 0)) {
    *Base = PcdBase;
  }
  if ((Size != NULL) && (PcdSize != 0)) {
    *Size = PcdSize;
  }

  return Status;
}


/**
  Get device address

  If PCI device in device table, the device address format is 0x00BBDDFF, where
  BB, DD and FF are PCI bus, device and function number.
  If the device is MMIO device, the device address format is 0xMMxxxxxx, where
  MM should be non-zero value, xxxxxx could be any value.

  @param[in]  DeviceType         The device type, refer OS_BOOT_MEDIUM_TYPE.
  @param[in]  DeviceInstance     The device instance number starting from 0.

  @retval     Device address for a given device instance, return 0 if the device
              could not be found from device table.
**/
UINT32
GetDeviceAddr (
  IN  UINT8          DeviceType,
  IN  UINT8          DeviceInstance
  )
{
  PLT_DEVICE_TABLE   *DeviceTable;
  PLT_DEVICE         *PltDevice;
  UINT32             DeviceBase;
  UINT32             Index;
  UINT8              Bus;
  UINT8              Device;
  UINT8              Function;

  DeviceTable = (PLT_DEVICE_TABLE *) PlatformGetGuidHobData (&gDeviceTableHobGuid);
  DEBUG((EFI_D_INFO, "   DeviceTable = 0x%x\n",DeviceTable));
  if (DeviceTable == NULL) {
    return 0;
  }

  DeviceBase = 0;
  PltDevice  = NULL;
  //CWE-606
  if (DeviceTable->DeviceNumber >= 0xffff) {
      return 0;
  }
  for (Index = 0; Index < DeviceTable->DeviceNumber; Index++) {
    PltDevice = &DeviceTable->Device[Index];
    if ((PltDevice->Type == DeviceType) && (PltDevice->Instance == DeviceInstance)){
      DEBUG((EFI_D_INFO, "   found it  = 0x%x\n",PltDevice->Dev.DevAddr));
      break;
    }
  }

  if (DeviceTable->DeviceNumber != Index) {
    DeviceBase = PltDevice->Dev.DevAddr;
  }
      DEBUG((EFI_D_INFO, "   DeviceBase  = 0x%x\n",DeviceBase));


  Bus        = (UINT8)((DeviceBase >> 16) & 0xFF);
  Device     = (UINT8)((DeviceBase >> 8)  & 0xFF);
  Function   = (UINT8)(DeviceBase & 0xFF);
  DeviceBase = (UINT32)(Bus << 20) + (UINT32)(Device << 15) + (UINT32)(Function << 12);
      DEBUG((EFI_D_INFO, "   2DeviceBase  = 0x%x\n",DeviceBase));

  return DeviceBase;
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
  EFI_STATUS                   Status;
  UINT32                       Base;
  UINT32                       Size;
  ACPI_BOARD_INFO              *AcpiBoardInfo;
  UINT8                        *GuidHob;
  LOADER_PLATFORM_INFO         *PlatformInfo;

  Status = GetComponentInfo (FLASH_MAP_SIG_EPVARIABLE, FALSE, &Base, &Size);
  DEBUG((EFI_D_INFO, " Base = 0x%x, Size=0x%x Status=0x%r\n", Base, Size, Status));

  if (EFI_ERROR (Status)) {
    return Status;
  }

  SpiFlashInfo->VariableStoreBase = Base;
  SpiFlashInfo->VariableStoreSize = Size;

  GuidHob = GetFirstGuidHob (&gUefiAcpiBoardInfoGuid);
  DEBUG((EFI_D_INFO, " GuidHob = 0x%x\n",GuidHob));

  if (GuidHob == NULL) {
    return EFI_NOT_FOUND;
  }
  AcpiBoardInfo = (ACPI_BOARD_INFO *)GET_GUID_HOB_DATA (GuidHob);

  // Get first SPI device BDF
  SpiFlashInfo->SpiPciBase = (UINT32)AcpiBoardInfo->PcieBaseAddress + GetDeviceAddr (4, 0);
  DEBUG((EFI_D_INFO, " SpiPciBase = 0x%x\n",SpiFlashInfo->SpiPciBase));

  PlatformInfo = (LOADER_PLATFORM_INFO *) PlatformGetGuidHobData (&gLoaderPlatformInfoGuid);
  if (PlatformInfo != NULL) {
    SpiFlashInfo->Flags = PlatformInfo->Flags;
    DEBUG((EFI_D_INFO, " SpiFlashInfo->Flags = 0x%x\n", SpiFlashInfo->Flags));
  }

  return EFI_SUCCESS;
}


/**
  Parse performance data from bootloader and build a new hob

  @retval RETURN_SUCCESS     Successfully find out the SMM info.
  @retval RETURN_NOT_FOUND   Failed to find the SMM info.

**/
RETURN_STATUS
ParsePerformanceInfo (
  VOID
  )
{
  PERFORMANCE_INFO               *PerfInfo;
  PERFORMANCE_INFO               *NewPerfInfo;

  PerfInfo = (PERFORMANCE_INFO *) PlatformGetGuidHobData (&gLoaderPerformanceInfoGuid);
  if (PerfInfo == NULL) {
    ASSERT (FALSE);
    return RETURN_NOT_FOUND;
  }

  NewPerfInfo = BuildGuidHob (&gLoaderPerformanceInfoGuid, sizeof (PERFORMANCE_INFO));
  ASSERT (NewPerfInfo != NULL);
  CopyMem (NewPerfInfo, PerfInfo, sizeof (PERFORMANCE_INFO));

  return RETURN_SUCCESS;
}


/**
  Checks whether the platform is a pre-production part; or in manufacturing mode or debug mode.

  @retval  TRUE    Platform is a pre-production part; or in manufacturing mode or debug mode.
  @retval  FALSE   Platfomr is not a pre-production part; or in manufacturing mode or debug mode.
**/
BOOLEAN
PlatformDebugStateEnabled (
  IN UINT16 HwState
  )
{
  MSR_IA32_FEATURE_CONTROL_REGISTER Ia32FeatureControlMsr;
  MSR_IA32_DEBUG_INTERFACE_REGISTER DebugInterfaceMsr;

  //
  // Check for Platform in Pre-production or in Manufaturing mode or secure debug mode
  //
  if((HwState & HWSTATE_IN_MANU_SECURE_DEBUG_MODE) || (HwState & HWSTATE_PLATFORM_PRE_PRODUCTION)){
    return TRUE;
  }

  //
  // Check for Sample part
  //
  Ia32FeatureControlMsr.Uint64 = AsmReadMsr64 (MSR_IA32_FEATURE_CONTROL);
  if (Ia32FeatureControlMsr.Bits.Lock == 0) {
    return TRUE;
  }

  //
  // Check for Debug mode
  //
  DebugInterfaceMsr.Uint64 = AsmReadMsr64 (MSR_IA32_DEBUG_INTERFACE);
  if (DebugInterfaceMsr.Bits.Enable) {
    return TRUE;
  }

  return FALSE;
}

/**
  Acquire the PCI Root Bridge info and update

  @retval RETURN_SUCCESS     Successfully find out the RootBridge info.
  @retval RETURN_NOT_FOUND   Failed to find the RootBridge info.

**/
RETURN_STATUS
EFIAPI
ParsePciRootBridgeInfo (
  VOID
  )
{
  PCI_ROOT_BRIDGE_INFO_HOB    *PciRootBridgeInfo;
  PCI_ROOT_BRIDGE_INFO_HOB    *NewPciRootBridgeInfo;
  UINTN                       InfoLen;

  PciRootBridgeInfo = (PCI_ROOT_BRIDGE_INFO_HOB *) PlatformGetGuidHobData (&gLoaderPciRootBridgeInfoGuid);
  if (PciRootBridgeInfo == NULL) {
    ASSERT (FALSE);
    return RETURN_NOT_FOUND;
  }

  InfoLen = sizeof(PCI_ROOT_BRIDGE_INFO_HOB) + ((PciRootBridgeInfo->Count) * sizeof(PCI_ROOT_BRIDGE_ENTRY));
  NewPciRootBridgeInfo = BuildGuidHob (&gLoaderPciRootBridgeInfoGuid, InfoLen);
  ASSERT (NewPciRootBridgeInfo != NULL);
  CopyMem (NewPciRootBridgeInfo, PciRootBridgeInfo, InfoLen);

  return RETURN_SUCCESS;
}

/**
  Acquire the secure boot info

  @retval RETURN_SUCCESS     Successfully acquire the secure boot info.
  @retval RETURN_NOT_FOUND   Failed to acquire the secure boot info.

**/
RETURN_STATUS
EFIAPI
ParseSecureBootInfo (
  VOID
  )
{
  SECUREBOOT_INFO             *SecurebootInfo;
  SECUREBOOT_INFO             *NewSecurebootInfo;

  SecurebootInfo = (SECUREBOOT_INFO *) PlatformGetGuidHobData (&gSecureBootInfoGuid);
  if (SecurebootInfo == NULL) {
    DEBUG ((DEBUG_ERROR, "gSecureBootInfoGuid Not Found!\n"));
    return RETURN_NOT_FOUND;
  }

  NewSecurebootInfo = BuildGuidHob (&gSecureBootInfoGuid, sizeof (SECUREBOOT_INFO));
  ASSERT (NewSecurebootInfo != NULL);
  CopyMem (NewSecurebootInfo, SecurebootInfo, sizeof (SECUREBOOT_INFO));

  return RETURN_SUCCESS;
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

  ParsePerformanceInfo ();

  ParsePciRootBridgeInfo ();

  ParseSecureBootInfo ();

  return EFI_SUCCESS;
}

