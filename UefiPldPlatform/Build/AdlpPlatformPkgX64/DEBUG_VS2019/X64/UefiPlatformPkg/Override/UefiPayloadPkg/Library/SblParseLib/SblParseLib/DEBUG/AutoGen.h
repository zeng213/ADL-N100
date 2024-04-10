/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_DE6FB32C_52CF_4A17_A84C_B323653CB5E0
#define _AUTOGENH_DE6FB32C_52CF_4A17_A84C_B323653CB5E0

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gUefiSystemTableInfoGuid;
extern GUID gUefiSerialPortInfoGuid;
extern GUID gLoaderMemoryMapInfoGuid;
extern GUID gEfiGraphicsInfoHobGuid;
extern GUID gEfiGraphicsDeviceInfoHobGuid;
extern GUID gUefiPayloadPkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdPayloadStackTop  286U
extern const UINT32 _gPcd_FixedAtBuild_PcdPayloadStackTop;
#define _PCD_GET_MODE_32_PcdPayloadStackTop  _gPcd_FixedAtBuild_PcdPayloadStackTop
//#define _PCD_SET_MODE_32_PcdPayloadStackTop  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPayloadStackTop 0x90000
#define _PCD_SIZE_PcdPayloadStackTop 4
#define _PCD_GET_MODE_SIZE_PcdPayloadStackTop _PCD_SIZE_PcdPayloadStackTop


#ifdef __cplusplus
}
#endif

#endif
