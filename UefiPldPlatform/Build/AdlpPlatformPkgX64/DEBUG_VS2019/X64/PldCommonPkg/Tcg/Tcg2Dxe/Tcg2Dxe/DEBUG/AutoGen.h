/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_FDFF263D_5F68_4591_87BA_B768F445A9AF
#define _AUTOGENH_FDFF263D_5F68_4591_87BA_B768F445A9AF

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xFDFF263D, 0x5F68, 0x4591, {0x87, 0xBA, 0xB7, 0x68, 0xF4, 0x45, 0xA9, 0xAF}}

// Guids
extern EFI_GUID gEfiGlobalVariableGuid;
extern EFI_GUID gEfiImageSecurityDatabaseGuid;
extern EFI_GUID gTcgEventEntryHobGuid;
extern EFI_GUID gTpmErrorHobGuid;
extern EFI_GUID gEfiEventExitBootServicesGuid;
extern EFI_GUID gEventExitBootServicesFailedGuid;
extern EFI_GUID gEfiTpmDeviceInstanceNoneGuid;
extern EFI_GUID gEfiTpmDeviceInstanceTpm12Guid;
extern EFI_GUID gTcgEvent2EntryHobGuid;
extern EFI_GUID gLoaderFspInfoGuid;
extern EFI_GUID gTpm2StartupLocalityHobGuid;
extern EFI_GUID gEfiAcpiTableGuid;
extern EFI_GUID gEfiSecurityPkgTokenSpaceGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gUefiSystemTableInfoGuid;
extern EFI_GUID gUefiSerialPortInfoGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gUefiPayloadPkgTokenSpaceGuid;
extern EFI_GUID gEfiVTUTF8Guid;
extern EFI_GUID gEfiVT100Guid;
extern EFI_GUID gEfiVT100PlusGuid;
extern EFI_GUID gEfiPcAnsiGuid;
extern EFI_GUID gEfiUartDevicePathGuid;
extern EFI_GUID gEfiSasDevicePathGuid;
extern EFI_GUID gEfiVirtualDiskGuid;
extern EFI_GUID gEfiVirtualCdGuid;
extern EFI_GUID gEfiPersistentVirtualDiskGuid;
extern EFI_GUID gEfiPersistentVirtualCdGuid;
extern EFI_GUID gEfiEventReadyToBootGuid;
extern EFI_GUID gEfiEventLegacyBootGuid;
extern EFI_GUID gEfiAcpi20TableGuid;
extern EFI_GUID gEfiAcpi10TableGuid;
extern EFI_GUID gEfiHobListGuid;
extern EFI_GUID gUefiAcpiBoardInfoGuid;
extern EFI_GUID gEdkiiIfrBitVarstoreGuid;
extern EFI_GUID gEfiStatusCodeSpecificDataGuid;
extern EFI_GUID gEfiStatusCodeDataTypeDebugGuid;
extern EFI_GUID gEfiTcg2PhysicalPresenceGuid;

// Protocols
extern EFI_GUID gEfiTcg2ProtocolGuid;
extern EFI_GUID gEfiTcg2FinalEventsTableGuid;
extern EFI_GUID gEfiAcpiTableProtocolGuid;
extern EFI_GUID gEfiMpServiceProtocolGuid;
extern EFI_GUID gEfiVariableWriteArchProtocolGuid;
extern EFI_GUID gEfiResetNotificationProtocolGuid;
extern EFI_GUID gPcdProtocolGuid;
extern EFI_GUID gEfiPcdProtocolGuid;
extern EFI_GUID gGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiDevicePathProtocolGuid;
extern EFI_GUID gEfiDebugPortProtocolGuid;
extern EFI_GUID gEfiDriverBindingProtocolGuid;
extern EFI_GUID gEfiSimpleTextOutProtocolGuid;
extern EFI_GUID gEfiGraphicsOutputProtocolGuid;
extern EFI_GUID gEfiHiiFontProtocolGuid;
extern EFI_GUID gEfiSimpleFileSystemProtocolGuid;
extern EFI_GUID gEfiUgaDrawProtocolGuid;
extern EFI_GUID gEfiComponentNameProtocolGuid;
extern EFI_GUID gEfiComponentName2ProtocolGuid;
extern EFI_GUID gEfiDriverConfigurationProtocolGuid;
extern EFI_GUID gEfiDriverConfiguration2ProtocolGuid;
extern EFI_GUID gEfiDriverDiagnosticsProtocolGuid;
extern EFI_GUID gEfiDriverDiagnostics2ProtocolGuid;
extern EFI_GUID gEfiHiiStringProtocolGuid;
extern EFI_GUID gEfiHiiImageProtocolGuid;
extern EFI_GUID gEfiHiiDatabaseProtocolGuid;
extern EFI_GUID gEfiHiiConfigRoutingProtocolGuid;
extern EFI_GUID gEfiFormBrowser2ProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;
extern EFI_GUID gEfiStatusCodeRuntimeProtocolGuid;
extern EFI_GUID gEdkiiVariableLockProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdTpmPlatformClass  201U
#define _PCD_SIZE_PcdTpmPlatformClass 1
#define _PCD_GET_MODE_SIZE_PcdTpmPlatformClass  _PCD_SIZE_PcdTpmPlatformClass 
#define _PCD_VALUE_PcdTpmPlatformClass  0U
extern const  UINT8  _gPcd_FixedAtBuild_PcdTpmPlatformClass;
#define _PCD_GET_MODE_8_PcdTpmPlatformClass  _gPcd_FixedAtBuild_PcdTpmPlatformClass
//#define _PCD_SET_MODE_8_PcdTpmPlatformClass  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFirmwareDebuggerInitialized  22U
#define _PCD_GET_MODE_BOOL_PcdFirmwareDebuggerInitialized  LibPcdGetBool(_PCD_TOKEN_PcdFirmwareDebuggerInitialized)
#define _PCD_GET_MODE_SIZE_PcdFirmwareDebuggerInitialized  LibPcdGetSize(_PCD_TOKEN_PcdFirmwareDebuggerInitialized)
#define _PCD_SET_MODE_BOOL_PcdFirmwareDebuggerInitialized(Value)  LibPcdSetBool(_PCD_TOKEN_PcdFirmwareDebuggerInitialized, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdFirmwareDebuggerInitialized(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdFirmwareDebuggerInitialized, (Value))

