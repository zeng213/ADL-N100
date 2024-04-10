/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A4EC8ADB_B7A8_47d1_8E52_EC820D0ACF6F
#define _AUTOGENH_A4EC8ADB_B7A8_47d1_8E52_EC820D0ACF6F

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xA4EC8ADB, 0xB7A8, 0x47d1, {0x8E, 0x52, 0xEC, 0x82, 0x0D, 0x0A, 0xCF, 0x6F}}

// Guids
extern EFI_GUID gEfiFirmwareFileSystem2Guid;
extern EFI_GUID gEfiSystemNvDataFvGuid;
extern EFI_GUID gEfiAuthenticatedVariableGuid;
extern EFI_GUID gSpiFlashVariableInfoGuid;
extern EFI_GUID gLoaderFspInfoGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gPldCommonPkgTokenSpaceGuid;
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
extern EFI_GUID gEfiGlobalVariableGuid;
extern EFI_GUID gEfiAcpi20TableGuid;
extern EFI_GUID gEfiAcpi10TableGuid;
extern EFI_GUID gEfiHobListGuid;
extern EFI_GUID gUefiAcpiBoardInfoGuid;
extern EFI_GUID gEfiFileInfoGuid;

// Protocols
extern EFI_GUID gEfiDevicePathProtocolGuid;
extern EFI_GUID gEfiSmmFirmwareVolumeBlockProtocolGuid;
extern EFI_GUID gEfiMpServiceProtocolGuid;
extern EFI_GUID gPcdProtocolGuid;
extern EFI_GUID gEfiPcdProtocolGuid;
extern EFI_GUID gGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiSmmBase2ProtocolGuid;
extern EFI_GUID gEfiDebugPortProtocolGuid;
extern EFI_GUID gEfiSmmAccess2ProtocolGuid;
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
extern EFI_GUID gEfiLoadedImageProtocolGuid;
extern EFI_GUID gEfiFirmwareVolume2ProtocolGuid;
extern EFI_GUID gEfiLoadFileProtocolGuid;
extern EFI_GUID gEfiLoadFile2ProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdFlashNvStorageVariableBase  9U
#define _PCD_GET_MODE_32_PcdFlashNvStorageVariableBase  LibPcdGet32(_PCD_TOKEN_PcdFlashNvStorageVariableBase)
#define _PCD_GET_MODE_SIZE_PcdFlashNvStorageVariableBase  LibPcdGetSize(_PCD_TOKEN_PcdFlashNvStorageVariableBase)
#define _PCD_SET_MODE_32_PcdFlashNvStorageVariableBase(Value)  LibPcdSet32(_PCD_TOKEN_PcdFlashNvStorageVariableBase, (Value))
#define _PCD_SET_MODE_32_S_PcdFlashNvStorageVariableBase(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFlashNvStorageVariableBase, (Value))

#define _PCD_TOKEN_PcdFlashNvStorageVariableSize  11U
#define _PCD_GET_MODE_32_PcdFlashNvStorageVariableSize  LibPcdGet32(_PCD_TOKEN_PcdFlashNvStorageVariableSize)
#define _PCD_GET_MODE_SIZE_PcdFlashNvStorageVariableSize  LibPcdGetSize(_PCD_TOKEN_PcdFlashNvStorageVariableSize)
#define _PCD_SET_MODE_32_PcdFlashNvStorageVariableSize(Value)  LibPcdSet32(_PCD_TOKEN_PcdFlashNvStorageVariableSize, (Value))
#define _PCD_SET_MODE_32_S_PcdFlashNvStorageVariableSize(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFlashNvStorageVariableSize, (Value))

#define _PCD_TOKEN_PcdFlashNvStorageFtwWorkingSize  8U
#define _PCD_GET_MODE_32_PcdFlashNvStorageFtwWorkingSize  LibPcdGet32(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingSize)
#define _PCD_GET_MODE_SIZE_PcdFlashNvStorageFtwWorkingSize  LibPcdGetSize(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingSize)
#define _PCD_SET_MODE_32_PcdFlashNvStorageFtwWorkingSize(Value)  LibPcdSet32(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingSize, (Value))
#define _PCD_SET_MODE_32_S_PcdFlashNvStorageFtwWorkingSize(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingSize, (Value))

