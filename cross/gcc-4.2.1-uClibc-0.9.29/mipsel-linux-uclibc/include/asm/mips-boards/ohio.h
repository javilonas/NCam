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
 * Defines of the OHIO board specific address-MAP, registers, etc.
 *
 */
#ifndef _MIPS_OHIO_H
#define _MIPS_OHIO_H

#include <asm/addrspace.h>

#define KERNEL_ADDR(a)      ((a) | 0xA0000000)

#define DSL_REG32( addr )   (*(volatile unsigned int *)KERNEL_ADDR(addr))
#define DSL_REG8( addr )    (*(volatile unsigned char *)KERNEL_ADDR(addr))
/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define OHIO_ADSLSS_BASE0       (0x01000000)
#define OHIO_ADSLSS_BASE1       (0x01800000)
#define OHIO_ADSLSS_BASE2       (0x01C00000)

#define OHIO_ATMSAR_BASE        (0x03000000)

#define DSP_ADDRMASK            0xff000000
#define DSP_PMEM_MASK           0x00000000
#define DSP_DMEM_MASK           0x80000000
#define DSP_RMEM_MASK           0x02000000

/*--- direkter Zugriff auf DSP-Registerset:  ---*/
/*--- Analog front end subsystem specification ---*/
#define DSP_DEV_CODEC_BASE                       (DSP_RMEM_MASK + 0x40000)
#define DSP_DEV_CODEC_CTRL2_OFFSET               (0x11)   
#define DSP_DEV_CODEC_BUCK_TRIM_PASSWORD_OFFSET  (0x67)

#define OHIO_ADSLSS_PRCR_BASE       (0x01000600)
#define OHIO_ADSLSS_PRCR            (OHIO_ADSLSS_PRCR_BASE + 0x00)
#define OHIO_ADSLSS_PRCR_DSL_SPA    0x40
#define OHIO_ADSLSS_BUCKTRIM_READ   (0x01040000 + 0x18) 

#define OHIO_USB_BASE           KERNEL_ADDR(0x03400000)

#define OHIO_VLYNQ0_BASE        KERNEL_ADDR(0x04000000)

#define OHIO_CPMAC0_BASE        KERNEL_ADDR(0x08610000)
#define OHIO_EMIF_BASE          KERNEL_ADDR(0x08610800)
#define OHIO_GPIO_BASE          KERNEL_ADDR(0x08610900)
#define OHIO_CLOCK_BASE         KERNEL_ADDR(0x08610A00)
#define OHIO_TIMER1_BASE        KERNEL_ADDR(0x08610C00)
#define OHIO_TIMER2_BASE        KERNEL_ADDR(0x08610D00)

/*
 * OHIO UART register base.
 */
#define OHIO_UART0_BASE         KERNEL_ADDR(0x08610E00)
#define OHIO_BASE_BAUD          (3686400 / 16)   /* TODO */

#define OHIO_I2C_BASE           KERNEL_ADDR(0x08610F00)
#define OHIO_USBDMA_BASE        KERNEL_ADDR(0x08611200)
#define OHIO_MCDMA_BASE         KERNEL_ADDR(0x08611400)
#define OHIO_RESET_BASE         KERNEL_ADDR(0x08611600)
#define OHIO_BIST_BASE          KERNEL_ADDR(0x08611700)
#define OHIO_VLYNQ0_CTRL_BASE   KERNEL_ADDR(0x08611800)
#define OHIO_DEVICE_CONFIG_BASE KERNEL_ADDR(0x08611A00)
#define OHIO_MII_SEL_REG        KERNEL_ADDR(0x08611A08)
#define OHIO_MDIO_BASE          KERNEL_ADDR(0x08611E00)
#define OHIO_WDT_BASE           KERNEL_ADDR(0x08611F00)
#define OHIO_IRQ_CTRL_BASE      KERNEL_ADDR(0x08612400)
/* ohio hat zwar nur einen cpmac; Sangam hat jedoch zwei, die einheitlich angesteuert werden sollen */
#define OHIO_CPMAC1_BASE        KERNEL_ADDR(0x08612800)
#define OHIO_CS0_BASE           KERNEL_ADDR(0x10000000)
#define OHIO_CS1_BASE           KERNEL_ADDR(0x14000000)
#define OHIO_CS2_BASE           KERNEL_ADDR(0x18000000)
#define OHIO_CS3_BASE           KERNEL_ADDR(0x1C000000)
#define OHIO_CS4_BASE           KERNEL_ADDR(0x1D000000)
#define OHIO_CS5_BASE           KERNEL_ADDR(0x1E000000)
#define OHIO_ROM_BASE           KERNEL_ADDR(0x1FC00000)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/

#endif /* !(_MIPS_OHIO_H) */
