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
 * Defines of the UR8 board specific address-MAP, registers, etc.
 *
 */
#ifndef _MIPS_UR8_H
#define _MIPS_UR8_H

#include <asm/addrspace.h>

#define KERNEL_ADDR(a)      ((a) | 0xA0000000)

#define DSL_REG32( addr )   (*(volatile unsigned int *)KERNEL_ADDR(addr))
#define DSL_REG8( addr )    (*(volatile unsigned char *)KERNEL_ADDR(addr))
/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define UR8_ADSLSS_BASE0       (0x01000000) /* DSLSS Peripheral Space */
#define UR8_ADSLSS_BASE1       (0x01800000)
#define UR8_ADSLSS_BASE2       (0x01C00000) /* DSLSS Memory Space */

#define UR8_ATMSAR_BASE        (0x03000000)

#define DSP_ADDRMASK            0xff000000
#define DSP_PMEM_MASK           0x00000000
#define DSP_DMEM_MASK           0x80000000
#define DSP_RMEM_MASK           0x02000000

/*--- direkter Zugriff auf DSP-Registerset:  ---*/
/*--- Analog front end subsystem specification ---*/
#define DSP_DEV_CODEC_BASE                       (DSP_RMEM_MASK + 0x40000)
#define DSP_DEV_CODEC_CTRL2_OFFSET               (0x11)   
#define DSP_DEV_CODEC_BUCK_TRIM_PASSWORD_OFFSET  (0x67)

#define UR8_ADSLSS_PRCR_BASE       (0x01000600)
#define UR8_ADSLSS_PRCR            (OHIO_ADSLSS_PRCR_BASE + 0x00)
#define UR8_ADSLSS_PRCR_DSL_SPA    0x40
#define UR8_ADSLSS_BUCKTRIM_READ   (0x01040000 + 0x18) 


#define UR8_NWSS_BASE          KERNEL_ADDR(0x03000000)
#define UR8_NWSS_QUEUE         KERNEL_ADDR(0x03068000)

#define UR8_USB_BASE           KERNEL_ADDR(0x03400000)

#define UR8_VOICE_BASE         KERNEL_ADDR(0x04000000)
#define UR8_TDM_BASE           KERNEL_ADDR(0x08604000)

#define UR8_CPMAC0_BASE        KERNEL_ADDR(0x0304E000)
#define UR8_EMIF_BASE          KERNEL_ADDR(0x08610800)
#define UR8_GPIO_BASE          KERNEL_ADDR(0x08610900)
#define UR8_CLOCK_BASE         KERNEL_ADDR(0x08610A00)

#define UR8_WDT_BASE           KERNEL_ADDR(0x08610B00)
#define UR8_TIMER1_BASE        KERNEL_ADDR(0x08610C00)
#define UR8_TIMER2_BASE        KERNEL_ADDR(0x08610D00)

/*
 * UR8 UART register base.
 */
#ifdef CONFIG_UR8_EVM
#define UR8_UART1_BASE         KERNEL_ADDR(0x08610E00) 
#define UR8_UART0_BASE         KERNEL_ADDR(0x08610F00) 
#else
#define UR8_UART0_BASE         KERNEL_ADDR(0x08610E00)
#define UR8_UART1_BASE         KERNEL_ADDR(0x08610F00)
#endif

#define UR8_BASE_BAUD          (3686400 / 16)   /* TODO */

#define UR8_SPI_BASE           KERNEL_ADDR(0x08611000)

#define UR8_MCDMA_BASE         KERNEL_ADDR(0x08611400)

#define UR8_RESET_BASE         KERNEL_ADDR(0x08611600)
#define UR8_VLYNQ0_CTRL_BASE   KERNEL_ADDR(0x08611800)
#define UR8_DEVICE_CONFIG_BASE KERNEL_ADDR(0x08611A00)
/*--- #define UR8_MII_SEL_REG        KERNEL_ADDR(0x08611A08) ---*/
#define UR8_MDIO_BASE          KERNEL_ADDR(0x08611E00)
#define UR8_IRQ_CTRL_BASE      KERNEL_ADDR(0x08612400)

#define UR8_PCI_CFG_BASE       KERNEL_ADDR(0x08614000)
#define UR8_MCSP_BASE          KERNEL_ADDR(0x08620000)
#define UR8_VLYNQ_WINDOW       KERNEL_ADDR(0x0C000000)

/* ohio hat zwar nur einen cpmac; Sangam hat jedoch zwei, die einheitlich angesteuert werden sollen */
#define UR8_CPMAC1_BASE        KERNEL_ADDR(0x0304E000)
#define UR8_CS0_BASE           KERNEL_ADDR(0x10000000)
#define UR8_CS1_BASE           KERNEL_ADDR(0x14000000)
#define UR8_CS2_BASE           KERNEL_ADDR(0x18000000)
/*--- #define UR8_CS3_BASE           KERNEL_ADDR(0x1C000000) ---*/
/*--- #define UR8_CS4_BASE           KERNEL_ADDR(0x1D000000) ---*/
/*--- #define UR8_CS5_BASE           KERNEL_ADDR(0x1E000000) ---*/
#define UR8_ROM_BASE           KERNEL_ADDR(0x1FC00000)
#define UR8_PCI_BASE           KERNEL_ADDR(0x40000000)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define UR8_SDRAM_BASE          0x14000000


/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/

#endif /* !(_MIPS_UR8_H) */
