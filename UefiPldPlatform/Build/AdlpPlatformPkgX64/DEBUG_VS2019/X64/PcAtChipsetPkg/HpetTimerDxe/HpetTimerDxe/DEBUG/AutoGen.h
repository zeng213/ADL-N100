/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_6CE6B0DE_781C_4f6c_B42D_98346C614BEC
#define _AUTOGENH_6CE6B0DE_781C_4f6c_B42D_98346C614BEC

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x6CE6B0DE, 0x781C, 0x4f6c, {0xB4, 0x2D, 0x98, 0x34, 0x6C, 0x61, 0x4B, 0xEC}}

// Guids
extern EFI_GUID gPcAtChipsetPkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gUefiSystemTableInfoGuid;
extern EFI_GUID gUefiSerialPortInfoGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gUefiPayloadPkgTokenSpaceGuid;
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
extern EFI_GUID gUefiAcpiBoardInfoGuid;
extern EFI_GUID gUefiCpuPkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiTimerArchProtocolGuid;
extern EFI_GUID gEfiCpuArchProtocolGuid;
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

#define _PCD_TOKEN_PcdHpetMsiEnable  238U
#define _PCD_SIZE_PcdHpetMsiEnable 1
#define _PCD_GET_MODE_SIZE_PcdHpetMsiEnable  _PCD_SIZE_PcdHpetMsiEnable 
#define _PCD_VALUE_PcdHpetMsiEnable  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdHpetMsiEnable;
#define _PCD_GET_MODE_BOOL_PcdHpetMsiEnable  _gPcd_FixedAtBuild_PcdHpetMsiEnable
//#define _PCD_SET_MODE_BOOL_PcdHpetMsiEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHpetBaseAddress  235U
#define _PCD_SIZE_PcdHpetBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdHpetBaseAddress  _PCD_SIZE_PcdHpetBaseAddress 
#define _PCD_VALUE_PcdHpetBaseAddress  0xFED00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdHpetBaseAddress;
#define _PCD_GET_MODE_32_PcdHpetBaseAddress  _gPcd_FixedAtBuild_PcdHpetBaseAddress
//#define _PCD_SET_MODE_32_PcdHpetBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHpetLocalApicVector  237U
#define _PCD_SIZE_PcdHpetLocalApicVector 1
#define _PCD_GET_MODE_SIZE_PcdHpetLocalApicVector  _PCD_SIZE_PcdHpetLocalApicVector 
#define _PCD_VALUE_PcdHpetLocalApicVector  0x40U
extern const  UINT8  _gPcd_FixedAtBuild_PcdHpetLocalApicVector;
#define _PCD_GET_MODE_8_PcdHpetLocalApicVector  _gPcd_FixedAtBuild_PcdHpetLocalApicVector
//#define _PCD_SET_MODE_8_PcdHpetLocalApicVector  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHpetDefaultTimerPeriod  236U
#define _PCD_SIZE_PcdHpetDefaultTimerPeriod 8
#define _PCD_GET_MODE_SIZE_PcdHpetDefaultTimerPeriod  _PCD_SIZE_PcdHpetDefaultTimerPeriod 
#define _PCD_VALUE_PcdHpetDefaultTimerPeriod  100000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdHpetDefaultTimerPeriod;
#define _PCD_GET_MODE_64_PcdHpetDefaultTimerPeriod  _gPcd_FixedAtBuild_PcdHpetDefaultTimerPeriod
//#define _PCD_SET_MODE_64_PcdHpetDefaultTimerPeriod  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
TimerDriverInitialize (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
