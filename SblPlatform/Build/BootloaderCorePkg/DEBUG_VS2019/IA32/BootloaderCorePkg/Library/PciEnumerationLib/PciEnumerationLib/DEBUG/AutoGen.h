/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_42204583_B618_4403_8625_C0A1813D9048
#define _AUTOGENH_42204583_B618_4403_8625_C0A1813D9048

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
extern GUID gLoaderPciRootBridgeInfoGuid;
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
#define _PCD_TOKEN_PcdPciResourceIoBase  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPciResourceIoBase;
#define _PCD_GET_MODE_32_PcdPciResourceIoBase  _gPcd_BinaryPatch_PcdPciResourceIoBase
#define _PCD_SET_MODE_32_PcdPciResourceIoBase(Value)  (_gPcd_BinaryPatch_PcdPciResourceIoBase = (Value))
#define _PCD_SET_MODE_32_S_PcdPciResourceIoBase(Value)  ((_gPcd_BinaryPatch_PcdPciResourceIoBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciResourceIoBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciResourceIoBase _gPcd_BinaryPatch_Size_PcdPciResourceIoBase
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResourceIoBase; 
#define _PCD_TOKEN_PcdPciResourceMem32Base  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPciResourceMem32Base;
#define _PCD_GET_MODE_32_PcdPciResourceMem32Base  _gPcd_BinaryPatch_PcdPciResourceMem32Base
#define _PCD_SET_MODE_32_PcdPciResourceMem32Base(Value)  (_gPcd_BinaryPatch_PcdPciResourceMem32Base = (Value))
#define _PCD_SET_MODE_32_S_PcdPciResourceMem32Base(Value)  ((_gPcd_BinaryPatch_PcdPciResourceMem32Base = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciResourceMem32Base_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciResourceMem32Base _gPcd_BinaryPatch_Size_PcdPciResourceMem32Base
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResourceMem32Base; 
#define _PCD_TOKEN_PcdPciEnumPolicyInfo  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdPciEnumPolicyInfo[];
#define _PCD_GET_MODE_PTR_PcdPciEnumPolicyInfo  (VOID *)_gPcd_FixedAtBuild_PcdPciEnumPolicyInfo
//#define _PCD_SET_MODE_PTR_PcdPciEnumPolicyInfo  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPciEnumPolicyInfo (VOID *)_gPcd_FixedAtBuild_PcdPciEnumPolicyInfo
#define _PCD_SIZE_PcdPciEnumPolicyInfo 7
#define _PCD_GET_MODE_SIZE_PcdPciEnumPolicyInfo _PCD_SIZE_PcdPciEnumPolicyInfo
#define _PCD_TOKEN_PcdPciResourceMem64Base  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciResourceMem64Base;
#define _PCD_GET_MODE_64_PcdPciResourceMem64Base  _gPcd_BinaryPatch_PcdPciResourceMem64Base
#define _PCD_SET_MODE_64_PcdPciResourceMem64Base(Value)  (_gPcd_BinaryPatch_PcdPciResourceMem64Base = (Value))
#define _PCD_SET_MODE_64_S_PcdPciResourceMem64Base(Value)  ((_gPcd_BinaryPatch_PcdPciResourceMem64Base = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciResourceMem64Base_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciResourceMem64Base _gPcd_BinaryPatch_Size_PcdPciResourceMem64Base
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResourceMem64Base; 
#define _PCD_TOKEN_PcdAriSupport  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdAriSupport;
#define _PCD_GET_MODE_BOOL_PcdAriSupport  _gPcd_FixedAtBuild_PcdAriSupport
//#define _PCD_SET_MODE_BOOL_PcdAriSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdSrIovSupport  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdSrIovSupport;
#define _PCD_GET_MODE_BOOL_PcdSrIovSupport  _gPcd_FixedAtBuild_PcdSrIovSupport
//#define _PCD_SET_MODE_BOOL_PcdSrIovSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdPciResAllocTableBase  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPciResAllocTableBase;
#define _PCD_GET_MODE_32_PcdPciResAllocTableBase  _gPcd_BinaryPatch_PcdPciResAllocTableBase
#define _PCD_SET_MODE_32_PcdPciResAllocTableBase(Value)  (_gPcd_BinaryPatch_PcdPciResAllocTableBase = (Value))
#define _PCD_SET_MODE_32_S_PcdPciResAllocTableBase(Value)  ((_gPcd_BinaryPatch_PcdPciResAllocTableBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciResAllocTableBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciResAllocTableBase _gPcd_BinaryPatch_Size_PcdPciResAllocTableBase
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResAllocTableBase; 
#define _PCD_TOKEN_PcdPciEnumHookProc  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPciEnumHookProc;
#define _PCD_GET_MODE_32_PcdPciEnumHookProc  _gPcd_BinaryPatch_PcdPciEnumHookProc
#define _PCD_SET_MODE_32_PcdPciEnumHookProc(Value)  (_gPcd_BinaryPatch_PcdPciEnumHookProc = (Value))
#define _PCD_SET_MODE_32_S_PcdPciEnumHookProc(Value)  ((_gPcd_BinaryPatch_PcdPciEnumHookProc = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciEnumHookProc_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciEnumHookProc _gPcd_BinaryPatch_Size_PcdPciEnumHookProc
extern UINTN _gPcd_BinaryPatch_Size_PcdPciEnumHookProc; 


#ifdef __cplusplus
}
#endif

#endif
