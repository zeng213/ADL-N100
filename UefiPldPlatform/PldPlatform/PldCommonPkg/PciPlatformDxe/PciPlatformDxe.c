/** @file

  Copyright (c) 2004  - 2021, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

Module Name:


    PciPlatform.c

Abstract:
--*/

#include "PciPlatformDxe.h"
#include <IndustryStandard/Pci.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Protocol/PciIo.h>
#include <Protocol/PciRootBridgeIo.h>
#include <Bus/Pci/PciBusDxe/PciBus.h>

EFI_HANDLE mPciPlatformHandle;

EFI_PCI_PLATFORM_PROTOCOL mPciPlatform = {
  PhaseNotify,
  PlatformPrepController,
  GetPlatformPolicy,
  GetPciRom
};

/**

  Get MEM32 base and limit from a specific PCI device's parent PPB

  @param[in]  PciDevice     A PCI device
  @param[out] MemBase       MEM32 base from the specific PCI's PPB
  @param[out] MemLimit      MEM32 limit from the specific PCI's PPB

  @retval EFI_SUCCESS       The function completed successfully.
  @retval EFI_DEVICE_ERROR  A device error if a valid MEM32 range is not found

**/
EFI_STATUS
GetPpbMem32Range (
  IN  PCI_IO_DEVICE   *PciDevice,
  OUT UINT32          *MemBase,
  OUT UINT32          *MemLimit
  )
{
  PCI_IO_DEVICE                   *Parent;
  PCI_IO_DEVICE                   *Next;
  EFI_PCI_IO_PROTOCOL             *PciIo;
  UINT16                          Base;
  UINT16                          Limit;

  if (PciDevice == NULL) {
    return EFI_INVALID_PARAMETER;
  }

  Next = PciDevice;
  Parent = Next;
  while (Next != NULL) {
    if (IS_PCI_BRIDGE (&(Next->Pci))) {
      Parent = Next;
      break;
    }
    Next = Next->Parent;
  }
  PciIo = &Parent->PciIo;

  PciIo->Pci.Read (
          PciIo,
          EfiPciIoWidthUint16,
          OFFSET_OF (PCI_TYPE01, Bridge.MemoryBase),
          1,
          &Base);

  PciIo->Pci.Read (
          PciIo,
          EfiPciIoWidthUint16,
          OFFSET_OF (PCI_TYPE01, Bridge.MemoryLimit),
          1,
          &Limit);

  DEBUG ((DEBUG_VERBOSE, "GetPpbMem32Range: [%02X|%02X|%02X] 0x%X - 0x%X\n",
    Parent->BusNumber, Parent->DeviceNumber, Parent->FunctionNumber, Base, Limit));

  if ((Base == 0) || (Limit == 0) || (Limit <= Base)) {
    return EFI_DEVICE_ERROR;
  }

  if (MemBase != NULL) {
    *MemBase  = (Base << 16);
  }
  if (MemLimit != NULL) {
    *MemLimit = (Limit << 16);
  }
  return EFI_SUCCESS;
}

/**
  The notification from the PCI bus enumerator to the platform that it is
  about to enter a certain phase during the enumeration process.

  @param[in] This           The pointer to the EFI_PCI_PLATFORM_PROTOCOL instance.
  @param[in] HostBridge     The handle of the host bridge controller.
  @param[in] Phase          The phase of the PCI bus enumeration.
  @param[in] ExecPhase      Defines the execution phase of the PCI chipset driver.

  @retval EFI_SUCCESS   The function completed successfully.

**/
EFI_STATUS
EFIAPI
PhaseNotify (
  IN EFI_PCI_PLATFORM_PROTOCOL                      *This,
  IN EFI_HANDLE                                     HostBridge,
  IN EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PHASE  Phase,
  IN EFI_PCI_CHIPSET_EXECUTION_PHASE                ChipsetPhase
  )
{
  return EFI_UNSUPPORTED;
}

