/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_932AD5C3_768D_4f48_B2FE_83FF0C64F7B3
#define _AUTOGENH_932AD5C3_768D_4f48_B2FE_83FF0C64F7B3

#ifdef __cplusplus
extern "C" {
#endif

#include <PiPei.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x932AD5C3, 0x768D, 0x4f48, {0xB2, 0xFE, 0x83, 0xFF, 0x0C, 0x64, 0xF7, 0xB3}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}}

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

#define PCD_PEI_SERVICE_DRIVER_VERSION         7

//
// External PCD database debug information
//
#if 0
#define PEI_GUID_TABLE_SIZE                1U
#define PEI_STRING_TABLE_SIZE              1U
#define PEI_SKUID_TABLE_SIZE               1U
#define PEI_LOCAL_TOKEN_NUMBER_TABLE_SIZE  3
#define PEI_LOCAL_TOKEN_NUMBER             3
#define PEI_EXMAPPING_TABLE_SIZE           1U
#define PEI_EX_TOKEN_NUMBER                0U
#define PEI_SIZE_TABLE_SIZE                2U
#define PEI_GUID_TABLE_EMPTY               TRUE
#define PEI_STRING_TABLE_EMPTY             TRUE
#define PEI_SKUID_TABLE_EMPTY              TRUE
#define PEI_DATABASE_EMPTY                 FALSE
#define PEI_EXMAP_TABLE_EMPTY              TRUE

typedef struct {
  UINT64             SkuIdTable[PEI_SKUID_TABLE_SIZE];


  UINT32             PcdMeasuredBootHashMask_373657df_5dc0_4cbb_87ad_501eb889bf89[1];



  DYNAMICEX_MAPPING  ExMapTable[PEI_EXMAPPING_TABLE_SIZE];
  UINT32             LocalTokenNumberTable[PEI_LOCAL_TOKEN_NUMBER_TABLE_SIZE];
  GUID               GuidTable[PEI_GUID_TABLE_SIZE];

  UINT8              StringTable[1]; /* _ */

  SIZE_INFO          SizeTable[PEI_SIZE_TABLE_SIZE];
  UINT16             PcdPlatformBootTimeOut_914aebe7_4635_459b_aa1c_11e219b03a10[1];






  SKU_ID             SystemSkuId;
} PEI_PCD_DATABASE_INIT;

typedef struct {


  UINT32   PcdFspResetStatus_69d13bf0_af91_4d96_aa9f_2184c5ce3bc0[1];




} PEI_PCD_DATABASE_UNINIT;

typedef struct {
  //GUID                  Signature;  // PcdDataBaseGuid
  //UINT32                BuildVersion;
  //UINT32                Length;
  //SKU_ID                SystemSkuId;       // Current SkuId value.
  //UINT32                LengthForAllSkus;  // Length of all SKU PCD DB
  //UINT32                UninitDataBaseSize;// Total size for PCD those default value with 0.
  //TABLE_OFFSET          LocalTokenNumberTableOffset;
  //TABLE_OFFSET          ExMapTableOffset;
  //TABLE_OFFSET          GuidTableOffset;
  //TABLE_OFFSET          StringTableOffset;
  //TABLE_OFFSET          SizeTableOffset;
  //TABLE_OFFSET          SkuIdTableOffset;
  //TABLE_OFFSET          PcdNameTableOffset;
  //UINT16                LocalTokenCount;  // LOCAL_TOKEN_NUMBER for all
  //UINT16                ExTokenCount;     // EX_TOKEN_NUMBER for DynamicEx
  //UINT16                GuidTableCount;   // The Number of Guid in GuidTable
  //UINT8                 Pad[6];
  PEI_PCD_DATABASE_INIT    Init;
  PEI_PCD_DATABASE_UNINIT  Uninit;
} PEI_PCD_DATABASE;

#define PEI_NEX_TOKEN_NUMBER (PEI_LOCAL_TOKEN_NUMBER - PEI_EX_TOKEN_NUMBER)
#endif






#ifdef __cplusplus
}
#endif

#endif
