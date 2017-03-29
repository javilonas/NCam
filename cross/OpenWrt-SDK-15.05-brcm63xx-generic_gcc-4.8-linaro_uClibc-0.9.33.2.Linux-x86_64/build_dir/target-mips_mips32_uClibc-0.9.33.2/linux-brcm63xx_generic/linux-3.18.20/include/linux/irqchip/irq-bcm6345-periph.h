/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2008 Maxime Bizon <mbizon@freebox.fr>
 * Copyright (C) 2008 Nicolas Schichan <nschichan@freebox.fr>
 */

#ifndef __INCLUDE_LINUX_IRQCHIP_IRQ_BCM6345_PERIPH_H
#define __INCLUDE_LINUX_IRQCHIP_IRQ_BCM6345_PERIPH_H

void bcm6345_periph_intc_init(int num_blocks, int *irq, void __iomem **base,
			      int num_words);

#endif /* __INCLUDE_LINUX_IRQCHIP_IRQ_BCM6345_PERIPH_H */
