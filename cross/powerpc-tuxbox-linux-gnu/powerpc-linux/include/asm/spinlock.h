#ifndef __ASM_SPINLOCK_H
#define __ASM_SPINLOCK_H

#include <asm/system.h>

/*
 * Simple spin lock operations.
 */

typedef struct {
	volatile unsigned long lock;
#ifdef CONFIG_DEBUG_SPINLOCK
	volatile unsigned long owner_pc;
	volatile unsigned long owner_cpu;
#endif
#ifdef CONFIG_PREEMPT
	unsigned int break_lock;
#endif
} spinlock_t;


#endif /* __ASM_SPINLOCK_H */

