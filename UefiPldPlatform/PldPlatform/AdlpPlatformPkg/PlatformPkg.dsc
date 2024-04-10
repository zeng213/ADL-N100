## @file
# Bootloader Payload Package
#
# Provides drivers and definitions to create uefi payload for bootloaders.
#
# Copyright (c) 2014 - 2023, Intel Corporation. All rights reserved.<BR>
# This program and the accompanying materials are licensed and made available under
# the terms and conditions of the BSD License that accompanies this distribution.
# The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php.
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  DEFINE PLATFORM_PACKAGE             = AdlpPlatformPkg
  DEFINE PLATFORM_COMMON_PACKAGE      = AdlpPlatformPkg
  PLATFORM_NAME                       = $(PLATFORM_PACKAGE)X64
  SUPPORTED_ARCHITECTURES             = IA32|X64
  PLATFORM_GUID                       = 66CFCF39-4493-411f-B4DE-D8D05CCD2C56
  PLATFORM_VERSION                    = 0.1
  DSC_SPECIFICATION                   = 0x00010005
  BUILD_TARGETS                       = DEBUG|RELEASE|NOOPT
  SKUID_IDENTIFIER                    = DEFAULT
  OUTPUT_DIRECTORY                    = Build/$(PLATFORM_NAME)
  DEFINE PLATFORM_PATH                = $(PLATFORM_COMMON_PACKAGE)
  FLASH_DEFINITION                    = $(PLATFORM_PATH)/PlatformPkg.fdf

  #
  # Specify the supported boards of this PlatformPkg
  # ('board' argument of BuildPayload.py build command)
  # Leave it blank if not used
  # Concatenate with separator '|' for multiple boards
  #
  SUPPORTED_BOARDS                    = Adl|Adls|Adln|Adlp|Adlps

  #
  # TRUE:  Use EMU variable driver.
  # FALSE: Use real variable driver.
  #
  DEFINE EMU_VARIABLE_ENABLE          = FALSE

  #
  # SBL:      UEFI payload for Slim Bootloader
  # COREBOOT: UEFI payload for coreboot
  #
  DEFINE BOOTLOADER = SBL

  #
  # TRUE:  Enable image verification
  # FALSE: Disable image verification.
  #
  DEFINE SECURE_BOOT_ENABLE           = TRUE

  #
  # TRUE:  Build in TPM modules.
  # FALSE: NOT build in TPM modules.
  #
  DEFINE MEASURED_BOOT_ENABLE         = TRUE
  DEFINE SOURCE_DEBUG_ENABLE          = FALSE
  
  #
  # Intel GOP support
  #
  DEFINE INTEL_GOP_ENABLE             = FALSE

  #
  # CPU options
  #
  DEFINE MAX_LOGICAL_PROCESSORS       = 64

  #
  # Serial port set up
  #
  DEFINE SERIAL_LINE_CONTROL          = 3 # 8-bits, no parity
  DEFINE SERIAL_HARDWARE_FLOW_CONTROL = FALSE
  DEFINE SERIAL_DETECT_CABLE          = FALSE
  DEFINE SERIAL_FIFO_CONTROL          = 7 # Enable FIFO
  DEFINE SERIAL_EXTENDED_TX_FIFO_SIZE = 16
  DEFINE UART_DEFAULT_DATA_BITS       = 8
  DEFINE UART_DEFAULT_PARITY          = 1
  DEFINE UART_DEFAULT_STOP_BITS       = 1
  DEFINE DEFAULT_TERMINAL_TYPE        = 0

  #
  #  typedef struct {
  #    UINT16  VendorId;          ///< Vendor ID to match the PCI device.  The value 0xFFFF terminates the list of entries.
  #    UINT16  DeviceId;          ///< Device ID to match the PCI device
  #    UINT32  ClockRate;         ///< UART clock rate.  Set to 0 for default clock rate of 1843200 Hz
  #    UINT64  Offset;            ///< The byte offset into to the BAR
  #    UINT8   BarIndex;          ///< Which BAR to get the UART base address
  #    UINT8   RegisterStride;    ///< UART register stride in bytes.  Set to 0 for default register stride of 1 byte.
  #    UINT16  ReceiveFifoDepth;  ///< UART receive FIFO depth in bytes. Set to 0 for a default FIFO depth of 16 bytes.
  #    UINT16  TransmitFifoDepth; ///< UART transmit FIFO depth in bytes. Set to 0 for a default FIFO depth of 16 bytes.
  #    UINT8   Reserved[2];
  #  } PCI_SERIAL_PARAMETER;
  #
  # Vendor FFFF Device 0000 Prog Interface 1, BAR #0, Offset 0, Stride = 1, Clock 1843200 (0x1c2000)
  #
  #                                       [Vendor]   [Device]  [----ClockRate---]  [------------Offset-----------] [Bar] [Stride] [RxFifo] [TxFifo]   [Rsvd]   [Vendor]
  DEFINE PCI_SERIAL_PARAMETERS        = {0xff,0xff, 0x00,0x00, 0x0,0x20,0x1c,0x00, 0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0, 0x00,    0x01, 0x0,0x0, 0x0,0x0, 0x0,0x0, 0xff,0xff}

  #
  # Shell options: [BUILD_SHELL, MIN_BIN, NONE, UEFI_BIN]
  #
  DEFINE SHELL_TYPE                   = BUILD_SHELL

