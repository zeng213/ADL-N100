/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_FC3DC10D_D271_422a_AFF3_CBCF70344431
#define _AUTOGENH_FC3DC10D_D271_422a_AFF3_CBCF70344431

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern EFI_GUID gUefiCpuPkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdCpuMaxLogicalProcessorNumber  261U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber;
#define _PCD_GET_MODE_32_PcdCpuMaxLogicalProcessorNumber  _gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber
#define _PCD_SET_MODE_32_PcdCpuMaxLogicalProcessorNumber(Value)  (_gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber = (Value))
#define _PCD_SET_MODE_32_S_PcdCpuMaxLogicalProcessorNumber(Value)  ((_gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdCpuMaxLogicalProcessorNumber_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdCpuMaxLogicalProcessorNumber _gPcd_BinaryPatch_Size_PcdCpuMaxLogicalProcessorNumber
extern UINTN _gPcd_BinaryPatch_Size_PcdCpuMaxLogicalProcessorNumber; 

EFI_STATUS
EFIAPI
SmmCpuFeaturesLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );


#ifdef __cplusplus
}
#endif

#endif
