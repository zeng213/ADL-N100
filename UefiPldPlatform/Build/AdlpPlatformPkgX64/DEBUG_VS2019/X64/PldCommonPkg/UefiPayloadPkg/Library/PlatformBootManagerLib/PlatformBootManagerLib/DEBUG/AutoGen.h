/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_F0D9063A_DADB_4185_85E2_D7ACDA93F7A6
#define _AUTOGENH_F0D9063A_DADB_4185_85E2_D7ACDA93F7A6

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern EFI_GUID gEfiEndOfDxeEventGroupGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gUefiPayloadPkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiGenericMemTestProtocolGuid;
extern EFI_GUID gEfiGraphicsOutputProtocolGuid;
extern EFI_GUID gEfiUgaDrawProtocolGuid;
extern EFI_GUID gEfiBootLogoProtocolGuid;
extern EFI_GUID gEfiDxeSmmReadyToLockProtocolGuid;
extern EFI_GUID gEfiSmmAccess2ProtocolGuid;
extern EFI_GUID gEfiPciRootBridgeIoProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdPlatformBootTimeOut  19U
#define _PCD_GET_MODE_16_PcdPlatformBootTimeOut  LibPcdGet16(_PCD_TOKEN_PcdPlatformBootTimeOut)
#define _PCD_GET_MODE_SIZE_PcdPlatformBootTimeOut  LibPcdGetSize(_PCD_TOKEN_PcdPlatformBootTimeOut)
#define _PCD_SET_MODE_16_PcdPlatformBootTimeOut(Value)  LibPcdSet16(_PCD_TOKEN_PcdPlatformBootTimeOut, (Value))
#define _PCD_SET_MODE_16_S_PcdPlatformBootTimeOut(Value)  LibPcdSet16S(_PCD_TOKEN_PcdPlatformBootTimeOut, (Value))
#define _PCD_TOKEN_PcdUgaConsumeSupport  187U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdUgaConsumeSupport;
#define _PCD_GET_MODE_BOOL_PcdUgaConsumeSupport  _gPcd_FixedAtBuild_PcdUgaConsumeSupport
//#define _PCD_SET_MODE_BOOL_PcdUgaConsumeSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdConOutRow  3U
#define _PCD_GET_MODE_32_PcdConOutRow  LibPcdGet32(_PCD_TOKEN_PcdConOutRow)
#define _PCD_GET_MODE_SIZE_PcdConOutRow  LibPcdGetSize(_PCD_TOKEN_PcdConOutRow)
#define _PCD_SET_MODE_32_PcdConOutRow(Value)  LibPcdSet32(_PCD_TOKEN_PcdConOutRow, (Value))
#define _PCD_SET_MODE_32_S_PcdConOutRow(Value)  LibPcdSet32S(_PCD_TOKEN_PcdConOutRow, (Value))
#define _PCD_TOKEN_PcdConOutColumn  2U
#define _PCD_GET_MODE_32_PcdConOutColumn  LibPcdGet32(_PCD_TOKEN_PcdConOutColumn)
#define _PCD_GET_MODE_SIZE_PcdConOutColumn  LibPcdGetSize(_PCD_TOKEN_PcdConOutColumn)
#define _PCD_SET_MODE_32_PcdConOutColumn(Value)  LibPcdSet32(_PCD_TOKEN_PcdConOutColumn, (Value))
#define _PCD_SET_MODE_32_S_PcdConOutColumn(Value)  LibPcdSet32S(_PCD_TOKEN_PcdConOutColumn, (Value))
#define _PCD_TOKEN_PcdConInConnectOnDemand  60U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdConInConnectOnDemand;
#define _PCD_GET_MODE_BOOL_PcdConInConnectOnDemand  _gPcd_FixedAtBuild_PcdConInConnectOnDemand
//#define _PCD_SET_MODE_BOOL_PcdConInConnectOnDemand  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdConInConnectOnDemand 0
#define _PCD_SIZE_PcdConInConnectOnDemand 1
#define _PCD_GET_MODE_SIZE_PcdConInConnectOnDemand _PCD_SIZE_PcdConInConnectOnDemand
#define _PCD_TOKEN_PcdShellFile  287U
extern const UINT8 _gPcd_FixedAtBuild_PcdShellFile[];
#define _PCD_GET_MODE_PTR_PcdShellFile  (VOID *)_gPcd_FixedAtBuild_PcdShellFile
//#define _PCD_SET_MODE_PTR_PcdShellFile  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdShellFile (VOID *)_gPcd_FixedAtBuild_PcdShellFile
#define _PCD_SIZE_PcdShellFile 16
#define _PCD_GET_MODE_SIZE_PcdShellFile _PCD_SIZE_PcdShellFile
#define _PCD_TOKEN_PcdUartDefaultBaudRate  175U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdUartDefaultBaudRate;
#define _PCD_GET_MODE_64_PcdUartDefaultBaudRate  _gPcd_BinaryPatch_PcdUartDefaultBaudRate
#define _PCD_SET_MODE_64_PcdUartDefaultBaudRate(Value)  (_gPcd_BinaryPatch_PcdUartDefaultBaudRate = (Value))
#define _PCD_SET_MODE_64_S_PcdUartDefaultBaudRate(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultBaudRate = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdUartDefaultBaudRate_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdUartDefaultBaudRate _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate; 
#define _PCD_TOKEN_PcdUartDefaultDataBits  176U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdUartDefaultDataBits;
#define _PCD_GET_MODE_8_PcdUartDefaultDataBits  _gPcd_BinaryPatch_PcdUartDefaultDataBits
#define _PCD_SET_MODE_8_PcdUartDefaultDataBits(Value)  (_gPcd_BinaryPatch_PcdUartDefaultDataBits = (Value))
#define _PCD_SET_MODE_8_S_PcdUartDefaultDataBits(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultDataBits = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdUartDefaultDataBits_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdUartDefaultDataBits _gPcd_BinaryPatch_Size_PcdUartDefaultDataBits
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultDataBits; 
#define _PCD_TOKEN_PcdUartDefaultParity  177U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdUartDefaultParity;
#define _PCD_GET_MODE_8_PcdUartDefaultParity  _gPcd_BinaryPatch_PcdUartDefaultParity
#define _PCD_SET_MODE_8_PcdUartDefaultParity(Value)  (_gPcd_BinaryPatch_PcdUartDefaultParity = (Value))
#define _PCD_SET_MODE_8_S_PcdUartDefaultParity(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultParity = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdUartDefaultParity_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdUartDefaultParity _gPcd_BinaryPatch_Size_PcdUartDefaultParity
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultParity; 
#define _PCD_TOKEN_PcdUartDefaultStopBits  179U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdUartDefaultStopBits;
#define _PCD_GET_MODE_8_PcdUartDefaultStopBits  _gPcd_BinaryPatch_PcdUartDefaultStopBits
#define _PCD_SET_MODE_8_PcdUartDefaultStopBits(Value)  (_gPcd_BinaryPatch_PcdUartDefaultStopBits = (Value))
#define _PCD_SET_MODE_8_S_PcdUartDefaultStopBits(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultStopBits = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdUartDefaultStopBits_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdUartDefaultStopBits _gPcd_BinaryPatch_Size_PcdUartDefaultStopBits
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultStopBits; 


#ifdef __cplusplus
}
#endif

#endif
