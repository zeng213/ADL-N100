/** @file

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __HDA_VERB_TABLE_H__
#define __HDA_VERB_TABLE_H__

#include <Library/BaseLib.h>

///
/// Use this macro to create HDAUDIO_VERB_TABLE and populate size automatically
///
#define HDAUDIO_VERB_TABLE_INIT(Vid,Did,Rid,Sdi,...) \
{ \
  { Vid, Did, Rid, Sdi, (sizeof((UINT32[]){__VA_ARGS__})/sizeof(UINT32)) }, \
  { __VA_ARGS__ } \
}

/**
  Azalia verb table header
  Every verb table should contain this defined header and followed by azalia verb commands.
**/
typedef struct {
  UINT16  VendorId;             ///< Codec Vendor ID
  UINT16  DeviceId;             ///< Codec Device ID
  UINT8   RevisionId;           ///< Revision ID of the codec. 0xFF matches any revision.
  UINT8   SdiNum;               ///< SDI number, 0xFF matches any SDI.
  UINT16  DataDwords;           ///< Number of data DWORDs following the header.
} PCH_HDA_VERB_TABLE_HEADER;

#ifdef _MSC_VER
//
// Disable "zero-sized array in struct/union" extension warning.
// Used for neater verb table definitions.
//
#pragma warning (push)
#pragma warning (disable: 4200)
#endif
typedef struct  {
  PCH_HDA_VERB_TABLE_HEADER  Header;
  UINT32 Data[];
} HDAUDIO_VERB_TABLE;
#ifdef _MSC_VER
#pragma warning (pop)
#endif

//
// Realtek ALC269 Audio Codec
//
CONST HDAUDIO_VERB_TABLE AdlHdaVerbTableAlc269 = HDAUDIO_VERB_TABLE_INIT (
  //
  //  VerbTable: (Realtek ALC269) CNL external kit
  //  Revision ID = 0xff
  //  Codec Verb Table for CNL PCH boards
  //  Codec Address: CAd value (0/1/2)
  //  Codec Vendor: 0x10EC0269
  //
  0x10EC, 0x0269,
  0xFF, 0xFF,
  //===================================================================================================
  //
  //                               Realtek Semiconductor Corp.
  //
  //===================================================================================================

// Realtek High Definition Audio Configuration - Version : 5.0.3.3
// Realtek HD Audio Codec : ALC269-VC3
// PCI PnP ID : PCI\VEN_8086&DEV_2668&SUBSYS_111E10EC
// HDA Codec PnP ID : HDAUDIO\FUNC_01&VEN_10EC&DEV_0269&SUBSYS_10EC111E
// The number of verb command block : 17

    // NID 0x12 : 0x90A60140
    // NID 0x14 : 0x90170110
    // NID 0x15 : 0x04214020
    // NID 0x17 : 0x40000000
    // NID 0x18 : 0x04A19030
    // NID 0x19 : 0x411111F0
    // NID 0x1A : 0x411111F0
    // NID 0x1B : 0x411111F0
    // NID 0x1D : 0x40E4A205
    // NID 0x1E : 0x411111F0
    // NID 0x20 : 0x0013FFFF
//===== HDA Codec Subsystem ID Verb-table =====
//HDA Codec Subsystem ID  : 0x10EC111E
 0x0017201E,
 0x00172111,
 0x001722EC,
 0x00172310,

//===== Pin Widget Verb-table =====
//Widget node 0x01 :
 0x0017FF00,
 0x0017FF00,
 0x0017FF00,
 0x0017FF00,
//Pin widget 0x12 - DMIC
 0x01271C00,
 0x01271D00,
 0x01271E00,
 0x01271F40,
//Pin widget 0x14 - SPEAKER-OUT (Port-D)
 0x01471C20,
 0x01471D01,
 0x01471E17,
 0x01471F90,
//Pin widget 0x15 - P-OUT (Port-A)
 0x01571C10,
 0x01571D40,
 0x01571E21,
 0x01571F04,
//Pin widget 0x17 - MONO-OUT (Port-)
 0x01771CF0,
 0x01771D11,
 0x01771E11,
 0x01771F41,
// //Pin widget 0x18 - MIC1 (Port-B)
//  0x01871C40,
//  0x01871D10,
//  0x01871EA1,
//  0x01871F04,
//  //Pin widget 0x19 - MIC2 (Port-F)
//  0x01971CF0,
//  0x01971D11,
//  0x01971E11,
//  0x01971F41,
//Pin widget 0x18 - MIC1 (Port-B)
 0x01871C30,
 0x01871D90,
 0x01871EA1,
 0x01871F04,
//Pin widget 0x19 - MIC2 (Port-F)
 0x01971C3F,
 0x01971D01,
 0x01971EA7,
 0x01971FB7,
//Pin widget 0x1A - LINE1 (Port-C)
 0x01A71CF0,
 0x01A71D11,
 0x01A71E11,
 0x01A71F41,
//Pin widget 0x1B - LINE2 (Port-E)
 0x01B71CF0,
 0x01B71D11,
 0x01B71E11,
 0x01B71F41,
//Pin widget 0x1D - PC-BEEP
 0x01D71C05,
 0x01D71DA2,
 0x01D71E44,
 0x01D71F40,
//Pin widget 0x1E - S/PDIF-OUT
 0x01E71CF0,
 0x01E71D11,
 0x01E71E11,
 0x01E71F41,
//Widget node 0x20 :
 0x02050018,
 0x02045184,
 0x0205001C,
 0x02042800,
//Widget node 0x20 - 1 :
 0x02050024,
 0x02040000,
 0x02050004,
 0x02040080,
//Widget node 0x20 - 2 :
 0x02050008,
 0x02040300,
 0x0205000C,
 0x02043F00,
//Widget node 0x20 - 3 :
 0x02050015,
 0x02048002,
 0x02050015,
 0x02048002,
//Widget node 0x0C :
 0x00C37080,
 0x00270610,
 0x00D37080,
 0x00370610
);// HdaVerbTableAlc269

