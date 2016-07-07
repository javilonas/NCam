/*
 *	Routines to manage notifier chains for passing status changes to any
 *	interested routines. We need this instead of hard coded call lists so
 *	that modules can poke their nose into the innards. The network devices
 *	needed them so here they are for the rest of you.
 *
 *				Alan Cox <Alan.Cox@linux.org>
 */
 
#ifndef _LINUX_NOTIFIER_H
#define _LINUX_NOTIFIER_H
#include <linux/errno.h>

struct notifier_block
{
	int (*notifier_call)(struct notifier_block *self, unsigned long, void *);
	struct notifier_block *next;
	int priority;
};

#endif /* _LINUX_NOTIFIER_H */
