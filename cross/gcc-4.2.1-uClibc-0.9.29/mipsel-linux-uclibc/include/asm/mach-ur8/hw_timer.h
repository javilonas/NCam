/*------------------------------------------------------------------------------------------*\
 *
 *  $Id$
 *
 *  $Log$
 *
\*------------------------------------------------------------------------------------------*/
#ifndef _hw_timer_h_
#define _hw_timer_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if !defined(NO_TYPES)
struct _timer_hw {
    union __timer_control {
        volatile unsigned int reg;
        volatile struct _timer_control {
            unsigned int go : 1;
            unsigned int mode : 1;
            unsigned int prescale : 4;
            unsigned int reserved1 : 9;
            unsigned int prescale_enable : 1;
            unsigned int reserved2 : 16;
        } Bits;
    } timer_control;
    volatile unsigned int timer_load_reg;
    volatile unsigned int timer_value_reg;
    volatile unsigned int timer_interrupt_reg;
};

extern struct _timer_hw * const T[2];
#endif /*--- #if !defined(NO_TYPES) ---*/

#endif /*--- #ifndef _hw_timer_h_ ---*/
