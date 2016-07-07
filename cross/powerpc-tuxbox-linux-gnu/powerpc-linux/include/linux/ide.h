#ifndef _IDE_H
#define _IDE_H
/*
 *  linux/include/linux/ide.h
 *
 *  Copyright (C) 1994-2002  Linus Torvalds & authors
 */

#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/hdreg.h>
#include <linux/hdsmart.h>
#include <linux/proc_fs.h>
#include <linux/interrupt.h>
#include <linux/bitops.h>
#include <linux/device.h>
#include <linux/pci.h>
#include <endian.h>
#include <byteswap.h>
#include <asm/system.h>
#include <asm/io.h>
#include <asm/semaphore.h>

/*
 * This is the multiple IDE interface driver, as evolved from hd.c.
 * It supports up to four IDE interfaces, on one or more IRQs (usually 14 & 15).
 * There can be up to two drives per interface, as per the ATA-2 spec.
 *
 * Primary i/f:    ide0: major=3;  (hda)         minor=0; (hdb)         minor=64
 * Secondary i/f:  ide1: major=22; (hdc or hd1a) minor=0; (hdd or hd1b) minor=64
 * Tertiary i/f:   ide2: major=33; (hde)         minor=0; (hdf)         minor=64
 * Quaternary i/f: ide3: major=34; (hdg)         minor=0; (hdh)         minor=64
 */

/******************************************************************************
 * IDE driver configuration options (play with these as desired):
 *
 * REALLY_SLOW_IO can be defined in ide.c and ide-cd.c, if necessary
 */
#define INITIAL_MULT_COUNT	0	/* off=0; on=2,4,8,16,32, etc.. */

#ifndef SUPPORT_SLOW_DATA_PORTS		/* 1 to support slow data ports */
#define SUPPORT_SLOW_DATA_PORTS	1	/* 0 to reduce kernel size */
#endif
#ifndef SUPPORT_VLB_SYNC		/* 1 to support weird 32-bit chips */
#define SUPPORT_VLB_SYNC	1	/* 0 to reduce kernel size */
#endif
#ifndef OK_TO_RESET_CONTROLLER		/* 1 needed for good error recovery */
#define OK_TO_RESET_CONTROLLER	1	/* 0 for use with AH2372A/B interface */
#endif

#ifndef DISABLE_IRQ_NOSYNC
#define DISABLE_IRQ_NOSYNC	0
#endif

/*
 * Used to indicate "no IRQ", should be a value that cannot be an IRQ
 * number.
 */
 
#define IDE_NO_IRQ		(-1)

/*
 *  "No user-serviceable parts" beyond this point  :)
 *****************************************************************************/

typedef unsigned char	byte;	/* used everywhere */

/*
 * Probably not wise to fiddle with these
 */
#define ERROR_MAX	8	/* Max read/write errors per sector */
#define ERROR_RESET	3	/* Reset controller every 4th retry */
#define ERROR_RECAL	1	/* Recalibrate every 2nd retry */

/*
 * Tune flags
 */
#define IDE_TUNE_NOAUTO		2
#define IDE_TUNE_AUTO		1
#define IDE_TUNE_DEFAULT	0

/*
 * state flags
 */

#define DMA_PIO_RETRY	1	/* retrying in PIO */

#define HWIF(drive)		((ide_hwif_t *)((drive)->hwif))
#define HWGROUP(drive)		((ide_hwgroup_t *)(HWIF(drive)->hwgroup))

/*
 * Definitions for accessing IDE controller registers
 */
#define IDE_NR_PORTS		(10)

#define IDE_DATA_OFFSET		(0)
#define IDE_ERROR_OFFSET	(1)
#define IDE_NSECTOR_OFFSET	(2)
#define IDE_SECTOR_OFFSET	(3)
#define IDE_LCYL_OFFSET		(4)
#define IDE_HCYL_OFFSET		(5)
#define IDE_SELECT_OFFSET	(6)
#define IDE_STATUS_OFFSET	(7)
#define IDE_CONTROL_OFFSET	(8)
#define IDE_IRQ_OFFSET		(9)

#define IDE_FEATURE_OFFSET	IDE_ERROR_OFFSET
#define IDE_COMMAND_OFFSET	IDE_STATUS_OFFSET

#define IDE_CONTROL_OFFSET_HOB	(7)

