#ifndef _AFFS_FS_SB
#define _AFFS_FS_SB

/*
 * super-block data in memory
 *
 * Block numbers are adjusted for their actual size
 *
 */

struct affs_bm_info {
	u32 bm_key;			/* Disk block number */
	u32 bm_free;			/* Free blocks in here */
};

#define SF_INTL		0x0001		/* International filesystem. */
#define SF_BM_VALID	0x0002		/* Bitmap is valid. */
#define SF_IMMUTABLE	0x0004		/* Protection bits cannot be changed */
#define SF_QUIET	0x0008		/* chmod errors will be not reported */
#define SF_SETUID	0x0010		/* Ignore Amiga uid */
#define SF_SETGID	0x0020		/* Ignore Amiga gid */
#define SF_SETMODE	0x0040		/* Ignore Amiga protection bits */
#define SF_MUFS		0x0100		/* Use MUFS uid/gid mapping */
#define SF_OFS		0x0200		/* Old filesystem */
#define SF_PREFIX	0x0400		/* Buffer for prefix is allocated */
#define SF_VERBOSE	0x0800		/* Talk about fs when mounting */



#endif
