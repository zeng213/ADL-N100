/** @file
  This file include all platform action which can be customized
  by IBV/OEM.

Copyright (c) 2015 - 2018, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "PlatformBootManager.h"
#include "PlatformConsole.h"
#include <Library/Tcg2PhysicalPresenceLib.h>

GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID  *mLibTerminalType[] = {
  &gEfiPcAnsiGuid,
  &gEfiVT100Guid,
  &gEfiVT100PlusGuid,
  &gEfiVTUTF8Guid
};

VOID
InstallReadyToLock (
  VOID
  )
{
  EFI_STATUS                            Status;
  EFI_HANDLE                            Handle;
  EFI_SMM_ACCESS2_PROTOCOL              *SmmAccess;

  DEBUG((DEBUG_INFO,"InstallReadyToLock  entering......\n"));
  //
  // Inform the SMM infrastructure that we're entering BDS and may run 3rd party code hereafter
  // Since PI1.2.1, we need signal EndOfDxe as ExitPmAuth
  //
  EfiEventGroupSignal (&gEfiEndOfDxeEventGroupGuid);
  DEBUG((DEBUG_INFO,"All EndOfDxe callbacks have returned successfully\n"));

  //
  // Install DxeSmmReadyToLock protocol in order to lock SMM
  //
  Status = gBS->LocateProtocol (&gEfiSmmAccess2ProtocolGuid, NULL, (VOID **) &SmmAccess);
  if (!EFI_ERROR (Status)) {
    Handle = NULL;
    Status = gBS->InstallProtocolInterface (
                    &Handle,
                    &gEfiDxeSmmReadyToLockProtocolGuid,
                    EFI_NATIVE_INTERFACE,
                    NULL
                    );
    ASSERT_EFI_ERROR (Status);
  }

  DEBUG((DEBUG_INFO,"InstallReadyToLock  end\n"));
  return;
}

/**
  Return the index of the load option in the load option array.

  The function consider two load options are equal when the
  OptionType, Attributes, Description, FilePath and OptionalData are equal.

  @param Key    Pointer to the load option to be found.
  @param Array  Pointer to the array of load options to be found.
  @param Count  Number of entries in the Array.

  @retval -1          Key wasn't found in the Array.
  @retval 0 ~ Count-1 The index of the Key in the Array.
**/
INTN
PlatformFindLoadOption (
  IN CONST EFI_BOOT_MANAGER_LOAD_OPTION *Key,
  IN CONST EFI_BOOT_MANAGER_LOAD_OPTION *Array,
  IN UINTN                              Count
)
{
  UINTN                             Index;

  for (Index = 0; Index < Count; Index++) {
    if ((Key->OptionType == Array[Index].OptionType) &&
        (Key->Attributes == Array[Index].Attributes) &&
        (StrCmp (Key->Description, Array[Index].Description) == 0) &&
        (CompareMem (Key->FilePath, Array[Index].FilePath, GetDevicePathSize (Key->FilePath)) == 0) &&
        (Key->OptionalDataSize == Array[Index].OptionalDataSize) &&
        (CompareMem (Key->OptionalData, Array[Index].OptionalData, Key->OptionalDataSize) == 0)) {
      return (INTN) Index;
    }
  }

  return -1;
}