#define IDE_DATA_REG		(HWIF(drive)->io_ports[IDE_DATA_OFFSET])
#define IDE_ERROR_REG		(HWIF(drive)->io_ports[IDE_ERROR_OFFSET])
#define IDE_NSECTOR_REG		(HWIF(drive)->io_ports[IDE_NSECTOR_OFFSET])
#define IDE_SECTOR_REG		(HWIF(drive)->io_ports[IDE_SECTOR_OFFSET])
#define IDE_LCYL_REG		(HWIF(drive)->io_ports[IDE_LCYL_OFFSET])
#define IDE_HCYL_REG		(HWIF(drive)->io_ports[IDE_HCYL_OFFSET])
#define IDE_SELECT_REG		(HWIF(drive)->io_ports[IDE_SELECT_OFFSET])
#define IDE_STATUS_REG		(HWIF(drive)->io_ports[IDE_STATUS_OFFSET])
#define IDE_CONTROL_REG		(HWIF(drive)->io_ports[IDE_CONTROL_OFFSET])
#define IDE_IRQ_REG		(HWIF(drive)->io_ports[IDE_IRQ_OFFSET])

#define IDE_FEATURE_REG		IDE_ERROR_REG
#define IDE_COMMAND_REG		IDE_STATUS_REG
#define IDE_ALTSTATUS_REG	IDE_CONTROL_REG
#define IDE_IREASON_REG		IDE_NSECTOR_REG
#define IDE_BCOUNTL_REG		IDE_LCYL_REG
#define IDE_BCOUNTH_REG		IDE_HCYL_REG

#define OK_STAT(stat,good,bad)	(((stat)&((good)|(bad)))==(good))
#define BAD_R_STAT		(BUSY_STAT   | ERR_STAT)
#define BAD_W_STAT		(BAD_R_STAT  | WRERR_STAT)
#define BAD_STAT		(BAD_R_STAT  | DRQ_STAT)
#define DRIVE_READY		(READY_STAT  | SEEK_STAT)
#define DATA_READY		(DRQ_STAT)

#define BAD_CRC			(ABRT_ERR    | ICRC_ERR)

#define SATA_NR_PORTS		(3)	/* 16 possible ?? */

#define SATA_STATUS_OFFSET	(0)
#define SATA_STATUS_REG		(HWIF(drive)->sata_scr[SATA_STATUS_OFFSET])
#define SATA_ERROR_OFFSET	(1)
#define SATA_ERROR_REG		(HWIF(drive)->sata_scr[SATA_ERROR_OFFSET])
#define SATA_CONTROL_OFFSET	(2)
#define SATA_CONTROL_REG	(HWIF(drive)->sata_scr[SATA_CONTROL_OFFSET])

#define SATA_MISC_OFFSET	(0)
#define SATA_MISC_REG		(HWIF(drive)->sata_misc[SATA_MISC_OFFSET])
#define SATA_PHY_OFFSET		(1)
#define SATA_PHY_REG		(HWIF(drive)->sata_misc[SATA_PHY_OFFSET])
#define SATA_IEN_OFFSET		(2)
#define SATA_IEN_REG		(HWIF(drive)->sata_misc[SATA_IEN_OFFSET])

/*
 * Our Physical Region Descriptor (PRD) table should be large enough
 * to handle the biggest I/O request we are likely to see.  Since requests
 * can have no more than 256 sectors, and since the typical blocksize is
 * two or more sectors, we could get by with a limit of 128 entries here for
 * the usual worst case.  Most requests seem to include some contiguous blocks,
 * further reducing the number of table entries required.
 *
 * The driver reverts to PIO mode for individual requests that exceed
 * this limit (possible with 512 byte blocksizes, eg. MSDOS f/s), so handling
 * 100% of all crazy scenarios here is not necessary.
 *
 * As it turns out though, we must allocate a full 4KB page for this,
 * so the two PRD tables (ide0 & ide1) will each get half of that,
 * allowing each to have about 256 entries (8 bytes each) from this.
 */
#define PRD_BYTES       8
#define PRD_ENTRIES	256

/*
 * Some more useful definitions
 */
#define PARTN_BITS	6	/* number of minor dev bits for partitions */
#define MAX_DRIVES	2	/* per interface; 2 assumed by lots of code */
#define SECTOR_SIZE	512
#define SECTOR_WORDS	(SECTOR_SIZE / 4)	/* number of 32bit words per sector */
#define IDE_LARGE_SEEK(b1,b2,t)	(((b1) > (b2) + (t)) || ((b2) > (b1) + (t)))

/*
 * Timeouts for various operations:
 */
#define WAIT_DRQ	(HZ/10)		/* 100msec - spec allows up to 20ms */
#define WAIT_READY	(5*HZ)		/* 5sec - some laptops are very slow */
#define WAIT_PIDENTIFY	(10*HZ)	/* 10sec  - should be less than 3ms (?), if all ATAPI CD is closed at boot */
#define WAIT_WORSTCASE	(30*HZ)	/* 30sec  - worst case when spinning up */
#define WAIT_CMD	(10*HZ)	/* 10sec  - maximum wait for an IRQ to happen */
#define WAIT_MIN_SLEEP	(2*HZ/100)	/* 20msec - minimum sleep time */

