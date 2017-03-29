/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ohio_gpio_h
#define _ohio_gpio_h

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ohio/hw_gpio.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
void ohio_gpio_init(void);
int ohio_gpio_ctrl(unsigned int gpio_pin, enum _hw_gpio_function pin_mode, enum _hw_gpio_direction pin_dir);
int ohio_gpio_out_bit(unsigned int gpio_pin, int value);
int ohio_gpio_in_bit(unsigned int gpio_pin);
unsigned int ohio_gpio_in_value(void);
void ohio_gpio_set_bitmask(unsigned int mask, unsigned int value);





#endif /*--- #ifndef _ohio_gpio_h ---*/
