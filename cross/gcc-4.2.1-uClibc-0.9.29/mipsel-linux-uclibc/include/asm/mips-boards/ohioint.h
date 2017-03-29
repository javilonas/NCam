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
 * Defines for the OHIO interrupt controller.
 */
#ifndef _MIPS_OHIOINT_H
#define _MIPS_OHIOINT_H

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ohio.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _ohio_interrupt_type_trigger {
    ohio_interrupt_type_level = 1,
    ohio_interrupt_type_edge = 0
};

enum _ohio_interrupt_type_polarity {
    ohio_interrupt_type_active_high = 0,
    ohio_interrupt_type_active_low = 1
};

unsigned int ohioint_set_type(unsigned int irq, enum _ohio_interrupt_type_trigger, enum _ohio_interrupt_type_polarity);

/*------------------------------------------------------------------------------------------*\
 * Initialize the IRQ pacing administration                                                 *
 *                                                                                          *
 * Argument: prescale: Prescale-Value to define the intervals to count IRQs                 *
\*------------------------------------------------------------------------------------------*/
void ohioint_ctrl_irq_pacing_setup(unsigned int prescale);

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
int ohioint_ctrl_irq_pacing_register(unsigned int irq);

/*------------------------------------------------------------------------------------------*\
 * Unregister the IRQ pacing for a given handle                                             *
 *                                                                                          *
 * Argument: handle - Handle returned at register time                                      *
\*------------------------------------------------------------------------------------------*/
void ohioint_ctrl_irq_pacing_unregister(int handle);

/*------------------------------------------------------------------------------------------*\
 * Set the needed IRQ pacing                                                                *
 *                                                                                          *
 * Arguments: handle - Handle returned at registration time                                 *
 *            max    - Summarize at most 'max' interrupts per time slot                     *
 *                                                                                          *
 * Return: 0 on success, -1 on invalid handle                                               *
\*------------------------------------------------------------------------------------------*/
int ohioint_ctrl_irq_pacing_set(int handle, unsigned int max);

/*------------------------------------------------------------------------------------------*\
 * enable: max >= 2 (0 <= prescale < (1 << 12))
 * illegal: max = 1
 * disable: max = 0 (prescale must be 0)
\*------------------------------------------------------------------------------------------*/
unsigned int ohioint_ctrl_irq_pacing(unsigned int irq, unsigned int index, unsigned int prescale, unsigned int max);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
extern void ohioint_init(void);
void ohio_timer_interrupt(void);
extern unsigned long long ohio_nsec_timer(void);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define MIPS_EXCEPTION_OFFSET           8
#define OHIO_MAX_INT_PRIMARY            32
#define OHIO_MAX_INT_SECONDARY          32

#define OHIO_INT_END_PRIMARY            (OHIO_MAX_INT_PRIMARY + MIPS_EXCEPTION_OFFSET)
#define OHIO_INT_START_SECONDARY        OHIO_INT_END_PRIMARY            
#define OHIO_INT_END_SECONDARY          (OHIO_MAX_INT_SECONDARY + OHIO_INT_END_PRIMARY)

#if defined(CONFIG_VLYNQ_SUPPORT)
#define OHIO_MAX_INT_VIRTUAL            (32 * MAX_VLYNQ_DEVICES)
#define OHIO_INT_START_VIRTUAL          OHIO_INT_END_SECONDARY          
#define OHIO_INT_END_VIRTUAL            (OHIO_MAX_INT_VIRTUAL + OHIO_INT_END_SECONDARY)
#endif /*--- #if defined(CONFIG_VLYNQ_SUPPORT) ---*/

/*------------------------------------------------------------------------------------------*\
 * Primary Interrupts
\*------------------------------------------------------------------------------------------*/
#define OHIOINT_EXT_0                       (MIPS_EXCEPTION_OFFSET + 1)
#define OHIOINT_EXT_1                       (MIPS_EXCEPTION_OFFSET + 2)
/* Line#  3 to 4 are reserved                            */
#define OHIOINT_TIMER_0                     (MIPS_EXCEPTION_OFFSET + 5)
#define OHIOINT_TIMER_1                     (MIPS_EXCEPTION_OFFSET + 6)
#define OHIOINT_UART0                       (MIPS_EXCEPTION_OFFSET + 7)
/* Line#  8 is reserved                            */
#define OHIOINT0_DMA                        (MIPS_EXCEPTION_OFFSET + 9)
#define OHIOINT1_DMA                        (MIPS_EXCEPTION_OFFSET + 10)
/* Line# 11 to 14 are reserved                    */
#define OHIOINT_ATM_SAR                     (MIPS_EXCEPTION_OFFSET + 15)
/* Line# 16 to 18 are reserved                    */
#define OHIOINT_CPMAC0                      (MIPS_EXCEPTION_OFFSET + 19)
/* Line# 20 is reserved                           */
#define OHIOINT_VLYNQ0                      (MIPS_EXCEPTION_OFFSET + 21)
#define OHIOINT_CODEC_WAKEUP                (MIPS_EXCEPTION_OFFSET + 22)
#define OHIOINT_ADSLSS                      (MIPS_EXCEPTION_OFFSET + 23) 
#define OHIOINT_USB_SLAVE                   (MIPS_EXCEPTION_OFFSET + 24)
#define OHIOINT_HIGH_VLYNQ                  (MIPS_EXCEPTION_OFFSET + 25)
/* Line# 26 to 27 are reserved                    */
#define OHIOINT_UNIFIED_PHY                 (MIPS_EXCEPTION_OFFSET + 28)
#define OHIOINT_I2C                         (MIPS_EXCEPTION_OFFSET + 29)
#define OHIOINT2_DMA                        (MIPS_EXCEPTION_OFFSET + 30)
#define OHIOINT3_DMA                        (MIPS_EXCEPTION_OFFSET + 31)

/* diesen int gibt es beim ohio nicht: aber wegen einheitlichem Ansprechen der hw (sangam) hier definiert: */
#define OHIOINT_CPMAC1                      (MIPS_EXCEPTION_OFFSET + 33)

/*------------------------------------------------------------------------------------------*\
 * Secondary Interrupts
\*------------------------------------------------------------------------------------------*/
/*--- channel 0 to 6 are reserved ---*/
#define OHIOINT_EMIF                        (MIPS_EXCEPTION_OFFSET + 7)
/*--- channel 8 to 31 are reserved ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ohio_sleep_mode(unsigned deep_sleep);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#endif /* !(_MIPS_OHIOINT_H) */
