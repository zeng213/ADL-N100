/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.c
  Abstract:       Auto-generated AutoGen.c for building module or library.
**/
#include <PiPei.h>
#include <Library/DebugLib.h>
#include <Library/PeimEntryPoint.h>

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEfiCallerIdGuid = {0x932AD5C3, 0x768D, 0x4f48, {0xB2, 0xFE, 0x83, 0xFF, 0x0C, 0x64, 0xF7, 0xB3}};

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEdkiiDscPlatformGuid = {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}};

GLOBAL_REMOVE_IF_UNREFERENCED CHAR8 *gEfiCallerBaseName = "PcdData";

// Definition of SkuId Array
GLOBAL_REMOVE_IF_UNREFERENCED UINT64 _gPcd_SkuId_Array[] = {0x0};
//SKUID: DEFAULT
//
// External PCD database debug information
//
#if 0
PEI_PCD_DATABASE_INIT gPEIPcdDbInit = {
  /* SkuIdTable */
  { 1, 0U,  },


  { 0x00000002U }, /*  PcdMeasuredBootHashMask_373657df_5dc0_4cbb_87ad_501eb889bf89[1] */


  /* VPD */

  /* ExMapTable */
  {
    { 0U, 0U, 0U },

  },
  /* LocalTokenNumberTable */
  {
    offsetof(PEI_PCD_DATABASE, Init.PcdPlatformBootTimeOut_914aebe7_4635_459b_aa1c_11e219b03a10) | PCD_DATUM_TYPE_UINT16 | PCD_TYPE_DATA,
    offsetof(PEI_PCD_DATABASE, Init.PcdMeasuredBootHashMask_373657df_5dc0_4cbb_87ad_501eb889bf89) | PCD_DATUM_TYPE_UINT32 | PCD_TYPE_DATA,
    offsetof(PEI_PCD_DATABASE, Uninit.PcdFspResetStatus_69d13bf0_af91_4d96_aa9f_2184c5ce3bc0) | PCD_DATUM_TYPE_UINT32 | PCD_TYPE_DATA,

  },
  /* GuidTable */
  {
    {0x00000000, 0x0000, 0x0000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},

  },


/* SkuHead */
  {
   offsetof (PEI_PCD_DATABASE, Init.PcdPlatformBootTimeOut_914aebe7_4635_459b_aa1c_11e219b03a10) | PCD_DATUM_TYPE_UINT16 | PCD_TYPE_DATA, /* */
           offsetof (PEI_PCD_DATABASE, Init.SkuHead)  /* */
   offsetof (PEI_PCD_DATABASE, Init.PcdMeasuredBootHashMask_373657df_5dc0_4cbb_87ad_501eb889bf89) | PCD_DATUM_TYPE_UINT32 | PCD_TYPE_DATA, /* */
           offsetof (PEI_PCD_DATABASE, Init.SkuHead)  /* */
   offsetof (PEI_PCD_DATABASE, Uninit.PcdFspResetStatus_69d13bf0_af91_4d96_aa9f_2184c5ce3bc0) | PCD_DATUM_TYPE_UINT32 | PCD_TYPE_DATA, /* */
           offsetof (PEI_PCD_DATABASE, Uninit.SkuHead)  /* */
  
  },
 /* StringTable */
  { 0 }, /* _ */

  /* SizeTable */
  {
    0U, ['0U'], /* _ */

  },
  { 2U }, /*  PcdPlatformBootTimeOut_914aebe7_4635_459b_aa1c_11e219b03a10[1] */






  0
};
#endif



VOID
EFIAPI
ProcessLibraryConstructorList (
  IN       EFI_PEI_FILE_HANDLE       FileHandle,
  IN CONST EFI_PEI_SERVICES          **PeiServices
  )
{

}



VOID
EFIAPI
ProcessLibraryDestructorList (
  IN       EFI_PEI_FILE_HANDLE       FileHandle,
  IN CONST EFI_PEI_SERVICES          **PeiServices
  )
{

}

GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPeimRevision = 0x00000000U;

EFI_STATUS
EFIAPI
ProcessModuleEntryPointList (
  IN       EFI_PEI_FILE_HANDLE  FileHandle,
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )

{
  return EFI_SUCCESS;
}

GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gDriverUnloadImageCount = 0U;

EFI_STATUS
EFIAPI
ProcessModuleUnloadList (
  IN EFI_HANDLE        ImageHandle
  )
{
  return EFI_SUCCESS;
}
