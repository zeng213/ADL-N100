/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_CB92AF64_D337_48A0_9DCD_ECF4549380D2
#define _AUTOGENH_CB92AF64_D337_48A0_9DCD_ECF4549380D2

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPlatformModuleTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdRedundantRegionSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdRedundantRegionSize;
#define _PCD_GET_MODE_32_PcdRedundantRegionSize  _gPcd_FixedAtBuild_PcdRedundantRegionSize
//#define _PCD_SET_MODE_32_PcdRedundantRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdRedundantRegionSize 0x003D3000
#define _PCD_SIZE_PcdRedundantRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdRedundantRegionSize _PCD_SIZE_PcdRedundantRegionSize
#define _PCD_TOKEN_PcdTopSwapRegionSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdTopSwapRegionSize;
#define _PCD_GET_MODE_32_PcdTopSwapRegionSize  _gPcd_FixedAtBuild_PcdTopSwapRegionSize
//#define _PCD_SET_MODE_32_PcdTopSwapRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTopSwapRegionSize 0x00080000
#define _PCD_SIZE_PcdTopSwapRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdTopSwapRegionSize _PCD_SIZE_PcdTopSwapRegionSize
#define _PCD_TOKEN_PcdStage1ABase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1ABase;
#define _PCD_GET_MODE_32_PcdStage1ABase  _gPcd_FixedAtBuild_PcdStage1ABase
//#define _PCD_SET_MODE_32_PcdStage1ABase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1ABase 0xFFFE5000
#define _PCD_SIZE_PcdStage1ABase 4
#define _PCD_GET_MODE_SIZE_PcdStage1ABase _PCD_SIZE_PcdStage1ABase
#define _PCD_TOKEN_PcdStage1ASize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1ASize;
#define _PCD_GET_MODE_32_PcdStage1ASize  _gPcd_FixedAtBuild_PcdStage1ASize
//#define _PCD_SET_MODE_32_PcdStage1ASize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1ASize 0x0001B000
#define _PCD_SIZE_PcdStage1ASize 4
#define _PCD_GET_MODE_SIZE_PcdStage1ASize _PCD_SIZE_PcdStage1ASize
#define _PCD_TOKEN_PcdStage1BBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1BBase;
#define _PCD_GET_MODE_32_PcdStage1BBase  _gPcd_FixedAtBuild_PcdStage1BBase
//#define _PCD_SET_MODE_32_PcdStage1BBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1BBase 0xFFD00000
#define _PCD_SIZE_PcdStage1BBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BBase _PCD_SIZE_PcdStage1BBase
#define _PCD_TOKEN_PcdStage1BSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1BSize;
#define _PCD_GET_MODE_32_PcdStage1BSize  _gPcd_FixedAtBuild_PcdStage1BSize
//#define _PCD_SET_MODE_32_PcdStage1BSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1BSize 0x00200000
#define _PCD_SIZE_PcdStage1BSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BSize _PCD_SIZE_PcdStage1BSize
#define _PCD_TOKEN_PcdStage2Base  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage2Base;
#define _PCD_GET_MODE_32_PcdStage2Base  _gPcd_FixedAtBuild_PcdStage2Base
//#define _PCD_SET_MODE_32_PcdStage2Base  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage2Base 0xFFC19000
#define _PCD_SIZE_PcdStage2Base 4
#define _PCD_GET_MODE_SIZE_PcdStage2Base _PCD_SIZE_PcdStage2Base
#define _PCD_TOKEN_PcdStage2Size  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage2Size;
#define _PCD_GET_MODE_32_PcdStage2Size  _gPcd_FixedAtBuild_PcdStage2Size
//#define _PCD_SET_MODE_32_PcdStage2Size  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage2Size 0x000C2000
#define _PCD_SIZE_PcdStage2Size 4
#define _PCD_GET_MODE_SIZE_PcdStage2Size _PCD_SIZE_PcdStage2Size
#define _PCD_TOKEN_PcdPayloadBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdPayloadBase;
#define _PCD_GET_MODE_32_PcdPayloadBase  _gPcd_FixedAtBuild_PcdPayloadBase
//#define _PCD_SET_MODE_32_PcdPayloadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPayloadBase 0xFF72A000
#define _PCD_SIZE_PcdPayloadBase 4
#define _PCD_GET_MODE_SIZE_PcdPayloadBase _PCD_SIZE_PcdPayloadBase
#define _PCD_TOKEN_PcdPayloadSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdPayloadSize;
#define _PCD_GET_MODE_32_PcdPayloadSize  _gPcd_FixedAtBuild_PcdPayloadSize
//#define _PCD_SET_MODE_32_PcdPayloadSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPayloadSize 0x00030000
#define _PCD_SIZE_PcdPayloadSize 4
#define _PCD_GET_MODE_SIZE_PcdPayloadSize _PCD_SIZE_PcdPayloadSize
#define _PCD_TOKEN_PcdMrcDataBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdMrcDataBase;
#define _PCD_GET_MODE_32_PcdMrcDataBase  _gPcd_FixedAtBuild_PcdMrcDataBase
//#define _PCD_SET_MODE_32_PcdMrcDataBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdMrcDataBase 0xFF579000
#define _PCD_SIZE_PcdMrcDataBase 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataBase _PCD_SIZE_PcdMrcDataBase
#define _PCD_TOKEN_PcdMrcDataSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdMrcDataSize;
#define _PCD_GET_MODE_32_PcdMrcDataSize  _gPcd_FixedAtBuild_PcdMrcDataSize
//#define _PCD_SET_MODE_32_PcdMrcDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdMrcDataSize 0x00010000
#define _PCD_SIZE_PcdMrcDataSize 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataSize _PCD_SIZE_PcdMrcDataSize
#define _PCD_TOKEN_PcdUcodeBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdUcodeBase;
#define _PCD_GET_MODE_32_PcdUcodeBase  _gPcd_FixedAtBuild_PcdUcodeBase
//#define _PCD_SET_MODE_32_PcdUcodeBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdUcodeBase 0xFFB2D000
#define _PCD_SIZE_PcdUcodeBase 4
#define _PCD_GET_MODE_SIZE_PcdUcodeBase _PCD_SIZE_PcdUcodeBase
#define _PCD_TOKEN_PcdUcodeSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdUcodeSize;
#define _PCD_GET_MODE_32_PcdUcodeSize  _gPcd_FixedAtBuild_PcdUcodeSize
//#define _PCD_SET_MODE_32_PcdUcodeSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdUcodeSize 0x000EC000
#define _PCD_SIZE_PcdUcodeSize 4
#define _PCD_GET_MODE_SIZE_PcdUcodeSize _PCD_SIZE_PcdUcodeSize
#define _PCD_TOKEN_PcdSpiIasImage1RegionBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage1RegionBase;
#define _PCD_GET_MODE_32_PcdSpiIasImage1RegionBase  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionBase
//#define _PCD_SET_MODE_32_PcdSpiIasImage1RegionBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSpiIasImage1RegionBase 0
#define _PCD_SIZE_PcdSpiIasImage1RegionBase 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage1RegionBase _PCD_SIZE_PcdSpiIasImage1RegionBase
#define _PCD_TOKEN_PcdSpiIasImage1RegionSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage1RegionSize;
#define _PCD_GET_MODE_32_PcdSpiIasImage1RegionSize  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionSize
//#define _PCD_SET_MODE_32_PcdSpiIasImage1RegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSpiIasImage1RegionSize 0x0
#define _PCD_SIZE_PcdSpiIasImage1RegionSize 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage1RegionSize _PCD_SIZE_PcdSpiIasImage1RegionSize
#define _PCD_TOKEN_PcdSpiIasImage2RegionBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage2RegionBase;
#define _PCD_GET_MODE_32_PcdSpiIasImage2RegionBase  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionBase
//#define _PCD_SET_MODE_32_PcdSpiIasImage2RegionBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSpiIasImage2RegionBase 0
#define _PCD_SIZE_PcdSpiIasImage2RegionBase 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage2RegionBase _PCD_SIZE_PcdSpiIasImage2RegionBase
#define _PCD_TOKEN_PcdSpiIasImage2RegionSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage2RegionSize;
#define _PCD_GET_MODE_32_PcdSpiIasImage2RegionSize  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionSize
//#define _PCD_SET_MODE_32_PcdSpiIasImage2RegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSpiIasImage2RegionSize 0x0
#define _PCD_SIZE_PcdSpiIasImage2RegionSize 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage2RegionSize _PCD_SIZE_PcdSpiIasImage2RegionSize
#define _PCD_TOKEN_PcdFwuPayloadBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadBase;
#define _PCD_GET_MODE_32_PcdFwuPayloadBase  _gPcd_FixedAtBuild_PcdFwuPayloadBase
//#define _PCD_SET_MODE_32_PcdFwuPayloadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFwuPayloadBase 0xFFCDB000
#define _PCD_SIZE_PcdFwuPayloadBase 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadBase _PCD_SIZE_PcdFwuPayloadBase
#define _PCD_TOKEN_PcdFwuPayloadSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadSize;
#define _PCD_GET_MODE_32_PcdFwuPayloadSize  _gPcd_FixedAtBuild_PcdFwuPayloadSize
//#define _PCD_SET_MODE_32_PcdFwuPayloadSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFwuPayloadSize 0x00020000
#define _PCD_SIZE_PcdFwuPayloadSize 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadSize _PCD_SIZE_PcdFwuPayloadSize
#define _PCD_TOKEN_PcdCfgDataBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCfgDataBase;
#define _PCD_GET_MODE_32_PcdCfgDataBase  _gPcd_FixedAtBuild_PcdCfgDataBase
//#define _PCD_SET_MODE_32_PcdCfgDataBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCfgDataBase 0xFFCFB000
#define _PCD_SIZE_PcdCfgDataBase 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataBase _PCD_SIZE_PcdCfgDataBase
#define _PCD_TOKEN_PcdCfgDataSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCfgDataSize;
#define _PCD_GET_MODE_32_PcdCfgDataSize  _gPcd_FixedAtBuild_PcdCfgDataSize
//#define _PCD_SET_MODE_32_PcdCfgDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCfgDataSize 0x00004000
#define _PCD_SIZE_PcdCfgDataSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataSize _PCD_SIZE_PcdCfgDataSize


#ifdef __cplusplus
}
#endif

#endif
