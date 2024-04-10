/** @file

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <PiPei.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/IoLib.h>
#include <Library/PcdLib.h>
#include <Library/PrePiHobListPointerLib.h>
#include <Library/PrePiLib.h>
#include <Library/BlParseLib.h>
#include <IndustryStandard/Acpi.h>
#include <IndustryStandard/MemoryMappedConfigurationSpaceAccessTable.h>
#include <Guid/SerialPortInfoGuid.h>
#include <Guid/SystemTableInfoGuid.h>
#include <Guid/MemoryMapInfoGuid.h>
#include <Guid/AcpiBoardInfoGuid.h>
#include <Guid/GraphicsInfoHob.h>
#include <Library/PlatformSupportLib.h>
#include <Library/UefiCpuLib.h>
#include <Guid/MemoryTypeInformation.h>

#define LEGACY_8259_MASK_REGISTER_MASTER  0x21
#define LEGACY_8259_MASK_REGISTER_SLAVE   0xA1

//
// PcdMemoryTypeEfixxxxxxx conflict in UefiPayloadPkg and EmbeddedPkg
// Use fixed values until removing dependancy from EmbeddedPkg
//
EFI_MEMORY_TYPE_INFORMATION mDefaultMemoryTypeInformation[] = {
  { EfiBootServicesData,    0x3000 },
  { EfiReservedMemoryType,  0x16   },
  { EfiRuntimeServicesData, 0x400  },
  { EfiRuntimeServicesCode, 0x130  },
  { EfiMaxMemoryType,       0      }
};


/**
   Transfers control to DxeCore.

   This function performs a CPU architecture specific operations to execute
   the entry point of DxeCore with the parameters of HobList.

   @param DxeCoreEntryPoint         The entry point of DxeCore.
   @param HobList                   The start of HobList passed to DxeCore.

**/
VOID
HandOffToDxeCore (
  IN EFI_PHYSICAL_ADDRESS   DxeCoreEntryPoint,
  IN EFI_PEI_HOB_POINTERS   HobList
  );


EFI_STATUS
MemInfoCallback (
  IN MEMROY_MAP_ENTRY          *MemoryMapEntry,
  IN VOID                      *Params
  )
{
  EFI_PHYSICAL_ADDRESS         Base;
  EFI_RESOURCE_TYPE            Type;
  UINT64                       Size;
  EFI_RESOURCE_ATTRIBUTE_TYPE  Attribue;

  Type    = (MemoryMapEntry->Type == 1) ? EFI_RESOURCE_SYSTEM_MEMORY : EFI_RESOURCE_MEMORY_RESERVED;
  Base    = MemoryMapEntry->Base;
  Size    = MemoryMapEntry->Size;

  Attribue = EFI_RESOURCE_ATTRIBUTE_PRESENT |
             EFI_RESOURCE_ATTRIBUTE_INITIALIZED |
             EFI_RESOURCE_ATTRIBUTE_TESTED |
             EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |
             EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |
             EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |
             EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE;

  if ((Base >= BASE_4GB) && (Type == EFI_RESOURCE_SYSTEM_MEMORY)) {
    // Remove tested attribute to avoid DXE core to dispatch driver to memory above 4GB
    Attribue &= ~EFI_RESOURCE_ATTRIBUTE_TESTED;
  }

  //
  // Enable memory resource promotion later for SBL + UefiPayload.
  // When DxeMpLib tries to allocate memory for wake buffer at fixed address 0x88000,
  // FindFreePages() will promote initialized but Untested memory resources to
  // available memory, this includes >4GiB which is set as Untested above.
  //
  if (Base == 0x00) {
    Attribue &= ~EFI_RESOURCE_ATTRIBUTE_TESTED;
  }

  BuildResourceDescriptorHob (Type, Attribue, (EFI_PHYSICAL_ADDRESS)Base, Size);
  DEBUG ((DEBUG_INFO , "buildhob: base = 0x%lx, size = 0x%lx, type = 0x%x\n", Base, Size, Type));

  return EFI_SUCCESS;
}