/**
  The notification from the PCI bus enumerator to the platform for each PCI
  controller at several predefined points during PCI controller initialization.

  @param[in] This           The pointer to the EFI_PCI_PLATFORM_PROTOCOL instance.
  @param[in] HostBridge     The associated PCI host bridge handle.
  @param[in] RootBridge     The associated PCI root bridge handle.
  @param[in] PciAddress     The address of the PCI device on the PCI bus.
  @param[in] Phase          The phase of the PCI controller enumeration.
  @param[in] ChipsetPhase   Defines the execution phase of the PCI chipset driver.

  @retval EFI_SUCCESS   The function completed successfully.

**/
EFI_STATUS
EFIAPI
PlatformPrepController (
  IN EFI_PCI_PLATFORM_PROTOCOL                      *This,
  IN EFI_HANDLE                                     HostBridge,
  IN EFI_HANDLE                                     RootBridge,
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS    PciAddress,
  IN EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE   Phase,
  IN EFI_PCI_CHIPSET_EXECUTION_PHASE                ChipsetPhase
  )
{
  return EFI_UNSUPPORTED;
}

/**
  Retrieves the platform policy regarding enumeration.

  @param[in]  This        The pointer to the EFI_PCI_PLATFORM_PROTOCOL instance.
  @param[out] PciPolicy   The platform policy with respect to VGA and ISA aliasing.

  @retval EFI_SUCCESS             The function completed successfully.
  @retval EFI_INVALID_PARAMETER   PciPolicy is NULL.

**/
EFI_STATUS
EFIAPI
GetPlatformPolicy (
  IN  CONST EFI_PCI_PLATFORM_PROTOCOL   *This,
  OUT       EFI_PCI_PLATFORM_POLICY     *PciPolicy
  )
{
  *PciPolicy = EFI_RESERVE_VGA_IO_ALIAS;
  return EFI_SUCCESS;
}

