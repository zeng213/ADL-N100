/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_5D5DB4E5_066C_4968_B00A_5582CF5098C6
#define _AUTOGENH_5D5DB4E5_066C_4968_B00A_5582CF5098C6

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
#define _PCD_TOKEN_PcdUfsPciHostControllerMmioBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdUfsPciHostControllerMmioBase;
#define _PCD_GET_MODE_32_PcdUfsPciHostControllerMmioBase  _gPcd_FixedAtBuild_PcdUfsPciHostControllerMmioBase
//#define _PCD_SET_MODE_32_PcdUfsPciHostControllerMmioBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdUfsPciHostControllerMmioBase 0xd0000000
#define _PCD_SIZE_PcdUfsPciHostControllerMmioBase 4
#define _PCD_GET_MODE_SIZE_PcdUfsPciHostControllerMmioBase _PCD_SIZE_PcdUfsPciHostControllerMmioBase


#ifdef __cplusplus
}
#endif

#endif
