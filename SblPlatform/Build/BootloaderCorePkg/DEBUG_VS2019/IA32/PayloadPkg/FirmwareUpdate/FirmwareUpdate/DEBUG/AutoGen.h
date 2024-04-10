/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_E2E57F60_4C17_461e_92A2_E428DBB12D06
#define _AUTOGENH_E2E57F60_4C17_461e_92A2_E428DBB12D06

#ifdef __cplusplus
extern "C" {
#endif

#include <PiPei.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xE2E57F60, 0x4C17, 0x461e, {0x92, 0xA2, 0xE4, 0x28, 0xDB, 0xB1, 0x2D, 0x06}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}}

// Guids
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gLoaderFspInfoGuid;
extern EFI_GUID gLoaderSystemTableInfoGuid;
extern EFI_GUID gEfiPartTypeSystemPartGuid;
extern EFI_GUID gFirmwareUpdateImageFileGuid;
extern EFI_GUID gFlashMapInfoGuid;
extern EFI_GUID gBootLoaderVersionFileGuid;
extern EFI_GUID gBootLoaderVersionGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gPayloadTokenSpaceGuid;
extern EFI_GUID gPlatformCommonLibTokenSpaceGuid;
extern EFI_GUID gPlatformModuleTokenSpaceGuid;
extern EFI_GUID gPayloadKeyHashGuid;
extern EFI_GUID gDeviceTableHobGuid;
extern EFI_GUID gUniversalPayloadSerialPortInfoGuid;
extern EFI_GUID gZeroGuid;
extern EFI_GUID gMeBiosPayloadHobGuid;
extern EFI_GUID gPeiFirmwarePerformanceGuid;
extern EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid;
extern EFI_GUID gCsmePerformanceInfoGuid;
extern EFI_GUID gEfiPartTypeUnusedGuid;
extern EFI_GUID gLoaderPlatformInfoGuid;
extern EFI_GUID gLoaderPerformanceInfoGuid;
extern EFI_GUID gTcgEvent2EntryHobGuid;
extern EFI_GUID gOsBootOptionGuid;
extern EFI_GUID gSblCompFWUpdateImageFileGuid;
extern EFI_GUID gLoaderLibraryDataGuid;
extern EFI_GUID gLoaderPlatformDataGuid;
extern EFI_GUID gBootLoaderServiceGuid;
extern EFI_GUID gLoaderPciRootBridgeInfoGuid;
extern EFI_GUID gOsConfigDataGuid;

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

#define _PCD_TOKEN_PcdPayloadHobList  0U
#define _PCD_PATCHABLE_VALUE_PcdPayloadHobList  ((UINT32)0x00000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPayloadHobList;
#define _PCD_GET_MODE_32_PcdPayloadHobList  _gPcd_BinaryPatch_PcdPayloadHobList
#define _PCD_PATCHABLE_PcdPayloadHobList_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadHobList  _gPcd_BinaryPatch_Size_PcdPayloadHobList 
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadHobList; 
#define _PCD_SET_MODE_32_PcdPayloadHobList(Value)  (_gPcd_BinaryPatch_PcdPayloadHobList = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadHobList(Value)  ((_gPcd_BinaryPatch_PcdPayloadHobList = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdAcpiPmTimerBase  0U
#define _PCD_PATCHABLE_VALUE_PcdAcpiPmTimerBase  ((UINT16)0x00001808U)
extern volatile   UINT16  _gPcd_BinaryPatch_PcdAcpiPmTimerBase;
#define _PCD_GET_MODE_16_PcdAcpiPmTimerBase  _gPcd_BinaryPatch_PcdAcpiPmTimerBase
#define _PCD_PATCHABLE_PcdAcpiPmTimerBase_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdAcpiPmTimerBase  _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase; 
#define _PCD_SET_MODE_16_PcdAcpiPmTimerBase(Value)  (_gPcd_BinaryPatch_PcdAcpiPmTimerBase = (Value))
#define _PCD_SET_MODE_16_S_PcdAcpiPmTimerBase(Value)  ((_gPcd_BinaryPatch_PcdAcpiPmTimerBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdFwUpdStatusBase  0U
#define _PCD_PATCHABLE_VALUE_PcdFwUpdStatusBase  ((UINT32)0x00000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdFwUpdStatusBase;
#define _PCD_GET_MODE_32_PcdFwUpdStatusBase  _gPcd_BinaryPatch_PcdFwUpdStatusBase
#define _PCD_PATCHABLE_PcdFwUpdStatusBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFwUpdStatusBase  _gPcd_BinaryPatch_Size_PcdFwUpdStatusBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdFwUpdStatusBase; 
#define _PCD_SET_MODE_32_PcdFwUpdStatusBase(Value)  (_gPcd_BinaryPatch_PcdFwUpdStatusBase = (Value))
#define _PCD_SET_MODE_32_S_PcdFwUpdStatusBase(Value)  ((_gPcd_BinaryPatch_PcdFwUpdStatusBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdLowestSupportedFwVer  0U
#define _PCD_SIZE_PcdLowestSupportedFwVer 4
#define _PCD_GET_MODE_SIZE_PcdLowestSupportedFwVer  _PCD_SIZE_PcdLowestSupportedFwVer 
#define _PCD_VALUE_PcdLowestSupportedFwVer  0x1U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLowestSupportedFwVer;
#define _PCD_GET_MODE_32_PcdLowestSupportedFwVer  _gPcd_FixedAtBuild_PcdLowestSupportedFwVer
//#define _PCD_SET_MODE_32_PcdLowestSupportedFwVer  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCsmeUpdateEnabled  0U
#define _PCD_SIZE_PcdCsmeUpdateEnabled 1
#define _PCD_GET_MODE_SIZE_PcdCsmeUpdateEnabled  _PCD_SIZE_PcdCsmeUpdateEnabled 
#define _PCD_VALUE_PcdCsmeUpdateEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCsmeUpdateEnabled;
#define _PCD_GET_MODE_BOOL_PcdCsmeUpdateEnabled  _gPcd_FixedAtBuild_PcdCsmeUpdateEnabled
//#define _PCD_SET_MODE_BOOL_PcdCsmeUpdateEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCompSignHashAlg  0U
#define _PCD_SIZE_PcdCompSignHashAlg 1
#define _PCD_GET_MODE_SIZE_PcdCompSignHashAlg  _PCD_SIZE_PcdCompSignHashAlg 
#define _PCD_VALUE_PcdCompSignHashAlg  0x00000002U
extern const  UINT8  _gPcd_FixedAtBuild_PcdCompSignHashAlg;
#define _PCD_GET_MODE_8_PcdCompSignHashAlg  _gPcd_FixedAtBuild_PcdCompSignHashAlg
//#define _PCD_SET_MODE_8_PcdCompSignHashAlg  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdConsoleOutDeviceMask  0U
#define _PCD_SIZE_PcdConsoleOutDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdConsoleOutDeviceMask  _PCD_SIZE_PcdConsoleOutDeviceMask 
#define _PCD_VALUE_PcdConsoleOutDeviceMask  3U
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

#define _PCD_TOKEN_PcdSblResiliencyEnabled  0U
#define _PCD_SIZE_PcdSblResiliencyEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSblResiliencyEnabled  _PCD_SIZE_PcdSblResiliencyEnabled 
#define _PCD_VALUE_PcdSblResiliencyEnabled  0x0
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSblResiliencyEnabled;
#define _PCD_GET_MODE_BOOL_PcdSblResiliencyEnabled  _gPcd_FixedAtBuild_PcdSblResiliencyEnabled
//#define _PCD_SET_MODE_BOOL_PcdSblResiliencyEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBootFailureThreshold  0U
#define _PCD_SIZE_PcdBootFailureThreshold 1
#define _PCD_GET_MODE_SIZE_PcdBootFailureThreshold  _PCD_SIZE_PcdBootFailureThreshold 
#define _PCD_VALUE_PcdBootFailureThreshold  3U
extern const  UINT8  _gPcd_FixedAtBuild_PcdBootFailureThreshold;
#define _PCD_GET_MODE_8_PcdBootFailureThreshold  _gPcd_FixedAtBuild_PcdBootFailureThreshold
//#define _PCD_SET_MODE_8_PcdBootFailureThreshold  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUcodeSlotSize  0U
#define _PCD_SIZE_PcdUcodeSlotSize 4
#define _PCD_GET_MODE_SIZE_PcdUcodeSlotSize  _PCD_SIZE_PcdUcodeSlotSize 
#define _PCD_VALUE_PcdUcodeSlotSize  0x0003B000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdUcodeSlotSize;
#define _PCD_GET_MODE_32_PcdUcodeSlotSize  _gPcd_FixedAtBuild_PcdUcodeSlotSize
//#define _PCD_SET_MODE_32_PcdUcodeSlotSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVerifiedBootEnabled  0U
#define _PCD_SIZE_PcdVerifiedBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdVerifiedBootEnabled  _PCD_SIZE_PcdVerifiedBootEnabled 
#define _PCD_VALUE_PcdVerifiedBootEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootEnabled  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c






#ifdef __cplusplus
}
#endif

#endif