/**
  Register a boot option using a file GUID in the FV.

  @param FileGuid     The file GUID name in FV.
  @param Description  The boot option description.
  @param Attributes   The attributes used for the boot option loading.
**/
VOID
PlatformRegisterFvBootOption (
  EFI_GUID                         *FileGuid,
  CHAR16                           *Description,
  UINT32                           Attributes
)
{
  EFI_STATUS                        Status;
  UINTN                             OptionIndex;
  EFI_BOOT_MANAGER_LOAD_OPTION      NewOption;
  EFI_BOOT_MANAGER_LOAD_OPTION      *BootOptions;
  UINTN                             BootOptionCount;
  MEDIA_FW_VOL_FILEPATH_DEVICE_PATH FileNode;
  EFI_LOADED_IMAGE_PROTOCOL         *LoadedImage;
  EFI_DEVICE_PATH_PROTOCOL          *DevicePath;

  Status = gBS->HandleProtocol (gImageHandle, &gEfiLoadedImageProtocolGuid, (VOID **) &LoadedImage);
  ASSERT_EFI_ERROR (Status);

  EfiInitializeFwVolDevicepathNode (&FileNode, FileGuid);
  DevicePath = AppendDevicePathNode (
                 DevicePathFromHandle (LoadedImage->DeviceHandle),
                 (EFI_DEVICE_PATH_PROTOCOL *) &FileNode
               );

  Status = EfiBootManagerInitializeLoadOption (
             &NewOption,
             LoadOptionNumberUnassigned,
             LoadOptionTypeBoot,
             Attributes,
             Description,
             DevicePath,
             NULL,
             0
           );
  if (!EFI_ERROR (Status)) {
    BootOptions = EfiBootManagerGetLoadOptions (&BootOptionCount, LoadOptionTypeBoot);

    OptionIndex = PlatformFindLoadOption (&NewOption, BootOptions, BootOptionCount);

    if (OptionIndex == -1) {
      Status = EfiBootManagerAddLoadOptionVariable (&NewOption, (UINTN) -1);
      ASSERT_EFI_ERROR (Status);
    }
    EfiBootManagerFreeLoadOption (&NewOption);
    EfiBootManagerFreeLoadOptions (BootOptions, BootOptionCount);
  }
}

/**
  Update the ConIn variable with USB Keyboard device path,if its not already exists in ConIn
**/
VOID
EnumUsbKeyboard (
  VOID
  )
{
  UINTN                     DevicePathSize;
  EFI_DEVICE_PATH_PROTOCOL  *VarConIn;
  EFI_DEVICE_PATH_PROTOCOL  *DevicePathInstance;
  EFI_DEVICE_PATH_PROTOCOL  *Next;
  BOOLEAN                   UsbKeyboard;

  UsbKeyboard = FALSE;
  GetEfiGlobalVariable2 (L"ConIn", (VOID **) &VarConIn, NULL);

  //
  // If ConIn variable is empty, need to enumerate USB keyboard device path
  //
  do {
    DevicePathInstance = GetNextDevicePathInstance (
                           &VarConIn,
                           &DevicePathSize
                           );

    if (DevicePathInstance == NULL) {
      //
      // The instance is NULL, it means the VarConIn is null, escape the DO loop,
      // and need to add USB keyboard dev path.
      //
      break;
    }

    Next = DevicePathInstance;
    while (!IsDevicePathEndType(Next)) {
      //
      // Checking the device path to see the USB keyboard existance.
      //
      if ((Next->Type    == MESSAGING_DEVICE_PATH) &&
          (Next->SubType == MSG_USB_CLASS_DP) &&
          (((USB_CLASS_DEVICE_PATH *) Next)->DeviceClass == CLASS_HID) &&
          (((USB_CLASS_DEVICE_PATH *) Next)->DeviceSubClass == SUBCLASS_BOOT) &&
          (((USB_CLASS_DEVICE_PATH *) Next)->DeviceProtocol == PROTOCOL_KEYBOARD)) {
        DEBUG ((DEBUG_INFO, "[EnumUsbKeyboard] USB keyboard path exists\n"));
        UsbKeyboard = TRUE;

        break;
      }
      Next = NextDevicePathNode (Next);
    } // while (!IsDevicePathEndType(Next));

    if (DevicePathInstance != NULL) {
      FreePool (DevicePathInstance);
    }
  } while (VarConIn != NULL);

  //
  //  USB keyboard device path does not exist, So add it to the ConIn
  //
  if (!UsbKeyboard) {
    DEBUG ((DEBUG_INFO, "[EnumUsbKeyboard] Adding USB keyboard device path to ConIn.\n"));
    EfiBootManagerUpdateConsoleVariable (ConIn, (EFI_DEVICE_PATH_PROTOCOL *) &gUsbClassKeyboardDevicePath, NULL);
  }

  if (VarConIn != NULL) {
    FreePool (VarConIn);
  }
}

