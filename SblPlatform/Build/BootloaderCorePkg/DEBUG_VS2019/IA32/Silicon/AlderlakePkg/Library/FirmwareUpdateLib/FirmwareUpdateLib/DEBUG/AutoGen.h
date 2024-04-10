/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_8EFEE308_844C_4386_A892_D9945549DF21
#define _AUTOGENH_8EFEE308_844C_4386_A892_D9945549DF21

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiPartTypeSystemPartGuid;
extern GUID gOsBootOptionGuid;
extern GUID gSblCompFWUpdateImageFileGuid;
extern GUID gPlatformModuleTokenSpaceGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPayloadTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
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
#define _PCD_TOKEN_PcdFlashBaseAddress  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFlashBaseAddress;
#define _PCD_GET_MODE_32_PcdFlashBaseAddress  _gPcd_FixedAtBuild_PcdFlashBaseAddress
//#define _PCD_SET_MODE_32_PcdFlashBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFlashBaseAddress 0xFF300000
#define _PCD_SIZE_PcdFlashBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdFlashBaseAddress _PCD_SIZE_PcdFlashBaseAddress
#define _PCD_TOKEN_PcdMrcDataSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdMrcDataSize;
#define _PCD_GET_MODE_32_PcdMrcDataSize  _gPcd_FixedAtBuild_PcdMrcDataSize
//#define _PCD_SET_MODE_32_PcdMrcDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdMrcDataSize 0x00010000
#define _PCD_SIZE_PcdMrcDataSize 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataSize _PCD_SIZE_PcdMrcDataSize
#define _PCD_TOKEN_PcdStage1BSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1BSize;
#define _PCD_GET_MODE_32_PcdStage1BSize  _gPcd_FixedAtBuild_PcdStage1BSize
//#define _PCD_SET_MODE_32_PcdStage1BSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1BSize 0x00200000
#define _PCD_SIZE_PcdStage1BSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BSize _PCD_SIZE_PcdStage1BSize
#define _PCD_TOKEN_PcdStage2Size  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage2Size;
#define _PCD_GET_MODE_32_PcdStage2Size  _gPcd_FixedAtBuild_PcdStage2Size
//#define _PCD_SET_MODE_32_PcdStage2Size  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage2Size 0x000C2000
#define _PCD_SIZE_PcdStage2Size 4
#define _PCD_GET_MODE_SIZE_PcdStage2Size _PCD_SIZE_PcdStage2Size
#define _PCD_TOKEN_PcdUcodeSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdUcodeSize;
#define _PCD_GET_MODE_32_PcdUcodeSize  _gPcd_FixedAtBuild_PcdUcodeSize
//#define _PCD_SET_MODE_32_PcdUcodeSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdUcodeSize 0x000EC000
#define _PCD_SIZE_PcdUcodeSize 4
#define _PCD_GET_MODE_SIZE_PcdUcodeSize _PCD_SIZE_PcdUcodeSize
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdPayloadHobList  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPayloadHobList;
#define _PCD_GET_MODE_32_PcdPayloadHobList  _gPcd_BinaryPatch_PcdPayloadHobList
#define _PCD_SET_MODE_32_PcdPayloadHobList(Value)  (_gPcd_BinaryPatch_PcdPayloadHobList = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadHobList(Value)  ((_gPcd_BinaryPatch_PcdPayloadHobList = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPayloadHobList_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadHobList _gPcd_BinaryPatch_Size_PcdPayloadHobList
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadHobList; 


#ifdef __cplusplus
}
#endif

#endif
