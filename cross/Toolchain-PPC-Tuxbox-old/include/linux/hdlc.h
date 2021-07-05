/*
 * Generic HDLC support routines for Linux
 *
 * Copyright (C) 1999-2003 Krzysztof Halasa <khc@pm.waw.pl>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License
 * as published by the Free Software Foundation.
 */

#ifndef __HDLC_H
#define __HDLC_H

#define GENERIC_HDLC_VERSION 4	/* For synchronization with sethdlc utility */

#define CLOCK_DEFAULT   0	/* Default setting */
#define CLOCK_EXT	1	/* External TX and RX clock - DTE */
#define CLOCK_INT	2	/* Internal TX and RX clock - DCE */
#define CLOCK_TXINT	3	/* Internal TX and external RX clock */
#define CLOCK_TXFROMRX	4	/* TX clock derived from external RX clock */


#define ENCODING_DEFAULT	0 /* Default setting */
#define ENCODING_NRZ		1
#define ENCODING_NRZI		2
#define ENCODING_FM_MARK	3
#define ENCODING_FM_SPACE	4
#define ENCODING_MANCHESTER	5


#define PARITY_DEFAULT		0 /* Default setting */
#define PARITY_NONE		1 /* No parity */
#define PARITY_CRC16_PR0	2 /* CRC16, initial value 0x0000 */
#define PARITY_CRC16_PR1	3 /* CRC16, initial value 0xFFFF */
#define PARITY_CRC16_PR0_CCITT	4 /* CRC16, initial 0x0000, ITU-T version */
#define PARITY_CRC16_PR1_CCITT	5 /* CRC16, initial 0xFFFF, ITU-T version */
#define PARITY_CRC32_PR0_CCITT	6 /* CRC32, initial value 0x00000000 */
#define PARITY_CRC32_PR1_CCITT	7 /* CRC32, initial value 0xFFFFFFFF */

#define LMI_DEFAULT		0 /* Default setting */
#define LMI_NONE		1 /* No LMI, all PVCs are static */
#define LMI_ANSI		2 /* ANSI Annex D */
#define LMI_CCITT		3 /* ITU-T Annex A */

#define HDLC_MAX_MTU 1500	/* Ethernet 1500 bytes */
#define HDLC_MAX_MRU (HDLC_MAX_MTU + 10 + 14 + 4) /* for ETH+VLAN over FR */

#endif /* __HDLC_H */
