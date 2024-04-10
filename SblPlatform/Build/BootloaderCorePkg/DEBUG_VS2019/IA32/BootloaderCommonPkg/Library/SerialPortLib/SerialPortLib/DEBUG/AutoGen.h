/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_15B26F43_A389_4bae_BDE3_4BB0719B7D4F
#define _AUTOGENH_15B26F43_A389_4bae_BDE3_4BB0719B7D4F

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
#define _PCD_TOKEN_PcdForceToInitSerialPort  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdForceToInitSerialPort;
#define _PCD_GET_MODE_BOOL_PcdForceToInitSerialPort  _gPcd_FixedAtBuild_PcdForceToInitSerialPort
//#define _PCD_SET_MODE_BOOL_PcdForceToInitSerialPort  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
