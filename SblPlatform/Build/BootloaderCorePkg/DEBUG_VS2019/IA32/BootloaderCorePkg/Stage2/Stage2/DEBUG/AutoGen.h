/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_1BB388F8_77D8_4c00_98A7_38F45931B2A4
#define _AUTOGENH_1BB388F8_77D8_4c00_98A7_38F45931B2A4

#ifdef __cplusplus
extern "C" {
#endif

#include <PiPei.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x1BB388F8, 0x77D8, 0x4c00, {0x98, 0xA7, 0x38, 0xF4, 0x59, 0x31, 0xB2, 0xA4}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}}

// Guids
extern EFI_GUID gFspReservedMemoryResourceHobGuid;
extern EFI_GUID gLoaderSerialPortInfoGuid;
extern EFI_GUID gLoaderPlatformDeviceInfoGuid;
extern EFI_GUID gLoaderSystemTableInfoGuid;
extern EFI_GUID gLoaderPerformanceInfoGuid;
extern EFI_GUID gLoaderLibraryDataGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gLoaderFspInfoGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gPayloadKeyHashGuid;
extern EFI_GUID gOsBootOptionGuid;
extern EFI_GUID gBootLoaderServiceGuid;
extern EFI_GUID gBootLoaderVersionGuid;
extern EFI_GUID gFlashMapInfoGuid;
extern EFI_GUID gLoaderPlatformInfoGuid;
extern EFI_GUID gSeedListInfoHobGuid;
extern EFI_GUID gLoaderPlatformDataGuid;
extern EFI_GUID gDeviceTableHobGuid;
extern EFI_GUID gSmmInformationGuid;
extern EFI_GUID gLoaderMpCpuTaskInfoGuid;
extern EFI_GUID gUniversalPayloadPciRootBridgeInfoGuid;
extern EFI_GUID gUniversalPayloadAcpiTableGuid;
extern EFI_GUID gUniversalPayloadSmbiosTableGuid;
extern EFI_GUID gUniversalPayloadSerialPortInfoGuid;
extern EFI_GUID gUniversalPayloadExtraDataGuid;
extern EFI_GUID gPldSmmRegisterInfoGuid;
extern EFI_GUID gEfiSmmSmramMemoryGuid;
extern EFI_GUID gSpiFlashInfoGuid;
extern EFI_GUID gNvVariableInfoGuid;
extern EFI_GUID gPldS3CommunicationGuid;
extern EFI_GUID gTpmEventLogInfoGuid;
extern EFI_GUID gSecureBootInfoGuid;
extern EFI_GUID gPlatformCommonLibTokenSpaceGuid;
extern EFI_GUID gPlatformModuleTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gPlatformAlderLakeTokenSpaceGuid;
extern EFI_GUID gMeBiosPayloadHobGuid;
extern EFI_GUID gTccRtctHobGuid;
extern EFI_GUID gTcgEvent2EntryHobGuid;
extern EFI_GUID gSchemaListGuid;
extern EFI_GUID gOsConfigDataGuid;
extern EFI_GUID gZeroGuid;
extern EFI_GUID gFspNonVolatileStorageHobGuid;
extern EFI_GUID gFspNonVolatileStorageHob2Guid;
extern EFI_GUID gFspVariableNvDataHobGuid;
extern EFI_GUID gCpuInitDataHobGuid;
extern EFI_GUID gCsmePerformanceInfoGuid;
extern EFI_GUID gLoaderPciRootBridgeInfoGuid;
extern EFI_GUID gEsrtSystemFirmwareGuid;
extern EFI_GUID gCsmeFWUDriverImageFileGuid;
extern EFI_GUID gPeiFirmwarePerformanceGuid;
extern EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdMaxLibraryDataEntry  0U
#define _PCD_SIZE_PcdMaxLibraryDataEntry 4
#define _PCD_GET_MODE_SIZE_PcdMaxLibraryDataEntry  _PCD_SIZE_PcdMaxLibraryDataEntry 
#define _PCD_VALUE_PcdMaxLibraryDataEntry  8U
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry;
#define _PCD_GET_MODE_32_PcdMaxLibraryDataEntry  _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry
//#define _PCD_SET_MODE_32_PcdMaxLibraryDataEntry  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVerifiedBootEnabled  0U
#define _PCD_SIZE_PcdVerifiedBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdVerifiedBootEnabled  _PCD_SIZE_PcdVerifiedBootEnabled 
#define _PCD_VALUE_PcdVerifiedBootEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootEnabled  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2FdBase  0U
#define _PCD_SIZE_PcdStage2FdBase 4
#define _PCD_GET_MODE_SIZE_PcdStage2FdBase  _PCD_SIZE_PcdStage2FdBase 
#define _PCD_VALUE_PcdStage2FdBase  0x01000000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage2FdBase;
#define _PCD_GET_MODE_32_PcdStage2FdBase  _gPcd_FixedAtBuild_PcdStage2FdBase
//#define _PCD_SET_MODE_32_PcdStage2FdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiTablesAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdAcpiTablesAddress  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdAcpiTablesAddress;
#define _PCD_GET_MODE_32_PcdAcpiTablesAddress  _gPcd_BinaryPatch_PcdAcpiTablesAddress
#define _PCD_PATCHABLE_PcdAcpiTablesAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiTablesAddress  _gPcd_BinaryPatch_Size_PcdAcpiTablesAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiTablesAddress; 
#define _PCD_SET_MODE_32_PcdAcpiTablesAddress(Value)  (_gPcd_BinaryPatch_PcdAcpiTablesAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiTablesAddress(Value)  ((_gPcd_BinaryPatch_PcdAcpiTablesAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPayloadLoadHigh  0U
#define _PCD_SIZE_PcdPayloadLoadHigh 1
#define _PCD_GET_MODE_SIZE_PcdPayloadLoadHigh  _PCD_SIZE_PcdPayloadLoadHigh 
#define _PCD_VALUE_PcdPayloadLoadHigh  0x1
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPayloadLoadHigh;
#define _PCD_GET_MODE_BOOL_PcdPayloadLoadHigh  _gPcd_FixedAtBuild_PcdPayloadLoadHigh
//#define _PCD_SET_MODE_BOOL_PcdPayloadLoadHigh  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadExeBase  0U
#define _PCD_SIZE_PcdPayloadExeBase 4
#define _PCD_GET_MODE_SIZE_PcdPayloadExeBase  _PCD_SIZE_PcdPayloadExeBase 
#define _PCD_VALUE_PcdPayloadExeBase  0x00800000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadExeBase;
#define _PCD_GET_MODE_32_PcdPayloadExeBase  _gPcd_FixedAtBuild_PcdPayloadExeBase
//#define _PCD_SET_MODE_32_PcdPayloadExeBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadLoadBase  0U
#define _PCD_SIZE_PcdPayloadLoadBase 4
#define _PCD_GET_MODE_SIZE_PcdPayloadLoadBase  _PCD_SIZE_PcdPayloadLoadBase 
#define _PCD_VALUE_PcdPayloadLoadBase  0x0U
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadLoadBase;
#define _PCD_GET_MODE_32_PcdPayloadLoadBase  _gPcd_FixedAtBuild_PcdPayloadLoadBase
//#define _PCD_SET_MODE_32_PcdPayloadLoadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFwuPayloadLoadBase  0U
#define _PCD_SIZE_PcdFwuPayloadLoadBase 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadLoadBase  _PCD_SIZE_PcdFwuPayloadLoadBase 
#define _PCD_VALUE_PcdFwuPayloadLoadBase  0x0U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFwuPayloadLoadBase;
#define _PCD_GET_MODE_32_PcdFwuPayloadLoadBase  _gPcd_FixedAtBuild_PcdFwuPayloadLoadBase
//#define _PCD_SET_MODE_32_PcdFwuPayloadLoadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLoaderHobStackSize  0U
#define _PCD_SIZE_PcdLoaderHobStackSize 4
#define _PCD_GET_MODE_SIZE_PcdLoaderHobStackSize  _PCD_SIZE_PcdLoaderHobStackSize 
#define _PCD_VALUE_PcdLoaderHobStackSize  0x00040000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLoaderHobStackSize;
#define _PCD_GET_MODE_32_PcdLoaderHobStackSize  _gPcd_FixedAtBuild_PcdLoaderHobStackSize
//#define _PCD_SET_MODE_32_PcdLoaderHobStackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadReservedMemSize  0U
#define _PCD_PATCHABLE_VALUE_PcdPayloadReservedMemSize  ((UINT32)0x00500000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPayloadReservedMemSize;
#define _PCD_GET_MODE_32_PcdPayloadReservedMemSize  _gPcd_BinaryPatch_PcdPayloadReservedMemSize
#define _PCD_PATCHABLE_PcdPayloadReservedMemSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadReservedMemSize  _gPcd_BinaryPatch_Size_PcdPayloadReservedMemSize 
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadReservedMemSize; 
#define _PCD_SET_MODE_32_PcdPayloadReservedMemSize(Value)  (_gPcd_BinaryPatch_PcdPayloadReservedMemSize = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadReservedMemSize(Value)  ((_gPcd_BinaryPatch_PcdPayloadReservedMemSize = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdLoaderAcpiNvsSize  0U
#define _PCD_SIZE_PcdLoaderAcpiNvsSize 4
#define _PCD_GET_MODE_SIZE_PcdLoaderAcpiNvsSize  _PCD_SIZE_PcdLoaderAcpiNvsSize 
#define _PCD_VALUE_PcdLoaderAcpiNvsSize  0x00008000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLoaderAcpiNvsSize;
#define _PCD_GET_MODE_32_PcdLoaderAcpiNvsSize  _gPcd_FixedAtBuild_PcdLoaderAcpiNvsSize
//#define _PCD_SET_MODE_32_PcdLoaderAcpiNvsSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLoaderAcpiReclaimSize  0U
#define _PCD_SIZE_PcdLoaderAcpiReclaimSize 4
#define _PCD_GET_MODE_SIZE_PcdLoaderAcpiReclaimSize  _PCD_SIZE_PcdLoaderAcpiReclaimSize 
#define _PCD_VALUE_PcdLoaderAcpiReclaimSize  0x00090000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLoaderAcpiReclaimSize;
#define _PCD_GET_MODE_32_PcdLoaderAcpiReclaimSize  _gPcd_FixedAtBuild_PcdLoaderAcpiReclaimSize
//#define _PCD_SET_MODE_32_PcdLoaderAcpiReclaimSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryMapEntryNumber  0U
#define _PCD_SIZE_PcdMemoryMapEntryNumber 4
#define _PCD_GET_MODE_SIZE_PcdMemoryMapEntryNumber  _PCD_SIZE_PcdMemoryMapEntryNumber 
#define _PCD_VALUE_PcdMemoryMapEntryNumber  0x00000020U
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryMapEntryNumber;
#define _PCD_GET_MODE_32_PcdMemoryMapEntryNumber  _gPcd_FixedAtBuild_PcdMemoryMapEntryNumber
//#define _PCD_SET_MODE_32_PcdMemoryMapEntryNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiGnvsAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdAcpiGnvsAddress  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdAcpiGnvsAddress;
#define _PCD_GET_MODE_32_PcdAcpiGnvsAddress  _gPcd_BinaryPatch_PcdAcpiGnvsAddress
#define _PCD_PATCHABLE_PcdAcpiGnvsAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiGnvsAddress  _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress; 
#define _PCD_SET_MODE_32_PcdAcpiGnvsAddress(Value)  (_gPcd_BinaryPatch_PcdAcpiGnvsAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiGnvsAddress(Value)  ((_gPcd_BinaryPatch_PcdAcpiGnvsAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdGraphicsVbtAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdGraphicsVbtAddress  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdGraphicsVbtAddress;
#define _PCD_GET_MODE_32_PcdGraphicsVbtAddress  _gPcd_BinaryPatch_PcdGraphicsVbtAddress
#define _PCD_PATCHABLE_PcdGraphicsVbtAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdGraphicsVbtAddress  _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress; 
#define _PCD_SET_MODE_32_PcdGraphicsVbtAddress(Value)  (_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdGraphicsVbtAddress(Value)  ((_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPsdBiosEnabled  0U
#define _PCD_SIZE_PcdPsdBiosEnabled 1
#define _PCD_GET_MODE_SIZE_PcdPsdBiosEnabled  _PCD_SIZE_PcdPsdBiosEnabled 
#define _PCD_VALUE_PcdPsdBiosEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPsdBiosEnabled;
#define _PCD_GET_MODE_BOOL_PcdPsdBiosEnabled  _gPcd_FixedAtBuild_PcdPsdBiosEnabled
//#define _PCD_SET_MODE_BOOL_PcdPsdBiosEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiEnabled  0U
#define _PCD_SIZE_PcdAcpiEnabled 1
#define _PCD_GET_MODE_SIZE_PcdAcpiEnabled  _PCD_SIZE_PcdAcpiEnabled 
#define _PCD_VALUE_PcdAcpiEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdAcpiEnabled;
#define _PCD_GET_MODE_BOOL_PcdAcpiEnabled  _gPcd_FixedAtBuild_PcdAcpiEnabled
//#define _PCD_SET_MODE_BOOL_PcdAcpiEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSmpEnabled  0U
#define _PCD_SIZE_PcdSmpEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSmpEnabled  _PCD_SIZE_PcdSmpEnabled 
#define _PCD_VALUE_PcdSmpEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSmpEnabled;
#define _PCD_GET_MODE_BOOL_PcdSmpEnabled  _gPcd_FixedAtBuild_PcdSmpEnabled
//#define _PCD_SET_MODE_BOOL_PcdSmpEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciEnumEnabled  0U
#define _PCD_SIZE_PcdPciEnumEnabled 1
#define _PCD_GET_MODE_SIZE_PcdPciEnumEnabled  _PCD_SIZE_PcdPciEnumEnabled 
#define _PCD_VALUE_PcdPciEnumEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPciEnumEnabled;
#define _PCD_GET_MODE_BOOL_PcdPciEnumEnabled  _gPcd_FixedAtBuild_PcdPciEnumEnabled
//#define _PCD_SET_MODE_BOOL_PcdPciEnumEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFSPSBase  0U
#define _PCD_PATCHABLE_VALUE_PcdFSPSBase  ((UINT32)0x01191000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdFSPSBase;
#define _PCD_GET_MODE_32_PcdFSPSBase  _gPcd_BinaryPatch_PcdFSPSBase
#define _PCD_PATCHABLE_PcdFSPSBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFSPSBase  _gPcd_BinaryPatch_Size_PcdFSPSBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdFSPSBase; 
#define _PCD_SET_MODE_32_PcdFSPSBase(Value)  (_gPcd_BinaryPatch_PcdFSPSBase = (Value))
#define _PCD_SET_MODE_32_S_PcdFSPSBase(Value)  ((_gPcd_BinaryPatch_PcdFSPSBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdFlashBaseAddress  0U
#define _PCD_SIZE_PcdFlashBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdFlashBaseAddress  _PCD_SIZE_PcdFlashBaseAddress 
#define _PCD_VALUE_PcdFlashBaseAddress  0xFF300000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashBaseAddress;
#define _PCD_GET_MODE_32_PcdFlashBaseAddress  _gPcd_FixedAtBuild_PcdFlashBaseAddress
//#define _PCD_SET_MODE_32_PcdFlashBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashSize  0U
#define _PCD_SIZE_PcdFlashSize 4
#define _PCD_GET_MODE_SIZE_PcdFlashSize  _PCD_SIZE_PcdFlashSize 
#define _PCD_VALUE_PcdFlashSize  0x00D00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashSize;
#define _PCD_GET_MODE_32_PcdFlashSize  _gPcd_FixedAtBuild_PcdFlashSize
//#define _PCD_SET_MODE_32_PcdFlashSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSplashEnabled  0U
#define _PCD_SIZE_PcdSplashEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSplashEnabled  _PCD_SIZE_PcdSplashEnabled 
#define _PCD_VALUE_PcdSplashEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSplashEnabled;
#define _PCD_GET_MODE_BOOL_PcdSplashEnabled  _gPcd_FixedAtBuild_PcdSplashEnabled
//#define _PCD_SET_MODE_BOOL_PcdSplashEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSplashLogoAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdSplashLogoAddress  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSplashLogoAddress;
#define _PCD_GET_MODE_32_PcdSplashLogoAddress  _gPcd_BinaryPatch_PcdSplashLogoAddress
#define _PCD_PATCHABLE_PcdSplashLogoAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSplashLogoAddress  _gPcd_BinaryPatch_Size_PcdSplashLogoAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdSplashLogoAddress; 
#define _PCD_SET_MODE_32_PcdSplashLogoAddress(Value)  (_gPcd_BinaryPatch_PcdSplashLogoAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdSplashLogoAddress(Value)  ((_gPcd_BinaryPatch_PcdSplashLogoAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdOsBootOptionNumber  0U
#define _PCD_SIZE_PcdOsBootOptionNumber 4
#define _PCD_GET_MODE_SIZE_PcdOsBootOptionNumber  _PCD_SIZE_PcdOsBootOptionNumber 
#define _PCD_VALUE_PcdOsBootOptionNumber  0x00000008U
extern const  UINT32  _gPcd_FixedAtBuild_PcdOsBootOptionNumber;
#define _PCD_GET_MODE_32_PcdOsBootOptionNumber  _gPcd_FixedAtBuild_PcdOsBootOptionNumber
//#define _PCD_SET_MODE_32_PcdOsBootOptionNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdServiceNumber  0U
#define _PCD_SIZE_PcdServiceNumber 4
#define _PCD_GET_MODE_SIZE_PcdServiceNumber  _PCD_SIZE_PcdServiceNumber 
#define _PCD_VALUE_PcdServiceNumber  0x00000004U
extern const  UINT32  _gPcd_FixedAtBuild_PcdServiceNumber;
#define _PCD_GET_MODE_32_PcdServiceNumber  _gPcd_FixedAtBuild_PcdServiceNumber
//#define _PCD_SET_MODE_32_PcdServiceNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMeasuredBootEnabled  0U
#define _PCD_SIZE_PcdMeasuredBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdMeasuredBootEnabled  _PCD_SIZE_PcdMeasuredBootEnabled 
#define _PCD_VALUE_PcdMeasuredBootEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdMeasuredBootEnabled  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdMeasuredBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSeedListBufferSize  0U
#define _PCD_SIZE_PcdSeedListBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdSeedListBufferSize  _PCD_SIZE_PcdSeedListBufferSize 
#define _PCD_VALUE_PcdSeedListBufferSize  0x00000400U
extern const  UINT32  _gPcd_FixedAtBuild_PcdSeedListBufferSize;
#define _PCD_GET_MODE_32_PcdSeedListBufferSize  _gPcd_FixedAtBuild_PcdSeedListBufferSize
//#define _PCD_SET_MODE_32_PcdSeedListBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSeedListEnabled  0U
#define _PCD_SIZE_PcdSeedListEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSeedListEnabled  _PCD_SIZE_PcdSeedListEnabled 
#define _PCD_VALUE_PcdSeedListEnabled  0x0
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSeedListEnabled;
#define _PCD_GET_MODE_BOOL_PcdSeedListEnabled  _gPcd_FixedAtBuild_PcdSeedListEnabled
//#define _PCD_SET_MODE_BOOL_PcdSeedListEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdPciExpressBaseAddress  ((UINT64)0xC0000000ULL)
extern volatile   UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSmbiosTablesBase  0U
#define _PCD_PATCHABLE_VALUE_PcdSmbiosTablesBase  ((UINT32)0x00000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSmbiosTablesBase;
#define _PCD_GET_MODE_32_PcdSmbiosTablesBase  _gPcd_BinaryPatch_PcdSmbiosTablesBase
#define _PCD_PATCHABLE_PcdSmbiosTablesBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmbiosTablesBase  _gPcd_BinaryPatch_Size_PcdSmbiosTablesBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosTablesBase; 
#define _PCD_SET_MODE_32_PcdSmbiosTablesBase(Value)  (_gPcd_BinaryPatch_PcdSmbiosTablesBase = (Value))
#define _PCD_SET_MODE_32_S_PcdSmbiosTablesBase(Value)  ((_gPcd_BinaryPatch_PcdSmbiosTablesBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSmbiosTablesSize  0U
#define _PCD_SIZE_PcdSmbiosTablesSize 2
#define _PCD_GET_MODE_SIZE_PcdSmbiosTablesSize  _PCD_SIZE_PcdSmbiosTablesSize 
#define _PCD_VALUE_PcdSmbiosTablesSize  0x1000U
extern const  UINT16  _gPcd_FixedAtBuild_PcdSmbiosTablesSize;
#define _PCD_GET_MODE_16_PcdSmbiosTablesSize  _gPcd_FixedAtBuild_PcdSmbiosTablesSize
//#define _PCD_SET_MODE_16_PcdSmbiosTablesSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSmbiosEnabled  0U
#define _PCD_SIZE_PcdSmbiosEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSmbiosEnabled  _PCD_SIZE_PcdSmbiosEnabled 
#define _PCD_VALUE_PcdSmbiosEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSmbiosEnabled;
#define _PCD_GET_MODE_BOOL_PcdSmbiosEnabled  _gPcd_FixedAtBuild_PcdSmbiosEnabled
//#define _PCD_SET_MODE_BOOL_PcdSmbiosEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLinuxPayloadEnabled  0U
#define _PCD_SIZE_PcdLinuxPayloadEnabled 1
#define _PCD_GET_MODE_SIZE_PcdLinuxPayloadEnabled  _PCD_SIZE_PcdLinuxPayloadEnabled 
#define _PCD_VALUE_PcdLinuxPayloadEnabled  ((BOOLEAN)0x0)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdLinuxPayloadEnabled;
#define _PCD_GET_MODE_BOOL_PcdLinuxPayloadEnabled  _gPcd_FixedAtBuild_PcdLinuxPayloadEnabled
//#define _PCD_SET_MODE_BOOL_PcdLinuxPayloadEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMeasuredBootHashMask  2U
#define _PCD_GET_MODE_32_PcdMeasuredBootHashMask  LibPcdGet32(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_GET_MODE_SIZE_PcdMeasuredBootHashMask  LibPcdGetSize(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_SET_MODE_32_PcdMeasuredBootHashMask(Value)  LibPcdSet32(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))
#define _PCD_SET_MODE_32_S_PcdMeasuredBootHashMask(Value)  LibPcdSet32S(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))

#define _PCD_TOKEN_PcdSmmRebaseMode  0U
#define _PCD_PATCHABLE_VALUE_PcdSmmRebaseMode  ((UINT8)0x00000002U)
extern volatile   UINT8  _gPcd_BinaryPatch_PcdSmmRebaseMode;
#define _PCD_GET_MODE_8_PcdSmmRebaseMode  _gPcd_BinaryPatch_PcdSmmRebaseMode
#define _PCD_PATCHABLE_PcdSmmRebaseMode_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSmmRebaseMode  _gPcd_BinaryPatch_Size_PcdSmmRebaseMode 
extern UINTN _gPcd_BinaryPatch_Size_PcdSmmRebaseMode; 
#define _PCD_SET_MODE_8_PcdSmmRebaseMode(Value)  (_gPcd_BinaryPatch_PcdSmmRebaseMode = (Value))
#define _PCD_SET_MODE_8_S_PcdSmmRebaseMode(Value)  ((_gPcd_BinaryPatch_PcdSmmRebaseMode = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdAcpiTablesRsdp  0U
#define _PCD_PATCHABLE_VALUE_PcdAcpiTablesRsdp  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdAcpiTablesRsdp;
#define _PCD_GET_MODE_32_PcdAcpiTablesRsdp  _gPcd_BinaryPatch_PcdAcpiTablesRsdp
#define _PCD_PATCHABLE_PcdAcpiTablesRsdp_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiTablesRsdp  _gPcd_BinaryPatch_Size_PcdAcpiTablesRsdp 
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiTablesRsdp; 
#define _PCD_SET_MODE_32_PcdAcpiTablesRsdp(Value)  (_gPcd_BinaryPatch_PcdAcpiTablesRsdp = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiTablesRsdp(Value)  ((_gPcd_BinaryPatch_PcdAcpiTablesRsdp = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdBuildSmmHobs  0U
#define _PCD_SIZE_PcdBuildSmmHobs 1
#define _PCD_GET_MODE_SIZE_PcdBuildSmmHobs  _PCD_SIZE_PcdBuildSmmHobs 
#define _PCD_VALUE_PcdBuildSmmHobs  0x03U
extern const  UINT8  _gPcd_FixedAtBuild_PcdBuildSmmHobs;
#define _PCD_GET_MODE_8_PcdBuildSmmHobs  _gPcd_FixedAtBuild_PcdBuildSmmHobs
//#define _PCD_SET_MODE_8_PcdBuildSmmHobs  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBootPerformanceMask  0U
#define _PCD_SIZE_PcdBootPerformanceMask 4
#define _PCD_GET_MODE_SIZE_PcdBootPerformanceMask  _PCD_SIZE_PcdBootPerformanceMask 
#define _PCD_VALUE_PcdBootPerformanceMask  0x1U
extern const  UINT32  _gPcd_FixedAtBuild_PcdBootPerformanceMask;
#define _PCD_GET_MODE_32_PcdBootPerformanceMask  _gPcd_FixedAtBuild_PcdBootPerformanceMask
//#define _PCD_SET_MODE_32_PcdBootPerformanceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSblResiliencyEnabled  0U
#define _PCD_SIZE_PcdSblResiliencyEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSblResiliencyEnabled  _PCD_SIZE_PcdSblResiliencyEnabled 
#define _PCD_VALUE_PcdSblResiliencyEnabled  0x0
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSblResiliencyEnabled;
#define _PCD_GET_MODE_BOOL_PcdSblResiliencyEnabled  _gPcd_FixedAtBuild_PcdSblResiliencyEnabled
//#define _PCD_SET_MODE_BOOL_PcdSblResiliencyEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdEnableFwuNotify  0U
#define _PCD_SIZE_PcdEnableFwuNotify 1
#define _PCD_GET_MODE_SIZE_PcdEnableFwuNotify  _PCD_SIZE_PcdEnableFwuNotify 
#define _PCD_VALUE_PcdEnableFwuNotify  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdEnableFwuNotify;
#define _PCD_GET_MODE_BOOL_PcdEnableFwuNotify  _gPcd_FixedAtBuild_PcdEnableFwuNotify
//#define _PCD_SET_MODE_BOOL_PcdEnableFwuNotify  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c






#ifdef __cplusplus
}
#endif

#endif