/**
  Find the board related info from ACPI table

  @param  AcpiTableBase          ACPI table start address in memory
  @param  AcpiBoardInfo          Pointer to the acpi board info strucutre

  @retval RETURN_SUCCESS     Successfully find out all the required information.
  @retval RETURN_NOT_FOUND   Failed to find the required info.

**/
RETURN_STATUS
ParseAcpiInfo (
  IN   UINT64                                   AcpiTableBase,
  OUT  ACPI_BOARD_INFO                          *AcpiBoardInfo
  )
{
  EFI_ACPI_3_0_ROOT_SYSTEM_DESCRIPTION_POINTER  *Rsdp;
  EFI_ACPI_DESCRIPTION_HEADER                   *Rsdt;
  UINT32                                        *Entry32;
  UINTN                                         Entry32Num;
  EFI_ACPI_3_0_FIXED_ACPI_DESCRIPTION_TABLE     *Fadt;
  EFI_ACPI_DESCRIPTION_HEADER                   *Xsdt;
  UINT64                                        *Entry64;
  UINTN                                         Entry64Num;
  UINTN                                         Idx;
  UINT32                                        *Signature;
  EFI_ACPI_MEMORY_MAPPED_CONFIGURATION_BASE_ADDRESS_TABLE_HEADER *MmCfgHdr;
  EFI_ACPI_MEMORY_MAPPED_ENHANCED_CONFIGURATION_SPACE_BASE_ADDRESS_ALLOCATION_STRUCTURE *MmCfgBase;

  Rsdp = (EFI_ACPI_3_0_ROOT_SYSTEM_DESCRIPTION_POINTER *)(UINTN)AcpiTableBase;
  DEBUG ((DEBUG_INFO, "Rsdp at 0x%p\n", Rsdp));
  DEBUG ((DEBUG_INFO, "Rsdt at 0x%x, Xsdt at 0x%lx\n", Rsdp->RsdtAddress, Rsdp->XsdtAddress));

  //
  // Search Rsdt First
  //
  Fadt     = NULL;
  MmCfgHdr = NULL;
  Rsdt     = (EFI_ACPI_DESCRIPTION_HEADER *)(UINTN)(Rsdp->RsdtAddress);
  if (Rsdt != NULL) {
    Entry32  = (UINT32 *)(Rsdt + 1);
    Entry32Num = (Rsdt->Length - sizeof(EFI_ACPI_DESCRIPTION_HEADER)) >> 2;
    for (Idx = 0; Idx < Entry32Num; Idx++) {
      Signature = (UINT32 *)(UINTN)Entry32[Idx];
      if (*Signature == EFI_ACPI_3_0_FIXED_ACPI_DESCRIPTION_TABLE_SIGNATURE) {
        Fadt = (EFI_ACPI_3_0_FIXED_ACPI_DESCRIPTION_TABLE *)Signature;
        DEBUG ((DEBUG_INFO, "Found Fadt in Rsdt\n"));
      }

      if (*Signature == EFI_ACPI_5_0_PCI_EXPRESS_MEMORY_MAPPED_CONFIGURATION_SPACE_BASE_ADDRESS_DESCRIPTION_TABLE_SIGNATURE) {
        MmCfgHdr = (EFI_ACPI_MEMORY_MAPPED_CONFIGURATION_BASE_ADDRESS_TABLE_HEADER *)Signature;
        DEBUG ((DEBUG_INFO, "Found MM config address in Rsdt\n"));
      }

      if ((Fadt != NULL) && (MmCfgHdr != NULL)) {
        goto Done;
      }
    }
  }

  //
  // Search Xsdt Second
  //
  Xsdt     = (EFI_ACPI_DESCRIPTION_HEADER *)(UINTN)(Rsdp->XsdtAddress);
  if (Xsdt != NULL) {
    Entry64  = (UINT64 *)(Xsdt + 1);
    Entry64Num = (Xsdt->Length - sizeof(EFI_ACPI_DESCRIPTION_HEADER)) >> 3;
    for (Idx = 0; Idx < Entry64Num; Idx++) {
      Signature = (UINT32 *)(UINTN)Entry64[Idx];
      if (*Signature == EFI_ACPI_3_0_FIXED_ACPI_DESCRIPTION_TABLE_SIGNATURE) {
        Fadt = (EFI_ACPI_3_0_FIXED_ACPI_DESCRIPTION_TABLE *)Signature;
        DEBUG ((DEBUG_INFO, "Found Fadt in Xsdt\n"));
      }

      if (*Signature == EFI_ACPI_5_0_PCI_EXPRESS_MEMORY_MAPPED_CONFIGURATION_SPACE_BASE_ADDRESS_DESCRIPTION_TABLE_SIGNATURE) {
        MmCfgHdr = (EFI_ACPI_MEMORY_MAPPED_CONFIGURATION_BASE_ADDRESS_TABLE_HEADER *)Signature;
        DEBUG ((DEBUG_INFO, "Found MM config address in Xsdt\n"));
      }

      if ((Fadt != NULL) && (MmCfgHdr != NULL)) {
        goto Done;
      }
    }
  }

  if (Fadt == NULL) {
    return RETURN_NOT_FOUND;
  }

Done:

  AcpiBoardInfo->PmCtrlRegBase   = Fadt->Pm1aCntBlk;
  AcpiBoardInfo->PmTimerRegBase  = Fadt->PmTmrBlk;
  AcpiBoardInfo->ResetRegAddress = Fadt->ResetReg.Address;
  AcpiBoardInfo->ResetValue      = Fadt->ResetValue;
  AcpiBoardInfo->PmEvtBase       = Fadt->Pm1aEvtBlk;
  AcpiBoardInfo->PmGpeEnBase     = Fadt->Gpe0Blk + Fadt->Gpe0BlkLen / 2;

  if (MmCfgHdr != NULL) {
    MmCfgBase = (EFI_ACPI_MEMORY_MAPPED_ENHANCED_CONFIGURATION_SPACE_BASE_ADDRESS_ALLOCATION_STRUCTURE *)((UINT8*) MmCfgHdr + sizeof (*MmCfgHdr));
    AcpiBoardInfo->PcieBaseAddress = MmCfgBase->BaseAddress;
  } else {
    AcpiBoardInfo->PcieBaseAddress = 0;
  }
  DEBUG ((DEBUG_INFO, "PmCtrl  Reg 0x%lx\n",  AcpiBoardInfo->PmCtrlRegBase));
  DEBUG ((DEBUG_INFO, "PmTimer Reg 0x%lx\n",  AcpiBoardInfo->PmTimerRegBase));
  DEBUG ((DEBUG_INFO, "Reset   Reg 0x%lx\n",  AcpiBoardInfo->ResetRegAddress));
  DEBUG ((DEBUG_INFO, "Reset   Value 0x%x\n", AcpiBoardInfo->ResetValue));
  DEBUG ((DEBUG_INFO, "PmEvt   Reg 0x%lx\n",  AcpiBoardInfo->PmEvtBase));
  DEBUG ((DEBUG_INFO, "PmGpeEn Reg 0x%lx\n",  AcpiBoardInfo->PmGpeEnBase));
  DEBUG ((DEBUG_INFO, "PcieBaseAddr 0x%lx\n", AcpiBoardInfo->PcieBaseAddress));

  //
  // Verify values for proper operation
  //
  ASSERT(Fadt->Pm1aCntBlk != 0);
  ASSERT(Fadt->PmTmrBlk != 0);
  ASSERT(Fadt->ResetReg.Address != 0);
  ASSERT(Fadt->Pm1aEvtBlk != 0);
  ASSERT(Fadt->Gpe0Blk != 0);

  DEBUG_CODE_BEGIN ();
    BOOLEAN    SciEnabled;

    //
    // Check the consistency of SCI enabling
    //

    //
    // Get SCI_EN value
    //
   if (Fadt->Pm1CntLen == 4) {
      SciEnabled = (IoRead32 (Fadt->Pm1aCntBlk) & BIT0)? TRUE : FALSE;
    } else {
      //
      // if (Pm1CntLen == 2), use 16 bit IO read;
      // if (Pm1CntLen != 2 && Pm1CntLen != 4), use 16 bit IO read as a fallback
      //
      SciEnabled = (IoRead16 (Fadt->Pm1aCntBlk) & BIT0)? TRUE : FALSE;
    }

    if (!(Fadt->Flags & EFI_ACPI_5_0_HW_REDUCED_ACPI) &&
        (Fadt->SmiCmd == 0) &&
       !SciEnabled) {
      //
      // The ACPI enabling status is inconsistent: SCI is not enabled but ACPI
      // table does not provide a means to enable it through FADT->SmiCmd
      //
      DEBUG ((DEBUG_ERROR, "ERROR: The ACPI enabling status is inconsistent: SCI is not"
        " enabled but the ACPI table does not provide a means to enable it through FADT->SmiCmd."
        " This may cause issues in OS.\n"));
    }
  DEBUG_CODE_END ();

  return RETURN_SUCCESS;
}


