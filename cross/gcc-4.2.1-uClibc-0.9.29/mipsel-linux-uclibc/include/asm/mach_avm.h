#ifndef _mach_avm_h_
#define _mach_avm_h_

/*------------------------------------------------------------------------------------------*\
 * OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO OHIO 
\*------------------------------------------------------------------------------------------*/
#include <linux/config.h>
#ifdef CONFIG_MIPS_OHIO

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
void ohio_pre_init(void);
#define avm_pre_init ohio_pre_init

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _avm_clock_id {
    avm_clock_id_non        = 0x00,
    avm_clock_id_cpu        = 0x01,
    avm_clock_id_system     = 0x02,
    avm_clock_id_usb        = 0x04,
    avm_clock_id_dsp        = 0x08,
    avm_clock_id_vbus       = 0x10,
    avm_clock_id_peripheral = 0x20
};

#include <asm/mips-boards/ohio_clk.h>

#define avm_clk_get_pll_factor      ohio_clk_get_pll_factor
#define avm_get_clock               ohio_get_clock
#define avm_set_clock               ohio_set_clock
#define avm_get_clock_notify        ohio_get_clock_notify
#define avm_set_system_clock_notify ohio_set_system_clock_notify

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define MAX_ENV_ENTRY               256
#define FLASH_ENV_ENTRY_SIZE        64

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
char *avm_urlader_env_get_variable(int idx);
char *avm_urlader_env_get_value_by_id(unsigned int id);
char *avm_urlader_env_get_value(char *var);
int avm_urlader_env_set_variable(char *var, char *val);
int avm_urlader_env_unset_variable(char *var);
int avm_urlader_env_defrag(void);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ohio/hw_gpio.h>
#include <asm/mips-boards/ohio_gpio.h>

#define avm_gpio_init        ohio_gpio_init
#define avm_gpio_ctrl        ohio_gpio_ctrl
#define avm_gpio_out_bit     ohio_gpio_out_bit
#define avm_gpio_in_bit      ohio_gpio_in_bit
#define avm_gpio_in_value    ohio_gpio_in_value
#define avm_gpio_set_bitmask ohio_gpio_set_bitmask

/*------------------------------------------------------------------------------------------*\
 * 240-254 char	LOCAL/EXPERIMENTAL USE
 * 240-254 block	LOCAL/EXPERIMENTAL USE
 *         Allocated for local/experimental use.  For devices not
 *         assigned official numbers, these ranges should be
 *         used in order to avoid conflicting with future assignments.
\*------------------------------------------------------------------------------------------*/
#define RCAPI_MAJOR             225
/*--- kdsld_traffic = 226 ---*/
#define AVM_DECT_IO_MAJOR	    227
#define AVM_USERMAN_MAJOR	    228
#define KDSLD_USERMAN_MAJOR	    229
#define AVM_TIATM_MAJOR         230
#define TFFS_MAJOR              240
#define AVM_EVENT_MAJOR         241
#define WATCHDOG_MAJOR          242
#define KDSLD_MAJOR             243
#define KDSLDPTRACE_MAJOR       244
#define UBIK_MAJOR              245
#define DEBUG_TRACE_MAJOR       246
#define AVM_LED_MAJOR           247
#define AVM_I2C_MAJOR           248
#define YAFFS                   249
#define AVM_AUDIO_MAJOR         250
#define AVM_NEW_LED_MAJOR       251
#define AVM_POWER_MAJOR         252
#define AVM_VINAX_MAJOR		    253
#define AVM_HSK_MAJOR		    254
#define AVM_NET_TRACE_MAJOR	255

