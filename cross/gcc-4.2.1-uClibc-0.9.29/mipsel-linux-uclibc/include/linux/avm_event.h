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
#ifndef _avm_linux_event_h_
#define _avm_linux_event_h_

/*-----------------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------------*/
/*--- #define MODULE_NAME     "avm_event" ---*/
/*--- #define AVM_EVENT_DEBUG ---*/      


/*-----------------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------------*/
#if defined(__KERNEL__)
#include <asm/ioctl.h>
#include <linux/version.h>
#endif /*--- #if defined(__KERNEL__) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define MAX_EVENT_CLIENT_NAME_LEN   32
#define MAX_EVENT_SOURCE_NAME_LEN   32
#define MAX_AVM_EVENT_SOURCES       32

/*------------------------------------------------------------------------------------------*\
 * Aufteilung der Event typen (vorlaeufig in 8er Gruppen):
 *
 *  0 -  7:   WLAN 
 *  8 - 15:   DSL
 * 16 - 23:
 * 24 - 31:
 * 32 - 39:   Ethernet
 * 40 - 47:
 * 48 - 55:
 * 56 - 63:
\*------------------------------------------------------------------------------------------*/
#define AVM_EVENT_TYPE_WLAN_CLIENT_CHANGE   0
#define AVM_EVENT_TYPE_WLAN_ERROR           1

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _avm_event_id {
    avm_event_id_wlan_client_status      = 0,

    avm_event_id_autoprov                = 7,  
    avm_event_id_usb_status              = 8,

    avm_event_id_dsl_status              = 16,
    avm_event_id_dsl_connect_status      = 17,

    avm_event_id_push_button             = 19,
    avm_event_id_telefon_wlan_command    = 20,
    avm_event_id_capiotcp_startstop      = 21,
    avm_event_id_telefon_up              = 22,
    avm_event_id_reboot_req              = 23,

    avm_event_id_appl_status             = 24,
    avm_event_id_led_status              = 25,
    avm_event_id_led_info                = 26,

    avm_event_id_telefonprofile          = 27,
    avm_event_id_temperature             = 28,

    /*--- avm_event_id_ethernet_status         = 32, ---*/
    avm_event_id_ethernet_connect_status = 33,

    avm_event_id_pm_ressourceinfo_status = 40,

    avm_event_id_user_source_notify      = 63,
    avm_event_last                       = 64
};

struct _avm_event_header {
    enum _avm_event_id id;
};


/*------------------------------------------------------------------------------------------*\
 *  ID Spezifische Datentypen  (id=avm_event_id_user_source_notify)
\*------------------------------------------------------------------------------------------*/
struct _avm_event_user_mode_source_notify {
    struct _avm_event_header header;
    enum _avm_event_id id;
};

/*------------------------------------------------------------------------------------------*\
 * CMD Spezifische Datentypen
\*------------------------------------------------------------------------------------------*/
enum __avm_event_cmd {
    avm_event_cmd_register        = 0,
    avm_event_cmd_release         = 1,
    avm_event_cmd_source_register = 2,
    avm_event_cmd_source_release  = 3,
    avm_event_cmd_source_trigger  = 4,
    avm_event_cmd_trigger         = 5,
    avm_event_cmd_undef
};

/*------------------------------------------------------------------------------------------*\
 * cmd=avm_event_cmd_param_register 
\*------------------------------------------------------------------------------------------*/
struct _avm_event_cmd_param_register {
    unsigned long long mask;
    char Name[MAX_EVENT_CLIENT_NAME_LEN + 1];
};

/*------------------------------------------------------------------------------------------*\
 * cmd=avm_event_cmd_param_release 
\*------------------------------------------------------------------------------------------*/
struct _avm_event_cmd_param_release {
    char Name[MAX_EVENT_CLIENT_NAME_LEN + 1];
};

struct _avm_event_cmd_param_trigger {
    unsigned int id;
};

