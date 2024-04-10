/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_EBF144C8_70F5_4e09_ADE2_F41F5C59AFDA
#define _AUTOGENH_EBF144C8_70F5_4e09_ADE2_F41F5C59AFDA

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern EFI_GUID gEfiStatusCodeSpecificDataGuid;
extern EFI_GUID gEfiStatusCodeDataTypeDebugGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiStatusCodeRuntimeProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdReportStatusCodePropertyMask  172U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdReportStatusCodePropertyMask;
#define _PCD_GET_MODE_8_PcdReportStatusCodePropertyMask  _gPcd_BinaryPatch_PcdReportStatusCodePropertyMask
#define _PCD_SET_MODE_8_PcdReportStatusCodePropertyMask(Value)  (_gPcd_BinaryPatch_PcdReportStatusCodePropertyMask = (Value))
#define _PCD_SET_MODE_8_S_PcdReportStatusCodePropertyMask(Value)  ((_gPcd_BinaryPatch_PcdReportStatusCodePropertyMask = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdReportStatusCodePropertyMask_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdReportStatusCodePropertyMask _gPcd_BinaryPatch_Size_PcdReportStatusCodePropertyMask
extern UINTN _gPcd_BinaryPatch_Size_PcdReportStatusCodePropertyMask; 


#ifdef __cplusplus
}
#endif

#endif
