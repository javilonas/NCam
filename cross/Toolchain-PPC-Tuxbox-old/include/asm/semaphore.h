#ifndef _PPC_SEMAPHORE_H
#define _PPC_SEMAPHORE_H

/*
 * Swiped from asm-sparc/semaphore.h and modified
 * -- Cort (cort@cs.nmt.edu)
 *
 * Stole some rw spinlock-based semaphore stuff from asm-alpha/semaphore.h
 * -- Ani Joshi (ajoshi@unixbox.com)
 *
 * Remove spinlock-based RW semaphores; RW semaphore definitions are
 * now in rwsem.h and we use the generic lib/rwsem.c implementation.
 * Rework semaphores to use atomic_dec_if_positive.
 * -- Paul Mackerras (paulus@samba.org)
 */

#endif /* !(_PPC_SEMAPHORE_H) */