/**
  Find DXE core from FV and build DXE core HOBs.

  @retval EFI_SUCCESS        If it completed successfully.
  @retval EFI_NOT_FOUND      If it failed to process DXE FV.
**/
EFI_STATUS
ProcessDxeFv (
  VOID
  )
{
  EFI_PHYSICAL_ADDRESS        CurrentAddress;
  EFI_PHYSICAL_ADDRESS        EndOfFirmwareVolume;
  EFI_FFS_FILE_HEADER         *File;
  UINT32                      Size;
  EFI_PHYSICAL_ADDRESS        EndOfFile;
  EFI_FIRMWARE_VOLUME_HEADER  *BootFirmwareVolume;

  BootFirmwareVolume = (EFI_FIRMWARE_VOLUME_HEADER *)(UINTN)PcdGet32 (PcdPayloadFdMemBase);
  CurrentAddress = (EFI_PHYSICAL_ADDRESS)(UINTN) BootFirmwareVolume;
  EndOfFirmwareVolume = CurrentAddress + BootFirmwareVolume->FvLength;

  //
  // Loop through the FFS files in the Boot Firmware Volume
  //
  for (EndOfFile = CurrentAddress + BootFirmwareVolume->HeaderLength; ; ) {

    CurrentAddress = (EndOfFile + 7) & 0xfffffffffffffff8ULL;
    if (CurrentAddress > EndOfFirmwareVolume) {
      return EFI_NOT_FOUND;
    }

    File = (EFI_FFS_FILE_HEADER*)(UINTN) CurrentAddress;
    if (IS_FFS_FILE2 (File)) {
      Size = FFS_FILE2_SIZE (File);
      if (Size <= 0x00FFFFFF) {
        return EFI_NOT_FOUND;
      }
    } else {
      Size = FFS_FILE_SIZE (File);
      if (Size < sizeof (EFI_FFS_FILE_HEADER)) {
        return EFI_NOT_FOUND;
      }
    }

    EndOfFile = CurrentAddress + Size;
    if (EndOfFile > EndOfFirmwareVolume) {
      return EFI_NOT_FOUND;
    }

    //
    // Look for FV file
    //
    if (File->Type != EFI_FV_FILETYPE_FIRMWARE_VOLUME_IMAGE) {
      continue;
    }

    FfsProcessFvFile ((EFI_PEI_FILE_HANDLE)(UINTN)File);
    break;
  }

  return EFI_SUCCESS;
}


