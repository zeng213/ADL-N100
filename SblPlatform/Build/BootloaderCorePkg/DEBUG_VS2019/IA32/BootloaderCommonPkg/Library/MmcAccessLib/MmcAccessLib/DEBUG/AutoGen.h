/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_2C3E0812_1516_4327_8281_68710197A082
#define _AUTOGENH_2C3E0812_1516_4327_8281_68710197A082

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
#define _PCD_TOKEN_PcdEmmcBlockDeviceLibId  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdEmmcBlockDeviceLibId;
#define _PCD_GET_MODE_8_PcdEmmcBlockDeviceLibId  _gPcd_FixedAtBuild_PcdEmmcBlockDeviceLibId
//#define _PCD_SET_MODE_8_PcdEmmcBlockDeviceLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdEmmcBlockDeviceLibId 3
#define _PCD_SIZE_PcdEmmcBlockDeviceLibId 1
#define _PCD_GET_MODE_SIZE_PcdEmmcBlockDeviceLibId _PCD_SIZE_PcdEmmcBlockDeviceLibId
#define _PCD_TOKEN_PcdEmmcMaxRwBlockNumber  0U
extern volatile  UINT16  _gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber;
#define _PCD_GET_MODE_16_PcdEmmcMaxRwBlockNumber  _gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber
#define _PCD_SET_MODE_16_PcdEmmcMaxRwBlockNumber(Value)  (_gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber = (Value))
#define _PCD_SET_MODE_16_S_PcdEmmcMaxRwBlockNumber(Value)  ((_gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdEmmcMaxRwBlockNumber_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdEmmcMaxRwBlockNumber _gPcd_BinaryPatch_Size_PcdEmmcMaxRwBlockNumber
extern UINTN _gPcd_BinaryPatch_Size_PcdEmmcMaxRwBlockNumber; 
#define _PCD_TOKEN_PcdEmmcHs400SupportEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdEmmcHs400SupportEnabled;
#define _PCD_GET_MODE_BOOL_PcdEmmcHs400SupportEnabled  _gPcd_FixedAtBuild_PcdEmmcHs400SupportEnabled
//#define _PCD_SET_MODE_BOOL_PcdEmmcHs400SupportEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdDmaBufferSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdDmaBufferSize;
#define _PCD_GET_MODE_32_PcdDmaBufferSize  _gPcd_FixedAtBuild_PcdDmaBufferSize
//#define _PCD_SET_MODE_32_PcdDmaBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdDmaBufferSize 0x00400000
#define _PCD_SIZE_PcdDmaBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdDmaBufferSize _PCD_SIZE_PcdDmaBufferSize
#define _PCD_TOKEN_PcdDmaProtectionEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdDmaProtectionEnabled;
#define _PCD_GET_MODE_BOOL_PcdDmaProtectionEnabled  _gPcd_FixedAtBuild_PcdDmaProtectionEnabled
//#define _PCD_SET_MODE_BOOL_PcdDmaProtectionEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
