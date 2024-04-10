/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_6DBF359B_DC7D_4009_9827_D8C736157706
#define _AUTOGENH_6DBF359B_DC7D_4009_9827_D8C736157706

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gSmmInformationGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
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
