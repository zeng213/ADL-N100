/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_12E7B4D9_BC4B_4BE2_9988_6CEC92D6C683
#define _AUTOGENH_12E7B4D9_BC4B_4BE2_9988_6CEC92D6C683

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
#define _PCD_TOKEN_PcdMaxLibraryDataEntry  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry;
#define _PCD_GET_MODE_32_PcdMaxLibraryDataEntry  _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry
//#define _PCD_SET_MODE_32_PcdMaxLibraryDataEntry  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdMaxLibraryDataEntry 8
#define _PCD_SIZE_PcdMaxLibraryDataEntry 4
#define _PCD_GET_MODE_SIZE_PcdMaxLibraryDataEntry _PCD_SIZE_PcdMaxLibraryDataEntry
#define _PCD_TOKEN_PcdDebugOutputDeviceMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask;
#define _PCD_GET_MODE_32_PcdDebugOutputDeviceMask  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask
//#define _PCD_SET_MODE_32_PcdDebugOutputDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdDebugOutputDeviceMask 3
#define _PCD_SIZE_PcdDebugOutputDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdDebugOutputDeviceMask _PCD_SIZE_PcdDebugOutputDeviceMask


#ifdef __cplusplus
}
#endif

#endif