/*------------------------------------------------------------------------------------------*\
 * zusaetzlich folgende:
 *
 * 207 char	Compaq ProLiant health feature indicate
 * 220 char	Myricom Myrinet "GM" board
 * 224 char	A2232 serial card
 * 225 char	A2232 serial card (alternate devices)
 * 227 char	IBM 3270 terminal Unix tty access
 * 228 char	IBM 3270 terminal block-mode access
 * 229 char	IBM iSeries virtual console
 * 230 char	IBM iSeries virtual tape
 *
\*------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ohio_power.h>

#define avm_power_down_init               ohio_power_down_init
#define avm_put_device_into_power_down    ohio_put_device_into_power_down
#define avm_take_device_out_of_power_down ohio_take_device_out_of_power_down
#define avm_register_power_down_gpio      ohio_register_power_down_gpio
#define avm_release_power_down_gpio       ohio_release_power_down_gpio
#define avm_power_down_status             ohio_power_down_status

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ohio/hw_reset.h>
#include <asm/mips-boards/ohio_reset.h>

#define avm_reset_init                      ohio_reset_init
#define avm_take_device_out_of_reset        ohio_take_device_out_of_reset
#define avm_put_device_into_reset           ohio_put_device_into_reset
#define avm_reset_device                    ohio_reset_device
#define avm_reset_status                    ohio_reset_status
#define avm_register_reset_gpio		        ohio_register_reset_gpio
#define avm_release_reset_gpio		        ohio_release_reset_gpio

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ohio_vlynq.h>

#define avm_vlynq_init                      ohio_vlynq_init
#define avm_vlynq_init_link                 ohio_vlynq_init_link
#define avm_vlynq_alloc_context             ohio_vlynq_alloc_context
#define avm_vlynq_free_context              ohio_vlynq_free_context

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ohioint.h>

#define avm_int_init                        ohioint_init
#define avm_int_set_type                    ohioint_set_type
#define avm_int_ctrl_irq_pacing_setup       ohioint_ctrl_irq_pacing_setup
#define avm_int_ctrl_irq_pacing_register    ohioint_ctrl_irq_pacing_register
#define avm_int_ctrl_irq_pacing_unregister  ohioint_ctrl_irq_pacing_unregister
#define avm_int_ctrl_irq_pacing_set         ohioint_ctrl_irq_pacing_set
#define avm_nsec_timer                      ohio_nsec_timer

#endif /*--- #ifdef CONFIG_MIPS_OHIO ---*/

/*------------------------------------------------------------------------------------------*\
 * AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 AR7 
\*------------------------------------------------------------------------------------------*/
#ifdef CONFIG_MIPS_AR7

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
void ar7_pre_init(void);
#define avm_pre_init ar7_pre_init

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _avm_clock_id {
    avm_clock_id_non        = 0x00,
    avm_clock_id_cpu        = 0x01,
    avm_clock_id_system     = 0x02,
    avm_clock_id_usb        = 0x04,
    avm_clock_id_dsp        = 0x08,
    avm_clock_id_vbus       = 0x10,
    avm_clock_id_peripheral = 0x20
};

#include <asm/mips-boards/ar7_clk.h>

#define avm_clk_get_pll_factor      ar7_clk_get_pll_factor
#define avm_get_clock               ar7_get_clock
#define avm_set_clock               ar7_set_clock
#define avm_get_clock_notify        ar7_get_clock_notify
#define avm_set_system_clock_notify ar7_set_system_clock_notify

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define MAX_ENV_ENTRY               256
#define FLASH_ENV_ENTRY_SIZE        64

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
char *avm_urlader_env_get_variable(int idx);
char *avm_urlader_env_get_value_by_id(unsigned int id);
char *avm_urlader_env_get_value(char *var);
int avm_urlader_env_set_variable(char *var, char *val);
int avm_urlader_env_unset_variable(char *var);
int avm_urlader_env_defrag(void);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ar7/hw_gpio.h>
#include <asm/mips-boards/ar7_gpio.h>

#define avm_gpio_init        ar7_gpio_init
#define avm_gpio_ctrl        ar7_gpio_ctrl
#define avm_gpio_out_bit     ar7_gpio_out_bit
#define avm_gpio_in_bit      ar7_gpio_in_bit
#define avm_gpio_in_value    ar7_gpio_in_value
#define avm_gpio_set_bitmask ar7_gpio_set_bitmask

/*------------------------------------------------------------------------------------------*\
 * 240-254 char	LOCAL/EXPERIMENTAL USE
 * 240-254 block	LOCAL/EXPERIMENTAL USE
 *         Allocated for local/experimental use.  For devices not
 *         assigned official numbers, these ranges should be
 *         used in order to avoid conflicting with future assignments.
\*------------------------------------------------------------------------------------------*/
#define AVM_DECT_IO_MAJOR	    227
#define AVM_USERMAN_MAJOR	    228
#define KDSLD_USERMAN_MAJOR	    229
#define AVM_TIATM_MAJOR         230
#define TFFS_MAJOR              240
#define AVM_EVENT_MAJOR         241
#define WATCHDOG_MAJOR          242
#define KDSLD_MAJOR             243
#define KDSLDPTRACE_MAJOR       244
#define UBIK_MAJOR              245
#define DEBUG_TRACE_MAJOR       246
#define AVM_LED_MAJOR           247
#define AVM_I2C_MAJOR           248
#define YAFFS                   249
#define AVM_AUDIO_MAJOR         250
#define AVM_NEW_LED_MAJOR       251
#define AVM_POWER_MAJOR         252
#define AVM_VINAX_MAJOR		    253
#define AVM_HSK_MAJOR		    254
#define AVM_NET_TRACE_MAJOR	255

