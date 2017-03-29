#ifndef _linux_POSIX_TIMERS_H
#define _linux_POSIX_TIMERS_H


struct k_clock {
	int res;		/* in nano seconds */
	int (*clock_getres) (clockid_t which_clock, struct timespec *tp);
	struct k_clock_abs *abs_struct;
	int (*clock_set) (clockid_t which_clock, struct timespec * tp);
	int (*clock_get) (clockid_t which_clock, struct timespec * tp);
	int (*timer_create) (struct k_itimer *timer);
	int (*nsleep) (clockid_t which_clock, int flags, struct timespec *);
	int (*timer_set) (struct k_itimer * timr, int flags,
			  struct itimerspec * new_setting,
			  struct itimerspec * old_setting);
	int (*timer_del) (struct k_itimer * timr);
#define TIMER_RETRY 1
	void (*timer_get) (struct k_itimer * timr,
			   struct itimerspec * cur_setting);
};

void register_posix_clock(clockid_t clock_id, struct k_clock *new_clock);

/* Error handlers for timer_create, nanosleep and settime */
int do_posix_clock_notimer_create(struct k_itimer *timer);
int do_posix_clock_nonanosleep(clockid_t, int flags, struct timespec *);
int do_posix_clock_nosettime(clockid_t, struct timespec *tp);

/* function to call to trigger timer event */
int posix_timer_event(struct k_itimer *timr, int si_private);

struct now_struct {
	unsigned long jiffies;
};

#define posix_get_now(now) (now)->jiffies = jiffies;
#define posix_time_before(timer, now) \
                      time_before((timer)->expires, (now)->jiffies)

#define posix_bump_timer(timr, now)					\
         do {								\
              long delta, orun;						\
	      delta = now.jiffies - (timr)->it.real.timer.expires;	\
              if (delta >= 0) {						\
	           orun = 1 + (delta / (timr)->it.real.incr);		\
	          (timr)->it.real.timer.expires +=			\
			 orun * (timr)->it.real.incr;			\
                  (timr)->it_overrun += orun;				\
              }								\
            }while (0)

int posix_cpu_clock_getres(clockid_t which_clock, struct timespec *);
int posix_cpu_clock_get(clockid_t which_clock, struct timespec *);
int posix_cpu_clock_set(clockid_t which_clock, const struct timespec *tp);
int posix_cpu_timer_create(struct k_itimer *);
int posix_cpu_nsleep(clockid_t, int, struct timespec *);
int posix_cpu_timer_set(struct k_itimer *, int,
			struct itimerspec *, struct itimerspec *);
int posix_cpu_timer_del(struct k_itimer *);
void posix_cpu_timer_get(struct k_itimer *, struct itimerspec *);

void posix_cpu_timer_schedule(struct k_itimer *);

void run_posix_cpu_timers(struct task_struct *);
void posix_cpu_timers_exit(struct task_struct *);
void posix_cpu_timers_exit_group(struct task_struct *);

void set_process_cpu_timer(struct task_struct *, unsigned int,
			   cputime_t *, cputime_t *);

#endif
