/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_2119BBD7_9432_4f47_B5E2_5C4EA31B6BDC
#define _AUTOGENH_2119BBD7_9432_4f47_B5E2_5C4EA31B6BDC

#ifdef __cplusplus
extern "C" {
#endif

#include <PiPei.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x2119BBD7, 0x9432, 0x4f47, {0xB5, 0xE2, 0x5C, 0x4E, 0xA3, 0x1B, 0x6B, 0xDC}}

// Guids
extern EFI_GUID gEfiMemoryTypeInformationGuid;
extern EFI_GUID gEfiFirmwareFileSystem2Guid;
extern EFI_GUID gUefiSystemTableInfoGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gUefiAcpiBoardInfoGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gUefiPayloadPkgTokenSpaceGuid;
extern EFI_GUID gUefiPlatformPkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gEfiHobMemoryAllocModuleGuid;
extern EFI_GUID gEfiHobMemoryAllocStackGuid;
extern EFI_GUID gEmbeddedTokenSpaceGuid;
extern EFI_GUID gUefiSerialPortInfoGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gLoaderFspInfoGuid;
extern EFI_GUID gSmmInformationGuid;
extern EFI_GUID gTpmEventLogInfoGuid;
extern EFI_GUID gSpiFlashVariableInfoGuid;
extern EFI_GUID gLoaderPlatformInfoGuid;
extern EFI_GUID gDeviceTableHobGuid;
extern EFI_GUID gFlashMapInfoGuid;
extern EFI_GUID gLoaderPerformanceInfoGuid;
extern EFI_GUID gEfiSecurityPkgTokenSpaceGuid;
extern EFI_GUID gEfiTpmDeviceInstanceNoneGuid;
extern EFI_GUID gEfiTpmDeviceInstanceTpm20DtpmGuid;
extern EFI_GUID gTpmDeviceInstanceTpm20PttPtpGuid;
extern EFI_GUID gLoaderPciRootBridgeInfoGuid;
extern EFI_GUID gSecureBootInfoGuid;

// Protocols
extern EFI_GUID gPeCoffLoaderProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdDxeIplSwitchToLongMode  42U
#define _PCD_SIZE_PcdDxeIplSwitchToLongMode 1
#define _PCD_GET_MODE_SIZE_PcdDxeIplSwitchToLongMode  _PCD_SIZE_PcdDxeIplSwitchToLongMode 
#define _PCD_VALUE_PcdDxeIplSwitchToLongMode  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdDxeIplSwitchToLongMode;
#define _PCD_GET_MODE_BOOL_PcdDxeIplSwitchToLongMode  _gPcd_FixedAtBuild_PcdDxeIplSwitchToLongMode
//#define _PCD_SET_MODE_BOOL_PcdDxeIplSwitchToLongMode  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUse1GPageTable  62U
#define _PCD_SIZE_PcdUse1GPageTable 1
#define _PCD_GET_MODE_SIZE_PcdUse1GPageTable  _PCD_SIZE_PcdUse1GPageTable 
#define _PCD_VALUE_PcdUse1GPageTable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUse1GPageTable;
#define _PCD_GET_MODE_BOOL_PcdUse1GPageTable  _gPcd_FixedAtBuild_PcdUse1GPageTable
//#define _PCD_SET_MODE_BOOL_PcdUse1GPageTable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPteMemoryEncryptionAddressOrMask  48U
#define _PCD_SIZE_PcdPteMemoryEncryptionAddressOrMask 8
#define _PCD_GET_MODE_SIZE_PcdPteMemoryEncryptionAddressOrMask  _PCD_SIZE_PcdPteMemoryEncryptionAddressOrMask 
#define _PCD_VALUE_PcdPteMemoryEncryptionAddressOrMask  0x0ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdPteMemoryEncryptionAddressOrMask;
#define _PCD_GET_MODE_64_PcdPteMemoryEncryptionAddressOrMask  _gPcd_FixedAtBuild_PcdPteMemoryEncryptionAddressOrMask
//#define _PCD_SET_MODE_64_PcdPteMemoryEncryptionAddressOrMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdNullPointerDetectionPropertyMask  46U
#define _PCD_SIZE_PcdNullPointerDetectionPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdNullPointerDetectionPropertyMask  _PCD_SIZE_PcdNullPointerDetectionPropertyMask 
#define _PCD_VALUE_PcdNullPointerDetectionPropertyMask  0x0U
extern const  UINT8  _gPcd_FixedAtBuild_PcdNullPointerDetectionPropertyMask;
#define _PCD_GET_MODE_8_PcdNullPointerDetectionPropertyMask  _gPcd_FixedAtBuild_PcdNullPointerDetectionPropertyMask
//#define _PCD_SET_MODE_8_PcdNullPointerDetectionPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHeapGuardPropertyMask  44U
#define _PCD_SIZE_PcdHeapGuardPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdHeapGuardPropertyMask  _PCD_SIZE_PcdHeapGuardPropertyMask 
#define _PCD_VALUE_PcdHeapGuardPropertyMask  0x0U
extern const  UINT8  _gPcd_FixedAtBuild_PcdHeapGuardPropertyMask;
#define _PCD_GET_MODE_8_PcdHeapGuardPropertyMask  _gPcd_FixedAtBuild_PcdHeapGuardPropertyMask
//#define _PCD_SET_MODE_8_PcdHeapGuardPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuStackGuard  41U
#define _PCD_SIZE_PcdCpuStackGuard 1
#define _PCD_GET_MODE_SIZE_PcdCpuStackGuard  _PCD_SIZE_PcdCpuStackGuard 
#define _PCD_VALUE_PcdCpuStackGuard  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuStackGuard;
#define _PCD_GET_MODE_BOOL_PcdCpuStackGuard  _gPcd_FixedAtBuild_PcdCpuStackGuard
//#define _PCD_SET_MODE_BOOL_PcdCpuStackGuard  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUse5LevelPageTable  63U
#define _PCD_SIZE_PcdUse5LevelPageTable 1
#define _PCD_GET_MODE_SIZE_PcdUse5LevelPageTable  _PCD_SIZE_PcdUse5LevelPageTable 
#define _PCD_VALUE_PcdUse5LevelPageTable  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUse5LevelPageTable;
#define _PCD_GET_MODE_BOOL_PcdUse5LevelPageTable  _gPcd_FixedAtBuild_PcdUse5LevelPageTable
//#define _PCD_SET_MODE_BOOL_PcdUse5LevelPageTable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadFdMemBase  88U
#define _PCD_SIZE_PcdPayloadFdMemBase 4
#define _PCD_GET_MODE_SIZE_PcdPayloadFdMemBase  _PCD_SIZE_PcdPayloadFdMemBase 
#define _PCD_VALUE_PcdPayloadFdMemBase  0x800000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadFdMemBase;
#define _PCD_GET_MODE_32_PcdPayloadFdMemBase  _gPcd_FixedAtBuild_PcdPayloadFdMemBase
//#define _PCD_SET_MODE_32_PcdPayloadFdMemBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadFdMemSize  89U
#define _PCD_SIZE_PcdPayloadFdMemSize 4
#define _PCD_GET_MODE_SIZE_PcdPayloadFdMemSize  _PCD_SIZE_PcdPayloadFdMemSize 
#define _PCD_VALUE_PcdPayloadFdMemSize  0x630000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadFdMemSize;
#define _PCD_GET_MODE_32_PcdPayloadFdMemSize  _gPcd_FixedAtBuild_PcdPayloadFdMemSize
//#define _PCD_SET_MODE_32_PcdPayloadFdMemSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadStackTop  90U
#define _PCD_SIZE_PcdPayloadStackTop 4
#define _PCD_GET_MODE_SIZE_PcdPayloadStackTop  _PCD_SIZE_PcdPayloadStackTop 
#define _PCD_VALUE_PcdPayloadStackTop  0x90000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadStackTop;
#define _PCD_GET_MODE_32_PcdPayloadStackTop  _gPcd_FixedAtBuild_PcdPayloadStackTop
//#define _PCD_SET_MODE_32_PcdPayloadStackTop  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSystemMemoryUefiRegionSize  91U
#define _PCD_SIZE_PcdSystemMemoryUefiRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdSystemMemoryUefiRegionSize  _PCD_SIZE_PcdSystemMemoryUefiRegionSize 
#define _PCD_VALUE_PcdSystemMemoryUefiRegionSize  0x02000000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdSystemMemoryUefiRegionSize;
#define _PCD_GET_MODE_32_PcdSystemMemoryUefiRegionSize  _gPcd_FixedAtBuild_PcdSystemMemoryUefiRegionSize
//#define _PCD_SET_MODE_32_PcdSystemMemoryUefiRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSetNxForStack  61U
#define _PCD_SIZE_PcdSetNxForStack 1
#define _PCD_GET_MODE_SIZE_PcdSetNxForStack  _PCD_SIZE_PcdSetNxForStack 
#define _PCD_VALUE_PcdSetNxForStack  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSetNxForStack;
#define _PCD_GET_MODE_BOOL_PcdSetNxForStack  _gPcd_FixedAtBuild_PcdSetNxForStack
//#define _PCD_SET_MODE_BOOL_PcdSetNxForStack  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDxeNxMemoryProtectionPolicy  43U
#define _PCD_SIZE_PcdDxeNxMemoryProtectionPolicy 8
#define _PCD_GET_MODE_SIZE_PcdDxeNxMemoryProtectionPolicy  _PCD_SIZE_PcdDxeNxMemoryProtectionPolicy 
#define _PCD_VALUE_PcdDxeNxMemoryProtectionPolicy  0x0000000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdDxeNxMemoryProtectionPolicy;
#define _PCD_GET_MODE_64_PcdDxeNxMemoryProtectionPolicy  _gPcd_FixedAtBuild_PcdDxeNxMemoryProtectionPolicy
//#define _PCD_SET_MODE_64_PcdDxeNxMemoryProtectionPolicy  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdImageProtectionPolicy  45U
#define _PCD_SIZE_PcdImageProtectionPolicy 4
#define _PCD_GET_MODE_SIZE_PcdImageProtectionPolicy  _PCD_SIZE_PcdImageProtectionPolicy 
#define _PCD_VALUE_PcdImageProtectionPolicy  0x00000002U
extern const  UINT32  _gPcd_FixedAtBuild_PcdImageProtectionPolicy;
#define _PCD_GET_MODE_32_PcdImageProtectionPolicy  _gPcd_FixedAtBuild_PcdImageProtectionPolicy
//#define _PCD_SET_MODE_32_PcdImageProtectionPolicy  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


#ifdef __cplusplus
}
#endif

#endif
