#ifndef __AVALANCHE_SPI_H_
#define __AVALANCHE_SPI_H_

#define AVALANCHE_SPI_SIZE				0xFF
#define AVALANCHE_SPI_INIT_SPMODE			0

/* Chip selects available on the spi IP */
#define AVALANCHE_SPI_CS0		0
#define AVALANCHE_SPI_CS1		1
#define AVALANCHE_SPI_CS2		2
#define AVALANCHE_SPI_CS3		3


struct ctlr_cs_sel_t
{
	u8 cs;
	u8 pol;
};

struct avalanche_spi_platform_data {
	/* initial SPMODE value */
	u32 	initial_spmode;	
	/* board specific information */
	u16		bus_num; /* id for controller */
	u16	max_chipselect;
	int	(*activate_cs)(u8 cs, u8 polarity, struct ctlr_cs_sel_t *ctlr_cs_sel);
	int	(*deactivate_cs)(u8 cs, u8 polarity, struct ctlr_cs_sel_t *ctlr_cs_sel);
	u32	sysclk;
};


extern int ti_spi_register_driver(struct spi_driver *sdrv);

extern int __init
ti_spi_register_board_info(struct spi_board_info const *info, unsigned n);

extern struct spi_master *ti_spi_busnum_to_master(u16 bus_num);

extern int ti_spi_sync(struct spi_device *spi, struct spi_message *message);

extern int ti_spi_write_then_read(struct spi_device *spi,
                const u8 *txbuf, unsigned n_tx,
                u8 *rxbuf, unsigned n_rx);


extern void ti_spi_unregister_driver(struct spi_driver *sdrv);

extern int ti_device_create_file(struct device *device, struct device_attribute * entry);
extern void ti_device_remove_file(struct device * dev, struct device_attribute * attr);



extern int ti_spi_write(struct spi_device *spi, const u8 *buf, size_t len);


extern int ti_spi_read(struct spi_device *spi, u8 *buf, size_t len);

#endif /* __AVALANCHE_SPI_H_ */

