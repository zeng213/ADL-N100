#undef MIN
#undef MAX
/** @file
  ACPI RTD3 SSDT table for ADL N RVP

  Copyright (c) 2020 - 2022, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include <Include/AcpiDebug.h>

DefinitionBlock (
    "Rtd3.aml",
    "SSDT",
    2,
    "Rtd3",
    "AdlN_Rvp",
    0x1000
    )
{
External(S0ID)
//
//WWAN Pins
//
External(WRTO)
External(WBRS)
External(PBRS)
External(PRST)
External(WPRP)
External(WFCP)
External(PFCP)
External(WWKP)
External(WWEN)

External(TPDT)
External(TPLT)
//
//Pcie Slot 1 Pins
//
External(PSPR)
External(PPSP)
External(PSPE)
External(PPSR)
External(PSWP)

//
// Pch ssd Pins
//
External(SSDP)
External(SSDR)
External(SDRP)
External(SDPP)

//
// Touch panel Pins
//
External(GPDI)
External(GPLI)
External(GPLP)
External(GPLR)
External(PPDI)
External(PPLI)
External(PPLP)
External(PPLR)
External(TPLS)

//
//WLAN wake Pins
//
External(WLWK)


//
//sata
//

External(SATP)
External(STPP)

//
//GbE
//
External(GBED)

External(XDCE)

/** @file
  ACPI RTD3 SSDT table

@copyright
  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

External(\_SB.OSCO)
External(\_SB.PC00,DeviceObj)
External(\_SB.PC00.SAT0, DeviceObj)
External(\_SB.PC00.SAT0.PRT0, DeviceObj)
External(\_SB.PC00.SAT0.PRT1, DeviceObj)
External(\_SB.PC00.SAT0.PRT2, DeviceObj)
External(\_SB.PC00.SAT0.PRT3, DeviceObj)
External(\_SB.PC00.SAT0.PRT4, DeviceObj)
External(\_SB.PC00.SAT0.PRT5, DeviceObj)
External(\_SB.PC00.SAT0.PRT6, DeviceObj)
External(\_SB.PC00.SAT0.PRT7, DeviceObj)

/** @file
  ACPI Common Include File for PCIE RP ACPI Objects.

@copyright
  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <PcieRpMacroDefinition.h>


//
// MACRO Definations for Printing PCIE RP Info: Start
// Note: These below MACRO will only work under PCIE RP Scope.
//
#define GET_STRING_PCIE_RP_INDEX_FROM_SLOT_VAR   Concatenate(" And Index : ", ToHexString(SLOT))
#define GET_STRING_PCIE_RP_TYPE_FROM_PRTP_VAR    Concatenate(" Type (2: PCH, 4: CPU) : ", ToHexString(PRTP))
#define GET_STRING_PCIE_RP_INFO_PRTP_SLOT        Concatenate(GET_STRING_PCIE_RP_TYPE_FROM_PRTP_VAR, GET_STRING_PCIE_RP_INDEX_FROM_SLOT_VAR)
#define GET_STRING_PCIE_RP_INFO                  Concatenate("PCIE RP", GET_STRING_PCIE_RP_INFO_PRTP_SLOT)
//
// Note: These above MACRO will only work under PCIE RP Scope.
// MACRO Definations for Printing PCIE RP Info: End
//

External (\_SB.PC00,DeviceObj)
// External Variable for PCIE Rp Device Objects
External (\_SB.PC00.RP01, DeviceObj)
External (\_SB.PC00.RP02, DeviceObj)
External (\_SB.PC00.RP03, DeviceObj)
External (\_SB.PC00.RP04, DeviceObj)
External (\_SB.PC00.RP05, DeviceObj)
External (\_SB.PC00.RP06, DeviceObj)
External (\_SB.PC00.RP07, DeviceObj)
External (\_SB.PC00.RP08, DeviceObj)
External (\_SB.PC00.RP09, DeviceObj)
External (\_SB.PC00.RP10, DeviceObj)
External (\_SB.PC00.RP11, DeviceObj)
External (\_SB.PC00.RP12, DeviceObj)
External (\_SB.PC00.RP13, DeviceObj)
External (\_SB.PC00.RP14, DeviceObj)
External (\_SB.PC00.RP15, DeviceObj)
External (\_SB.PC00.RP16, DeviceObj)
External (\_SB.PC00.RP17, DeviceObj)
External (\_SB.PC00.RP18, DeviceObj)
External (\_SB.PC00.RP19, DeviceObj)
External (\_SB.PC00.RP20, DeviceObj)
External (\_SB.PC00.RP21, DeviceObj)
External (\_SB.PC00.RP22, DeviceObj)
External (\_SB.PC00.RP23, DeviceObj)
External (\_SB.PC00.RP24, DeviceObj)
External (\_SB.PC00.RP25, DeviceObj)
External (\_SB.PC00.RP26, DeviceObj)
External (\_SB.PC00.RP27, DeviceObj)
External (\_SB.PC00.RP28, DeviceObj)

External (\_SB.PC00.PEG0, DeviceObj)
External (\_SB.PC00.PEG1, DeviceObj)
External (\_SB.PC00.PEG2, DeviceObj)

// External Variable holding PCIE Rp Mapped under VMD status
External (\_SB.PC00.RP01.PRMV, IntObj)
External (\_SB.PC00.RP02.PRMV, IntObj)
External (\_SB.PC00.RP03.PRMV, IntObj)
External (\_SB.PC00.RP04.PRMV, IntObj)
External (\_SB.PC00.RP05.PRMV, IntObj)
External (\_SB.PC00.RP06.PRMV, IntObj)
External (\_SB.PC00.RP07.PRMV, IntObj)
External (\_SB.PC00.RP08.PRMV, IntObj)
External (\_SB.PC00.RP09.PRMV, IntObj)
External (\_SB.PC00.RP10.PRMV, IntObj)
External (\_SB.PC00.RP11.PRMV, IntObj)
External (\_SB.PC00.RP12.PRMV, IntObj)
External (\_SB.PC00.RP13.PRMV, IntObj)
External (\_SB.PC00.RP14.PRMV, IntObj)
External (\_SB.PC00.RP15.PRMV, IntObj)
External (\_SB.PC00.RP16.PRMV, IntObj)
External (\_SB.PC00.RP17.PRMV, IntObj)
External (\_SB.PC00.RP18.PRMV, IntObj)
External (\_SB.PC00.RP19.PRMV, IntObj)
External (\_SB.PC00.RP20.PRMV, IntObj)
External (\_SB.PC00.RP21.PRMV, IntObj)
External (\_SB.PC00.RP22.PRMV, IntObj)
External (\_SB.PC00.RP23.PRMV, IntObj)
External (\_SB.PC00.RP24.PRMV, IntObj)
External (\_SB.PC00.RP25.PRMV, IntObj)
External (\_SB.PC00.RP26.PRMV, IntObj)
External (\_SB.PC00.RP27.PRMV, IntObj)
External (\_SB.PC00.RP28.PRMV, IntObj)

External (\_SB.PC00.PEG0.PRMV, IntObj)
External (\_SB.PC00.PEG1.PRMV, IntObj)
External (\_SB.PC00.PEG2.PRMV, IntObj)


// External Variable holding PCIE Rp Index Number
External (\_SB.PC00.RP01.SLOT, IntObj)
External (\_SB.PC00.RP02.SLOT, IntObj)
External (\_SB.PC00.RP03.SLOT, IntObj)
External (\_SB.PC00.RP04.SLOT, IntObj)
External (\_SB.PC00.RP05.SLOT, IntObj)
External (\_SB.PC00.RP06.SLOT, IntObj)
External (\_SB.PC00.RP07.SLOT, IntObj)
External (\_SB.PC00.RP08.SLOT, IntObj)
External (\_SB.PC00.RP09.SLOT, IntObj)
External (\_SB.PC00.RP10.SLOT, IntObj)
External (\_SB.PC00.RP11.SLOT, IntObj)
External (\_SB.PC00.RP12.SLOT, IntObj)
External (\_SB.PC00.RP13.SLOT, IntObj)
External (\_SB.PC00.RP14.SLOT, IntObj)
External (\_SB.PC00.RP15.SLOT, IntObj)
External (\_SB.PC00.RP16.SLOT, IntObj)
External (\_SB.PC00.RP17.SLOT, IntObj)
External (\_SB.PC00.RP18.SLOT, IntObj)
External (\_SB.PC00.RP19.SLOT, IntObj)
External (\_SB.PC00.RP20.SLOT, IntObj)
External (\_SB.PC00.RP21.SLOT, IntObj)
External (\_SB.PC00.RP22.SLOT, IntObj)
External (\_SB.PC00.RP23.SLOT, IntObj)
External (\_SB.PC00.RP24.SLOT, IntObj)
External (\_SB.PC00.RP25.SLOT, IntObj)
External (\_SB.PC00.RP26.SLOT, IntObj)
External (\_SB.PC00.RP27.SLOT, IntObj)
External (\_SB.PC00.RP28.SLOT, IntObj)

External (\_SB.PC00.PEG0.SLOT, IntObj)
External (\_SB.PC00.PEG1.SLOT, IntObj)
External (\_SB.PC00.PEG2.SLOT, IntObj)

// External Variable holding PCIE Rp Type Information
External (\_SB.PC00.RP01.PRTP, IntObj)
External (\_SB.PC00.RP02.PRTP, IntObj)
External (\_SB.PC00.RP03.PRTP, IntObj)
External (\_SB.PC00.RP04.PRTP, IntObj)
External (\_SB.PC00.RP05.PRTP, IntObj)
External (\_SB.PC00.RP06.PRTP, IntObj)
External (\_SB.PC00.RP07.PRTP, IntObj)
External (\_SB.PC00.RP08.PRTP, IntObj)
External (\_SB.PC00.RP09.PRTP, IntObj)
External (\_SB.PC00.RP10.PRTP, IntObj)
External (\_SB.PC00.RP11.PRTP, IntObj)
External (\_SB.PC00.RP12.PRTP, IntObj)
External (\_SB.PC00.RP13.PRTP, IntObj)
External (\_SB.PC00.RP14.PRTP, IntObj)
External (\_SB.PC00.RP15.PRTP, IntObj)
External (\_SB.PC00.RP16.PRTP, IntObj)
External (\_SB.PC00.RP17.PRTP, IntObj)
External (\_SB.PC00.RP18.PRTP, IntObj)
External (\_SB.PC00.RP19.PRTP, IntObj)
External (\_SB.PC00.RP20.PRTP, IntObj)
External (\_SB.PC00.RP21.PRTP, IntObj)
External (\_SB.PC00.RP22.PRTP, IntObj)
External (\_SB.PC00.RP23.PRTP, IntObj)
External (\_SB.PC00.RP24.PRTP, IntObj)
External (\_SB.PC00.RP25.PRTP, IntObj)
External (\_SB.PC00.RP26.PRTP, IntObj)
External (\_SB.PC00.RP27.PRTP, IntObj)
External (\_SB.PC00.RP28.PRTP, IntObj)

External (\_SB.PC00.PEG0.PRTP, IntObj)
External (\_SB.PC00.PEG1.PRTP, IntObj)
External (\_SB.PC00.PEG2.PRTP, IntObj)

// External Variable holding PCIE Rp RTD3 Cold Capability
External (\_SB.PC00.RP01.RD3C, IntObj)
External (\_SB.PC00.RP02.RD3C, IntObj)
External (\_SB.PC00.RP03.RD3C, IntObj)
External (\_SB.PC00.RP04.RD3C, IntObj)
External (\_SB.PC00.RP05.RD3C, IntObj)
External (\_SB.PC00.RP06.RD3C, IntObj)
External (\_SB.PC00.RP07.RD3C, IntObj)
External (\_SB.PC00.RP08.RD3C, IntObj)
External (\_SB.PC00.RP09.RD3C, IntObj)
External (\_SB.PC00.RP10.RD3C, IntObj)
External (\_SB.PC00.RP11.RD3C, IntObj)
External (\_SB.PC00.RP12.RD3C, IntObj)
External (\_SB.PC00.RP13.RD3C, IntObj)
External (\_SB.PC00.RP14.RD3C, IntObj)
External (\_SB.PC00.RP15.RD3C, IntObj)
External (\_SB.PC00.RP16.RD3C, IntObj)
External (\_SB.PC00.RP17.RD3C, IntObj)
External (\_SB.PC00.RP18.RD3C, IntObj)
External (\_SB.PC00.RP19.RD3C, IntObj)
External (\_SB.PC00.RP20.RD3C, IntObj)
External (\_SB.PC00.RP21.RD3C, IntObj)
External (\_SB.PC00.RP22.RD3C, IntObj)
External (\_SB.PC00.RP23.RD3C, IntObj)
External (\_SB.PC00.RP24.RD3C, IntObj)
External (\_SB.PC00.RP25.RD3C, IntObj)
External (\_SB.PC00.RP26.RD3C, IntObj)
External (\_SB.PC00.RP27.RD3C, IntObj)
External (\_SB.PC00.RP28.RD3C, IntObj)

External (\_SB.PC00.PEG0.RD3C, IntObj)
External (\_SB.PC00.PEG1.RD3C, IntObj)
External (\_SB.PC00.PEG2.RD3C, IntObj)


External(\_SB.PC00.RP01.VDID)
External(\_SB.PC00.RP02.VDID)
External(\_SB.PC00.RP03.VDID)
External(\_SB.PC00.RP04.VDID)
External(\_SB.PC00.RP05.VDID)
External(\_SB.PC00.RP06.VDID)
External(\_SB.PC00.RP07.VDID)
External(\_SB.PC00.RP08.VDID)
External(\_SB.PC00.RP09.VDID)
External(\_SB.PC00.RP10.VDID)
External(\_SB.PC00.RP11.VDID)
External(\_SB.PC00.RP12.VDID)
External(\_SB.PC00.RP13.VDID)
External(\_SB.PC00.RP14.VDID)
External(\_SB.PC00.RP15.VDID)
External(\_SB.PC00.RP16.VDID)
External(\_SB.PC00.RP17.VDID)
External(\_SB.PC00.RP18.VDID)
External(\_SB.PC00.RP19.VDID)
External(\_SB.PC00.RP20.VDID)
External(\_SB.PC00.RP21.VDID)
External(\_SB.PC00.RP22.VDID)
External(\_SB.PC00.RP23.VDID)
External(\_SB.PC00.RP24.VDID)
External(\_SB.PC00.RP25.VDID)
External(\_SB.PC00.RP26.VDID)
External(\_SB.PC00.RP27.VDID)
External(\_SB.PC00.RP28.VDID)

External(\_SB.PC00.PEG0.VDID)
External(\_SB.PC00.PEG1.VDID)
External(\_SB.PC00.PEG2.VDID)

External(\_SB.PC00.RP01.L23D, MethodObj)
External(\_SB.PC00.RP02.L23D, MethodObj)
External(\_SB.PC00.RP03.L23D, MethodObj)
External(\_SB.PC00.RP04.L23D, MethodObj)
External(\_SB.PC00.RP05.L23D, MethodObj)
External(\_SB.PC00.RP06.L23D, MethodObj)
External(\_SB.PC00.RP07.L23D, MethodObj)
External(\_SB.PC00.RP08.L23D, MethodObj)
External(\_SB.PC00.RP09.L23D, MethodObj)
External(\_SB.PC00.RP10.L23D, MethodObj)
External(\_SB.PC00.RP11.L23D, MethodObj)
External(\_SB.PC00.RP12.L23D, MethodObj)
External(\_SB.PC00.RP13.L23D, MethodObj)
External(\_SB.PC00.RP14.L23D, MethodObj)
External(\_SB.PC00.RP15.L23D, MethodObj)
External(\_SB.PC00.RP16.L23D, MethodObj)
External(\_SB.PC00.RP17.L23D, MethodObj)
External(\_SB.PC00.RP18.L23D, MethodObj)
External(\_SB.PC00.RP19.L23D, MethodObj)
External(\_SB.PC00.RP20.L23D, MethodObj)
External(\_SB.PC00.RP21.L23D, MethodObj)
External(\_SB.PC00.RP22.L23D, MethodObj)
External(\_SB.PC00.RP23.L23D, MethodObj)
External(\_SB.PC00.RP24.L23D, MethodObj)
External(\_SB.PC00.RP25.L23D, MethodObj)
External(\_SB.PC00.RP26.L23D, MethodObj)
External(\_SB.PC00.RP27.L23D, MethodObj)
External(\_SB.PC00.RP28.L23D, MethodObj)
External(\_SB.PC00.PEG0.L23D, MethodObj)
External(\_SB.PC00.PEG1.L23D, MethodObj)
External(\_SB.PC00.PEG2.L23D, MethodObj)

External(\_SB.PC00.RP01.DL23, MethodObj)
External(\_SB.PC00.RP02.DL23, MethodObj)
External(\_SB.PC00.RP03.DL23, MethodObj)
External(\_SB.PC00.RP04.DL23, MethodObj)
External(\_SB.PC00.RP05.DL23, MethodObj)
External(\_SB.PC00.RP06.DL23, MethodObj)
External(\_SB.PC00.RP07.DL23, MethodObj)
External(\_SB.PC00.RP08.DL23, MethodObj)
External(\_SB.PC00.RP09.DL23, MethodObj)
External(\_SB.PC00.RP10.DL23, MethodObj)
External(\_SB.PC00.RP11.DL23, MethodObj)
External(\_SB.PC00.RP12.DL23, MethodObj)
External(\_SB.PC00.RP13.DL23, MethodObj)
External(\_SB.PC00.RP14.DL23, MethodObj)
External(\_SB.PC00.RP15.DL23, MethodObj)
External(\_SB.PC00.RP16.DL23, MethodObj)
External(\_SB.PC00.RP17.DL23, MethodObj)
External(\_SB.PC00.RP18.DL23, MethodObj)
External(\_SB.PC00.RP19.DL23, MethodObj)
External(\_SB.PC00.RP20.DL23, MethodObj)
External(\_SB.PC00.RP21.DL23, MethodObj)
External(\_SB.PC00.RP22.DL23, MethodObj)
External(\_SB.PC00.RP23.DL23, MethodObj)
External(\_SB.PC00.RP24.DL23, MethodObj)
External(\_SB.PC00.RP25.DL23, MethodObj)
External(\_SB.PC00.RP26.DL23, MethodObj)
External(\_SB.PC00.RP27.DL23, MethodObj)
External(\_SB.PC00.RP28.DL23, MethodObj)
External(\_SB.PC00.PEG0.DL23, MethodObj)
External(\_SB.PC00.PEG1.DL23, MethodObj)
External(\_SB.PC00.PEG2.DL23, MethodObj)

External(\_SB.PC00.XHCI, DeviceObj)
External(\_SB.PC00.XDCI, DeviceObj)
External(GBES)
If (LNotEqual(GBES,0)) {
  External(\_SB.PC00.GLAN, DeviceObj)
}
External(\_SB.PC00.XHCI.MEMB)
External(\_SB.PC00.XDCI.D0I3)
External(\_SB.PC00.XDCI.XDCB)
External(\GBEP)
External(\_SB.PC00.XHCI.RHUB, DeviceObj)
External(\_SB.PC00.XHCI.RHUB.SS01, DeviceObj)
External(\_SB.PC00.XHCI.RHUB.SS02, DeviceObj)
External(\_SB.PC00.XHCI.RHUB.HS01, DeviceObj) //xHCI HSP port 1
External(\_SB.PC00.XHCI.RHUB.HS02, DeviceObj) //xHCI HSP port 2

External(PEP0)
External(XHPR)
External(RCG0, IntObj)     // RTD3 Config Setting0(BIT0:Reserved, BIT1:Reserved, Bit3: BT, BIT6:Card Reader, BIT7:WWAN, BIT8:WSB SIP FAB1 Card reader)
External(RCG1, IntObj)     // RTD3 Config Setting1(BIT0:Sata Port0, BIT1:Sata Port1, BIT2:Sata Port2, BIT3:Sata Port3)
External(\GPRW, MethodObj)
External(P8XH, MethodObj)

//
// Externs common to ULT0RTD3.asl and FFRDRTD3.asl and exclude for BRRTD3.asl
//

// GPIO methods
External(\_SB.SPMV, MethodObj)
External(\_SB.SGRA, MethodObj)
External(\_SB.SGWP, MethodObj)
External(\_SB.GGIV, MethodObj)
External(\_SB.GGOV, MethodObj)
External(\_SB.SGOV, MethodObj)
External(\_SB.SGII, MethodObj)
External(\_SB.CAGS, MethodObj)
External(\_SB.ISME, MethodObj)


// RTD3 devices and variables
External(\_SB.PC00.LPCB.H_EC.ECMD, MethodObj) // EC Command method

External(\UAMS)
External(SDS0,FieldUnitObj)
External(SDS1,FieldUnitObj)
External(AUDD,FieldUnitObj)
External(SHSB,FieldUnitObj)
External(VRRD,FieldUnitObj)
External(IC0D,FieldUnitObj)
External(IC1D,FieldUnitObj)

External (DGBA, FieldUnitObj)
External (DGOP, FieldUnitObj)

External(SPCO,MethodObj)
External(SPCX,MethodObj)

External(\_SB.CSD0, MethodObj)
External(\_SB.CSD3, MethodObj)
External(DVID)

#if FixedPcdGetBool(PcdAdlLpSupport) == 1
/**@file
 VER2 GPIO ASL header

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

//
// Definition for GPIO groups and pads
//
#ifndef _GPIO_ACPI_DEFINES_TGL_
#define _GPIO_ACPI_DEFINES_TGL_

#include <GpioPinsVer2Lp.h>

#define GPIO_VER2_P_ACPI_HID  "INTC1055" //ADL-P GPIO Controller

//
// TGL-PCH-LP
//
#define GPIO_VER2_LP_DRIVER_GPP_B0  0
#define GPIO_VER2_LP_DRIVER_GPP_B1  1
#define GPIO_VER2_LP_DRIVER_GPP_B2  2
#define GPIO_VER2_LP_DRIVER_GPP_B3  3
#define GPIO_VER2_LP_DRIVER_GPP_B4  4
#define GPIO_VER2_LP_DRIVER_GPP_B5  5
#define GPIO_VER2_LP_DRIVER_GPP_B6  6
#define GPIO_VER2_LP_DRIVER_GPP_B7  7
#define GPIO_VER2_LP_DRIVER_GPP_B8  8
#define GPIO_VER2_LP_DRIVER_GPP_B9  9
#define GPIO_VER2_LP_DRIVER_GPP_B10 10
#define GPIO_VER2_LP_DRIVER_GPP_B11 11
#define GPIO_VER2_LP_DRIVER_GPP_B12 12
#define GPIO_VER2_LP_DRIVER_GPP_B13 13
#define GPIO_VER2_LP_DRIVER_GPP_B14 14
#define GPIO_VER2_LP_DRIVER_GPP_B15 15
#define GPIO_VER2_LP_DRIVER_GPP_B16 16
#define GPIO_VER2_LP_DRIVER_GPP_B17 17
#define GPIO_VER2_LP_DRIVER_GPP_B18 18
#define GPIO_VER2_LP_DRIVER_GPP_B19 19
#define GPIO_VER2_LP_DRIVER_GPP_B20 20
#define GPIO_VER2_LP_DRIVER_GPP_B21 21
#define GPIO_VER2_LP_DRIVER_GPP_B22 22
#define GPIO_VER2_LP_DRIVER_GPP_B23 23

#define GPIO_VER2_LP_DRIVER_GPP_T1  33
#define GPIO_VER2_LP_DRIVER_GPP_T10 42
#define GPIO_VER2_LP_DRIVER_GPP_T11 43
#define GPIO_VER2_LP_DRIVER_GPP_T12 44
#define GPIO_VER2_LP_DRIVER_GPP_T13 45
#define GPIO_VER2_LP_DRIVER_GPP_T14 46
#define GPIO_VER2_LP_DRIVER_GPP_T15 47

#define GPIO_VER2_LP_DRIVER_GPP_A1  65
#define GPIO_VER2_LP_DRIVER_GPP_A2  66
#define GPIO_VER2_LP_DRIVER_GPP_A10 74
#define GPIO_VER2_LP_DRIVER_GPP_A11 75
#define GPIO_VER2_LP_DRIVER_GPP_A12 76
#define GPIO_VER2_LP_DRIVER_GPP_A13 77
#define GPIO_VER2_LP_DRIVER_GPP_A14 78
#define GPIO_VER2_LP_DRIVER_GPP_A15 79
#define GPIO_VER2_LP_DRIVER_GPP_A16 80
#define GPIO_VER2_LP_DRIVER_GPP_A17 81
#define GPIO_VER2_LP_DRIVER_GPP_A18 82
#define GPIO_VER2_LP_DRIVER_GPP_A19 83
#define GPIO_VER2_LP_DRIVER_GPP_A20 84
#define GPIO_VER2_LP_DRIVER_GPP_A21 85
#define GPIO_VER2_LP_DRIVER_GPP_A22 86
#define GPIO_VER2_LP_DRIVER_GPP_A23 87


#endif // _GPIO_ACPI_DEFINES_TGL_

#else
/**@file
 VER4 GPIO ASL header

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

//
// Definition for GPIO groups and pads
//
#ifndef _GPIO_ACPI_DEFINES_ADL_
#define _GPIO_ACPI_DEFINES_ADL_

#include "GpioPinsVer4S.h"

#define GPIO_VER4_S_ACPI_HID   "INTC1056" //ADL-S GPIO Controller

//
// ADL-PCH-S
//
#define GPIO_VER4_S_DRIVER_GPP_I0                 0

#define GPIO_VER4_S_DRIVER_GPP_R0                 32


#define GPIO_VER4_S_DRIVER_VGPIO0                 96
#define GPIO_VER4_S_DRIVER_VGPIO30                115

#define GPIO_VER4_S_DRIVER_VGPIO_0_0              128

#define GPIO_VER4_S_DRIVER_GPP_B0                 160

#define GPIO_VER4_S_DRIVER_GPP_G0                 192

#define GPIO_VER4_S_DRIVER_GPP_H0                 224

#define GPIO_VER4_S_DRIVER_GPP_A0                 256

#define GPIO_VER4_S_DRIVER_GPP_C0                 288

#define GPIO_VER4_S_DRIVER_GPP_S0                 320

#define GPIO_VER4_S_DRIVER_GPP_E0                 352

#define GPIO_VER4_S_DRIVER_GPP_K0                 384

#define GPIO_VER4_S_DRIVER_GPP_F0                 416

#define GPIO_VER4_S_DRIVER_GPP_D0                 448

#endif // _GPIO_ACPI_DEFINES_ADL_

#endif
/** @file

  Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/


//
// Definition for MSPDRTREQ bits, which are used for ASL code to
// trigger requests for ModPHY SPD gating.
//
#ifndef _HSIO_DEFINE_ASL_
#define _HSIO_DEFINE_ASL_

#define MODPHY_SPD_GATING_PCIE_RP1    0
#define MODPHY_SPD_GATING_PCIE_RP2    1
#define MODPHY_SPD_GATING_PCIE_RP3    2
#define MODPHY_SPD_GATING_PCIE_RP4    3
#define MODPHY_SPD_GATING_PCIE_RP5    4
#define MODPHY_SPD_GATING_PCIE_RP6    5
#define MODPHY_SPD_GATING_PCIE_RP7    6
#define MODPHY_SPD_GATING_PCIE_RP8    7
#define MODPHY_SPD_GATING_PCIE_RP9    8
#define MODPHY_SPD_GATING_PCIE_RP10   9
#define MODPHY_SPD_GATING_PCIE_RP11   10
#define MODPHY_SPD_GATING_PCIE_RP12   11
#define MODPHY_SPD_GATING_PCIE_RP13   12
#define MODPHY_SPD_GATING_PCIE_RP14   13
#define MODPHY_SPD_GATING_PCIE_RP15   14
#define MODPHY_SPD_GATING_PCIE_RP16   15
#define MODPHY_SPD_GATING_PCIE_RP17   16
#define MODPHY_SPD_GATING_PCIE_RP18   17
#define MODPHY_SPD_GATING_PCIE_RP19   18
#define MODPHY_SPD_GATING_PCIE_RP20   19
#define MODPHY_SPD_GATING_SATA        20
#define MODPHY_SPD_GATING_GBE         21
#define MODPHY_SPD_GATING_XHCI        22
#define MODPHY_SPD_GATING_XDCI        23
#define MODPHY_SPD_GATING_UFS         24

#endif // _HSIO_DEFINE_ASL_


#define RCG1_RTD3_PRT0_ENABLED 0x01
#define RCG1_RTD3_PRT1_ENABLED 0x02
#define RCG1_RTD3_PRT2_ENABLED 0x04
#define RCG1_RTD3_PRT3_ENABLED 0x08
#define RCG1_RTD3_PRT4_ENABLED 0x10
#define RCG1_RTD3_PRT5_ENABLED 0x20
#define RCG1_RTD3_PRT6_ENABLED 0x40
#define RCG1_RTD3_PRT7_ENABLED 0x80
#define RCG1_RTD3_NVM1_ENABLED 0x100
#define RCG1_RTD3_NVM2_ENABLED 0x200
#define RCG1_RTD3_NVM3_ENABLED 0x400

//
// GPIO states mapping
//
#define PIN_GPIO_ACTIVE_LOW 0
#define PIN_GPIO_ACTIVE_HIGH 1

#define WWAN_PCIE_ROOT_PORT \_SB.PC00.RP04
External(WWAN_PCIE_ROOT_PORT.PXSX, DeviceObj)
External(WWAN_PCIE_ROOT_PORT.LASX)
External(\_SB.PC00.RP09.PXSX,DeviceObj)
External(\_SB.PC00.RP04.PXSX.WIST,MethodObj)
External(\_SB.PC00.XHCI.RHUB.HS08, DeviceObj)
External(\_SB.GBTR, MethodObj)
External(\_SB.BTRK, MethodObj)


External(\_SB.PC00.I2C0, DeviceObj) //I2C0 Controller
External(\_SB.PC00.I2C0.TPD0, DeviceObj) // Touch pad
External(\_SB.PC00.I2C0.TPD0._STA, MethodObj)
External(\_SB.PC00.I2C0.TPL1, DeviceObj) // Touch panel 2
External(\_SB.PC00.I2C0.TPL1._STA, MethodObj)

External(\_SB.PC00.HDAS, DeviceObj)
External(\_SB.PC00.HDAS.VDID)

External(\_SB.PC00.SAT0.PRT0.PRES, MethodObj)

//Board configuration

//PCIe P3 -M.2 KEY E WWAN7360 -SRC CLK-NA(REWORK)
//PCIe P4 -M.2 KEY B WLAN Wifi-BT -SRC CLK-2
//PCIe P4 -M.2 KEY B WWAN7360 -SRC CLK-1(REWORK)
//PCIe P7 -x4 PCIe DT Slot (1Pair -x1 cem slot -sd card/TSN AIC) -SRC CLK-3
//PCIe P9:P12 -PCIe X4 ssd -SRC CLK-0(LAN REVERSAL)
//PCIe P9 -RJ45 LAN PORT/UFS(0)- SRC CLK-4 (REWORK)
//PCIe P10 -UFS(1)- SRC CLK-4-(REWORK)
//PCIe P11 -Sata Direct(SATA P0) SRC CLK-4 -(REWORK)

// PCIe root ports - START
  /// PCIE RTD3 - PCIe M.2 CONNECTOR WWAN
    ///
    If (LAnd(LNotEqual(WWEN,0),LNotEqual(WRTO,0)) ) {
      Scope(WWAN_PCIE_ROOT_PORT) {
        Name(BRST, Package() {0, 0})
        Store(WBRS, Index(BRST, 0))
        Store(PBRS, Index(BRST, 1))
        Name(RSTG, Package() {0, 0})
        Store(PRST, Index(RSTG, 0))
        Store(WPRP, Index(RSTG, 1))
        Name(PWRG, Package() {0, 0})
        Store(WFCP, Index(PWRG, 0))
        Store(PFCP, Index(PWRG, 1))
        Name(WAKG, 0)
        Store(WWKP, WAKG)
        Name(SCLK, 1)

      }
    }
    ///
    /// PCIE RTD3 - PCIE SLOT 1 - X1 CONNECTOR
    ///
    Scope(\_SB.PC00.RP07) {
      Name(RSTG, Package() {0, 0})
      Store(PSPR, Index(RSTG, 0))
      Store(PPSR, Index(RSTG, 1))
      Name(PWRG, Package() {0, 0})
      Store(PSPE, Index(PWRG, 0))
      Store(PPSP, Index(PWRG, 1))
      Name(WAKG, 0)
      Name(SCLK, 3)
      Name(WAKP, 0)             // must be defined due to compiler bug, will be removed when fixed https://bugs.acpica.org/show_bug.cgi?id=1432
      Store(PSWP,WAKG)
      /**@file
        PCIe Root Port Generic PCIE Device Rtd3 file.
      
        Copyright (c) 2021 - 2022, Intel Corporation. All rights reserved.<BR>
        SPDX-License-Identifier: BSD-2-Clause-Patent
      **/
      
      /// @details
      /// Code in this file uses following variables:
      /// SCLK: ICC Clock number - optional
      /// WAKG: WAKE GPIO pad - optional
      /// Below objects should be defined according to the format described in PinDriverLib.asl
      /// RSTG: reset pin definition - mandatory
      /// PWRG: power GPIO pad - optional
      /// WAKP: Flag to indicate that power gating must not be performed if WAKE is enabled - optional
      /** @defgroup pcie_scope PCIe Root Port Scope **/
      
        //
        // AcpiPinDriverLib imports(from DSDT in platform)
        //
        External (\PIN.STA, MethodObj)
        External (\PIN.ON, MethodObj)
        External (\PIN.OFF, MethodObj)
        //
        // GpioLib imports(DSDT)
        //
        External (\_SB.SHPO, MethodObj)
      
        //
        // HSIO lib imports
        //
        External (\_SB.PSD0, MethodObj)
        External (\_SB.PSD3, MethodObj)
        External (DVES, MethodObj)
        External (DHDW, MethodObj)
        External (EHDW, MethodObj)
        External (D3HT, FieldUnitObj) // CPU PCIE RP Power State
        External (PCPB, IntObj) // PCIe core power veto bitmask, default 0 - allow for core power removal
        External (HBSL, FieldUnitObj)
        External (HBCL, FieldUnitObj)
        External (HBPL, FieldUnitObj)
        External (TMCS, IntObj)
      
        // WAKE enable on PCIe device.
        Name (WKEN, 0)
      
        // Last OFF Timestamp (WOFF): The time stamp of the last power resource _OFF method evaluation
        Name (WOFF, 0)
      
        Name (LNRD, 0) // Delay before PERST# assertion in us
      
        //
        // The deepest D-state supported by this device in the S0 system sleeping state where the device can wake itself,
        // "4" represents D3cold.
        //
        Method (_S0W, 0x0, NotSerialized)
        {
      
          If (CondRefOf (RD3C)) {
            If (LEqual (RD3C, 0x01)) {
              Return (0x4)
            }
          }
      
          Return (0x3)
        }
      
        //
        // Device Sleep Wake - sets the sleep and wake transition states for a device.
        // ACPI Specification Defined Method. Called by OSPM.
        //
        Method (_DSW, 3, NotSerialized)
        {
          /// This method is used to enable/disable wake from PCIe (WKEN)
      
          If (Arg1)
          { /// If entering Sx, enable Sx WAKE
            Store (1, WKEN)
          } Else {  /// If Staying in S0
            If (LAnd(Arg0, Arg2)) ///- Check if Exiting D0 and arming for wake
            { ///- Set PME
              Store (1, WKEN)
            } Else { ///- Disable runtime PME, either because staying in D0 or disabling wake
              Store (0, WKEN)
            }
          }
        /** @defgroup pcie_dsw PCIE _DSW **/
        } // End _DSW
      
        Method (PPS0, 0, Serialized) { // Platform specific PCIe root port _PS0 Hook Function.
        }
      
        Method (PPS3, 0, Serialized) { // Platform specific PCIe root port _PS3 Hook Function.
        }
      
        //
        // PCIe slot power resource definition
        //
        PowerResource (PXP, 0, 0) {
      
          Method (_STA, 0) {
      
            //
            // Check if PCIE RP is available or Not by Checking Vendor and Device ID.
            //
            If (LEqual (VDID, 0xFFFFFFFF)) {
              Return (0)
            }
      
            //
            // Check if PCIE RP Power Resource is supported or Not.
            //
            If (LEqual (GPRS (), 0)) {
              Return (0)
            }
      
            //
            // Return PCIE RP Power Resource Status.
            //
            Return (PSTA ())
          }
      
          Method (_ON) {
      
            //
            // Check if PCIE RP is available or Not by Checking Vendor and Device ID.
            //
            If (LEqual (VDID, 0xFFFFFFFF)) {
              Return ()
            }
      
            //
            // Check if PCIE RP Power Resource is supported or Not.
            //
            If (LEqual (GPRS (), 0)) {
              Return ()
            }
      
            //
            // Turn on slot power
            //
            PON ()
      
            //
            // Trigger L2/L3 ready exit flow in rootport - transition link to Detect
            //
            L23D ()
          }
      
          Method (_OFF) {
      
            //
            // Check if PCIE RP is available or Not by Checking Vendor and Device ID.
            //
            If (LEqual (VDID, 0xFFFFFFFF)) {
              Return ()
            }
      
            //
            // Check if PCIE RP Power Resource is supported or Not.
            //
            If (LEqual (GPRS (), 0)) {
              Return ()
            }
      
            //
            // Trigger L2/L3 ready entry flow in rootport
            //
            DL23 ()
      
            //
            // Turn off slot power
            //
            POFF ()
          }
        } // End PowerResource
      
        //
        // Get Permission for Power Removal.
        // Check whether or not to Disable Power Package GPIO During Device Power OFF(D3 Cold Transition).
        // Input: VOID
        //
        // @return 1 if it is Safe to Remove/Disable Power. 0 Not allow for Power Removal.
        //
        Method (GPPR, 0) {
      
          // If WAKP has not been defined we can safely disable power.
          // If WAKP is defined this slot does not supply device with auxilary power and we have to keep primary power
          // to allow for WAKE. If WAKP is not equal to 0 and WKEN has been enabled do not disable the power.
          If (CondRefOf (WAKP)) {
            If (LAnd (LNotEqual (WAKP, 0), LEqual (WKEN, 0))) {
              Return (0)
            }
          }
      
          //
          // If PCPB has not been defined we can safely disable power.
          // If PCPB is defined and non Zero we have to keep primary power.
          //
          If (CondRefOf (PCPB)) {
            If (LNotEqual (PCPB, 0)) {
              Return (0)
            }
          }
      
          //
          // If DVES Method has not been defined we can safely disable power.
          // If DVES Method is defined and return Zero value we have to keep primary power.
          //
          If (CondRefOf (DVES)) {
            If (LEqual (DVES (), 0)) {
              Return (0)
            }
          }
      
          //
          // Now Safe To Remove/Disable Power.
          //
          Return (1)
        }
      
        //
        // Get PCIe RP Power Resource Support.
        // If D3 Cold is supported by PCIE RP or Not.
        // Input: VOID
        //
        // @return 1 PCIE RP Power Resource Supported. 0 PCIE RP Power Resource Not Supported.
        //
        Method (GPRS, 0) {
      
          If (LAnd (CondRefOf (PRTP), LEqual (PRTP, PCIE_RP_TYPE_CPU))) {
      
            //
            // Check for Hybrid Connection Status for PCIE RP and for single CPU M.2 with x2 MUX
            //
            If (CondRefOf (HBCL)) {
              If (LOr(LNotEqual(HBCL, 0xFF), LLessEqual(HBCL, 0x2))) {
                If (LEqual (HBCL, SLOT)) {
                  Return (0)
                }
              }
            }
          }
      
          //
          // Check for Hybrid Connection Status for PCIE RP and for single CPU M.2 with x2 MUX
          //
          If (LAnd (CondRefOf (PRTP), LEqual (PRTP, PCIE_RP_TYPE_PCH))) {
            If (CondRefOf (HBSL)) {
              Divide ( Subtract (SLOT, 1), 4, , Local0) // Get PCIE RP Controller Number ( (SLOT-1)/4)
              // Check if Hybrid Connection Status BIT Corresponding to Controller Number is SET or NOT.
              If ( And (HBSL, ShiftLeft (BIT0, Local0))) {
                Return (0)
              }
            }
      
            If (LAnd(CondRefOf (HBCL), CondRefOf (HBPL))) {
              If (LOr(LNotEqual(HBCL, 0xFF), LLessEqual(HBCL, 0x2))) {
                If (LEqual (HBPL, Subtract(SLOT, 1))) {
                  Return (0)
                }
              }
            }
      
          }
      
          //
          // Check if D3 Cold is supported for PCIE RP.
          //
          If (CondRefOf (RD3C)) {
            If (LNotEqual (RD3C, 0)) {
              Return (0)
            }
          }
      
          //
          // Check if PCIE RP is Mapped under VMD. D3 Cold flow will be taken care by VMD and it's Child ACPI Devices.
          //
          If (CondRefOf (PRMV)) {
            If (LEqual (PRMV, 1)) {
              Return (0)
            }
          }
      
          //
          // D3 Cold is supported for PCIE RP
          //
          Return (1)
        }
      
        //
        // Returns the status of PCIe slot core power.
        //
        Method (PSTA, 0) {
      
          //
          // RESET# assertion is mandatory for PCIe RTD3
          // So if RESET# is asserted the whole slot is off
          //
          If (\PIN.STA (RSTG)) {
            Return (0)
          } Else {
            Return (1)
          }
        }
      
        // Turn on power to PCIe Slot
        // Since this method is also used by the remapped devices to turn on power to the slot
        // this method should not make any access to the PCie config space.
        Method (PON) {
      
          // Disable WAKE
          If (CondRefOf (WAKG)) {
            \_SB.SHPO (WAKG, 1) // set gpio ownership to driver(0=ACPI mode, 1=GPIO mode)
            \_SB.CAGS (WAKG) // Clear GPIO Status if set.
          }
          If (CondRefOf (DHDW)) { // DG support HPD as D3 Wake GPIO and DHDW exists
            DHDW () // Disable Discrete Graphics HPD SCI implementated As D3 Wake GPIO
          }
      
          // Restore power to the modPHY (Only for PCH PCIE RP)
          If (LAnd (CondRefOf (PRTP), LEqual (PRTP, PCIE_RP_TYPE_PCH))) {
            \_SB.PSD0 (SLOT)
          }
      
          // Turn ON Power for PCIe Slot
          If (CondRefOf (PWRG)) {
            // Delay by 10 ms if required using WOFF
            If (CondRefOf (WOFF)) {
              If (LNotEqual (WOFF, Zero)) {
                Divide (Subtract (Timer (), WOFF), 10000, , Local0) // Store Elapsed time in ms, ignore remainder
                If (LLess (Local0, 200)) {                           // If Elapsed time is less than 20ms
                  Sleep (Subtract (200, Local0))                     // Sleep for the remaining time
                }
                Store (0, WOFF)
              }
            }
            \PIN.ON (PWRG)
            Sleep (PEP0)
          }
      
          //
          // On RTD3 Exit, BIOS will instruct the PMC to Enable source clocks.
          // This is done through sending a PMC IPC command if IPC Command is supported.
          //
          If (CondRefOf (SCLK)) {
            If(CondRefOf(TMCS)) {
              SPCX(SCLK, 1, TMCS)
            } Else {
              SPCO(SCLK, 1)
            }
          }
      
          // De-Assert Reset Pin
          \PIN.OFF (RSTG)
        }
      
        // Turn off power to PCIe Slot
        // Since this method is also used by the remapped devices to turn off power to the slot
        // this method should not make any access to the PCIe config space.
        Method (POFF) {
      
          // Assert Reset Pin after the delay passed from the bus driver
          Divide (LNRD, 1000, , Local1)
          Sleep (Local1)
      
          // Reset pin is mandatory for correct PCIe RTD3 flow
          \PIN.ON (RSTG)
      
          If (LAnd (CondRefOf (PRTP), LEqual (PRTP, PCIE_RP_TYPE_PCH))) {
            // Enable modPHY power gating
            // This must be done after the device has been put in reset
            \_SB.PSD3 (SLOT)
          }
      
          //
          // On RTD3 entry, BIOS will instruct the PMC to disable source clocks.
          // This is done through sending a PMC IPC command if IPC Command is supported.
          //
          If (CondRefOf (SCLK)) {
            If(CondRefOf(TMCS)) {
              SPCX(SCLK, 0, TMCS)
            } Else {
              SPCO(SCLK, 0)
            }
          }
      
          // Power OFF for Slot
          If (CondRefOf (PWRG)) {
            If ( LEqual ( GPPR(), 1)) { // we can safely disable power.
              \PIN.OFF (PWRG)
            }
            // Store current timestamp in WOFF
            If (CondRefOf (WOFF)) {
              Store (Timer (), WOFF)
            }
          }
      
          // enable WAKE
          If (CondRefOf (WAKG)) {
            If (LAnd (LNotEqual (WAKG, 0), WKEN)) {
              \_SB.SHPO (WAKG, 0)
            }
          }
          If (CondRefOf (EHDW)) { // DG support HPD as D3 Wake GPIO and DHDW exists
            EHDW () // Enable Discrete Graphics HPD SCI implementated As D3 Wake GPIO
          }
        }
      
        Method (_PR0) {
          Return (Package (){PXP})
        }
      
        Method (_PR3) {
          Return (Package (){PXP})
        }
      
        //
        // Update PERST# assertion delay.
        // This function will be called from reference code during PCIe _DSM function index 11 evaluation.
        // Arg0 - New delay value in microseconds. Max is 10ms
        //
        // @return Last sucessfully negotiated value in us. 0 if no such value exists.
        //
        Method (UPRD, 1, Serialized) {
          If (LLessEqual (Arg0, 10000)) {
            // If the value does not exceed the limit
            // Update last negotiated value and calculate the value in ms.
            Store (Arg0, LNRD)
          }
          Return (LNRD)
        }
      

    }

    ///
    /// PCIe RP09 RTD3 - PCH M.2 SSD RTD3
    ///
    Scope(\_SB.PC00.RP09) {
      Name(RSTG, Package() {0, 0})
      Store(SSDR, Index(RSTG, 0))
      Store(SDRP, Index(RSTG, 1))
      Name(PWRG, Package() {0, 0})
      Store(SSDP, Index(PWRG, 0))
      Store(SDPP, Index(PWRG, 1))
      Name(WAKG, 0)              // must be defined due to compiler bug, will be removed when fixed https://bugs.acpica.org/show_bug.cgi?id=1432
      Name(WAKP, 0)              // must be defined due to compiler bug, will be removed when fixed https://bugs.acpica.org/show_bug.cgi?id=1432
      Name(SCLK, 0)
      /**@file
        PCIe Root Port Generic PCIE Device Rtd3 file.
      
        Copyright (c) 2021 - 2022, Intel Corporation. All rights reserved.<BR>
        SPDX-License-Identifier: BSD-2-Clause-Patent
      **/
      
      /// @details
      /// Code in this file uses following variables:
      /// SCLK: ICC Clock number - optional
      /// WAKG: WAKE GPIO pad - optional
      /// Below objects should be defined according to the format described in PinDriverLib.asl
      /// RSTG: reset pin definition - mandatory
      /// PWRG: power GPIO pad - optional
      /// WAKP: Flag to indicate that power gating must not be performed if WAKE is enabled - optional
      /** @defgroup pcie_scope PCIe Root Port Scope **/
      
        //
        // AcpiPinDriverLib imports(from DSDT in platform)
        //
        External (\PIN.STA, MethodObj)
        External (\PIN.ON, MethodObj)
        External (\PIN.OFF, MethodObj)
        //
        // GpioLib imports(DSDT)
        //
        External (\_SB.SHPO, MethodObj)
      
        //
        // HSIO lib imports
        //
        External (\_SB.PSD0, MethodObj)
        External (\_SB.PSD3, MethodObj)
        External (DVES, MethodObj)
        External (DHDW, MethodObj)
        External (EHDW, MethodObj)
        External (D3HT, FieldUnitObj) // CPU PCIE RP Power State
        External (PCPB, IntObj) // PCIe core power veto bitmask, default 0 - allow for core power removal
        External (HBSL, FieldUnitObj)
        External (HBCL, FieldUnitObj)
        External (HBPL, FieldUnitObj)
        External (TMCS, IntObj)
      
        // WAKE enable on PCIe device.
        Name (WKEN, 0)
      
        // Last OFF Timestamp (WOFF): The time stamp of the last power resource _OFF method evaluation
        Name (WOFF, 0)
      
        Name (LNRD, 0) // Delay before PERST# assertion in us
      
        //
        // The deepest D-state supported by this device in the S0 system sleeping state where the device can wake itself,
        // "4" represents D3cold.
        //
        Method (_S0W, 0x0, NotSerialized)
        {
      
          If (CondRefOf (RD3C)) {
            If (LEqual (RD3C, 0x01)) {
              Return (0x4)
            }
          }
      
          Return (0x3)
        }
      
        //
        // Device Sleep Wake - sets the sleep and wake transition states for a device.
        // ACPI Specification Defined Method. Called by OSPM.
        //
        Method (_DSW, 3, NotSerialized)
        {
          /// This method is used to enable/disable wake from PCIe (WKEN)
      
          If (Arg1)
          { /// If entering Sx, enable Sx WAKE
            Store (1, WKEN)
          } Else {  /// If Staying in S0
            If (LAnd(Arg0, Arg2)) ///- Check if Exiting D0 and arming for wake
            { ///- Set PME
              Store (1, WKEN)
            } Else { ///- Disable runtime PME, either because staying in D0 or disabling wake
              Store (0, WKEN)
            }
          }
        /** @defgroup pcie_dsw PCIE _DSW **/
        } // End _DSW
      
        Method (PPS0, 0, Serialized) { // Platform specific PCIe root port _PS0 Hook Function.
        }
      
        Method (PPS3, 0, Serialized) { // Platform specific PCIe root port _PS3 Hook Function.
        }
      
        //
        // PCIe slot power resource definition
        //
        PowerResource (PXP, 0, 0) {
      
          Method (_STA, 0) {
      
            //
            // Check if PCIE RP is available or Not by Checking Vendor and Device ID.
            //
            If (LEqual (VDID, 0xFFFFFFFF)) {
              Return (0)
            }
      
            //
            // Check if PCIE RP Power Resource is supported or Not.
            //
            If (LEqual (GPRS (), 0)) {
              Return (0)
            }
      
            //
            // Return PCIE RP Power Resource Status.
            //
            Return (PSTA ())
          }
      
          Method (_ON) {
      
            //
            // Check if PCIE RP is available or Not by Checking Vendor and Device ID.
            //
            If (LEqual (VDID, 0xFFFFFFFF)) {
              Return ()
            }
      
            //
            // Check if PCIE RP Power Resource is supported or Not.
            //
            If (LEqual (GPRS (), 0)) {
              Return ()
            }
      
            //
            // Turn on slot power
            //
            PON ()
      
            //
            // Trigger L2/L3 ready exit flow in rootport - transition link to Detect
            //
            L23D ()
          }
      
          Method (_OFF) {
      
            //
            // Check if PCIE RP is available or Not by Checking Vendor and Device ID.
            //
            If (LEqual (VDID, 0xFFFFFFFF)) {
              Return ()
            }
      
            //
            // Check if PCIE RP Power Resource is supported or Not.
            //
            If (LEqual (GPRS (), 0)) {
              Return ()
            }
      
            //
            // Trigger L2/L3 ready entry flow in rootport
            //
            DL23 ()
      
            //
            // Turn off slot power
            //
            POFF ()
          }
        } // End PowerResource
      
        //
        // Get Permission for Power Removal.
        // Check whether or not to Disable Power Package GPIO During Device Power OFF(D3 Cold Transition).
        // Input: VOID
        //
        // @return 1 if it is Safe to Remove/Disable Power. 0 Not allow for Power Removal.
        //
        Method (GPPR, 0) {
      
          // If WAKP has not been defined we can safely disable power.
          // If WAKP is defined this slot does not supply device with auxilary power and we have to keep primary power
          // to allow for WAKE. If WAKP is not equal to 0 and WKEN has been enabled do not disable the power.
          If (CondRefOf (WAKP)) {
            If (LAnd (LNotEqual (WAKP, 0), LEqual (WKEN, 0))) {
              Return (0)
            }
          }
      
          //
          // If PCPB has not been defined we can safely disable power.
          // If PCPB is defined and non Zero we have to keep primary power.
          //
          If (CondRefOf (PCPB)) {
            If (LNotEqual (PCPB, 0)) {
              Return (0)
            }
          }
      
          //
          // If DVES Method has not been defined we can safely disable power.
          // If DVES Method is defined and return Zero value we have to keep primary power.
          //
          If (CondRefOf (DVES)) {
            If (LEqual (DVES (), 0)) {
              Return (0)
            }
          }
      
          //
          // Now Safe To Remove/Disable Power.
          //
          Return (1)
        }
      
        //
        // Get PCIe RP Power Resource Support.
        // If D3 Cold is supported by PCIE RP or Not.
        // Input: VOID
        //
        // @return 1 PCIE RP Power Resource Supported. 0 PCIE RP Power Resource Not Supported.
        //
        Method (GPRS, 0) {
      
          If (LAnd (CondRefOf (PRTP), LEqual (PRTP, PCIE_RP_TYPE_CPU))) {
      
            //
            // Check for Hybrid Connection Status for PCIE RP and for single CPU M.2 with x2 MUX
            //
            If (CondRefOf (HBCL)) {
              If (LOr(LNotEqual(HBCL, 0xFF), LLessEqual(HBCL, 0x2))) {
                If (LEqual (HBCL, SLOT)) {
                  Return (0)
                }
              }
            }
          }
      
          //
          // Check for Hybrid Connection Status for PCIE RP and for single CPU M.2 with x2 MUX
          //
          If (LAnd (CondRefOf (PRTP), LEqual (PRTP, PCIE_RP_TYPE_PCH))) {
            If (CondRefOf (HBSL)) {
              Divide ( Subtract (SLOT, 1), 4, , Local0) // Get PCIE RP Controller Number ( (SLOT-1)/4)
              // Check if Hybrid Connection Status BIT Corresponding to Controller Number is SET or NOT.
              If ( And (HBSL, ShiftLeft (BIT0, Local0))) {
                Return (0)
              }
            }
      
            If (LAnd(CondRefOf (HBCL), CondRefOf (HBPL))) {
              If (LOr(LNotEqual(HBCL, 0xFF), LLessEqual(HBCL, 0x2))) {
                If (LEqual (HBPL, Subtract(SLOT, 1))) {
                  Return (0)
                }
              }
            }
      
          }
      
          //
          // Check if D3 Cold is supported for PCIE RP.
          //
          If (CondRefOf (RD3C)) {
            If (LNotEqual (RD3C, 0)) {
              Return (0)
            }
          }
      
          //
          // Check if PCIE RP is Mapped under VMD. D3 Cold flow will be taken care by VMD and it's Child ACPI Devices.
          //
          If (CondRefOf (PRMV)) {
            If (LEqual (PRMV, 1)) {
              Return (0)
            }
          }
      
          //
          // D3 Cold is supported for PCIE RP
          //
          Return (1)
        }
      
        //
        // Returns the status of PCIe slot core power.
        //
        Method (PSTA, 0) {
      
          //
          // RESET# assertion is mandatory for PCIe RTD3
          // So if RESET# is asserted the whole slot is off
          //
          If (\PIN.STA (RSTG)) {
            Return (0)
          } Else {
            Return (1)
          }
        }
      
        // Turn on power to PCIe Slot
        // Since this method is also used by the remapped devices to turn on power to the slot
        // this method should not make any access to the PCie config space.
        Method (PON) {
      
          // Disable WAKE
          If (CondRefOf (WAKG)) {
            \_SB.SHPO (WAKG, 1) // set gpio ownership to driver(0=ACPI mode, 1=GPIO mode)
            \_SB.CAGS (WAKG) // Clear GPIO Status if set.
          }
          If (CondRefOf (DHDW)) { // DG support HPD as D3 Wake GPIO and DHDW exists
            DHDW () // Disable Discrete Graphics HPD SCI implementated As D3 Wake GPIO
          }
      
          // Restore power to the modPHY (Only for PCH PCIE RP)
          If (LAnd (CondRefOf (PRTP), LEqual (PRTP, PCIE_RP_TYPE_PCH))) {
            \_SB.PSD0 (SLOT)
          }
      
          // Turn ON Power for PCIe Slot
          If (CondRefOf (PWRG)) {
            // Delay by 10 ms if required using WOFF
            If (CondRefOf (WOFF)) {
              If (LNotEqual (WOFF, Zero)) {
                Divide (Subtract (Timer (), WOFF), 10000, , Local0) // Store Elapsed time in ms, ignore remainder
                If (LLess (Local0, 200)) {                           // If Elapsed time is less than 20ms
                  Sleep (Subtract (200, Local0))                     // Sleep for the remaining time
                }
                Store (0, WOFF)
              }
            }
            \PIN.ON (PWRG)
            Sleep (PEP0)
          }
      
          //
          // On RTD3 Exit, BIOS will instruct the PMC to Enable source clocks.
          // This is done through sending a PMC IPC command if IPC Command is supported.
          //
          If (CondRefOf (SCLK)) {
            If(CondRefOf(TMCS)) {
              SPCX(SCLK, 1, TMCS)
            } Else {
              SPCO(SCLK, 1)
            }
          }
      
          // De-Assert Reset Pin
          \PIN.OFF (RSTG)
        }
      
        // Turn off power to PCIe Slot
        // Since this method is also used by the remapped devices to turn off power to the slot
        // this method should not make any access to the PCIe config space.
        Method (POFF) {
      
          // Assert Reset Pin after the delay passed from the bus driver
          Divide (LNRD, 1000, , Local1)
          Sleep (Local1)
      
          // Reset pin is mandatory for correct PCIe RTD3 flow
          \PIN.ON (RSTG)
      
          If (LAnd (CondRefOf (PRTP), LEqual (PRTP, PCIE_RP_TYPE_PCH))) {
            // Enable modPHY power gating
            // This must be done after the device has been put in reset
            \_SB.PSD3 (SLOT)
          }
      
          //
          // On RTD3 entry, BIOS will instruct the PMC to disable source clocks.
          // This is done through sending a PMC IPC command if IPC Command is supported.
          //
          If (CondRefOf (SCLK)) {
            If(CondRefOf(TMCS)) {
              SPCX(SCLK, 0, TMCS)
            } Else {
              SPCO(SCLK, 0)
            }
          }
      
          // Power OFF for Slot
          If (CondRefOf (PWRG)) {
            If ( LEqual ( GPPR(), 1)) { // we can safely disable power.
              \PIN.OFF (PWRG)
            }
            // Store current timestamp in WOFF
            If (CondRefOf (WOFF)) {
              Store (Timer (), WOFF)
            }
          }
      
          // enable WAKE
          If (CondRefOf (WAKG)) {
            If (LAnd (LNotEqual (WAKG, 0), WKEN)) {
              \_SB.SHPO (WAKG, 0)
            }
          }
          If (CondRefOf (EHDW)) { // DG support HPD as D3 Wake GPIO and DHDW exists
            EHDW () // Enable Discrete Graphics HPD SCI implementated As D3 Wake GPIO
          }
        }
      
        Method (_PR0) {
          Return (Package (){PXP})
        }
      
        Method (_PR3) {
          Return (Package (){PXP})
        }
      
        //
        // Update PERST# assertion delay.
        // This function will be called from reference code during PCIe _DSM function index 11 evaluation.
        // Arg0 - New delay value in microseconds. Max is 10ms
        //
        // @return Last sucessfully negotiated value in us. 0 if no such value exists.
        //
        Method (UPRD, 1, Serialized) {
          If (LLessEqual (Arg0, 10000)) {
            // If the value does not exceed the limit
            // Update last negotiated value and calculate the value in ms.
            Store (Arg0, LNRD)
          }
          Return (LNRD)
        }
      

      Scope(\_SB.PC00.RP09.PXSX) {
        /**@file
          ACPI RTD3 Hook SSDT Library for Generic Pcie Rp with End Point as M.2 SSD/Storage Device.
        
          Copyright (c) 2021 - 2022, Intel Corporation. All rights reserved.<BR>
          SPDX-License-Identifier: BSD-2-Clause-Patent
        **/
        
        //
        // This code should be included in the scope of the PCIe root port that is connected to the M.2 slot
        //
          External (PAHC, MethodObj) // Checks if the connected device is AHCI drive
          External (PNVM, MethodObj) // Checks if the connected device is NVME drive
        
          //
          // The deepest D-state supported by this device in the S0 system sleeping state where the device can wake itself,
          // "4" represents D3cold.
          //
          Method (_S0W, 0x0, NotSerialized)
          {
        
            If (CondRefOf (^^RD3C)) {
              If (LEqual (^^RD3C, 0x01)) {
                Return (0x4)
              }
            }
        
            Return (0x3)
          }
        
          //
          // PCIe D3Cold support hacks ACPI specification in order to work around bug in Windows PCIe driver.
          // For storage we want to return power resources from root port's _PR0 so that we won't get unexpected D3Cold entry.
          //
          Method (_PR0, Zero, NotSerialized, 0, PkgObj){
            Return (^^_PR0 ())
          }
          Method (_PR3, Zero, NotSerialized, 0, PkgObj){
            Return (^^_PR0 ())
          }
        
          Method (_PS0, 0, Serialized){
          }
        
          Method (_PS3, 0, Serialized){
          }
        
          Device (MINI){
            Method (_STA, 0, Serialized){
              If (CondRefOf (PAHC)) {
                If (PAHC ()){
                  Return (0x0F)
                }
              }
              Return (0)
            }
        
            //
            // Declare MINI device as a SATA drive connected to the port 0 of the SATA controller
            //
            Name (_ADR, 0x0000FFFF)
            Name (_S0W, 0x04)
        
            Method (_PS0, 0, Serialized){
            }
        
            Method (_PS3, 0, Serialized){
            }
        
            //
            // PCIe D3Cold support hacks ACPI specification in order to work around bug in Windows PCIe driver.
            // For storage we want to return power resources from root port's _PR0 so that we won't get unexpected D3Cold entry.
            //
            Method (_PR0, Zero, NotSerialized, 0, PkgObj){
              Return (^^^_PR0 ())
            }
            Method (_PR3, Zero, NotSerialized, 0, PkgObj){
              Return (^^^_PR0 ())
            }
        
          }

      }
    }

