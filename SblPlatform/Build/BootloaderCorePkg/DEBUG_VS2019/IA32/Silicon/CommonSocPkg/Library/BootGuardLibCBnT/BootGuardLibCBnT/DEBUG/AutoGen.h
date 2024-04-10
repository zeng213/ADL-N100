/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_4AECEA3D_82F6_4796_9934_6371D97B7FED
#define _AUTOGENH_4AECEA3D_82F6_4796_9934_6371D97B7FED

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformModuleTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdTopSwapRegionSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdTopSwapRegionSize;
#define _PCD_GET_MODE_32_PcdTopSwapRegionSize  _gPcd_FixedAtBuild_PcdTopSwapRegionSize
//#define _PCD_SET_MODE_32_PcdTopSwapRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTopSwapRegionSize 0x00080000
#define _PCD_SIZE_PcdTopSwapRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdTopSwapRegionSize _PCD_SIZE_PcdTopSwapRegionSize
#define _PCD_TOKEN_PcdMeasuredBootHashMask  2U
#define _PCD_GET_MODE_32_PcdMeasuredBootHashMask  LibPcdGet32(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_GET_MODE_SIZE_PcdMeasuredBootHashMask  LibPcdGetSize(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_SET_MODE_32_PcdMeasuredBootHashMask(Value)  LibPcdSet32(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))
#define _PCD_SET_MODE_32_S_PcdMeasuredBootHashMask(Value)  LibPcdSet32S(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))


#ifdef __cplusplus
}
#endif

#endif
