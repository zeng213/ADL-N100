  #
  # DXE Core
  #
  MdeModulePkg/Core/Dxe/DxeMain.inf {
    <LibraryClasses>
      NULL|MdeModulePkg/Library/LzmaCustomDecompressLib/LzmaCustomDecompressLib.inf
  }

  #
  # Components that produce the architectural protocols
  #
  UefiCpuPkg/CpuDxe/CpuDxe.inf
  MdeModulePkg/Universal/BdsDxe/BdsDxe.inf
  MdeModulePkg/Application/UiApp/UiApp.inf {
    <LibraryClasses>
      NULL|MdeModulePkg/Library/DeviceManagerUiLib/DeviceManagerUiLib.inf
      NULL|MdeModulePkg/Library/BootManagerUiLib/BootManagerUiLib.inf
      NULL|MdeModulePkg/Library/BootMaintenanceManagerUiLib/BootMaintenanceManagerUiLib.inf
  }

  PcAtChipsetPkg/HpetTimerDxe/HpetTimerDxe.inf
  MdeModulePkg/Universal/Metronome/Metronome.inf
  MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  MdeModulePkg/Universal/MonotonicCounterRuntimeDxe/MonotonicCounterRuntimeDxe.inf
  MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  PcAtChipsetPkg/PcatRealTimeClockRuntimeDxe/PcatRealTimeClockRuntimeDxe.inf {
    <PcdsFixedAtBuild>
    gPcAtChipsetPkgTokenSpaceGuid.PcdRealTimeClockUpdateTimeout|500000
  }
  MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf {
    <LibraryClasses>
!if $(SECURE_BOOT_ENABLE)
      NULL|SecurityPkg/Library/DxeImageVerificationLib/DxeImageVerificationLib.inf
!endif
!if $(MEASURED_BOOT_ENABLE) == TRUE
      NULL|SecurityPkg/Library/DxeTpm2MeasureBootLib/DxeTpm2MeasureBootLib.inf
!endif
  }

  #
  # Following are the DXE drivers
  #
  MdeModulePkg/Universal/PCD/Dxe/Pcd.inf {
    <LibraryClasses>
      PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
  }

  MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  UefiCpuPkg/CpuIo2Dxe/CpuIo2Dxe.inf
  MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  MdeModulePkg/Universal/MemoryTest/NullMemoryTestDxe/NullMemoryTestDxe.inf
  OvmfPkg/8259InterruptControllerDxe/8259.inf
  MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  MdeModulePkg/Universal/SetupBrowserDxe/SetupBrowserDxe.inf
  MdeModulePkg/Universal/DisplayEngineDxe/DisplayEngineDxe.inf

  UefiPlatformPkg/Override/UefiPayloadPkg/BlSupportDxe/BlSupportDxe.inf
  PldCommonPkg/FirmwarePerformanceDxe/FirmwarePerformanceDxe.inf

  #
  # SMBIOS Support
  #
  MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf

  #
  # ACPI Support
  #
  MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf

  #
  # PCI Support
  #
  MdeModulePkg/Bus/Pci/PciBusDxe/PciBusDxe.inf
  MdeModulePkg/Bus/Pci/PciHostBridgeDxe/PciHostBridgeDxe.inf {
    <LibraryClasses>
      PciHostBridgeLib|AdlpPlatformPkg/Override/UefiPayloadPkg/Library/PciHostBridgeLib/PciHostBridgeLib.inf
  }

  #
  # SCSI/ATA/IDE/DISK Support
  #
  MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf
  FatPkg/EnhancedFatDxe/Fat.inf
  MdeModulePkg/Bus/Pci/SataControllerDxe/SataControllerDxe.inf
  MdeModulePkg/Bus/Ata/AtaBusDxe/AtaBusDxe.inf
  MdeModulePkg/Bus/Ata/AtaAtapiPassThru/AtaAtapiPassThru.inf
  MdeModulePkg/Bus/Scsi/ScsiBusDxe/ScsiBusDxe.inf
  MdeModulePkg/Bus/Scsi/ScsiDiskDxe/ScsiDiskDxe.inf

  #
  # UFS Support
  #
  MdeModulePkg/Bus/Pci/UfsPciHcDxe/UfsPciHcDxe.inf
  PldCommonPkg/Bus/Ufs/UfsPassThruDxe/UfsPassThruDxe.inf
  PldCommonPkg/UfsPlatform/UfsPlatform.inf
  #
  # SD/eMMC Support
  #
  MdeModulePkg/Bus/Pci/SdMmcPciHcDxe/SdMmcPciHcDxe.inf
  MdeModulePkg/Bus/Sd/EmmcDxe/EmmcDxe.inf
  MdeModulePkg/Bus/Sd/SdDxe/SdDxe.inf

  #
  # Nvme Support
  #
  MdeModulePkg/Bus/Pci/NvmExpressDxe/NvmExpressDxe.inf

  #
  # Usb Support
  #
  MdeModulePkg/Bus/Pci/UhciDxe/UhciDxe.inf
  MdeModulePkg/Bus/Pci/EhciDxe/EhciDxe.inf
  MdeModulePkg/Bus/Pci/XhciDxe/XhciDxe.inf
  MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  #
  # ISA Support
  #
  MdeModulePkg/Universal/SerialDxe/SerialDxe.inf

  #
  # Console Support
  #
  MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf
  MdeModulePkg/Universal/Console/TerminalDxe/TerminalDxe.inf

  #
  # PCI Platform
  #
  PldCommonPkg/PciPlatformDxe/PciPlatformDxe.inf

  #
  # Framebuffer Gop
  #
