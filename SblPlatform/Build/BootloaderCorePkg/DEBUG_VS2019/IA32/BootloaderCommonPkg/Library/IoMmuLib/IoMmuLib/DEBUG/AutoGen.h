/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A8B8AF28_971A_49A1_9140_45365178D419
#define _AUTOGENH_A8B8AF28_971A_49A1_9140_45365178D419

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
#define _PCD_TOKEN_PcdDmaProtectionEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdDmaProtectionEnabled;
#define _PCD_GET_MODE_BOOL_PcdDmaProtectionEnabled  _gPcd_FixedAtBuild_PcdDmaProtectionEnabled
//#define _PCD_SET_MODE_BOOL_PcdDmaProtectionEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
