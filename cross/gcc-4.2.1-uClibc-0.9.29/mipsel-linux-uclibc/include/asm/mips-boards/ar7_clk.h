#ifndef _ar7_clk_h_
#define _ar7_clk_h_

#include <linux/config.h>
#include <asm/mach_avm.h>
#include <asm/mach-ar7/hw_clock.h>

unsigned int ar7_clk_get_pll_factor(enum _avm_clock_id, struct _hw_clock *hw_clock, unsigned int count);
unsigned int ar7_get_clock(enum _avm_clock_id);
unsigned int ar7_set_clock(enum _avm_clock_id, unsigned int);
#if defined(CONFIG_AR7_CLOCK_SWITCH)
unsigned int ar7_get_clock_notify(enum _avm_clock_id, unsigned int (*)(enum _avm_clock_id, unsigned int new_clk));
#endif /*--- #if defined(CONFIG_AR7_CLOCK_SWITCH) ---*/
unsigned int ar7_set_system_clock_notify(enum _avm_clock_id, unsigned int (*)(enum _avm_clock_id, unsigned int new_clk), int);

#endif /*--- #ifndef _ar7_clk_h_ ---*/
