/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_C4555E42_949D_4b8c_8157_61A419C0F915
#define _AUTOGENH_C4555E42_949D_4b8c_8157_61A419C0F915

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gFspNonVolatileStorageHobGuid;
extern GUID gPlatformAlderLakeTokenSpaceGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformModuleTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdAdlLpSupport  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdAdlLpSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlLpSupport  _gPcd_FixedAtBuild_PcdAdlLpSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlLpSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdAdlLpSupport 1
#define _PCD_SIZE_PcdAdlLpSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlLpSupport _PCD_SIZE_PcdAdlLpSupport
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdStage1BLoadBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1BLoadBase;
#define _PCD_GET_MODE_32_PcdStage1BLoadBase  _gPcd_FixedAtBuild_PcdStage1BLoadBase
//#define _PCD_SET_MODE_32_PcdStage1BLoadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1BLoadBase 0xFFD00000
#define _PCD_SIZE_PcdStage1BLoadBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BLoadBase _PCD_SIZE_PcdStage1BLoadBase
#define _PCD_TOKEN_PcdStage2LoadBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage2LoadBase;
#define _PCD_GET_MODE_32_PcdStage2LoadBase  _gPcd_FixedAtBuild_PcdStage2LoadBase
//#define _PCD_SET_MODE_32_PcdStage2LoadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage2LoadBase 0xFFC19000
#define _PCD_SIZE_PcdStage2LoadBase 4
#define _PCD_GET_MODE_SIZE_PcdStage2LoadBase _PCD_SIZE_PcdStage2LoadBase
#define _PCD_TOKEN_PcdCfgDatabaseSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCfgDatabaseSize;
#define _PCD_GET_MODE_32_PcdCfgDatabaseSize  _gPcd_FixedAtBuild_PcdCfgDatabaseSize
//#define _PCD_SET_MODE_32_PcdCfgDatabaseSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCfgDatabaseSize 0x00004000
#define _PCD_SIZE_PcdCfgDatabaseSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDatabaseSize _PCD_SIZE_PcdCfgDatabaseSize
#define _PCD_TOKEN_PcdCfgDataSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCfgDataSize;
#define _PCD_GET_MODE_32_PcdCfgDataSize  _gPcd_FixedAtBuild_PcdCfgDataSize
//#define _PCD_SET_MODE_32_PcdCfgDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCfgDataSize 0x00004000
#define _PCD_SIZE_PcdCfgDataSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataSize _PCD_SIZE_PcdCfgDataSize
#define _PCD_TOKEN_PcdVtdEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVtdEnabled;
#define _PCD_GET_MODE_BOOL_PcdVtdEnabled  _gPcd_FixedAtBuild_PcdVtdEnabled
//#define _PCD_SET_MODE_BOOL_PcdVtdEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdAcpiEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdAcpiEnabled;
#define _PCD_GET_MODE_BOOL_PcdAcpiEnabled  _gPcd_FixedAtBuild_PcdAcpiEnabled
//#define _PCD_SET_MODE_BOOL_PcdAcpiEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdFastBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdFastBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdFastBootEnabled  _gPcd_FixedAtBuild_PcdFastBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdFastBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFastBootEnabled 0x0
#define _PCD_SIZE_PcdFastBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdFastBootEnabled _PCD_SIZE_PcdFastBootEnabled
#define _PCD_TOKEN_PcdMeasuredBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdMeasuredBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdMeasuredBootEnabled  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdMeasuredBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdVerifiedBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVerifiedBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootEnabled  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdTccEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdTccEnabled;
#define _PCD_GET_MODE_BOOL_PcdTccEnabled  _gPcd_FixedAtBuild_PcdTccEnabled
//#define _PCD_SET_MODE_BOOL_PcdTccEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTccEnabled 0x0
#define _PCD_SIZE_PcdTccEnabled 1
#define _PCD_GET_MODE_SIZE_PcdTccEnabled _PCD_SIZE_PcdTccEnabled
#define _PCD_TOKEN_PcdSblResiliencyEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdSblResiliencyEnabled;
#define _PCD_GET_MODE_BOOL_PcdSblResiliencyEnabled  _gPcd_FixedAtBuild_PcdSblResiliencyEnabled
//#define _PCD_SET_MODE_BOOL_PcdSblResiliencyEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSblResiliencyEnabled 0x0
#define _PCD_SIZE_PcdSblResiliencyEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSblResiliencyEnabled _PCD_SIZE_PcdSblResiliencyEnabled
#define _PCD_TOKEN_PcdBootFailureThreshold  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdBootFailureThreshold;
#define _PCD_GET_MODE_8_PcdBootFailureThreshold  _gPcd_FixedAtBuild_PcdBootFailureThreshold
//#define _PCD_SET_MODE_8_PcdBootFailureThreshold  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdBootFailureThreshold 3
#define _PCD_SIZE_PcdBootFailureThreshold 1
#define _PCD_GET_MODE_SIZE_PcdBootFailureThreshold _PCD_SIZE_PcdBootFailureThreshold


#ifdef __cplusplus
}
#endif

#endif