/**
  It will build HOBs based on information from bootloaders.

  @retval EFI_SUCCESS        If it completed successfully.
  @retval Others             If it failed to build required HOBs.
**/
EFI_STATUS
BuildHobFromBl (
  VOID
  )
{
  EFI_STATUS                       Status;
  SYSTEM_TABLE_INFO                SysTableInfo;
  SYSTEM_TABLE_INFO                *NewSysTableInfo;
  ACPI_BOARD_INFO                  AcpiBoardInfo;
  ACPI_BOARD_INFO                  *NewAcpiBoardInfo;
  EFI_PEI_GRAPHICS_INFO_HOB        GfxInfo;
  EFI_PEI_GRAPHICS_INFO_HOB        *NewGfxInfo;
  EFI_PEI_GRAPHICS_DEVICE_INFO_HOB GfxDeviceInfo;
  EFI_PEI_GRAPHICS_DEVICE_INFO_HOB *NewGfxDeviceInfo;

  //
  // Parse memory info and build memory HOBs
  //
  Status = ParseMemoryInfo (MemInfoCallback, NULL);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  //
  // Create guid hob for frame buffer information
  //
  Status = ParseGfxInfo (&GfxInfo);
  if (!EFI_ERROR (Status)) {
    NewGfxInfo = BuildGuidHob (&gEfiGraphicsInfoHobGuid, sizeof (GfxInfo));
    ASSERT (NewGfxInfo != NULL);
    CopyMem (NewGfxInfo, &GfxInfo, sizeof (GfxInfo));
    DEBUG ((DEBUG_INFO, "Created graphics info hob\n"));
  }


  Status = ParseGfxDeviceInfo (&GfxDeviceInfo);
  if (!EFI_ERROR (Status)) {
    NewGfxDeviceInfo = BuildGuidHob (&gEfiGraphicsDeviceInfoHobGuid, sizeof (GfxDeviceInfo));
    ASSERT (NewGfxDeviceInfo != NULL);
    CopyMem (NewGfxDeviceInfo, &GfxDeviceInfo, sizeof (GfxDeviceInfo));
    DEBUG ((DEBUG_INFO, "Created graphics device info hob\n"));
  }


  //
  // Create guid hob for system tables like acpi table and smbios table
  //
  Status = ParseSystemTable(&SysTableInfo);
  ASSERT_EFI_ERROR (Status);
  if (!EFI_ERROR (Status)) {
    NewSysTableInfo = BuildGuidHob (&gUefiSystemTableInfoGuid, sizeof (SYSTEM_TABLE_INFO));
    ASSERT (NewSysTableInfo != NULL);
    CopyMem (NewSysTableInfo, &SysTableInfo, sizeof (SYSTEM_TABLE_INFO));
    DEBUG ((DEBUG_INFO, "Detected Acpi Table at 0x%lx, length 0x%x\n", SysTableInfo.AcpiTableBase, SysTableInfo.AcpiTableSize));
    DEBUG ((DEBUG_INFO, "Detected Smbios Table at 0x%lx, length 0x%x\n", SysTableInfo.SmbiosTableBase, SysTableInfo.SmbiosTableSize));
  }

  //
  // Create guid hob for acpi board information
  //
  Status = ParseAcpiInfo (SysTableInfo.AcpiTableBase, &AcpiBoardInfo);
  ASSERT_EFI_ERROR (Status);
  if (!EFI_ERROR (Status)) {
    NewAcpiBoardInfo = BuildGuidHob (&gUefiAcpiBoardInfoGuid, sizeof (ACPI_BOARD_INFO));
    ASSERT (NewAcpiBoardInfo != NULL);
    CopyMem (NewAcpiBoardInfo, &AcpiBoardInfo, sizeof (ACPI_BOARD_INFO));
    DEBUG ((DEBUG_INFO, "Create acpi board info guid hob\n"));
  }

  //
  // Parse platform specific information.
  //
  Status = ParsePlatformInfo ();
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Error when parsing platform info, Status = %r\n", Status));
    return Status;
  }

  return EFI_SUCCESS;
}