// PCIe root ports - END

//
// SATA - START
//
  Scope(\_SB.PC00.SAT0) {
    Scope(PRT0) {
      If (PRES ()) {
        Name(PWRG, Package() {0, 0})
        Store(SATP, Index(PWRG, 0))
        Store(STPP, Index(PWRG, 1))
      }
    }

  }


//
// USB - START
//

//
// XDCI - start
//
  If(LEqual(XDCE,1)) {
    Scope(\_SB)
    {
      //
      // Dummy power resource for USB D3 cold support
      //
      PowerResource(USBC, 0, 0)
      {
        Method(_STA) { Return (0xF) }
        Method(_ON) {}
        Method(_OFF) {}
      }
    }

    Scope(\_SB.PC00.XDCI)
    {
      OperationRegion (GENR, SystemMemory, Add(And(XDCB, 0xFFFFFFFFFFFFFF00), 0x10F81C), 0x4)  //AON MMIO - 10F81C: APBFC_U3PMU_CFG5
      Field (GENR, WordAcc, NoLock, Preserve)
      {
            ,   2,
        CPME,   1,    //bit2 core_pme_en
        U3EN,   1,    //bit3 u3_pme_en
        U2EN,   1     //bit4 u2_pme_en
      }

      Method (_PS3, 0, NotSerialized)
      {
        Store (One, CPME)
        Store (One, U2EN)
        Store (One, U3EN)

        \_SB.CSD3(MODPHY_SPD_GATING_XDCI)
      }
      Method (_PS0, 0, NotSerialized)
      {
        Store (Zero, CPME)
        Store (Zero, U2EN)
        Store (Zero, U3EN)

        If(LEqual(DVID,0xFFFF)) {
          Return()
        }

        \_SB.CSD0(MODPHY_SPD_GATING_XDCI)
      }

      Method (_RMV, 0, NotSerialized)  // _RMV: Removal Status
      {
        Return (Zero)
      }

      Method (_PR3, 0, NotSerialized)  // _PR3: Power Resources for D3hot
      {
        Return (Package (0x01)
        {
          USBC // return dummy package
        })
      }
    } // Scope(\_SB.PC00.XDCI)
  } // XDCE
