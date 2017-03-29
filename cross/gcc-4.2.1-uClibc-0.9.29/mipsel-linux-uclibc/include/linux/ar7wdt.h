/*------------------------------------------------------------------------------------------*\
 *   
 *   Copyright (C) 2006 AVM GmbH <fritzbox_info@avm.de>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
\*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*\
 *
 *  $Id$
 *
 *  $Log$
 *
\*------------------------------------------------------------------------------------------*/
#ifndef _linux_ar7wdt_h_
#define _linux_ar7wdt_h_



/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define MAX_WDT_NAME_LEN        64
#define MAX_WDT_APPLS           31   /*--- Position 31 ist fuer init-ueberwachung reserviert ---*/
#define WDT_DEFAULT_TIME        10   /*--- 10 Sekunden ---*/

struct _ar7wdt_command_queue {
    unsigned int rd, wr;
    unsigned char cmd[8];
};

struct _ar7wdt_appl_data {
    char Name[MAX_WDT_NAME_LEN + 1];
    unsigned int default_time;
	struct timer_list Timer;
    unsigned int *pf_owner;
    struct fasync_struct *fasync;
	wait_queue_head_t wait_queue;
};

struct _ar7wdt_data {
    unsigned int mask;
    unsigned int triggered;
    unsigned int requested;
    unsigned int states; /*--- timer schon einmal erfolglos abgelaufen ---*/
    struct _ar7wdt_appl_data appl[MAX_WDT_APPLS + 1];
#if MAX_WDT_APPLS > 31
#error MAX_WDT_APPLS darf maximal 31 sein
#endif
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
extern int AR7WDT_register(int, char *, int);
extern int AR7WDT_release(int, char *, int);
extern int AR7WDT_set_timeout(int, char *, int);
extern int AR7WDT_trigger(int, char *, int);
extern int AR7WDT_disable(int, char *, int);
extern int AR7WDT_read(int, char *, int);
extern int AR7WDT_init_start(int, char *, int);
extern int AR7WDT_init_done(int, char *, int);
extern int AR7WDT_reboot(int);
extern int AR7WDT_poll(int);
extern void AR7WDT_ungraceful_release(int);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
extern void AR7WDT_init(void);
extern void AR7WDT_deinit(void);
extern void AR7WDT_check_all_triggered(void);
extern struct fasync_struct **AR7WDT_get_fasync_ptr(int handle);
extern wait_queue_head_t *AR7WDT_get_wait_queue(int handle);
extern int ar7wdt_no_reboot;



/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
void ar7wdt_hw_trigger(void);
void ar7wdt_hw_reboot(void);
void ar7wdt_hw_deinit(void);
void ar7wdt_hw_init(void);








#endif /*--- #ifndef _linux_ar7wdt_h_ ---*/
