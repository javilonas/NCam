#ifndef _LINUX_DNOTIFY_H
#define _LINUX_DNOTIFY_H
/*
 * Directory notification for Linux
 *
 * Copyright (C) 2000,2002 Stephen Rothwell
 */

#include <linux/fs.h>

struct dnotify_struct {
	struct dnotify_struct *	dn_next;
	unsigned long		dn_mask;
	int			dn_fd;
	struct file *		dn_filp;
	fl_owner_t		dn_owner;
};

#endif /* _LINUX_DNOTIFY_H */
