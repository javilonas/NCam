/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ur8_reset_h_
#define _ur8_reset_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define UR8_RESET_START_GPIO          32

// RSP inserted was 32
#define UR8_RESET_END_GPIO          (44 + UR8_RESET_START_GPIO)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(CONFIG_VLYNQ_SUPPORT)
#include <asm/mips-boards/ur8_vlynq.h>
#define UR8_MAX_RESET_VIRTUAL            (32 * MAX_VLYNQ_DEVICES)
#define UR8_RESET_START_VIRTUAL          UR8_RESET_END_GPIO
#define UR8_RESET_END_VIRTUAL            (UR8_MAX_RESET_VIRTUAL + UR8_RESET_START_VIRTUAL)

#endif /*--- #if defined(CONFIG_VLYNQ_SUPPORT) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ur8_reset_init(void);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ur8_take_device_out_of_reset(unsigned int Bit);
int ur8_put_device_into_reset(unsigned int Bit);
int ur8_reset_device(unsigned int Bit, unsigned int delay);
unsigned int ur8_reset_status(void);


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

int ur8_register_reset_gpio(unsigned int gpio_pin, t_reset_gpio_polarity Polarity);
int ur8_release_reset_gpio(unsigned int gpio_pin);



#endif /*--- #ifndef _ur8_reset_h_ ---*/
