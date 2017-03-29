/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ar7_reset_h_
#define _ar7_reset_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define AR7_RESET_START_GPIO          32
#define AR7_RESET_END_GPIO          (32 + AR7_RESET_START_GPIO)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(CONFIG_VLYNQ_SUPPORT)
#include <asm/mips-boards/ar7_vlynq.h>
#define AR7_MAX_RESET_VIRTUAL            (32 * MAX_VLYNQ_DEVICES)
#define AR7_RESET_START_VIRTUAL          AR7_RESET_END_GPIO
#define AR7_RESET_END_VIRTUAL            (AR7_MAX_RESET_VIRTUAL + AR7_RESET_START_VIRTUAL)

#endif /*--- #if defined(CONFIG_VLYNQ_SUPPORT) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ar7_reset_init(void);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ar7_take_device_out_of_reset(unsigned int Bit);
int ar7_put_device_into_reset(unsigned int Bit);
int ar7_reset_device(unsigned int Bit, unsigned int delay);
unsigned int ar7_reset_status(void);


/*------------------------------------------------------------------------------------------*\
 * diese Funktionen dienen dazu ein GPIO Pin als Reset fuer ein externes
 * device zu definieren. Polarity = TRUE bedeutet dass das device im Reset
 * ist wenn der GPIO PIN high ist.
 *
 * Rückgabewert der Funktion ist die Bit-Nummer die bei den Reset Funktionen
 * anzugeben ist.
 *
 * Im Fehlerfall wird -1 zurueckgegeben.
\*------------------------------------------------------------------------------------------*/
typedef enum{
	LOW_ACTIVE=0,	/* Reset ist bei NULL-Pegel aktiv */
	HIGH_ACTIVE		/* Reset ist bei hohem Pregel aktiv */
} t_reset_gpio_polarity;

int ar7_register_reset_gpio(unsigned int gpio_pin, t_reset_gpio_polarity Polarity);
int ar7_release_reset_gpio(unsigned int gpio_pin);



#endif /*--- #ifndef _ar7_reset_h_ ---*/
