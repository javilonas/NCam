#ifndef _ur8_clk_h_
#define _ur8_clk_h_

#include <asm/mach_avm.h>
#include <asm/mach-ur8/hw_clock.h>

unsigned int ur8_clk_get_pll_factor(struct _ur8_clock_pll *pll, unsigned int count);
unsigned int ur8_get_clock(enum _avm_clock_id);
unsigned int ur8_set_clock(enum _avm_clock_id, unsigned int);
#if defined(CONFIG_UR8_CLOCK_SWITCH)
unsigned int ur8_get_clock_notify(enum _avm_clock_id, unsigned int (*)(enum _avm_clock_id, unsigned int new_clk));
#endif /*--- #if defined(CONFIG_UR8_CLOCK_SWITCH) ---*/
unsigned int ur8_set_system_clock_notify(enum _avm_clock_id, unsigned int (*)(enum _avm_clock_id, unsigned int new_clk), int);

#endif /*--- #ifndef _ur8_clk_h_ ---*/
