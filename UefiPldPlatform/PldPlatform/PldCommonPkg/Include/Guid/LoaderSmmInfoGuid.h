/** @file
  This file defines the SMM info hob structure, passed from bootloader.
  
  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __LOADER_SMM_INFO_GUID_H__
#define __LOADER_SMM_INFO_GUID_H__

///
/// SMM Information GUID
///
extern EFI_GUID gSmmInformationGuid;

//
// Set this flag if there are 4KB SMRAM at SmmBase used for communication
// between bootloader and UEFI payload.
//
#define   SMM_FLAGS_4KB_COMMUNICATION  BIT0

typedef enum {
  REG_TYPE_MEM,
  REG_TYPE_IO,
  REG_TYPE_PCICFG,
  REG_TYPE_MMIO,
} REG_TYPE;

typedef enum {
  WIDE8   = 1,
  WIDE16  = 2,
  WIDE32  = 4
} REG_WIDTH;

#pragma pack(1)

///
/// SMI control register
///
typedef struct {
  UINT8   RegType;
  UINT8   RegWidth;
  /// The bit index for APMC Enable (APMC_EN).
  UINT8   SmiApmPos;
  /// The bit index for Global SMI Enable (GBL_SMI_EN)
  UINT8   SmiGblPos;
  /// The bit index for End of SMI (EOS)
  UINT8   SmiEosPos;
  UINT8   Rsvd[3];
  /// Address for SMM control and enable register
  UINT32  Address;
} SMI_CTRL_REG;

///
/// SMI status register
///
typedef struct {
  UINT8   RegType;
  UINT8   RegWidth;
  /// The bit index for APM Status (APM_STS).
  UINT8   SmiApmPos;
  UINT8   Rsvd[5];
  /// Address for SMM status register
  UINT32  Address;
} SMI_STS_REG;

///
/// SMI lock register
///
typedef struct {
  UINT8   RegType;
  UINT8   RegWidth;
  /// The bit index for SMI Lock (SMI_LOCK)
  UINT8   SmiLockPos;
  UINT8   Rsvd;
  /// Register address for SMM SMI lock
  UINT32  Address;
} SMI_LOCK_REG;

typedef struct {
  UINT8                       Revision;
  UINT8                       Flags;
  UINT8                       Reserved[2];
  UINT32                      SmmBase;
  UINT32                      SmmSize;
  SMI_CTRL_REG                SmiCtrlReg;
  SMI_STS_REG                 SmiStsReg;
  SMI_LOCK_REG                SmiLockReg;
} LOADER_SMM_INFO;

#pragma pack()

#endif