!if ($(SECURE_BOOT_ENABLE) == TRUE) || ($(MEASURED_BOOT_ENABLE) == TRUE)
  DEFINE EMU_VARIABLE_ENABLE          = FALSE
!endif

[BuildOptions]
  GCC:DEBUG_*_*_CC_FLAGS         = -Os -flto
  GCC:DEBUG_*_*_DLINK_FLAGS      = -flto
  GCC:*_UNIXGCC_*_CC_FLAGS       = -DMDEPKG_NDEBUG
  GCC:RELEASE_*_*_CC_FLAGS       = -DMDEPKG_NDEBUG
  INTEL:RELEASE_*_*_CC_FLAGS     = /D MDEPKG_NDEBUG
  MSFT:RELEASE_*_*_CC_FLAGS      = /D MDEPKG_NDEBUG
!if $(VP_BIOS_ENABLE) == TRUE
  MSFT:*_*_*_CC_FLAGS            = /D VP_BIOS_ENABLE
!endif
!if $(BOOTLOADER) == "SBL"
  MSFT:*_*_*_CC_FLAGS            = /D SLIMBOOTLOADER_ENABLE
!endif

#
# Force PE/COFF sections to be aligned at 4KB boundaries to support page level
# protection of DXE_RUNTIME_DRIVER modules
#
[BuildOptions.common.EDKII.DXE_RUNTIME_DRIVER]
  MSFT:*_*_*_DLINK_FLAGS = /ALIGN:4096
  GCC:*_*_*_DLINK_FLAGS = -z common-page-size=0x1000

#
# Force PE/COFF sections to be aligned at 4KB boundaries to support page level
# protection of DXE_SMM_DRIVER/SMM_CORE modules
#
[BuildOptions.common.EDKII.DXE_SMM_DRIVER, BuildOptions.common.EDKII.SMM_CORE]
  MSFT:*_*_*_DLINK_FLAGS = /ALIGN:4096
  GCC:*_*_*_DLINK_FLAGS = -z common-page-size=0x1000

################################################################################
#
# SKU Identification section - list of all SKU IDs supported by this Platform.
#
################################################################################
[SkuIds]
  0|DEFAULT

