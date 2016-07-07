#ifndef _PPC_ERRNO_H
#define _PPC_ERRNO_H

#ifndef _LINUX_ERRNO_H
 #include <linux/errno.h>
#endif

#undef	EDEADLOCK
#define	EDEADLOCK	58	/* File locking deadlock error */

#define _LAST_ERRNO	516

#endif