#ifndef NO_DMA
#define NO_DMA  255
#endif

#include <asm/ide.h>

/*
 * Now for the data we need to maintain per-drive:  ide_drive_t
 */

#define ide_scsi	0x21
#define ide_disk	0x20
#define ide_optical	0x7
#define ide_cdrom	0x5
#define ide_tape	0x1
#define ide_floppy	0x0

/*
 * Special Driver Flags
 *
 * set_geometry	: respecify drive geometry
 * recalibrate	: seek to cyl 0
 * set_multmode	: set multmode count
 * set_tune	: tune interface for drive
 * serviced	: service command
 * reserved	: unused
 */
typedef union {
	unsigned all			: 8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned set_geometry	: 1;
		unsigned recalibrate	: 1;
		unsigned set_multmode	: 1;
		unsigned set_tune	: 1;
		unsigned serviced	: 1;
		unsigned reserved	: 3;
#elif defined(__BIG_ENDIAN)
		unsigned reserved	: 3;
		unsigned serviced	: 1;
		unsigned set_tune	: 1;
		unsigned set_multmode	: 1;
		unsigned recalibrate	: 1;
		unsigned set_geometry	: 1;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} special_t;

/*
 * ATA DATA Register Special.
 * ATA NSECTOR Count Register().
 * ATAPI Byte Count Register.
 * Channel index ordering pairs.
 */
typedef union {
	unsigned all			:16;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned low		:8;	/* LSB */
		unsigned high		:8;	/* MSB */
#elif defined(__BIG_ENDIAN)
		unsigned high		:8;	/* MSB */
		unsigned low		:8;	/* LSB */
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} ata_nsector_t, ata_data_t, atapi_bcount_t, ata_index_t;

/*
 * ATA-IDE Error Register
 *
 * mark		: Bad address mark
 * tzero	: Couldn't find track 0
 * abrt		: Aborted Command
 * mcr		: Media Change Request
 * id		: ID field not found
 * mce		: Media Change Event
 * ecc		: Uncorrectable ECC error
 * bdd		: dual meaing
 */
typedef union {
	unsigned all			:8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned mark		:1;
		unsigned tzero		:1;
		unsigned abrt		:1;
		unsigned mcr		:1;
		unsigned id		:1;
		unsigned mce		:1;
		unsigned ecc		:1;
		unsigned bdd		:1;
#elif defined(__BIG_ENDIAN)
		unsigned bdd		:1;
		unsigned ecc		:1;
		unsigned mce		:1;
		unsigned id		:1;
		unsigned mcr		:1;
		unsigned abrt		:1;
		unsigned tzero		:1;
		unsigned mark		:1;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} ata_error_t;

/*
 * ATA-IDE Select Register, aka Device-Head
 *
 * head		: always zeros here
 * unit		: drive select number: 0/1
 * bit5		: always 1
 * lba		: using LBA instead of CHS
 * bit7		: always 1
 */
typedef union {
	unsigned all			: 8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned head		: 4;
		unsigned unit		: 1;
		unsigned bit5		: 1;
		unsigned lba		: 1;
		unsigned bit7		: 1;
#elif defined(__BIG_ENDIAN)
		unsigned bit7		: 1;
		unsigned lba		: 1;
		unsigned bit5		: 1;
		unsigned unit		: 1;
		unsigned head		: 4;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} select_t, ata_select_t;

/*
 * The ATA-IDE Status Register.
 * The ATAPI Status Register.
 *
 * check	: Error occurred
 * idx		: Index Error
 * corr		: Correctable error occurred
 * drq		: Data is request by the device
 * dsc		: Disk Seek Complete			: ata
 *		: Media access command finished		: atapi
 * df		: Device Fault				: ata
 *		: Reserved				: atapi
 * drdy		: Ready, Command Mode Capable		: ata
 *		: Ignored for ATAPI commands		: atapi
 * bsy		: Disk is Busy
 *		: The device has access to the command block
 */
typedef union {
	unsigned all			:8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned check		:1;
		unsigned idx		:1;
		unsigned corr		:1;
		unsigned drq		:1;
		unsigned dsc		:1;
		unsigned df		:1;
		unsigned drdy		:1;
		unsigned bsy		:1;
#elif defined(__BIG_ENDIAN)
		unsigned bsy		:1;
		unsigned drdy		:1;
		unsigned df		:1;
		unsigned dsc		:1;
		unsigned drq		:1;
		unsigned corr           :1;
		unsigned idx		:1;
		unsigned check		:1;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} ata_status_t, atapi_status_t;

