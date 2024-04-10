/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_EF5676C2_86C2_49ac_B517_7092CDDB5A93
#define _AUTOGENH_EF5676C2_86C2_49ac_B517_7092CDDB5A93

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
#define _PCD_TOKEN_PcdCryptoShaOptMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCryptoShaOptMask;
#define _PCD_GET_MODE_32_PcdCryptoShaOptMask  _gPcd_FixedAtBuild_PcdCryptoShaOptMask
//#define _PCD_SET_MODE_32_PcdCryptoShaOptMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCryptoShaOptMask 0x00000006
#define _PCD_SIZE_PcdCryptoShaOptMask 4
#define _PCD_GET_MODE_SIZE_PcdCryptoShaOptMask _PCD_SIZE_PcdCryptoShaOptMask
#define _PCD_TOKEN_PcdIppHashLibSupportedMask  0U
extern const UINT16 _gPcd_FixedAtBuild_PcdIppHashLibSupportedMask;
#define _PCD_GET_MODE_16_PcdIppHashLibSupportedMask  _gPcd_FixedAtBuild_PcdIppHashLibSupportedMask
//#define _PCD_SET_MODE_16_PcdIppHashLibSupportedMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdIppHashLibSupportedMask 0x00000006
#define _PCD_SIZE_PcdIppHashLibSupportedMask 2
#define _PCD_GET_MODE_SIZE_PcdIppHashLibSupportedMask _PCD_SIZE_PcdIppHashLibSupportedMask
#define _PCD_TOKEN_PcdCompSignSchemeSupportedMask  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdCompSignSchemeSupportedMask;
#define _PCD_GET_MODE_8_PcdCompSignSchemeSupportedMask  _gPcd_FixedAtBuild_PcdCompSignSchemeSupportedMask
//#define _PCD_SET_MODE_8_PcdCompSignSchemeSupportedMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCompSignSchemeSupportedMask 0x03
#define _PCD_SIZE_PcdCompSignSchemeSupportedMask 1
#define _PCD_GET_MODE_SIZE_PcdCompSignSchemeSupportedMask _PCD_SIZE_PcdCompSignSchemeSupportedMask


#ifdef __cplusplus
}
#endif

#endif
