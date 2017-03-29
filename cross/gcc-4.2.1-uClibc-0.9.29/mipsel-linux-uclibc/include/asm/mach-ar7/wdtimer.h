/******************************************************************************
 * FILE PURPOSE:    Watchdog Timer Module Header
 ********************************************************************************
 * FILE NAME:       wdtimer.h
 *
 * DESCRIPTION:     Platform and OS independent API for watchdog timer module
 *
 * REVISION HISTORY:
 * 27 Nov 02 - PSP TII  
 * 
 * (C) Copyright 2002, Texas Instruments, Inc
 *******************************************************************************/


#ifndef __WDTIMER_H__
#define __WDTIMER_H__

/* Return Codes */
#define WDTIMER_RET_OK			0
#define WDTIMER_RET_ERR			-1
#define WDTIMER_ERR_INVAL		-2

/****************************************************************************
 * Type:        WDTIMER_STRUCT_T
 ****************************************************************************
 * Description: This type defines the hardware configuration of the 
 *              watchdog timer
 ***************************************************************************/
typedef struct WDTIMER_STRUCT_tag
{
    UINT32  kick_lock;
    UINT32  kick;
    UINT32  change_lock;
    UINT32  change ; 
    UINT32  disable_lock;
    UINT32  disable;
    UINT32  prescale_lock;
    UINT32  prescale;
} WDTIMER_STRUCT_T;


/****************************************************************************
 * Type:        WDTIMER_CTRL_T
 ****************************************************************************
 * Description: This type defines start and stop values for the timer. 
 *              
 ***************************************************************************/
typedef enum WDTIMER_CTRL_tag
{
    WDTIMER_CTRL_DISABLE = 0,
    WDTIMER_CTRL_ENABLE
} WDTIMER_CTRL_T ;

void wdtimer_init(UINT32 clk_freq);
extern int blabla(int);
INT32 wdtimer_set_period( UINT32 msec );
INT32 wdtimer_ctrl(WDTIMER_CTRL_T wd_ctrl);
INT32 wdtimer_kick(void);

#endif /* __WDTIMER_H__ */
