/*------------------------------------------------------------------------------------------*\
 *   
 *   Copyright (C) 2006 AVM GmbH <fritzbox_info@avm.de>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
\*------------------------------------------------------------------------------------------*/
#ifndef _avm_profile_h_
#define _avm_profile_h_

#if defined(CONFIG_AVM_SIMPLE_PROFILING)

enum _avm_profile_data_type {
    avm_profile_data_type_free,
    avm_profile_data_type_text,
    avm_profile_data_type_code_address_info,
    avm_profile_data_type_data_address_info,
    avm_profile_data_type_trace_skb,
    avm_profile_data_type_hw_irq_begin,
    avm_profile_data_type_hw_irq_end,
    avm_profile_data_type_sw_irq_begin,
    avm_profile_data_type_sw_irq_end,
    avm_profile_data_type_timer_begin,
    avm_profile_data_type_timer_end,
    avm_profile_data_type_tasklet_begin,
    avm_profile_data_type_tasklet_end,
    avm_profile_data_type_hi_tasklet_begin,
    avm_profile_data_type_hi_tasklet_end,
    avm_profile_data_type_workitem_begin,
    avm_profile_data_type_workitem_end,
    avm_profile_data_type_cpphytx_begin,
    avm_profile_data_type_cpphytx_end,
    avm_profile_data_type_cpphyrx_begin,
    avm_profile_data_type_cpphyrx_end,
    avm_profile_data_type_func_begin,
    avm_profile_data_type_func_end,
    avm_profile_data_type_unknown
};

struct _avm_profile_data {
    enum _avm_profile_data_type type : 16;
    struct task_struct *curr;
    unsigned int id : 16;
    unsigned int addr;  /* obersten 3 bit geben die quelle an */
    unsigned int time;
    unsigned int total_access;
    unsigned int total_activate;
};

void avm_simple_profiling_text(const  char *text);
void avm_simple_profiling_log(enum _avm_profile_data_type type, unsigned int addr, unsigned int id);
unsigned int avm_simple_profiling(struct pt_regs *regs, unsigned int irqnum);
struct _avm_profile_data *avm_simple_profiling_enable(unsigned int on, unsigned int *count, unsigned long *timediff);

#include <asm/mips-boards/ohio.h>
#include <asm/mach-ohio/hw_emif.h>
/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
static inline unsigned int avm_profile_sdramacess(void) {
    struct EMIF_register_memory_map *OHIO_EMIF_register_memory_map = (struct EMIF_register_memory_map *)OHIO_EMIF_BASE;
    return OHIO_EMIF_register_memory_map->TotalAccesses; 
}
/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
static inline unsigned int avm_profile_sdramactivate(void) {
    struct EMIF_register_memory_map *OHIO_EMIF_register_memory_map = (struct EMIF_register_memory_map *)OHIO_EMIF_BASE;
    return OHIO_EMIF_register_memory_map->TotalActivate; 
}
#define avm_profile_counter()   read_c0_count()

#else /*--- #if defined(CONFIG_AVM_SIMPLE_PROFILING) ---*/
#define avm_profile_counter()
#define avm_simple_profiling_text(text)
#define avm_simple_profiling_log(type, addr, id)
#define avm_simple_profiling(regs, irqnum)
#define avm_simple_profiling_enable(on, count, timediff)     NULL;
#endif /*--- #else ---*/ /*--- #if defined(CONFIG_AVM_SIMPLE_PROFILING) ---*/

#endif /*--- #ifndef _avm_profile_h_ ---*/