################################################################################
#
# Library Class section - list of all Library Classes needed by this Platform.
#
################################################################################
[LibraryClasses]
  #
  # Entry point
  #
  PeiCoreEntryPoint|MdePkg/Library/PeiCoreEntryPoint/PeiCoreEntryPoint.inf
  PeimEntryPoint|MdePkg/Library/PeimEntryPoint/PeimEntryPoint.inf
  DxeCoreEntryPoint|MdePkg/Library/DxeCoreEntryPoint/DxeCoreEntryPoint.inf
  UefiDriverEntryPoint|MdePkg/Library/UefiDriverEntryPoint/UefiDriverEntryPoint.inf
  UefiApplicationEntryPoint|MdePkg/Library/UefiApplicationEntryPoint/UefiApplicationEntryPoint.inf

  #
  # Basic
  #
  BaseLib|MdePkg/Library/BaseLib/BaseLib.inf
  BaseMemoryLib|MdePkg/Library/BaseMemoryLibRepStr/BaseMemoryLibRepStr.inf
  SynchronizationLib|MdePkg/Library/BaseSynchronizationLib/BaseSynchronizationLib.inf
  PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
  CpuLib|MdePkg/Library/BaseCpuLib/BaseCpuLib.inf
  IoLib|MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsic.inf
  PciLib|MdePkg/Library/BasePciLibPciExpress/BasePciLibPciExpress.inf
  PciExpressLib|MdePkg/Library/BasePciExpressLib/BasePciExpressLib.inf
  PciSegmentLib|MdePkg/Library/PciSegmentLibSegmentInfo/BasePciSegmentLibSegmentInfo.inf
  PciSegmentInfoLib|UefiPlatformPkg/Library/PciSegmentInfoLibAcpiBoardInfo/PciSegmentInfoLibAcpiBoardInfo.inf
  PeCoffLib|MdePkg/Library/BasePeCoffLib/BasePeCoffLib.inf
  PeCoffGetEntryPointLib|MdePkg/Library/BasePeCoffGetEntryPointLib/BasePeCoffGetEntryPointLib.inf
  CacheMaintenanceLib|MdePkg/Library/BaseCacheMaintenanceLib/BaseCacheMaintenanceLib.inf

  #
  # UEFI & PI
  #
  UefiBootServicesTableLib|MdePkg/Library/UefiBootServicesTableLib/UefiBootServicesTableLib.inf
  UefiRuntimeServicesTableLib|MdePkg/Library/UefiRuntimeServicesTableLib/UefiRuntimeServicesTableLib.inf
  UefiRuntimeLib|MdePkg/Library/UefiRuntimeLib/UefiRuntimeLib.inf
  UefiLib|MdePkg/Library/UefiLib/UefiLib.inf
  UefiHiiServicesLib|MdeModulePkg/Library/UefiHiiServicesLib/UefiHiiServicesLib.inf
  HiiLib|MdeModulePkg/Library/UefiHiiLib/UefiHiiLib.inf
  DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
  UefiDecompressLib|MdePkg/Library/BaseUefiDecompressLib/BaseUefiDecompressLib.inf
  PeiServicesTablePointerLib|MdePkg/Library/PeiServicesTablePointerLibIdt/PeiServicesTablePointerLibIdt.inf
  PeiServicesLib|MdePkg/Library/PeiServicesLib/PeiServicesLib.inf
  DxeServicesLib|MdePkg/Library/DxeServicesLib/DxeServicesLib.inf
  DxeServicesTableLib|MdePkg/Library/DxeServicesTableLib/DxeServicesTableLib.inf
  UefiCpuLib|UefiCpuPkg/Library/BaseUefiCpuLib/BaseUefiCpuLib.inf
  SortLib|MdeModulePkg/Library/UefiSortLib/UefiSortLib.inf

  #
  # Generic Modules
  #
  UefiUsbLib|MdePkg/Library/UefiUsbLib/UefiUsbLib.inf
  UefiScsiLib|MdePkg/Library/UefiScsiLib/UefiScsiLib.inf
  OemHookStatusCodeLib|MdeModulePkg/Library/OemHookStatusCodeLibNull/OemHookStatusCodeLibNull.inf
  CapsuleLib|MdeModulePkg/Library/DxeCapsuleLibNull/DxeCapsuleLibNull.inf
  SecurityManagementLib|MdeModulePkg/Library/DxeSecurityManagementLib/DxeSecurityManagementLib.inf
  UefiBootManagerLib|MdeModulePkg/Library/UefiBootManagerLib/UefiBootManagerLib.inf
  CustomizedDisplayLib|MdeModulePkg/Library/CustomizedDisplayLib/CustomizedDisplayLib.inf

  #
  # CPU
  #
  MtrrLib|UefiCpuPkg/Library/MtrrLib/MtrrLib.inf
  LocalApicLib|UefiCpuPkg/Library/BaseXApicX2ApicLib/BaseXApicX2ApicLib.inf

  #
  # Platform
  #
  TimerLib|UefiPayloadPkg/Library/AcpiTimerLib/AcpiTimerLib.inf
  ResetSystemLib|UefiPayloadPkg/Library/ResetSystemLib/ResetSystemLib.inf
  SerialPortLib|MdeModulePkg/Library/BaseSerialPortLib16550/BaseSerialPortLib16550.inf
  PlatformHookLib|UefiPayloadPkg/Library/PlatformHookLib/PlatformHookLib.inf
