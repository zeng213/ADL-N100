/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_DED53C0B_1EA9_4b29_9780_45A6A6C6BC36
#define _AUTOGENH_DED53C0B_1EA9_4b29_9780_45A6A6C6BC36

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdUsbTransferTimeoutValue  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdUsbTransferTimeoutValue;
#define _PCD_GET_MODE_32_PcdUsbTransferTimeoutValue  _gPcd_FixedAtBuild_PcdUsbTransferTimeoutValue
//#define _PCD_SET_MODE_32_PcdUsbTransferTimeoutValue  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdUsbTransferTimeoutValue 3000
#define _PCD_SIZE_PcdUsbTransferTimeoutValue 4
#define _PCD_GET_MODE_SIZE_PcdUsbTransferTimeoutValue _PCD_SIZE_PcdUsbTransferTimeoutValue
#define _PCD_TOKEN_PcdUsbKeyboardPollingTimeout  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdUsbKeyboardPollingTimeout;
#define _PCD_GET_MODE_32_PcdUsbKeyboardPollingTimeout  _gPcd_FixedAtBuild_PcdUsbKeyboardPollingTimeout
//#define _PCD_SET_MODE_32_PcdUsbKeyboardPollingTimeout  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdUsbKeyboardPollingTimeout 0x1
#define _PCD_SIZE_PcdUsbKeyboardPollingTimeout 4
#define _PCD_GET_MODE_SIZE_PcdUsbKeyboardPollingTimeout _PCD_SIZE_PcdUsbKeyboardPollingTimeout


#ifdef __cplusplus
}
#endif

#endif