/*
 * ATA-IDE Control Register
 *
 * bit0		: Should be set to zero
 * nIEN		: device INTRQ to host
 * SRST		: host soft reset bit
 * bit3		: ATA-2 thingy, Should be set to 1
 * reserved456	: Reserved
 * HOB		: 48-bit address ordering, High Ordered Bit
 */
typedef union {
	unsigned all			: 8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned bit0		: 1;
		unsigned nIEN		: 1;
		unsigned SRST		: 1;
		unsigned bit3		: 1;
		unsigned reserved456	: 3;
		unsigned HOB		: 1;
#elif defined(__BIG_ENDIAN)
		unsigned HOB		: 1;
		unsigned reserved456	: 3;
		unsigned bit3		: 1;
		unsigned SRST		: 1;
		unsigned nIEN		: 1;
		unsigned bit0		: 1;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} ata_control_t;

/*
 * ATAPI Feature Register
 *
 * dma		: Using DMA or PIO
 * reserved321	: Reserved
 * reserved654	: Reserved (Tag Type)
 * reserved7	: Reserved
 */
typedef union {
	unsigned all			:8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned dma		:1;
		unsigned reserved321	:3;
		unsigned reserved654	:3;
		unsigned reserved7	:1;
#elif defined(__BIG_ENDIAN)
		unsigned reserved7	:1;
		unsigned reserved654	:3;
		unsigned reserved321	:3;
		unsigned dma		:1;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} atapi_feature_t;

/*
 * ATAPI Interrupt Reason Register.
 *
 * cod		: Information transferred is command (1) or data (0)
 * io		: The device requests us to read (1) or write (0)
 * reserved	: Reserved
 */
typedef union {
	unsigned all			:8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned cod		:1;
		unsigned io		:1;
		unsigned reserved	:6;
#elif defined(__BIG_ENDIAN)
		unsigned reserved	:6;
		unsigned io		:1;
		unsigned cod		:1;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} atapi_ireason_t;

/*
 * The ATAPI error register.
 *
 * ili		: Illegal Length Indication
 * eom		: End Of Media Detected
 * abrt		: Aborted command - As defined by ATA
 * mcr		: Media Change Requested - As defined by ATA
 * sense_key	: Sense key of the last failed packet command
 */
typedef union {
	unsigned all			:8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned ili		:1;
		unsigned eom		:1;
		unsigned abrt		:1;
		unsigned mcr		:1;
		unsigned sense_key	:4;
#elif defined(__BIG_ENDIAN)
		unsigned sense_key	:4;
		unsigned mcr		:1;
		unsigned abrt		:1;
		unsigned eom		:1;
		unsigned ili		:1;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} atapi_error_t;

#ifdef CONFIG_BLK_DEV_IDEPCI
void ide_pci_create_host_proc(const char *, get_info_t *);
#endif

/*
 * ATAPI floppy Drive Select Register
 *
 * sam_lun	: Logical unit number
 * reserved3	: Reserved
 * drv		: The responding drive will be drive 0 (0) or drive 1 (1)
 * one5		: Should be set to 1
 * reserved6	: Reserved
 * one7		: Should be set to 1
 */
typedef union {
	unsigned all			:8;
	struct {
#if defined(__LITTLE_ENDIAN)
		unsigned sam_lun	:3;
		unsigned reserved3	:1;
		unsigned drv		:1;
		unsigned one5		:1;
		unsigned reserved6	:1;
		unsigned one7		:1;
#elif defined(__BIG_ENDIAN)
		unsigned one7		:1;
		unsigned reserved6	:1;
		unsigned one5		:1;
		unsigned drv		:1;
		unsigned reserved3	:1;
		unsigned sam_lun	:3;
#else
#error "Endian problem - this didn't happen"
#endif
	} b;
} atapi_select_t;

#define ON_BOARD		1
#define NEVER_BOARD		0

#define NODMA 0
#define NOAUTODMA 1
#define AUTODMA 2

#define BAD_DMA_DRIVE		0
#define GOOD_DMA_DRIVE		1

typedef struct ide_pio_timings_s {
	int	setup_time;	/* Address setup (ns) minimum */
	int	active_time;	/* Active pulse (ns) minimum */
	int	cycle_time;	/* Cycle time (ns) minimum = (setup + active + recovery) */
} ide_pio_timings_t;

#endif /* _IDE_H */
