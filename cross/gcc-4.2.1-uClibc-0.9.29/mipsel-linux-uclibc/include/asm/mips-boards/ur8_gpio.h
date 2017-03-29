/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ur8_gpio_h
#define _ur8_gpio_h

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ur8/hw_gpio.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
void ur8_gpio_init(void);
int ur8_gpio_ctrl(unsigned int gpio_pin, enum _hw_gpio_function pin_mode, enum _hw_gpio_direction pin_dir);
int ur8_gpio_out_bit(unsigned int gpio_pin, int value);
int ur8_gpio_in_bit(unsigned int gpio_pin);
unsigned int ur8_gpio_in_value(void);
void ur8_gpio_set_bitmask(unsigned int mask, unsigned int value);





#endif /*--- #ifndef _ur8_gpio_h ---*/
