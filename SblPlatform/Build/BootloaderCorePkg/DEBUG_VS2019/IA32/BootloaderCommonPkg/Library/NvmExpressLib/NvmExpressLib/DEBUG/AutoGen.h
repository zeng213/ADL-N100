/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_5BE3BDF4_53CF_46a3_A6A9_73C34A6E5EE3
#define _AUTOGENH_5BE3BDF4_53CF_46a3_A6A9_73C34A6E5EE3

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


#ifdef __cplusplus
}
#endif

#endif
