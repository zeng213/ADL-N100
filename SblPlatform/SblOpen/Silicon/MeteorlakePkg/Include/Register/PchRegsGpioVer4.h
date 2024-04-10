/** @file
  Register names for Ver4 GPIO

  Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/
#ifndef _PCH_REGS_GPIO_VER4_H_
#define _PCH_REGS_GPIO_VER4_H_

//MTL-M, SOC-M GPIO registers
//
//
// GPIO Community Common Private Configuration Registers
//
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_V   0x0
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_C   0x1
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_A   0x2
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_E   0x3
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_H   0x4
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_F   0x5
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_USB     0x6
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_VGPIO   0x7
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_S   0x8
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_B   0x9
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_D   0xA
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_CPU     0xF
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_SPI_SYS 0xF
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_JTAG    0xF

//
// PCH-S GPIO
//
#define GPIO_VER4_PCH_S_GPIO_GROUP_MAX        19


//VER6
//
// SoC-M GPIO
//
#define GPIO_VER6_SOC_M_GPIO_GROUP_MAX        14

// COM0
#define GPIO_VER6_SOC_M_CPU_PAD_MAX            5
#define GPIO_VER6_SOC_M_GPP_V_PAD_MAX         24
#define GPIO_VER6_SOC_M_GPP_C_PAD_MAX         24
// COM1
#define GPIO_VER6_SOC_M_GPP_A_PAD_MAX         25
#define GPIO_VER6_SOC_M_GPP_E_PAD_MAX         25
// COM2
// COM3
#define GPIO_VER6_SOC_M_GPP_H_PAD_MAX         26
#define GPIO_VER6_SOC_M_GPP_F_PAD_MAX         26
#define GPIO_VER6_SOC_M_SPI_SYS_PAD_MAX       15
#define GPIO_VER6_SOC_M_USB_THC_PAD_MAX       14
// COM4
#define GPIO_VER6_SOC_M_GPP_S_PAD_MAX          8
#define GPIO_VER6_SOC_M_JTAG_PAD_MAX          12
// COM5
#define GPIO_VER6_SOC_M_GPP_B_PAD_MAX         25
#define GPIO_VER6_SOC_M_GPP_D_PAD_MAX         25
#define GPIO_VER6_SOC_M_VGPIO_PAD_MAX         35


//
// SoC-M GPIO registers
//
//
// GPIO Community Common Private Configuration Registers
//
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_V   0x0
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_C   0x1
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_A   0x2
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_E   0x3
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_H   0x4
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_F   0x5
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_USB     0x6
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_VGPIO   0x7
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_S   0x8
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_B   0x9
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_GPP_D   0xA
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_CPU     0xF
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_SPI_SYS 0xF
#define V_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG_GPE0_JTAG    0xF

//
// GPIO all communities common offsets
//
#define R_GPIO_VER6_SOC_M_GPIO_PCR_MISCCFG                  0x0010

//
// GPIO Community 0 Private Configuration Registers
//
#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_PAD_OWN              0x00B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_PAD_OWN            0x00B4
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_PAD_OWN            0x00C0

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_PADCFGLOCK           0x0110
#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_PADCFGLOCKTX         0x0114
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_PADCFGLOCK         0x0118
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_PADCFGLOCKTX       0x011c
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_PADCFGLOCK         0x0120
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_PADCFGLOCKTX       0x0124

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_HOSTSW_OWN           0x0140
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_HOSTSW_OWN         0x0144
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_HOSTSW_OWN         0x0148

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_GPI_IS               0x0200
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_GPI_IS             0x0204
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_GPI_IS             0x0208

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_GPI_IE               0x0210
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_GPI_IE             0x0214
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_GPI_IE             0x0218

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_GPI_GPE_STS          0x0230
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_GPI_GPE_STS        0x0234
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_GPI_GPE_STS        0x0238

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_GPI_GPE_EN           0x0250
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_GPI_GPE_EN         0x0254
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_GPI_GPE_EN         0x0258

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_I_SMI_STS            0x0270
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_I_SMI_STS          0x0274
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_I_SMI_STS          0x0278

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_I_SMI_EN             0x0290
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_I_SMI_EN           0x0294
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_I_SMI_EN           0x0298

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_NMI_STS              0x02B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_NMI_STS            0x02B4
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_NMI_STS            0x02B8

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_NMI_EN               0x02D0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_NMI_EN             0x02D4
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_NMI_EN             0x02D8

#define R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_PADCFG_OFFSET        0x0600
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_PADCFG_OFFSET      0x0650
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_PADCFG_OFFSET      0x07D0

//
// GPIO Community 1 Private Configuration Registers
//
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_PAD_OWN            0x00B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_PAD_OWN            0x00C0

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_PADCFGLOCK         0x0110
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_PADCFGLOCKTX       0x0114
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_PADCFGLOCK         0x0118
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_PADCFGLOCKTX       0x011C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_HOSTSW_OWN       0x0140
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_HOSTSW_OWN       0x0144

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_GPI_IS           0x0200
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_GPI_IS           0x0204

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_GPI_IE           0x0210
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_GPI_IE           0x0214

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_GPI_GPE_STS      0x0230
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_GPI_GPE_STS      0x0234

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_GPI_GPE_EN       0x0250
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_GPI_GPE_EN       0x0254

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_SMI_STS          0x0270
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_SMI_STS          0x0274

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_SMI_EN           0x0290
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_SMI_EN           0x0294

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_NMI_STS          0x02B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_NMI_STS          0x02B4

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_NMI_EN           0x02D0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_NMI_EN           0x02D4

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_PADCFG_OFFSET    0x0600
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_PADCFG_OFFSET    0x0790

//
// GPIO Community 2 Private Configuration Registers
//
//
// GPIO Community 3 Private Configuration Registers
//
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_PAD_OWN          0x00B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_PAD_OWN          0x00C0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_PAD_OWN            0x00D0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_PAD_OWN          0x00D8

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_PADCFGLOCK       0x0110
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_PADCFGLOCKTX     0x0114
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_PADCFGLOCK       0x0118
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_PADCFGLOCKTX     0x011C
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_PADCFGLOCK         0x0120
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_PADCFGLOCKTX       0x0124
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_PADCFGLOCK       0x0128
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_PADCFGLOCKTX     0x012C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_HOSTSW_OWN       0x0140
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_HOSTSW_OWN       0x0144
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_HOSTSW_OWN         0x0148
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_HOSTSW_OWN       0x014C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_GPI_IS           0x0200
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_GPI_IS           0x0204
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_GPI_IS             0x0208
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_GPI_IS           0x020C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_GPI_IE           0x0210
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_GPI_IE           0x0214
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_GPI_IE             0x0218
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_GPI_IE           0x021C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_GPI_GPE_STS      0x0230
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_GPI_GPE_STS      0x0234
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_GPI_GPE_STS        0x0238
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_GPI_GPE_STS      0x023C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_GPI_GPE_EN       0x0250
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_GPI_GPE_EN       0x0254
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_GPI_GPE_EN         0x0258
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_GPI_GPE_EN       0x025C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_SMI_STS          0x0270
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_SMI_STS          0x0274
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_SMI_STS            0x0278
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_SMI_STS          0x027C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_SMI_EN           0x0290
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_SMI_EN           0x0294
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_SMI_EN             0x0298
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_SMI_EN           0x029C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_NMI_STS          0x02B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_NMI_STS          0x02B4
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_NMI_STS            0x02B8
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_NMI_STS          0x02BC

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_NMI_EN           0x02D0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_NMI_EN           0x02D4
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_NMI_EN             0x02D8
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_NMI_EN           0x02DC

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_PADCFG_OFFSET    0x0600
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_PADCFG_OFFSET    0x07A0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_PADCFG_OFFSET      0x0940
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_PADCFG_OFFSET    0x0A30

//
// GPIO Community 4 Private Configuration Registers
//
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_PAD_OWN          0x00B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_PAD_OWN           0x00B4

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_PADCFGLOCK       0x0110
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_PADCFGLOCKTX     0x0114
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_PADCFGLOCK        0x0118
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_PADCFGLOCKTX      0x011C

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_HOSTSW_OWN       0x0140
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_HOSTSW_OWN        0x0144

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_GPI_IS           0x0200
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_GPI_IS            0x0204

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_GPI_IE           0x0210
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_GPI_IE            0x0214

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_GPI_GPE_STS      0x0230
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_GPI_GPE_STS       0x0234

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_GPI_GPE_EN       0x0250
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_GPI_GPE_EN        0x0254

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_SMI_STS          0x0270
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_SMI_STS           0x0274

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_SMI_EN           0x0290
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_SMI_EN            0x0294

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_NMI_STS          0x02B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_NMI_STS           0x02B4

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_NMI_EN           0x02D0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_NMI_EN            0x02D4

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_PADCFG_OFFSET    0x0600
#define R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_PADCFG_OFFSET     0x0680

//
// GPIO Community 5 Private Configuration Registers
//
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_PAD_OWN          0x00B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_PAD_OWN          0x00C0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_PAD_OWN         0x00D0

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_PADCFGLOCK       0x0110
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_PADCFGLOCKTX     0x0114
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_PADCFGLOCK       0x0118
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_PADCFGLOCKTX     0x011C
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VPGIO5_PADCFGLOCK      0x0120
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_PADCFGLOCKTX    0x0124

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_HOSTSW_OWN       0x0140
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_HOSTSW_OWN       0x0144
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_HOSTSW_OWN      0x0148

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_GPI_IS           0x0200
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_GPI_IS           0x0204
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_GPI_IS          0x0208

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_GPI_IE           0x0210
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_GPI_IE           0x0214
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_GPI_IE          0x0218

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_GPI_GPE_STS      0x0230
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_GPI_GPE_STS      0x0234
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_GPI_GPE_STS     0x0238

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_GPI_GPE_EN       0x0250
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_GPI_GPE_EN       0x0254
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_GPI_GPE_EN      0x0258

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_SMI_STS          0x0270
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_SMI_STS          0x0274
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_SMI_STS         0x0278

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_SMI_EN           0x0290
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_SMI_EN           0x0294
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_SMI_EN          0x0298

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_NMI_STS          0x02B0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_NMI_STS          0x02B4
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_NMI_STS         0x02B8

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_NMI_EN           0x02D0
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_NMI_EN           0x02D4
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_NMI_EN          0x02D8

#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_PADCFG_OFFSET    0x0600
#define R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_PADCFG_OFFSET    0x0790
#define R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_PADCFG_OFFSET   0x0920

//
// SoC-S GPIO
//
#define GPIO_VER6_SOC_S_GPIO_GROUP_MAX         8

// COM0
#define GPIO_VER6_SOC_S_GPP_A_PAD_MAX         28
#define GPIO_VER6_SOC_S_GPP_C_PAD_MAX         27
#define GPIO_VER6_SOC_S_VGPIO_0_PAD_MAX        6
// COM1
#define GPIO_VER6_SOC_S_GPP_B_PAD_MAX         20
#define GPIO_VER6_SOC_S_VGPIO_3_PAD_MAX        7
#define GPIO_VER6_SOC_S_GPP_D_PAD_MAX         24
// COM2
// COM3
#define GPIO_VER6_SOC_S_JTAG_PAD_MAX          16
#define GPIO_VER6_SOC_S_VGPIO_4_PAD_MAX        2

//
// SoC-S GPIO registers
//
//
// GPIO Community Common Private Configuration Registers
//
#define V_GPIO_VER6_SOC_S_GPIO_PCR_MISCCFG_GPE0_GPP_A   0x0
#define V_GPIO_VER6_SOC_S_GPIO_PCR_MISCCFG_GPE0_GPP_C   0x1
#define V_GPIO_VER6_SOC_S_GPIO_PCR_MISCCFG_GPE0_GPP_B   0x2
#define V_GPIO_VER6_SOC_S_GPIO_PCR_MISCCFG_GPE0_VGPIO_3 0x3
#define V_GPIO_VER6_SOC_S_GPIO_PCR_MISCCFG_GPE0_VGPIO_4 0x4
#define V_GPIO_VER6_SOC_S_GPIO_PCR_MISCCFG_GPE0_VGPIO_0 0x5
#define V_GPIO_VER6_SOC_S_GPIO_PCR_MISCCFG_GPE0_GPP_D   0x7
#define V_GPIO_VER6_SOC_S_GPIO_PCR_MISCCFG_GPE0_JTAG    0xF
//
// GPIO Community 0 Private Configuration Registers
//
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_PAD_OWN            0x00B0
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_PAD_OWN          0x00C0
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_PAD_OWN            0x00CC

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_PADCFGLOCK         0x00F0
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_PADCFGLOCKTX       0x00F4
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_PADCFGLOCK       0x00F8
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_PADCFGLOCKTX     0x00FC
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_PADCFGLOCK         0x0100
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_PADCFGLOCKTX       0x0104

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_HOSTSW_OWN         0x0110
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_HOSTSW_OWN       0x0114
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_HOSTSW_OWN         0x0118

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_GPI_IS             0x0200
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_GPI_IS           0x0204
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_GPI_IS             0x0208

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_GPI_IE             0x0210
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_GPI_IE           0x0214
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_GPI_IE             0x0218

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_GPI_GPE_STS        0x0220
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_GPI_GPE_STS      0x0224
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_GPI_GPE_STS        0x0228

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_GPI_GPE_EN         0x0230
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_GPI_GPE_EN       0x0234
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_GPI_GPE_EN         0x0238

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_SMI_STS            0x0240
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_SMI_STS          0x0244
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_SMI_STS            0x0248

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_SMI_EN             0x0250
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_SMI_EN           0x0254
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_SMI_EN             0x0258

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_NMI_STS            0x0260
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_NMI_STS          0x0264
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_NMI_STS            0x0268

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_NMI_EN             0x0270
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_NMI_EN           0x0274
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_NMI_EN             0x0278

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_PADCFG_OFFSET      0x0600
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_PADCFG_OFFSET    0x07C0
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_PADCFG_OFFSET      0x08E0

//
// GPIO Community 1 Private Configuration Registers
//
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_PAD_OWN            0x00B0
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_PAD_OWN          0x00BC
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_PAD_OWN            0x00C0

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_PADCFGLOCK         0x00F0
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_PADCFGLOCKTX       0x00F4
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_PADCFGLOCK       0x00F8
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_PADCFGLOCKTX     0x00FC
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_PADCFGLOCK         0x0100
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_PADCFGLOCKTX       0x0104

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_HOSTSW_OWN         0x0110
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_HOSTSW_OWN       0x0114
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_HOSTSW_OWN         0x0118

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_GPI_IS             0x0200
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_GPI_IS           0x0204
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_GPI_IS             0x0208

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_GPI_IE             0x0210
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_GPI_IE           0x0214
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_GPI_IE             0x0218

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_GPI_GPE_STS        0x0220
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_GPI_GPE_STS      0x0224
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_GPI_GPE_STS        0x0228

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_GPI_GPE_EN         0x0230
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_GPI_GPE_EN       0x0234
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_GPI_GPE_EN         0x0238

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_SMI_STS            0x0240
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_SMI_STS          0x0244
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_SMI_STS            0x0248

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_SMI_EN             0x0250
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_SMI_EN           0x0254
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_SMI_EN             0x0258

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_NMI_STS            0x0260
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_NMI_STS          0x0264
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_NMI_STS            0x0268

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_NMI_EN             0x0270
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_NMI_EN           0x0274
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_NMI_EN             0x0278

#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_PADCFG_OFFSET      0x0600
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_PADCFG_OFFSET    0x0740
#define R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_PADCFG_OFFSET      0x07B0

//
// GPIO Community 3 Private Configuration Registers
//
#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_PAD_OWN             0x00B0
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_PAD_OWN          0x00B8

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_PADCFGLOCK          0x00F0
#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_PADCFGLOCKTX        0x00F4
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_PADCFGLOCK       0x00F8
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_PADCFGLOCKTX     0x00FC

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_HOSTSW_OWN          0x0110
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_HOSTSW_OWN       0x0114

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_GPI_IS              0x0200
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_GPI_IS           0x0204

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_GPI_IE              0x0210
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_GPI_IE           0x0214

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_GPI_GPE_STS         0x0220
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_GPI_GPE_STS      0x0224

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_GPI_GPE_EN          0x0230
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_GPI_GPE_EN       0x0234

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_SMI_STS             0x0240
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_SMI_STS          0x0244

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_SMI_EN              0x0250
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_SMI_EN           0x0254

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_NMI_STS             0x0260
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_NMI_STS          0x0264

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_NMI_EN              0x0270
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_NMI_EN           0x0274

#define R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_PADCFG_OFFSET       0x0600
#define R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_PADCFG_OFFSET    0x0700


//
// PMC SSRAM Registers (D20:F2)
//
#define PCI_DEVICE_NUMBER_PCH_PMC_SSRAM                             20
#define PCI_FUNCTION_NUMBER_PCH_PMC_SSRAM                           2


// CNP

//
// PMC Registers (D31:F2)
//
#define PCI_DEVICE_NUMBER_PCH_PMC                                   31
#define PCI_FUNCTION_NUMBER_PCH_PMC                                 2


//
// PWRM Registers
//


//
// ICLK Registers
//
#define V_ICLK_PCR_CMU_ONE_DWORD0_MUXSEL_CPUBCLK_OCPLL  1

#define R_ICLK_PCR_CMU_ONE_DWORD25                      0x22E4
#define R_ICLK_PCR_CMU_ONE_DWORD26                      0x22E8
#define S_ICLK_PCR_MUXSEL_BITS_PER_FIELD                4      // CLKREQ number is encoded in 4 bits
#define B_ICLK_PCR_MUXSEL_BITS_PER_FIELD                0xF    // CLKREQ number is encoded in 4 bits
#define S_ICLK_PCR_MUXSEL_FIELDS_PER_REG                8      // each CMU_ONE_DWORD register contains bitfields for 8 CLK_SRC


#define R_ICLK_PCR_CAMERA1                              0x8000
#define B_ICLK_PCR_FREQUENCY                            BIT0
#define B_ICLK_PCR_REQUEST                              BIT1

#endif // _GPIO_REGS_VER4_H_
