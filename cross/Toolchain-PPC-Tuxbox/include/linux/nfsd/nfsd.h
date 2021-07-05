/*
 * linux/include/linux/nfsd/nfsd.h
 *
 * Hodge-podge collection of knfsd-related stuff.
 * I will sort this out later.
 *
 * Copyright (C) 1995-1997 Olaf Kirch <okir@monad.swb.de>
 */

#ifndef LINUX_NFSD_NFSD_H
#define LINUX_NFSD_NFSD_H

#include <linux/types.h>
#include <linux/unistd.h>
#include <linux/dirent.h>
#include <linux/fs.h>

#include <linux/nfsd/debug.h>
#include <linux/nfsd/nfsfh.h>
#include <linux/nfsd/export.h>
#include <linux/nfsd/stats.h>
#include <linux/nfsd/interface.h>
/*
 * nfsd version
 */
#define NFSD_VERSION		"0.5"
#define NFSD_SUPPORTED_MINOR_VERSION	0


#endif /* LINUX_NFSD_NFSD_H */
