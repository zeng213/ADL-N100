/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_CFD586F9_B7B6_4384_B472_0EC5CD916B7C
#define _AUTOGENH_CFD586F9_B7B6_4384_B472_0EC5CD916B7C

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiGraphicsDeviceInfoHobGuid;
extern GUID gEfiGraphicsInfoHobGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformModuleTokenSpaceGuid;
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
#define _PCD_TOKEN_PcdOsBootOptionNumber  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdOsBootOptionNumber;
#define _PCD_GET_MODE_32_PcdOsBootOptionNumber  _gPcd_FixedAtBuild_PcdOsBootOptionNumber
//#define _PCD_SET_MODE_32_PcdOsBootOptionNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdOsBootOptionNumber 0x00000008
#define _PCD_SIZE_PcdOsBootOptionNumber 4
#define _PCD_GET_MODE_SIZE_PcdOsBootOptionNumber _PCD_SIZE_PcdOsBootOptionNumber
#define _PCD_TOKEN_PcdCfgDataLoadSource  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCfgDataLoadSource;
#define _PCD_GET_MODE_32_PcdCfgDataLoadSource  _gPcd_FixedAtBuild_PcdCfgDataLoadSource
//#define _PCD_SET_MODE_32_PcdCfgDataLoadSource  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCfgDataLoadSource 0x1
#define _PCD_SIZE_PcdCfgDataLoadSource 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataLoadSource _PCD_SIZE_PcdCfgDataLoadSource
#define _PCD_TOKEN_PcdCfgDatabaseSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCfgDatabaseSize;
#define _PCD_GET_MODE_32_PcdCfgDatabaseSize  _gPcd_FixedAtBuild_PcdCfgDatabaseSize
//#define _PCD_SET_MODE_32_PcdCfgDatabaseSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCfgDatabaseSize 0x00004000
#define _PCD_SIZE_PcdCfgDatabaseSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDatabaseSize _PCD_SIZE_PcdCfgDatabaseSize
#define _PCD_TOKEN_PcdVerifiedBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVerifiedBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootEnabled  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdGraphicsVbtAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdGraphicsVbtAddress;
#define _PCD_GET_MODE_32_PcdGraphicsVbtAddress  _gPcd_BinaryPatch_PcdGraphicsVbtAddress
#define _PCD_SET_MODE_32_PcdGraphicsVbtAddress(Value)  (_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdGraphicsVbtAddress(Value)  ((_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdGraphicsVbtAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdGraphicsVbtAddress _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress; 


#ifdef __cplusplus
}
#endif

#endif