/*------------------------------------------------------------------------------------------*\
 * zusaetzlich folgende:
 *
 * 207 char	Compaq ProLiant health feature indicate
 * 220 char	Myricom Myrinet "GM" board
 * 224 char	A2232 serial card
 * 225 char	A2232 serial card (alternate devices)
 * 227 char	IBM 3270 terminal Unix tty access
 * 228 char	IBM 3270 terminal block-mode access
 * 229 char	IBM iSeries virtual console
 * 230 char	IBM iSeries virtual tape
 *
\*------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ar7_power.h>

#define avm_power_down_init               ar7_power_down_init
#define avm_put_device_into_power_down    ar7_put_device_into_power_down
#define avm_take_device_out_of_power_down ar7_take_device_out_of_power_down
#define avm_register_power_down_gpio      ar7_register_power_down_gpio
#define avm_release_power_down_gpio       ar7_release_power_down_gpio
#define avm_power_down_status             ar7_power_down_status

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ar7/hw_reset.h>
#include <asm/mips-boards/ar7_reset.h>

#define avm_reset_init                      ar7_reset_init
#define avm_take_device_out_of_reset        ar7_take_device_out_of_reset
#define avm_put_device_into_reset           ar7_put_device_into_reset
#define avm_reset_device                    ar7_reset_device
#define avm_reset_status                    ar7_reset_status
#define avm_register_reset_gpio		        ar7_register_reset_gpio
#define avm_release_reset_gpio		        ar7_release_reset_gpio

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ar7_vlynq.h>

#define avm_vlynq_init                      ar7_vlynq_init
#define avm_vlynq_init_link                 ar7_vlynq_init_link
#define avm_vlynq_alloc_context             ar7_vlynq_alloc_context
#define avm_vlynq_free_context              ar7_vlynq_free_context

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ar7int.h>

#define avm_int_init                        ar7int_init
#define avm_int_set_type                    ar7int_set_type
#define avm_int_ctrl_irq_pacing_setup       ar7int_ctrl_irq_pacing_setup
#define avm_int_ctrl_irq_pacing_register    ar7int_ctrl_irq_pacing_register
#define avm_int_ctrl_irq_pacing_unregister  ar7int_ctrl_irq_pacing_unregister
#define avm_int_ctrl_irq_pacing_set         ar7int_ctrl_irq_pacing_set
#define avm_nsec_timer                      ar7_nsec_timer

#endif /*--- #ifdef CONFIG_MIPS_AR7 ---*/

/*------------------------------------------------------------------------------------------*\
 * UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 UR8 
\*------------------------------------------------------------------------------------------*/
#ifdef CONFIG_MIPS_UR8

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
void ur8_pre_init(void);
#define avm_pre_init ur8_pre_init

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _avm_clock_id {
    avm_clock_id_non        = 0x00,
    avm_clock_id_cpu        = 0x01,
    avm_clock_id_system     = 0x02,
    avm_clock_id_usb        = 0x04,
    avm_clock_id_dsp        = 0x08,
    avm_clock_id_vbus       = 0x10,
    avm_clock_id_peripheral = 0x20,
    avm_clock_id_c55x       = 0x40,
    avm_clock_id_ephy       = 0x80,
    avm_clock_id_pci        = 0x100,
    avm_clock_id_tdm        = 0x200
};

#include <asm/mips-boards/ur8_clk.h>

#define avm_clk_get_pll_factor      ur8_clk_get_pll_factor
#define avm_get_clock               ur8_get_clock
#define avm_set_clock               ur8_set_clock
#define avm_get_clock_notify        ur8_get_clock_notify
#define avm_set_system_clock_notify ur8_set_system_clock_notify

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define MAX_ENV_ENTRY               256
#define FLASH_ENV_ENTRY_SIZE        64

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
char *avm_urlader_env_get_variable(int idx);
char *avm_urlader_env_get_value_by_id(unsigned int id);
char *avm_urlader_env_get_value(char *var);
int avm_urlader_env_set_variable(char *var, char *val);
int avm_urlader_env_unset_variable(char *var);
int avm_urlader_env_defrag(void);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ur8/hw_gpio.h>
#include <asm/mips-boards/ur8_gpio.h>

