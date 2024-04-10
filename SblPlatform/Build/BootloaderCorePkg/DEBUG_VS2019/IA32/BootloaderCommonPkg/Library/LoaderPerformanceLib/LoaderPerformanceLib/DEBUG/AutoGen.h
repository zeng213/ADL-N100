/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_73EA68AC_D03C_4c47_BDFD_41C5267AC6EC
#define _AUTOGENH_73EA68AC_D03C_4c47_BDFD_41C5267AC6EC

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPeiFirmwarePerformanceGuid;
extern GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid;
extern GUID gLoaderFspInfoGuid;
extern GUID gCsmePerformanceInfoGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdBootPerformanceMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdBootPerformanceMask;
#define _PCD_GET_MODE_32_PcdBootPerformanceMask  _gPcd_FixedAtBuild_PcdBootPerformanceMask
//#define _PCD_SET_MODE_32_PcdBootPerformanceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdBootPerformanceMask 0x1
#define _PCD_SIZE_PcdBootPerformanceMask 4
#define _PCD_GET_MODE_SIZE_PcdBootPerformanceMask _PCD_SIZE_PcdBootPerformanceMask


#ifdef __cplusplus
}
#endif

#endif
