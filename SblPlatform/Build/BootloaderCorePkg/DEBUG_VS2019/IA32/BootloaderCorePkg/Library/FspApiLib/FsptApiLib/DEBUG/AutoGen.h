/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_06156ECD_38DF_4e8a_AE96_077234A56C80
#define _AUTOGENH_06156ECD_38DF_4e8a_AE96_077234A56C80

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
#define _PCD_TOKEN_PcdFSPTBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFSPTBase;
#define _PCD_GET_MODE_32_PcdFSPTBase  _gPcd_FixedAtBuild_PcdFSPTBase
//#define _PCD_SET_MODE_32_PcdFSPTBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFSPTBase 0xFFFE5000
#define _PCD_SIZE_PcdFSPTBase 4
#define _PCD_GET_MODE_SIZE_PcdFSPTBase _PCD_SIZE_PcdFSPTBase


#ifdef __cplusplus
}
#endif

#endif
