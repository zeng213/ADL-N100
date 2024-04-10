/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_67B8E021_B014_4E83_B692_9590F8214F87
#define _AUTOGENH_67B8E021_B014_4E83_B692_9590F8214F87

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
#define _PCD_TOKEN_PcdMultiUsbBootDeviceEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdMultiUsbBootDeviceEnabled;
#define _PCD_GET_MODE_BOOL_PcdMultiUsbBootDeviceEnabled  _gPcd_FixedAtBuild_PcdMultiUsbBootDeviceEnabled
//#define _PCD_SET_MODE_BOOL_PcdMultiUsbBootDeviceEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdUsbCmdTimeout  0U
extern const UINT16 _gPcd_FixedAtBuild_PcdUsbCmdTimeout;
#define _PCD_GET_MODE_16_PcdUsbCmdTimeout  _gPcd_FixedAtBuild_PcdUsbCmdTimeout
//#define _PCD_SET_MODE_16_PcdUsbCmdTimeout  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdUsbCmdTimeout 0x00001000
#define _PCD_SIZE_PcdUsbCmdTimeout 2
#define _PCD_GET_MODE_SIZE_PcdUsbCmdTimeout _PCD_SIZE_PcdUsbCmdTimeout


#ifdef __cplusplus
}
#endif

#endif