//
// XDCI - end
//

//
// USB - END
//

If (LNotEqual(GBES,0)) {
  Scope(\_SB.PC00.GLAN)
  {
    Method (_PS3, 0, NotSerialized)
    {
      \_SB.CSD3(MODPHY_SPD_GATING_GBE)
    }
    Method (_PS0, 0, NotSerialized)
    {
      If(LNot(GBED)){  // If GBE_FDIS_PMC == 0
        \_SB.CSD0(MODPHY_SPD_GATING_GBE)
      }
    }
  } // Scope(\_SB.PC00.GLAN)
}

//
// Human Interface Devices Start
//

//

//
// PCH I2C0 - TouchPad Power control
//
    Scope(\_SB.PC00.I2C0){

      Method(PS0X,0,Serialized)
      {
      }
      /// PS3X Method, called by PS3 method in PchSerialIo.asl
      Method(PS3X,0,Serialized)
      {
      }
      /// \ref i2c0_pr_pxtc
      ///@defgroup i2c0_scope  I2C1 Scope
      If (LNotEqual(TPDT,0)) {
      PowerResource(PXTC, 0, 0){
        Method(_STA){
          Return(PSTA(0))
        }

        Method(_ON){
          PON(0)
        }

        Method(_OFF){
          POFF(0)
        }
      } // End PXTC
      }
      /// \ref i2c0_pr_ptpl
      ///@defgroup i2c0_scope
      If (LNotEqual(TPLT,0)) {
      PowerResource(PTPL, 0, 0){
        Method(_STA){
          Return(PSTA(1))
        }

        Method(_ON){
          PON(1)
        }

        Method(_OFF){
          POFF(1)
          }
        }
      }
      /// Variable:
      Name(ONTM, 0) ///ONTM: 0 - Not in Speculative ON ; Non-Zero - elapsed time in Nanosecs after Physical ON
      Method(PSTA, 1, Serialized){
        If (Arg0 == 0) {
          Return(0x01)
        }
        If (Arg0 == 1) {
          If(LEqual(\_SB.GGOV(GPLP), 1)) {
            Return(0x01)
          } Else {
            Return(0x00)
          }
        }
        Return(0x00)
      }
      // Timing of Power and Reset for I2C Touch Panel
      //  _____________________________________________________________________________________________________
      // | minimum required time |  Reset de-assert from Power On (ms)   |     Power Off from Reset assert (ms)|
      // |_______________________|_______________________________________|_____________________________________|
      // | current setting       |                2                      |                3                    |
      // |_______________________|_______________________________________|_____________________________________|
      // * no maximum time limitation.
      Method(PON, 1, Serialized) /// _ON Method \n Turn on
      {
        If (Arg0 == 0) {
          // enable int line
          \_SB.SGRA(GPDI, PPDI)
        }
        ElseIf (Arg0 == 1) {
        // drive pwr high
        \_SB.SGOV(GPLP, PPLP)
        Sleep(2)                  // time for Reset de-assert from Power On
          // De-Assert GPIO RST
        \_SB.SGOV(GPLR, PPLR)
          // update ONTM
          Store(Timer(), ONTM)
          // enable int line
        \_SB.SGRA(GPLI, PPLI)
        }
      }

      Method(POFF, 1, Serialized)  /// _OFF method \n Turn off
      {
        If (Arg0 == 0) {
          // disable int line
          Xor(PPDI, 1, Local0)
          \_SB.SGRA(GPDI, Local0)
        }
        ElseIf (Arg0 == 1) {
          // disable int line
        Xor(PPLI, 1, Local0)
        \_SB.SGRA(GPLI, Local0)
        // Assert GPIO RST
        Xor(PPLR, 1, Local0)
        \_SB.SGOV(GPLR, Local0)
        Sleep(3)                   // time for Power Off from Reset assert
        // drive pwr low
        Xor(PPLP, 1, Local0)
        \_SB.SGOV(GPLP, Local0)
          // update ONTM
          Store(Zero , ONTM)  ///- Clear ONTM
        }
      }

      If (LNotEqual(TPDT,0)) {
      Scope(TPD0){
        Name (TD_P, Package(){\_SB.PC00.I2C0.PXTC})               // TD_P - Touch Device Power Package

        Alias(IC0D, TD_D)                                         // TD_D - Touch Device power on delay
        Alias(\_SB.PC00.I2C0.ONTM, TD_C)                     // TD_C - Touch Device I2C controller power on timestamp


        Method(_PS0) { PS0X() }
        Method(_PS3) { PS3X() }
      }// End Of Scope(TPD0)
     }

      If (LNotEqual(TPLT,0)) {
        Scope(TPL1){
          Name (TD_P, Package(){\_SB.PC00.I2C0.PTPL})               // TD_P - Touch Device Power Package

          Alias(IC1D, TD_D)                                         // TD_D - Touch Device power on delay
          Alias(\_SB.PC00.I2C0.ONTM, TD_C)                          // TD_C - Touch Device I2C controller power on timestamp


          Method(_PS0) { PS0X() }
          Method(_PS3) { PS3X() }
        }// End Of Scope(TPL1)
      }
    } //  Scope(\_SB.PC00.I2C0)

