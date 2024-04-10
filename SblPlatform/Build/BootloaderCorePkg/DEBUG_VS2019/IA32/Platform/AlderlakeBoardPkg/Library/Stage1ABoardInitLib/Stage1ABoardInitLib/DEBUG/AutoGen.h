/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_78232E4A_E195_4996_9C7A_9D1199F1B948
#define _AUTOGENH_78232E4A_E195_4996_9C7A_9D1199F1B948

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPlatformAlderLakeTokenSpaceGuid;
extern GUID gPlatformModuleTokenSpaceGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdAdlLpSupport  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdAdlLpSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlLpSupport  _gPcd_FixedAtBuild_PcdAdlLpSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlLpSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdAdlLpSupport 1
#define _PCD_SIZE_PcdAdlLpSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlLpSupport _PCD_SIZE_PcdAdlLpSupport
#define _PCD_TOKEN_PcdPciMmcfgBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdPciMmcfgBase;
#define _PCD_GET_MODE_32_PcdPciMmcfgBase  _gPcd_FixedAtBuild_PcdPciMmcfgBase
//#define _PCD_SET_MODE_32_PcdPciMmcfgBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPciMmcfgBase 0xC0000000
#define _PCD_SIZE_PcdPciMmcfgBase 4
#define _PCD_GET_MODE_SIZE_PcdPciMmcfgBase _PCD_SIZE_PcdPciMmcfgBase
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
#define _PCD_TOKEN_PcdFlashBaseAddress  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFlashBaseAddress;
#define _PCD_GET_MODE_32_PcdFlashBaseAddress  _gPcd_FixedAtBuild_PcdFlashBaseAddress
//#define _PCD_SET_MODE_32_PcdFlashBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFlashBaseAddress 0xFF300000
#define _PCD_SIZE_PcdFlashBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdFlashBaseAddress _PCD_SIZE_PcdFlashBaseAddress
#define _PCD_TOKEN_PcdFlashSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFlashSize;
#define _PCD_GET_MODE_32_PcdFlashSize  _gPcd_FixedAtBuild_PcdFlashSize
//#define _PCD_SET_MODE_32_PcdFlashSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFlashSize 0x00D00000
#define _PCD_SIZE_PcdFlashSize 4
#define _PCD_GET_MODE_SIZE_PcdFlashSize _PCD_SIZE_PcdFlashSize
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdTopSwapRegionSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdTopSwapRegionSize;
#define _PCD_GET_MODE_32_PcdTopSwapRegionSize  _gPcd_FixedAtBuild_PcdTopSwapRegionSize
//#define _PCD_SET_MODE_32_PcdTopSwapRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTopSwapRegionSize 0x00080000
#define _PCD_SIZE_PcdTopSwapRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdTopSwapRegionSize _PCD_SIZE_PcdTopSwapRegionSize
#define _PCD_TOKEN_PcdRedundantRegionSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdRedundantRegionSize;
#define _PCD_GET_MODE_32_PcdRedundantRegionSize  _gPcd_FixedAtBuild_PcdRedundantRegionSize
//#define _PCD_SET_MODE_32_PcdRedundantRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdRedundantRegionSize 0x003D3000
#define _PCD_SIZE_PcdRedundantRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdRedundantRegionSize _PCD_SIZE_PcdRedundantRegionSize
#define _PCD_TOKEN_PcdStage1BSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1BSize;
#define _PCD_GET_MODE_32_PcdStage1BSize  _gPcd_FixedAtBuild_PcdStage1BSize
//#define _PCD_SET_MODE_32_PcdStage1BSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1BSize 0x00200000
#define _PCD_SIZE_PcdStage1BSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BSize _PCD_SIZE_PcdStage1BSize
#define _PCD_TOKEN_PcdDebugPortNumber  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdDebugPortNumber;
#define _PCD_GET_MODE_8_PcdDebugPortNumber  _gPcd_FixedAtBuild_PcdDebugPortNumber
//#define _PCD_SET_MODE_8_PcdDebugPortNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdDebugPortNumber 0x0
#define _PCD_SIZE_PcdDebugPortNumber 1
#define _PCD_GET_MODE_SIZE_PcdDebugPortNumber _PCD_SIZE_PcdDebugPortNumber


#ifdef __cplusplus
}
#endif

#endif
