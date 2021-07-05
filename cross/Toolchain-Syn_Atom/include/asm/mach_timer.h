/*
 *  Machine specific calibrate_tsc() for generic.
 *  Split out from timer_tsc.c by Osamu Tomita <tomita@cinet.co.jp>
 */
/* ------ Calibrate the TSC ------- 
 * Return 2^32 * (1 / (TSC clocks per usec)) for do_fast_gettimeoffset().
 * Too much 64-bit arithmetic here to do this cleanly in C, and for
 * accuracy's sake we want to keep the overhead on the CTC speaker (channel 2)
 * output busy loop as low as possible. We avoid reading the CTC registers
 * directly because of the awkward 8-bit access mechanism of the 82C54
 * device.
 */
#ifndef _ASM_X86_MACH_DEFAULT_MACH_TIMER_H
#define _ASM_X86_MACH_DEFAULT_MACH_TIMER_H

#define CALIBRATE_TIME_MSEC 30 /* 30 msecs */
#define CALIBRATE_LATCH	\
	((CLOCK_TICK_RATE * CALIBRATE_TIME_MSEC + 1000/2)/1000)

static inline void mach_prepare_counter(void)
{
       /* Set the Gate high, disable speaker */
	outb((inb(0x61) & ~0x02) | 0x01, 0x61);

	/*
	 * Now let's take care of CTC channel 2
	 *
	 * Set the Gate high, program CTC channel 2 for mode 0,
	 * (interrupt on terminal count mode), binary count,
	 * load 5 * LATCH count, (LSB and MSB) to begin countdown.
	 *
	 * Some devices need a delay here.
	 */
	outb(0xb0, 0x43);			/* binary, mode 0, LSB/MSB, Ch 2 */
	outb_p(CALIBRATE_LATCH & 0xff, 0x42);	/* LSB of count */
	outb_p(CALIBRATE_LATCH >> 8, 0x42);       /* MSB of count */
}

static inline void mach_countup(unsigned long *count_p)
{
	unsigned long count = 0;
#ifdef CONFIG_ARCH_GEN3
/*
 * The 8254 timer flop has an issue between the reset and set pin of a flop.
 * This causes a race condition to happen and the value can change based on
 * clock sku. The workaround for this silicon issue uses a polling method which
 * is not affected by race condition. If this workaround is not applied, then the
 * cpu MHz entry in /proc/cpuinfo may show the wrong information. This workaround
 * is for errata number 22 in Errata - A Step. 
*/
	u8 count1;
	u8 count2;
	do {
		count++;
		outb(0x80, 0x43);
		count1 = inb(0x42);
		count2 = inb(0x42);
	} while (count1 >= 0x20 || count2 != 0);
#else
	do {
		count++;
	} while ((inb_p(0x61) & 0x20) == 0);
#endif
	*count_p = count;
}

#endif /* _ASM_X86_MACH_DEFAULT_MACH_TIMER_H */
