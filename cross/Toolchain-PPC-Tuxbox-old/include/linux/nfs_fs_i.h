#ifndef _NFS_FS_I
#define _NFS_FS_I

#include <asm/types.h>
#include <linux/nfs.h>

struct nlm_lockowner;

/*
 * NFS lock info
 */
struct nfs_lock_info {
	__u32		state;
	__u32		flags;
	struct nlm_lockowner *owner;
};

/*
 * Lock flag values
 */
#define NFS_LCK_GRANTED		0x0001		/* lock has been granted */
#define NFS_LCK_RECLAIM		0x0002		/* lock marked for reclaiming */

#endif
