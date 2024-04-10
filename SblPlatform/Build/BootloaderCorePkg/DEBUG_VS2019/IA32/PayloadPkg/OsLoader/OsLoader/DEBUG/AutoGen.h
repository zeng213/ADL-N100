/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A257AA67_53F3_491B_8CFF_E9A4E2E2A514
#define _AUTOGENH_A257AA67_53F3_491B_8CFF_E9A4E2E2A514

#ifdef __cplusplus
extern "C" {
#endif

#include <PiPei.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xA257AA67, 0x53F3, 0x491B, {0x8C, 0xFF, 0xE9, 0xA4, 0xE2, 0xE2, 0xA5, 0x14}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}}

// Guids
extern EFI_GUID gOsConfigDataGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gLoaderPlatformInfoGuid;
extern EFI_GUID gBootLoaderVersionGuid;
extern EFI_GUID gFlashMapInfoGuid;
extern EFI_GUID gSeedListInfoHobGuid;
extern EFI_GUID gLoaderMpCpuTaskInfoGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gPayloadTokenSpaceGuid;
extern EFI_GUID gPlatformCommonLibTokenSpaceGuid;
extern EFI_GUID gPlatformModuleTokenSpaceGuid;
extern EFI_GUID gPlatformAlderLakeTokenSpaceGuid;
extern EFI_GUID gPayloadKeyHashGuid;
extern EFI_GUID gDeviceTableHobGuid;
extern EFI_GUID gUniversalPayloadSerialPortInfoGuid;
extern EFI_GUID gZeroGuid;
extern EFI_GUID gPeiFirmwarePerformanceGuid;
extern EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid;
extern EFI_GUID gLoaderFspInfoGuid;
extern EFI_GUID gCsmePerformanceInfoGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gLoaderSystemTableInfoGuid;
extern EFI_GUID gLoaderPerformanceInfoGuid;
extern EFI_GUID gEfiPartTypeUnusedGuid;
extern EFI_GUID gLoaderLibraryDataGuid;
extern EFI_GUID gLoaderPlatformDataGuid;
extern EFI_GUID gBootLoaderServiceGuid;
extern EFI_GUID gLoaderPciRootBridgeInfoGuid;
extern EFI_GUID gOsBootOptionGuid;
extern EFI_GUID gTcgEvent2EntryHobGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdPciExpressBaseAddress  ((UINT64)0xC0000000ULL)
extern volatile   UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdDebugPrintErrorLevel  0U
#define _PCD_PATCHABLE_VALUE_PcdDebugPrintErrorLevel  ((UINT32)0x8000004FU)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdDebugPrintErrorLevel  _gPcd_BinaryPatch_PcdDebugPrintErrorLevel
#define _PCD_PATCHABLE_PcdDebugPrintErrorLevel_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdDebugPrintErrorLevel  _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel 
extern UINTN _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel; 
#define _PCD_SET_MODE_32_PcdDebugPrintErrorLevel(Value)  (_gPcd_BinaryPatch_PcdDebugPrintErrorLevel = (Value))
#define _PCD_SET_MODE_32_S_PcdDebugPrintErrorLevel(Value)  ((_gPcd_BinaryPatch_PcdDebugPrintErrorLevel = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPayloadHobList  0U
#define _PCD_PATCHABLE_VALUE_PcdPayloadHobList  ((UINT32)0x00000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPayloadHobList;
#define _PCD_GET_MODE_32_PcdPayloadHobList  _gPcd_BinaryPatch_PcdPayloadHobList
#define _PCD_PATCHABLE_PcdPayloadHobList_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadHobList  _gPcd_BinaryPatch_Size_PcdPayloadHobList 
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadHobList; 
#define _PCD_SET_MODE_32_PcdPayloadHobList(Value)  (_gPcd_BinaryPatch_PcdPayloadHobList = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadHobList(Value)  ((_gPcd_BinaryPatch_PcdPayloadHobList = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPayloadStackSize  0U
#define _PCD_PATCHABLE_VALUE_PcdPayloadStackSize  ((UINT32)0x00020000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPayloadStackSize;
#define _PCD_GET_MODE_32_PcdPayloadStackSize  _gPcd_BinaryPatch_PcdPayloadStackSize
#define _PCD_PATCHABLE_PcdPayloadStackSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadStackSize  _gPcd_BinaryPatch_Size_PcdPayloadStackSize 
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadStackSize; 
#define _PCD_SET_MODE_32_PcdPayloadStackSize(Value)  (_gPcd_BinaryPatch_PcdPayloadStackSize = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadStackSize(Value)  ((_gPcd_BinaryPatch_PcdPayloadStackSize = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPayloadModuleEnabled  0U
#define _PCD_SIZE_PcdPayloadModuleEnabled 1
#define _PCD_GET_MODE_SIZE_PcdPayloadModuleEnabled  _PCD_SIZE_PcdPayloadModuleEnabled 
#define _PCD_VALUE_PcdPayloadModuleEnabled  ((BOOLEAN)0x0)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPayloadModuleEnabled;
#define _PCD_GET_MODE_BOOL_PcdPayloadModuleEnabled  _gPcd_FixedAtBuild_PcdPayloadModuleEnabled
//#define _PCD_SET_MODE_BOOL_PcdPayloadModuleEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPlatformBootTimeOut  1U
#define _PCD_GET_MODE_16_PcdPlatformBootTimeOut  LibPcdGet16(_PCD_TOKEN_PcdPlatformBootTimeOut)
#define _PCD_GET_MODE_SIZE_PcdPlatformBootTimeOut  LibPcdGetSize(_PCD_TOKEN_PcdPlatformBootTimeOut)
#define _PCD_SET_MODE_16_PcdPlatformBootTimeOut(Value)  LibPcdSet16(_PCD_TOKEN_PcdPlatformBootTimeOut, (Value))
#define _PCD_SET_MODE_16_S_PcdPlatformBootTimeOut(Value)  LibPcdSet16S(_PCD_TOKEN_PcdPlatformBootTimeOut, (Value))

#define _PCD_TOKEN_PcdMeasuredBootEnabled  0U
#define _PCD_SIZE_PcdMeasuredBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdMeasuredBootEnabled  _PCD_SIZE_PcdMeasuredBootEnabled 
#define _PCD_VALUE_PcdMeasuredBootEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdMeasuredBootEnabled  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdMeasuredBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVerifiedBootEnabled  0U
#define _PCD_SIZE_PcdVerifiedBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdVerifiedBootEnabled  _PCD_SIZE_PcdVerifiedBootEnabled 
#define _PCD_VALUE_PcdVerifiedBootEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootEnabled  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugOutputDeviceMask  0U
#define _PCD_SIZE_PcdDebugOutputDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdDebugOutputDeviceMask  _PCD_SIZE_PcdDebugOutputDeviceMask 
#define _PCD_VALUE_PcdDebugOutputDeviceMask  0x00000003U
extern const  UINT32  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask;
#define _PCD_GET_MODE_32_PcdDebugOutputDeviceMask  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask
//#define _PCD_SET_MODE_32_PcdDebugOutputDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadHeapSize  0U
#define _PCD_PATCHABLE_VALUE_PcdPayloadHeapSize  ((UINT32)0x04000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPayloadHeapSize;
#define _PCD_GET_MODE_32_PcdPayloadHeapSize  _gPcd_BinaryPatch_PcdPayloadHeapSize
#define _PCD_PATCHABLE_PcdPayloadHeapSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadHeapSize  _gPcd_BinaryPatch_Size_PcdPayloadHeapSize 
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadHeapSize; 
#define _PCD_SET_MODE_32_PcdPayloadHeapSize(Value)  (_gPcd_BinaryPatch_PcdPayloadHeapSize = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadHeapSize(Value)  ((_gPcd_BinaryPatch_PcdPayloadHeapSize = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSeedListEnabled  0U
#define _PCD_SIZE_PcdSeedListEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSeedListEnabled  _PCD_SIZE_PcdSeedListEnabled 
#define _PCD_VALUE_PcdSeedListEnabled  0x0
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSeedListEnabled;
#define _PCD_GET_MODE_BOOL_PcdSeedListEnabled  _gPcd_FixedAtBuild_PcdSeedListEnabled
//#define _PCD_SET_MODE_BOOL_PcdSeedListEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdConsoleInDeviceMask  0U
#define _PCD_SIZE_PcdConsoleInDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdConsoleInDeviceMask  _PCD_SIZE_PcdConsoleInDeviceMask 
#define _PCD_VALUE_PcdConsoleInDeviceMask  0x1U
extern const  UINT32  _gPcd_FixedAtBuild_PcdConsoleInDeviceMask;
#define _PCD_GET_MODE_32_PcdConsoleInDeviceMask  _gPcd_FixedAtBuild_PcdConsoleInDeviceMask
//#define _PCD_SET_MODE_32_PcdConsoleInDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdConsoleOutDeviceMask  0U
#define _PCD_SIZE_PcdConsoleOutDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdConsoleOutDeviceMask  _PCD_SIZE_PcdConsoleOutDeviceMask 
#define _PCD_VALUE_PcdConsoleOutDeviceMask  0x1U
extern const  UINT32  _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask;
#define _PCD_GET_MODE_32_PcdConsoleOutDeviceMask  _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask
//#define _PCD_SET_MODE_32_PcdConsoleOutDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFrameBufferMaxConsoleWidth  0U
#define _PCD_SIZE_PcdFrameBufferMaxConsoleWidth 4
#define _PCD_GET_MODE_SIZE_PcdFrameBufferMaxConsoleWidth  _PCD_SIZE_PcdFrameBufferMaxConsoleWidth 
#define _PCD_VALUE_PcdFrameBufferMaxConsoleWidth  0xFFFFFFFFU
extern const  UINT32  _gPcd_FixedAtBuild_PcdFrameBufferMaxConsoleWidth;
#define _PCD_GET_MODE_32_PcdFrameBufferMaxConsoleWidth  _gPcd_FixedAtBuild_PcdFrameBufferMaxConsoleWidth
//#define _PCD_SET_MODE_32_PcdFrameBufferMaxConsoleWidth  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFrameBufferMaxConsoleHeight  0U
#define _PCD_SIZE_PcdFrameBufferMaxConsoleHeight 4
#define _PCD_GET_MODE_SIZE_PcdFrameBufferMaxConsoleHeight  _PCD_SIZE_PcdFrameBufferMaxConsoleHeight 
#define _PCD_VALUE_PcdFrameBufferMaxConsoleHeight  0xFFFFFFFFU
extern const  UINT32  _gPcd_FixedAtBuild_PcdFrameBufferMaxConsoleHeight;
#define _PCD_GET_MODE_32_PcdFrameBufferMaxConsoleHeight  _gPcd_FixedAtBuild_PcdFrameBufferMaxConsoleHeight
//#define _PCD_SET_MODE_32_PcdFrameBufferMaxConsoleHeight  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGrubBootCfgEnabled  0U
#define _PCD_SIZE_PcdGrubBootCfgEnabled 1
#define _PCD_GET_MODE_SIZE_PcdGrubBootCfgEnabled  _PCD_SIZE_PcdGrubBootCfgEnabled 
#define _PCD_VALUE_PcdGrubBootCfgEnabled  ((BOOLEAN)0x0)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdGrubBootCfgEnabled;
#define _PCD_GET_MODE_BOOL_PcdGrubBootCfgEnabled  _gPcd_FixedAtBuild_PcdGrubBootCfgEnabled
//#define _PCD_SET_MODE_BOOL_PcdGrubBootCfgEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMeasuredBootHashMask  2U
#define _PCD_GET_MODE_32_PcdMeasuredBootHashMask  LibPcdGet32(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_GET_MODE_SIZE_PcdMeasuredBootHashMask  LibPcdGetSize(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_SET_MODE_32_PcdMeasuredBootHashMask(Value)  LibPcdSet32(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))
#define _PCD_SET_MODE_32_S_PcdMeasuredBootHashMask(Value)  LibPcdSet32S(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))

#define _PCD_TOKEN_PcdRtcmRsvdSize  0U
#define _PCD_SIZE_PcdRtcmRsvdSize 4
#define _PCD_GET_MODE_SIZE_PcdRtcmRsvdSize  _PCD_SIZE_PcdRtcmRsvdSize 
#define _PCD_VALUE_PcdRtcmRsvdSize  0x000FF000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdRtcmRsvdSize;
#define _PCD_GET_MODE_32_PcdRtcmRsvdSize  _gPcd_FixedAtBuild_PcdRtcmRsvdSize
//#define _PCD_SET_MODE_32_PcdRtcmRsvdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c






#ifdef __cplusplus
}
#endif

#endif
