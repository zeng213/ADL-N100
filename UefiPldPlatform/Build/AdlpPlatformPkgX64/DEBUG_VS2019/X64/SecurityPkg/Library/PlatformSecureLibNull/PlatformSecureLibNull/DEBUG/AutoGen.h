/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_7FA68D82_10A4_4e71_9524_D3D9500D3CDF
#define _AUTOGENH_7FA68D82_10A4_4e71_9524_D3D9500D3CDF

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiSecurityPkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdUserPhysicalPresence  202U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdUserPhysicalPresence;
#define _PCD_GET_MODE_BOOL_PcdUserPhysicalPresence  _gPcd_FixedAtBuild_PcdUserPhysicalPresence
//#define _PCD_SET_MODE_BOOL_PcdUserPhysicalPresence  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdUserPhysicalPresence 0
#define _PCD_SIZE_PcdUserPhysicalPresence 1
#define _PCD_GET_MODE_SIZE_PcdUserPhysicalPresence _PCD_SIZE_PcdUserPhysicalPresence

RETURN_STATUS
EFIAPI
PlatformSecureLibNullConstructor (
  VOID
  );


#ifdef __cplusplus
}
#endif

#endif
