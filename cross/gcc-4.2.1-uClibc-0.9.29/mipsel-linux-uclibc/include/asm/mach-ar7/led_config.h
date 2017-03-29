/******************************************************************************    
 * FILE PURPOSE:     - LED config Header                                       
 ******************************************************************************    
 * FILE NAME:     led_config.h                                                        
 *                                                                                 
 * DESCRIPTION:  Header file for LED configuration parameters
 *               and data structures                                                 
 *                                                                                 
 * REVISION HISTORY:                                                               
 * 11 Oct 03 - PSP TII                                                             
 *                                                                                 
 * (C) Copyright 2002, Texas Instruments, Inc                                      
 *******************************************************************************/  
                                                                                   

#ifndef __LED_CONFIG__
#define __LED_CONFIG__

/* LED config parameters */
#define  MAX_GPIO_PIN_NUM           64
#define  MAX_GPIOS_PER_STATE         5
#define  MAX_MODULE_ENTRIES         25
#define  MAX_MODULE_INSTANCES        4
#define  MAX_STATE_ENTRIES          25
#define  MAX_LED_ENTRIES            25


/* LED modes */
#define LED_OFF                    0
#define LED_ON                     1
#define LED_ONESHOT_OFF            2
#define LED_ONESHOT_ON             3
#define LED_FLASH                  4
#define LED_BLINK_CODE0            5    /*--- param1: on time, param2: blink nr , (param2 > 100 blink off) ---*/
#define LED_BLINK_CODE1            6 
#define LED_BLINK_CODE2            7 

#define NUM_LED_MODES              8



/* Data structure for LED configuration */
typedef struct led_config {
    char name[80];
    unsigned int instance;
    unsigned int state;
    unsigned int gpio[MAX_GPIOS_PER_STATE];
    unsigned int mode[MAX_GPIOS_PER_STATE];
    unsigned int gpio_num;
    unsigned int param1;
    unsigned int param2;
    unsigned int event_id;
    char event_name[80];
} LED_CONFIG_T;


#endif /* __LED_CONFIG__ */
