/*
 * Carsten Langgaard, carstenl@mips.com
 * Copyright (C) 2002 MIPS Technologies, Inc.  All rights reserved.
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
 * Defines for the UR8 interrupt controller.
 */
#ifndef _MIPS_UR8INT_H
#define _MIPS_UR8INT_H

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ur8.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _ur8_interrupt_type_trigger {
    ur8_interrupt_type_level = 1,
    ur8_interrupt_type_edge = 0
};

enum _ur8_interrupt_type_polarity {
    ur8_interrupt_type_active_high = 0,
    ur8_interrupt_type_active_low = 1
};

unsigned int ur8int_set_type(unsigned int irq, enum _ur8_interrupt_type_trigger, enum _ur8_interrupt_type_polarity);

/*------------------------------------------------------------------------------------------*\
 * Initialize the IRQ pacing administration                                                 *
 *                                                                                          *
 * Argument: prescale: Prescale-Value to define the intervals to count IRQs                 *
\*------------------------------------------------------------------------------------------*/
void ur8int_ctrl_irq_pacing_setup(unsigned int prescale);

/*------------------------------------------------------------------------------------------*\
 * Register the usage of pacing for an IRQ                                                  *
 *                                                                                          *
 * Argument: irq - The IRQ that should be paced                                             *
 *                                                                                          *
 * Return: >=0: Handle, with which to call the pacing related functions                     *
 *         -1 : IRQ is already registered                                                   *
 *         -2 : No more pacing registers available                                          *
 *         -3 : Thengiven IRQ can not be set and is therefor rejected                       *
\*------------------------------------------------------------------------------------------*/
int ur8int_ctrl_irq_pacing_register(unsigned int irq);

/*------------------------------------------------------------------------------------------*\
 * Unregister the IRQ pacing for a given handle                                             *
 *                                                                                          *
 * Argument: handle - Handle returned at register time                                      *
\*------------------------------------------------------------------------------------------*/
void ur8int_ctrl_irq_pacing_unregister(int handle);

/*------------------------------------------------------------------------------------------*\
 * Set the needed IRQ pacing                                                                *
 *                                                                                          *
 * Arguments: handle - Handle returned at registration time                                 *
 *            max    - Summarize at most 'max' interrupts per time slot                     *
 *                                                                                          *
 * Return: 0 on success, -1 on invalid handle                                               *
\*------------------------------------------------------------------------------------------*/
int ur8int_ctrl_irq_pacing_set(int handle, unsigned int max);

/*------------------------------------------------------------------------------------------*\
 * enable: max >= 2 (0 <= prescale < (1 << 12))
 * illegal: max = 1
 * disable: max = 0 (prescale must be 0)
\*------------------------------------------------------------------------------------------*/
unsigned int ur8int_ctrl_irq_pacing(unsigned int irq, unsigned int index, unsigned int prescale, unsigned int max);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
extern void ur8int_init(void);
void ur8_timer_interrupt(void);
extern unsigned long long ur8_nsec_timer(void);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define LNXINTNUM(x)((x) + MIPS_EXCEPTION_OFFSET)

#define MAX_VLYNQ_DEVICES       	1
#define MIPS_EXCEPTION_OFFSET           8
#define UR8_MAX_INT_PRIMARY            40
#define UR8_MAX_INT_SECONDARY          32

#define UR8_INT_END_PRIMARY            (UR8_MAX_INT_PRIMARY + MIPS_EXCEPTION_OFFSET)
#define UR8_INT_START_SECONDARY        UR8_INT_END_PRIMARY            
#define UR8_INT_END_SECONDARY          (UR8_MAX_INT_SECONDARY + UR8_INT_END_PRIMARY)

#if defined(CONFIG_VLYNQ_SUPPORT)
#define UR8_MAX_INT_VIRTUAL            (32 * MAX_VLYNQ_DEVICES)
#define UR8_INT_START_VIRTUAL          UR8_INT_END_SECONDARY          
#define UR8_INT_END_VIRTUAL            (UR8_MAX_INT_VIRTUAL + UR8_INT_END_SECONDARY)
#endif /*--- #if defined(CONFIG_VLYNQ_SUPPORT) ---*/

#if defined(CONFIG_PCI )
#define UR8_INT_PCI_BEGIN		( UR8_INT_END_VIRTUAL )
#define UR8_INT_PCI_END		    	( UR8_INT_PCI_BEGIN + 4 * MAX_PCI_DEVICES)
#define UR8_INT_END			UR8_INT_PCI_END

#define UR8_PCI_INTA_SWIRQ		( UR8_INT_PCI_BEGIN + 0 )
#define UR8_PCI_INTB_SWIRQ		( UR8_INT_PCI_BEGIN + 1 )
#define UR8_PCI_INTC_SWIRQ		( UR8_INT_PCI_BEGIN + 2 )
#define UR8_PCI_INTD_SWIRQ		( UR8_INT_PCI_BEGIN + 3 ) 


/* fuer spaeter...
#define UR8_PCI_INTA_SWIRQ(slot)		( UR8_INT_PCI_BEGIN + 0 + 4 * (slot))
*/
#endif /*--- #if defined(CONFIG_PCI ) ---*/

