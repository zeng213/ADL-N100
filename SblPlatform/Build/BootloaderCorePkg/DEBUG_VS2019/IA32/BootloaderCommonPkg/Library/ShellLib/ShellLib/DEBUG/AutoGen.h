/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_C0297BE1_944B_4134_AC79_AA928F74AE31
#define _AUTOGENH_C0297BE1_944B_4134_AC79_AA928F74AE31

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gLoaderPerformanceInfoGuid;
extern GUID gLoaderMemoryMapInfoGuid;
extern GUID gOsBootOptionGuid;
extern GUID gLoaderFspInfoGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdMiniShellEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdMiniShellEnabled;
#define _PCD_GET_MODE_BOOL_PcdMiniShellEnabled  _gPcd_FixedAtBuild_PcdMiniShellEnabled
//#define _PCD_SET_MODE_BOOL_PcdMiniShellEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdConsoleInDeviceMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdConsoleInDeviceMask;
#define _PCD_GET_MODE_32_PcdConsoleInDeviceMask  _gPcd_FixedAtBuild_PcdConsoleInDeviceMask
//#define _PCD_SET_MODE_32_PcdConsoleInDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdConsoleInDeviceMask 0x1
#define _PCD_SIZE_PcdConsoleInDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdConsoleInDeviceMask _PCD_SIZE_PcdConsoleInDeviceMask
#define _PCD_TOKEN_PcdBootPerformanceMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdBootPerformanceMask;
#define _PCD_GET_MODE_32_PcdBootPerformanceMask  _gPcd_FixedAtBuild_PcdBootPerformanceMask
//#define _PCD_SET_MODE_32_PcdBootPerformanceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdBootPerformanceMask 0x1
#define _PCD_SIZE_PcdBootPerformanceMask 4
#define _PCD_GET_MODE_SIZE_PcdBootPerformanceMask _PCD_SIZE_PcdBootPerformanceMask


#ifdef __cplusplus
}
#endif

#endif
