/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ohio_power_h_
#define _ohio_power_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define OHIO_POWER_START_GPIO          32
#define OHIO_POWER_END_GPIO          (32 + OHIO_POWER_START_GPIO)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(CONFIG_VLYNQ_SUPPORT)
#include <asm/mips-boards/ohio_vlynq.h>
#define OHIO_MAX_POWER_VIRTUAL            (32 * MAX_VLYNQ_DEVICES)
#define OHIO_POWER_START_VIRTUAL          OHIO_POWER_END_GPIO
#define OHIO_POWER_END_VIRTUAL            (OHIO_MAX_POWER_VIRTUAL + OHIO_POWER_START_VIRTUAL)

#endif /*--- #if defined(CONFIG_VLYNQ_SUPPORT) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ohio_power_down_init(void);
int ohio_put_device_into_power_down(unsigned int Bit);
int ohio_take_device_out_of_power_down(unsigned int Bit);
int ohio_register_power_down_gpio(unsigned int gpio_pin, unsigned int Polarity);
int ohio_release_power_down_gpio(unsigned int Bit);
unsigned int ohio_power_down_status(void);



#endif /*--- #ifndef _ohio_power_h_ ---*/
