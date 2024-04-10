/** @file

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

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

typedef struct  {
  PCH_HDA_VERB_TABLE_HEADER  Header;
  UINT32 Data[];
} HDAUDIO_VERB_TABLE;

HDAUDIO_VERB_TABLE HdaVerbTableDisplayAudio = HDAUDIO_VERB_TABLE_INIT (
  //
  //  VerbTable: ICL Display Audio Codec
  //  Revision ID = 0xFF
  //  Codec Vendor: 0x8086280F
  //
  0x8086, 0x280F,
  0xFF, 0xFF,
  //
  // Display Audio Verb Table
  //
  // Enable the third converter and 4 pin widgets (for GEN10+, the Vendor Node ID is 02h)
  0x00278111,
  // Pin Widget 5 - PORT B - Configuration Default: 0x18560010
  0x00571C10,
  0x00571D00,
  0x00571E56,
  0x00571F18,
  // Pin Widget 6 - PORT C - Configuration Default: 0x18560020
  0x00671C20,
  0x00671D00,
  0x00671E56,
  0x00671F18,
  // Pin Widget 7 - PORT D - Configuration Default: 0x18560030
  0x00771C30,
  0x00771D00,
  0x00771E56,
  0x00771F18,
  // Pin Widget 8 - PORT E - Configuration Default: 0x18560040
  // For GEN10+ forth port was added and Node ID 8 has this Pin Widget for the forth port
  0x00871C40,
  0x00871D00,
  0x00871E56,
  0x00871F18,
  // Disable the third converter and 4 Pins (NID 02h)
  0x00278100
);

HDAUDIO_VERB_TABLE HdaVerbTableAlc700 = HDAUDIO_VERB_TABLE_INIT(
  //
  //  VerbTable: (Realtek ALC700) RVP
  //  Revision ID = 0xff
  //  Codec Verb Table
  //  Codec Address: CAd value (0/1/2)
  //  Codec Vendor: 0x10EC0700
  //
  0x10EC, 0x0700,
  0xFF, 0xFF,


  //===== HDA Codec Subsystem ID Verb-table =====
  //HDA Codec Subsystem ID  : 0x10EC10F2
  0x001720F2,
  0x00172110,
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
  //Pin widget 0x13 - DMIC
  0x01371C00,
  0x01371D00,
  0x01371E00,
  0x01371F40,
  //Pin widget 0x14 - FRONT (Port-D)
  0x01471CF0,
  0x01471D11,
  0x01471E11,
  0x01471F41,
  //Pin widget 0x15 - I2S-OUT
  0x01571CF0,
  0x01571D11,
  0x01571E11,
  0x01571F41,
  //Pin widget 0x16 - LINE3 (Port-B)
  0x01671CF0,
  0x01671D11,
  0x01671E11,
  0x01671F41,
  //Pin widget 0x17 - I2S-OUT
  0x01771C10,
  0x01771D01,
  0x01771E17,
  0x01771F90,
  //Pin widget 0x18 - I2S-IN
  0x01871CF0,
  0x01871D11,
  0x01871E11,
  0x01871F41,
  //Pin widget 0x19 - MIC2 (Port-F)
  0x01971C30,
  0x01971D10,
  0x01971EA1,
  0x01971F04,
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
  0x01D71D20,
  0x01D71E62,
  0x01D71F40,
  //Pin widget 0x1E - S/PDIF-OUT
  0x01E71CF0,
  0x01E71D11,
  0x01E71E11,
  0x01E71F41,
  //Pin widget 0x1F - S/PDIF-IN
  0x01F71CF0,
  0x01F71D11,
  0x01F71E11,
  0x01F71F41,
  //Pin widget 0x21 - HP-OUT (Port-I)
  0x02171C20,
  0x02171D10,
  0x02171E21,
  0x02171F04,
  //Pin widget 0x29 - I2S-IN
  0x02971CF0,
  0x02971D11,
  0x02971E11,
  0x02971F41,
  //Widget node 0x20 :
  0x02050045,
  0x02045289,
  0x0205004A,
  0x0204201B,
  //Widget node 0x20 - 1 :
  0x05850000,
  0x05843888,
  0x0205006F,
  0x02042C0B,


  //Widget node 0X20 for ALC1305   20160603 update
  0x02050024,
  0x02040010,
  0x02050026,
  0x02040000,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040004,
  0x02050028,
  0x02040600,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FFD0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040080,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040080,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003A,
  0x02050028,
  0x02040DFE,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x0204005D,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02040442,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040005,
  0x02050028,
  0x02040880,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040006,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040008,
  0x02050028,
  0x0204B000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204002E,
  0x02050028,
  0x02040800,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400C3,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204D4A0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400CC,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204400A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x020400C1,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x02040320,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040039,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003B,
  0x02050028,
  0x0204FFFF,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003C,
  0x02050028,
  0x0204FC20,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204003A,
  0x02050028,
  0x02041DFE,
  0x02050029,
  0x0204B024,
  //
  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C0,
  0x02050028,
  0x020401FA,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C1,
  0x02050028,
  0x0204DE23,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C2,
  0x02050028,
  0x02041C00,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C3,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C4,
  0x02050028,
  0x02040200,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C5,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C6,
  0x02050028,
  0x020403F5,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C7,
  0x02050028,
  0x0204AF1B,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C8,
  0x02050028,
  0x02041E0A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400C9,
  0x02050028,
  0x0204368E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CA,
  0x02050028,
  0x020401FA,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CB,
  0x02050028,
  0x0204DE23,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CC,
  0x02050028,
  0x02041C00,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CD,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CE,
  0x02050028,
  0x02040200,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400CF,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D0,
  0x02050028,
  0x020403F5,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D1,
  0x02050028,
  0x0204AF1B,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D2,
  0x02050028,
  0x02041E0A,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x020400D3,
  0x02050028,
  0x0204368E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040040,
  0x02050028,
  0x0204800F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040062,
  0x02050028,
  0x02048000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040063,
  0x02050028,
  0x02044848,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040064,
  0x02050028,
  0x02040800,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040065,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040066,
  0x02050028,
  0x02044004,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040067,
  0x02050028,
  0x02040802,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040068,
  0x02050028,
  0x0204890F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040069,
  0x02050028,
  0x0204E021,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040070,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040071,
  0x02050000,
  0x02043330,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040072,
  0x02050000,
  0x02043333,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040073,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040074,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040075,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040076,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040050,
  0x02050028,
  0x020402EC,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040051,
  0x02050028,
  0x02044909,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040052,
  0x02050028,
  0x020440B0,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040046,
  0x02050028,
  0x0204C22E,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040047,
  0x02050028,
  0x02040C00,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040048,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040049,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204004A,
  0x02050028,
  0x02040000,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204004B,
  0x02050028,
  0x02041C00,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006A,
  0x02050028,
  0x02040090,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204006C,
  0x02050028,
  0x0204721F,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x0204009E,
  0x02050028,
  0x02040001,
  0x02050029,
  0x0204B024,

  0x02050024,
  0x02040010,
  0x02050026,
  0x02040004,
  0x02050028,
  0x02040500,
  0x02050029,
  0x0204B024
); // HdaVerbTableAlc700