!if $(MEASURED_BOOT_ENABLE) == TRUE
  PlatformBootManagerLib|PldCommonPkg/UefiPayloadPkg/Library/PlatformBootManagerLib/PlatformBootManagerLib.inf
!else
  PlatformBootManagerLib|UefiPayloadPkg/Library/PlatformBootManagerLib/PlatformBootManagerLib.inf
!endif
  IoApicLib|PcAtChipsetPkg/Library/BaseIoApicLib/BaseIoApicLib.inf

  #
  # Misc
  #
  DebugPrintErrorLevelLib|MdePkg/Library/BaseDebugPrintErrorLevelLib/BaseDebugPrintErrorLevelLib.inf
  PerformanceLib|MdePkg/Library/BasePerformanceLibNull/BasePerformanceLibNull.inf
  PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
!if $(SOURCE_DEBUG_ENABLE) == TRUE
  PeCoffExtraActionLib|SourceLevelDebugPkg/Library/PeCoffExtraActionLibDebug/PeCoffExtraActionLibDebug.inf
  DebugCommunicationLib|SourceLevelDebugPkg/Library/DebugCommunicationLibSerialPort/DebugCommunicationLibSerialPort.inf
!else
  PeCoffExtraActionLib|MdePkg/Library/BasePeCoffExtraActionLibNull/BasePeCoffExtraActionLibNull.inf
  DebugAgentLib|MdeModulePkg/Library/DebugAgentLibNull/DebugAgentLibNull.inf
!endif

!if $(BOOTLOADER) == "COREBOOT"
  BlParseLib|UefiPayloadPkg/Library/CbParseLib/CbParseLib.inf
  PlatformSupportLib|PldCommonPkg/Library/PlatformSupportLibCb/PlatformSupportLibCb.inf
!else
  BlParseLib|UefiPlatformPkg/Override/UefiPayloadPkg/Library/SblParseLib/SblParseLib.inf
  PlatformSupportLib|AdlpPlatformPkg/Override/PldCommonPkg/Library/PlatformSupportLibSbl/PlatformSupportLibSbl.inf

!if $(MEASURED_BOOT_ENABLE) == TRUE
  Tcg2SupportLib|PldCommonPkg/Library/Tcg2SupportLib/Tcg2SupportLib.inf
!else
  Tcg2SupportLib|PldCommonPkg/Library/Tcg2SupportLibNull/Tcg2SupportLibNull.inf
!endif
!endif

  VmgExitLib|UefiCpuPkg/Library/VmgExitLibNull/VmgExitLibNull.inf
  DebugLib|MdePkg/Library/BaseDebugLibSerialPort/BaseDebugLibSerialPort.inf
  LockBoxLib|MdeModulePkg/Library/LockBoxNullLib/LockBoxNullLib.inf
  FileExplorerLib|MdeModulePkg/Library/FileExplorerLib/FileExplorerLib.inf
  FspWrapperApiLib|IntelFsp2WrapperPkg/Library/BaseFspWrapperApiLib/BaseFspWrapperApiLib.inf
  FspWrapperPlatformLib|IntelFsp2WrapperPkg/Library/BaseFspWrapperPlatformLibSample/BaseFspWrapperPlatformLibSample.inf
  VarCheckLib|MdeModulePkg/Library/VarCheckLib/VarCheckLib.inf
  FrameBufferBltLib|MdeModulePkg/Library/FrameBufferBltLib/FrameBufferBltLib.inf

  #
  # Crypto
  #
!if ($(EMU_VARIABLE_ENABLE) == FALSE)
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/BaseCryptLib.inf
  IntrinsicLib|CryptoPkg/Library/IntrinsicLib/IntrinsicLib.inf
  OpensslLib|CryptoPkg/Library/OpensslLib/OpensslLib.inf
!endif

!if $(SECURE_BOOT_ENABLE)
  AuthVariableLib|SecurityPkg/Library/AuthVariableLib/AuthVariableLib.inf
!else
  AuthVariableLib|MdeModulePkg/Library/AuthVariableLibNull/AuthVariableLibNull.inf
!endif

  ReportStatusCodeLib|MdePkg/Library/BaseReportStatusCodeLibNull/BaseReportStatusCodeLibNull.inf
  #
  # TPM
  #
