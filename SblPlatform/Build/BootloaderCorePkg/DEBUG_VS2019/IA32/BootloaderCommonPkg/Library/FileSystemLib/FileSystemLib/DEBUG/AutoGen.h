/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_8949AC97_8541_44BA_BD27_8EF5F259EC93
#define _AUTOGENH_8949AC97_8541_44BA_BD27_8EF5F259EC93

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdSupportedFileSystemMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdSupportedFileSystemMask;
#define _PCD_GET_MODE_32_PcdSupportedFileSystemMask  _gPcd_FixedAtBuild_PcdSupportedFileSystemMask
//#define _PCD_SET_MODE_32_PcdSupportedFileSystemMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSupportedFileSystemMask 0x00000003
#define _PCD_SIZE_PcdSupportedFileSystemMask 4
#define _PCD_GET_MODE_SIZE_PcdSupportedFileSystemMask _PCD_SIZE_PcdSupportedFileSystemMask


#ifdef __cplusplus
}
#endif

#endif