// //
// // Realtek ALC269 Audio Codec
// //
// CONST HDAUDIO_VERB_TABLE AdlHdaVerbTableAlc269 = HDAUDIO_VERB_TABLE_INIT (
//   //
//   //  VerbTable: (Realtek ALC269) CNL external kit
//   //  Revision ID = 0xff
//   //  Codec Verb Table for CNL PCH boards
//   //  Codec Address: CAd value (0/1/2)
//   //  Codec Vendor: 0x10EC111E
//   //
//   0x10EC, 0x0269,
//   0xFF, 0xFF,
//   //===================================================================================================
//   //
//   //                               Realtek Semiconductor Corp.
//   //
//   //===================================================================================================

// // Realtek High Definition Audio Configuration - Version : 5.0.3.3
// // Realtek HD Audio Codec : ALC269-VC3
// // PCI PnP ID : PCI\VEN_8086&DEV_2668&SUBSYS_111E10EC
// // HDA Codec PnP ID : HDAUDIO\FUNC_01&VEN_10EC&DEV_0269&SUBSYS_10EC111E
// // The number of verb command block : 17

//     // NID 0x12 : 0x90A60140
//     // NID 0x14 : 0x90170110
//     // NID 0x15 : 0x04214020
//     // NID 0x17 : 0x40000000
//     // NID 0x18 : 0x04A19030
//     // NID 0x19 : 0x411111F0
//     // NID 0x1A : 0x411111F0
//     // NID 0x1B : 0x411111F0
//     // NID 0x1D : 0x40E4A205
//     // NID 0x1E : 0x411111F0
//     // NID 0x20 : 0x0013FFFF
// //===== ,DA Codec Subsystem ID Verb-table =====
//         //,DA Codec Subsystem ID  : 0x10EC12B6
//         0x001720B6,
//         0x00172112,
//         0x001722EC,
//         0x00172310,


//         //===== Pin Widget Verb-table =====
//         //Widget node 0x01 :
//         0x0017FF00,
//         0x0017FF00,
//         0x0017FF00,
//         0x0017FF00,
//         //Pin widget 0x12 - DMIC
//         0x01271C30,
//         0x01271D01,
//         0x01271EA6,
//         0x01271F90,
//         //Pin widget 0x14 - SPEAKER-OUT (Port-D)
//         0x01471C10,
//         0x01471D01,
//         0x01471E17,
//         0x01471F90,
//         //Pin widget 0x15 - ,P-OUT (Port-A)
//         0x01571C20,
//         0x01571D10,
//         0x01571E21,
//         0x01571F04,
//         //Pin widget 0x17 - MONO-OUT (Port-,)
//         0x01771C00,
//         0x01771D00,
//         0x01771E00,
//         0x01771F40,
//         //Pin widget 0x18 - MIC1 (Port-B)
//         0x01871C40,
//         0x01871D10,
//         0x01871EA1,
//         0x01871F04,
//         //Pin widget 0x19 - MIC2 (Port-F)
//         0x01971CF0,
//         0x01971D11,
//         0x01971E11,
//         0x01971F41,
//         //Pin widget 0x1A - LINE1 (Port-C)
//         0x01A71CF0,
//         0x01A71D11,
//         0x01A71E11,
//         0x01A71F41,
//         //Pin widget 0x1B - LINE2 (Port-E)
//         0x01B71CF0,
//         0x01B71D11,
//         0x01B71E11,
//         0x01B71F41,
//         //Pin widget 0x1D - PC-BEEP
//         0x01D71C45,
//         0x01D71DA1,
//         0x01D71EE5,
//         0x01D71F40,
//         //Pin widget 0x1E - S/PDIF-OUT
//         0x01E71CF0,
//         0x01E71D11,
//         0x01E71E11,
//         0x01E71F41,
//         //Widget node 0x20 :
//         0x02050018,
//         0x02040184,
//         0x0205001C,
//         0x02040800,
//         //Widget node 0x20 - 1 :
//         0x02050024,
//         0x02040000,
//         0x02050004,
//         0x02040080,
//         //Widget node 0x20 - 2 :
//         0x02050008,
//         0x02040300,
//         0x0205000C,
//         0x02043F00,
//         //Widget node 0x20 - 3 :
//         0x02050015,
//         0x02048002,

// );// HdaVerbTableAlc269

#endif /* __HDA_VERB_TABLE_H__ */
