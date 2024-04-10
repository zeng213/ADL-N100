/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_AD61999A_507E_47E6_BA28_79CC609FA1A4
#define _AUTOGENH_AD61999A_507E_47E6_BA28_79CC609FA1A4

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xAD61999A, 0x507E, 0x47E6, {0xBA, 0x28, 0x79, 0xCC, 0x60, 0x9F, 0xA1, 0xA4}}

// Guids
extern EFI_GUID gFspApiPerformanceGuid;
extern EFI_GUID gEfiEventExitBootServicesGuid;
extern EFI_GUID gFspHobGuid;
extern EFI_GUID gIntelFsp2WrapperTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
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
extern EFI_GUID gFspHeaderFileGuid;
extern EFI_GUID gEfiFileInfoGuid;

// Protocols
extern EFI_GUID gEfiPciEnumerationCompleteProtocolGuid;
extern EFI_GUID gAddPerfRecordProtocolGuid;
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
extern EFI_GUID gEfiLoadedImageProtocolGuid;
extern EFI_GUID gEfiFirmwareVolume2ProtocolGuid;
extern EFI_GUID gEfiLoadFileProtocolGuid;
extern EFI_GUID gEfiLoadFile2ProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdSkipFspApi  234U
#define _PCD_SIZE_PcdSkipFspApi 4
#define _PCD_GET_MODE_SIZE_PcdSkipFspApi  _PCD_SIZE_PcdSkipFspApi 
#define _PCD_VALUE_PcdSkipFspApi  0x00010000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdSkipFspApi;
#define _PCD_GET_MODE_32_PcdSkipFspApi  _gPcd_FixedAtBuild_PcdSkipFspApi
//#define _PCD_SET_MODE_32_PcdSkipFspApi  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
FspWrapperNotifyDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
