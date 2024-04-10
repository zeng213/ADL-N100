/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_06156ECD_38DF_4e8a_AE96_077234A56C80
#define _AUTOGENH_06156ECD_38DF_4e8a_AE96_077234A56C80

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPlatformModuleTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdFSPMUpdSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFSPMUpdSize;
#define _PCD_GET_MODE_32_PcdFSPMUpdSize  _gPcd_FixedAtBuild_PcdFSPMUpdSize
//#define _PCD_SET_MODE_32_PcdFSPMUpdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFSPMUpdSize 0x00000B60
#define _PCD_SIZE_PcdFSPMUpdSize 4
#define _PCD_GET_MODE_SIZE_PcdFSPMUpdSize _PCD_SIZE_PcdFSPMUpdSize
#define _PCD_TOKEN_PcdFSPMBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFSPMBase;
#define _PCD_GET_MODE_32_PcdFSPMBase  _gPcd_FixedAtBuild_PcdFSPMBase
//#define _PCD_SET_MODE_32_PcdFSPMBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFSPMBase 0xFFE40000
#define _PCD_SIZE_PcdFSPMBase 4
#define _PCD_GET_MODE_SIZE_PcdFSPMBase _PCD_SIZE_PcdFSPMBase
#define _PCD_TOKEN_PcdFSPSBase  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdFSPSBase;
#define _PCD_GET_MODE_32_PcdFSPSBase  _gPcd_BinaryPatch_PcdFSPSBase
#define _PCD_SET_MODE_32_PcdFSPSBase(Value)  (_gPcd_BinaryPatch_PcdFSPSBase = (Value))
#define _PCD_SET_MODE_32_S_PcdFSPSBase(Value)  ((_gPcd_BinaryPatch_PcdFSPSBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdFSPSBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFSPSBase _gPcd_BinaryPatch_Size_PcdFSPSBase
extern UINTN _gPcd_BinaryPatch_Size_PcdFSPSBase; 
#define _PCD_TOKEN_PcdFSPMStackTop  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFSPMStackTop;
#define _PCD_GET_MODE_32_PcdFSPMStackTop  _gPcd_FixedAtBuild_PcdFSPMStackTop
//#define _PCD_SET_MODE_32_PcdFSPMStackTop  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFSPMStackTop 0xFEF7FF00
#define _PCD_SIZE_PcdFSPMStackTop 4
#define _PCD_GET_MODE_SIZE_PcdFSPMStackTop _PCD_SIZE_PcdFSPMStackTop
#define _PCD_TOKEN_PcdFspResetStatus  3U
#define _PCD_GET_MODE_32_PcdFspResetStatus  LibPcdGet32(_PCD_TOKEN_PcdFspResetStatus)
#define _PCD_GET_MODE_SIZE_PcdFspResetStatus  LibPcdGetSize(_PCD_TOKEN_PcdFspResetStatus)
#define _PCD_SET_MODE_32_PcdFspResetStatus(Value)  LibPcdSet32(_PCD_TOKEN_PcdFspResetStatus, (Value))
#define _PCD_SET_MODE_32_S_PcdFspResetStatus(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFspResetStatus, (Value))


#ifdef __cplusplus
}
#endif

#endif
