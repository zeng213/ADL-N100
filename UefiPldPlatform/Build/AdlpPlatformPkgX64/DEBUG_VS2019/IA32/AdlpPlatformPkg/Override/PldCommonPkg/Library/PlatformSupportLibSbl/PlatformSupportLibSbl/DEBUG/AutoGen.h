/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A07C1C7A_D693_4ED3_A443_1B1011835804
#define _AUTOGENH_A07C1C7A_D693_4ED3_A443_1B1011835804

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gLoaderFspInfoGuid;
extern GUID gSmmInformationGuid;
extern GUID gTpmEventLogInfoGuid;
extern GUID gSpiFlashVariableInfoGuid;
extern GUID gLoaderPlatformInfoGuid;
extern GUID gUefiAcpiBoardInfoGuid;
extern GUID gDeviceTableHobGuid;
extern GUID gFlashMapInfoGuid;
extern GUID gLoaderPerformanceInfoGuid;
extern GUID gEfiSecurityPkgTokenSpaceGuid;
extern GUID gEfiTpmDeviceInstanceNoneGuid;
extern GUID gEfiTpmDeviceInstanceTpm20DtpmGuid;
extern GUID gTpmDeviceInstanceTpm20PttPtpGuid;
extern GUID gLoaderPciRootBridgeInfoGuid;
extern GUID gSecureBootInfoGuid;
extern GUID gUefiPayloadPkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdPayloadStackTop  90U
extern const UINT32 _gPcd_FixedAtBuild_PcdPayloadStackTop;
#define _PCD_GET_MODE_32_PcdPayloadStackTop  _gPcd_FixedAtBuild_PcdPayloadStackTop
//#define _PCD_SET_MODE_32_PcdPayloadStackTop  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdPayloadStackTop 0x90000
#define _PCD_SIZE_PcdPayloadStackTop 4
#define _PCD_GET_MODE_SIZE_PcdPayloadStackTop _PCD_SIZE_PcdPayloadStackTop
#define _PCD_TOKEN_PcdTpmInstanceGuid  25U
#define _PCD_GET_MODE_PTR_PcdTpmInstanceGuid  LibPcdGetPtr(_PCD_TOKEN_PcdTpmInstanceGuid)
#define _PCD_GET_MODE_SIZE_PcdTpmInstanceGuid  LibPcdGetSize(_PCD_TOKEN_PcdTpmInstanceGuid)
#define _PCD_SET_MODE_PTR_PcdTpmInstanceGuid(SizeOfBuffer, Buffer)  LibPcdSetPtr(_PCD_TOKEN_PcdTpmInstanceGuid, (SizeOfBuffer), (Buffer))
#define _PCD_SET_MODE_PTR_S_PcdTpmInstanceGuid(SizeOfBuffer, Buffer)  LibPcdSetPtrS(_PCD_TOKEN_PcdTpmInstanceGuid, (SizeOfBuffer), (Buffer))


#ifdef __cplusplus
}
#endif

#endif
