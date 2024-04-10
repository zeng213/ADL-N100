/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_9DDDBAA5_3A62_4798_9526_2F1350E8D89E
#define _AUTOGENH_9DDDBAA5_3A62_4798_9526_2F1350E8D89E

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

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdSeedListEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdSeedListEnabled;
#define _PCD_GET_MODE_BOOL_PcdSeedListEnabled  _gPcd_FixedAtBuild_PcdSeedListEnabled
//#define _PCD_SET_MODE_BOOL_PcdSeedListEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSeedListEnabled 0x0
#define _PCD_SIZE_PcdSeedListEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSeedListEnabled _PCD_SIZE_PcdSeedListEnabled


#ifdef __cplusplus
}
#endif

#endif
