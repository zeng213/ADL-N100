/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A41BF616_EF77_4658_9992_D813071C34CF
#define _AUTOGENH_A41BF616_EF77_4658_9992_D813071C34CF

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
#define _PCD_TOKEN_PcdAcpiPmTimerBase  0U
extern volatile  UINT16  _gPcd_BinaryPatch_PcdAcpiPmTimerBase;
#define _PCD_GET_MODE_16_PcdAcpiPmTimerBase  _gPcd_BinaryPatch_PcdAcpiPmTimerBase
#define _PCD_SET_MODE_16_PcdAcpiPmTimerBase(Value)  (_gPcd_BinaryPatch_PcdAcpiPmTimerBase = (Value))
#define _PCD_SET_MODE_16_S_PcdAcpiPmTimerBase(Value)  ((_gPcd_BinaryPatch_PcdAcpiPmTimerBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdAcpiPmTimerBase_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdAcpiPmTimerBase _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase; 


#ifdef __cplusplus
}
#endif

#endif
