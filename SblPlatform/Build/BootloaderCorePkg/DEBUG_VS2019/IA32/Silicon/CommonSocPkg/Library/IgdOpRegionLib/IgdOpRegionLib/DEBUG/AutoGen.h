/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_98796601_6f1f_492e_8f53_546eebed43bc
#define _AUTOGENH_98796601_6f1f_492e_8f53_546eebed43bc

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPlatformModuleTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdGraphicsVbtAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdGraphicsVbtAddress;
#define _PCD_GET_MODE_32_PcdGraphicsVbtAddress  _gPcd_BinaryPatch_PcdGraphicsVbtAddress
#define _PCD_SET_MODE_32_PcdGraphicsVbtAddress(Value)  (_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdGraphicsVbtAddress(Value)  ((_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdGraphicsVbtAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdGraphicsVbtAddress _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress; 
#define _PCD_TOKEN_PcdIgdOpRegionAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdIgdOpRegionAddress;
#define _PCD_GET_MODE_32_PcdIgdOpRegionAddress  _gPcd_BinaryPatch_PcdIgdOpRegionAddress
#define _PCD_SET_MODE_32_PcdIgdOpRegionAddress(Value)  (_gPcd_BinaryPatch_PcdIgdOpRegionAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdIgdOpRegionAddress(Value)  ((_gPcd_BinaryPatch_PcdIgdOpRegionAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdIgdOpRegionAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdIgdOpRegionAddress _gPcd_BinaryPatch_Size_PcdIgdOpRegionAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdIgdOpRegionAddress; 


#ifdef __cplusplus
}
#endif

#endif