/**
  Connect the USB short form device path.

  @param DevicePath   USB short form device path

  @retval EFI_SUCCESS           Successfully connected the USB device
  @retval EFI_NOT_FOUND         Cannot connect the USB device
  @retval EFI_INVALID_PARAMETER The device path is invalid.
**/
EFI_STATUS
ConnectUsbShortFormDevicePath (
  IN EFI_DEVICE_PATH_PROTOCOL   *DevicePath
  )
{
  EFI_STATUS                            Status;
  EFI_HANDLE                            *Handles;
  UINTN                                 HandleCount;
  UINTN                                 Index;
  EFI_PCI_IO_PROTOCOL                   *PciIo;
  UINT8                                 Class[3];
  BOOLEAN                               AtLeastOneConnected;

  //
  // Check the passed in parameters
  //
  if (DevicePath == NULL) {
    return EFI_INVALID_PARAMETER;
  }

  if ((DevicePathType (DevicePath) != MESSAGING_DEVICE_PATH) ||
      ((DevicePathSubType (DevicePath) != MSG_USB_CLASS_DP) && (DevicePathSubType (DevicePath) != MSG_USB_WWID_DP))
     ) {
    return EFI_INVALID_PARAMETER;
  }

  //
  // Find the usb host controller firstly, then connect with the remaining device path
  //
  AtLeastOneConnected = FALSE;
  Status = gBS->LocateHandleBuffer (
                  ByProtocol,
                  &gEfiPciIoProtocolGuid,
                  NULL,
                  &HandleCount,
                  &Handles
                  );
  for (Index = 0; Index < HandleCount; Index++) {
    Status = gBS->HandleProtocol (
                    Handles[Index],
                    &gEfiPciIoProtocolGuid,
                    (VOID **) &PciIo
                    );
    if (!EFI_ERROR (Status)) {
      //
      // Check whether the Pci device is the wanted usb host controller
      //
      Status = PciIo->Pci.Read (PciIo, EfiPciIoWidthUint8, 0x09, 3, &Class);
      if (!EFI_ERROR (Status) &&
          ((PCI_CLASS_SERIAL == Class[2]) && (PCI_CLASS_SERIAL_USB == Class[1]))
         ) {
        Status = gBS->ConnectController (
                        Handles[Index],
                        NULL,
                        DevicePath,
                        FALSE
                        );
        if (!EFI_ERROR(Status)) {
          AtLeastOneConnected = TRUE;
        }
      }
    }
  }

  return AtLeastOneConnected ? EFI_SUCCESS : EFI_NOT_FOUND;
}

/**
  Check whether the device path node is ISA Serial Node.

  @param Acpi           Device path node to be checked

  @retval TRUE          It's ISA Serial Node.
  @retval FALSE         It's NOT ISA Serial Node.

**/
BOOLEAN
IsIsaSerialNode (
  IN ACPI_HID_DEVICE_PATH *Acpi
  )
{
  return (BOOLEAN) (
      (DevicePathType (Acpi) == ACPI_DEVICE_PATH) &&
      (DevicePathSubType (Acpi) == ACPI_DP) &&
      (ReadUnaligned32 (&Acpi->HID) == EISA_PNP_ID (0x0501))
      );
}

/**
  Test whether DevicePath is a valid Terminal


  @param DevicePath      DevicePath to be checked

  @retval  TRUE         If DevicePath point to a Terminal.
  @retval  FALSE        If DevicePath does not point to a Terminal.

**/
BOOLEAN
IsTerminalDevicePath (
  IN  EFI_DEVICE_PATH_PROTOCOL *DevicePath
  )
{
  BOOLEAN                   IsTerminal;
  EFI_DEVICE_PATH_PROTOCOL  *Node;
  VENDOR_DEVICE_PATH        *Vendor;
  UART_DEVICE_PATH          *Uart;
  ACPI_HID_DEVICE_PATH      *Acpi;

  IsTerminal = FALSE;

  Uart   = NULL;
  Vendor = NULL;
  Acpi   = NULL;
  for (Node = DevicePath; !IsDevicePathEnd (Node); Node = NextDevicePathNode (Node)) {
    //
    // Vendor points to the node before the End node
    //
    Vendor = (VENDOR_DEVICE_PATH *) Node;

    if ((DevicePathType (Node) == MESSAGING_DEVICE_PATH) && (DevicePathSubType (Node) == MSG_UART_DP)) {
      Uart = (UART_DEVICE_PATH *) Node;
    }

    if (Uart == NULL) {
      //
      // Acpi points to the node before the UART node
      //
      Acpi = (ACPI_HID_DEVICE_PATH *) Node;
    }
  }

  if (Vendor == NULL ||
      DevicePathType (Vendor) != MESSAGING_DEVICE_PATH ||
      DevicePathSubType (Vendor) != MSG_VENDOR_DP ||
      Uart == NULL) {
    return FALSE;
  }

  //
  // There are four kinds of Terminal types
  // check to see whether this devicepath
  // is one of that type
  //
  if (CompareGuid (&Vendor->Guid, mLibTerminalType[0]) ||
      CompareGuid (&Vendor->Guid, mLibTerminalType[1]) ||
      CompareGuid (&Vendor->Guid, mLibTerminalType[2]) ||
      CompareGuid (&Vendor->Guid, mLibTerminalType[3])) {
    IsTerminal  = TRUE;
  } else {
    IsTerminal = FALSE;
  }

  if (!IsTerminal) {
    return FALSE;
  }

  if ((Acpi != NULL) && IsIsaSerialNode (Acpi)) {
    return TRUE;
  } else {
    return FALSE;
  }
}

