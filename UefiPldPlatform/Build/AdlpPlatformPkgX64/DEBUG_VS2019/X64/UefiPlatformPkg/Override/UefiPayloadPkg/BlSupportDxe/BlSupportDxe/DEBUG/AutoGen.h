/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_C68DAA4E_7AB5_41e8_A91D_5954421053F3
#define _AUTOGENH_C68DAA4E_7AB5_41e8_A91D_5954421053F3

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xC68DAA4E, 0x7AB5, 0x41e8, {0xA9, 0x1D, 0x59, 0x54, 0x42, 0x10, 0x53, 0xF3}}

// Guids
extern EFI_GUID gEfiAcpiTableGuid;
extern EFI_GUID gEfiSmbiosTableGuid;
extern EFI_GUID gUefiSystemTableInfoGuid;
extern EFI_GUID gUefiAcpiBoardInfoGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gLoaderFspInfoGuid;
extern EFI_GUID gSecureBootInfoGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gIntelFsp2WrapperTokenSpaceGuid;
extern EFI_GUID gEfiSecurityPkgTokenSpaceGuid;
extern EFI_GUID gUefiSerialPortInfoGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
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
extern EFI_GUID gEfiDxeServicesTableGuid;

// Protocols
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

#define _PCD_TOKEN_PcdVideoHorizontalResolution  16U
#define _PCD_GET_MODE_32_PcdVideoHorizontalResolution  LibPcdGet32(_PCD_TOKEN_PcdVideoHorizontalResolution)
#define _PCD_GET_MODE_SIZE_PcdVideoHorizontalResolution  LibPcdGetSize(_PCD_TOKEN_PcdVideoHorizontalResolution)
#define _PCD_SET_MODE_32_PcdVideoHorizontalResolution(Value)  LibPcdSet32(_PCD_TOKEN_PcdVideoHorizontalResolution, (Value))
#define _PCD_SET_MODE_32_S_PcdVideoHorizontalResolution(Value)  LibPcdSet32S(_PCD_TOKEN_PcdVideoHorizontalResolution, (Value))

#define _PCD_TOKEN_PcdVideoVerticalResolution  17U
#define _PCD_GET_MODE_32_PcdVideoVerticalResolution  LibPcdGet32(_PCD_TOKEN_PcdVideoVerticalResolution)
#define _PCD_GET_MODE_SIZE_PcdVideoVerticalResolution  LibPcdGetSize(_PCD_TOKEN_PcdVideoVerticalResolution)
#define _PCD_SET_MODE_32_PcdVideoVerticalResolution(Value)  LibPcdSet32(_PCD_TOKEN_PcdVideoVerticalResolution, (Value))
#define _PCD_SET_MODE_32_S_PcdVideoVerticalResolution(Value)  LibPcdSet32S(_PCD_TOKEN_PcdVideoVerticalResolution, (Value))

#define _PCD_TOKEN_PcdSetupVideoHorizontalResolution  13U
#define _PCD_GET_MODE_32_PcdSetupVideoHorizontalResolution  LibPcdGet32(_PCD_TOKEN_PcdSetupVideoHorizontalResolution)
#define _PCD_GET_MODE_SIZE_PcdSetupVideoHorizontalResolution  LibPcdGetSize(_PCD_TOKEN_PcdSetupVideoHorizontalResolution)
#define _PCD_SET_MODE_32_PcdSetupVideoHorizontalResolution(Value)  LibPcdSet32(_PCD_TOKEN_PcdSetupVideoHorizontalResolution, (Value))
#define _PCD_SET_MODE_32_S_PcdSetupVideoHorizontalResolution(Value)  LibPcdSet32S(_PCD_TOKEN_PcdSetupVideoHorizontalResolution, (Value))

#define _PCD_TOKEN_PcdSetupVideoVerticalResolution  14U
#define _PCD_GET_MODE_32_PcdSetupVideoVerticalResolution  LibPcdGet32(_PCD_TOKEN_PcdSetupVideoVerticalResolution)
#define _PCD_GET_MODE_SIZE_PcdSetupVideoVerticalResolution  LibPcdGetSize(_PCD_TOKEN_PcdSetupVideoVerticalResolution)
#define _PCD_SET_MODE_32_PcdSetupVideoVerticalResolution(Value)  LibPcdSet32(_PCD_TOKEN_PcdSetupVideoVerticalResolution, (Value))
#define _PCD_SET_MODE_32_S_PcdSetupVideoVerticalResolution(Value)  LibPcdSet32S(_PCD_TOKEN_PcdSetupVideoVerticalResolution, (Value))

#define _PCD_TOKEN_PcdPciExpressBaseAddress  18U
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  LibPcdGet64(_PCD_TOKEN_PcdPciExpressBaseAddress)
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress  LibPcdGetSize(_PCD_TOKEN_PcdPciExpressBaseAddress)
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  LibPcdSet64(_PCD_TOKEN_PcdPciExpressBaseAddress, (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  LibPcdSet64S(_PCD_TOKEN_PcdPciExpressBaseAddress, (Value))

#define _PCD_TOKEN_PcdFspsBaseAddress  26U
#define _PCD_GET_MODE_32_PcdFspsBaseAddress  LibPcdGet32(_PCD_TOKEN_PcdFspsBaseAddress)
#define _PCD_GET_MODE_SIZE_PcdFspsBaseAddress  LibPcdGetSize(_PCD_TOKEN_PcdFspsBaseAddress)
#define _PCD_SET_MODE_32_PcdFspsBaseAddress(Value)  LibPcdSet32(_PCD_TOKEN_PcdFspsBaseAddress, (Value))
#define _PCD_SET_MODE_32_S_PcdFspsBaseAddress(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFspsBaseAddress, (Value))

#define _PCD_TOKEN_PcdTpm2HashMask  24U
#define _PCD_GET_MODE_32_PcdTpm2HashMask  LibPcdGet32(_PCD_TOKEN_PcdTpm2HashMask)
#define _PCD_GET_MODE_SIZE_PcdTpm2HashMask  LibPcdGetSize(_PCD_TOKEN_PcdTpm2HashMask)
#define _PCD_SET_MODE_32_PcdTpm2HashMask(Value)  LibPcdSet32(_PCD_TOKEN_PcdTpm2HashMask, (Value))
#define _PCD_SET_MODE_32_S_PcdTpm2HashMask(Value)  LibPcdSet32S(_PCD_TOKEN_PcdTpm2HashMask, (Value))

#define _PCD_TOKEN_PcdFirmwareDebuggerInitialized  22U
#define _PCD_GET_MODE_BOOL_PcdFirmwareDebuggerInitialized  LibPcdGetBool(_PCD_TOKEN_PcdFirmwareDebuggerInitialized)
#define _PCD_GET_MODE_SIZE_PcdFirmwareDebuggerInitialized  LibPcdGetSize(_PCD_TOKEN_PcdFirmwareDebuggerInitialized)
#define _PCD_SET_MODE_BOOL_PcdFirmwareDebuggerInitialized(Value)  LibPcdSetBool(_PCD_TOKEN_PcdFirmwareDebuggerInitialized, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdFirmwareDebuggerInitialized(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdFirmwareDebuggerInitialized, (Value))

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
BlDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
