/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_952474C3_8CFC_428c_9D5F_118319E7C879
#define _AUTOGENH_952474C3_8CFC_428c_9D5F_118319E7C879

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEsrtSystemFirmwareGuid;
extern GUID gCsmeFWUDriverImageFileGuid;
extern GUID gPlatformModuleTokenSpaceGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdAcpiTablesRsdp  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdAcpiTablesRsdp;
#define _PCD_GET_MODE_32_PcdAcpiTablesRsdp  _gPcd_BinaryPatch_PcdAcpiTablesRsdp
#define _PCD_SET_MODE_32_PcdAcpiTablesRsdp(Value)  (_gPcd_BinaryPatch_PcdAcpiTablesRsdp = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiTablesRsdp(Value)  ((_gPcd_BinaryPatch_PcdAcpiTablesRsdp = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdAcpiTablesRsdp_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiTablesRsdp _gPcd_BinaryPatch_Size_PcdAcpiTablesRsdp
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiTablesRsdp; 
#define _PCD_TOKEN_PcdAcpiTablesMaxEntry  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdAcpiTablesMaxEntry;
#define _PCD_GET_MODE_32_PcdAcpiTablesMaxEntry  _gPcd_FixedAtBuild_PcdAcpiTablesMaxEntry
//#define _PCD_SET_MODE_32_PcdAcpiTablesMaxEntry  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdAcpiTablesMaxEntry 40
#define _PCD_SIZE_PcdAcpiTablesMaxEntry 4
#define _PCD_GET_MODE_SIZE_PcdAcpiTablesMaxEntry _PCD_SIZE_PcdAcpiTablesMaxEntry
#define _PCD_TOKEN_PcdAcpiTablesAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdAcpiTablesAddress;
#define _PCD_GET_MODE_32_PcdAcpiTablesAddress  _gPcd_BinaryPatch_PcdAcpiTablesAddress
#define _PCD_SET_MODE_32_PcdAcpiTablesAddress(Value)  (_gPcd_BinaryPatch_PcdAcpiTablesAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiTablesAddress(Value)  ((_gPcd_BinaryPatch_PcdAcpiTablesAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdAcpiTablesAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiTablesAddress _gPcd_BinaryPatch_Size_PcdAcpiTablesAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiTablesAddress; 
#define _PCD_TOKEN_PcdAcpiGnvsAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdAcpiGnvsAddress;
#define _PCD_GET_MODE_32_PcdAcpiGnvsAddress  _gPcd_BinaryPatch_PcdAcpiGnvsAddress
#define _PCD_SET_MODE_32_PcdAcpiGnvsAddress(Value)  (_gPcd_BinaryPatch_PcdAcpiGnvsAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiGnvsAddress(Value)  ((_gPcd_BinaryPatch_PcdAcpiGnvsAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdAcpiGnvsAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiGnvsAddress _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress; 
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdS3DebugEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdS3DebugEnabled;
#define _PCD_GET_MODE_BOOL_PcdS3DebugEnabled  _gPcd_FixedAtBuild_PcdS3DebugEnabled
//#define _PCD_SET_MODE_BOOL_PcdS3DebugEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdLoaderAcpiReclaimSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdLoaderAcpiReclaimSize;
#define _PCD_GET_MODE_32_PcdLoaderAcpiReclaimSize  _gPcd_FixedAtBuild_PcdLoaderAcpiReclaimSize
//#define _PCD_SET_MODE_32_PcdLoaderAcpiReclaimSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdLoaderAcpiReclaimSize 0x00090000
#define _PCD_SIZE_PcdLoaderAcpiReclaimSize 4
#define _PCD_GET_MODE_SIZE_PcdLoaderAcpiReclaimSize _PCD_SIZE_PcdLoaderAcpiReclaimSize
#define _PCD_TOKEN_PcdLowestSupportedFwVer  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdLowestSupportedFwVer;
#define _PCD_GET_MODE_32_PcdLowestSupportedFwVer  _gPcd_FixedAtBuild_PcdLowestSupportedFwVer
//#define _PCD_SET_MODE_32_PcdLowestSupportedFwVer  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdLowestSupportedFwVer 0x1
#define _PCD_SIZE_PcdLowestSupportedFwVer 4
#define _PCD_GET_MODE_SIZE_PcdLowestSupportedFwVer _PCD_SIZE_PcdLowestSupportedFwVer
#define _PCD_TOKEN_PcdLegacyEfSegmentEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdLegacyEfSegmentEnabled;
#define _PCD_GET_MODE_BOOL_PcdLegacyEfSegmentEnabled  _gPcd_FixedAtBuild_PcdLegacyEfSegmentEnabled
//#define _PCD_SET_MODE_BOOL_PcdLegacyEfSegmentEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdSplashLogoAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSplashLogoAddress;
#define _PCD_GET_MODE_32_PcdSplashLogoAddress  _gPcd_BinaryPatch_PcdSplashLogoAddress
#define _PCD_SET_MODE_32_PcdSplashLogoAddress(Value)  (_gPcd_BinaryPatch_PcdSplashLogoAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdSplashLogoAddress(Value)  ((_gPcd_BinaryPatch_PcdSplashLogoAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSplashLogoAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSplashLogoAddress _gPcd_BinaryPatch_Size_PcdSplashLogoAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdSplashLogoAddress; 
#define _PCD_TOKEN_PcdSplashEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdSplashEnabled;
#define _PCD_GET_MODE_BOOL_PcdSplashEnabled  _gPcd_FixedAtBuild_PcdSplashEnabled
//#define _PCD_SET_MODE_BOOL_PcdSplashEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdCpuX2ApicEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdCpuX2ApicEnabled;
#define _PCD_GET_MODE_BOOL_PcdCpuX2ApicEnabled  _gPcd_FixedAtBuild_PcdCpuX2ApicEnabled
//#define _PCD_SET_MODE_BOOL_PcdCpuX2ApicEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdAcpiTableTemplatePtr  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdAcpiTableTemplatePtr;
#define _PCD_GET_MODE_32_PcdAcpiTableTemplatePtr  _gPcd_BinaryPatch_PcdAcpiTableTemplatePtr
#define _PCD_SET_MODE_32_PcdAcpiTableTemplatePtr(Value)  (_gPcd_BinaryPatch_PcdAcpiTableTemplatePtr = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiTableTemplatePtr(Value)  ((_gPcd_BinaryPatch_PcdAcpiTableTemplatePtr = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdAcpiTableTemplatePtr_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiTableTemplatePtr _gPcd_BinaryPatch_Size_PcdAcpiTableTemplatePtr
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiTableTemplatePtr; 
#define _PCD_TOKEN_PcdAcpiProcessorIdBase  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdAcpiProcessorIdBase;
#define _PCD_GET_MODE_32_PcdAcpiProcessorIdBase  _gPcd_FixedAtBuild_PcdAcpiProcessorIdBase
//#define _PCD_SET_MODE_32_PcdAcpiProcessorIdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdAcpiProcessorIdBase 0x1
#define _PCD_SIZE_PcdAcpiProcessorIdBase 4
#define _PCD_GET_MODE_SIZE_PcdAcpiProcessorIdBase _PCD_SIZE_PcdAcpiProcessorIdBase


#ifdef __cplusplus
}
#endif

#endif
