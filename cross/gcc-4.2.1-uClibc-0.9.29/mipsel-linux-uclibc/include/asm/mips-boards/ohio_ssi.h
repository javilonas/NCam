/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _gpio_h_
#define _gpio_h_

int gpio_dataonly_test(void);
void gpio_ssi_init(void);
void gpio_ssi_select(unsigned int chip, unsigned int select);
unsigned int gpio_ssi_read(void);
unsigned int gpio_ssi_detect0_and_read(unsigned char* buffer);
void gpio_ssi_write(unsigned int byte);

#endif /*--- #ifndef _gpio_h_ ---*/
