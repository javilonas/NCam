#ifndef _PCI_ATH9K_FIXUP
#define _PCI_ATH9K_FIXUP


void pci_enable_ath9k_fixup(unsigned slot, u32 offset,
	unsigned endian_check, int led_pin) __init;

#endif /* _PCI_ATH9K_FIXUP */