!if $(MEASURED_BOOT_ENABLE) == TRUE
  Tpm2CommandLib|SecurityPkg/Library/Tpm2CommandLib/Tpm2CommandLib.inf
  Tpm2DeviceLib|SecurityPkg/Library/Tpm2DeviceLibTcg2/Tpm2DeviceLibTcg2.inf
  Tcg2PhysicalPresenceLib|SecurityPkg/Library/DxeTcg2PhysicalPresenceLib/DxeTcg2PhysicalPresenceLib.inf
  Tcg2PpVendorLib|SecurityPkg/Library/Tcg2PpVendorLibNull/Tcg2PpVendorLibNull.inf
!endif

  #
  # Authenticated Variable
  #
!if $(EMU_VARIABLE_ENABLE) == TRUE
  TpmMeasurementLib|MdeModulePkg/Library/TpmMeasurementLibNull/TpmMeasurementLibNull.inf
!else
  PlatformSecureLib|SecurityPkg/Library/PlatformSecureLibNull/PlatformSecureLibNull.inf
  TpmMeasurementLib|SecurityPkg/Library/DxeTpmMeasurementLib/DxeTpmMeasurementLib.inf
  S3BootScriptLib|MdePkg/Library/BaseS3BootScriptLibNull/BaseS3BootScriptLibNull.inf
!endif

  #
  # Shell Libraries
  #
  BcfgCommandLib|ShellPkg/Library/UefiShellBcfgCommandLib/UefiShellBcfgCommandLib.inf
  DevicePathLib|MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.inf
  FileHandleLib|MdePkg/Library/UefiFileHandleLib/UefiFileHandleLib.inf
  ShellLib|ShellPkg/Library/UefiShellLib/UefiShellLib.inf
  NetLib|NetworkPkg/Library/DxeNetLib/DxeNetLib.inf

[LibraryClasses.common.SEC]
  PrePiLib|UefiPlatformPkg/Override/EmbeddedPkg/Library/PrePiLib/PrePiLib.inf
  MemoryAllocationLib|EmbeddedPkg/Library/PrePiMemoryAllocationLib/PrePiMemoryAllocationLib.inf
  HobLib|EmbeddedPkg/Library/PrePiHobLib/PrePiHobLib.inf
  ExtractGuidedSectionLib|EmbeddedPkg/Library/PrePiExtractGuidedSectionLib/PrePiExtractGuidedSectionLib.inf
  PrePiHobListPointerLib|UefiPlatformPkg/Library/PrePiHobListPointerLib/PrePiHobListPointerLib.inf
  PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf

[LibraryClasses.common.DXE_CORE]
  PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
  HobLib|MdePkg/Library/DxeCoreHobLib/DxeCoreHobLib.inf
  MemoryAllocationLib|MdeModulePkg/Library/DxeCoreMemoryAllocationLib/DxeCoreMemoryAllocationLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
!if $(SOURCE_DEBUG_ENABLE)
  DebugAgentLib|SourceLevelDebugPkg/Library/DebugAgent/DxeDebugAgentLib.inf
!endif
  CpuExceptionHandlerLib|UefiCpuPkg/Library/CpuExceptionHandlerLib/DxeCpuExceptionHandlerLib.inf

!if $(PERFORMANCE_ENABLE) == TRUE
  PerformanceLib|MdeModulePkg/Library/DxeCorePerformanceLib/DxeCorePerformanceLib.inf
!endif

[LibraryClasses.common.DXE_DRIVER]
  PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf
  ExtractGuidedSectionLib|MdePkg/Library/DxeExtractGuidedSectionLib/DxeExtractGuidedSectionLib.inf
  ReportStatusCodeLib|MdeModulePkg/Library/DxeReportStatusCodeLib/DxeReportStatusCodeLib.inf
!if $(SOURCE_DEBUG_ENABLE)
  DebugAgentLib|SourceLevelDebugPkg/Library/DebugAgent/DxeDebugAgentLib.inf
!endif
  CpuExceptionHandlerLib|UefiCpuPkg/Library/CpuExceptionHandlerLib/DxeCpuExceptionHandlerLib.inf
  MpInitLib|UefiCpuPkg/Library/MpInitLib/DxeMpInitLib.inf
!if $(PERFORMANCE_ENABLE) == TRUE
  PerformanceLib|MdeModulePkg/Library/DxePerformanceLib/DxePerformanceLib.inf
