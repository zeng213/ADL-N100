/**@file
  GPIO data for use with GPIO ASL lib

  Copyright (c) 2023, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "Register/GpioRegs.h"
#include "Register/GpioRegsVer6.h"
#include "GpioAcpiDefinesMtl.h"

//
// If in GPIO_GROUP_INFO structure certain register doesn't exist
// it will have value equal to NO_REGISTER_FOR_PROPERTY
//
#define NO_REGISTER_FOR_PROPERTY 0xFFFF

//
// If in GPIO_GROUP_INFO structure certain group should not be used
// by GPIO OS driver then "Gpio base number" field should be set to below value
//
#define GPIO_OS_DRV_NOT_SUPPORTED 0xFFFF

//
// GPIO Library objects
//
Scope (\_SB)
{
  //
  // GPIO information data structure
  //

  Name (GPCM, Package() {
    Package() { // COM0
      PCH_GPIO_COM0,
      Package() {
        Package() { // CPU
          GPIO_VER6_SOC_M_CPU_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_CPU_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_CPU_PECI,
          0
        },
        Package() { // GPP_V
          GPIO_VER6_SOC_M_GPP_V_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_V_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_V0,
          1
        },
        Package() { // GPP_C
          GPIO_VER6_SOC_M_GPP_C_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_C_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_C0,
          2
        }
      }
    },
    Package() { // COM1
      PCH_GPIO_COM1,
      Package() {
        Package() { // GPP_A
          GPIO_VER6_SOC_M_GPP_A_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_A_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_A0,
          3
        },
        Package() { // GPP_E
          GPIO_VER6_SOC_M_GPP_E_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_E_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_E0,
          4
        }
      }
    },
    // COM2 - not used
    Package() { // COM3
      PCH_GPIO_COM3,
      Package() {
        Package() { // GPP_H
          GPIO_VER6_SOC_M_GPP_H_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_H_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_H0,
          5
        },
        Package() { // GPP_F
          GPIO_VER6_SOC_M_GPP_F_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_F_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_F0,
          6
        },
        Package() { // SPI_SYS
          GPIO_VER6_SOC_M_SPI_SYS_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_SPI_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_SPI0_IO2,
          7
        },
        Package() { // THC
          GPIO_VER6_SOC_M_USB_THC_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_USB_0,
          8
        }
      }
    },
    Package() { // COM4
      PCH_GPIO_COM4,
      Package() {
        Package() { // GPP_S
          GPIO_VER6_SOC_M_GPP_S_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_S_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_S0,
          9
        },
        Package() { // JTAG
          GPIO_VER6_SOC_M_JTAG_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_JTAG_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_MBPB0,
          10
        }
      }
    },
    Package() { // COM5
      PCH_GPIO_COM5,
      Package() {
        Package() { // GPP_B
          GPIO_VER6_SOC_M_GPP_B_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_B_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_B0,
          11
        },
        Package() { // GPP_D
          GPIO_VER6_SOC_M_GPP_D_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_GPP_D_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_GPP_D0,
          12
        },
        Package() { // VGPIO
          GPIO_VER6_SOC_M_VGPIO_PAD_MAX,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_HOSTSW_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_PAD_OWN,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_GPI_GPE_STS,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VPGIO5_PADCFGLOCK,
          R_GPIO_VER6_SOC_M_GPIO_PCR_VGPIO5_PADCFGLOCKTX,
          GPIO_VER6_SOC_M_DRIVER_VGPIO0,
          13
        }
      }
    }
  })

  Name (GPCS, Package() {
    Package() { // COM0
      PCH_GPIO_COM0,
      Package() {
        Package() { // GPP_A
          GPIO_VER6_SOC_S_GPP_A_PAD_MAX,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_HOSTSW_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_PAD_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_GPI_GPE_STS,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_PADCFGLOCK,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_A_PADCFGLOCKTX,
          GPIO_VER6_SOC_S_DRIVER_GPP_A0,
          0
        },
        Package() { // VGPIO_0
          GPIO_VER6_SOC_S_VGPIO_0_PAD_MAX,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_HOSTSW_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_PAD_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_GPI_GPE_STS,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_PADCFGLOCK,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_0_PADCFGLOCKTX,
          GPIO_VER6_SOC_S_DRIVER_VGPIO_LPC_0,
          1
        },
        Package() { // GPP_C
          GPIO_VER6_SOC_S_GPP_C_PAD_MAX,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_HOSTSW_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_PAD_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_GPI_GPE_STS,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_PADCFGLOCK,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_C_PADCFGLOCKTX,
          GPIO_VER6_SOC_S_DRIVER_GPP_C0,
          2
        }
      }
    },
    Package() { // COM1
      PCH_GPIO_COM1,
      Package() {
        Package() { // GPP_B
          GPIO_VER6_SOC_S_GPP_B_PAD_MAX,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_HOSTSW_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_PAD_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_GPI_GPE_STS,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_PADCFGLOCK,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_B_PADCFGLOCKTX,
          GPIO_VER6_SOC_S_DRIVER_GPP_B0,
          3
        },
        Package() { // VGPIO_3
          GPIO_VER6_SOC_S_VGPIO_3_PAD_MAX,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_HOSTSW_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_PAD_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_GPI_GPE_STS,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_PADCFGLOCK,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_3_PADCFGLOCKTX,
          GPIO_VER6_SOC_S_DRIVER_VGPIO_USB_0,
          4
        },
        Package() { // GPP_D
          GPIO_VER6_SOC_S_GPP_D_PAD_MAX,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_HOSTSW_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_PAD_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_GPI_GPE_STS,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_PADCFGLOCK,
          R_GPIO_VER6_SOC_S_GPIO_PCR_GPP_D_PADCFGLOCKTX,
          GPIO_VER6_SOC_S_DRIVER_GPP_D0,
          5
        }
      }
    },
    // COM2 - not used
    Package() { // COM3
      PCH_GPIO_COM3,
      Package() {
        Package() { // JTAG
          GPIO_VER6_SOC_S_JTAG_PAD_MAX,
          R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_HOSTSW_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_PAD_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_GPI_GPE_STS,
          R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_PADCFGLOCK,
          R_GPIO_VER6_SOC_S_GPIO_PCR_JTAG_PADCFGLOCKTX,
          GPIO_VER6_SOC_S_DRIVER_PECI,
          6
        },
        Package() { // VGPIO_4
          GPIO_VER6_SOC_S_VGPIO_4_PAD_MAX,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_PADCFG_OFFSET,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_HOSTSW_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_PAD_OWN,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_GPI_GPE_STS,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_PADCFGLOCK,
          R_GPIO_VER6_SOC_S_GPIO_PCR_VGPIO_4_PADCFGLOCKTX,
          GPIO_VER6_SOC_S_DRIVER_VGPIO_ISCLK0,
          7
        }
      }
    }
  })
}