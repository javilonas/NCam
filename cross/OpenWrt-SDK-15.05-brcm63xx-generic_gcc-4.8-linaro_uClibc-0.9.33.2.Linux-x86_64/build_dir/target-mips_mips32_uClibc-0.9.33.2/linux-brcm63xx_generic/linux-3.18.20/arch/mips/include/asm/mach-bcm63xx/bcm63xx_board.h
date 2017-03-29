#ifndef BCM63XX_BOARD_H_
#define BCM63XX_BOARD_H_

#include <asm/bootinfo.h>

const char *board_get_name(void);

void board_prom_init(void);

void board_setup(void);

int board_register_devices(void);

static inline bool bcm63xx_is_cfe_present(void) {
	return fw_arg3 == 0x43464531;
}

#endif /* ! BCM63XX_BOARD_H_ */