//
    //Power Resource for Audio Codec
    Scope(\_SB.PC00)
    {
      PowerResource(PAUD, 0, 0) {
        /// Namespace variable used:
        Name(PSTA, One) /// PSTA: Physical Power Status of Codec 0 - OFF; 1-ON
        Name(ONTM, Zero) /// ONTM: 0 - Not in Speculative ON ; Non-Zero - elapsed time in Nanosecs after Physical ON

        Name(_STA, One) /// _STA: PowerResource Logical Status 0 - OFF; 1-ON

        ///@defgroup pr_paud Power Resource for onboard Audio CODEC

        Method(_ON, 0){     /// _ON method \n
          Store(One, _STA)        ///- Set Logocal power state
          PUAM() ///- Call PUAM() to tansition Physical state to match current logical state
                    ///@addtogroup pr_paud
        } // End _ON

        Method(_OFF, 0){    /// _OFF method \n
          Store(Zero, _STA)    ///- Set the current power state
          PUAM() ///- Call PUAM() to tansition Physical state to match current logical state
        ///@addtogroup pr_paud
        } // End _OFF

        ///  PUAM - Power Resource User Absent Mode for onboard Audio CODEC
        ///  Arguments:
        ///
        ///  Uses:
        ///      _STA - Variable updated by Power Resource _ON/_OFF methods \n
        ///      \\UAMS - Variable updated by GUAM method to show User absent present \n
        ///      ONTM - Local variable to store ON time during Speculative ON \n
        /// ______________________________
        // |  Inputs      |   Outputs    |
        // ______________________________
        // | _STA | \UAMS | GPIO | ONTM |
        // ______________________________
        // |   1  |   0   | ON   |   !0 |
        // |   1  |   !0  | ON   |   !0 |
        // |   0  |   0   | ON   |   !0 |
        // |   0  |   !0  | OFF  |   0  |
        // ______________________________
                    /**
                    <table>
                    <tr> <th colspan="2"> Inputs <th colspan="2"> Output
                    <tr> <th>_STA <th> \\UAMS <th> GPIO <th>ONTM
                    <tr> <td>1 <td>0 <td>ON <td>!0
                    <tr> <td>1 <td>!0<td>ON <td>!0
                    <tr> <td>0 <td>0 <td>ON <td>!0
                    <tr> <td>0 <td>!0<td>OFF<td> 0
                    </table>
                    **/
        ///@addtogroup pr_paud_puam
        Method(PUAM, 0, Serialized)
        {
                // power rail = NOT there for ICL U
                // Note:- Audio Power enable need not be implemented by default and need rework if we need power control.
          If (LAnd(LEqual(^_STA, Zero), LNotEqual(\UAMS, Zero))) { ///New state = OFF Check if (_STA ==0 && \UAMS != 0) \n
          } Else { /// New state = ON (_STA=1) or (_STA=0 and \UAMS=0)
            /// Turn power on \n
            If(LNotEqual(^PSTA, One)) { ///- Skip below if Power Resource is already in ON
              Store(One, ^PSTA)  ///- >> Set PSTA to 1
              Store(Timer(), ^ONTM) ///- >> Start the timer for this PR
            }
          }
        ///@defgroup pr_paud_puam Power Resource User Absent Mode for onboard Audio CODEC
        } //PUAM
      } //PAUD
    } //Scope(\_SB.PC00)

