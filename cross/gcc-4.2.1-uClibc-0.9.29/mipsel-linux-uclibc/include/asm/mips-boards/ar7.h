/*
 * Carsten Langgaard, carstenl@mips.com
 * Copyright (C) 2002 MIPS Technologies, Inc.  All rights reserved.
 *
 * ########################################################################
 *
 *  This program is free software; you can distribute it and/or modify it
 *  under the terms of the GNU General Public License (Version 2) as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston MA 02111-1307, USA.
 *
 * ########################################################################
 *
 * Defines of the AR7 board specific address-MAP, registers, etc.
 *
 */
#ifndef _MIPS_AR7_H
#define _MIPS_AR7_H

#include <asm/addrspace.h>

#define KERNEL_ADDR(a)      ((a) | 0xA0000000)


#define DSL_REG32( addr )   (*(volatile unsigned int *)KERNEL_ADDR(addr))
#define DSL_REG8( addr )    (*(volatile unsigned char *)KERNEL_ADDR(addr))
/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define AR7_ADSLSS_BASE0       (0x01000000)

#define AR7_BBIF_CONTROL_BASE  (0x02000000) 
#define AR7_ADSLSSADR          (AR7_BBIF_CONTROL_BASE + 0)

#define AR7_ATMSAR_BASE        (0x03000000)

#define DSP_ADDRMASK            0xff000000
#define DSP_PMEM_MASK           0x00000000
#define DSP_DMEM_MASK           0x80000000
#define DSP_RMEM_MASK           0x02000000

/*--- direkter Zugriff auf DSP-Registerset:  ---*/
/*--- Analog front end subsystem specification ---*/
#define DSP_DEV_CODEC_BASE          (DSP_RMEM_MASK + 0x40000)
#define DSP_DEV_CODEC_CTRL1_ADDR    (DSP_DEV_CODEC_BASE +0x10) /*--- wird benötigt für DSP-CoreVoltage ändern ---*/

#define AR7_USB_BASE           KERNEL_ADDR(0x03400000)

#define AR7_VLYNQ0_BASE        KERNEL_ADDR(0x04000000)

#define AR7_CPMAC0_BASE        KERNEL_ADDR(0x08610000)
#define AR7_EMIF_BASE          KERNEL_ADDR(0x08610800)
#define AR7_GPIO_BASE          KERNEL_ADDR(0x08610900)
#define AR7_CLOCK_BASE         KERNEL_ADDR(0x08610A00)
#define AR7_TIMER1_BASE        KERNEL_ADDR(0x08610C00)
#define AR7_TIMER2_BASE        KERNEL_ADDR(0x08610D00)

/*
 * AR7 UART register base.
 */
#define AR7_UART0_BASE         KERNEL_ADDR(0x08610E00)
#define AR7_BASE_BAUD          (3686400 / 16)   /* TODO */

#define AR7_I2C_BASE           KERNEL_ADDR(0x08610F00)
#define AR7_USBDMA_BASE        KERNEL_ADDR(0x08611200)
#define AR7_MCDMA_BASE         KERNEL_ADDR(0x08611400)
#define AR7_RESET_BASE         KERNEL_ADDR(0x08611600)
#define AR7_BIST_BASE          KERNEL_ADDR(0x08611700)
#define AR7_VLYNQ0_CTRL_BASE   KERNEL_ADDR(0x08611800)
#define AR7_DEVICE_CONFIG_BASE KERNEL_ADDR(0x08611A00)
#define AR7_MII_SEL_REG        KERNEL_ADDR(0x08611A08)
#define AR7_MDIO_BASE          KERNEL_ADDR(0x08611E00)
#define AR7_VLYNQ1_CTRL_BASE   KERNEL_ADDR(0x08611C00)
#define AR7_WDT_BASE           KERNEL_ADDR(0x08611F00)
#define AR7_IRQ_CTRL_BASE      KERNEL_ADDR(0x08612400)
/* Ohio hat zwar nur einen cpmac; Sangam hat jedoch zwei, die einheitlich angesteuert werden sollen */
#define AR7_CPMAC1_BASE        KERNEL_ADDR(0x08612800)
#define AR7_VLYNQ1_BASE        KERNEL_ADDR(0x0C000000)
#define AR7_CS0_BASE           KERNEL_ADDR(0x10000000)
#define AR7_CS1_BASE           KERNEL_ADDR(0x14000000)
#define AR7_CS2_BASE           KERNEL_ADDR(0x18000000)
#define AR7_CS3_BASE           KERNEL_ADDR(0x1C000000)
#define AR7_CS4_BASE           KERNEL_ADDR(0x1D000000)
#define AR7_CS5_BASE           KERNEL_ADDR(0x1E000000)
#define AR7_ROM_BASE           KERNEL_ADDR(0x1FC00000)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/

#endif /* !(_MIPS_AR7_H) */
