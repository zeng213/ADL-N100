/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_3F2FE5B4_5E95_44C4_8466_9BF5BA32A2CD
#define _AUTOGENH_3F2FE5B4_5E95_44C4_8466_9BF5BA32A2CD

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gZeroGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdVariableLibId  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdVariableLibId;
#define _PCD_GET_MODE_8_PcdVariableLibId  _gPcd_FixedAtBuild_PcdVariableLibId
//#define _PCD_SET_MODE_8_PcdVariableLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdVariableLibId 1
#define _PCD_SIZE_PcdVariableLibId 1
#define _PCD_GET_MODE_SIZE_PcdVariableLibId _PCD_SIZE_PcdVariableLibId


#ifdef __cplusplus
}
#endif

#endif