/**
  Gets the PCI device's option ROM from a platform-specific location.

  @param[in]  This        The pointer to the EFI_PCI_PLATFORM_PROTOCOL instance.
  @param[in]  PciHandle   The handle of the PCI device.
  @param[out] RomImage    If the call succeeds, the pointer to the pointer to the option ROM image.
                          Otherwise, this field is undefined. The memory for RomImage is allocated
                          by EFI_PCI_PLATFORM_PROTOCOL.GetPciRom() using the EFI Boot Service AllocatePool().
                          It is the caller's responsibility to free the memory using the EFI Boot Service
                          FreePool(), when the caller is done with the option ROM.
  @param[out] RomSize     If the call succeeds, a pointer to the size of the option ROM size. Otherwise,
                          this field is undefined.

  @retval EFI_SUCCESS            The option ROM was available for this device and loaded into memory.
  @retval EFI_NOT_FOUND          No option ROM was available for this device.
  @retval EFI_OUT_OF_RESOURCES   No memory was available to load the option ROM.
  @retval EFI_DEVICE_ERROR       An error occurred in obtaining the option ROM.

**/
EFI_STATUS
EFIAPI
GetPciRom (
  IN  CONST EFI_PCI_PLATFORM_PROTOCOL   *This,
  IN        EFI_HANDLE                  PciHandle,
  OUT       VOID                        **RomImage,
  OUT       UINTN                       *RomSize
  )
{
  EFI_STATUS                      Status;
  UINT8                           RomBarIndex;
  UINT32                          RomBar;
  UINT32                          RomBarOffset;
  UINT32                          Mem32Base;
  UINT32                          Mem32Limit;
  UINT32                          AllOnes;
  UINT32                          LegacyImageLength;
  UINT64                          RomImageSize;
  UINT16                          OffsetPcir;
  BOOLEAN                         FirstCheck;
  UINT8                           Indicator;
  UINT8                           CodeType;
  UINT8                           *Image;
  PCI_EXPANSION_ROM_HEADER        *RomHeader;
  PCI_DATA_STRUCTURE              *RomPcir;
  EFI_PCI_IO_PROTOCOL             *PciIo;
  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL *PciRootBridgeIo;
  PCI_IO_DEVICE                   *PciDevice;

  Status = gBS->HandleProtocol (
                PciHandle,
                &gEfiPciIoProtocolGuid,
                (VOID **) &PciIo);

  if (EFI_ERROR (Status)) {
    return EFI_NOT_FOUND;
  }

  PciDevice       = PCI_IO_DEVICE_FROM_PCI_IO_THIS (PciIo);
  PciRootBridgeIo = PciDevice->PciRootBridgeIo;

  //
  // 0x30
  //
  RomBarIndex = PCI_EXPANSION_ROM_BASE;

  if (IS_PCI_BRIDGE (&(PciDevice->Pci))) {
    //
    // If is ppb, 0x38
    //
    RomBarIndex = PCI_BRIDGE_ROMBAR;
  }

  //
  // The bit0 is 0 to prevent the enabling of the Rom address decoder
  //
  AllOnes = 0xfffffffe;
  Status = PciIo->Pci.Write (
                  PciIo,
                  EfiPciWidthUint32,
                  RomBarIndex,
                  1,
                  &AllOnes
                );
  if (EFI_ERROR (Status)) {
    return EFI_NOT_FOUND;
  }

  //
  // Read back
  //
  Status = PciIo->Pci.Read (
                  PciIo,
                  EfiPciWidthUint32,
                  RomBarIndex,
                  1,
                  &AllOnes
                );
  if (EFI_ERROR (Status)) {
    return EFI_NOT_FOUND;
  }

  //
  // Bits [1, 10] are reserved
  //
  AllOnes &= 0xFFFFF800;
  if ((AllOnes == 0) || (AllOnes == 0xFFFFF800)) {
    return EFI_NOT_FOUND;
  }
  *RomSize = (~AllOnes) + 1;

  //
  // The PPB's MEM32 RANGE BAR is re-programmed to the Option ROM BAR Base in order to
  // shadow the Option ROM of the devices under the PPB.
  //
  Status = GetPpbMem32Range (PciDevice, &Mem32Base, &Mem32Limit);
  if (EFI_ERROR (Status)) {
    return Status;
  }
  if ((Mem32Limit - Mem32Base) < *RomSize) {
    return EFI_DEVICE_ERROR;
  }
  RomBar = Mem32Base;

  //
  // Allocate memory for Rom header and PCIR
  //
  RomHeader = AllocatePool (sizeof (PCI_EXPANSION_ROM_HEADER));
  if (RomHeader == NULL) {
    return EFI_OUT_OF_RESOURCES;
  }

  RomPcir = AllocatePool (sizeof (PCI_DATA_STRUCTURE));
  if (RomPcir == NULL) {
    FreePool (RomHeader);
    return EFI_OUT_OF_RESOURCES;
  }

  //
  // Restore & Enable RomBar
  //
  RomBar |= BIT0;
  Status = PciIo->Pci.Write (
                  PciIo,
                  EfiPciWidthUint32,
                  RomBarIndex,
                  1,
                  &RomBar
                );
  if (EFI_ERROR (Status)) {
    Status = EFI_NOT_FOUND;
    goto Error;
  }

  RomBar &= (UINT32)~(BIT0);

  RomBarOffset      = RomBar;
  Status            = EFI_NOT_FOUND;
  FirstCheck        = TRUE;
  LegacyImageLength = 0;
  Image             = NULL;
  RomImageSize      = 0;
  Indicator         = 0;
  CodeType          = 0xFF;

  do {
    PciRootBridgeIo->Mem.Read (
                              PciRootBridgeIo,
                              EfiPciWidthUint8,
                              RomBarOffset,
                              sizeof (PCI_EXPANSION_ROM_HEADER),
                              (UINT8 *) RomHeader
                              );

    if (RomHeader->Signature != PCI_EXPANSION_ROM_HEADER_SIGNATURE) {
      RomBarOffset = RomBarOffset + 512;
      if (FirstCheck) {
        break;
      } else {
        RomImageSize = RomImageSize + 512;
        continue;
      }
    }

    FirstCheck  = FALSE;
    OffsetPcir  = RomHeader->PcirOffset;
    //
    // If the pointer to the PCI Data Structure is invalid, no further images can be located.
    // The PCI Data Structure must be DWORD aligned.
    //
    if (OffsetPcir == 0 ||
        (OffsetPcir & 3) != 0 ||
        RomImageSize + OffsetPcir + sizeof (PCI_DATA_STRUCTURE) > *RomSize) {
      break;
    }
    PciRootBridgeIo->Mem.Read (
                              PciRootBridgeIo,
                              EfiPciWidthUint8,
                              RomBarOffset + OffsetPcir,
                              sizeof (PCI_DATA_STRUCTURE),
                              (UINT8 *) RomPcir
                              );
    //
    // If a valid signature is not present in the PCI Data Structure, no further images can be located.
    //
    if (RomPcir->Signature != PCI_DATA_STRUCTURE_SIGNATURE) {
      break;
    }
    if (RomImageSize + RomPcir->ImageLength * 512 > *RomSize) {
      break;
    }
    if (RomPcir->CodeType == PCI_CODE_TYPE_PCAT_IMAGE) {
      CodeType = PCI_CODE_TYPE_PCAT_IMAGE;
      LegacyImageLength = ((UINT32)((EFI_LEGACY_EXPANSION_ROM_HEADER *)RomHeader)->Size512) * 512;
    }
    Indicator     = RomPcir->Indicator;
    RomImageSize  = RomImageSize + RomPcir->ImageLength * 512;
    RomBarOffset  = RomBarOffset + RomPcir->ImageLength * 512;
  } while (((Indicator & 0x80) == 0x00) && ((RomBarOffset - RomBar) < *RomSize));

  //
  // Some Legacy Cards do not report the correct ImageLength so used the maximum
  // of the legacy length and the PCIR Image Length
  //
  if (CodeType == PCI_CODE_TYPE_PCAT_IMAGE) {
    RomImageSize = MAX (RomImageSize, LegacyImageLength);
  }

  if (RomImageSize > 0) {
    Status = EFI_SUCCESS;
    Image  = AllocatePool ((UINT32) RomImageSize);
    if (Image == NULL) {
      Status = EFI_OUT_OF_RESOURCES;
      goto Error;
    }

    //
    // Copy Rom image into memory
    //
    Status = PciRootBridgeIo->Mem.Read (
                              PciRootBridgeIo,
                              EfiPciWidthUint8,
                              RomBar,
                              (UINT32) RomImageSize,
                              Image
                              );
  } else {
    Status = EFI_NOT_FOUND;
  }

  *RomImage = Image;
  *RomSize  = RomImageSize;

Error:
  //
  // Free allocated memory
  //
  if (RomHeader != NULL) {
    FreePool (RomHeader);
  }
  if (RomPcir != NULL) {
    FreePool (RomPcir);
  }

  //
  // Disable rom decode
  //
  AllOnes = 0xfffffffe;
  PciIo->Pci.Write (
    PciIo,
    EfiPciWidthUint32,
    RomBarIndex,
    1,
    &AllOnes
    );

  return Status;
}

/**

  @param  (Standard EFI Image entry - EFI_IMAGE_ENTRY_POINT)

  @retval EFI_STATUS

**/
EFI_STATUS
EFIAPI
PciPlatformDriverEntry (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_STATUS  Status;

  //
  // Install on a new handle
  //
  Status = gBS->InstallProtocolInterface (
                  &mPciPlatformHandle,
                  &gEfiPciPlatformProtocolGuid,
                  EFI_NATIVE_INTERFACE,
                  &mPciPlatform
                  );

  return Status;
}
