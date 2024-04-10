/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_FF26CB5D_CADC_40a7_B43E_27083EA644DF
#define _AUTOGENH_FF26CB5D_CADC_40a7_B43E_27083EA644DF

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
#define _PCD_TOKEN_PcdSupportedMediaTypeMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdSupportedMediaTypeMask;
#define _PCD_GET_MODE_32_PcdSupportedMediaTypeMask  _gPcd_FixedAtBuild_PcdSupportedMediaTypeMask
//#define _PCD_SET_MODE_32_PcdSupportedMediaTypeMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSupportedMediaTypeMask 0xFFFFFFFF
#define _PCD_SIZE_PcdSupportedMediaTypeMask 4
#define _PCD_GET_MODE_SIZE_PcdSupportedMediaTypeMask _PCD_SIZE_PcdSupportedMediaTypeMask


#ifdef __cplusplus
}
#endif

#endif
