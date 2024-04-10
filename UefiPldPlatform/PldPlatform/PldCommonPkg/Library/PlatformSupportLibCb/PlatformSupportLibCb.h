/** @file
  Platform support module include file.

  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

/*
 * This file is part of the libpayload project.
 *
 * Copyright (C) 2008 Advanced Micro Devices, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#ifndef _PLATFORM_SUPPORT_LIB_CB_
#define _PLATFORM_SUPPORT_LIB_CB_

#include <PiPei.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/HobLib.h>
#include <Library/PlatformSupportLib.h>
#include <Library/BlParseLib.h>
#include <Guid/LoaderFspInfoGuid.h>
#include <Guid/LoaderSmmInfoGuid.h>
#include <Guid/SpiFlashInfoGuid.h>
#include <Guid/TpmEventLogInfoGuid.h>
#include <Coreboot.h>

#define CB_TAG_FSP_INFO    0x0031
struct cb_fsp_info {
  UINT8          Revision;
  UINT8          verified_boot:1;
  UINT8          measure_boot:1;
  UINT8          Flags:6;
  UINT8          Reserved0[2];
  UINT32         fsps_base;
  VOID           *HobList;
};

#define CB_TAG_SMM_REGION       0x0032
struct cb_smm_region {
  UINT32 tag;
  UINT32 size;
  UINT32 smm_base;
  UINT32 smm_size;
};

#define CB_TAG_MB_EVENT_LOG     0x0033
struct cb_mb_event_log {
  UINT32 tag;
  UINT32 size;
  UINT32 tcg1_2_lasa;
  UINT32 tcg1_2_last_evt;
  UINT32 tcg2_lasa;
  UINT32 tcg2_last_evt;
};


#endif // _COREBOOT_PEI_H_INCLUDED_
