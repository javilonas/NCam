/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _hardware_error_h_
#define _hardware_error_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define HARDWARE_ERROR_ISDN_IPAC        "I001"
#define HARDWARE_ERROR_AB_              "A001"
#define HARDWARE_ERROR_DSL_12VOLT       "D001"
#define HARDWARE_ERROR_WLAN             "W001"

/*------------------------------------------------------------------------------------------*\
 * aus  hardtest.h uebernommen
\*------------------------------------------------------------------------------------------*/
#define ROMLOW_ERR_LED                  1
#define ROMHIGH_ERR_LED                 2
#define CLASS_VERSION_ERR_LED           3

#define ISACINTOFF_ERR_LED              4
#define ISACINTON_ERR_LED               5
#define VOLTAGE_FAIL                    5  /*--- 12 Volt versorgungsfehler ---*/

#define ISAC_ERR_LED                    6  /*--- isac ---*/
#define CAPIINIT_ERR_LED                7  /*--- analog AB ---*/
#define RAM_ERR_LED                     8
#define DSL_BRIDGE_ERROR                8  /*--- die DSL Brigde haengt: hier hilft nur noch Power-Off ---*/

#define FIFO_ERR_LED                    9  /*--- usb ---*/
#define SL11_ERR_LED                    9

#define CPU_ERR_LED                     10

#define WLAN_ERR_LED                    11 /*--- wlan ---*/
#define PIGLET_ERR_LED                  11 /*--- bluetooth ---*/
#define BT_RADIO_ERR_16MHZ              12 
#define BT_RADIO_ERR_LED                13

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(__KERNEL__)
extern void hardware_error_init(void);
extern void hardware_error_log(char *error_msg, unsigned int blink_code);
#endif /*--- #if defined(__KERNEL__) ---*/

#endif /*--- #ifndef _hardware_error_h_ ---*/
