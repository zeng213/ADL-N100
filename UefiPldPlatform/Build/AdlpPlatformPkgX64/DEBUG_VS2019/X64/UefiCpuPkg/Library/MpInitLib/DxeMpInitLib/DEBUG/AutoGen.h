/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_B88F7146_9834_4c55_BFAC_481CC0C33736
#define _AUTOGENH_B88F7146_9834_4c55_BFAC_481CC0C33736

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern EFI_GUID gEfiEventExitBootServicesGuid;
extern EFI_GUID gEfiEventLegacyBootGuid;
extern EFI_GUID gEdkiiMicrocodePatchHobGuid;
extern EFI_GUID gUefiCpuPkgTokenSpaceGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiTimerArchProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdCpuMaxLogicalProcessorNumber  261U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber;
#define _PCD_GET_MODE_32_PcdCpuMaxLogicalProcessorNumber  _gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber
#define _PCD_SET_MODE_32_PcdCpuMaxLogicalProcessorNumber(Value)  (_gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber = (Value))
#define _PCD_SET_MODE_32_S_PcdCpuMaxLogicalProcessorNumber(Value)  ((_gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdCpuMaxLogicalProcessorNumber_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdCpuMaxLogicalProcessorNumber _gPcd_BinaryPatch_Size_PcdCpuMaxLogicalProcessorNumber
extern UINTN _gPcd_BinaryPatch_Size_PcdCpuMaxLogicalProcessorNumber; 
#define _PCD_TOKEN_PcdCpuBootLogicalProcessorNumber  256U
extern const UINT32 _gPcd_FixedAtBuild_PcdCpuBootLogicalProcessorNumber;
#define _PCD_GET_MODE_32_PcdCpuBootLogicalProcessorNumber  _gPcd_FixedAtBuild_PcdCpuBootLogicalProcessorNumber
//#define _PCD_SET_MODE_32_PcdCpuBootLogicalProcessorNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuBootLogicalProcessorNumber 0
#define _PCD_SIZE_PcdCpuBootLogicalProcessorNumber 4
#define _PCD_GET_MODE_SIZE_PcdCpuBootLogicalProcessorNumber _PCD_SIZE_PcdCpuBootLogicalProcessorNumber
#define _PCD_TOKEN_PcdCpuApInitTimeOutInMicroSeconds  251U
extern const UINT32 _gPcd_FixedAtBuild_PcdCpuApInitTimeOutInMicroSeconds;
#define _PCD_GET_MODE_32_PcdCpuApInitTimeOutInMicroSeconds  _gPcd_FixedAtBuild_PcdCpuApInitTimeOutInMicroSeconds
//#define _PCD_SET_MODE_32_PcdCpuApInitTimeOutInMicroSeconds  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuApInitTimeOutInMicroSeconds 50000
#define _PCD_SIZE_PcdCpuApInitTimeOutInMicroSeconds 4
#define _PCD_GET_MODE_SIZE_PcdCpuApInitTimeOutInMicroSeconds _PCD_SIZE_PcdCpuApInitTimeOutInMicroSeconds
#define _PCD_TOKEN_PcdCpuApStackSize  253U
extern const UINT32 _gPcd_FixedAtBuild_PcdCpuApStackSize;
#define _PCD_GET_MODE_32_PcdCpuApStackSize  _gPcd_FixedAtBuild_PcdCpuApStackSize
//#define _PCD_SET_MODE_32_PcdCpuApStackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuApStackSize 0x8000
#define _PCD_SIZE_PcdCpuApStackSize 4
#define _PCD_GET_MODE_SIZE_PcdCpuApStackSize _PCD_SIZE_PcdCpuApStackSize
#define _PCD_TOKEN_PcdCpuMicrocodePatchAddress  262U
extern const UINT64 _gPcd_FixedAtBuild_PcdCpuMicrocodePatchAddress;
#define _PCD_GET_MODE_64_PcdCpuMicrocodePatchAddress  _gPcd_FixedAtBuild_PcdCpuMicrocodePatchAddress
//#define _PCD_SET_MODE_64_PcdCpuMicrocodePatchAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuMicrocodePatchAddress 0x0
#define _PCD_SIZE_PcdCpuMicrocodePatchAddress 8
#define _PCD_GET_MODE_SIZE_PcdCpuMicrocodePatchAddress _PCD_SIZE_PcdCpuMicrocodePatchAddress
#define _PCD_TOKEN_PcdCpuMicrocodePatchRegionSize  263U
extern const UINT64 _gPcd_FixedAtBuild_PcdCpuMicrocodePatchRegionSize;
#define _PCD_GET_MODE_64_PcdCpuMicrocodePatchRegionSize  _gPcd_FixedAtBuild_PcdCpuMicrocodePatchRegionSize
//#define _PCD_SET_MODE_64_PcdCpuMicrocodePatchRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuMicrocodePatchRegionSize 0x0
#define _PCD_SIZE_PcdCpuMicrocodePatchRegionSize 8
#define _PCD_GET_MODE_SIZE_PcdCpuMicrocodePatchRegionSize _PCD_SIZE_PcdCpuMicrocodePatchRegionSize
#define _PCD_TOKEN_PcdCpuApLoopMode  252U
extern const UINT8 _gPcd_FixedAtBuild_PcdCpuApLoopMode;
#define _PCD_GET_MODE_8_PcdCpuApLoopMode  _gPcd_FixedAtBuild_PcdCpuApLoopMode
//#define _PCD_SET_MODE_8_PcdCpuApLoopMode  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuApLoopMode 1
#define _PCD_SIZE_PcdCpuApLoopMode 1
#define _PCD_GET_MODE_SIZE_PcdCpuApLoopMode _PCD_SIZE_PcdCpuApLoopMode
#define _PCD_TOKEN_PcdCpuApTargetCstate  255U
extern const UINT8 _gPcd_FixedAtBuild_PcdCpuApTargetCstate;
#define _PCD_GET_MODE_8_PcdCpuApTargetCstate  _gPcd_FixedAtBuild_PcdCpuApTargetCstate
//#define _PCD_SET_MODE_8_PcdCpuApTargetCstate  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuApTargetCstate 0
#define _PCD_SIZE_PcdCpuApTargetCstate 1
#define _PCD_GET_MODE_SIZE_PcdCpuApTargetCstate _PCD_SIZE_PcdCpuApTargetCstate
#define _PCD_TOKEN_PcdCpuApStatusCheckIntervalInMicroSeconds  254U
extern const UINT32 _gPcd_FixedAtBuild_PcdCpuApStatusCheckIntervalInMicroSeconds;
#define _PCD_GET_MODE_32_PcdCpuApStatusCheckIntervalInMicroSeconds  _gPcd_FixedAtBuild_PcdCpuApStatusCheckIntervalInMicroSeconds
//#define _PCD_SET_MODE_32_PcdCpuApStatusCheckIntervalInMicroSeconds  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuApStatusCheckIntervalInMicroSeconds 100000
#define _PCD_SIZE_PcdCpuApStatusCheckIntervalInMicroSeconds 4
#define _PCD_GET_MODE_SIZE_PcdCpuApStatusCheckIntervalInMicroSeconds _PCD_SIZE_PcdCpuApStatusCheckIntervalInMicroSeconds
#define _PCD_TOKEN_PcdSevEsIsEnabled  36U
#define _PCD_GET_MODE_BOOL_PcdSevEsIsEnabled  LibPcdGetBool(_PCD_TOKEN_PcdSevEsIsEnabled)
#define _PCD_GET_MODE_SIZE_PcdSevEsIsEnabled  LibPcdGetSize(_PCD_TOKEN_PcdSevEsIsEnabled)
#define _PCD_SET_MODE_BOOL_PcdSevEsIsEnabled(Value)  LibPcdSetBool(_PCD_TOKEN_PcdSevEsIsEnabled, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSevEsIsEnabled(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdSevEsIsEnabled, (Value))
#define _PCD_TOKEN_PcdSevEsWorkAreaBase  281U
extern const UINT32 _gPcd_FixedAtBuild_PcdSevEsWorkAreaBase;
#define _PCD_GET_MODE_32_PcdSevEsWorkAreaBase  _gPcd_FixedAtBuild_PcdSevEsWorkAreaBase
//#define _PCD_SET_MODE_32_PcdSevEsWorkAreaBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSevEsWorkAreaBase 0x0
#define _PCD_SIZE_PcdSevEsWorkAreaBase 4
#define _PCD_GET_MODE_SIZE_PcdSevEsWorkAreaBase _PCD_SIZE_PcdSevEsWorkAreaBase
#define _PCD_TOKEN_PcdCpuStackGuard  63U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdCpuStackGuard;
#define _PCD_GET_MODE_BOOL_PcdCpuStackGuard  _gPcd_FixedAtBuild_PcdCpuStackGuard
//#define _PCD_SET_MODE_BOOL_PcdCpuStackGuard  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCpuStackGuard 0
#define _PCD_SIZE_PcdCpuStackGuard 1
#define _PCD_GET_MODE_SIZE_PcdCpuStackGuard _PCD_SIZE_PcdCpuStackGuard
#define _PCD_TOKEN_PcdGhcbBase  12U
#define _PCD_GET_MODE_64_PcdGhcbBase  LibPcdGet64(_PCD_TOKEN_PcdGhcbBase)
#define _PCD_GET_MODE_SIZE_PcdGhcbBase  LibPcdGetSize(_PCD_TOKEN_PcdGhcbBase)
#define _PCD_SET_MODE_64_PcdGhcbBase(Value)  LibPcdSet64(_PCD_TOKEN_PcdGhcbBase, (Value))
#define _PCD_SET_MODE_64_S_PcdGhcbBase(Value)  LibPcdSet64S(_PCD_TOKEN_PcdGhcbBase, (Value))


#ifdef __cplusplus
}
#endif

#endif
