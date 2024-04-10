/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_D38FC876_0B17_4D95_A7F8_A022ECA1CA42
#define _AUTOGENH_D38FC876_0B17_4D95_A7F8_A022ECA1CA42

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gMeBiosPayloadHobGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdMeasuredBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdMeasuredBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdMeasuredBootEnabled  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdMeasuredBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
