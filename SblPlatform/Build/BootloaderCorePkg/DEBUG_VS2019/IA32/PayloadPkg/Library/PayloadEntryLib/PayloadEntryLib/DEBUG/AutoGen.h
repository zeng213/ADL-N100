/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_91815665_3EBA_494e_BB8A_58B5CA272BA7
#define _AUTOGENH_91815665_3EBA_494e_BB8A_58B5CA272BA7

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gLoaderLibraryDataGuid;
extern GUID gLoaderPlatformDataGuid;
extern GUID gBootLoaderServiceGuid;
extern GUID gBootLoaderVersionGuid;
extern GUID gLoaderPciRootBridgeInfoGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;
extern GUID gPayloadTokenSpaceGuid;

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
#define _PCD_TOKEN_PcdPayloadHobList  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPayloadHobList;
#define _PCD_GET_MODE_32_PcdPayloadHobList  _gPcd_BinaryPatch_PcdPayloadHobList
#define _PCD_SET_MODE_32_PcdPayloadHobList(Value)  (_gPcd_BinaryPatch_PcdPayloadHobList = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadHobList(Value)  ((_gPcd_BinaryPatch_PcdPayloadHobList = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPayloadHobList_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadHobList _gPcd_BinaryPatch_Size_PcdPayloadHobList
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadHobList; 
#define _PCD_TOKEN_PcdPayloadStackSize  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPayloadStackSize;
#define _PCD_GET_MODE_32_PcdPayloadStackSize  _gPcd_BinaryPatch_PcdPayloadStackSize
#define _PCD_SET_MODE_32_PcdPayloadStackSize(Value)  (_gPcd_BinaryPatch_PcdPayloadStackSize = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadStackSize(Value)  ((_gPcd_BinaryPatch_PcdPayloadStackSize = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPayloadStackSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadStackSize _gPcd_BinaryPatch_Size_PcdPayloadStackSize
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadStackSize; 
#define _PCD_TOKEN_PcdPayloadHeapSize  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPayloadHeapSize;
#define _PCD_GET_MODE_32_PcdPayloadHeapSize  _gPcd_BinaryPatch_PcdPayloadHeapSize
#define _PCD_SET_MODE_32_PcdPayloadHeapSize(Value)  (_gPcd_BinaryPatch_PcdPayloadHeapSize = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadHeapSize(Value)  ((_gPcd_BinaryPatch_PcdPayloadHeapSize = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPayloadHeapSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadHeapSize _gPcd_BinaryPatch_Size_PcdPayloadHeapSize
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadHeapSize; 
#define _PCD_TOKEN_PcdGlobalDataAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdGlobalDataAddress;
#define _PCD_GET_MODE_32_PcdGlobalDataAddress  _gPcd_BinaryPatch_PcdGlobalDataAddress
#define _PCD_SET_MODE_32_PcdGlobalDataAddress(Value)  (_gPcd_BinaryPatch_PcdGlobalDataAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdGlobalDataAddress(Value)  ((_gPcd_BinaryPatch_PcdGlobalDataAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdGlobalDataAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdGlobalDataAddress _gPcd_BinaryPatch_Size_PcdGlobalDataAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdGlobalDataAddress; 
#define _PCD_TOKEN_PcdEmmcMaxRwBlockNumber  0U
extern volatile  UINT16  _gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber;
#define _PCD_GET_MODE_16_PcdEmmcMaxRwBlockNumber  _gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber
#define _PCD_SET_MODE_16_PcdEmmcMaxRwBlockNumber(Value)  (_gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber = (Value))
#define _PCD_SET_MODE_16_S_PcdEmmcMaxRwBlockNumber(Value)  ((_gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdEmmcMaxRwBlockNumber_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdEmmcMaxRwBlockNumber _gPcd_BinaryPatch_Size_PcdEmmcMaxRwBlockNumber
extern UINTN _gPcd_BinaryPatch_Size_PcdEmmcMaxRwBlockNumber; 
#define _PCD_TOKEN_PcdPcdLibId  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdPcdLibId;
#define _PCD_GET_MODE_8_PcdPcdLibId  _gPcd_FixedAtBuild_PcdPcdLibId
//#define _PCD_SET_MODE_8_PcdPcdLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPcdLibId 0
#define _PCD_SIZE_PcdPcdLibId 1
#define _PCD_GET_MODE_SIZE_PcdPcdLibId _PCD_SIZE_PcdPcdLibId
#define _PCD_TOKEN_PcdDmaProtectionEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdDmaProtectionEnabled;
#define _PCD_GET_MODE_BOOL_PcdDmaProtectionEnabled  _gPcd_FixedAtBuild_PcdDmaProtectionEnabled
//#define _PCD_SET_MODE_BOOL_PcdDmaProtectionEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdDmaBufferSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdDmaBufferSize;
#define _PCD_GET_MODE_32_PcdDmaBufferSize  _gPcd_FixedAtBuild_PcdDmaBufferSize
//#define _PCD_SET_MODE_32_PcdDmaBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdDmaBufferSize 0x00400000
#define _PCD_SIZE_PcdDmaBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdDmaBufferSize _PCD_SIZE_PcdDmaBufferSize
#define _PCD_TOKEN_PcdDmaBufferAlignment  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdDmaBufferAlignment;
#define _PCD_GET_MODE_32_PcdDmaBufferAlignment  _gPcd_FixedAtBuild_PcdDmaBufferAlignment
//#define _PCD_SET_MODE_32_PcdDmaBufferAlignment  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdDmaBufferAlignment 0x00100000
#define _PCD_SIZE_PcdDmaBufferAlignment 4
#define _PCD_GET_MODE_SIZE_PcdDmaBufferAlignment _PCD_SIZE_PcdDmaBufferAlignment


#ifdef __cplusplus
}
#endif

#endif
