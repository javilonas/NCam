#ifndef __BCM63XX_FALLBACK_SPROM
#define __BCM63XX_FALLBACK_SPROM

#include <linux/if_ether.h>

enum sprom_type {
	SPROM_DEFAULT, /* default fallback sprom */
	/* SSB based */
	SPROM_BCM4306,
	SPROM_BCM4318,
	SPROM_BCM4321,
	SPROM_BCM4322,
	SPROM_BCM43222,
	/* BCMA based */
	SPROM_BCM4313,
	SPROM_BCM43131,
	SPROM_BCM43217,
	SPROM_BCM43225,
	SPROM_BCM43227,
	SPROM_BCM43228,
	SPROM_BCM4331,
};

struct sprom_fixup {
	u16 offset;
	u16 value;
};

struct fallback_sprom_data {
	u8 mac_addr[ETH_ALEN];
	enum sprom_type type;

	u8 pci_bus;
	u8 pci_dev;

	struct sprom_fixup *board_fixups;
	unsigned int num_board_fixups;
};

int bcm63xx_register_fallback_sprom(struct fallback_sprom_data *data);

#endif
