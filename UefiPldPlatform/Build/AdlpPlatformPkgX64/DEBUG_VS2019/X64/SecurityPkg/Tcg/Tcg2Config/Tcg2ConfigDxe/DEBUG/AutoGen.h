/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_4D9CBEF0_15A0_4D0C_83DB_5213E710C23F
#define _AUTOGENH_4D9CBEF0_15A0_4D0C_83DB_5213E710C23F

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x4D9CBEF0, 0x15A0, 0x4D0C, {0x83, 0xDB, 0x52, 0x13, 0xE7, 0x10, 0xC2, 0x3F}}

// Guids
extern EFI_GUID gTcg2ConfigFormSetGuid;
extern EFI_GUID gEfiSecurityPkgTokenSpaceGuid;
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
extern EFI_GUID gEdkiiIfrBitVarstoreGuid;
extern EFI_GUID gUefiAcpiBoardInfoGuid;
extern EFI_GUID gEfiTcg2PhysicalPresenceGuid;

// Protocols
extern EFI_GUID gEfiHiiConfigAccessProtocolGuid;
extern EFI_GUID gEfiDevicePathProtocolGuid;
extern EFI_GUID gEdkiiVariableLockProtocolGuid;
extern EFI_GUID gEfiTcg2ProtocolGuid;
extern EFI_GUID gPcdProtocolGuid;
extern EFI_GUID gEfiPcdProtocolGuid;
extern EFI_GUID gGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiGetPcdInfoProtocolGuid;
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

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdTpmInstanceGuid  25U
#define _PCD_GET_MODE_PTR_PcdTpmInstanceGuid  LibPcdGetPtr(_PCD_TOKEN_PcdTpmInstanceGuid)
#define _PCD_GET_MODE_SIZE_PcdTpmInstanceGuid  LibPcdGetSize(_PCD_TOKEN_PcdTpmInstanceGuid)
#define _PCD_SET_MODE_PTR_PcdTpmInstanceGuid(SizeOfBuffer, Buffer)  LibPcdSetPtr(_PCD_TOKEN_PcdTpmInstanceGuid, (SizeOfBuffer), (Buffer))
#define _PCD_SET_MODE_PTR_S_PcdTpmInstanceGuid(SizeOfBuffer, Buffer)  LibPcdSetPtrS(_PCD_TOKEN_PcdTpmInstanceGuid, (SizeOfBuffer), (Buffer))

#define _PCD_TOKEN_PcdTcg2HashAlgorithmBitmap  23U
#define _PCD_GET_MODE_32_PcdTcg2HashAlgorithmBitmap  LibPcdGet32(_PCD_TOKEN_PcdTcg2HashAlgorithmBitmap)
#define _PCD_GET_MODE_SIZE_PcdTcg2HashAlgorithmBitmap  LibPcdGetSize(_PCD_TOKEN_PcdTcg2HashAlgorithmBitmap)
#define _PCD_SET_MODE_32_PcdTcg2HashAlgorithmBitmap(Value)  LibPcdSet32(_PCD_TOKEN_PcdTcg2HashAlgorithmBitmap, (Value))
#define _PCD_SET_MODE_32_S_PcdTcg2HashAlgorithmBitmap(Value)  LibPcdSet32S(_PCD_TOKEN_PcdTcg2HashAlgorithmBitmap, (Value))

#define _PCD_TOKEN_PcdTpmBaseAddress  200U
#define _PCD_SIZE_PcdTpmBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdTpmBaseAddress  _PCD_SIZE_PcdTpmBaseAddress 
#define _PCD_VALUE_PcdTpmBaseAddress  0xFED40000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdTpmBaseAddress;
#define _PCD_GET_MODE_64_PcdTpmBaseAddress  _gPcd_FixedAtBuild_PcdTpmBaseAddress
//#define _PCD_SET_MODE_64_PcdTpmBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTcgPhysicalPresenceInterfaceVer  198U
#define _PCD_VALUE_PcdTcgPhysicalPresenceInterfaceVer  _gPcd_FixedAtBuild_PcdTcgPhysicalPresenceInterfaceVer
extern const UINT8 _gPcd_FixedAtBuild_PcdTcgPhysicalPresenceInterfaceVer[4];
#define _PCD_GET_MODE_PTR_PcdTcgPhysicalPresenceInterfaceVer  _gPcd_FixedAtBuild_PcdTcgPhysicalPresenceInterfaceVer
#define _PCD_SIZE_PcdTcgPhysicalPresenceInterfaceVer 4
#define _PCD_GET_MODE_SIZE_PcdTcgPhysicalPresenceInterfaceVer  _PCD_SIZE_PcdTcgPhysicalPresenceInterfaceVer 
//#define _PCD_SET_MODE_PTR_PcdTcgPhysicalPresenceInterfaceVer  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTpm2AcpiTableRev  199U
#define _PCD_SIZE_PcdTpm2AcpiTableRev 1
#define _PCD_GET_MODE_SIZE_PcdTpm2AcpiTableRev  _PCD_SIZE_PcdTpm2AcpiTableRev 
#define _PCD_VALUE_PcdTpm2AcpiTableRev  3U
extern const  UINT8  _gPcd_FixedAtBuild_PcdTpm2AcpiTableRev;
#define _PCD_GET_MODE_8_PcdTpm2AcpiTableRev  _gPcd_FixedAtBuild_PcdTpm2AcpiTableRev
//#define _PCD_SET_MODE_8_PcdTpm2AcpiTableRev  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdActiveTpmInterfaceType  20U
#define _PCD_GET_MODE_8_PcdActiveTpmInterfaceType  LibPcdGet8(_PCD_TOKEN_PcdActiveTpmInterfaceType)
#define _PCD_GET_MODE_SIZE_PcdActiveTpmInterfaceType  LibPcdGetSize(_PCD_TOKEN_PcdActiveTpmInterfaceType)
#define _PCD_SET_MODE_8_PcdActiveTpmInterfaceType(Value)  LibPcdSet8(_PCD_TOKEN_PcdActiveTpmInterfaceType, (Value))
#define _PCD_SET_MODE_8_S_PcdActiveTpmInterfaceType(Value)  LibPcdSet8S(_PCD_TOKEN_PcdActiveTpmInterfaceType, (Value))

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
Tcg2ConfigDriverEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );



EFI_STATUS
EFIAPI
Tcg2ConfigDriverUnload (
  IN EFI_HANDLE        ImageHandle
  );

#include "Tcg2ConfigDxeStrDefs.h"


#ifdef __cplusplus
}
#endif

#endif