/**
  This function will build some generic HOBs that doesn't depend on information from bootloaders.

**/
VOID
BuildGenericHob (
  VOID
  )
{
  UINT32                           RegEax;
  UINT8                            PhysicalAddressBits;
  EFI_RESOURCE_ATTRIBUTE_TYPE      ResourceAttribute;

 //
  // Create Memory Type Information HOB
  //
  BuildGuidDataHob (
    &gEfiMemoryTypeInformationGuid,
    mDefaultMemoryTypeInformation,
    sizeof(mDefaultMemoryTypeInformation)
    );

  // The UEFI payload FV
  //BuildFvHob (PcdGet32 (PcdPayloadFdMemBase), PcdGet32 (PcdPayloadFdMemSize));
  BuildMemoryAllocationHob (PcdGet32 (PcdPayloadFdMemBase), PcdGet32 (PcdPayloadFdMemSize), EfiBootServicesData);
  ProcessDxeFv ();

  //
  // Build CPU memory space and IO space hob
  //
  AsmCpuid (0x80000000, &RegEax, NULL, NULL, NULL);
  if (RegEax >= 0x80000008) {
    AsmCpuid (0x80000008, &RegEax, NULL, NULL, NULL);
    PhysicalAddressBits = (UINT8) RegEax;
  } else {
    PhysicalAddressBits  = 36;
  }

  BuildCpuHob (PhysicalAddressBits, 16);

  //
  // Report Local APIC range, cause sbl HOB to be NULL, comment now
  //
  ResourceAttribute = (
      EFI_RESOURCE_ATTRIBUTE_PRESENT |
      EFI_RESOURCE_ATTRIBUTE_INITIALIZED |
      EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |
      EFI_RESOURCE_ATTRIBUTE_TESTED
  );
  BuildResourceDescriptorHob (EFI_RESOURCE_MEMORY_MAPPED_IO, ResourceAttribute, 0xFEC80000, SIZE_512KB);
  BuildMemoryAllocationHob ( 0xFEC80000, SIZE_512KB, EfiMemoryMappedIO);


//  if (FeaturePcdGet (PcdPrePiProduceMemoryTypeInformationHob)) {
    // Optional feature that helps prevent EFI memory map fragmentation.
//    BuildMemoryTypeInformationHob ();
//  }

}


