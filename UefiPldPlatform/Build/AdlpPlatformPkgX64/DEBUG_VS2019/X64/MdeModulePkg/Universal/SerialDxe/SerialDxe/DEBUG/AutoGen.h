/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_9A5163E7_5C29_453F_825C_837A46A81E15
#define _AUTOGENH_9A5163E7_5C29_453F_825C_837A46A81E15

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x9A5163E7, 0x5C29, 0x453F, {0x82, 0x5C, 0x83, 0x7A, 0x46, 0xA8, 0x1E, 0x15}}

// Guids
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
extern EFI_GUID gEfiSerialIoProtocolGuid;
extern EFI_GUID gEfiDevicePathProtocolGuid;
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
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdUartDefaultBaudRate  175U
#define _PCD_PATCHABLE_VALUE_PcdUartDefaultBaudRate  ((UINT64)0ULL)
extern volatile   UINT64  _gPcd_BinaryPatch_PcdUartDefaultBaudRate;
#define _PCD_GET_MODE_64_PcdUartDefaultBaudRate  _gPcd_BinaryPatch_PcdUartDefaultBaudRate
#define _PCD_PATCHABLE_PcdUartDefaultBaudRate_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdUartDefaultBaudRate  _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate 
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate; 
#define _PCD_SET_MODE_64_PcdUartDefaultBaudRate(Value)  (_gPcd_BinaryPatch_PcdUartDefaultBaudRate = (Value))
#define _PCD_SET_MODE_64_S_PcdUartDefaultBaudRate(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultBaudRate = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdUartDefaultDataBits  176U
#define _PCD_PATCHABLE_VALUE_PcdUartDefaultDataBits  ((UINT8)8U)
extern volatile   UINT8  _gPcd_BinaryPatch_PcdUartDefaultDataBits;
#define _PCD_GET_MODE_8_PcdUartDefaultDataBits  _gPcd_BinaryPatch_PcdUartDefaultDataBits
#define _PCD_PATCHABLE_PcdUartDefaultDataBits_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdUartDefaultDataBits  _gPcd_BinaryPatch_Size_PcdUartDefaultDataBits 
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultDataBits; 
#define _PCD_SET_MODE_8_PcdUartDefaultDataBits(Value)  (_gPcd_BinaryPatch_PcdUartDefaultDataBits = (Value))
#define _PCD_SET_MODE_8_S_PcdUartDefaultDataBits(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultDataBits = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdUartDefaultParity  177U
#define _PCD_PATCHABLE_VALUE_PcdUartDefaultParity  ((UINT8)1U)
extern volatile   UINT8  _gPcd_BinaryPatch_PcdUartDefaultParity;
#define _PCD_GET_MODE_8_PcdUartDefaultParity  _gPcd_BinaryPatch_PcdUartDefaultParity
#define _PCD_PATCHABLE_PcdUartDefaultParity_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdUartDefaultParity  _gPcd_BinaryPatch_Size_PcdUartDefaultParity 
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultParity; 
#define _PCD_SET_MODE_8_PcdUartDefaultParity(Value)  (_gPcd_BinaryPatch_PcdUartDefaultParity = (Value))
#define _PCD_SET_MODE_8_S_PcdUartDefaultParity(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultParity = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdUartDefaultStopBits  179U
#define _PCD_PATCHABLE_VALUE_PcdUartDefaultStopBits  ((UINT8)1U)
extern volatile   UINT8  _gPcd_BinaryPatch_PcdUartDefaultStopBits;
#define _PCD_GET_MODE_8_PcdUartDefaultStopBits  _gPcd_BinaryPatch_PcdUartDefaultStopBits
#define _PCD_PATCHABLE_PcdUartDefaultStopBits_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdUartDefaultStopBits  _gPcd_BinaryPatch_Size_PcdUartDefaultStopBits 
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultStopBits; 
#define _PCD_SET_MODE_8_PcdUartDefaultStopBits(Value)  (_gPcd_BinaryPatch_PcdUartDefaultStopBits = (Value))
#define _PCD_SET_MODE_8_S_PcdUartDefaultStopBits(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultStopBits = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdUartDefaultReceiveFifoDepth  178U
#define _PCD_SIZE_PcdUartDefaultReceiveFifoDepth 2
#define _PCD_GET_MODE_SIZE_PcdUartDefaultReceiveFifoDepth  _PCD_SIZE_PcdUartDefaultReceiveFifoDepth 
#define _PCD_VALUE_PcdUartDefaultReceiveFifoDepth  1U
extern const  UINT16  _gPcd_FixedAtBuild_PcdUartDefaultReceiveFifoDepth;
#define _PCD_GET_MODE_16_PcdUartDefaultReceiveFifoDepth  _gPcd_FixedAtBuild_PcdUartDefaultReceiveFifoDepth
//#define _PCD_SET_MODE_16_PcdUartDefaultReceiveFifoDepth  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
SerialDxeInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