#define avm_gpio_init        ur8_gpio_init
#define avm_gpio_ctrl        ur8_gpio_ctrl
#define avm_gpio_out_bit     ur8_gpio_out_bit
#define avm_gpio_in_bit      ur8_gpio_in_bit
#define avm_gpio_in_value    ur8_gpio_in_value
#define avm_gpio_set_bitmask ur8_gpio_set_bitmask

/*------------------------------------------------------------------------------------------*\
 * 240-254 char	LOCAL/EXPERIMENTAL USE
 * 240-254 block	LOCAL/EXPERIMENTAL USE
 *         Allocated for local/experimental use.  For devices not
 *         assigned official numbers, these ranges should be
 *         used in order to avoid conflicting with future assignments.
\*------------------------------------------------------------------------------------------*/
#define AVM_DECT_IO_MAJOR	    227
#define AVM_USERMAN_MAJOR	    228
#define KDSLD_USERMAN_MAJOR	    229
#define AVM_TIATM_MAJOR         230
#define TFFS_MAJOR              240
#define AVM_EVENT_MAJOR         241
#define WATCHDOG_MAJOR          242
#define KDSLD_MAJOR             243
#define KDSLDPTRACE_MAJOR       244
#define UBIK_MAJOR              245
#define DEBUG_TRACE_MAJOR       246
#define AVM_LED_MAJOR           247
#define AVM_I2C_MAJOR           248
#define YAFFS                   249
#define AVM_AUDIO_MAJOR         250
#define AVM_NEW_LED_MAJOR       251
#define AVM_POWER_MAJOR         252
#define AVM_VINAX_MAJOR		    253
#define AVM_HSK_MAJOR		    254
#define AVM_NET_TRACE_MAJOR	255

/*------------------------------------------------------------------------------------------*\
 * zusaetzlich folgende:
 *
 * 207 char	Compaq ProLiant health feature indicate
 * 220 char	Myricom Myrinet "GM" board
 * 224 char	A2232 serial card
 * 225 char	A2232 serial card (alternate devices)
 * 227 char	IBM 3270 terminal Unix tty access
 * 228 char	IBM 3270 terminal block-mode access
 * 229 char	IBM iSeries virtual console
 * 230 char	IBM iSeries virtual tape
 *
\*------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ur8_power.h>

#define avm_power_down_init               ur8_power_down_init
#define avm_put_device_into_power_down    ur8_put_device_into_power_down
#define avm_take_device_out_of_power_down ur8_take_device_out_of_power_down
#define avm_register_power_down_gpio      ur8_register_power_down_gpio
#define avm_release_power_down_gpio       ur8_release_power_down_gpio
#define avm_power_down_status             ur8_power_down_status

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mach-ur8/hw_reset.h>
#include <asm/mips-boards/ur8_reset.h>

#define avm_reset_init                      ur8_reset_init
#define avm_take_device_out_of_reset        ur8_take_device_out_of_reset
#define avm_put_device_into_reset           ur8_put_device_into_reset
#define avm_reset_device                    ur8_reset_device
#define avm_reset_status                    ur8_reset_status
#define avm_register_reset_gpio		        ur8_register_reset_gpio
#define avm_release_reset_gpio		        ur8_release_reset_gpio

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ur8_vlynq.h>

#define avm_vlynq_init                      ur8_vlynq_init
#define avm_vlynq_init_link                 ur8_vlynq_init_link
#define avm_vlynq_alloc_context             ur8_vlynq_alloc_context
#define avm_vlynq_free_context              ur8_vlynq_free_context

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <asm/mips-boards/ur8int.h>

#define avm_int_init                        ur8int_init
#define avm_int_set_type                    ur8int_set_type
#define avm_int_ctrl_irq_pacing_setup       ur8int_ctrl_irq_pacing_setup
#define avm_int_ctrl_irq_pacing_register    ur8int_ctrl_irq_pacing_register
#define avm_int_ctrl_irq_pacing_unregister  ur8int_ctrl_irq_pacing_unregister
#define avm_int_ctrl_irq_pacing_set         ur8int_ctrl_irq_pacing_set
#define avm_nsec_timer                      ur8_nsec_timer

#endif /*--- #ifdef CONFIG_MIPS_OHIO ---*/




#endif /*--- #ifndef _mach_avm_h_ ---*/
