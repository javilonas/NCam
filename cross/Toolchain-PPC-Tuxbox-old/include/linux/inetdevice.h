#ifndef _LINUX_INETDEVICE_H
#define _LINUX_INETDEVICE_H

#include <asm/types.h>

static __inline__ __u32 inet_make_mask(int logmask)
{
	if (logmask)
		return htonl(~((1<<(32-logmask))-1));
	return 0;
}

static __inline__ int inet_mask_len(__u32 mask)
{
	if (!(mask = ntohl(mask)))
		return 0;
	return 32 - ffz(~mask);
}


#endif /* _LINUX_INETDEVICE_H */
