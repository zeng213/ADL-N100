/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_7E374E25_8E01_4FEE_87F2_390C23C606CD
#define _AUTOGENH_7E374E25_8E01_4FEE_87F2_390C23C606CD

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x7E374E25, 0x8E01, 0x4FEE, {0x87, 0xF2, 0x39, 0x0C, 0x23, 0xC6, 0x06, 0xCD}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}}

// Guids
extern GUID gPlatformAlderLakeTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdAdlNSupport  0U
#define _PCD_SIZE_PcdAdlNSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlNSupport  _PCD_SIZE_PcdAdlNSupport 
#define _PCD_VALUE_PcdAdlNSupport  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdAdlNSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlNSupport  _gPcd_FixedAtBuild_PcdAdlNSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlNSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
