#ifndef _AFFS_FS_I
#define _AFFS_FS_I

#include <linux/a.out.h>
#include <linux/fs.h>
#include <asm/semaphore.h>

#define AFFS_CACHE_SIZE		PAGE_SIZE
//#define AFFS_CACHE_SIZE		(4*4)

#define AFFS_MAX_PREALLOC	32
#define AFFS_LC_SIZE		(AFFS_CACHE_SIZE/sizeof(u32)/2)
#define AFFS_AC_SIZE		(AFFS_CACHE_SIZE/sizeof(struct affs_ext_key)/2)
#define AFFS_AC_MASK		(AFFS_AC_SIZE-1)

struct affs_ext_key {
	u32	ext;				/* idx of the extended block */
	u32	key;				/* block number */
};


#endif