/*------------------------------------------------------------------------------------------*\
 * Primary Interrupts
\*------------------------------------------------------------------------------------------*/
#define UR8INT_EXT_0                       (MIPS_EXCEPTION_OFFSET + 1)
/*--- #define UR8INT_EXT_1                       (MIPS_EXCEPTION_OFFSET + 2) ---*/
/* Line#  3 to 4 are reserved                            */
#define UR8INT_TIMER_0                     (MIPS_EXCEPTION_OFFSET + 5)
#define UR8INT_TIMER_1                     (MIPS_EXCEPTION_OFFSET + 6)

#ifdef CONFIG_UR8_EVM
#define UR8INT_UART1                       (MIPS_EXCEPTION_OFFSET + 7)
#define UR8INT_UART0                       (MIPS_EXCEPTION_OFFSET + 8)
#else
#define UR8INT_UART0                       (MIPS_EXCEPTION_OFFSET + 7)
#define UR8INT_UART1                       (MIPS_EXCEPTION_OFFSET + 8)
#endif

#define UR8INT_TDM_TxDMA                   (MIPS_EXCEPTION_OFFSET + 9)
#define UR8INT_TDM_RxDMA                   (MIPS_EXCEPTION_OFFSET + 10)
#define UR8INT_MCSP_TxDMA                  (MIPS_EXCEPTION_OFFSET + 11)
#define UR8INT_MCSP_RxDMA                  (MIPS_EXCEPTION_OFFSET + 12)
#define UR8INT_MCSP_Tx                     (MIPS_EXCEPTION_OFFSET + 13)
#define UR8INT_MCSP_Rx                     (MIPS_EXCEPTION_OFFSET + 14)
#define UR8INT_NWSS_Tx0                    (MIPS_EXCEPTION_OFFSET + 15)
#define UR8INT_NWSS_Tx1                    (MIPS_EXCEPTION_OFFSET + 16)
#define UR8INT_NWSS_Tx2                    (MIPS_EXCEPTION_OFFSET + 17)
#define UR8INT_NWSS_Tx3                    (MIPS_EXCEPTION_OFFSET + 18)
#define UR8INT_UART_TxDMA                  (MIPS_EXCEPTION_OFFSET + 19)
#define UR8INT_UART_RxDMA                  (MIPS_EXCEPTION_OFFSET + 20)
#define UR8INT_C55_DSP0                    (MIPS_EXCEPTION_OFFSET + 21)
#define UR8INT_C55_DSP1                    (MIPS_EXCEPTION_OFFSET + 22)
/* Line# 23 is reserved                           */
#define UR8INT_VLYNQ0                      (MIPS_EXCEPTION_OFFSET + 24)
#define UR8INT_PCI                         (MIPS_EXCEPTION_OFFSET + 25)
#define UR8INT_TDM_Tx                      (MIPS_EXCEPTION_OFFSET + 26)
#define UR8INT_TDM_Rx                      (MIPS_EXCEPTION_OFFSET + 27)
#define UR8INT_ADSLSS                      (MIPS_EXCEPTION_OFFSET + 28) 
#define UR8INT_SPI                         (MIPS_EXCEPTION_OFFSET + 29) 
#define UR8INT_USB_DMA                     (MIPS_EXCEPTION_OFFSET + 30) 
#define UR8INT_USB                         (MIPS_EXCEPTION_OFFSET + 31) 
#define UR8INT_NWSS_Rx0                    (MIPS_EXCEPTION_OFFSET + 32)
#define UR8INT_NWSS_Rx1                    (MIPS_EXCEPTION_OFFSET + 33)
#define UR8INT_NWSS_Rx2                    (MIPS_EXCEPTION_OFFSET + 34)
#define UR8INT_NWSS_Rx3                    (MIPS_EXCEPTION_OFFSET + 35)
#define UR8INT_NWSS_Rx4                    (MIPS_EXCEPTION_OFFSET + 36)
#define UR8INT_NWSS_Rx5                    (MIPS_EXCEPTION_OFFSET + 37)
#define UR8INT_NWSS_Rx6                    (MIPS_EXCEPTION_OFFSET + 38)
#define UR8INT_NWSS_Rx7                    (MIPS_EXCEPTION_OFFSET + 39)


/* diesen int gibt es beim ur8 nicht: aber wegen einheitlichem Ansprechen der hw (sangam) hier definiert: */
#define UR8INT_MAC0_STATUS                 (UR8_INT_START_SECONDARY + 3)
#define UR8INT_MDIO0_LINK                  (UR8_INT_START_SECONDARY + 4)
#define UR8INT_MDIO0_USER                  (UR8_INT_START_SECONDARY + 5)
#define UR8INT_C55_ADDR_EXEP               (UR8_INT_START_SECONDARY + 6)
#define UR8INT_EMIF                        (UR8_INT_START_SECONDARY + 7)

#define UR8INT_MAC1_STATUS                 (UR8_INT_START_SECONDARY + 20)
#define UR8INT_MDIO1_LINK                  (UR8_INT_START_SECONDARY + 21)
#define UR8INT_MDIO1_USER                  (UR8_INT_START_SECONDARY + 22)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#endif /* !(_MIPS_UR8INT_H) */
