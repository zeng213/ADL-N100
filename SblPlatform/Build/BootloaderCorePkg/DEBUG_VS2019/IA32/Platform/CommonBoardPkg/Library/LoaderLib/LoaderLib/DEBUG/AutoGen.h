/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_36CB9AE9_7090_41d7_8719_B2B799DF9F39
#define _AUTOGENH_36CB9AE9_7090_41d7_8719_B2B799DF9F39

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
#define _PCD_TOKEN_PcdPayloadBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdPayloadBase;
#define _PCD_GET_MODE_32_PcdPayloadBase  _gPcd_FixedAtBuild_PcdPayloadBase
//#define _PCD_SET_MODE_32_PcdPayloadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPayloadBase 0xFF72A000
#define _PCD_SIZE_PcdPayloadBase 4
#define _PCD_GET_MODE_SIZE_PcdPayloadBase _PCD_SIZE_PcdPayloadBase
#define _PCD_TOKEN_PcdPayloadSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdPayloadSize;
#define _PCD_GET_MODE_32_PcdPayloadSize  _gPcd_FixedAtBuild_PcdPayloadSize
//#define _PCD_SET_MODE_32_PcdPayloadSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPayloadSize 0x00030000
#define _PCD_SIZE_PcdPayloadSize 4
#define _PCD_GET_MODE_SIZE_PcdPayloadSize _PCD_SIZE_PcdPayloadSize
#define _PCD_TOKEN_PcdFwuPayloadBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadBase;
#define _PCD_GET_MODE_32_PcdFwuPayloadBase  _gPcd_FixedAtBuild_PcdFwuPayloadBase
//#define _PCD_SET_MODE_32_PcdFwuPayloadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFwuPayloadBase 0xFFCDB000
#define _PCD_SIZE_PcdFwuPayloadBase 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadBase _PCD_SIZE_PcdFwuPayloadBase
#define _PCD_TOKEN_PcdFwuPayloadSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadSize;
#define _PCD_GET_MODE_32_PcdFwuPayloadSize  _gPcd_FixedAtBuild_PcdFwuPayloadSize
//#define _PCD_SET_MODE_32_PcdFwuPayloadSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFwuPayloadSize 0x00020000
#define _PCD_SIZE_PcdFwuPayloadSize 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadSize _PCD_SIZE_PcdFwuPayloadSize


#ifdef __cplusplus
}
#endif

#endif
