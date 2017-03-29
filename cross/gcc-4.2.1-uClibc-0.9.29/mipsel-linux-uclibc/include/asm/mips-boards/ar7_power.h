/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ar7_power_h_
#define _ar7_power_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define AR7_POWER_START_GPIO          32
#define AR7_POWER_END_GPIO          (32 + AR7_POWER_START_GPIO)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(CONFIG_VLYNQ_SUPPORT)
#include <asm/mips-boards/ar7_vlynq.h>
#define AR7_MAX_POWER_VIRTUAL            (32 * MAX_VLYNQ_DEVICES)
#define AR7_POWER_START_VIRTUAL          AR7_POWER_END_GPIO
#define AR7_POWER_END_VIRTUAL            (AR7_MAX_POWER_VIRTUAL + AR7_POWER_START_VIRTUAL)

#endif /*--- #if defined(CONFIG_VLYNQ_SUPPORT) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ar7_power_down_init(void);
int ar7_put_device_into_power_down(unsigned int Bit);
int ar7_take_device_out_of_power_down(unsigned int Bit);
int ar7_register_power_down_gpio(unsigned int gpio_pin, unsigned int Polarity);
int ar7_release_power_down_gpio(unsigned int Bit);
unsigned int ar7_power_down_status(void);



#endif /*--- #ifndef _ar7_power_h_ ---*/