!endif

[LibraryClasses.common.DXE_RUNTIME_DRIVER]
  PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf

!if ($(EMU_VARIABLE_ENABLE) == FALSE)
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/RuntimeCryptLib.inf
!endif

[LibraryClasses.common.UEFI_DRIVER,LibraryClasses.common.UEFI_APPLICATION]
  PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
  MemoryAllocationLib|MdePkg/Library/UefiMemoryAllocationLib/UefiMemoryAllocationLib.inf

  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
[LibraryClasses.common.SMM_CORE]
!if $(EMU_VARIABLE_ENABLE) == FALSE
  PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf
  SmmServicesTableLib|MdeModulePkg/Library/PiSmmCoreSmmServicesTableLib/PiSmmCoreSmmServicesTableLib.inf

  MemoryAllocationLib|MdeModulePkg/Library/PiSmmCoreMemoryAllocationLib/PiSmmCoreMemoryAllocationLib.inf
  SmmCorePlatformHookLib|PldCommonPkg/Library/SmmCorePlatformHookLib/SmmCorePlatformHookLib.inf
  SmmMemLib|MdePkg/Library/SmmMemLib/SmmMemLib.inf
!endif

[LibraryClasses.common.DXE_SMM_DRIVER]
!if $(EMU_VARIABLE_ENABLE) == FALSE
  PcdLib|MdePkg/Library/DxePcdLib/DxePcdLib.inf
  HobLib|MdePkg/Library/DxeHobLib/DxeHobLib.inf

  MemoryAllocationLib|MdePkg/Library/SmmMemoryAllocationLib/SmmMemoryAllocationLib.inf
  SmmServicesTableLib|MdePkg/Library/SmmServicesTableLib/SmmServicesTableLib.inf
  SmmMemLib|MdePkg/Library/SmmMemLib/SmmMemLib.inf
  MmServicesTableLib|MdePkg/Library/MmServicesTableLib/MmServicesTableLib.inf
  DebugLib|MdePkg/Library/BaseDebugLibSerialPort/BaseDebugLibSerialPort.inf
  SmmCpuPlatformHookLib|UefiCpuPkg/Library/SmmCpuPlatformHookLibNull/SmmCpuPlatformHookLibNull.inf
  SmmCpuFeaturesLib|$(PLATFORM_PATH)/Override/UefiCpuPkg/Library/SmmCpuFeaturesLib/SmmCpuFeaturesLib.inf
  CpuExceptionHandlerLib|UefiCpuPkg/Library/CpuExceptionHandlerLib/SmmCpuExceptionHandlerLib.inf
  SpiFlashLib|PldCommonPkg/Library/SpiFlashLib/SpiFlashLib.inf
  FlashDeviceLib|PldCommonPkg/Library/FlashDeviceLibSpi/FlashDeviceLib.inf
  BlSmmCommunicationLib|PldCommonPkg/Library/BlSmmCommunicationLib/BlSmmCommunicationLib.inf
!endif

!if $(MEASURED_BOOT_ENABLE) == TRUE
 Tcg2PhysicalPresenceLib|SecurityPkg/Library/SmmTcg2PhysicalPresenceLib/SmmTcg2PhysicalPresenceLib.inf
!endif

!if $(EMU_VARIABLE_ENABLE) == FALSE
  BaseCryptLib|CryptoPkg/Library/BaseCryptLib/SmmCryptLib.inf
!endif

################################################################################
#
# Pcd Section - list of all EDK II PCD Entries defined by this Platform.
#
################################################################################
[PcdsFeatureFlag]
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutGopSupport|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutUgaSupport|FALSE
  gEfiMdeModulePkgTokenSpaceGuid.PcdDxeIplSwitchToLongMode|TRUE
  gUefiCpuPkgTokenSpaceGuid.PcdCpuSmmEnableBspElection|FALSE

[PcdsFixedAtBuild]
  gEfiMdeModulePkgTokenSpaceGuid.PcdStatusCodeUseSerial|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdStatusCodeUseMemory|FALSE
!if $(SECURE_BOOT_ENABLE) == TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdMaxVariableSize            |0x10000
!else
  gEfiMdeModulePkgTokenSpaceGuid.PcdMaxVariableSize            |0x8000
