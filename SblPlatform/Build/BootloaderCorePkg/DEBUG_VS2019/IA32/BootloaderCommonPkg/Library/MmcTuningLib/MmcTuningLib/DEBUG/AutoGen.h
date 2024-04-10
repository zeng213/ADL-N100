/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_7B99CD9B_9706_407A_A9C4_01AFC058A80C
#define _AUTOGENH_7B99CD9B_9706_407A_A9C4_01AFC058A80C

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

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdMmcTuningLibId  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdMmcTuningLibId;
#define _PCD_GET_MODE_8_PcdMmcTuningLibId  _gPcd_FixedAtBuild_PcdMmcTuningLibId
//#define _PCD_SET_MODE_8_PcdMmcTuningLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdMmcTuningLibId 6
#define _PCD_SIZE_PcdMmcTuningLibId 1
#define _PCD_GET_MODE_SIZE_PcdMmcTuningLibId _PCD_SIZE_PcdMmcTuningLibId
#define _PCD_TOKEN_PcdMmcTuningLba  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdMmcTuningLba;
#define _PCD_GET_MODE_32_PcdMmcTuningLba  _gPcd_FixedAtBuild_PcdMmcTuningLba
//#define _PCD_SET_MODE_32_PcdMmcTuningLba  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdMmcTuningLba 0x00000040
#define _PCD_SIZE_PcdMmcTuningLba 4
#define _PCD_GET_MODE_SIZE_PcdMmcTuningLba _PCD_SIZE_PcdMmcTuningLba
#define _PCD_TOKEN_PcdEmmcHs400SupportEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdEmmcHs400SupportEnabled;
#define _PCD_GET_MODE_BOOL_PcdEmmcHs400SupportEnabled  _gPcd_FixedAtBuild_PcdEmmcHs400SupportEnabled
//#define _PCD_SET_MODE_BOOL_PcdEmmcHs400SupportEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
