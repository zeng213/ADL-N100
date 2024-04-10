/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_597FAEBB_0A3B_4d16_9593_3915AE7D961A
#define _AUTOGENH_597FAEBB_0A3B_4d16_9593_3915AE7D961A

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
#define _PCD_TOKEN_PcdMinDecompression  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdMinDecompression;
#define _PCD_GET_MODE_BOOL_PcdMinDecompression  _gPcd_FixedAtBuild_PcdMinDecompression
//#define _PCD_SET_MODE_BOOL_PcdMinDecompression  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
