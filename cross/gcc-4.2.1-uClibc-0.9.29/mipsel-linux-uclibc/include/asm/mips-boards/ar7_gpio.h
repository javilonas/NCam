/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ar7_gpio_h
#define _ar7_gpio_h

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ar7/hw_gpio.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
void ar7_gpio_init(void);
int ar7_gpio_ctrl(unsigned int gpio_pin, enum _hw_gpio_function pin_mode, enum _hw_gpio_direction pin_dir);
int ar7_gpio_out_bit(unsigned int gpio_pin, int value);
int ar7_gpio_in_bit(unsigned int gpio_pin);
unsigned int ar7_gpio_in_value(void);
void ar7_gpio_set_bitmask(unsigned int mask, unsigned int value);





#endif /*--- #ifndef _ar7_gpio_h ---*/
