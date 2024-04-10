/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_FB56D5A8_ABD3_4BB6_81F7_B08F7CFB646C
#define _AUTOGENH_FB56D5A8_ABD3_4BB6_81F7_B08F7CFB646C

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gTcgEvent2EntryHobGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdTpmBaseAddress  0U
extern const UINT64 _gPcd_FixedAtBuild_PcdTpmBaseAddress;
#define _PCD_GET_MODE_64_PcdTpmBaseAddress  _gPcd_FixedAtBuild_PcdTpmBaseAddress
//#define _PCD_SET_MODE_64_PcdTpmBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTpmBaseAddress 0xFED40000
#define _PCD_SIZE_PcdTpmBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdTpmBaseAddress _PCD_SIZE_PcdTpmBaseAddress
#define _PCD_TOKEN_PcdTcgLogAreaMinLen  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen;
#define _PCD_GET_MODE_32_PcdTcgLogAreaMinLen  _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen
//#define _PCD_SET_MODE_32_PcdTcgLogAreaMinLen  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTcgLogAreaMinLen 0x10000
#define _PCD_SIZE_PcdTcgLogAreaMinLen 4
#define _PCD_GET_MODE_SIZE_PcdTcgLogAreaMinLen _PCD_SIZE_PcdTcgLogAreaMinLen
#define _PCD_TOKEN_PcdTpmLibId  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdTpmLibId;
#define _PCD_GET_MODE_8_PcdTpmLibId  _gPcd_FixedAtBuild_PcdTpmLibId
//#define _PCD_SET_MODE_8_PcdTpmLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTpmLibId 4
#define _PCD_SIZE_PcdTpmLibId 1
#define _PCD_GET_MODE_SIZE_PcdTpmLibId _PCD_SIZE_PcdTpmLibId
#define _PCD_TOKEN_PcdVerifiedBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVerifiedBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootEnabled  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdMeasuredBootHashMask  2U
#define _PCD_GET_MODE_32_PcdMeasuredBootHashMask  LibPcdGet32(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_GET_MODE_SIZE_PcdMeasuredBootHashMask  LibPcdGetSize(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_SET_MODE_32_PcdMeasuredBootHashMask(Value)  LibPcdSet32(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))
#define _PCD_SET_MODE_32_S_PcdMeasuredBootHashMask(Value)  LibPcdSet32S(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))


#ifdef __cplusplus
}
#endif

#endif
