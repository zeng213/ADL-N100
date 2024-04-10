/** @file
  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _BL_SMM_COMMUNICATION_LIB_H
#define _BL_SMM_COMMUNICATION_LIB_H


#define BL_PLD_COMM_SIG       SIGNATURE_32('B', 'P', 'C', 'O')

#define SMMBASE_INFO_COMM_ID  1
#define S3_SAVE_REG_COMM_ID   2
#define BL_SW_SMI_COMM_ID     3

//
// Format to share info between bootloader and payload.
// Structures can be present in any order within the 4KB
// communication area starting from TSEG. They are
// identified by their Id.
//

      //  -------------------------- <----TSEG_BASE------
      //  |     BL_PLD_COMM_HDR    |
      //  |         (Id:1)         |
      //  --------------------------
      //  |       SMMBASE_INFO     |
      //  --------------------------
      //  --------------------------
      //  |     BL_PLD_COMM_HDR    |
      //  |         (Id:*)         |
      //  --------------------------
      //  |      COMM_STRUCT_2     |
      //  --------------------------
      //  --------------------------
      //  |     BL_PLD_COMM_HDR    |
      //  |         (Id:*)         |
      //  --------------------------
      //  |      COMM_STRUCT_3     |
      //  --------------------------
      //  --------------------------
      //  |     BL_PLD_COMM_HDR    |
      //  |         (Id:2)         |
      //  --------------------------
      //  |      S3_SAVE_REG       |
      //  --------------------------
      //  --------------------------
      //  |     BL_PLD_COMM_HDR    |
      //  |         (Id:*)         |
      //  --------------------------
      //  |      COMM_STRUCT_5     |
      //  --------------------------
      //  --------------------------
      //            .....
      //            .....
      //            .....


#pragma pack(1)

typedef struct {
  UINT32  Signature;
  UINT8   Id;
  UINT8   Count;
  UINT16  TotalSize;
} BL_PLD_COMM_HDR;

typedef struct {
  UINT8         Type;
  UINT8         Width;
  UINT8         Rsvd[2];
  UINT32        Addr;
  UINT32        Val;
} REG_INFO;

typedef struct {
  BL_PLD_COMM_HDR S3SaveHdr;
  REG_INFO        RegInfo[];
} S3_SAVE_REG;

typedef struct {
  UINT32  ApicId;
  UINT32  SmmBase;
} CPU_SMMBASE;

typedef struct {
  BL_PLD_COMM_HDR SmmBaseHdr;
  CPU_SMMBASE     SmmBase[];
} SMMBASE_INFO;

typedef struct {
  UINTN   SmmCommBase;
  UINTN   SmmCommSize;
} BL_SMM_COMMUNICATION_INFO;

typedef struct {
  BL_PLD_COMM_HDR BlSwSmiHdr;
  UINT8           BlSwSmiHandlerInput;
} BL_SW_SMI_INFO;

#pragma pack()

/**
  Get base and size of communication area

  @param[out] BlSmmCommInfo Pointer to Bootloader smm communication info structure

  @retval   EFI_NOT_FOUND     Struct with signature not found
  @retval   EFI_SUCCESS       Struct with signature found
**/
EFI_STATUS
EFIAPI
GetBlCommArea (
  OUT  BL_SMM_COMMUNICATION_INFO    *BlSmmCommInfo
  );

/**
  Get pointer to a specific struct area in TSEG

  @param[in] BlSmmCommInfo Pointer to Bootloader smm communication info structure
  @param[in] Id            Id of the struct to be retreived

  @retval   NULL           Struct with signature not found
  @retval   Ptr            Pointer to struct with signature
**/
VOID *
EFIAPI
GetBlCommData (
  IN  BL_SMM_COMMUNICATION_INFO *BlSmmCommInfo,
  IN  UINT8   Id
  );

/**
  This function set data in TSEG area
  designated for bootloader and payload communication purpose.

  @param[in] BlSmmCommInfo Pointer to Bootloader smm communication info structure
  @param[in] DataPtr       Address of the structure to be copied to TSEG

  @retval   EFI_OUT_OF_RESOURCES  If SmmSize is exceeding the range
  @retval   EFI_OUT_OF_RESOURCES  If appeding new struct exceeds SmmCommSize
  @retval   EFI_SUCCESS           Append is successful

**/
EFI_STATUS
EFIAPI
SetBlCommData (
  IN  BL_SMM_COMMUNICATION_INFO *BlSmmCommInfo,
  IN  VOID                      *DataPtr
  );

#endif
