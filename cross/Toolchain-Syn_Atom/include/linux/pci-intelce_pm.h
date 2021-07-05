/*
 *  GPL LICENSE SUMMARY
 *
 *  Copyright(c) 2010 - 2012 Intel Corporation. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of version 2 of the GNU General Public License as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *  The full GNU General Public License is included in this distribution
 *  in the file called LICENSE.GPL.
 *
 *  Contact Information:
 *    Intel Corporation
 *    2200 Mission College Blvd.
 *    Santa Clara, CA  97052
 *
 */

#ifndef __PCI_INTELCE_PM_H__
#define __PCI_INTELCE_PM_H__

typedef struct intel_pm_pci_ops_t 
{
	bool        (*is_manageable)(struct pci_dev *dev);
	int         (*set_state)    (struct pci_dev *dev, pci_power_t state);
	pci_power_t (*choose_state) (struct pci_dev *dev);
	bool        (*can_wakeup)   (struct pci_dev *dev);
	int         (*sleep_wake)   (struct pci_dev *dev, bool enable);
} intel_pm_pci_ops_t;

void intel_pm_register_callback(intel_pm_pci_ops_t * ops);
extern int suspend_devices_rooted(struct device *root, pm_message_t state);
extern int resume_devices_rooted(struct device *root, pm_message_t state);
extern void clear_async_error(void);

#endif
