/*
 * linux/include/linux/hrtimers.h
 *
 *                           by George Anzinger george@mvista.com
 *
 *			     Copyright (C) 2005 by MontaVista Software.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * MontaVista Software | 1237 East Arques Avenue | Sunnyvale | CA 94085 | USA
 */
#ifndef _LINUX_HRTIMERS
#define _LINUX_HRTIMERS

#include <linux/hrtime.h>
#include <linux/timer.h>

#ifdef CONFIG_HIGH_RES_TIMERS
extern void init_hrtimers(void);
extern void do_handle_expired_timer(struct timer_list *timer);
extern void do_high_res_timer(struct timer_list *timer, spinlock_t *lock);
extern void hrtimers_expire_timers(void);

#define handle_expired_timer(timer) do {				\
                                        do_handle_expired_timer(timer);	\
                                        return; 			\
                                       } while (0)

#define check_for_high_res_timer(timer, lock, go_to)			\
                    do {						\
                         if (unlikely(timer->arch_cycle_expires)) {	\
			    do_high_res_timer(timer, lock);		\
                            go_to;					\
                          }						\
                       } while (0)

#define done_to_high_res() hrtimers_expire_timers()
#else
#define init_hrtimers()
#define handle_expired_timer(timer) \
                        vec = base->tv1.vec + (base->timer_jiffies & TVR_MASK)

#define check_for_high_res_timer(timer, lock, go_to)
#define done_to_high_res()
#endif 

#endif
