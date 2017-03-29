/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ur8_pci_h_
#define _ur8_pci_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <linux/interrupt.h>
#include <asm/mach-ur8/hw_pci.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/

#define MAX_PCI_DEVICES       3
#define MAX_PCI_INT_VECTORS   8           /*--- mehr Interruptvektoren sind nicht erlaubt ---*/



struct ur8_ictrl_regs /* UR8 Interrupt control registers */
{
  volatile unsigned long intsr1;    /* Interrupt Status/Set Register 1   0x00 */
  volatile unsigned long intsr2;    /* Interrupt Status/Set Register 2   0x04 */
  volatile unsigned long unused1;                                      /*0x08 */
  volatile unsigned long unused2;                                      /*0x0C */
  volatile unsigned long intcr1;    /* Interrupt Clear Register 1        0x10 */
  volatile unsigned long intcr2;    /* Interrupt Clear Register 2        0x14 */
  volatile unsigned long unused3;                                      /*0x18 */
  volatile unsigned long unused4;                                      /*0x1C */
  volatile unsigned long intesr1;   /* Interrupt Enable (Set) Register 1 0x20 */
  volatile unsigned long intesr2;   /* Interrupt Enable (Set) Register 2 0x24 */
  volatile unsigned long unused5;                                      /*0x28 */
  volatile unsigned long unused6;                                      /*0x2C */
  volatile unsigned long intecr1;   /* Interrupt Enable Clear Register 1 0x30 */
  volatile unsigned long intecr2;   /* Interrupt Enable Clear Register 2 0x34 */
  volatile unsigned long unused7;                                     /* 0x38 */
  volatile unsigned long unused8;                                     /* 0x3c */
  volatile unsigned long pintir;    /* Priority Interrupt Index Register 0x40 */
  volatile unsigned long intmsr;    /* Priority Interrupt Mask Index Reg 0x44 */
  volatile unsigned long unused9;                                     /* 0x48 */
  volatile unsigned long unused10;                                    /* 0x4C */
  volatile unsigned long intpolr1;  /* Interrupt Polarity Mask register 10x50 */
  volatile unsigned long intpolr2;  /* Interrupt Polarity Mask register 20x54 */
  volatile unsigned long unused11;                                    /* 0x58 */
  volatile unsigned long unused12;                                   /*0x5C */
  volatile unsigned long inttypr1;  /* Interrupt Type     Mask register 10x60 */
  volatile unsigned long inttypr2;  /* Interrupt Type     Mask register 20x64 */
};





unsigned int pci_get_irq(unsigned int instance);
unsigned int pci_irq_ack(unsigned int instance, unsigned int irq);

unsigned int pci_irq_status(unsigned int instance);
unsigned int pci_irq_enable_mask(unsigned int instance);
unsigned int pci_irq_enable(unsigned int instance, unsigned int irq);
unsigned int pci_irq_disable(unsigned int instance, unsigned int irq);

#endif //--- #ifndef _ur8_pci_h_ ---
