/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_32D37CEB_1B69_49F5_B94A_F38D33159F64
#define _AUTOGENH_32D37CEB_1B69_49F5_B94A_F38D33159F64

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
#define _PCD_TOKEN_PcdDmaBufferSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdDmaBufferSize;
#define _PCD_GET_MODE_32_PcdDmaBufferSize  _gPcd_FixedAtBuild_PcdDmaBufferSize
//#define _PCD_SET_MODE_32_PcdDmaBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdDmaBufferSize 0x00400000
#define _PCD_SIZE_PcdDmaBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdDmaBufferSize _PCD_SIZE_PcdDmaBufferSize
#define _PCD_TOKEN_PcdDmaProtectionEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdDmaProtectionEnabled;
#define _PCD_GET_MODE_BOOL_PcdDmaProtectionEnabled  _gPcd_FixedAtBuild_PcdDmaProtectionEnabled
//#define _PCD_SET_MODE_BOOL_PcdDmaProtectionEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
