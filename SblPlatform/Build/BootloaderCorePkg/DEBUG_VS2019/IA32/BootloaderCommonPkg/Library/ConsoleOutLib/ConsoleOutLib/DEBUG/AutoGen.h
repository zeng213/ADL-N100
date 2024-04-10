/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_2167653D_A99A_4789_84D3_7D15B948F5AC
#define _AUTOGENH_2167653D_A99A_4789_84D3_7D15B948F5AC

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
#define _PCD_TOKEN_PcdConsoleOutDeviceMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask;
#define _PCD_GET_MODE_32_PcdConsoleOutDeviceMask  _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask
//#define _PCD_SET_MODE_32_PcdConsoleOutDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdConsoleOutDeviceMask 0x1
#define _PCD_SIZE_PcdConsoleOutDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdConsoleOutDeviceMask _PCD_SIZE_PcdConsoleOutDeviceMask
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
