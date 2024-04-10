/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_1F78F562_79BB_4090_9110_729E870B84F4
#define _AUTOGENH_1F78F562_79BB_4090_9110_729E870B84F4

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
#define _PCD_TOKEN_PcdConsoleInDeviceMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdConsoleInDeviceMask;
#define _PCD_GET_MODE_32_PcdConsoleInDeviceMask  _gPcd_FixedAtBuild_PcdConsoleInDeviceMask
//#define _PCD_SET_MODE_32_PcdConsoleInDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdConsoleInDeviceMask 0x1
#define _PCD_SIZE_PcdConsoleInDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdConsoleInDeviceMask _PCD_SIZE_PcdConsoleInDeviceMask
#define _PCD_TOKEN_PcdSourceDebugEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdSourceDebugEnabled;
#define _PCD_GET_MODE_BOOL_PcdSourceDebugEnabled  _gPcd_FixedAtBuild_PcdSourceDebugEnabled
//#define _PCD_SET_MODE_BOOL_PcdSourceDebugEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