#define _PCD_TOKEN_PcdFlashNvStorageFtwSpareSize  6U
#define _PCD_GET_MODE_32_PcdFlashNvStorageFtwSpareSize  LibPcdGet32(_PCD_TOKEN_PcdFlashNvStorageFtwSpareSize)
#define _PCD_GET_MODE_SIZE_PcdFlashNvStorageFtwSpareSize  LibPcdGetSize(_PCD_TOKEN_PcdFlashNvStorageFtwSpareSize)
#define _PCD_SET_MODE_32_PcdFlashNvStorageFtwSpareSize(Value)  LibPcdSet32(_PCD_TOKEN_PcdFlashNvStorageFtwSpareSize, (Value))
#define _PCD_SET_MODE_32_S_PcdFlashNvStorageFtwSpareSize(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFlashNvStorageFtwSpareSize, (Value))

#define _PCD_TOKEN_PcdFlashNvStorageVariableBase64  10U
#define _PCD_GET_MODE_64_PcdFlashNvStorageVariableBase64  LibPcdGet64(_PCD_TOKEN_PcdFlashNvStorageVariableBase64)
#define _PCD_GET_MODE_SIZE_PcdFlashNvStorageVariableBase64  LibPcdGetSize(_PCD_TOKEN_PcdFlashNvStorageVariableBase64)
#define _PCD_SET_MODE_64_PcdFlashNvStorageVariableBase64(Value)  LibPcdSet64(_PCD_TOKEN_PcdFlashNvStorageVariableBase64, (Value))
#define _PCD_SET_MODE_64_S_PcdFlashNvStorageVariableBase64(Value)  LibPcdSet64S(_PCD_TOKEN_PcdFlashNvStorageVariableBase64, (Value))

#define _PCD_TOKEN_PcdFlashNvStorageFtwWorkingBase  7U
#define _PCD_GET_MODE_32_PcdFlashNvStorageFtwWorkingBase  LibPcdGet32(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingBase)
#define _PCD_GET_MODE_SIZE_PcdFlashNvStorageFtwWorkingBase  LibPcdGetSize(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingBase)
#define _PCD_SET_MODE_32_PcdFlashNvStorageFtwWorkingBase(Value)  LibPcdSet32(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingBase, (Value))
#define _PCD_SET_MODE_32_S_PcdFlashNvStorageFtwWorkingBase(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFlashNvStorageFtwWorkingBase, (Value))

#define _PCD_TOKEN_PcdFlashNvStorageFtwSpareBase  5U
#define _PCD_GET_MODE_32_PcdFlashNvStorageFtwSpareBase  LibPcdGet32(_PCD_TOKEN_PcdFlashNvStorageFtwSpareBase)
#define _PCD_GET_MODE_SIZE_PcdFlashNvStorageFtwSpareBase  LibPcdGetSize(_PCD_TOKEN_PcdFlashNvStorageFtwSpareBase)
#define _PCD_SET_MODE_32_PcdFlashNvStorageFtwSpareBase(Value)  LibPcdSet32(_PCD_TOKEN_PcdFlashNvStorageFtwSpareBase, (Value))
#define _PCD_SET_MODE_32_S_PcdFlashNvStorageFtwSpareBase(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFlashNvStorageFtwSpareBase, (Value))

#define _PCD_TOKEN_PcdNvsDataFileSecureBoot  249U
#define _PCD_VALUE_PcdNvsDataFileSecureBoot  (VOID *)_gPcd_FixedAtBuild_PcdNvsDataFileSecureBoot
extern const UINT8 _gPcd_FixedAtBuild_PcdNvsDataFileSecureBoot[16];
#define _PCD_GET_MODE_PTR_PcdNvsDataFileSecureBoot  (VOID *)_gPcd_FixedAtBuild_PcdNvsDataFileSecureBoot
#define _PCD_SIZE_PcdNvsDataFileSecureBoot 16
#define _PCD_GET_MODE_SIZE_PcdNvsDataFileSecureBoot  _PCD_SIZE_PcdNvsDataFileSecureBoot 
//#define _PCD_SET_MODE_PTR_PcdNvsDataFileSecureBoot  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdNvsDataFile  248U
#define _PCD_VALUE_PcdNvsDataFile  (VOID *)_gPcd_FixedAtBuild_PcdNvsDataFile
extern const UINT8 _gPcd_FixedAtBuild_PcdNvsDataFile[16];
#define _PCD_GET_MODE_PTR_PcdNvsDataFile  (VOID *)_gPcd_FixedAtBuild_PcdNvsDataFile
#define _PCD_SIZE_PcdNvsDataFile 16
#define _PCD_GET_MODE_SIZE_PcdNvsDataFile  _PCD_SIZE_PcdNvsDataFile 
//#define _PCD_SET_MODE_PTR_PcdNvsDataFile  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
FvbSmmInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
