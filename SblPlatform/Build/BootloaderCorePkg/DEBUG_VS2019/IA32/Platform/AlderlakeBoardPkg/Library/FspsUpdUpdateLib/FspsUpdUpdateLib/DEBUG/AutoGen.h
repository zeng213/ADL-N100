/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_F0F0D153_A1A6_4455_89C5_F2BDD02C25459
#define _AUTOGENH_F0F0D153_A1A6_4455_89C5_F2BDD02C25459

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPlatformCommonLibTokenSpaceGuid;
extern GUID gPlatformAlderLakeTokenSpaceGuid;
extern GUID gPlatformModuleTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdTccEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdTccEnabled;
#define _PCD_GET_MODE_BOOL_PcdTccEnabled  _gPcd_FixedAtBuild_PcdTccEnabled
//#define _PCD_SET_MODE_BOOL_PcdTccEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTccEnabled 0x0
#define _PCD_SIZE_PcdTccEnabled 1
#define _PCD_GET_MODE_SIZE_PcdTccEnabled _PCD_SIZE_PcdTccEnabled
#define _PCD_TOKEN_PcdAdlLpSupport  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdAdlLpSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlLpSupport  _gPcd_FixedAtBuild_PcdAdlLpSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlLpSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdAdlLpSupport 1
#define _PCD_SIZE_PcdAdlLpSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlLpSupport _PCD_SIZE_PcdAdlLpSupport
#define _PCD_TOKEN_PcdAdlNSupport  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdAdlNSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlNSupport  _gPcd_FixedAtBuild_PcdAdlNSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlNSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdAdlNSupport 1
#define _PCD_SIZE_PcdAdlNSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlNSupport _PCD_SIZE_PcdAdlNSupport
#define _PCD_TOKEN_PcdFramebufferInitEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdFramebufferInitEnabled;
#define _PCD_GET_MODE_BOOL_PcdFramebufferInitEnabled  _gPcd_FixedAtBuild_PcdFramebufferInitEnabled
//#define _PCD_SET_MODE_BOOL_PcdFramebufferInitEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdEnablePciePm  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdEnablePciePm;
#define _PCD_GET_MODE_BOOL_PcdEnablePciePm  _gPcd_FixedAtBuild_PcdEnablePciePm
//#define _PCD_SET_MODE_BOOL_PcdEnablePciePm  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdFastBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdFastBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdFastBootEnabled  _gPcd_FixedAtBuild_PcdFastBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdFastBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFastBootEnabled 0x0
#define _PCD_SIZE_PcdFastBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdFastBootEnabled _PCD_SIZE_PcdFastBootEnabled
#define _PCD_TOKEN_PcdSblResiliencyEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdSblResiliencyEnabled;
#define _PCD_GET_MODE_BOOL_PcdSblResiliencyEnabled  _gPcd_FixedAtBuild_PcdSblResiliencyEnabled
//#define _PCD_SET_MODE_BOOL_PcdSblResiliencyEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSblResiliencyEnabled 0x0
#define _PCD_SIZE_PcdSblResiliencyEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSblResiliencyEnabled _PCD_SIZE_PcdSblResiliencyEnabled
#define _PCD_TOKEN_PcdMeasuredBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdMeasuredBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdMeasuredBootEnabled  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdMeasuredBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
