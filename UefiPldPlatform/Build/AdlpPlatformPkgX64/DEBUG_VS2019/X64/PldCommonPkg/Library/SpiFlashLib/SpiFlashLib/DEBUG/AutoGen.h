/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_6F96AFCB_DE89_4ca1_A63F_8703EE8FDE50
#define _AUTOGENH_6F96AFCB_DE89_4ca1_A63F_8703EE8FDE50

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gSpiFlashVariableInfoGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdPciExpressBaseAddress  18U
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  LibPcdGet64(_PCD_TOKEN_PcdPciExpressBaseAddress)
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress  LibPcdGetSize(_PCD_TOKEN_PcdPciExpressBaseAddress)
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  LibPcdSet64(_PCD_TOKEN_PcdPciExpressBaseAddress, (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  LibPcdSet64S(_PCD_TOKEN_PcdPciExpressBaseAddress, (Value))

RETURN_STATUS
EFIAPI
SpiConstructor (
  VOID
  );


#ifdef __cplusplus
}
#endif

#endif