#define _PCD_TOKEN_PcdTpmInstanceGuid  25U
#define _PCD_GET_MODE_PTR_PcdTpmInstanceGuid  LibPcdGetPtr(_PCD_TOKEN_PcdTpmInstanceGuid)
#define _PCD_GET_MODE_SIZE_PcdTpmInstanceGuid  LibPcdGetSize(_PCD_TOKEN_PcdTpmInstanceGuid)
#define _PCD_SET_MODE_PTR_PcdTpmInstanceGuid(SizeOfBuffer, Buffer)  LibPcdSetPtr(_PCD_TOKEN_PcdTpmInstanceGuid, (SizeOfBuffer), (Buffer))
#define _PCD_SET_MODE_PTR_S_PcdTpmInstanceGuid(SizeOfBuffer, Buffer)  LibPcdSetPtrS(_PCD_TOKEN_PcdTpmInstanceGuid, (SizeOfBuffer), (Buffer))

#define _PCD_TOKEN_PcdTpmBaseAddress  200U
#define _PCD_SIZE_PcdTpmBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdTpmBaseAddress  _PCD_SIZE_PcdTpmBaseAddress 
#define _PCD_VALUE_PcdTpmBaseAddress  0xFED40000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdTpmBaseAddress;
#define _PCD_GET_MODE_64_PcdTpmBaseAddress  _gPcd_FixedAtBuild_PcdTpmBaseAddress
//#define _PCD_SET_MODE_64_PcdTpmBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiDefaultOemId  43U
#define _PCD_VALUE_PcdAcpiDefaultOemId  _gPcd_FixedAtBuild_PcdAcpiDefaultOemId
extern const UINT8 _gPcd_FixedAtBuild_PcdAcpiDefaultOemId[7];
#define _PCD_GET_MODE_PTR_PcdAcpiDefaultOemId  _gPcd_FixedAtBuild_PcdAcpiDefaultOemId
#define _PCD_SIZE_PcdAcpiDefaultOemId 7
#define _PCD_GET_MODE_SIZE_PcdAcpiDefaultOemId  _PCD_SIZE_PcdAcpiDefaultOemId 
//#define _PCD_SET_MODE_PTR_PcdAcpiDefaultOemId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiDefaultOemTableId  45U
#define _PCD_SIZE_PcdAcpiDefaultOemTableId 8
#define _PCD_GET_MODE_SIZE_PcdAcpiDefaultOemTableId  _PCD_SIZE_PcdAcpiDefaultOemTableId 
#define _PCD_VALUE_PcdAcpiDefaultOemTableId  0x20202020324B4445ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdAcpiDefaultOemTableId;
#define _PCD_GET_MODE_64_PcdAcpiDefaultOemTableId  _gPcd_FixedAtBuild_PcdAcpiDefaultOemTableId
//#define _PCD_SET_MODE_64_PcdAcpiDefaultOemTableId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiDefaultOemRevision  44U
#define _PCD_SIZE_PcdAcpiDefaultOemRevision 4
#define _PCD_GET_MODE_SIZE_PcdAcpiDefaultOemRevision  _PCD_SIZE_PcdAcpiDefaultOemRevision 
#define _PCD_VALUE_PcdAcpiDefaultOemRevision  0x00000002U
extern const  UINT32  _gPcd_FixedAtBuild_PcdAcpiDefaultOemRevision;
#define _PCD_GET_MODE_32_PcdAcpiDefaultOemRevision  _gPcd_FixedAtBuild_PcdAcpiDefaultOemRevision
//#define _PCD_SET_MODE_32_PcdAcpiDefaultOemRevision  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiDefaultCreatorId  41U
#define _PCD_SIZE_PcdAcpiDefaultCreatorId 4
#define _PCD_GET_MODE_SIZE_PcdAcpiDefaultCreatorId  _PCD_SIZE_PcdAcpiDefaultCreatorId 
#define _PCD_VALUE_PcdAcpiDefaultCreatorId  0x20202020U
extern const  UINT32  _gPcd_FixedAtBuild_PcdAcpiDefaultCreatorId;
#define _PCD_GET_MODE_32_PcdAcpiDefaultCreatorId  _gPcd_FixedAtBuild_PcdAcpiDefaultCreatorId
//#define _PCD_SET_MODE_32_PcdAcpiDefaultCreatorId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiDefaultCreatorRevision  42U
#define _PCD_SIZE_PcdAcpiDefaultCreatorRevision 4
#define _PCD_GET_MODE_SIZE_PcdAcpiDefaultCreatorRevision  _PCD_SIZE_PcdAcpiDefaultCreatorRevision 
#define _PCD_VALUE_PcdAcpiDefaultCreatorRevision  0x01000013U
extern const  UINT32  _gPcd_FixedAtBuild_PcdAcpiDefaultCreatorRevision;
#define _PCD_GET_MODE_32_PcdAcpiDefaultCreatorRevision  _gPcd_FixedAtBuild_PcdAcpiDefaultCreatorRevision
//#define _PCD_SET_MODE_32_PcdAcpiDefaultCreatorRevision  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStatusCodeSubClassTpmDevice  193U
#define _PCD_SIZE_PcdStatusCodeSubClassTpmDevice 4
#define _PCD_GET_MODE_SIZE_PcdStatusCodeSubClassTpmDevice  _PCD_SIZE_PcdStatusCodeSubClassTpmDevice 
#define _PCD_VALUE_PcdStatusCodeSubClassTpmDevice  0x010D0000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStatusCodeSubClassTpmDevice;
#define _PCD_GET_MODE_32_PcdStatusCodeSubClassTpmDevice  _gPcd_FixedAtBuild_PcdStatusCodeSubClassTpmDevice
//#define _PCD_SET_MODE_32_PcdStatusCodeSubClassTpmDevice  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTcg2HashAlgorithmBitmap  23U
#define _PCD_GET_MODE_32_PcdTcg2HashAlgorithmBitmap  LibPcdGet32(_PCD_TOKEN_PcdTcg2HashAlgorithmBitmap)
#define _PCD_GET_MODE_SIZE_PcdTcg2HashAlgorithmBitmap  LibPcdGetSize(_PCD_TOKEN_PcdTcg2HashAlgorithmBitmap)
#define _PCD_SET_MODE_32_PcdTcg2HashAlgorithmBitmap(Value)  LibPcdSet32(_PCD_TOKEN_PcdTcg2HashAlgorithmBitmap, (Value))
#define _PCD_SET_MODE_32_S_PcdTcg2HashAlgorithmBitmap(Value)  LibPcdSet32S(_PCD_TOKEN_PcdTcg2HashAlgorithmBitmap, (Value))

