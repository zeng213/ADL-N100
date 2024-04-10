/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_AAE02741_858B_4964_9887_CA870489D944
#define _AUTOGENH_AAE02741_858B_4964_9887_CA870489D944

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

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdTcgPhysicalPresenceInterfaceVer  198U
extern const UINT8 _gPcd_FixedAtBuild_PcdTcgPhysicalPresenceInterfaceVer[];
#define _PCD_GET_MODE_PTR_PcdTcgPhysicalPresenceInterfaceVer  _gPcd_FixedAtBuild_PcdTcgPhysicalPresenceInterfaceVer
//#define _PCD_SET_MODE_PTR_PcdTcgPhysicalPresenceInterfaceVer  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTcgPhysicalPresenceInterfaceVer _gPcd_FixedAtBuild_PcdTcgPhysicalPresenceInterfaceVer
#define _PCD_SIZE_PcdTcgPhysicalPresenceInterfaceVer 4
#define _PCD_GET_MODE_SIZE_PcdTcgPhysicalPresenceInterfaceVer _PCD_SIZE_PcdTcgPhysicalPresenceInterfaceVer
#define _PCD_TOKEN_PcdTcg2PhysicalPresenceFlags  196U
extern const UINT32 _gPcd_FixedAtBuild_PcdTcg2PhysicalPresenceFlags;
#define _PCD_GET_MODE_32_PcdTcg2PhysicalPresenceFlags  _gPcd_FixedAtBuild_PcdTcg2PhysicalPresenceFlags
//#define _PCD_SET_MODE_32_PcdTcg2PhysicalPresenceFlags  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTcg2PhysicalPresenceFlags 0x700E2
#define _PCD_SIZE_PcdTcg2PhysicalPresenceFlags 4
#define _PCD_GET_MODE_SIZE_PcdTcg2PhysicalPresenceFlags _PCD_SIZE_PcdTcg2PhysicalPresenceFlags

EFI_STATUS
EFIAPI
Tcg2PhysicalPresenceLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );


#ifdef __cplusplus
}
#endif

#endif
