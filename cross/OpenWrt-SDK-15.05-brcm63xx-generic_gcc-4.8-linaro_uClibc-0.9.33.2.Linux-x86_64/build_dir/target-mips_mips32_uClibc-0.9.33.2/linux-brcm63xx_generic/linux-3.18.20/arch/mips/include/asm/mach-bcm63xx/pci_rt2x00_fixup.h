#ifndef _PCI_RT2X00_FIXUP
#define _PCI_RT2X00_FIXUP

#define PCI_VENDOR_ID_RALINK 0x1814

void pci_enable_rt2x00_fixup(unsigned slot, char* eeprom) __init;

#endif /* _PCI_RT2X00_FIXUP */

