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
\*------------------------------------------------------------------------------------------*/
#ifndef _linux_avm_led_h_
#define _linux_avm_led_h_

#include <linux/config.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define AVM_LED_STATE_TABLE_SIZE        0x100
#define AVM_LED_GOTO_PRIVIOUS_STATE     AVM_LED_STATE_TABLE_SIZE        

#if defined(CONFIG_AVM_LED_BIER_HOLEN)
#define AVM_LED_MAX_MODE_DRIVER         12
#else /*--- #if defined(CONFIG_AVM_LED_BIER_HOLEN) ---*/
#define AVM_LED_MAX_MODE_DRIVER         9
#endif /*--- #else ---*/ /*--- #if defined(CONFIG_AVM_LED_BIER_HOLEN) ---*/

#define AVM_LED_MAX_GPIO_DRIVER         8
#define AVM_LED_GPIO_DRIVER_INCREDIBLE  99
#define AVM_LED_MAX_INSTANCE            10

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define AVM_LED_MONITOR_ACTION          0x0001
#define AVM_LED_MONITOR_MAP             0x0002
#define AVM_LED_MONITOR_RELEASE         0x0004
#define AVM_LED_MONITOR_REGISTER        0x0008
#define AVM_LED_MONITOR_USER            0x0010
#define AVM_LED_MONITOR_MAP_STATE       0x0020
#define AVM_LED_MONITOR_CTRL            0x0040

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _avm_led_frequency {
    avm_led_frequency_0_5Hz = 0,
    avm_led_frequency_1Hz   = 1,
    avm_led_frequency_2Hz   = 2,
    avm_led_frequency_4Hz   = 3
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _avm_led_modi {
    avm_led_off                     = 0x000,
    avm_led_on,
    avm_led_previous,

    avm_led_bier_holen_6000ms        = 0x003,
    avm_led_bier_holen_4000ms,
    avm_led_bier_holen_3000ms,
    avm_led_bier_holen_2000ms,
    avm_led_bier_holen_1500ms,

    avm_led_flash_on_1000ms         = 0x008,
    avm_led_flash_on_500ms,
    avm_led_flash_on_250ms,
    avm_led_flash_on_125ms,

    avm_led_flash_off_1000ms        = 0x00C,
    avm_led_flash_off_500ms,
    avm_led_flash_off_250ms,
    avm_led_flash_off_125ms,

    avm_led_symmetric_blink_0_5Hz    = 0x010,
    avm_led_symmetric_blink_1Hz,
    avm_led_symmetric_blink_2Hz,
    avm_led_symmetric_blink_4Hz,

    avm_led_walkingled_4000ms       = 0x014,
    avm_led_walkingled_3000ms,
    avm_led_walkingled_2000ms,
    avm_led_walkingled_1000ms,

    /*--------------------------------------------------------------------------------------*\
     *  Blink code 3 _X_X_X_____X_X_X___
     *  0 < repeat < 16
     *  Hz: 0.5, 1.0, 2.0, 4.0
     *  (0x40 Codes)
    \*--------------------------------------------------------------------------------------*/
    avm_led_blink_1_code_0_5Hz      = 0x040,
    avm_led_blink_1_code_1Hz,
    avm_led_blink_1_code_2Hz,
    avm_led_blink_1_code_4Hz,

    avm_led_blink_2_code_0_5Hz,
    avm_led_blink_2_code_1Hz,
    avm_led_blink_2_code_2Hz,
    avm_led_blink_2_code_4Hz,

#define AVM_LED_BLINK_CODE(repeat, freq)    (avm_led_blink_1_code_0_5Hz + (repeat * 4) + freq)
#define AVM_LED_BLINK_CODE_0_5Hz(repeat)    AVM_LED_BLINK_CODE((repeat), avm_led_frequency_0_5Hz)
#define AVM_LED_BLINK_CODE_1Hz(repeat)      AVM_LED_BLINK_CODE((repeat), avm_led_frequency_1Hz)   
#define AVM_LED_BLINK_CODE_2Hz(repeat)      AVM_LED_BLINK_CODE((repeat), avm_led_frequency_2Hz)
#define AVM_LED_BLINK_CODE_4Hz(repeat)      AVM_LED_BLINK_CODE((repeat), avm_led_frequency_4Hz)

    /*--------------------------------------------------------------------------------------*\
     *  Blink code 3 _XX_XX___XX_XX___XX_XX_________XX_XX___XX_XX___XX_XX_________
     *  0 < repeat < 16
     *  Hz: 0.5, 1.0, 2.0, 4.0
     *  (0x40 Codes)
    \*--------------------------------------------------------------------------------------*/
    avm_led_double_blink_1_code_0_5Hz      = 0x080,
    avm_led_double_blink_1_code_1Hz,
    avm_led_double_blink_1_code_2Hz,
    avm_led_double_blink_1_code_4Hz,

    avm_led_double_blink_2_code_0_5Hz,
    avm_led_double_blink_2_code_1Hz,
    avm_led_double_blink_2_code_2Hz,
    avm_led_double_blink_2_code_4Hz,

#define AVM_LED_DOUBLE_BLINK_CODE(repeat, freq)    (avm_led_double_blink_1_code_0_5Hz + (repeat * 4) + freq)
#define AVM_LED_DOUBLE_BLINK_CODE_0_5Hz(repeat)    AVM_LED_DOUBLE_BLINK_CODE((repeat), avm_led_frequency_0_5Hz)
#define AVM_LED_DOUBLE_BLINK_CODE_1Hz(repeat)      AVM_LED_DOUBLE_BLINK_CODE((repeat), avm_led_frequency_1Hz)   
#define AVM_LED_DOUBLE_BLINK_CODE_2Hz(repeat)      AVM_LED_DOUBLE_BLINK_CODE((repeat), avm_led_frequency_2Hz)
#define AVM_LED_DOUBLE_BLINK_CODE_4Hz(repeat)      AVM_LED_DOUBLE_BLINK_CODE((repeat), avm_led_frequency_4Hz)

    /*--------------------------------------------------------------------------------------*\
     *  Blink code 3 _XX_XX___X_X___XX_XX___X_X____XX_XX___X_X__________XX_XX___X_X___XX_XX___X_X____XX_XX___X_X_________
     *  0 < repeat < 16
     *  Hz: 0.5, 1.0, 2.0, 4.0
     *  (0x40 Codes)
    \*--------------------------------------------------------------------------------------*/
    avm_led_double_mixed_blink_1_code_0_5Hz      = 0x0C0,
    avm_led_double_mixed_blink_1_code_1Hz,
    avm_led_double_mixed_blink_1_code_2Hz,
    avm_led_double_mixed_blink_1_code_4Hz,

    avm_led_double_mixed_blink_2_code_0_5Hz,
    avm_led_double_mixed_blink_2_code_1Hz,
    avm_led_double_mixed_blink_2_code_2Hz,
    avm_led_double_mixed_blink_2_code_4Hz,

#define AVM_LED_DOUBLE_MIXED_BLINK_CODE(repeat, freq)    (avm_led_double_mixed_blink_1_code_0_5Hz + (repeat * 4) + freq)
#define AVM_LED_DOUBLE_MIXED_BLINK_CODE_0_5Hz(repeat)    AVM_LED_DOUBLE_MIXED_BLINK_CODE((repeat), avm_led_frequency_0_5Hz)
#define AVM_LED_DOUBLE_MIXED_BLINK_CODE_1Hz(repeat)      AVM_LED_DOUBLE_MIXED_BLINK_CODE((repeat), avm_led_frequency_1Hz)   
#define AVM_LED_DOUBLE_MIXED_BLINK_CODE_2Hz(repeat)      AVM_LED_DOUBLE_MIXED_BLINK_CODE((repeat), avm_led_frequency_2Hz)
#define AVM_LED_DOUBLE_MIXED_BLINK_CODE_4Hz(repeat)      AVM_LED_DOUBLE_MIXED_BLINK_CODE((repeat), avm_led_frequency_4Hz)

    avm_led_last_state = AVM_LED_STATE_TABLE_SIZE
};


/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _avm_led_register_struct {
    char name[32];
    unsigned int instance;
    unsigned int driver_type;  /* 0 single pin gpio, 1 all pin gpio ... */
    unsigned int gpio;      /* -1 no physikal led connected */
    unsigned int led_pos;
    char led_name[32];
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _avm_led_release_struct {
    char name[32];
    unsigned int instance;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _avm_led_action_struct {
    char name[32];
    unsigned int instance;
    unsigned int state;
    void *event;
    unsigned int event_size;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _avm_led_map_struct {
    char from_name[32];
    unsigned int from_instance;
    char to_name[32];
    unsigned int to_instance;
    unsigned int both;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _avm_led_unmap_struct {
    char name[32];
    unsigned int instance;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define LED_REGISTER            0
#define LED_RELEASE             1
#define LED_ACTION              2
#define LED_ACTION_WITH_EVENT   3
#define LED_MAP                 4
#define LED_UNMAP               5

/*------------------------------------------------------------------------------------------*\
 * avm_led_if.c
\*------------------------------------------------------------------------------------------*/
int avm_led_alloc_handle(char *name, int instance, void (*remove_call_back)(int));
int avm_led_free_handle(int handle);
void avm_led_action_with_handle(int handle, int state);
void avm_led_action_with_name_and_instance(char *name, int instance, int state);

/*-------------------------------------------------------------------------------------*\
 * avm_led_file.c
\*-------------------------------------------------------------------------------------*/
int avm_led_load_config(void);


#endif /*--- #ifndef _linux_avm_led_h_ ---*/
