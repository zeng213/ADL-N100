/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.c
  Abstract:       Auto-generated AutoGen.c for building module or library.
**/
#include <PiPei.h>
#include <Library/DebugLib.h>
#include <Library/PeimEntryPoint.h>

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEfiCallerIdGuid = {0xA68576FB, 0x074E, 0x4490, {0xA8, 0x2A, 0x7C, 0x56, 0x12, 0x1E, 0xCC, 0x56}};

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEdkiiDscPlatformGuid = {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}};

GLOBAL_REMOVE_IF_UNREFERENCED CHAR8 *gEfiCallerBaseName = "Stage1B";

// Guids
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformModuleTokenSpaceGuid = { 0x69d13bf0, 0xaf91, 0x4d96, { 0xaa, 0x9f, 0x21, 0x84, 0xc5, 0xce, 0x3b, 0xc0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFspReservedMemoryResourceHobGuid = { 0x69a79759, 0x1373, 0x4367, { 0xa6, 0xc4, 0xc7, 0xf5, 0x9e, 0xfd, 0x98, 0x6e } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformCommonLibTokenSpaceGuid = { 0x373657df, 0x5dc0, 0x4cbb, { 0x87, 0xad, 0x50, 0x1e, 0xb8, 0x89, 0xbf, 0x89 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdePkgTokenSpaceGuid = { 0x914AEBE7, 0x4635, 0x459b, { 0xAA, 0x1C, 0x11, 0xE2, 0x19, 0xB0, 0x3A, 0x10 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformAlderLakeTokenSpaceGuid = { 0xfec38282, 0xab42, 0x4aba, {0x8c, 0x25, 0xa4, 0x4e, 0x46, 0x23, 0xf7, 0x6e}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gTccRtctHobGuid = { 0x6bddb43d, 0x1782, 0x4d9c, { 0xb6, 0x80, 0xe3, 0xde, 0x45, 0xe0, 0x37, 0x4a } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gMeBiosPayloadHobGuid = { 0x992c52c8, 0xbc01, 0x4ecd, { 0x20, 0xbf, 0xf9, 0x57, 0x16, 0x0e, 0x9e, 0xf7 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gTcgEvent2EntryHobGuid = { 0xd26c221e, 0x2430, 0x4c8a, { 0x91, 0x70, 0x3f, 0xcb, 0x45, 0x0, 0x41, 0x3f  } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGraphicsDeviceInfoHobGuid = { 0xe5cb2ac9, 0xd35d, 0x4430, { 0x93, 0x6e, 0x1d, 0xe3, 0x32, 0x47, 0x8d, 0xe7 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGraphicsInfoHobGuid = { 0x39f62cce, 0x6825, 0x4669, { 0xbb, 0x56, 0x54, 0x1a, 0xba, 0x75, 0x3a, 0x07 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gZeroGuid = { 0x0,        0x0,    0x0,    { 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0  } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderMemoryMapInfoGuid = { 0xa1ff7424, 0x7a1a, 0x478e, { 0xa9, 0xe4, 0x92, 0xf3, 0x57, 0xd1, 0x28, 0x32 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderSystemTableInfoGuid = { 0x16c8a6d0, 0xfe8a, 0x4082, { 0xa2, 0x08, 0xcf, 0x89, 0xc4, 0x29, 0x04, 0x33 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFspNonVolatileStorageHobGuid = { 0x721acf02, 0x4d77, 0x4c2a, { 0xb3, 0xdc, 0x27, 0x0b, 0x7b, 0xa9, 0xe4, 0xb0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFspNonVolatileStorageHob2Guid = { 0x4866788f, 0x6ba8, 0x47d8, { 0x83, 0x06, 0xac, 0xf7, 0x7f, 0x55, 0x10, 0x46 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPeiFirmwarePerformanceGuid = { 0x55765e8f, 0x021a, 0x41f9, { 0x93, 0x2d, 0x4c, 0x49, 0xc5, 0xb7, 0xef, 0x5d } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid = { 0x3b387bfd, 0x7abc, 0x4cf2, { 0xa0, 0xca, 0xb6, 0xa1, 0x6c, 0x1b, 0x1b, 0x25 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderFspInfoGuid = { 0xbd42bc23, 0x1efe, 0x4b2b, { 0xa5, 0x8e, 0x08, 0x8b, 0x5b, 0xa2, 0xf5, 0xb0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gCsmePerformanceInfoGuid = { 0x7add2938, 0xf96a, 0x45c2, { 0x8f, 0x99, 0x23, 0xf4, 0xf2, 0xf0, 0x6f, 0xb8 } };

// Definition of SkuId Array
GLOBAL_REMOVE_IF_UNREFERENCED UINT64 _gPcd_SkuId_Array[] = {0x0};

// Definition of PCDs used in this module
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry = _PCD_VALUE_PcdMaxLibraryDataEntry;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifiedBootEnabled = _PCD_VALUE_PcdVerifiedBootEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1StackSize = _PCD_VALUE_PcdStage1StackSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1DataSize = _PCD_VALUE_PcdStage1DataSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFSPTBase = _PCD_VALUE_PcdFSPTBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage2FdBase = _PCD_VALUE_PcdStage2FdBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage2FdSize = _PCD_VALUE_PcdStage2FdSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMrcDataBase = _PCD_VALUE_PcdMrcDataBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BFdBase = _PCD_VALUE_PcdStage1BFdBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BFdSize = _PCD_VALUE_PcdStage1BFdSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage2LoadBase = _PCD_VALUE_PcdStage2LoadBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLoaderReservedMemSize = _PCD_VALUE_PcdLoaderReservedMemSize;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdStage2LoadHigh = _PCD_VALUE_PcdStage2LoadHigh;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLoaderHobStackSize = _PCD_VALUE_PcdLoaderHobStackSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadExeBase = _PCD_VALUE_PcdPayloadExeBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFlashBaseAddress = _PCD_VALUE_PcdFlashBaseAddress;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFlashSize = _PCD_VALUE_PcdFlashSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFSPMBase = _PCD_VALUE_PcdFSPMBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDataSize = _PCD_VALUE_PcdCfgDataSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDataBase = _PCD_VALUE_PcdCfgDataBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDatabaseSize = _PCD_VALUE_PcdCfgDatabaseSize;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdStage1BXip = _PCD_VALUE_PcdStage1BXip;
volatile  UINT32 _gPcd_BinaryPatch_PcdDebugPrintErrorLevel = _PCD_PATCHABLE_VALUE_PcdDebugPrintErrorLevel;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdS3DebugEnabled = _PCD_VALUE_PcdS3DebugEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDataLoadSource = _PCD_VALUE_PcdCfgDataLoadSource;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdMeasuredBootEnabled = _PCD_VALUE_PcdMeasuredBootEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdEarlyLogBufferSize = _PCD_VALUE_PcdEarlyLogBufferSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLogBufferSize = _PCD_VALUE_PcdLogBufferSize;
volatile  UINT32 _gPcd_BinaryPatch_PcdCfgDataIntBase = _PCD_PATCHABLE_VALUE_PcdCfgDataIntBase;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdCfgDataIntBase = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdCompSignHashAlg = _PCD_VALUE_PcdCompSignHashAlg;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdDmaProtectionEnabled = _PCD_VALUE_PcdDmaProtectionEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdDmaBufferAlignment = _PCD_VALUE_PcdDmaBufferAlignment;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdDmaBufferSize = _PCD_VALUE_PcdDmaBufferSize;
volatile  UINT32 _gPcd_BinaryPatch_PcdPayloadReservedMemSize = _PCD_PATCHABLE_VALUE_PcdPayloadReservedMemSize;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPayloadReservedMemSize = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLoaderAcpiNvsSize = _PCD_VALUE_PcdLoaderAcpiNvsSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLoaderAcpiReclaimSize = _PCD_VALUE_PcdLoaderAcpiReclaimSize;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdEnableSetup = _PCD_VALUE_PcdEnableSetup;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSblResiliencyEnabled = _PCD_VALUE_PcdSblResiliencyEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdBootFailureThreshold = _PCD_VALUE_PcdBootFailureThreshold;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT16 _gPcd_FixedAtBuild_PcdTcoTimeout = _PCD_VALUE_PcdTcoTimeout;

// Definition of PCDs used in libraries

#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdPciExpressBaseAddress  ((UINT64)0xC0000000ULL)
volatile  UINT64 _gPcd_BinaryPatch_PcdPciExpressBaseAddress = _PCD_PATCHABLE_VALUE_PcdPciExpressBaseAddress;
extern volatile   UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress = 8;
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPciExpressBaseSize  0U
#define _PCD_SIZE_PcdPciExpressBaseSize 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseSize  _PCD_SIZE_PcdPciExpressBaseSize 
#define _PCD_VALUE_PcdPciExpressBaseSize  0x10000000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdPciExpressBaseSize = _PCD_VALUE_PcdPciExpressBaseSize;
extern const  UINT64  _gPcd_FixedAtBuild_PcdPciExpressBaseSize;
#define _PCD_GET_MODE_64_PcdPciExpressBaseSize  _gPcd_FixedAtBuild_PcdPciExpressBaseSize
//#define _PCD_SET_MODE_64_PcdPciExpressBaseSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAdlLpSupport  0U
#define _PCD_SIZE_PcdAdlLpSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlLpSupport  _PCD_SIZE_PcdAdlLpSupport 
#define _PCD_VALUE_PcdAdlLpSupport  1U
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdAdlLpSupport = _PCD_VALUE_PcdAdlLpSupport;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdAdlLpSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlLpSupport  _gPcd_FixedAtBuild_PcdAdlLpSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlLpSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumAsciiStringLength  0U
#define _PCD_SIZE_PcdMaximumAsciiStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumAsciiStringLength  _PCD_SIZE_PcdMaximumAsciiStringLength 
#define _PCD_VALUE_PcdMaximumAsciiStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength = _PCD_VALUE_PcdMaximumAsciiStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength;
#define _PCD_GET_MODE_32_PcdMaximumAsciiStringLength  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength
//#define _PCD_SET_MODE_32_PcdMaximumAsciiStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumUnicodeStringLength  0U
#define _PCD_SIZE_PcdMaximumUnicodeStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumUnicodeStringLength  _PCD_SIZE_PcdMaximumUnicodeStringLength 
#define _PCD_VALUE_PcdMaximumUnicodeStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength = _PCD_VALUE_PcdMaximumUnicodeStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength;
#define _PCD_GET_MODE_32_PcdMaximumUnicodeStringLength  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength
//#define _PCD_SET_MODE_32_PcdMaximumUnicodeStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdConsoleOutDeviceMask  0U
#define _PCD_SIZE_PcdConsoleOutDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdConsoleOutDeviceMask  _PCD_SIZE_PcdConsoleOutDeviceMask 
#define _PCD_VALUE_PcdConsoleOutDeviceMask  0x1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask = _PCD_VALUE_PcdConsoleOutDeviceMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask;
#define _PCD_GET_MODE_32_PcdConsoleOutDeviceMask  _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask
//#define _PCD_SET_MODE_32_PcdConsoleOutDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugOutputDeviceMask  0U
#define _PCD_SIZE_PcdDebugOutputDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdDebugOutputDeviceMask  _PCD_SIZE_PcdDebugOutputDeviceMask 
#define _PCD_VALUE_PcdDebugOutputDeviceMask  3U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask = _PCD_VALUE_PcdDebugOutputDeviceMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask;
#define _PCD_GET_MODE_32_PcdDebugOutputDeviceMask  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask
//#define _PCD_SET_MODE_32_PcdDebugOutputDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdForceToInitSerialPort  0U
#define _PCD_SIZE_PcdForceToInitSerialPort 1
#define _PCD_GET_MODE_SIZE_PcdForceToInitSerialPort  _PCD_SIZE_PcdForceToInitSerialPort 
#define _PCD_VALUE_PcdForceToInitSerialPort  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdForceToInitSerialPort = _PCD_VALUE_PcdForceToInitSerialPort;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdForceToInitSerialPort;
#define _PCD_GET_MODE_BOOL_PcdForceToInitSerialPort  _gPcd_FixedAtBuild_PcdForceToInitSerialPort
//#define _PCD_SET_MODE_BOOL_PcdForceToInitSerialPort  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugClearMemoryValue  0U
#define _PCD_SIZE_PcdDebugClearMemoryValue 1
#define _PCD_GET_MODE_SIZE_PcdDebugClearMemoryValue  _PCD_SIZE_PcdDebugClearMemoryValue 
#define _PCD_VALUE_PcdDebugClearMemoryValue  0xAFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugClearMemoryValue = _PCD_VALUE_PcdDebugClearMemoryValue;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue;
#define _PCD_GET_MODE_8_PcdDebugClearMemoryValue  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue
//#define _PCD_SET_MODE_8_PcdDebugClearMemoryValue  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPropertyMask  0U
#define _PCD_SIZE_PcdDebugPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdDebugPropertyMask  _PCD_SIZE_PcdDebugPropertyMask 
#define _PCD_VALUE_PcdDebugPropertyMask  0x27U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugPropertyMask = _PCD_VALUE_PcdDebugPropertyMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugPropertyMask;
#define _PCD_GET_MODE_8_PcdDebugPropertyMask  _gPcd_FixedAtBuild_PcdDebugPropertyMask
//#define _PCD_SET_MODE_8_PcdDebugPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFixedDebugPrintErrorLevel  0U
#define _PCD_SIZE_PcdFixedDebugPrintErrorLevel 4
#define _PCD_GET_MODE_SIZE_PcdFixedDebugPrintErrorLevel  _PCD_SIZE_PcdFixedDebugPrintErrorLevel 
#define _PCD_VALUE_PcdFixedDebugPrintErrorLevel  0xFFFFFFFFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel = _PCD_VALUE_PcdFixedDebugPrintErrorLevel;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdFixedDebugPrintErrorLevel  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel
//#define _PCD_SET_MODE_32_PcdFixedDebugPrintErrorLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdRedundantRegionSize  0U
#define _PCD_SIZE_PcdRedundantRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdRedundantRegionSize  _PCD_SIZE_PcdRedundantRegionSize 
#define _PCD_VALUE_PcdRedundantRegionSize  0x003D3000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdRedundantRegionSize = _PCD_VALUE_PcdRedundantRegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdRedundantRegionSize;
#define _PCD_GET_MODE_32_PcdRedundantRegionSize  _gPcd_FixedAtBuild_PcdRedundantRegionSize
//#define _PCD_SET_MODE_32_PcdRedundantRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTopSwapRegionSize  0U
#define _PCD_SIZE_PcdTopSwapRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdTopSwapRegionSize  _PCD_SIZE_PcdTopSwapRegionSize 
#define _PCD_VALUE_PcdTopSwapRegionSize  0x00080000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdTopSwapRegionSize = _PCD_VALUE_PcdTopSwapRegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdTopSwapRegionSize;
#define _PCD_GET_MODE_32_PcdTopSwapRegionSize  _gPcd_FixedAtBuild_PcdTopSwapRegionSize
//#define _PCD_SET_MODE_32_PcdTopSwapRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1ABase  0U
#define _PCD_SIZE_PcdStage1ABase 4
#define _PCD_GET_MODE_SIZE_PcdStage1ABase  _PCD_SIZE_PcdStage1ABase 
#define _PCD_VALUE_PcdStage1ABase  0xFFFE5000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1ABase = _PCD_VALUE_PcdStage1ABase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1ABase;
#define _PCD_GET_MODE_32_PcdStage1ABase  _gPcd_FixedAtBuild_PcdStage1ABase
//#define _PCD_SET_MODE_32_PcdStage1ABase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1ASize  0U
#define _PCD_SIZE_PcdStage1ASize 4
#define _PCD_GET_MODE_SIZE_PcdStage1ASize  _PCD_SIZE_PcdStage1ASize 
#define _PCD_VALUE_PcdStage1ASize  0x0001B000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1ASize = _PCD_VALUE_PcdStage1ASize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1ASize;
#define _PCD_GET_MODE_32_PcdStage1ASize  _gPcd_FixedAtBuild_PcdStage1ASize
//#define _PCD_SET_MODE_32_PcdStage1ASize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BBase  0U
#define _PCD_SIZE_PcdStage1BBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BBase  _PCD_SIZE_PcdStage1BBase 
#define _PCD_VALUE_PcdStage1BBase  0xFFD00000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BBase = _PCD_VALUE_PcdStage1BBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BBase;
#define _PCD_GET_MODE_32_PcdStage1BBase  _gPcd_FixedAtBuild_PcdStage1BBase
//#define _PCD_SET_MODE_32_PcdStage1BBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BSize  0U
#define _PCD_SIZE_PcdStage1BSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BSize  _PCD_SIZE_PcdStage1BSize 
#define _PCD_VALUE_PcdStage1BSize  0x00200000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BSize = _PCD_VALUE_PcdStage1BSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BSize;
#define _PCD_GET_MODE_32_PcdStage1BSize  _gPcd_FixedAtBuild_PcdStage1BSize
//#define _PCD_SET_MODE_32_PcdStage1BSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2Base  0U
#define _PCD_SIZE_PcdStage2Base 4
#define _PCD_GET_MODE_SIZE_PcdStage2Base  _PCD_SIZE_PcdStage2Base 
#define _PCD_VALUE_PcdStage2Base  0xFFC19000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage2Base = _PCD_VALUE_PcdStage2Base;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage2Base;
#define _PCD_GET_MODE_32_PcdStage2Base  _gPcd_FixedAtBuild_PcdStage2Base
//#define _PCD_SET_MODE_32_PcdStage2Base  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2Size  0U
#define _PCD_SIZE_PcdStage2Size 4
#define _PCD_GET_MODE_SIZE_PcdStage2Size  _PCD_SIZE_PcdStage2Size 
#define _PCD_VALUE_PcdStage2Size  0x000C2000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage2Size = _PCD_VALUE_PcdStage2Size;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage2Size;
#define _PCD_GET_MODE_32_PcdStage2Size  _gPcd_FixedAtBuild_PcdStage2Size
//#define _PCD_SET_MODE_32_PcdStage2Size  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadBase  0U
#define _PCD_SIZE_PcdPayloadBase 4
#define _PCD_GET_MODE_SIZE_PcdPayloadBase  _PCD_SIZE_PcdPayloadBase 
#define _PCD_VALUE_PcdPayloadBase  0xFF72A000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadBase = _PCD_VALUE_PcdPayloadBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadBase;
#define _PCD_GET_MODE_32_PcdPayloadBase  _gPcd_FixedAtBuild_PcdPayloadBase
//#define _PCD_SET_MODE_32_PcdPayloadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadSize  0U
#define _PCD_SIZE_PcdPayloadSize 4
#define _PCD_GET_MODE_SIZE_PcdPayloadSize  _PCD_SIZE_PcdPayloadSize 
#define _PCD_VALUE_PcdPayloadSize  0x00030000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadSize = _PCD_VALUE_PcdPayloadSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadSize;
#define _PCD_GET_MODE_32_PcdPayloadSize  _gPcd_FixedAtBuild_PcdPayloadSize
//#define _PCD_SET_MODE_32_PcdPayloadSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMrcDataSize  0U
#define _PCD_SIZE_PcdMrcDataSize 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataSize  _PCD_SIZE_PcdMrcDataSize 
#define _PCD_VALUE_PcdMrcDataSize  0x00010000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMrcDataSize = _PCD_VALUE_PcdMrcDataSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMrcDataSize;
#define _PCD_GET_MODE_32_PcdMrcDataSize  _gPcd_FixedAtBuild_PcdMrcDataSize
//#define _PCD_SET_MODE_32_PcdMrcDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUcodeBase  0U
#define _PCD_SIZE_PcdUcodeBase 4
#define _PCD_GET_MODE_SIZE_PcdUcodeBase  _PCD_SIZE_PcdUcodeBase 
#define _PCD_VALUE_PcdUcodeBase  0xFFB2D000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdUcodeBase = _PCD_VALUE_PcdUcodeBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdUcodeBase;
#define _PCD_GET_MODE_32_PcdUcodeBase  _gPcd_FixedAtBuild_PcdUcodeBase
//#define _PCD_SET_MODE_32_PcdUcodeBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUcodeSize  0U
#define _PCD_SIZE_PcdUcodeSize 4
#define _PCD_GET_MODE_SIZE_PcdUcodeSize  _PCD_SIZE_PcdUcodeSize 
#define _PCD_VALUE_PcdUcodeSize  0x000EC000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdUcodeSize = _PCD_VALUE_PcdUcodeSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdUcodeSize;
#define _PCD_GET_MODE_32_PcdUcodeSize  _gPcd_FixedAtBuild_PcdUcodeSize
//#define _PCD_SET_MODE_32_PcdUcodeSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiIasImage1RegionBase  0U
#define _PCD_SIZE_PcdSpiIasImage1RegionBase 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage1RegionBase  _PCD_SIZE_PcdSpiIasImage1RegionBase 
#define _PCD_VALUE_PcdSpiIasImage1RegionBase  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage1RegionBase = _PCD_VALUE_PcdSpiIasImage1RegionBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionBase;
#define _PCD_GET_MODE_32_PcdSpiIasImage1RegionBase  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionBase
//#define _PCD_SET_MODE_32_PcdSpiIasImage1RegionBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiIasImage1RegionSize  0U
#define _PCD_SIZE_PcdSpiIasImage1RegionSize 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage1RegionSize  _PCD_SIZE_PcdSpiIasImage1RegionSize 
#define _PCD_VALUE_PcdSpiIasImage1RegionSize  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage1RegionSize = _PCD_VALUE_PcdSpiIasImage1RegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionSize;
#define _PCD_GET_MODE_32_PcdSpiIasImage1RegionSize  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionSize
//#define _PCD_SET_MODE_32_PcdSpiIasImage1RegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiIasImage2RegionBase  0U
#define _PCD_SIZE_PcdSpiIasImage2RegionBase 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage2RegionBase  _PCD_SIZE_PcdSpiIasImage2RegionBase 
#define _PCD_VALUE_PcdSpiIasImage2RegionBase  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage2RegionBase = _PCD_VALUE_PcdSpiIasImage2RegionBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionBase;
#define _PCD_GET_MODE_32_PcdSpiIasImage2RegionBase  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionBase
//#define _PCD_SET_MODE_32_PcdSpiIasImage2RegionBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiIasImage2RegionSize  0U
#define _PCD_SIZE_PcdSpiIasImage2RegionSize 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage2RegionSize  _PCD_SIZE_PcdSpiIasImage2RegionSize 
#define _PCD_VALUE_PcdSpiIasImage2RegionSize  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage2RegionSize = _PCD_VALUE_PcdSpiIasImage2RegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionSize;
#define _PCD_GET_MODE_32_PcdSpiIasImage2RegionSize  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionSize
//#define _PCD_SET_MODE_32_PcdSpiIasImage2RegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFwuPayloadBase  0U
#define _PCD_SIZE_PcdFwuPayloadBase 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadBase  _PCD_SIZE_PcdFwuPayloadBase 
#define _PCD_VALUE_PcdFwuPayloadBase  0xFFCDB000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadBase = _PCD_VALUE_PcdFwuPayloadBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFwuPayloadBase;
#define _PCD_GET_MODE_32_PcdFwuPayloadBase  _gPcd_FixedAtBuild_PcdFwuPayloadBase
//#define _PCD_SET_MODE_32_PcdFwuPayloadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFwuPayloadSize  0U
#define _PCD_SIZE_PcdFwuPayloadSize 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadSize  _PCD_SIZE_PcdFwuPayloadSize 
#define _PCD_VALUE_PcdFwuPayloadSize  0x00020000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadSize = _PCD_VALUE_PcdFwuPayloadSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFwuPayloadSize;
#define _PCD_GET_MODE_32_PcdFwuPayloadSize  _gPcd_FixedAtBuild_PcdFwuPayloadSize
//#define _PCD_SET_MODE_32_PcdFwuPayloadSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVerifyNodeInList  0U
#define _PCD_SIZE_PcdVerifyNodeInList 1
#define _PCD_GET_MODE_SIZE_PcdVerifyNodeInList  _PCD_SIZE_PcdVerifyNodeInList 
#define _PCD_VALUE_PcdVerifyNodeInList  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifyNodeInList = _PCD_VALUE_PcdVerifyNodeInList;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifyNodeInList;
#define _PCD_GET_MODE_BOOL_PcdVerifyNodeInList  _gPcd_FixedAtBuild_PcdVerifyNodeInList
//#define _PCD_SET_MODE_BOOL_PcdVerifyNodeInList  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumLinkedListLength  0U
#define _PCD_SIZE_PcdMaximumLinkedListLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumLinkedListLength  _PCD_SIZE_PcdMaximumLinkedListLength 
#define _PCD_VALUE_PcdMaximumLinkedListLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumLinkedListLength = _PCD_VALUE_PcdMaximumLinkedListLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength;
#define _PCD_GET_MODE_32_PcdMaximumLinkedListLength  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength
//#define _PCD_SET_MODE_32_PcdMaximumLinkedListLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdControlFlowEnforcementPropertyMask  0U
#define _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 4
#define _PCD_GET_MODE_SIZE_PcdControlFlowEnforcementPropertyMask  _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 
#define _PCD_VALUE_PcdControlFlowEnforcementPropertyMask  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask = _PCD_VALUE_PcdControlFlowEnforcementPropertyMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask;
#define _PCD_GET_MODE_32_PcdControlFlowEnforcementPropertyMask  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask
//#define _PCD_SET_MODE_32_PcdControlFlowEnforcementPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpeculationBarrierType  0U
#define _PCD_SIZE_PcdSpeculationBarrierType 1
#define _PCD_GET_MODE_SIZE_PcdSpeculationBarrierType  _PCD_SIZE_PcdSpeculationBarrierType 
#define _PCD_VALUE_PcdSpeculationBarrierType  0x01U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdSpeculationBarrierType = _PCD_VALUE_PcdSpeculationBarrierType;
extern const  UINT8  _gPcd_FixedAtBuild_PcdSpeculationBarrierType;
#define _PCD_GET_MODE_8_PcdSpeculationBarrierType  _gPcd_FixedAtBuild_PcdSpeculationBarrierType
//#define _PCD_SET_MODE_8_PcdSpeculationBarrierType  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCryptoShaOptMask  0U
#define _PCD_SIZE_PcdCryptoShaOptMask 4
#define _PCD_GET_MODE_SIZE_PcdCryptoShaOptMask  _PCD_SIZE_PcdCryptoShaOptMask 
#define _PCD_VALUE_PcdCryptoShaOptMask  0x00000006U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCryptoShaOptMask = _PCD_VALUE_PcdCryptoShaOptMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCryptoShaOptMask;
#define _PCD_GET_MODE_32_PcdCryptoShaOptMask  _gPcd_FixedAtBuild_PcdCryptoShaOptMask
//#define _PCD_SET_MODE_32_PcdCryptoShaOptMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIppHashLibSupportedMask  0U
#define _PCD_SIZE_PcdIppHashLibSupportedMask 2
#define _PCD_GET_MODE_SIZE_PcdIppHashLibSupportedMask  _PCD_SIZE_PcdIppHashLibSupportedMask 
#define _PCD_VALUE_PcdIppHashLibSupportedMask  0x00000006U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT16 _gPcd_FixedAtBuild_PcdIppHashLibSupportedMask = _PCD_VALUE_PcdIppHashLibSupportedMask;
extern const  UINT16  _gPcd_FixedAtBuild_PcdIppHashLibSupportedMask;
#define _PCD_GET_MODE_16_PcdIppHashLibSupportedMask  _gPcd_FixedAtBuild_PcdIppHashLibSupportedMask
//#define _PCD_SET_MODE_16_PcdIppHashLibSupportedMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCompSignSchemeSupportedMask  0U
#define _PCD_SIZE_PcdCompSignSchemeSupportedMask 1
#define _PCD_GET_MODE_SIZE_PcdCompSignSchemeSupportedMask  _PCD_SIZE_PcdCompSignSchemeSupportedMask 
#define _PCD_VALUE_PcdCompSignSchemeSupportedMask  0x03U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdCompSignSchemeSupportedMask = _PCD_VALUE_PcdCompSignSchemeSupportedMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdCompSignSchemeSupportedMask;
#define _PCD_GET_MODE_8_PcdCompSignSchemeSupportedMask  _gPcd_FixedAtBuild_PcdCompSignSchemeSupportedMask
//#define _PCD_SET_MODE_8_PcdCompSignSchemeSupportedMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiPmTimerBase  0U
#define _PCD_PATCHABLE_VALUE_PcdAcpiPmTimerBase  ((UINT16)0x00001808U)
volatile  UINT16 _gPcd_BinaryPatch_PcdAcpiPmTimerBase = _PCD_PATCHABLE_VALUE_PcdAcpiPmTimerBase;
extern volatile   UINT16  _gPcd_BinaryPatch_PcdAcpiPmTimerBase;
#define _PCD_GET_MODE_16_PcdAcpiPmTimerBase  _gPcd_BinaryPatch_PcdAcpiPmTimerBase
#define _PCD_PATCHABLE_PcdAcpiPmTimerBase_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdAcpiPmTimerBase  _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase = 2;
#define _PCD_SET_MODE_16_PcdAcpiPmTimerBase(Value)  (_gPcd_BinaryPatch_PcdAcpiPmTimerBase = (Value))
#define _PCD_SET_MODE_16_S_PcdAcpiPmTimerBase(Value)  ((_gPcd_BinaryPatch_PcdAcpiPmTimerBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdMinDecompression  0U
#define _PCD_SIZE_PcdMinDecompression 1
#define _PCD_GET_MODE_SIZE_PcdMinDecompression  _PCD_SIZE_PcdMinDecompression 
#define _PCD_VALUE_PcdMinDecompression  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdMinDecompression = _PCD_VALUE_PcdMinDecompression;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdMinDecompression;
#define _PCD_GET_MODE_BOOL_PcdMinDecompression  _gPcd_FixedAtBuild_PcdMinDecompression
//#define _PCD_SET_MODE_BOOL_PcdMinDecompression  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiFlashLibId  0U
#define _PCD_SIZE_PcdSpiFlashLibId 1
#define _PCD_GET_MODE_SIZE_PcdSpiFlashLibId  _PCD_SIZE_PcdSpiFlashLibId 
#define _PCD_VALUE_PcdSpiFlashLibId  2U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdSpiFlashLibId = _PCD_VALUE_PcdSpiFlashLibId;
extern const  UINT8  _gPcd_FixedAtBuild_PcdSpiFlashLibId;
#define _PCD_GET_MODE_8_PcdSpiFlashLibId  _gPcd_FixedAtBuild_PcdSpiFlashLibId
//#define _PCD_SET_MODE_8_PcdSpiFlashLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdContainerMaxNumber  0U
#define _PCD_SIZE_PcdContainerMaxNumber 4
#define _PCD_GET_MODE_SIZE_PcdContainerMaxNumber  _PCD_SIZE_PcdContainerMaxNumber 
#define _PCD_VALUE_PcdContainerMaxNumber  8U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdContainerMaxNumber = _PCD_VALUE_PcdContainerMaxNumber;
extern const  UINT32  _gPcd_FixedAtBuild_PcdContainerMaxNumber;
#define _PCD_GET_MODE_32_PcdContainerMaxNumber  _gPcd_FixedAtBuild_PcdContainerMaxNumber
//#define _PCD_SET_MODE_32_PcdContainerMaxNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFspResetStatus  3U
#define _PCD_GET_MODE_32_PcdFspResetStatus  LibPcdGet32(_PCD_TOKEN_PcdFspResetStatus)
#define _PCD_GET_MODE_SIZE_PcdFspResetStatus  LibPcdGetSize(_PCD_TOKEN_PcdFspResetStatus)
#define _PCD_SET_MODE_32_PcdFspResetStatus(Value)  LibPcdSet32(_PCD_TOKEN_PcdFspResetStatus, (Value))
#define _PCD_SET_MODE_32_S_PcdFspResetStatus(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFspResetStatus, (Value))

#define _PCD_TOKEN_PcdTpmBaseAddress  0U
#define _PCD_SIZE_PcdTpmBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdTpmBaseAddress  _PCD_SIZE_PcdTpmBaseAddress 
#define _PCD_VALUE_PcdTpmBaseAddress  0xFED40000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdTpmBaseAddress = _PCD_VALUE_PcdTpmBaseAddress;
extern const  UINT64  _gPcd_FixedAtBuild_PcdTpmBaseAddress;
#define _PCD_GET_MODE_64_PcdTpmBaseAddress  _gPcd_FixedAtBuild_PcdTpmBaseAddress
//#define _PCD_SET_MODE_64_PcdTpmBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTcgLogAreaMinLen  0U
#define _PCD_SIZE_PcdTcgLogAreaMinLen 4
#define _PCD_GET_MODE_SIZE_PcdTcgLogAreaMinLen  _PCD_SIZE_PcdTcgLogAreaMinLen 
#define _PCD_VALUE_PcdTcgLogAreaMinLen  0x10000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen = _PCD_VALUE_PcdTcgLogAreaMinLen;
extern const  UINT32  _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen;
#define _PCD_GET_MODE_32_PcdTcgLogAreaMinLen  _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen
//#define _PCD_SET_MODE_32_PcdTcgLogAreaMinLen  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTpmLibId  0U
#define _PCD_SIZE_PcdTpmLibId 1
#define _PCD_GET_MODE_SIZE_PcdTpmLibId  _PCD_SIZE_PcdTpmLibId 
#define _PCD_VALUE_PcdTpmLibId  4U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdTpmLibId = _PCD_VALUE_PcdTpmLibId;
extern const  UINT8  _gPcd_FixedAtBuild_PcdTpmLibId;
#define _PCD_GET_MODE_8_PcdTpmLibId  _gPcd_FixedAtBuild_PcdTpmLibId
//#define _PCD_SET_MODE_8_PcdTpmLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTccEnabled  0U
#define _PCD_SIZE_PcdTccEnabled 1
#define _PCD_GET_MODE_SIZE_PcdTccEnabled  _PCD_SIZE_PcdTccEnabled 
#define _PCD_VALUE_PcdTccEnabled  0x0
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdTccEnabled = _PCD_VALUE_PcdTccEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdTccEnabled;
#define _PCD_GET_MODE_BOOL_PcdTccEnabled  _gPcd_FixedAtBuild_PcdTccEnabled
//#define _PCD_SET_MODE_BOOL_PcdTccEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFusaSupport  0U
#define _PCD_SIZE_PcdFusaSupport 1
#define _PCD_GET_MODE_SIZE_PcdFusaSupport  _PCD_SIZE_PcdFusaSupport 
#define _PCD_VALUE_PcdFusaSupport  0U
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdFusaSupport = _PCD_VALUE_PcdFusaSupport;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdFusaSupport;
#define _PCD_GET_MODE_BOOL_PcdFusaSupport  _gPcd_FixedAtBuild_PcdFusaSupport
//#define _PCD_SET_MODE_BOOL_PcdFusaSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVtdEnabled  0U
#define _PCD_SIZE_PcdVtdEnabled 1
#define _PCD_GET_MODE_SIZE_PcdVtdEnabled  _PCD_SIZE_PcdVtdEnabled 
#define _PCD_VALUE_PcdVtdEnabled  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVtdEnabled = _PCD_VALUE_PcdVtdEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVtdEnabled;
#define _PCD_GET_MODE_BOOL_PcdVtdEnabled  _gPcd_FixedAtBuild_PcdVtdEnabled
//#define _PCD_SET_MODE_BOOL_PcdVtdEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFastBootEnabled  0U
#define _PCD_SIZE_PcdFastBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdFastBootEnabled  _PCD_SIZE_PcdFastBootEnabled 
#define _PCD_VALUE_PcdFastBootEnabled  0x0
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdFastBootEnabled = _PCD_VALUE_PcdFastBootEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdFastBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdFastBootEnabled  _gPcd_FixedAtBuild_PcdFastBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdFastBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1StackBaseOffset  0U
#define _PCD_SIZE_PcdStage1StackBaseOffset 4
#define _PCD_GET_MODE_SIZE_PcdStage1StackBaseOffset  _PCD_SIZE_PcdStage1StackBaseOffset 
#define _PCD_VALUE_PcdStage1StackBaseOffset  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1StackBaseOffset = _PCD_VALUE_PcdStage1StackBaseOffset;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1StackBaseOffset;
#define _PCD_GET_MODE_32_PcdStage1StackBaseOffset  _gPcd_FixedAtBuild_PcdStage1StackBaseOffset
//#define _PCD_SET_MODE_32_PcdStage1StackBaseOffset  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOsBootOptionNumber  0U
#define _PCD_SIZE_PcdOsBootOptionNumber 4
#define _PCD_GET_MODE_SIZE_PcdOsBootOptionNumber  _PCD_SIZE_PcdOsBootOptionNumber 
#define _PCD_VALUE_PcdOsBootOptionNumber  0x00000008U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdOsBootOptionNumber = _PCD_VALUE_PcdOsBootOptionNumber;
extern const  UINT32  _gPcd_FixedAtBuild_PcdOsBootOptionNumber;
#define _PCD_GET_MODE_32_PcdOsBootOptionNumber  _gPcd_FixedAtBuild_PcdOsBootOptionNumber
//#define _PCD_SET_MODE_32_PcdOsBootOptionNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGraphicsVbtAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdGraphicsVbtAddress  ((UINT32)0xFF000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdGraphicsVbtAddress = _PCD_PATCHABLE_VALUE_PcdGraphicsVbtAddress;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdGraphicsVbtAddress;
#define _PCD_GET_MODE_32_PcdGraphicsVbtAddress  _gPcd_BinaryPatch_PcdGraphicsVbtAddress
#define _PCD_PATCHABLE_PcdGraphicsVbtAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdGraphicsVbtAddress  _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress = 4;
#define _PCD_SET_MODE_32_PcdGraphicsVbtAddress(Value)  (_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdGraphicsVbtAddress(Value)  ((_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdVariableLibId  0U
#define _PCD_SIZE_PcdVariableLibId 1
#define _PCD_GET_MODE_SIZE_PcdVariableLibId  _PCD_SIZE_PcdVariableLibId 
#define _PCD_VALUE_PcdVariableLibId  1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdVariableLibId = _PCD_VALUE_PcdVariableLibId;
extern const  UINT8  _gPcd_FixedAtBuild_PcdVariableLibId;
#define _PCD_GET_MODE_8_PcdVariableLibId  _gPcd_FixedAtBuild_PcdVariableLibId
//#define _PCD_SET_MODE_8_PcdVariableLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuInitIpiDelayInMicroSeconds  0U
#define _PCD_SIZE_PcdCpuInitIpiDelayInMicroSeconds 4
#define _PCD_GET_MODE_SIZE_PcdCpuInitIpiDelayInMicroSeconds  _PCD_SIZE_PcdCpuInitIpiDelayInMicroSeconds 
#define _PCD_VALUE_PcdCpuInitIpiDelayInMicroSeconds  100U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCpuInitIpiDelayInMicroSeconds = _PCD_VALUE_PcdCpuInitIpiDelayInMicroSeconds;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuInitIpiDelayInMicroSeconds;
#define _PCD_GET_MODE_32_PcdCpuInitIpiDelayInMicroSeconds  _gPcd_FixedAtBuild_PcdCpuInitIpiDelayInMicroSeconds
//#define _PCD_SET_MODE_32_PcdCpuInitIpiDelayInMicroSeconds  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuLocalApicBaseAddress  0U
#define _PCD_SIZE_PcdCpuLocalApicBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdCpuLocalApicBaseAddress  _PCD_SIZE_PcdCpuLocalApicBaseAddress 
#define _PCD_VALUE_PcdCpuLocalApicBaseAddress  0xFEE00000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCpuLocalApicBaseAddress = _PCD_VALUE_PcdCpuLocalApicBaseAddress;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuLocalApicBaseAddress;
#define _PCD_GET_MODE_32_PcdCpuLocalApicBaseAddress  _gPcd_FixedAtBuild_PcdCpuLocalApicBaseAddress
//#define _PCD_SET_MODE_32_PcdCpuLocalApicBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BLoadBase  0U
#define _PCD_SIZE_PcdStage1BLoadBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BLoadBase  _PCD_SIZE_PcdStage1BLoadBase 
#define _PCD_VALUE_PcdStage1BLoadBase  0xFFD00000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BLoadBase = _PCD_VALUE_PcdStage1BLoadBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BLoadBase;
#define _PCD_GET_MODE_32_PcdStage1BLoadBase  _gPcd_FixedAtBuild_PcdStage1BLoadBase
//#define _PCD_SET_MODE_32_PcdStage1BLoadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiEnabled  0U
#define _PCD_SIZE_PcdAcpiEnabled 1
#define _PCD_GET_MODE_SIZE_PcdAcpiEnabled  _PCD_SIZE_PcdAcpiEnabled 
#define _PCD_VALUE_PcdAcpiEnabled  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdAcpiEnabled = _PCD_VALUE_PcdAcpiEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdAcpiEnabled;
#define _PCD_GET_MODE_BOOL_PcdAcpiEnabled  _gPcd_FixedAtBuild_PcdAcpiEnabled
//#define _PCD_SET_MODE_BOOL_PcdAcpiEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBootPerformanceMask  0U
#define _PCD_SIZE_PcdBootPerformanceMask 4
#define _PCD_GET_MODE_SIZE_PcdBootPerformanceMask  _PCD_SIZE_PcdBootPerformanceMask 
#define _PCD_VALUE_PcdBootPerformanceMask  0x1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdBootPerformanceMask = _PCD_VALUE_PcdBootPerformanceMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdBootPerformanceMask;
#define _PCD_GET_MODE_32_PcdBootPerformanceMask  _gPcd_FixedAtBuild_PcdBootPerformanceMask
//#define _PCD_SET_MODE_32_PcdBootPerformanceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFSPMUpdSize  0U
#define _PCD_SIZE_PcdFSPMUpdSize 4
#define _PCD_GET_MODE_SIZE_PcdFSPMUpdSize  _PCD_SIZE_PcdFSPMUpdSize 
#define _PCD_VALUE_PcdFSPMUpdSize  0x00000B60U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFSPMUpdSize = _PCD_VALUE_PcdFSPMUpdSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFSPMUpdSize;
#define _PCD_GET_MODE_32_PcdFSPMUpdSize  _gPcd_FixedAtBuild_PcdFSPMUpdSize
//#define _PCD_SET_MODE_32_PcdFSPMUpdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFSPSBase  0U
#define _PCD_PATCHABLE_VALUE_PcdFSPSBase  ((UINT32)0x01191000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdFSPSBase = _PCD_PATCHABLE_VALUE_PcdFSPSBase;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdFSPSBase;
#define _PCD_GET_MODE_32_PcdFSPSBase  _gPcd_BinaryPatch_PcdFSPSBase
#define _PCD_PATCHABLE_PcdFSPSBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFSPSBase  _gPcd_BinaryPatch_Size_PcdFSPSBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdFSPSBase; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdFSPSBase = 4;
#define _PCD_SET_MODE_32_PcdFSPSBase(Value)  (_gPcd_BinaryPatch_PcdFSPSBase = (Value))
#define _PCD_SET_MODE_32_S_PcdFSPSBase(Value)  ((_gPcd_BinaryPatch_PcdFSPSBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdFSPMStackTop  0U
#define _PCD_SIZE_PcdFSPMStackTop 4
#define _PCD_GET_MODE_SIZE_PcdFSPMStackTop  _PCD_SIZE_PcdFSPMStackTop 
#define _PCD_VALUE_PcdFSPMStackTop  0xFEF7FF00U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFSPMStackTop = _PCD_VALUE_PcdFSPMStackTop;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFSPMStackTop;
#define _PCD_GET_MODE_32_PcdFSPMStackTop  _gPcd_FixedAtBuild_PcdFSPMStackTop
//#define _PCD_SET_MODE_32_PcdFSPMStackTop  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


RETURN_STATUS
EFIAPI
BaseRngLibConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
SpiConstructor (
  VOID
  );


VOID
EFIAPI
ProcessLibraryConstructorList (
  IN       EFI_PEI_FILE_HANDLE       FileHandle,
  IN CONST EFI_PEI_SERVICES          **PeiServices
  )
{
  EFI_STATUS  Status;

  Status = BaseRngLibConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = SpiConstructor ();
  ASSERT_RETURN_ERROR (Status);

}



VOID
EFIAPI
ProcessLibraryDestructorList (
  IN       EFI_PEI_FILE_HANDLE       FileHandle,
  IN CONST EFI_PEI_SERVICES          **PeiServices
  )
{

}

GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPeimRevision = 0x00000000U;

EFI_STATUS
EFIAPI
ProcessModuleEntryPointList (
  IN       EFI_PEI_FILE_HANDLE  FileHandle,
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )

{
  return EFI_SUCCESS;
}

GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gDriverUnloadImageCount = 0U;

EFI_STATUS
EFIAPI
ProcessModuleUnloadList (
  IN EFI_HANDLE        ImageHandle
  )
{
  return EFI_SUCCESS;
}
