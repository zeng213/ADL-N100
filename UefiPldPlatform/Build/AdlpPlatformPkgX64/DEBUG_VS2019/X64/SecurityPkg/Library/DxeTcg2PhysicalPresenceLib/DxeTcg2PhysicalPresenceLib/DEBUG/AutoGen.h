/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_7E507A86_DE8B_4AD3_BC4C_0498389098D3
#define _AUTOGENH_7E507A86_DE8B_4AD3_BC4C_0498389098D3

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern EFI_GUID gEfiTcg2PhysicalPresenceGuid;
extern EFI_GUID gEfiSecurityPkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiTcg2ProtocolGuid;
extern EFI_GUID gEdkiiVariableLockProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdTcg2PhysicalPresenceFlags  196U
extern const UINT32 _gPcd_FixedAtBuild_PcdTcg2PhysicalPresenceFlags;
#define _PCD_GET_MODE_32_PcdTcg2PhysicalPresenceFlags  _gPcd_FixedAtBuild_PcdTcg2PhysicalPresenceFlags
//#define _PCD_SET_MODE_32_PcdTcg2PhysicalPresenceFlags  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTcg2PhysicalPresenceFlags 0x700E2
#define _PCD_SIZE_PcdTcg2PhysicalPresenceFlags 4
#define _PCD_GET_MODE_SIZE_PcdTcg2PhysicalPresenceFlags _PCD_SIZE_PcdTcg2PhysicalPresenceFlags
#include "DxeTcg2PhysicalPresenceLibStrDefs.h"


#ifdef __cplusplus
}
#endif

#endif
