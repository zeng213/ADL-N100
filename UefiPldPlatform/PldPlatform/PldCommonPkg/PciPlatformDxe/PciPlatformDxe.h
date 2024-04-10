/*++

  Copyright (c) 2004  - 2021, Intel Corporation. All rights reserved.<BR>


  SPDX-License-Identifier: BSD-2-Clause-Patent




Module Name:

    PciPlatform.h

Abstract:

--*/
#ifndef PCI_PLATFORM_H_
#define PCI_PLATFORM_H_

#include <PiDxe.h>

//
// Produced Protocols
//
#include <Protocol/PciPlatform.h>

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
  IN  EFI_PCI_PLATFORM_PROTOCOL                     *This,
  IN  EFI_HANDLE                                    HostBridge,
  IN  EFI_PCI_HOST_BRIDGE_RESOURCE_ALLOCATION_PHASE Phase,
  IN  EFI_PCI_CHIPSET_EXECUTION_PHASE               ChipsetPhase
  );

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
  IN   EFI_HANDLE                                   HostBridge,
  IN  EFI_HANDLE                                    RootBridge,
  IN  EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_PCI_ADDRESS   PciAddress,
  IN  EFI_PCI_CONTROLLER_RESOURCE_ALLOCATION_PHASE  Phase,
  IN  EFI_PCI_CHIPSET_EXECUTION_PHASE               ChipsetPhase
  );

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
  IN CONST EFI_PCI_PLATFORM_PROTOCOL                *This,
  OUT EFI_PCI_PLATFORM_POLICY                       *PciPolicy
  );

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
  IN CONST EFI_PCI_PLATFORM_PROTOCOL                *This,
  IN EFI_HANDLE                                     PciHandle,
  OUT  VOID                                         **RomImage,
  OUT  UINTN                                        *RomSize
  );

#endif