/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_DAF723AE_933E_433e_B72E_101BB46F7F66
#define _AUTOGENH_DAF723AE_933E_433e_B72E_101BB46F7F66

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

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdVtdEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVtdEnabled;
#define _PCD_GET_MODE_BOOL_PcdVtdEnabled  _gPcd_FixedAtBuild_PcdVtdEnabled
//#define _PCD_SET_MODE_BOOL_PcdVtdEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif