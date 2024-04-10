/** @file
  SBL Gpiodump application to generate GPIO data for YAML or DLT

  Copyright (c) 2019 - 2022, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include  "ShellGpioApp.h"
#include  "PchRegsGpio.h"


// output GPIO Template version
//   0: (legacy) old version and no header in BIN
//   1: old version with header in BIN
//   2: newer version
UINT8 mOutFormat;

/**
  Change an ASCII string to a Unicode string.

  @param[in] AStr     ASCII string.
  @param[in] Length   The maximum size of AStr.
  @param[out] UStr    The Unicode string to pass out.

  @return The actual length.
**/
UINTN
AsciiToUnicode (
  IN  CONST UINT8    *AStr,
  IN  CONST UINTN    Length,
  OUT       CHAR16   *UStr
  )
{
  UINTN Index;

  //
  // just buffer copy, not character copy
  //
  for (Index = 0; Index < Length; Index++) {
    *UStr++ = (CHAR16) *AStr++;
  }

  return Index;
}

/**
  Return TRUE if GrpIdx is GPD (powered by deep sleep well)
**/
BOOLEAN
IsDswGroup (
  IN  UINT8     BrdId,
  IN  UINT8     GrpIdx
)
{
  if (mOutFormat > 0) {
    return (mHeader->DswGrpIdx == GrpIdx);
  }

  // old BIN format: only maintained for old BIN without header
  switch (BrdId) {
  case 0: // cfl
    return (GrpIdx == 0xB) ? TRUE : FALSE;
  case 1: // whl
    return (GrpIdx == 0x8) ? TRUE : FALSE;
  case 2: // TGLLP
    return (GrpIdx == 0x5) ? TRUE : FALSE;
  case 3: // TGLH
    return (GrpIdx == 0x9) ? TRUE : FALSE;
  case 4: // cml
  case 5: // icx-d
  default:
    return FALSE;
  }

}

/**
  This internal procedure will calculate GPIO_RESET_CONFIG value (new type)
  based on provided PadRstCfg for a specific GPIO Pad.

  @param[in]  GpioPad               GPIO Pad
  @param[in]  PadRstCfg             GPIO PadRstCfg value

  @retval GpioResetConfig           GPIO Reset configuration (new type)
**/
GPIO_RESET_CONFIG
GpioResetConfigFromPadRstCfg (
  IN  UINT32        PadRstCfg,
  IN  UINT8         GrpIdx,
  IN  UINT8         BrdId
  )
{
  //if (GrpIdx == 0x1)  ShellPrintEx(-1,-1, L"PRC=0x%08X\n", PadRstCfg);
  if (IsDswGroup(BrdId, GrpIdx) && PadRstCfg < 4) {
    return GpdPadRstCfgToGpioResetConfigMap[PadRstCfg];
  } else if (PadRstCfg < 3) {
    return GppPadRstCfgToGpioResetConfigMap[PadRstCfg];
  } else {
    if (mOutFormat > 0) { /* assume newer platform (e.g., ADL) has Global Rst */
      return GppPadRstCfgToGpioResetConfigMap[PadRstCfg];
    }
    if (BrdId != 5) ASSERT (FALSE);
    return GpioResetDefault;
  }
}

/**
**/
VOID
EFIAPI
BiosPadCfgToSblDw (
  IN      UINT32    Index,
  IN OUT  UINT32   *Sdw0,
  IN OUT  UINT32   *Sdw1,
  IN      UINT8     BrdId
)
{
  UINT32            BiosPadCfg0;
  UINT32            BiosPadCfg1;
  SBL_DW0           SDW0;
  SBL_DW1           SDW1;


  SDW0.DwVal  = 0x0;
  SDW1.DwVal  = 0x0;
  BiosPadCfg0 = MmioRead32(mPadInfo[Index].PadCfg0Addr);
  BiosPadCfg1 = MmioRead32(mPadInfo[Index].PadCfg1Addr);

  // Get BIOS_PAD_CFG_0.PAD_CFG.PADRSTCFG
  SDW0.DW.PowerConfig = GpioResetConfigFromPadRstCfg ((BiosPadCfg0 & B_GPIO_PCR_RST_CONF) >> N_GPIO_PCR_RST_CONF, (UINT8) ((SBL_DW1*)Sdw1)->DW.GrpIdx, BrdId);

  //
  // Get how interrupt is triggered (RxEvCfg)
  //
  SDW0.DW.InterruptConfig = ((BiosPadCfg0 & B_GPIO_PCR_RX_LVL_EDG) >> (N_GPIO_PCR_RX_LVL_EDG - (N_GPIO_INT_CONFIG_INT_TYPE_BIT_POS + 1))) | (0x1 << N_GPIO_INT_CONFIG_INT_TYPE_BIT_POS);

  //
  // Get interrupt generation (GPIRoutIOxAPIC/SCI/SMI/NMI)
  //
  SDW0.DW.InterruptConfig |= ((BiosPadCfg0 & (B_GPIO_PCR_RX_NMI_ROUTE | B_GPIO_PCR_RX_SCI_ROUTE | B_GPIO_PCR_RX_SMI_ROUTE | B_GPIO_PCR_RX_APIC_ROUTE)) >> (N_GPIO_PCR_RX_NMI_ROUTE - (N_GPIO_INT_CONFIG_INT_SOURCE_BIT_POS + 1))) | (0x1 << N_GPIO_INT_CONFIG_INT_SOURCE_BIT_POS);

  //
  // Get GPIO direction (GPIORxDis and GPIOTxDis)
  //
  SDW0.DW.Direction = ((BiosPadCfg0 & (B_GPIO_PCR_RXDIS | B_GPIO_PCR_TXDIS)) >> (N_GPIO_PCR_TXDIS - (N_GPIO_DIRECTION_DIR_BIT_POS + 1))) | (0x1 << N_GPIO_DIRECTION_DIR_BIT_POS);

  //
  // Get GPIO input inversion (RXINV)
  // (Only meaningful if input enabled)
  //
  if((BiosPadCfg0 & B_GPIO_PCR_RXDIS) == 0) {
    SDW0.DW.Direction |= ((BiosPadCfg0 & B_GPIO_PCR_RXINV) >> (N_GPIO_PCR_RXINV - (N_GPIO_DIRECTION_INV_BIT_POS + 1))) | (0x1 << N_GPIO_DIRECTION_INV_BIT_POS);
  }

  //
  // Get GPIO output state (GPIOTxState)
  //
  SDW0.DW.OutputState = ((BiosPadCfg0 & B_GPIO_PCR_TX_STATE) << (N_GPIO_PCR_TX_STATE + (N_GPIO_OUTPUT_BIT_POS + 1))) | (0x1 << N_GPIO_OUTPUT_BIT_POS);

  //
  // Configure GPIO RX raw override to '1' (RXRAW1)
  //
  SDW1.DW.Rsvd1 = ((BiosPadCfg0 & B_GPIO_PCR_RX_RAW1) >> (N_GPIO_PCR_RX_RAW1 - (N_GPIO_OTHER_CONFIG_RXRAW_BIT_POS + 1))) | (0x1 << N_GPIO_OTHER_CONFIG_RXRAW_BIT_POS);

  //
  // Get GPIO Pad Mode (PMode)
  //
  SDW0.DW.PadMode = ((BiosPadCfg0 & B_GPIO_PCR_PAD_MODE) >> (N_GPIO_PCR_PAD_MODE - (N_GPIO_PAD_MODE_BIT_POS + 1))) | (0x1 << N_GPIO_PAD_MODE_BIT_POS);

  //
  // Get GPIO termination (Term)
  //
  SDW1.DW.ElectricalCfg = ((BiosPadCfg1 & B_GPIO_PCR_TERM) >> (N_GPIO_PCR_TERM - (N_GPIO_ELECTRICAL_CONFIG_TERMINATION_BIT_POS + 1))) | (0x1 << N_GPIO_ELECTRICAL_CONFIG_TERMINATION_BIT_POS);


  *Sdw0 = SDW0.DwVal;
  *Sdw1 = SDW1.DwVal;

  return;
}

VOID
EFIAPI
ShowHelp (
  CHAR16 *ErrInfo
)
{
   if (ErrInfo != NULL) {
     ShellPrintEx(-1, -1, L"[Error] %s\n\n", ErrInfo);
   }

   ShellPrintEx(-1, -1, L"gpiodump [-p <platId>] -i padInfo_<board>.bin -n <dumpId>\n");
   ShellPrintEx(-1, -1, L"  <platId>: required for platform using legacy GPIO YAML format:\n");
   ShellPrintEx(-1, -1, L"            0 (cfl), 1 (whl), 2 (tgllp), 3 (tglh), 4 (cml), 5 (icx-d)\n");
   ShellPrintEx(-1, -1, L"            ignored for others\n");
   ShellPrintEx(-1, -1, L"  padInfo_<board>.bin = output from EdsScan.py\n");
   ShellPrintEx(-1, -1, L"  <dumpId>: 0: dump the PAD_CFG DW0&DW1 from BIOS\n");
   ShellPrintEx(-1, -1, L"            1: dump for YAML file format\n");
   ShellPrintEx(-1, -1, L"            2: dump for DLT file format\n");
}

STATIC CONST SHELL_PARAM_ITEM ParamList[] = {
  {L"-h", TypeFlag},
  {L"-p", TypeValue},
  {L"-i", TypeValue},
  {L"-n", TypeValue},
  {NULL, TypeMax}
  };

