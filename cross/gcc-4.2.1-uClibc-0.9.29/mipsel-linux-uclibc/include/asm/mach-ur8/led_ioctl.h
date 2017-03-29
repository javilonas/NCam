/******************************************************************************   
 * FILE PURPOSE:     - LED ioctl Header                                           
 ******************************************************************************   
 * FILE NAME:     led_ioctl.h                                                     
 *                                                                                
 * DESCRIPTION:   Header file defining macros for ioctl commands.                 
 *                                                                                
 * REVISION HISTORY:                                                              
 * 11 Oct 03 - PSP TII                                                            
 *                                                                                
 * (C) Copyright 2002, Texas Instruments, Inc                                     
 *******************************************************************************/ 
#ifndef __LED_IOCTL__
#define __LED_IOCTL__

typedef struct led_mod {
unsigned char *name;
unsigned int instance;
unsigned int handle;
} LED_MODULE_T;

typedef struct led_state {
    unsigned int handle;
    unsigned int state_id;
    /*--- am ende erweitert ---*/
    unsigned int param_len;
    void *param;
} LED_STATE_T;

#define LED_CONFIG           0
#define LED_GET_HANDLE       1
#define LED_ACTION           2
#define LED_RELEASE_HANDLE   3
#define LED_CONFIG_DONE      4
#define LED_EVENT_ACTION     5

#endif /*  __LED_IOCTL__ */
