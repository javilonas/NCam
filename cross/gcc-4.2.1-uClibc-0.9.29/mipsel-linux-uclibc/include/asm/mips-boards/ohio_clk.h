#ifndef _ohio_clk_h_
#define _ohio_clk_h_

#include <asm/mach_avm.h>
#if defined(CONFIG_MIPS_OHIO)
#include <asm/mach-ohio/hw_clock.h>

unsigned int ohio_clk_get_pll_factor(struct _ohio_clock_pll *pll, unsigned int count);
unsigned int ohio_get_clock(enum _avm_clock_id);
unsigned int ohio_set_clock(enum _avm_clock_id, unsigned int);
#if defined(CONFIG_OHIO_CLOCK_SWITCH)
unsigned int ohio_get_clock_notify(enum _avm_clock_id, unsigned int (*)(enum _avm_clock_id, unsigned int new_clk));
#endif /*--- #if defined(CONFIG_OHIO_CLOCK_SWITCH) ---*/
unsigned int ohio_set_system_clock_notify(enum _avm_clock_id, unsigned int (*)(enum _avm_clock_id, unsigned int new_clk), int);

#endif/*--- #if defined(CONFIG_MIPS_OHIO) ---*/
#endif /*--- #ifndef _ohio_clk_h_ ---*/