//
// Check HDAS (HD-Audio) controller present
//
    If(LNotEqual(\_SB.PC00.HDAS.VDID, 0xFFFFFFFF)) {
      Scope(\_SB.PC00.HDAS) {
        Method(PS0X,0,Serialized)     /// Platform D0 Method for HD-A Controller
        {
          If(LEqual(\_SB.PC00.PAUD.ONTM, Zero)){    ///- Check if ONTM=0
            Return()
          }

          ///
          ///- Make sure "D0 delay" (AUDD) delay is elapsed before returning _PS0
          ///- Local0: Elapse time since the _ON method
          ///- VRRD: VR Rampup Delay
          ///- AUDD: Time required for device to be ready after power on
          ///- Local1 = AUDD + VRRD: Need to incorporate VRRD since the _ON method no longer has VR Rampup Delay
          ///- So only need sleep for (Local1 - Local0), the amount of time remaining since the _ON method
          ///
          Divide(Subtract(Timer(), \_SB.PC00.PAUD.ONTM), 10000, , Local0) ///- Store Elapsed time in ms, ignore remainder
          Add(AUDD, VRRD, Local1) ///- Incorporate VR Rampup Delay
          If(LLess(Local0, Local1)) { ///- Do not sleep if already past the delay requirement audio
            ///- Delay for device init
            Sleep(Subtract(Local1, Local0)) ///- Sleep (AUDD + VRRD - time elapsed)
          }
        }

        ///Associate _PR0 with \ref pr_paud
        Name(_PR0, Package(){\_SB.PC00.PAUD})
      ///@defgroup hdef_scope       Intel High Definition Audio Scope
      }
    }// If(LNotEqual(\_SB.PC00.HDAS.VDID, 0xFFFFFFFF))
