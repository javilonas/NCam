/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ohio_reset_h_
#define _ohio_reset_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define OHIO_RESET_START_GPIO          32
#define OHIO_RESET_END_GPIO          (32 + OHIO_RESET_START_GPIO)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(CONFIG_VLYNQ_SUPPORT)
#include <asm/mips-boards/ohio_vlynq.h>
#define OHIO_MAX_RESET_VIRTUAL            (32 * MAX_VLYNQ_DEVICES)
#define OHIO_RESET_START_VIRTUAL          OHIO_RESET_END_GPIO
#define OHIO_RESET_END_VIRTUAL            (OHIO_MAX_RESET_VIRTUAL + OHIO_RESET_START_VIRTUAL)

#endif /*--- #if defined(CONFIG_VLYNQ_SUPPORT) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ohio_reset_init(void);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ohio_take_device_out_of_reset(unsigned int Bit);
int ohio_put_device_into_reset(unsigned int Bit);
int ohio_reset_device(unsigned int Bit, unsigned int delay);
unsigned int ohio_reset_status(void);


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

int ohio_register_reset_gpio(unsigned int gpio_pin, t_reset_gpio_polarity Polarity);
int ohio_release_reset_gpio(unsigned int gpio_pin);



#endif /*--- #ifndef _ohio_reset_h_ ---*/
