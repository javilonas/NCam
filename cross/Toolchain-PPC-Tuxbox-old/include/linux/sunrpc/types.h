/*
 * linux/include/linux/sunrpc/types.h
 *
 * Generic types and misc stuff for RPC.
 *
 * Copyright (C) 1996, Olaf Kirch <okir@monad.swb.de>
 */

#ifndef _LINUX_SUNRPC_TYPES_H_
#define _LINUX_SUNRPC_TYPES_H_

#include <linux/workqueue.h>
#include <linux/sunrpc/debug.h>

/*
 * Shorthands
 */
#define signalled()		(signal_pending(current))

#endif /* _LINUX_SUNRPC_TYPES_H_ */