//GPE Event handling - Start
  Scope(\_GPE) {
    //
    // Alternate _L6F(), to handle 2-tier RTD3 GPE events here
    //
    Method(AL6F) {
      // WLAN wake event
      If (\_SB.ISME(WLWK))
      {
        \_SB.SHPO(WLWK, 1) // set gpio ownership to driver(0=ACPI mode, 1=GPIO mode)
        Notify(\_SB.PC00.RP04, 0x02)      // device wake
        \_SB.CAGS(WLWK)    // WIFI_WAKE_N
      }

      //Wwan wake event
      If (\_SB.ISME(WWKP))
      {
        \_SB.SHPO(WWKP, 1) // set gpio ownership to driver(0=ACPI mode, 1=GPIO mode)
        Notify(WWAN_PCIE_ROOT_PORT, 0x02)     // device wake
        \_SB.CAGS(WWKP)    // WWAN_WAKE_N
      }

      //Pcie x1 DT slot wake event
      If (\_SB.ISME(PSWP))
      {
        \_SB.SHPO(PSWP, 1) // set gpio ownership to driver(0=ACPI mode, 1=GPIO mode)
        Notify(\_SB.PC00.RP07, 0x02)      // device wake
        \_SB.CAGS(PSWP)
      }
    }
  } //Scope(\_GPE)
//GPE Event handling - End
} // End SSDT