#define _PCD_TOKEN_PcdTcg2NumberOfPCRBanks  195U
#define _PCD_SIZE_PcdTcg2NumberOfPCRBanks 4
#define _PCD_GET_MODE_SIZE_PcdTcg2NumberOfPCRBanks  _PCD_SIZE_PcdTcg2NumberOfPCRBanks 
#define _PCD_VALUE_PcdTcg2NumberOfPCRBanks  0x0U
extern const  UINT32  _gPcd_FixedAtBuild_PcdTcg2NumberOfPCRBanks;
#define _PCD_GET_MODE_32_PcdTcg2NumberOfPCRBanks  _gPcd_FixedAtBuild_PcdTcg2NumberOfPCRBanks
//#define _PCD_SET_MODE_32_PcdTcg2NumberOfPCRBanks  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTcgLogAreaMinLen  197U
#define _PCD_SIZE_PcdTcgLogAreaMinLen 4
#define _PCD_GET_MODE_SIZE_PcdTcgLogAreaMinLen  _PCD_SIZE_PcdTcgLogAreaMinLen 
#define _PCD_VALUE_PcdTcgLogAreaMinLen  0x10000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen;
#define _PCD_GET_MODE_32_PcdTcgLogAreaMinLen  _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen
//#define _PCD_SET_MODE_32_PcdTcgLogAreaMinLen  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTcg2FinalLogAreaLen  194U
#define _PCD_SIZE_PcdTcg2FinalLogAreaLen 4
#define _PCD_GET_MODE_SIZE_PcdTcg2FinalLogAreaLen  _PCD_SIZE_PcdTcg2FinalLogAreaLen 
#define _PCD_VALUE_PcdTcg2FinalLogAreaLen  0x8000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdTcg2FinalLogAreaLen;
#define _PCD_GET_MODE_32_PcdTcg2FinalLogAreaLen  _gPcd_FixedAtBuild_PcdTcg2FinalLogAreaLen
//#define _PCD_SET_MODE_32_PcdTcg2FinalLogAreaLen  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
DriverEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