!if $(INTEL_GOP_ENABLE) == TRUE
  $(PLATFORM_PATH)/GopPolicyDxe/GopPolicy.inf
!else
  UefiPayloadPkg/GraphicsOutputDxe/GraphicsOutputDxe.inf
!endif

  OvmfPkg/QemuVideoDxe/QemuVideoDxe.inf

  IntelFsp2WrapperPkg/FspWrapperNotifyDxe/FspWrapperNotifyDxe.inf

  PldCommonPkg/PowerButtonHandler/PowerButtonHandler.inf

!if $(EMU_VARIABLE_ENABLE) == TRUE
  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
!else
  #
  # SMM Support
  #
  PldCommonPkg/SmmAccessDxe/SmmAccessDxe.inf
  PldCommonPkg/SmmControlDxe/SmmControlDxe.inf
  PldPlatform/PldCommonPkg/BlSmmSupport/BlSmmSupport.inf
  MdeModulePkg/Core/PiSmmCore/PiSmmIpl.inf
  MdeModulePkg/Core/PiSmmCore/PiSmmCore.inf
  PldCommonPkg/BlSwSmiHandler/BlSwSmiHandler.inf
!if $(BOOTLOADER) == "COREBOOT"
  PldCommonPkg/UefiSmmInitSmm/UefiSmmInitSmm.inf
!else
  UefiCpuPkg/PiSmmCpuDxeSmm/PiSmmCpuDxeSmm.inf
!endif

  UefiCpuPkg/CpuIo2Smm/CpuIo2Smm.inf

  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableSmm.inf {
    <LibraryClasses>
      NULL|MdeModulePkg/Library/VarCheckUefiLib/VarCheckUefiLib.inf
      NULL|MdeModulePkg/Library/VarCheckHiiLib/VarCheckHiiLib.inf
      NULL|MdeModulePkg/Library/VarCheckPcdLib/VarCheckPcdLib.inf
  }

  PldCommonPkg/FvbRuntimeDxe/FvbSmm.inf

  MdeModulePkg/Universal/FaultTolerantWriteDxe/FaultTolerantWriteSmm.inf
  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableSmmRuntimeDxe.inf
!if $(SECURE_BOOT_ENABLE)
  SecurityPkg/VariableAuthenticated/SecureBootConfigDxe/SecureBootConfigDxe.inf
!endif

!endif  #EMU_VARIABLE_ENABLE