/**
  UEFI application entry point
**/
EFI_STATUS
EFIAPI
GpiodumpEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  const CHAR16                     *FileName;
  const CHAR16                     *Temp1;
  const CHAR16                     *Temp2;
  SHELL_FILE_HANDLE                 Handle;
  EFI_STATUS                        Status;
  UINT64                            FileSize;
  UINTN                             TempBufferSize;
  VOID                             *TempBuffer;
  CHAR16                            PinName[8];
  UINT32                            Sdw0 = 0;
  UINT32                            Sdw1 = 0;
  UINT32                            Index;
  LIST_ENTRY                       *Package;
  CHAR16                           *ProblemParam;
  UINT8                             DumpType;
  UINT8                             BrdId;

  Status = ShellCommandLineParse (ParamList, &Package, &ProblemParam, TRUE);
  if (EFI_ERROR(Status)) {
    ShowHelp (L"invalid parameters");
    return SHELL_INVALID_PARAMETER;
  }

  if (ShellCommandLineGetFlag(Package, L"-h")) {
    ShowHelp (NULL);
    return SHELL_SUCCESS;
  }

  // Get padInfo filename
  if (ShellCommandLineGetFlag(Package, L"-i") == FALSE || ShellCommandLineGetValue(Package, L"-i") == NULL) {
    ShowHelp (L"Missing argument: -i padInfo_<board>.bin");
    return SHELL_INVALID_PARAMETER;
  } else {
    FileName = ShellCommandLineGetValue(Package, L"-i");
  }

  // Get dumpId
  if (ShellCommandLineGetFlag(Package, L"-n") == FALSE || ShellCommandLineGetValue(Package, L"-n") == NULL) {
    ShowHelp (L"Missing argument: -n <dumpId>>");
    return SHELL_INVALID_PARAMETER;   
  } else {
    Temp2     = ShellCommandLineGetValue(Package, L"-n");
    DumpType = (UINT8) ShellStrToUintn (Temp2);
  }

  // Get platform Id (optional)
  BrdId = 0xFF;
  if (ShellCommandLineGetFlag(Package, L"-p")) {
    Temp1     = ShellCommandLineGetValue(Package, L"-p");
    if (Temp1 != NULL) {
      BrdId = (UINT8) ShellStrToUintn (Temp1);
    }
  }

  Status = gEfiShellProtocol->OpenFileByName (
                            FileName,
                            &Handle,
                            EFI_FILE_MODE_READ
                            );
  if (EFI_ERROR (Status)) {
    ShellPrintEx(-1,-1, L"Open File (%s) Status = %r\n", FileName, Status);
    ShowHelp (NULL);
    return Status;
  }

  Status = gEfiShellProtocol->GetFileSize (Handle, &FileSize);
  if (EFI_ERROR (Status)) {
    ShellPrintEx(-1,-1, L"Get File (%s) Status = %r \n", FileName, Status);
    gEfiShellProtocol->CloseFile (Handle);
    return Status;
  }

  // simple boundary check: 1 entry for legacy or valid header for new version
  // file size should be small, says 1M > 50k gpio entries
  if (((FileSize < sizeof(BIN_HEADER)) && (FileSize < sizeof(PAD_INFO_STRUCT))) ||
       FileSize > 0x10000) {
    gEfiShellProtocol->CloseFile (Handle);
    return SHELL_UNSUPPORTED;
  }

  TempBufferSize = (UINTN) FileSize;  
  TempBuffer = AllocateZeroPool (TempBufferSize);
  Status = gEfiShellProtocol->ReadFile (
                            Handle,
                            &TempBufferSize,
                            TempBuffer
                            );
  if (EFI_ERROR (Status)) {
    ShellPrintEx(-1,-1, L"Read File (%s) Status = %r \n", FileName, Status);
    gEfiShellProtocol->CloseFile (Handle);
    return Status;
  }

  mHeader = (BIN_HEADER *) TempBuffer;
  if (CompareMem(mHeader->Magic, "SBL\0", 4) == 0) {
    if ((mHeader->Version == 1) && (mHeader->Cmd == 1)) {
      mOutFormat = mHeader->RevGpioTmpFormat;
      BrdId = mHeader->BoardId;
      TempBuffer = TempBuffer + sizeof(BIN_HEADER);
      FileSize -= sizeof(BIN_HEADER);
    } else {
      Status = SHELL_UNSUPPORTED;
      goto err;
    }
  } else { // old BIN format without header
    if (BrdId == 0xFF) {
      Status = SHELL_UNSUPPORTED;
      goto err;
    }

    mOutFormat = 0;
  }

  mPadInfo = (PAD_INFO_STRUCT *) TempBuffer;

  for (Index = 0; Index < (FileSize / sizeof(PAD_INFO_STRUCT)) ; Index++) {
    //
    // Convert from Pad Cfg Dws to SBL Dws
    //
    ((SBL_DW1 *)&Sdw1)->DW.GrpIdx = (UINT8)mPadInfo[Index].GrpId;
    BiosPadCfgToSblDw (Index, &Sdw0, &Sdw1, BrdId);
    ((SBL_DW1 *)&Sdw1)->DW.GrpIdx = (UINT8)mPadInfo[Index].GrpId;
    //
    // Update Pin Num
    //
    ((SBL_DW1 *)&Sdw1)->DW.PadNum = (UINT8) mPadInfo[Index].PinNum;
    //
    // Extract PinName
    //
    AsciiToUnicode (mPadInfo[Index].Name, 7, PinName);
    //
    // Dump the required config for SBL
    //
    if (DumpType == 0) { // raw
      ShellPrintEx(-1,-1, L"%s: PAD_CFG_DW0 = 0x%08X : PAD_CFG_DW1 = 0x%08X\n", 
                            PinName,
                            MmioRead32(mPadInfo[Index].PadCfg0Addr), MmioRead32(mPadInfo[Index].PadCfg1Addr));
    } else if (DumpType == 1) { // dsc, yaml
      //ShellPrintEx(-1,-1, L"# !BSF SUBT:{GPIO_TMPL:%s: 0x%08X: 0x%08X: %s}\n", PinName, Sdw0, Sdw1, Nat1Name);
      if (mOutFormat < 2) { // no header BIN or version 1
        ShellPrintEx(-1,-1, L"#  - !expand { GPIO_TMPL : [ %s, 0x%08X,  0x%08X ] }\n", PinName, Sdw0, Sdw1 | BIT31);
      } else {
        ShellPrintEx(-1,-1, L"#  - !expand { GPIO_TMPL : [ %s, %02d, 0x%08X,  0x%08X ] }\n", PinName, (UINT8) ((SBL_DW1 *)&Sdw1)->DW.PadNum, Sdw0, Sdw1 | BIT31);
      }
    } else if (DumpType == 2) { // .dlt
      if (mOutFormat < 2) { // no header BIN or version 1
        Print (L"GPIO_CFG_DATA.GpioPinConfig0_%s | 0x%08X\n", PinName, Sdw0);
        Print (L"GPIO_CFG_DATA.GpioPinConfig1_%s | 0x%08X\n", PinName, Sdw1);
      } else {
        Print (L"GPIO_CFG_DATA.GpioPinConfig0_%s%02d | 0x%08X\n", PinName, (UINT8) (((SBL_DW1 *)&Sdw1)->DW.PadNum & 0xff), Sdw0);
        Print (L"GPIO_CFG_DATA.GpioPinConfig1_%s%02d | 0x%08X\n", PinName, (UINT8) (((SBL_DW1 *)&Sdw1)->DW.PadNum & 0xff), Sdw1);
      }
    }
  }

  Status = EFI_SUCCESS;

err:
  gEfiShellProtocol->CloseFile (Handle);
  return Status;
}
