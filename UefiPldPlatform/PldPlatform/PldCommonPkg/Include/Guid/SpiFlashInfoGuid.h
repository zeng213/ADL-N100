/** @file
  This file defines the hob structure for the SPI flash variable info.

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __SPI_FLASH_VARIABLE_INFO_GUID_H__
#define __SPI_FLASH_VARIABLE_INFO_GUID_H__

///
/// SPI Flash variable hob info GUID
///
extern EFI_GUID gSpiFlashVariableInfoGuid;

//
// When writing flash in SMM mode, some platform need disable SMM write
// protection using following method:
//  -- AsmWriteMsr32 (0x1FE, MmioRead32 (0xFED30880) | BIT0);
//
#define   FLAGS_SPI_DISABLE_SMM_WRITE_PROTECT  BIT0

//
// On some platforms, flush to flash range will cause flush to MMIO MCA,
// So need a WA to save and restore MCA bank 4 when invalidating cache.
//
#define   FLAGS_SPI_CLFLUSH_WA                 BIT1

typedef struct {
  UINT8         Revision;
  UINT8         Reserved0[1];
  UINT16        Flags;
  // MMIO address to access Spi flash device PCI config data.
  UINT32        SpiPciBase;
  UINT32        VariableStoreBase;
  UINT32        VariableStoreSize;
} SPI_FLASH_INFO;

#endif
