/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_245CB4DA_8E15_4A1B_87E3_9878FFA07520
#define _AUTOGENH_245CB4DA_8E15_4A1B_87E3_9878FFA07520

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x245CB4DA, 0x8E15, 0x4A1B, {0x87, 0xE3, 0x98, 0x78, 0xFF, 0xA0, 0x75, 0x20}}

// Guids
extern EFI_GUID gUefiOvmfPkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
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
extern EFI_GUID gUefiSystemTableInfoGuid;
extern EFI_GUID gUefiSerialPortInfoGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gUefiPayloadPkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiLegacy8259ProtocolGuid;
extern EFI_GUID gEfiPciIoProtocolGuid;
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

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_Pcd8259LegacyModeMask  283U
#define _PCD_SIZE_Pcd8259LegacyModeMask 2
#define _PCD_GET_MODE_SIZE_Pcd8259LegacyModeMask  _PCD_SIZE_Pcd8259LegacyModeMask 
#define _PCD_VALUE_Pcd8259LegacyModeMask  0xFFFFU
extern const  UINT16  _gPcd_FixedAtBuild_Pcd8259LegacyModeMask;
#define _PCD_GET_MODE_16_Pcd8259LegacyModeMask  _gPcd_FixedAtBuild_Pcd8259LegacyModeMask
//#define _PCD_SET_MODE_16_Pcd8259LegacyModeMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_Pcd8259LegacyModeEdgeLevel  282U
#define _PCD_SIZE_Pcd8259LegacyModeEdgeLevel 2
#define _PCD_GET_MODE_SIZE_Pcd8259LegacyModeEdgeLevel  _PCD_SIZE_Pcd8259LegacyModeEdgeLevel 
#define _PCD_VALUE_Pcd8259LegacyModeEdgeLevel  0x0000U
extern const  UINT16  _gPcd_FixedAtBuild_Pcd8259LegacyModeEdgeLevel;
#define _PCD_GET_MODE_16_Pcd8259LegacyModeEdgeLevel  _gPcd_FixedAtBuild_Pcd8259LegacyModeEdgeLevel
//#define _PCD_SET_MODE_16_Pcd8259LegacyModeEdgeLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
Install8259 (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