/**
  Entry point to the C language phase of UEFI payload.

  @retval      It will not return if SUCCESS, and return error when passing bootloader parameter.
**/
EFI_STATUS
EFIAPI
PayloadEntry (
  IN UINTN                     BootloaderParameter
  )
{
  EFI_STATUS                    Status;
  PHYSICAL_ADDRESS              DxeCoreEntryPoint;
  EFI_HOB_HANDOFF_INFO_TABLE    *HandoffHobTable;
  UINTN                         HobMemBase;
  UINTN                         HobMemSize;
  EFI_PEI_HOB_POINTERS          Hob;

  DEBUG ((EFI_D_ERROR, "GET_BOOTLOADER_PARAMETER() = 0x%lx\n", GET_BOOTLOADER_PARAMETER()));
  DEBUG ((EFI_D_ERROR, "sizeof(UINTN) = 0x%x\n", sizeof(UINTN)));

  // Initialize floating point operating environment to be compliant with UEFI spec.
  InitializeFloatingPointUnits ();

  // Init the region for HOB and memory allocation for this module
  HobMemBase      = ALIGN_VALUE (PcdGet32 (PcdPayloadFdMemBase) + PcdGet32 (PcdPayloadFdMemSize), SIZE_1MB);
  HobMemSize      = FixedPcdGet32 (PcdSystemMemoryUefiRegionSize);
  HandoffHobTable = HobConstructor ((VOID *)HobMemBase, HobMemSize, (VOID *)HobMemBase, (VOID *)(HobMemBase + HobMemSize));
  PrePeiSetHobList (HandoffHobTable);

  // Build HOB based on information from Bootloader
  Status = BuildHobFromBl ();
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "BuildHobFromBl Status = %r\n", Status));
    return Status;
  }

  // Build other HOBs required by DXE
  BuildGenericHob ();

  // Load the DXE Core
  Status = LoadDxeCore (NULL, &DxeCoreEntryPoint);
  ASSERT_EFI_ERROR (Status);

  DEBUG ((EFI_D_INFO, "DxeCoreEntryPoint = 0x%lx\n", DxeCoreEntryPoint));

  //
  // Mask off all legacy 8259 interrupt sources
  //
  IoWrite8 (LEGACY_8259_MASK_REGISTER_MASTER, 0xFF);
  IoWrite8 (LEGACY_8259_MASK_REGISTER_SLAVE,  0xFF);

  Hob.Raw = GetHobList();
  HandOffToDxeCore (DxeCoreEntryPoint, Hob);

  // Should not get here
  CpuDeadLoop ();
  return EFI_SUCCESS; 
}