/**
  Return whether the device is trusted console.

  @param Device  The device to be tested.

  @retval TRUE   The device can be trusted.
  @retval FALSE  The device cannot be trusted.
**/
BOOLEAN
IsTrustedConsole (
  EFI_DEVICE_PATH_PROTOCOL  *Device
  )
{
  if(Device == NULL) {
    return FALSE;
  }

  if (CompareMem (Device, &gPlatformIGDDevice, GetDevicePathSize ((EFI_DEVICE_PATH_PROTOCOL *) &gPlatformIGDDevice) - END_DEVICE_PATH_LENGTH) == 0) {
    return TRUE;
  }


  if (CompareMem (Device, &gUsbClassKeyboardDevicePath, GetDevicePathSize ((EFI_DEVICE_PATH_PROTOCOL *) &gUsbClassKeyboardDevicePath) - END_DEVICE_PATH_LENGTH) == 0) {
    return TRUE;
  }

  if (CompareMem (Device, &gSerialDevicePath , GetDevicePathSize ((EFI_DEVICE_PATH_PROTOCOL *) &gSerialDevicePath ) - END_DEVICE_PATH_LENGTH) == 0) {
    return TRUE;
  }

  if( IsTerminalDevicePath (Device) ) {
    return TRUE;
  }

  return FALSE;
}

/**
  The function connects the trusted consoles.
**/
VOID
ConnectTrustedConsoles (
  VOID
  )
{
  EFI_DEVICE_PATH_PROTOCOL     *Consoles;
  EFI_DEVICE_PATH_PROTOCOL     *TempDevicePath;
  EFI_DEVICE_PATH_PROTOCOL     *Instance;
  EFI_DEVICE_PATH_PROTOCOL     *Next;
  UINTN                        Size;
  UINTN                        Index;
  EFI_HANDLE                   Handle;
  EFI_STATUS                   Status;
  CHAR16                       *ConsoleVar[] = {L"ConIn", L"ConOut"};

  for (Index = 0; Index < sizeof (ConsoleVar) / sizeof (ConsoleVar[0]); Index++) {
    GetEfiGlobalVariable2 (ConsoleVar[Index], (VOID **) &Consoles, NULL);

    TempDevicePath = Consoles;
    do {
      Instance = GetNextDevicePathInstance (&TempDevicePath, &Size);
      if (Instance == NULL) {
        break;
      }
      if (IsTrustedConsole (Instance)) {
        if ((DevicePathType (Instance) == MESSAGING_DEVICE_PATH) &&
            ((DevicePathSubType (Instance) == MSG_USB_CLASS_DP) || (DevicePathSubType (Instance) == MSG_USB_WWID_DP))
           ) {
          ConnectUsbShortFormDevicePath (Instance);
        } else {
          for (Next = Instance; !IsDevicePathEnd (Next); Next = NextDevicePathNode (Next)) {
            if (DevicePathType (Next) == ACPI_DEVICE_PATH && DevicePathSubType (Next) == ACPI_ADR_DP) {
              break;
            } else if (DevicePathType (Next) == HARDWARE_DEVICE_PATH &&
                       DevicePathSubType (Next) == HW_CONTROLLER_DP &&
                       DevicePathType (NextDevicePathNode (Next)) == ACPI_DEVICE_PATH &&
                       DevicePathSubType (NextDevicePathNode (Next)) == ACPI_ADR_DP
                       ) {
              break;
            }
          }
          if (!IsDevicePathEnd (Next)) {
            SetDevicePathEndNode (Next);
            Status = EfiBootManagerConnectDevicePath (Instance, &Handle);
            if (!EFI_ERROR (Status)) {
              gBS->ConnectController (Handle, NULL, NULL, TRUE);
            }
          } else {
            EfiBootManagerConnectDevicePath (Instance, NULL);
          }
        }
      }
      FreePool (Instance);
    } while (TempDevicePath != NULL);

    if (Consoles != NULL) {
      FreePool (Consoles);
    }
  }
}

