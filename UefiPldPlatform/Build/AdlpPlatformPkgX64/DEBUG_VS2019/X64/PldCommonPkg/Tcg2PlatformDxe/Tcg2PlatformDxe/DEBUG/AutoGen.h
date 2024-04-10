/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_5CAB08D5_AD8F_4d8b_B828_D17A8D9FE977
#define _AUTOGENH_5CAB08D5_AD8F_4d8b_B828_D17A8D9FE977

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x5CAB08D5, 0xAD8F, 0x4d8b, {0xB8, 0x28, 0xD1, 0x7A, 0x8D, 0x9F, 0xE9, 0x77}}

// Guids
extern EFI_GUID gEfiEventExitBootServicesGuid;
extern EFI_GUID gPldCommonPkgTokenSpaceGuid;
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
extern EFI_GUID gUefiAcpiBoardInfoGuid;
extern EFI_GUID gEfiSecurityPkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiDxeSmmReadyToLockProtocolGuid;
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
extern EFI_GUID gEfiTcg2ProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdTpm2HierarchyChangeAuthPlatform  30U
#define _PCD_GET_MODE_BOOL_PcdTpm2HierarchyChangeAuthPlatform  LibPcdGetBool(_PCD_TOKEN_PcdTpm2HierarchyChangeAuthPlatform)
#define _PCD_GET_MODE_SIZE_PcdTpm2HierarchyChangeAuthPlatform  LibPcdGetSize(_PCD_TOKEN_PcdTpm2HierarchyChangeAuthPlatform)
#define _PCD_SET_MODE_BOOL_PcdTpm2HierarchyChangeAuthPlatform(Value)  LibPcdSetBool(_PCD_TOKEN_PcdTpm2HierarchyChangeAuthPlatform, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdTpm2HierarchyChangeAuthPlatform(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdTpm2HierarchyChangeAuthPlatform, (Value))

#define _PCD_TOKEN_PcdTpm2ChangeEps  27U
#define _PCD_GET_MODE_BOOL_PcdTpm2ChangeEps  LibPcdGetBool(_PCD_TOKEN_PcdTpm2ChangeEps)
#define _PCD_GET_MODE_SIZE_PcdTpm2ChangeEps  LibPcdGetSize(_PCD_TOKEN_PcdTpm2ChangeEps)
#define _PCD_SET_MODE_BOOL_PcdTpm2ChangeEps(Value)  LibPcdSetBool(_PCD_TOKEN_PcdTpm2ChangeEps, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdTpm2ChangeEps(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdTpm2ChangeEps, (Value))

#define _PCD_TOKEN_PcdTpm2ChangePps  28U
#define _PCD_GET_MODE_BOOL_PcdTpm2ChangePps  LibPcdGetBool(_PCD_TOKEN_PcdTpm2ChangePps)
#define _PCD_GET_MODE_SIZE_PcdTpm2ChangePps  LibPcdGetSize(_PCD_TOKEN_PcdTpm2ChangePps)
#define _PCD_SET_MODE_BOOL_PcdTpm2ChangePps(Value)  LibPcdSetBool(_PCD_TOKEN_PcdTpm2ChangePps, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdTpm2ChangePps(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdTpm2ChangePps, (Value))

#define _PCD_TOKEN_PcdTpm2Clear  29U
#define _PCD_GET_MODE_BOOL_PcdTpm2Clear  LibPcdGetBool(_PCD_TOKEN_PcdTpm2Clear)
#define _PCD_GET_MODE_SIZE_PcdTpm2Clear  LibPcdGetSize(_PCD_TOKEN_PcdTpm2Clear)
#define _PCD_SET_MODE_BOOL_PcdTpm2Clear(Value)  LibPcdSetBool(_PCD_TOKEN_PcdTpm2Clear, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdTpm2Clear(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdTpm2Clear, (Value))

#define _PCD_TOKEN_PcdTpm2HierarchyControlPlatform  33U
#define _PCD_GET_MODE_BOOL_PcdTpm2HierarchyControlPlatform  LibPcdGetBool(_PCD_TOKEN_PcdTpm2HierarchyControlPlatform)
#define _PCD_GET_MODE_SIZE_PcdTpm2HierarchyControlPlatform  LibPcdGetSize(_PCD_TOKEN_PcdTpm2HierarchyControlPlatform)
#define _PCD_SET_MODE_BOOL_PcdTpm2HierarchyControlPlatform(Value)  LibPcdSetBool(_PCD_TOKEN_PcdTpm2HierarchyControlPlatform, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdTpm2HierarchyControlPlatform(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdTpm2HierarchyControlPlatform, (Value))

#define _PCD_TOKEN_PcdTpm2HierarchyControlEndorsement  31U
#define _PCD_GET_MODE_BOOL_PcdTpm2HierarchyControlEndorsement  LibPcdGetBool(_PCD_TOKEN_PcdTpm2HierarchyControlEndorsement)
#define _PCD_GET_MODE_SIZE_PcdTpm2HierarchyControlEndorsement  LibPcdGetSize(_PCD_TOKEN_PcdTpm2HierarchyControlEndorsement)
#define _PCD_SET_MODE_BOOL_PcdTpm2HierarchyControlEndorsement(Value)  LibPcdSetBool(_PCD_TOKEN_PcdTpm2HierarchyControlEndorsement, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdTpm2HierarchyControlEndorsement(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdTpm2HierarchyControlEndorsement, (Value))

#define _PCD_TOKEN_PcdTpm2HierarchyControlOwner  32U
#define _PCD_GET_MODE_BOOL_PcdTpm2HierarchyControlOwner  LibPcdGetBool(_PCD_TOKEN_PcdTpm2HierarchyControlOwner)
#define _PCD_GET_MODE_SIZE_PcdTpm2HierarchyControlOwner  LibPcdGetSize(_PCD_TOKEN_PcdTpm2HierarchyControlOwner)
#define _PCD_SET_MODE_BOOL_PcdTpm2HierarchyControlOwner(Value)  LibPcdSetBool(_PCD_TOKEN_PcdTpm2HierarchyControlOwner, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdTpm2HierarchyControlOwner(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdTpm2HierarchyControlOwner, (Value))

#define _PCD_TOKEN_PcdTpm2TxtProvisionSupport  250U
#define _PCD_SIZE_PcdTpm2TxtProvisionSupport 1
#define _PCD_GET_MODE_SIZE_PcdTpm2TxtProvisionSupport  _PCD_SIZE_PcdTpm2TxtProvisionSupport 
#define _PCD_VALUE_PcdTpm2TxtProvisionSupport  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdTpm2TxtProvisionSupport;
#define _PCD_GET_MODE_BOOL_PcdTpm2TxtProvisionSupport  _gPcd_FixedAtBuild_PcdTpm2TxtProvisionSupport
//#define _PCD_SET_MODE_BOOL_PcdTpm2TxtProvisionSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

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