!endif

  gEfiMdeModulePkgTokenSpaceGuid.PcdVariableStoreSize            | 0x10000

  gEfiMdeModulePkgTokenSpaceGuid.PcdVpdBaseAddress|0x0
  gEfiMdeModulePkgTokenSpaceGuid.PcdUse1GPageTable|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdBootManagerMenuFile|{ 0x21, 0xaa, 0x2c, 0x46, 0x14, 0x76, 0x03, 0x45, 0x83, 0x6e, 0x8a, 0xb6, 0xf4, 0x66, 0x23, 0x31 }

  gIntelFsp2WrapperTokenSpaceGuid.PcdSkipFspApi|0x00010000

!if $(SOURCE_DEBUG_ENABLE)
  gEfiSourceLevelDebugPkgTokenSpaceGuid.PcdDebugLoadImageMethod|0x2
!endif
!if $(SECURE_BOOT_ENABLE)
  # override the default values from SecurityPkg to ensure images from all sources are verified in secure boot
  gEfiSecurityPkgTokenSpaceGuid.PcdOptionRomImageVerificationPolicy|0x04
  gEfiSecurityPkgTokenSpaceGuid.PcdFixedMediaImageVerificationPolicy|0x04
  gEfiSecurityPkgTokenSpaceGuid.PcdRemovableMediaImageVerificationPolicy|0x04
!endif

!if $(EMU_VARIABLE_ENABLE) == TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdEmuVariableNvModeEnable        |TRUE
!else
  gEfiMdeModulePkgTokenSpaceGuid.PcdEmuVariableNvModeEnable        |FALSE
  gUefiPayloadPkgTokenSpaceGuid.PcdMemoryTypeEfiACPIReclaimMemory  |0x08
  gUefiPayloadPkgTokenSpaceGuid.PcdMemoryTypeEfiACPIMemoryNVS      |0x0A
  gUefiPayloadPkgTokenSpaceGuid.PcdMemoryTypeEfiReservedMemoryType |0x16
  gUefiPayloadPkgTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesData|0x400
  gUefiPayloadPkgTokenSpaceGuid.PcdMemoryTypeEfiRuntimeServicesCode|0x130
!endif

!if $(PERFORMANCE_ENABLE) == TRUE
  gEfiMdePkgTokenSpaceGuid.PcdPerformanceLibraryPropertyMask|0x1
  gEfiMdeModulePkgTokenSpaceGuid.PcdMaxPeiPerformanceLogEntries|60
!endif

# Test code added to enable secure boot menu options enable/disable config option
# and update custom certificates from secure boot menu
!if $(SECURE_BOOT_ENABLE) == TRUE
!if $(USERPHYSICALPRESENCE) == TRUE
  gEfiSecurityPkgTokenSpaceGuid.PcdUserPhysicalPresence|TRUE
!endif
!endif

  #
  # Set SMM stack size to 16 KB.
  #
  gUefiCpuPkgTokenSpaceGuid.PcdCpuSmmStackSize|0x4000

[PcdsFixedAtBuild.X64]
  gUefiCpuPkgTokenSpaceGuid.PcdCpuSmmRestrictedMemoryAccess|FALSE

[PcdsPatchableInModule.common]
  gEfiMdePkgTokenSpaceGuid.PcdReportStatusCodePropertyMask|0x7
  gEfiMdePkgTokenSpaceGuid.PcdDebugPrintErrorLevel|0x8000004F
!if $(SOURCE_DEBUG_ENABLE)
  gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x17
!else
  gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0x2F
!endif

  #
  # The following parameters are set by Library/PlatformHookLib
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialUseMmio|TRUE
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialRegisterBase|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialBaudRate|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialRegisterStride|0
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultBaudRate|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialClockRate|0

  #
  # Enable these parameters to be set on the command line
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialLineControl|$(SERIAL_LINE_CONTROL)
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialUseHardwareFlowControl|$(SERIAL_HARDWARE_FLOW_CONTROL)
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialDetectCable|$(SERIAL_DETECT_CABLE)
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialFifoControl|$(SERIAL_FIFO_CONTROL)
  gEfiMdeModulePkgTokenSpaceGuid.PcdSerialExtendedTxFifoSize|$(SERIAL_EXTENDED_TX_FIFO_SIZE)

  gEfiMdeModulePkgTokenSpaceGuid.PcdPciDisableBusEnumeration|TRUE

  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultDataBits|$(UART_DEFAULT_DATA_BITS)
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultParity|$(UART_DEFAULT_PARITY)
  gEfiMdePkgTokenSpaceGuid.PcdUartDefaultStopBits|$(UART_DEFAULT_STOP_BITS)
  gEfiMdePkgTokenSpaceGuid.PcdDefaultTerminalType|$(DEFAULT_TERMINAL_TYPE)
  gEfiMdeModulePkgTokenSpaceGuid.PcdPciSerialParameters|$(PCI_SERIAL_PARAMETERS)

  gUefiCpuPkgTokenSpaceGuid.PcdCpuMaxLogicalProcessorNumber|$(MAX_LOGICAL_PROCESSORS)


