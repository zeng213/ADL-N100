/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_9F7DCADE_11EA_448a_A46F_76E003657DD1
#define _AUTOGENH_9F7DCADE_11EA_448a_A46F_76E003657DD1

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x9F7DCADE, 0x11EA, 0x448a, {0xA4, 0x6F, 0x76, 0xE0, 0x03, 0x65, 0x7D, 0xD1}}

// Guids
extern EFI_GUID gEfiAuthenticatedVariableGuid;
extern EFI_GUID gEfiVariableGuid;
extern EFI_GUID gEfiEventVirtualAddressChangeGuid;
extern EFI_GUID gEfiEventExitBootServicesGuid;
extern EFI_GUID gSmmVariableWriteGuid;
extern EFI_GUID gEfiGlobalVariableGuid;
extern EFI_GUID gEfiImageSecurityDatabaseGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
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
extern EFI_GUID gUefiSystemTableInfoGuid;
extern EFI_GUID gUefiSerialPortInfoGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gUefiPayloadPkgTokenSpaceGuid;
extern EFI_GUID gEfiDxeServicesTableGuid;

// Protocols
extern EFI_GUID gEfiVariableWriteArchProtocolGuid;
extern EFI_GUID gEfiVariableArchProtocolGuid;
extern EFI_GUID gEfiMmCommunication2ProtocolGuid;
extern EFI_GUID gEfiSmmVariableProtocolGuid;
extern EFI_GUID gEdkiiVariableLockProtocolGuid;
extern EFI_GUID gEdkiiVarCheckProtocolGuid;
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
extern EFI_GUID gEfiTcgProtocolGuid;
extern EFI_GUID gEfiTcg2ProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdEnableVariableRuntimeCache  72U
#define _PCD_SIZE_PcdEnableVariableRuntimeCache 1
#define _PCD_GET_MODE_SIZE_PcdEnableVariableRuntimeCache  _PCD_SIZE_PcdEnableVariableRuntimeCache 
#define _PCD_VALUE_PcdEnableVariableRuntimeCache  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdEnableVariableRuntimeCache;
#define _PCD_GET_MODE_BOOL_PcdEnableVariableRuntimeCache  _gPcd_FixedAtBuild_PcdEnableVariableRuntimeCache
//#define _PCD_SET_MODE_BOOL_PcdEnableVariableRuntimeCache  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVariableCollectStatistics  152U
#define _PCD_SIZE_PcdVariableCollectStatistics 1
#define _PCD_GET_MODE_SIZE_PcdVariableCollectStatistics  _PCD_SIZE_PcdVariableCollectStatistics 
#define _PCD_VALUE_PcdVariableCollectStatistics  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVariableCollectStatistics;
#define _PCD_GET_MODE_BOOL_PcdVariableCollectStatistics  _gPcd_FixedAtBuild_PcdVariableCollectStatistics
//#define _PCD_SET_MODE_BOOL_PcdVariableCollectStatistics  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
VariableSmmRuntimeInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
