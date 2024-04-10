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

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEfiCallerIdGuid = {0xA0FC7906, 0x3519, 0x4605, {0xBA, 0xCD, 0x50, 0xB7, 0xC4, 0x39, 0x2F, 0x84}};

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEdkiiDscPlatformGuid = {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}};

GLOBAL_REMOVE_IF_UNREFERENCED CHAR8 *gEfiCallerBaseName = "Stage1A";

// Guids
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformModuleTokenSpaceGuid = { 0x69d13bf0, 0xaf91, 0x4d96, { 0xaa, 0x9f, 0x21, 0x84, 0xc5, 0xce, 0x3b, 0xc0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformCommonLibTokenSpaceGuid = { 0x373657df, 0x5dc0, 0x4cbb, { 0x87, 0xad, 0x50, 0x1e, 0xb8, 0x89, 0xbf, 0x89 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdePkgTokenSpaceGuid = { 0x914AEBE7, 0x4635, 0x459b, { 0xAA, 0x1C, 0x11, 0xE2, 0x19, 0xB0, 0x3A, 0x10 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformAlderLakeTokenSpaceGuid = { 0xfec38282, 0xab42, 0x4aba, {0x8c, 0x25, 0xa4, 0x4e, 0x46, 0x23, 0xf7, 0x6e}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPeiFirmwarePerformanceGuid = { 0x55765e8f, 0x021a, 0x41f9, { 0x93, 0x2d, 0x4c, 0x49, 0xc5, 0xb7, 0xef, 0x5d } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid = { 0x3b387bfd, 0x7abc, 0x4cf2, { 0xa0, 0xca, 0xb6, 0xa1, 0x6c, 0x1b, 0x1b, 0x25 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderFspInfoGuid = { 0xbd42bc23, 0x1efe, 0x4b2b, { 0xa5, 0x8e, 0x08, 0x8b, 0x5b, 0xa2, 0xf5, 0xb0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gCsmePerformanceInfoGuid = { 0x7add2938, 0xf96a, 0x45c2, { 0x8f, 0x99, 0x23, 0xf4, 0xf2, 0xf0, 0x6f, 0xb8 } };

// Definition of SkuId Array
GLOBAL_REMOVE_IF_UNREFERENCED UINT64 _gPcd_SkuId_Array[] = {0x0};

// Definition of PCDs used in this module
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry = _PCD_VALUE_PcdMaxLibraryDataEntry;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifiedBootEnabled = _PCD_VALUE_PcdVerifiedBootEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask = _PCD_VALUE_PcdDebugOutputDeviceMask;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdContainerMaxNumber = _PCD_VALUE_PcdContainerMaxNumber;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1StackSize = _PCD_VALUE_PcdStage1StackSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BFdBase = _PCD_VALUE_PcdStage1BFdBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BLoadBase = _PCD_VALUE_PcdStage1BLoadBase;
volatile  UINT32 _gPcd_BinaryPatch_PcdHashStoreBase = _PCD_PATCHABLE_VALUE_PcdHashStoreBase;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdHashStoreBase = 4;
volatile  UINT32 _gPcd_BinaryPatch_PcdVerInfoBase = _PCD_PATCHABLE_VALUE_PcdVerInfoBase;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdVerInfoBase = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1DataSize = _PCD_VALUE_PcdStage1DataSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1StackBaseOffset = _PCD_VALUE_PcdStage1StackBaseOffset;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdStage1BXip = _PCD_VALUE_PcdStage1BXip;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDatabaseSize = _PCD_VALUE_PcdCfgDatabaseSize;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdStage1AXip = _PCD_VALUE_PcdStage1AXip;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1ALoadBase = _PCD_VALUE_PcdStage1ALoadBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1AFdBase = _PCD_VALUE_PcdStage1AFdBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1AFvSize = _PCD_VALUE_PcdStage1AFvSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFSPTSize = _PCD_VALUE_PcdFSPTSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFSPTBase = _PCD_VALUE_PcdFSPTBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaxServiceNumber = _PCD_VALUE_PcdMaxServiceNumber;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdEarlyLogBufferSize = _PCD_VALUE_PcdEarlyLogBufferSize;
volatile  UINT32 _gPcd_BinaryPatch_PcdDebugPrintErrorLevel = _PCD_PATCHABLE_VALUE_PcdDebugPrintErrorLevel;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel = 4;
volatile  UINT32 _gPcd_BinaryPatch_PcdFileDataBase = _PCD_PATCHABLE_VALUE_PcdFileDataBase;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdFileDataBase = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifiedBootStage1B = _PCD_VALUE_PcdVerifiedBootStage1B;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdHashStoreSize = _PCD_VALUE_PcdHashStoreSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdPcdLibId = _PCD_VALUE_PcdPcdLibId;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdCompSignHashAlg = _PCD_VALUE_PcdCompSignHashAlg;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdIdenticalTopSwapsBuilt = _PCD_VALUE_PcdIdenticalTopSwapsBuilt;

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

#define _PCD_TOKEN_PcdMrcDataBase  0U
#define _PCD_SIZE_PcdMrcDataBase 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataBase  _PCD_SIZE_PcdMrcDataBase 
#define _PCD_VALUE_PcdMrcDataBase  0xFF579000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMrcDataBase = _PCD_VALUE_PcdMrcDataBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMrcDataBase;
#define _PCD_GET_MODE_32_PcdMrcDataBase  _gPcd_FixedAtBuild_PcdMrcDataBase
//#define _PCD_SET_MODE_32_PcdMrcDataBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

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

#define _PCD_TOKEN_PcdCfgDataBase  0U
#define _PCD_SIZE_PcdCfgDataBase 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataBase  _PCD_SIZE_PcdCfgDataBase 
#define _PCD_VALUE_PcdCfgDataBase  0xFFCFB000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDataBase = _PCD_VALUE_PcdCfgDataBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDataBase;
#define _PCD_GET_MODE_32_PcdCfgDataBase  _gPcd_FixedAtBuild_PcdCfgDataBase
//#define _PCD_SET_MODE_32_PcdCfgDataBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDataSize  0U
#define _PCD_SIZE_PcdCfgDataSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataSize  _PCD_SIZE_PcdCfgDataSize 
#define _PCD_VALUE_PcdCfgDataSize  0x00004000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDataSize = _PCD_VALUE_PcdCfgDataSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDataSize;
#define _PCD_GET_MODE_32_PcdCfgDataSize  _gPcd_FixedAtBuild_PcdCfgDataSize
//#define _PCD_SET_MODE_32_PcdCfgDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

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

#define _PCD_TOKEN_PcdForceToInitSerialPort  0U
#define _PCD_SIZE_PcdForceToInitSerialPort 1
#define _PCD_GET_MODE_SIZE_PcdForceToInitSerialPort  _PCD_SIZE_PcdForceToInitSerialPort 
#define _PCD_VALUE_PcdForceToInitSerialPort  ((BOOLEAN)1U)
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

#define _PCD_TOKEN_PcdPciMmcfgBase  0U
#define _PCD_SIZE_PcdPciMmcfgBase 4
#define _PCD_GET_MODE_SIZE_PcdPciMmcfgBase  _PCD_SIZE_PcdPciMmcfgBase 
#define _PCD_VALUE_PcdPciMmcfgBase  0xC0000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPciMmcfgBase = _PCD_VALUE_PcdPciMmcfgBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdPciMmcfgBase;
#define _PCD_GET_MODE_32_PcdPciMmcfgBase  _gPcd_FixedAtBuild_PcdPciMmcfgBase
//#define _PCD_SET_MODE_32_PcdPciMmcfgBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashBaseAddress  0U
#define _PCD_SIZE_PcdFlashBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdFlashBaseAddress  _PCD_SIZE_PcdFlashBaseAddress 
#define _PCD_VALUE_PcdFlashBaseAddress  0xFF300000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFlashBaseAddress = _PCD_VALUE_PcdFlashBaseAddress;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashBaseAddress;
#define _PCD_GET_MODE_32_PcdFlashBaseAddress  _gPcd_FixedAtBuild_PcdFlashBaseAddress
//#define _PCD_SET_MODE_32_PcdFlashBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashSize  0U
#define _PCD_SIZE_PcdFlashSize 4
#define _PCD_GET_MODE_SIZE_PcdFlashSize  _PCD_SIZE_PcdFlashSize 
#define _PCD_VALUE_PcdFlashSize  0x00D00000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFlashSize = _PCD_VALUE_PcdFlashSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashSize;
#define _PCD_GET_MODE_32_PcdFlashSize  _gPcd_FixedAtBuild_PcdFlashSize
//#define _PCD_SET_MODE_32_PcdFlashSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPortNumber  0U
#define _PCD_SIZE_PcdDebugPortNumber 1
#define _PCD_GET_MODE_SIZE_PcdDebugPortNumber  _PCD_SIZE_PcdDebugPortNumber 
#define _PCD_VALUE_PcdDebugPortNumber  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugPortNumber = _PCD_VALUE_PcdDebugPortNumber;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugPortNumber;
#define _PCD_GET_MODE_8_PcdDebugPortNumber  _gPcd_FixedAtBuild_PcdDebugPortNumber
//#define _PCD_SET_MODE_8_PcdDebugPortNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMinDecompression  0U
#define _PCD_SIZE_PcdMinDecompression 1
#define _PCD_GET_MODE_SIZE_PcdMinDecompression  _PCD_SIZE_PcdMinDecompression 
#define _PCD_VALUE_PcdMinDecompression  ((BOOLEAN)1U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdMinDecompression = _PCD_VALUE_PcdMinDecompression;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdMinDecompression;
#define _PCD_GET_MODE_BOOL_PcdMinDecompression  _gPcd_FixedAtBuild_PcdMinDecompression
//#define _PCD_SET_MODE_BOOL_PcdMinDecompression  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBootPerformanceMask  0U
#define _PCD_SIZE_PcdBootPerformanceMask 4
#define _PCD_GET_MODE_SIZE_PcdBootPerformanceMask  _PCD_SIZE_PcdBootPerformanceMask 
#define _PCD_VALUE_PcdBootPerformanceMask  0x1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdBootPerformanceMask = _PCD_VALUE_PcdBootPerformanceMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdBootPerformanceMask;
#define _PCD_GET_MODE_32_PcdBootPerformanceMask  _gPcd_FixedAtBuild_PcdBootPerformanceMask
//#define _PCD_SET_MODE_32_PcdBootPerformanceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BFdSize  0U
#define _PCD_SIZE_PcdStage1BFdSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BFdSize  _PCD_SIZE_PcdStage1BFdSize 
#define _PCD_VALUE_PcdStage1BFdSize  0x00200000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BFdSize = _PCD_VALUE_PcdStage1BFdSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BFdSize;
#define _PCD_GET_MODE_32_PcdStage1BFdSize  _gPcd_FixedAtBuild_PcdStage1BFdSize
//#define _PCD_SET_MODE_32_PcdStage1BFdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


RETURN_STATUS
EFIAPI
BaseRngLibConstructor (
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
