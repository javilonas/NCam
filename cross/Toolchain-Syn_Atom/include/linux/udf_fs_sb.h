/*
 * udf_fs_sb.h
 * 
 * This include file is for the Linux kernel/module.
 *
 * CONTACTS
 *	E-mail regarding any portion of the Linux UDF file system should be
 *	directed to the development team mailing list (run by majordomo):
 *		linux_udf@hpesjro.fc.hp.com
 *
 * COPYRIGHT
 *	This file is distributed under the terms of the GNU General Public
 *	License (GPL). Copies of the GPL can be obtained from:
 *		ftp://prep.ai.mit.edu/pub/gnu/GPL
 *	Each contributing author retains all rights to their own work.
 */

#ifndef _UDF_FS_SB_H
#define _UDF_FS_SB_H 1

#include <asm/types.h>

#include <asm/semaphore.h>

#pragma pack(1)

#define UDF_MAX_BLOCK_LOADED	8

#define UDF_TYPE1_MAP15			0x1511U
#define UDF_VIRTUAL_MAP15		0x1512U
#define UDF_VIRTUAL_MAP20		0x2012U
#define UDF_SPARABLE_MAP15		0x1522U


struct udf_virtual_data
{
	__u32	s_num_entries;
	__u16	s_start_offset;
};



#pragma pack()


#endif /* _UDF_FS_SB_H */