/**
  Do the platform specific action before the console is connected.

  Such as:
    Update console variable;
    Register new Driver#### or Boot####;
    Signal ReadyToLock event.
**/
VOID
EFIAPI
PlatformBootManagerBeforeConsole (
  VOID
)
{
  EFI_INPUT_KEY                Enter;
  EFI_INPUT_KEY                F2;
  EFI_INPUT_KEY                Down;
  EFI_BOOT_MANAGER_LOAD_OPTION BootOption;

  PlatformConsoleInit ();

  //
  // Register ENTER as CONTINUE key
  //
  Enter.ScanCode    = SCAN_NULL;
  Enter.UnicodeChar = CHAR_CARRIAGE_RETURN;
  EfiBootManagerRegisterContinueKeyOption (0, &Enter, NULL);

  //
  // Map F2 to Boot Manager Menu
  //
  F2.ScanCode    = SCAN_F2;
  F2.UnicodeChar = CHAR_NULL;
  EfiBootManagerGetBootManagerMenu (&BootOption);
  EfiBootManagerAddKeyOptionVariable (NULL, (UINT16) BootOption.OptionNumber, 0, &F2, NULL);

  //
  // Also add Down key to Boot Manager Menu since some serial terminals don't support F2 key.
  //
  Down.ScanCode    = SCAN_DOWN;
  Down.UnicodeChar = CHAR_NULL;
  EfiBootManagerGetBootManagerMenu (&BootOption);
  EfiBootManagerAddKeyOptionVariable (NULL, (UINT16) BootOption.OptionNumber, 0, &Down, NULL);

  EnumUsbKeyboard();

  ConnectTrustedConsoles();
  //
  // Process TCG Physical Presence request just after the trusted console is ready
  //
  Tcg2PhysicalPresenceLibProcessRequest (NULL); // TCG2 implementation

  //
  // Install ready to lock.
  // This needs to be done before option rom dispatched.
  //
  InstallReadyToLock ();

  //
  // Dispatch deferred images after EndOfDxe event and ReadyToLock installation.
  //
  EfiBootManagerDispatchDeferredImages ();

  PlatformConsoleDeferredInit ();
}

/**
  Do the platform specific action after the console is connected.

  Such as:
    Dynamically switch output mode;
    Signal console ready platform customized event;
    Run diagnostics like memory testing;
    Connect certain devices;
    Dispatch aditional option roms.
**/
VOID
EFIAPI
PlatformBootManagerAfterConsole (
  VOID
)
{
  EFI_GRAPHICS_OUTPUT_BLT_PIXEL  Black;
  EFI_GRAPHICS_OUTPUT_BLT_PIXEL  White;

  Black.Blue = Black.Green = Black.Red = Black.Reserved = 0;
  White.Blue = White.Green = White.Red = White.Reserved = 0xFF;

  EfiBootManagerConnectAll ();
  EfiBootManagerRefreshAllBootOption ();

  //
  // Register UEFI Shell
  //
  PlatformRegisterFvBootOption (PcdGetPtr (PcdShellFile), L"UEFI Shell", LOAD_OPTION_ACTIVE);

  Print (
    L"\n"
    L"F2 or Down      to enter Boot Manager Menu.\n"
    L"ENTER           to boot directly.\n"
    L"\n"
  );

}

/**
  This function is called each second during the boot manager waits the timeout.

  @param TimeoutRemain  The remaining timeout.
**/
VOID
EFIAPI
PlatformBootManagerWaitCallback (
  UINT16          TimeoutRemain
)
{
  return;
}

/**
  The function is called when no boot option could be launched,
  including platform recovery options and options pointing to applications
  built into firmware volumes.

  If this function returns, BDS attempts to enter an infinite loop.
**/
VOID
EFIAPI
PlatformBootManagerUnableToBoot (
  VOID
  )
{
  return;
}

