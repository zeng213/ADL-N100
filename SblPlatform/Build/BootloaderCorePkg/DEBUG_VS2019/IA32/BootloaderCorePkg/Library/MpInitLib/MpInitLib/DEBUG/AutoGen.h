/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_9C33ED3D_923B_40b4_B3AA_3F24FE7DD1C8
#define _AUTOGENH_9C33ED3D_923B_40b4_B3AA_3F24FE7DD1C8

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
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdCpuMaxLogicalProcessorNumber  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCpuMaxLogicalProcessorNumber;
#define _PCD_GET_MODE_32_PcdCpuMaxLogicalProcessorNumber  _gPcd_FixedAtBuild_PcdCpuMaxLogicalProcessorNumber
//#define _PCD_SET_MODE_32_PcdCpuMaxLogicalProcessorNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuMaxLogicalProcessorNumber 0x00000018
#define _PCD_SIZE_PcdCpuMaxLogicalProcessorNumber 4
#define _PCD_GET_MODE_SIZE_PcdCpuMaxLogicalProcessorNumber _PCD_SIZE_PcdCpuMaxLogicalProcessorNumber
#define _PCD_TOKEN_PcdCpuSortMethod  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCpuSortMethod;
#define _PCD_GET_MODE_32_PcdCpuSortMethod  _gPcd_FixedAtBuild_PcdCpuSortMethod
//#define _PCD_SET_MODE_32_PcdCpuSortMethod  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuSortMethod 0x0
#define _PCD_SIZE_PcdCpuSortMethod 4
#define _PCD_GET_MODE_SIZE_PcdCpuSortMethod _PCD_SIZE_PcdCpuSortMethod
#define _PCD_TOKEN_PcdSmramTsegBase  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSmramTsegBase;
#define _PCD_GET_MODE_32_PcdSmramTsegBase  _gPcd_BinaryPatch_PcdSmramTsegBase
#define _PCD_SET_MODE_32_PcdSmramTsegBase(Value)  (_gPcd_BinaryPatch_PcdSmramTsegBase = (Value))
#define _PCD_SET_MODE_32_S_PcdSmramTsegBase(Value)  ((_gPcd_BinaryPatch_PcdSmramTsegBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmramTsegBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmramTsegBase _gPcd_BinaryPatch_Size_PcdSmramTsegBase
extern UINTN _gPcd_BinaryPatch_Size_PcdSmramTsegBase; 
#define _PCD_TOKEN_PcdSmramTsegSize  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSmramTsegSize;
#define _PCD_GET_MODE_32_PcdSmramTsegSize  _gPcd_BinaryPatch_PcdSmramTsegSize
#define _PCD_SET_MODE_32_PcdSmramTsegSize(Value)  (_gPcd_BinaryPatch_PcdSmramTsegSize = (Value))
#define _PCD_SET_MODE_32_S_PcdSmramTsegSize(Value)  ((_gPcd_BinaryPatch_PcdSmramTsegSize = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmramTsegSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmramTsegSize _gPcd_BinaryPatch_Size_PcdSmramTsegSize
extern UINTN _gPcd_BinaryPatch_Size_PcdSmramTsegSize; 
#define _PCD_TOKEN_PcdSmmRebaseMode  0U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdSmmRebaseMode;
#define _PCD_GET_MODE_8_PcdSmmRebaseMode  _gPcd_BinaryPatch_PcdSmmRebaseMode
#define _PCD_SET_MODE_8_PcdSmmRebaseMode(Value)  (_gPcd_BinaryPatch_PcdSmmRebaseMode = (Value))
#define _PCD_SET_MODE_8_S_PcdSmmRebaseMode(Value)  ((_gPcd_BinaryPatch_PcdSmmRebaseMode = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmmRebaseMode_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSmmRebaseMode _gPcd_BinaryPatch_Size_PcdSmmRebaseMode
extern UINTN _gPcd_BinaryPatch_Size_PcdSmmRebaseMode; 
#define _PCD_TOKEN_PcdFuncCpuInitHook  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdFuncCpuInitHook;
#define _PCD_GET_MODE_32_PcdFuncCpuInitHook  _gPcd_BinaryPatch_PcdFuncCpuInitHook
#define _PCD_SET_MODE_32_PcdFuncCpuInitHook(Value)  (_gPcd_BinaryPatch_PcdFuncCpuInitHook = (Value))
#define _PCD_SET_MODE_32_S_PcdFuncCpuInitHook(Value)  ((_gPcd_BinaryPatch_PcdFuncCpuInitHook = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdFuncCpuInitHook_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFuncCpuInitHook _gPcd_BinaryPatch_Size_PcdFuncCpuInitHook
extern UINTN _gPcd_BinaryPatch_Size_PcdFuncCpuInitHook; 
#define _PCD_TOKEN_PcdCpuX2ApicEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdCpuX2ApicEnabled;
#define _PCD_GET_MODE_BOOL_PcdCpuX2ApicEnabled  _gPcd_FixedAtBuild_PcdCpuX2ApicEnabled
//#define _PCD_SET_MODE_BOOL_PcdCpuX2ApicEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdBuildSmmHobs  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdBuildSmmHobs;
#define _PCD_GET_MODE_8_PcdBuildSmmHobs  _gPcd_FixedAtBuild_PcdBuildSmmHobs
//#define _PCD_SET_MODE_8_PcdBuildSmmHobs  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdBuildSmmHobs 0x03
#define _PCD_SIZE_PcdBuildSmmHobs 1
#define _PCD_GET_MODE_SIZE_PcdBuildSmmHobs _PCD_SIZE_PcdBuildSmmHobs


#ifdef __cplusplus
}
#endif

#endif
