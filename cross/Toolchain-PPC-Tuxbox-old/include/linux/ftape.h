#ifndef _FTAPE_H
#define _FTAPE_H

/*
 * Copyright (C) 1994-1996 Bas Laarhoven,
 *           (C) 1996-1997 Claus-Justus Heine.

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2, or (at your option)
 any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; see the file COPYING.  If not, write to
 the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

 *
 * $Source: /cvsroot/linux-libc-headers/include/linux/ftape.h,v $
 * $Revision: 1.3 $
 * $Date: 2005-03-25 19:09:14 +0100 (Fri, 25 Mar 2005) $
 *
 *      This file contains global definitions, typedefs and macro's
 *      for the QIC-40/80/3010/3020 floppy-tape driver for Linux.
 */

#define FTAPE_VERSION "ftape v3.04d 25/11/97"

#include <linux/types.h>
#include <linux/mtio.h>

#define FT_SECTOR(x)		(x+1)	/* sector offset into real sector */
#define FT_SECTOR_SIZE		1024
#define FT_SECTORS_PER_SEGMENT	  32
#define FT_ECC_SECTORS		   3
#define FT_SEGMENT_SIZE		((FT_SECTORS_PER_SEGMENT - FT_ECC_SECTORS) * FT_SECTOR_SIZE)
#define FT_BUFF_SIZE    (FT_SECTORS_PER_SEGMENT * FT_SECTOR_SIZE)

/*
 *   bits of the minor device number that define drive selection
 *   methods. Could be used one day to access multiple tape
 *   drives on the same controller.
 */
#define FTAPE_SEL_A     0
#define FTAPE_SEL_B     1
#define FTAPE_SEL_C     2
#define FTAPE_SEL_D     3
#define FTAPE_SEL_MASK     3
#define FTAPE_SEL(unit) ((unit) & FTAPE_SEL_MASK)
#define FTAPE_NO_REWIND 4	/* mask for minor nr */

/* the following two may be reported when MTIOCGET is requested ... */
typedef union {
	struct {
		__u8 error;
		__u8 command;
	} error;
	long space;
} ft_drive_error;
typedef union {
	struct {
		__u8 drive_status;
		__u8 drive_config;
		__u8 tape_status;
	} status;
	long space;
} ft_drive_status;

#endif
