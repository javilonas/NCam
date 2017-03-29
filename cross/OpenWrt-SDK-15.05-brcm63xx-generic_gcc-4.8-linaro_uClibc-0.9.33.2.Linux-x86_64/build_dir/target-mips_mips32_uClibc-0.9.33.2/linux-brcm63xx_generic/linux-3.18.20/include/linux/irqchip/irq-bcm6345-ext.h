/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2014 Jonas Gorski <jogo@openwrt.org>
 */

#ifndef __INCLUDE_LINUX_IRQCHIP_IRQ_BCM6345_EXT_H
#define __INCLUDE_LINUX_IRQCHIP_IRQ_BCM6345_EXT_H

void bcm6345_ext_intc_init(int n_irqs, int *irqs, void __iomem *reg, int shift);

#endif /* __INCLUDE_LINUX_IRQCHIP_IRQ_BCM6345_EXT_H */