struct _avm_event_cmd_param_source_trigger {
    enum _avm_event_id id;
    unsigned int data_length;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _avm_event_cmd {
    enum __avm_event_cmd cmd;
    union _avm_event_cmd_param {
        struct _avm_event_cmd_param_register avm_event_cmd_param_register;
        struct _avm_event_cmd_param_release avm_event_cmd_param_release;
        struct _avm_event_cmd_param_trigger avm_event_cmd_param_trigger;
        struct _avm_event_cmd_param_register avm_event_cmd_param_source_register;
        struct _avm_event_cmd_param_source_trigger avm_event_cmd_param_source_trigger;
    } param;
};

#if defined(__KERNEL__)
#if defined(AVM_EVENT_INTERNAL)
/*------------------------------------------------------------------------------------------*\
     * KERNEL INCLUDE * KERNEL INCLUDE * KERNEL INCLUDE * KERNEL INCLUDE * KERNEL INCLUDE * 
\*------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _avm_event {
#if KERNEL_VERSION(2, 6, 0) < LINUX_VERSION_CODE 
    dev_t               device;
    struct cdev        *cdev;
#else /*--- #if KERNEL_VERSION(2, 6, 0) < LINUX_VERSION_CODE ---*/ 
	devfs_handle_t      devfs_handle;
    unsigned int        major;
    unsigned int        minor;
#endif /*--- #else ---*/ /*--- #if KERNEL_VERSION(2, 6, 0) < LINUX_VERSION_CODE ---*/ 
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _avm_event_open_data {
    struct _avm_event_open_data *next;
    struct _avm_event_open_data *prev;
    unsigned int registered;
    unsigned long long event_mask_registered;
    volatile struct _avm_event_item *item;
    char Name[MAX_EVENT_CLIENT_NAME_LEN + 1];
    wait_queue_head_t wait_queue;
    struct fown_struct *pf_owner;
    struct fasync_struct *fasync;
    void *event_source_handle;
};

struct _avm_event_data {
    struct _avm_event_data *debug; /*--- verkettung zu debug zwecken ---*/
    unsigned int link_count;
    void *data;
    unsigned int data_length;
};

struct _avm_event_item {
    struct _avm_event_data *debug; /*--- verkettung zu debug zwecken ---*/
    volatile struct _avm_event_item *next;  /*--- -1 wenn objekt in free queue ---*/
    volatile struct _avm_event_data *data;
};

extern volatile struct _avm_event_item *avm_event_first_Item; /*--- verkettung zu debug zwecken ---*/
extern volatile struct _avm_event_data *avm_event_first_Data; /*--- verkettung zu debug zwecken ---*/

#define AVM_EVENT_SIGNATUR      (unsigned long long)(0x544E56455F4D5641ULL)
struct _avm_event_source {
    unsigned long long signatur;
    char Name[MAX_EVENT_SOURCE_NAME_LEN + 1];
    unsigned long long event_mask;
    void (*notify)(void *, enum _avm_event_id);
    void *Context;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
extern int avm_event_register(struct _avm_event_open_data *, struct _avm_event_cmd_param_register *);
extern int avm_event_release(struct _avm_event_open_data *, struct _avm_event_cmd_param_release *);
extern int avm_event_trigger(struct _avm_event_open_data *, struct _avm_event_cmd_param_trigger *);
extern int avm_event_get(struct _avm_event_open_data *open_data, unsigned char **rx_buffer, unsigned int *rx_buffer_length, unsigned int *event_pos);
extern void avm_event_commit(struct _avm_event_open_data *open_data, unsigned int event_pos);
extern int avm_event_source_trigger_one(struct _avm_event_open_data *O, struct _avm_event_data *D);

#if !defined(CONFIG_NO_PRINTK)
extern void dump_all_user_data(void);
#endif /*--- #if !defined(CONFIG_NO_PRINTK) ---*/

int avm_event_init2(unsigned int max_items, unsigned int max_datas);
int avm_event_deinit2(void);
struct _avm_event_data *avm_event_alloc_data(void);
void avm_event_free_data(struct _avm_event_data *D);
struct _avm_event_item *avm_event_alloc_item(void);
void avm_event_free_item(struct _avm_event_item *I);

#endif /*--- #if defined(AVM_EVENT_INTERNAL) ---*/

/*------------------------------------------------------------------------------------------*\
 *   Kernel Schnittstelle des avm_event Treibers
\*------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------*\
 *   Jede Event/Informations Quelle muss sich einmalig registrieren. 
 *
 *   Parameter:   name      ein frei zu waehlender Name
 *                id_mask   eine 64 Bit Maske in der diejenigen Bits der IDs gesetzt
 *                          sind zu der der Registrierende Informationen liefern will
 *                          (zu jedem Bit kann es nur einen Lieferanten geben)
 *                notify    Diese Funktion wird durch den Event Treiber immer dann
 *                          aufgerufen, wenn sich a) ein Empfaenger, der Informationen von
 *                          diesem Treiber haben will, registriert hat oder b) wenn ein 
 *                          schon registrierter Empfaenger eine Aktualisierung der Daten
 *                          wuenscht (avm_event_trigger())
 *                          Parameter dieser Funktion sind: 1) der beim Registrieren 
 *                          uebergebene Kontext, und 2) die Id zu der Informationen gewuenscht 
 *                          sind.
 *                Context   (siehe notify)
 *
 *   Return wert:           NULL im Fehlerfall, andernfalls ein gueltiges Handle
\*------------------------------------------------------------------------------------------*/
extern void *avm_event_source_register(char *name, unsigned long long id_mask, void (*notify)(void *, enum _avm_event_id), void *Context);

/*------------------------------------------------------------------------------------------*\
 *   Deregistrieren, anschliessend ist der Handle ungueltig
\*------------------------------------------------------------------------------------------*/
extern void avm_event_source_release(void *handle);

/*------------------------------------------------------------------------------------------*\
 *   Immer wenn Informationen an den Event Treiber uebergeben werden sollen, muss diese 
 *   Funktion aufgerufen werden.
 *   
 *   Parameter:   Handle   Handle von avm_event_source_register()
 *   
 *                Id       Id des Events/Information
 *                data_length   Laenge der Daten/Informationen
 *                data     Pointer auf die Daten. Dieser MUSS mittels kmalloc alloziiert
 *                         worden sein.
 *   Returnwert:  Anzahl der Empfaenger die sich fuer die Daten interessierten (0 == keiner)
\*------------------------------------------------------------------------------------------*/
extern int avm_event_source_trigger(void *handle, enum _avm_event_id id, unsigned int data_length, void *data);

/*------------------------------------------------------------------------------------------*\
 * Ermoeglicht es die Nutzung eines Buttons extern an/abzuschalten und entsprechend zu 
 * konfigurieren
 * Dies ist z.B. notwendig, wenn es sich bei dem Button um kein GPIO, sondern einem FPGA-Register 
 * handelt, der erst nach laden des FPGA's zur Verfügung steht.
 * name: Suchname der Schalters
 * enable:             0 aus, 1 an: Übernahme der Werte nur bei enable = 1
 *                     2 keine Übernahme aber enable
 * gpio:               GPIO/Register-Bit 
 * register_address:   != NULL Register-Adresse anstelle GPIO
 * button_type:        0 = Taster, 1 = Schalter
 * Returnwert: 0: ok und gesetzt 1 Schalter nicht gefunden
\*------------------------------------------------------------------------------------------*/
extern int avm_event_push_button_ctrl(char *name, unsigned int enable, unsigned int gpio, volatile unsigned int *register_addr, unsigned int button_type);

/*------------------------------------------------------------------------------------------*\
 *   Pruefen ob sich jemand fuer die Daten interessiert
\*------------------------------------------------------------------------------------------*/
extern int avm_event_source_check_id(void *handle, enum _avm_event_id id);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
extern struct semaphore avm_event_sema;
extern unsigned long long avm_event_source_mask;
#endif /*--- #if defined(__KERNEL__) ---*/

/*------------------------------------------------------------------------------------------*\
 * user event structures
\*------------------------------------------------------------------------------------------*/
#if defined(__KERNEL__)
void avm_event_push_button_deinit(void);
void avm_event_push_button_init(void);
#endif /*--- #if defined(__KERNEL__) ---*/


enum _avm_event_push_button_key {
    avm_event_push_button_gpio_low  = 0,
    avm_event_push_button_gpio_high = 1,
    avm_event_push_button_key_1     = 2,  /*--- Taster1: kurz gedrücket 0,25 - 2 Sekunden ---*/
    avm_event_push_button_key_2     = 3,  /*--- Taster1: mittel lang gedrücket 2 - 8 Sekunden ---*/
    avm_event_push_button_key_3     = 4,  /*--- Taster1: lang gedrücket mehr als 8 Sekunden ---*/
    avm_event_push_button_key_4     = 5,  /*--- Taster2: kurz gedrücket 0,25 - 2 Sekunden ---*/
    avm_event_push_button_key_5     = 6,  /*--- Taster2: mittel lang gedrücket 2 - 8 Sekunden ---*/
    avm_event_push_button_key_6     = 7,  /*--- Taster2: lang gedrücket mehr als 8 Sekunden ---*/
    avm_event_push_button_key_7     = 8,  /*--- Schalter: aus ---*/
    avm_event_push_button_key_8     = 9,  /*--- Schalter: an ---*/
    avm_event_push_button_key_9     = 10, /*--- Schalter: Dummy ---*/
};

struct _avm_event_push_button {
    enum _avm_event_id id;
    enum _avm_event_push_button_key key;
    unsigned int pressed;  /*--- in ms ---*/
};

struct cpmac_port {
    unsigned int cable      : 1; /* Cable detected? */ /* not for all chips available */
    unsigned int link       : 1; /* Link up? */
    unsigned int speed100   : 1; /* 100 Mbps? Otherwise 10 Mbps */
    unsigned int fullduplex : 1; /* Full duplex? Otherwise half duplex */
};

struct cpmac_event_struct {
    struct _avm_event_header event_header; /* Header for the event structure */
    unsigned int ports;         /* Number of ports */
    struct cpmac_port port[5];  /* Data for the given port */
};

/* Derzeit keine Detailinfos notwendig */
/*--- struct cpmac_event_struct_verbose { ---*/
    /*--- struct _avm_event_header      event_header; ---*/
/*--- }; ---*/

enum _avm_event_led_id {
    logical_led_inval    = 0,
    logical_led_ppp      = 2,      /*--- gruppe: pppoe, instanz: 0 ---*/
    logical_led_error    = 17,     /*--- gruppe: error, instanz: 0 ---*/
    logical_led_pots     = 13,     /*--- gruppe: ab, instanz: 1 ---*/
    logical_led_info     = 7,      /*--- gruppe: info, instanz: 0 ---*/
    logical_led_traffic  = 18,     /*--- gruppe: info, instanz: 1 ---*/
    logical_led_freecall     = 16, /*--- gruppe: info, instanz: 2 ---*/
    logical_led_avmusbwlan   = 19, /*--- gruppe: info, instanz: 3 ---*/
    logical_led_sip      = 14,     /*--- gruppe: internet, instanz: 0 ---*/
    logical_led_mwi      = 20,     /*--- gruppe: internet, instanz: 1 ---*/
    logical_led_fest_mwi = 21,     /*--- gruppe: ab, instanz: 2 ---*/
    logical_led_isdn_d   = 12,     /*--- gruppe: isdn, instanz: 0 ---*/
    logical_led_isdn_b1  = 10,     /*--- gruppe: isdn, instanz: 1 ---*/
    logical_led_isdn_b2  = 11,     /*--- gruppe: isdn, instanz: 2 ---*/
    logical_led_lan      = 3,      /*--- gruppe: cpmac, instanz: 0 ---*/
    logical_led_lan1     = 15,     /*--- gruppe: cpmac, instanz: 1 ---*/
    logical_led_adsl     = 1,      /*--- gruppe: adsl, instanz: 0 ---*/
    logical_led_power    = 8,      /*--- gruppe: adsl, instanz: 1 ---*/
    logical_led_usb      = 5,      /*--- gruppe: usb, instanz: 0 ---*/
    logical_led_wifi     = 4,      /*--- gruppe: wlan, instanz: 0 ---*/
    logical_led_last
};

struct _avm_event_led_status {
    struct _avm_event_header header; /*--- interer Header der Eventschnittstelle ---*/
    enum _avm_event_led_id led; /*--- Logische LED Instanz ---*/
    unsigned int state;
    unsigned int param_len;
    unsigned char params[]; /*--- 0 bis 245 byte lang ---*/
};

struct _avm_event_led_info {
    struct _avm_event_header event_header; /* Header for the event structure */
    unsigned int mode;   /* 0 .. 7 */
    unsigned int param1;
    unsigned int param2;
    unsigned int gpio_driver_type;
    unsigned int gpio;  /*--- pin or mask, depens on driver type ---*/
    unsigned int pos;
    char Name[32];
};

/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
struct _avm_event_telefonprofile {
    struct _avm_event_header      event_header;
    unsigned int on;  /*--- 1 Telefonie aktiv  ---*/
};
/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
struct _avm_event_temperature {
    struct _avm_event_header      event_header;
    int temperature;   
};

/*--------------------------------------------------------------------------------*\
 * aktueller "Power"-Zustand der Box
\*--------------------------------------------------------------------------------*/
struct _avm_event_pm_info_stat {
	struct _avm_event_header header;
    unsigned char   reserved1;
	unsigned char   rate_sumact;      /*--- aktueller Energieverbrauch in Prozent ---*/
	unsigned char   rate_sumcum;      /*--- kumulierter Energieverbrauch in Prozent (24 h-Fenster) ---*/
	unsigned char   rate_systemact;   /*--- (gewichtete) aktuelle Aktivität MIPS, System und idle in Prozent ---*/
	unsigned char   rate_systemcum;   /*--- (gewichtete) kumulierte Aktivität MIPS, System und idle in Prozent ---*/
	unsigned char   system_status;    /*--- 0: Takt 125 MHz 1: 150 MHz 2: 62.5 MHz ---*/
	unsigned char   rate_dspact;      /*--- aktueller Aktivität DSP in Prozent ---*/
	unsigned char   rate_dspcum;      /*--- kumulierte Aktivität DSP in Prozent (24 h-Fenster) ---*/
	unsigned char   rate_wlanact;     /*--- aktueller Verbrauch WLAN in Prozent ---*/
	unsigned char   rate_wlancum;     /*--- kumulierter Verbrauch WLAN in Prozent (24 h-Fenster) ---*/
	unsigned char   wlan_devices;     /*--- angemeldete WLAN-Devices ---*/
	unsigned char   wlan_status;      /*--- WLAN-Status (1= ECO) ---*/
	unsigned char   rate_ethact;      /*--- aktueller Ethernet-Verbrauch in Prozent ---*/
	unsigned char   rate_ethcum;      /*--- kumulierter Ethernet-Verbrauch (24 h Fenster) ---*/
	unsigned short  eth_status;       /*--- Maske: je 2 Bit ein LAN-Port: Lan1 ... dabei: Wert: 0 aus, 1 power_save, 2 normal, 3 verbunden ---*/
	unsigned char   rate_abact;       /*--- aktueller Nebenstellen-Verbrauch in Prozent ---*/
	unsigned char   rate_abcum;       /*--- kumulierter Nebenstellen-Verbrauch in Prozent (24 h Fenster) ---*/
	unsigned short  isdn_status;      /*--- Maske: je 4 Bit ein Port (TEx/NTx): Bit0: TEx (E1+E3) aktiv, Bit1: NTx E1 aktiv, Bit2: NTx-E3 aktiv ---*/
	unsigned char   rate_dectact;     /*--- aktueller Verbrauch DECT in Prozent ---*/
	unsigned char   rate_dectcum;     /*--- kumulierter Verbrauch DECT in Prozent (24 h Fenster) ---*/
    unsigned char   rate_battchargeact;/*--- Batterieladeverbrauch (DECT) in Prozent ---*/  
    unsigned char   rate_battchargecum;/*--- kumulierter Batterieladeverbrauch (DECT) in Prozent ---*/  
	unsigned char   dect_status;      /*--- DECT-Status 1: ECO-Mode aktiv ---*/
	unsigned char   rate_usbhostact;  /*--- USB-Host-Leistungsverbrauch in Prozent ---*/
	unsigned char   rate_usbhostcum;  /*--- kumulierter USB-Host-Leistungsverbrauch in Prozent ---*/
	unsigned char   usb_status;       /*--- USB-Status 1= USB-Client angeschlossen ---*/
};

#endif /*--- #ifndef _avm_linux_event_h_ ---*/
