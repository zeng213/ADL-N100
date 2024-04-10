/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_BA714111_62C0_4C59_9898_E34A766E1515
#define _AUTOGENH_BA714111_62C0_4C59_9898_E34A766E1515

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
#define _PCD_TOKEN_PcdStage1BXip  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdStage1BXip;
#define _PCD_GET_MODE_BOOL_PcdStage1BXip  _gPcd_FixedAtBuild_PcdStage1BXip
//#define _PCD_SET_MODE_BOOL_PcdStage1BXip  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdStage1BFdBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1BFdBase;
#define _PCD_GET_MODE_32_PcdStage1BFdBase  _gPcd_FixedAtBuild_PcdStage1BFdBase
//#define _PCD_SET_MODE_32_PcdStage1BFdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1BFdBase 0xFFD00000
#define _PCD_SIZE_PcdStage1BFdBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BFdBase _PCD_SIZE_PcdStage1BFdBase
#define _PCD_TOKEN_PcdStage1BFdSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdStage1BFdSize;
#define _PCD_GET_MODE_32_PcdStage1BFdSize  _gPcd_FixedAtBuild_PcdStage1BFdSize
//#define _PCD_SET_MODE_32_PcdStage1BFdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdStage1BFdSize 0x00200000
#define _PCD_SIZE_PcdStage1BFdSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BFdSize _PCD_SIZE_PcdStage1BFdSize


#ifdef __cplusplus
}
#endif

#endif