################################################################################
#
# Pcd Dynamic Section - list of all EDK II PCD Entries defined by this Platform
#
################################################################################

[PcdsDynamicDefault]
  gUefiOvmfPkgTokenSpaceGuid.PcdOvmfHostBridgePciDevId|0x1237
  gEfiMdePkgTokenSpaceGuid.PcdPciExpressBaseAddress|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdEmuVariableNvStoreReserved|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableBase64|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingBase|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareBase|0
  gEfiMdePkgTokenSpaceGuid.PcdPlatformBootTimeOut|3
  gIntelFsp2WrapperTokenSpaceGuid.PcdFspsBaseAddress|0
!if ($(EMU_VARIABLE_ENABLE) == FALSE)
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableSize  |0
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwWorkingSize|0
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageFtwSpareSize  |0
  gEfiMdeModulePkgTokenSpaceGuid.PcdFlashNvStorageVariableBase  |0
!endif
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiS3Enable|FALSE

  ## This PCD defines the video horizontal resolution.
  #  This PCD could be set to 0 then video resolution could be at highest resolution.
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|0
  ## This PCD defines the video vertical resolution.
  #  This PCD could be set to 0 then video resolution could be at highest resolution.
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|0

  ## The PCD is used to specify the video horizontal resolution of text setup.
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|0
  ## The PCD is used to specify the video vertical resolution of text setup.
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|0

  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|25
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|80


!if $(MEASURED_BOOT_ENABLE) == TRUE
  gEfiSecurityPkgTokenSpaceGuid.PcdTpmInstanceGuid|{0x5a, 0xf2, 0x6b, 0x28, 0xc3, 0xc2, 0x8c, 0x40, 0xb3, 0xb4, 0x25, 0xe6, 0x75, 0x8b, 0x73, 0x17}
  gEfiSecurityPkgTokenSpaceGuid.PcdFirmwareDebuggerInitialized|FALSE

  # (BIT0 - SHA1. BIT1 - SHA256, BIT2 - SHA384, BIT3 - SHA512, BIT4 - SM3_256)
  gEfiSecurityPkgTokenSpaceGuid.PcdTpm2HashMask|0x000000016
  gEfiSecurityPkgTokenSpaceGuid.PcdTcg2HashAlgorithmBitmap|0x000000016
!endif

!if $(MEASURED_BOOT_ENABLE) == TRUE
  gPldCommonPkgTokenSpaceGuid.PcdTpm2HierarchyChangeAuthPlatform|1
  gPldCommonPkgTokenSpaceGuid.PcdTpm2HierarchyControlPlatform|1
  gPldCommonPkgTokenSpaceGuid.PcdTpm2HierarchyControlEndorsement|1
  gPldCommonPkgTokenSpaceGuid.PcdTpm2HierarchyControlOwner|1
  gPldCommonPkgTokenSpaceGuid.PcdTpm2ChangeEps|0
  gPldCommonPkgTokenSpaceGuid.PcdTpm2ChangePps|0
  gPldCommonPkgTokenSpaceGuid.PcdTpm2Clear|0
!endif

################################################################################
#
# Components Section - list of all EDK II Modules needed by this Platform.
#
################################################################################

!if "IA32" in $(ARCH)
  [Components.IA32]
    UefiPlatformPkg/UefiPayloadEntry/UefiPayloadEntry.inf
!else
  [Components.X64]
    UefiPlatformPkg/UefiPayloadEntry/UefiPayloadEntry.inf
!endif

[Components.X64]
  !include DxeComponents.dsc