!if $(MEASURED_BOOT_ENABLE) == TRUE
  SecurityPkg/Tcg/Tcg2Config/Tcg2ConfigDxe.inf {
  <LibraryClasses>
      Tpm2CommandLib|SecurityPkg/Library/Tpm2CommandLib/Tpm2CommandLib.inf
      Tpm2DeviceLib|SecurityPkg/Library/Tpm2DeviceLibRouter/Tpm2DeviceLibRouterDxe.inf
      NULL|SecurityPkg/Library/Tpm2DeviceLibDTpm/Tpm2InstanceLibDTpm.inf
  }

  PldCommonPkg/Tcg/Tcg2Smm/Tcg2Smm.inf {
    <LibraryClasses>
      Tpm2DeviceLib|SecurityPkg/Library/Tpm2DeviceLibTcg2/Tpm2DeviceLibTcg2.inf
  }

  PldCommonPkg/Tcg/Tcg2Dxe/Tcg2Dxe.inf {
    <LibraryClasses>
      Tpm2DeviceLib|SecurityPkg/Library/Tpm2DeviceLibRouter/Tpm2DeviceLibRouterDxe.inf
      HashLib|SecurityPkg/Library/HashLibBaseCryptoRouter/HashLibBaseCryptoRouterDxe.inf
      NULL|SecurityPkg/Library/Tpm2DeviceLibDTpm/Tpm2InstanceLibDTpm.inf
      NULL|SecurityPkg/Library/HashInstanceLibSha1/HashInstanceLibSha1.inf
      NULL|SecurityPkg/Library/HashInstanceLibSha256/HashInstanceLibSha256.inf
      NULL|SecurityPkg/Library/HashInstanceLibSha384/HashInstanceLibSha384.inf
      NULL|SecurityPkg/Library/HashInstanceLibSm3/HashInstanceLibSm3.inf
  }
  PldCommonPkg/Tcg2PlatformDxe/Tcg2PlatformDxe.inf
!endif #MEASURED_BOOT_ENABLE

!if $(PERFORMANCE_ENABLE) == TRUE
  PerformancePkg/Dp_App/Dp.inf {
  <LibraryClasses>
    PerformanceLib|MdeModulePkg/Library/DxePerformanceLib/DxePerformanceLib.inf
    ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
    FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  }
!endif



  #------------------------------
  #  Build the shell
  #------------------------------
!if $(SHELL_TYPE) == BUILD_SHELL

  ShellPkg/DynamicCommand/TftpDynamicCommand/TftpDynamicCommand.inf {
    <PcdsFixedAtBuild>
      ## This flag is used to control initialization of the shell library
      #  This should be FALSE for compiling the dynamic command.
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE
  }
  ShellPkg/DynamicCommand/DpDynamicCommand/DpDynamicCommand.inf {
    <PcdsFixedAtBuild>
      ## This flag is used to control initialization of the shell library
      #  This should be FALSE for compiling the dynamic command.
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE
  }
  ShellPkg/Application/Shell/Shell.inf {
    <PcdsFixedAtBuild>
      ## This flag is used to control initialization of the shell library
      #  This should be FALSE for compiling the shell application itself only.
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE

    #------------------------------
    #  Basic commands
    #------------------------------

    <LibraryClasses>
      NULL|ShellPkg/Library/UefiShellLevel1CommandsLib/UefiShellLevel1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel2CommandsLib/UefiShellLevel2CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel3CommandsLib/UefiShellLevel3CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDriver1CommandsLib/UefiShellDriver1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellInstall1CommandsLib/UefiShellInstall1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDebug1CommandsLib/UefiShellDebug1CommandsLib.inf

    #------------------------------
    #  Networking commands
    #------------------------------

    <LibraryClasses>
      NULL|ShellPkg/Library/UefiShellNetwork1CommandsLib/UefiShellNetwork1CommandsLib.inf

    #------------------------------
    #  Support libraries
    #------------------------------

    <LibraryClasses>
      DebugLib|MdePkg/Library/UefiDebugLibConOut/UefiDebugLibConOut.inf
      DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
      HandleParsingLib|ShellPkg/Library/UefiHandleParsingLib/UefiHandleParsingLib.inf
      PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
      ShellCEntryLib|ShellPkg/Library/UefiShellCEntryLib/UefiShellCEntryLib.inf
      ShellCommandLib|ShellPkg/Library/UefiShellCommandLib/UefiShellCommandLib.inf
      SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf
  }

!endif

#
# Platform specific drivers
#
$(PLATFORM_PATH)/HeciInitDxe/HeciInitDxe.inf {
  <PcdsFixedAtBuild>
    gEfiMdePkgTokenSpaceGuid.PcdFixedDebugPrintErrorLevel | 0x80000003
}
