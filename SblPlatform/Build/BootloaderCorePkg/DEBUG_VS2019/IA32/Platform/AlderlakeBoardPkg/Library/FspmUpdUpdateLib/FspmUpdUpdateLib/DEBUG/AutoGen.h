/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_1A29F3A2_9E6F_4E04_B16C_BB6C647308896
#define _AUTOGENH_1A29F3A2_9E6F_4E04_B16C_BB6C647308896

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
extern GUID gPlatformModuleTokenSpaceGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdTccEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdTccEnabled;
#define _PCD_GET_MODE_BOOL_PcdTccEnabled  _gPcd_FixedAtBuild_PcdTccEnabled
//#define _PCD_SET_MODE_BOOL_PcdTccEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTccEnabled 0x0
#define _PCD_SIZE_PcdTccEnabled 1
#define _PCD_GET_MODE_SIZE_PcdTccEnabled _PCD_SIZE_PcdTccEnabled
#define _PCD_TOKEN_PcdFusaSupport  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdFusaSupport;
#define _PCD_GET_MODE_BOOL_PcdFusaSupport  _gPcd_FixedAtBuild_PcdFusaSupport
//#define _PCD_SET_MODE_BOOL_PcdFusaSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFusaSupport 0
#define _PCD_SIZE_PcdFusaSupport 1
#define _PCD_GET_MODE_SIZE_PcdFusaSupport _PCD_SIZE_PcdFusaSupport
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdVtdEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVtdEnabled;
#define _PCD_GET_MODE_BOOL_PcdVtdEnabled  _gPcd_FixedAtBuild_PcdVtdEnabled
//#define _PCD_SET_MODE_BOOL_PcdVtdEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdFastBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdFastBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdFastBootEnabled  _gPcd_FixedAtBuild_PcdFastBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdFastBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFastBootEnabled 0x0
#define _PCD_SIZE_PcdFastBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdFastBootEnabled _PCD_SIZE_PcdFastBootEnabled
#define _PCD_TOKEN_PcdStage1StackBaseOffset  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1StackBaseOffset;
#define _PCD_GET_MODE_32_PcdStage1StackBaseOffset  _gPcd_FixedAtBuild_PcdStage1StackBaseOffset
//#define _PCD_SET_MODE_32_PcdStage1StackBaseOffset  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1StackBaseOffset 0x0
#define _PCD_SIZE_PcdStage1StackBaseOffset 4
#define _PCD_GET_MODE_SIZE_PcdStage1StackBaseOffset _PCD_SIZE_PcdStage1StackBaseOffset
#define _PCD_TOKEN_PcdStage1StackSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1StackSize;
#define _PCD_GET_MODE_32_PcdStage1StackSize  _gPcd_FixedAtBuild_PcdStage1StackSize
//#define _PCD_SET_MODE_32_PcdStage1StackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1StackSize 0x00002000
#define _PCD_SIZE_PcdStage1StackSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1StackSize _PCD_SIZE_PcdStage1StackSize
#define _PCD_TOKEN_PcdStage1DataSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1DataSize;
#define _PCD_GET_MODE_32_PcdStage1DataSize  _gPcd_FixedAtBuild_PcdStage1DataSize
//#define _PCD_SET_MODE_32_PcdStage1DataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1DataSize 0x00014000
#define _PCD_SIZE_PcdStage1DataSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1DataSize _PCD_SIZE_PcdStage1DataSize


#ifdef __cplusplus
}
#endif

#endif
