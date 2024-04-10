/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_F9D88642_0737_49bc_81B5_6889CD57D9EA
#define _AUTOGENH_F9D88642_0737_49bc_81B5_6889CD57D9EA

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
#define _PCD_TOKEN_PcdSmbiosTablesBase  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSmbiosTablesBase;
#define _PCD_GET_MODE_32_PcdSmbiosTablesBase  _gPcd_BinaryPatch_PcdSmbiosTablesBase
#define _PCD_SET_MODE_32_PcdSmbiosTablesBase(Value)  (_gPcd_BinaryPatch_PcdSmbiosTablesBase = (Value))
#define _PCD_SET_MODE_32_S_PcdSmbiosTablesBase(Value)  ((_gPcd_BinaryPatch_PcdSmbiosTablesBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmbiosTablesBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmbiosTablesBase _gPcd_BinaryPatch_Size_PcdSmbiosTablesBase
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosTablesBase; 
#define _PCD_TOKEN_PcdSmbiosTablesSize  0U
extern const UINT16 _gPcd_FixedAtBuild_PcdSmbiosTablesSize;
#define _PCD_GET_MODE_16_PcdSmbiosTablesSize  _gPcd_FixedAtBuild_PcdSmbiosTablesSize
//#define _PCD_SET_MODE_16_PcdSmbiosTablesSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSmbiosTablesSize 0x1000
#define _PCD_SIZE_PcdSmbiosTablesSize 2
#define _PCD_GET_MODE_SIZE_PcdSmbiosTablesSize _PCD_SIZE_PcdSmbiosTablesSize
#define _PCD_TOKEN_PcdSmbiosStringsPtr  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSmbiosStringsPtr;
#define _PCD_GET_MODE_32_PcdSmbiosStringsPtr  _gPcd_BinaryPatch_PcdSmbiosStringsPtr
#define _PCD_SET_MODE_32_PcdSmbiosStringsPtr(Value)  (_gPcd_BinaryPatch_PcdSmbiosStringsPtr = (Value))
#define _PCD_SET_MODE_32_S_PcdSmbiosStringsPtr(Value)  ((_gPcd_BinaryPatch_PcdSmbiosStringsPtr = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmbiosStringsPtr_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmbiosStringsPtr _gPcd_BinaryPatch_Size_PcdSmbiosStringsPtr
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosStringsPtr; 
#define _PCD_TOKEN_PcdSmbiosStringsCnt  0U
extern volatile  UINT16  _gPcd_BinaryPatch_PcdSmbiosStringsCnt;
#define _PCD_GET_MODE_16_PcdSmbiosStringsCnt  _gPcd_BinaryPatch_PcdSmbiosStringsCnt
#define _PCD_SET_MODE_16_PcdSmbiosStringsCnt(Value)  (_gPcd_BinaryPatch_PcdSmbiosStringsCnt = (Value))
#define _PCD_SET_MODE_16_S_PcdSmbiosStringsCnt(Value)  ((_gPcd_BinaryPatch_PcdSmbiosStringsCnt = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmbiosStringsCnt_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdSmbiosStringsCnt _gPcd_BinaryPatch_Size_PcdSmbiosStringsCnt
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosStringsCnt; 
#define _PCD_TOKEN_PcdLegacyEfSegmentEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdLegacyEfSegmentEnabled;
#define _PCD_GET_MODE_BOOL_PcdLegacyEfSegmentEnabled  _gPcd_FixedAtBuild_PcdLegacyEfSegmentEnabled
//#define _PCD_SET_MODE_BOOL_PcdLegacyEfSegmentEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
