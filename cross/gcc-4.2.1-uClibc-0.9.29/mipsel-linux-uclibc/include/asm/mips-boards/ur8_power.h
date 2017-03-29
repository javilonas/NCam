/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ur8_power_h_
#define _ur8_power_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define UR8_POWER_START_GPIO          32
#define UR8_POWER_END_GPIO          (32 + UR8_POWER_START_GPIO)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(CONFIG_VLYNQ_SUPPORT)
#include <asm/mips-boards/ur8_vlynq.h>
#define UR8_MAX_POWER_VIRTUAL            (32 * MAX_VLYNQ_DEVICES)
#define UR8_POWER_START_VIRTUAL          UR8_POWER_END_GPIO
#define UR8_POWER_END_VIRTUAL            (UR8_MAX_POWER_VIRTUAL + UR8_POWER_START_VIRTUAL)

#endif /*--- #if defined(CONFIG_VLYNQ_SUPPORT) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ur8_power_down_init(void);
int ur8_put_device_into_power_down(unsigned int Bit);
int ur8_take_device_out_of_power_down(unsigned int Bit);
int ur8_register_power_down_gpio(unsigned int gpio_pin, unsigned int Polarity);
int ur8_release_power_down_gpio(unsigned int Bit);
unsigned int ur8_power_down_status(void);



#endif /*--- #ifndef _ur8_power_h_ ---*/
