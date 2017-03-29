/*------------------------------------------------------------------------------------------*\
 *   
 *   Copyright (C) 2004 AVM GmbH <fritzbox_info@avm.de>
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
#ifndef _tffs_h_
#define _tffs_h_

/*-----------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------*/
enum _tffs_id {
    /*-------------------------------------------------------------------------------------*\
        reserved ID's
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_FREE              = 0xFFFF,
    FLASH_FS_ID_SKIP              = 0x0000,
    FLASH_FS_ID_SEGMENT           = 0x0001,

    /*-------------------------------------------------------------------------------------*\
     * Minor ID's  (0x0001 - 0x00FF)
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_PANIC_LOG         = 0x0060,   
    FLASH_FS_ID_RC_RESERVED_USER  = 0x0061,     /*--- reserved for files needed in rc.user ---*/
    FLASH_FS_ID_RC_USER           = 0x0062,
    FLASH_FS_ID_TEL_DEFAULT       = 0x0063,

    /*-------------------------------------------------------------------------------------*\
     * Beim Werkseinstellungen werden alle IDs von 0x64 - 0xFF gelöscht
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_TICFG             = 0x0064,
    /*--- FLASH_FS_ID_SHUTDOWN          = 0x0065, ---*/

    FLASH_FS_ID_CONFIG_0          = 0x0070,   /*--- /var/flash/udhcpd.leases ---*/
    FLASH_FS_ID_CONFIG_1          = 0x0071,   /*--- /var/flash/ar7.cfg ---*/
    FLASH_FS_ID_CONFIG_2          = 0x0072,   /*--- /var/flash/voip.cfg ---*/
    FLASH_FS_ID_CONFIG_3          = 0x0073,   /*--- /var/flash/wlan.cfg ---*/
    FLASH_FS_ID_CONFIG_4          = 0x0074,   /*--- /var/flash/ar7stat.cfg ---*/
    FLASH_FS_ID_CONFIG_5          = 0x0075,   /*--- /var/flash/net.update ---*/
    FLASH_FS_ID_CONFIG_6          = 0x0076,   /*--- /var/flash/vpn.cfg ---*/
    FLASH_FS_ID_CONFIG_7          = 0x0077,   /*--- /var/flash/tr069.cfg ---*/
    FLASH_FS_ID_CONFIG_8          = 0x0078,   /*--- /var/flash/user.cfg ---*/      
    FLASH_FS_ID_CONFIG_9          = 0x0079,   /*--- /var/flash/userstat.cfg ---*/   
    FLASH_FS_ID_CONFIG_10         = 0x007A,   /*--- /var/flash/voip_call_stat ---*/
    FLASH_FS_ID_CONFIG_11         = 0x007B,
    FLASH_FS_ID_CONFIG_12         = 0x007C,
    FLASH_FS_ID_CONFIG_13         = 0x007D,   /*--- /var/flash/pin ---*/
    FLASH_FS_ID_CONFIG_14         = 0x007E,   /*--- /var/flash/hcid.conf ---*/
    FLASH_FS_ID_CONFIG_15         = 0x007F,   /*--- /var/flash/link_key ---*/

    /*-------------------------------------------------------------------------------------*\
     * Telefon Applikation
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_MSNLISTE          = 0x0080,   /*--- /var/flash/telefon_msns ---*/
    FLASH_FS_ID_TEL_CONFIG        = 0x0081,   /*--- /var/flash/fx_conf ---*/
    FLASH_FS_ID_TEL_LCR           = 0x0082,   /*--- /var/flash/fx_lcr ---*/
    FLASH_FS_ID_TEL_MOH           = 0x0083,   /*--- /var/flash/ansage_moh1 ---*/
    FLASH_FS_ID_TEL_CG            = 0x0084,   /*--- /var/flash/fx_cg ---*/
    FLASH_FS_ID_TELCFG_MISC       = 0x0085,   /*--- /var/flash/telefon_misc ---*/

    FLASH_FS_ID_TEL_MOH2          = 0x0086,   /*--- /var/flash/ansage_moh2 ---*/
    FLASH_FS_ID_TEL_NO_SERVICE    = 0x0087,   /*--- /var/flash/ansage_no_service ---*/
    FLASH_FS_ID_TEL_NO_NUMBER     = 0x0088,   /*--- /var/flash/ansage_no_number ---*/
    FLASH_FS_ID_TEL_USER1         = 0x0089,   /*--- /var/flash/ansage_user ---*/
    FLASH_FS_ID_TEL_USER2         = 0x008A,   /*--- /var/flash/ansage_user2 ---*/
    FLASH_FS_ID_TEL_USER3         = 0x008B,   /*--- /var/flash/ansage_user3 ---*/
    FLASH_FS_ID_TEL_USER4         = 0x008C,   /*--- /var/flash/ansage_user4 ---*/
    FLASH_FS_ID_TEL_CALLLOG       = 0x008D,   /*--- /var/flash/calllog ---*/
    FLASH_FS_ID_TEL_PHONEBOOK     = 0x008E,   /*--- /var/flash/phonebook ---*/
    FLASH_FS_ID_TEL_FONCTRL       = 0x008F,   /*--- /var/flash/fonctrl ---*/

    /*-------------------------------------------------------------------------------------*\
     * Power Applikation
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_POWERMODE         = 0x0090,   /*--- /var/flash/powermode ---*/

    /*-------------------------------------------------------------------------------------*\
     * Audio/Aura/USB Applikation(s)
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_AURA_USB          = 0x00A0,   /*--- /var/flash/aura-usb ---*/

    /*-------------------------------------------------------------------------------------*\
     * Fritz Mini
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_BROWSER_DATA      = 0x00A8,   /*--- /var/flash/browser-data ---*/

    /*-------------------------------------------------------------------------------------*\
     * DECT
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_DECT_MISC         = 0x00B0,

    /*-------------------------------------------------------------------------------------*\
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_FIRMWARE_CONFIG_LAST = 0x00FF,
#if defined(CONFIG_TFFS_ENV)
    /*-------------------------------------------------------------------------------------*\
     * Adam2 ID's  (0x0100 - 0x01FF)
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_HWREVISION           = 0x0100,
    FLASH_FS_PRODUCTID            = 0x0101,
    FLASH_FS_SERIALNUMBER         = 0x0102,
    FLASH_FS_DMC                  = 0x0103,

    /*--- kleiner erster Buchstaben ---*/
    FLASH_FS_AUTOLOAD             = 0x0181,
    FLASH_FS_BOOTLOADERvERSION    = 0x0182,
    FLASH_FS_BOOTSERPORT          = 0x0183,
    FLASH_FS_MAC_BLUETOOTH        = 0x0184,
    FLASH_FS_CPUFREQUENCY         = 0x0185,
    FLASH_FS_FIRSTFREEADDRESS     = 0x0186,
    FLASH_FS_FLASHSIZE            = 0x0187,
    FLASH_FS_MAC_A                = 0x0188,
    FLASH_FS_MAC_B                = 0x0189,
    FLASH_FS_MAC_WLAN             = 0x018A,
    FLASH_FS_MAC_DSL              = 0x018B,
    FLASH_FS_MEMSIZE              = 0x018C,
    FLASH_FS_MODETTY0             = 0x018D,
    FLASH_FS_MODETTY1             = 0x018E,
    FLASH_FS_MY_IPADDRESS         = 0x018F,
    FLASH_FS_PROMPT               = 0x0190,
    FLASH_FS_MAC_RES              = 0x0191,
    FLASH_FS_REQ_FULLRATE_FREQ    = 0x0192,
    FLASH_FS_SYSFREQUENCY         = 0x0193,
    FLASH_FS_MAC_USB_BOARD        = 0x0194,
    FLASH_FS_MAC_USB_RNDIS        = 0x0195,
    FLASH_FS_MAC_C                = 0x0196,

    FLASH_FS_ETHADDR              = 0x0197,
    FLASH_FS_LINUX_FS_START       = 0x0198,
    FLASH_FS_LINUXIP              = 0x0199,
    FLASH_FS_MODULATION           = 0x019A,
    FLASH_FS_NFS                  = 0x019B,
    FLASH_FS_NFSROOT              = 0x019C,
    FLASH_FS_OAM_LB_TIMEOUT       = 0x019D,
    FLASH_FS_SYSTYPE              = 0x019E,
    FLASH_FS_KERNEL_ARGS1         = 0x019F,
	FLASH_FS_KERNEL_ARGS          = 0x01A0,
    FLASH_FS_CRASH                = 0x01A1,
    FLASH_FS_USB_DEVICE_ID        = 0x01A2,
    FLASH_FS_USB_REVISION_ID      = 0x01A3,
    FLASH_FS_USB_DEVICE_NAME      = 0x01A4,
    FLASH_FS_USB_MANUFACTURER_NAME = 0x01A5,
    FLASH_FS_FIRMWARE_VERSION     = 0x01A6,
    FLASH_FS_LANGUAGE             = 0x01A7,
    FLASH_FS_COUNTRY              = 0x01A8,
    FLASH_FS_ANNEX                = 0x01A9,
    FLASH_FS_PTEST                = 0x01AA,
    FLASH_FS_WLAN_KEY             = 0x01AB,
    FLASH_FS_BLUETOOTH_KEY        = 0x01AC,
    FLASH_FS_HTTP_KEY             = 0x01AD,
    FLASH_FS_FIRMWARE_INFO        = 0x01AE,
    FLASH_FS_AUTO_MDIX            = 0x01AF,
    FLASH_FS_MTD_0                = 0x01B0,
    FLASH_FS_MTD_1                = 0x01B1,
    FLASH_FS_MTD_2                = 0x01B2,
    FLASH_FS_MTD_3                = 0x01B3,
    FLASH_FS_MTD_4                = 0x01B4,
    FLASH_FS_MTD_5                = 0x01B5,
    FLASH_FS_MTD_6                = 0x01B6,
    FLASH_FS_MTD_7                = 0x01B7,
    FLASH_FS_WLAN_CAL             = 0x01B8,
    FLASH_FS_JFFS2_SIZE           = 0x01B9,
    FLASH_FS_TR069_SERIAL         = 0x01C0,
    FLASH_FS_TR069_PASSPHRASE     = 0x01C1,  

    FLASH_FS_URLADER_VERSION      = 0x01FD,
    FLASH_FS_TABLE_VERSION        = 0x01FE, /*--- eintrag in wirklichkeit nicht vorhanden, nur id reserviert ---*/
    FLASH_FS_NAME_TABLE           = 0x01FF,
#endif /*--- #if defined(CONFIG_TFFS_ENV) ---*/

    /*-------------------------------------------------------------------------------------*\
     * Zaehler
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_REBOOT_MAJOR         = 0x0400,
    FLASH_FS_REBOOT_MINOR         = 0x0401,
    FLASH_FS_HOUR_COUNTER         = 0x0402,
    FLASH_FS_DAY_COUNTER          = 0x0403,
    FLASH_FS_MOUNTH_COUNTER       = 0x0404,
    FLASH_FS_YEAR_COUNTER         = 0x0405,
    FLASH_FS_RESERVED_COUNTER     = 0x0406,
    FLASH_FS_VERSION_COUNTER      = 0x0407,

    /*-------------------------------------------------------------------------------------*\
     * AVM dropable data 
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_DROPABLE_DATA       = 0x4000,

    FLASH_FS_ID_ASSERT           = 0x4001,
    FLASH_FS_ID_ATM_JOURNAL      = 0x4002,

    /*-------------------------------------------------------------------------------------*\
    \*-------------------------------------------------------------------------------------*/
    FLASH_FS_ID_LAST   
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(TFFS_NAME_TABLE)
struct _TFFS_Name_Table {
    unsigned int id;
    char Name[64];
} TFFS_Name_Table[MAX_ENV_ENTRY];

#if defined(URLADER) 
struct _TFFS_Name_Table_Init {
    unsigned int id;
    char *Name;
};
#endif /*--- #if defined(URLADER) ---*/ 

#if defined(URLADER) 
struct _TFFS_Name_Table_Init T_Init[] = 
#else /*--- #if defined(URLADER) ---*/ 
struct _TFFS_Name_Table T_Init[] =
#endif /*--- #else ---*/ /*--- #if defined(URLADER) ---*/ 
/*--- !!! alphabetisch sortiert -> !!! ---*/
{
    /*--- neuer Versionseintrag ---*/
    { FLASH_FS_TABLE_VERSION,     "@D" },

    /*--- grosser erster Buchstaben ---*/
    { FLASH_FS_AUTO_MDIX,         "AutoMDIX" },
    { FLASH_FS_DMC,               "DMC" },
    { FLASH_FS_HWREVISION,        "HWRevision" },
    { FLASH_FS_PRODUCTID,         "ProductID" },
    { FLASH_FS_SERIALNUMBER,      "SerialNumber" },

    /*--- kleiner erster Buchstaben ---*/
    { FLASH_FS_ANNEX,             "annex" },
    { FLASH_FS_AUTOLOAD,          "autoload" },
    { FLASH_FS_BOOTLOADERvERSION, "bootloaderVersion" },
    /*--- { FLASH_FS_BOOTSERPORT,       "bootserport" }, ---*/
    { FLASH_FS_BLUETOOTH_KEY,     "bluetooth_key" },
    { FLASH_FS_MAC_BLUETOOTH,     "bluetooth" },
    { FLASH_FS_COUNTRY,           "country" },
    { FLASH_FS_CPUFREQUENCY,      "cpufrequency" },
    { FLASH_FS_CRASH,             "crash" },
    /*--- { FLASH_FS_ETHADDR,           "ethaddr" }, ---*/
    { FLASH_FS_FIRSTFREEADDRESS,  "firstfreeaddress" },
    { FLASH_FS_FIRMWARE_VERSION,  "firmware_version" },
    { FLASH_FS_FIRMWARE_INFO,     "firmware_info" },
    { FLASH_FS_FLASHSIZE,         "flashsize" },
    /*--- { FLASH_FS_HTTP_KEY,          "http_key" }, ---*/
    { FLASH_FS_JFFS2_SIZE,        "jffs2_size" },
	{ FLASH_FS_KERNEL_ARGS,       "kernel_args" },
    { FLASH_FS_KERNEL_ARGS1,      "kernel_args1" },
    { FLASH_FS_LANGUAGE,          "language" },
    /*--- { FLASH_FS_LINUX_FS_START,    "linux_fs_start" }, ---*/
    /*--- { FLASH_FS_LINUXIP,           "linuxip" }, ---*/
    { FLASH_FS_MAC_A,             "maca" },
    { FLASH_FS_MAC_B,             "macb" },
    /*--- { FLASH_FS_MAC_C,             "macc" }, ---*/
    { FLASH_FS_MAC_WLAN,          "macwlan" },
    { FLASH_FS_MAC_DSL,           "macdsl" },
    { FLASH_FS_MEMSIZE,           "memsize" },
    { FLASH_FS_MODETTY0,          "modetty0" },
    { FLASH_FS_MODETTY1,          "modetty1" },
    /*--- { FLASH_FS_MODULATION,        "modulation" }, ---*/
    { FLASH_FS_MTD_0,             "mtd0" },
    { FLASH_FS_MTD_1,             "mtd1" },
    { FLASH_FS_MTD_2,             "mtd2" },
    { FLASH_FS_MTD_3,             "mtd3" },
    { FLASH_FS_MTD_4,             "mtd4" },
    { FLASH_FS_MTD_5,             "mtd5" },
    { FLASH_FS_MTD_6,             "mtd6" },
    { FLASH_FS_MTD_7,             "mtd7" },
    { FLASH_FS_MY_IPADDRESS,      "my_ipaddress" },
    { FLASH_FS_NFS,               "nfs" },
    { FLASH_FS_NFSROOT,           "nfsroot" },
    /*--- { FLASH_FS_OAM_LB_TIMEOUT,    "oam_lb_timeout" }, ---*/
    { FLASH_FS_PROMPT,            "prompt" },
    { FLASH_FS_PTEST,             "ptest" },
    { FLASH_FS_MAC_RES,           "reserved" },
    { FLASH_FS_REQ_FULLRATE_FREQ, "req_fullrate_freq" },
    { FLASH_FS_SYSFREQUENCY,      "sysfrequency" },
    /*--- { FLASH_FS_SYSTYPE,           "systype" }, ---*/
    { FLASH_FS_TR069_PASSPHRASE,  "tr069_passphrase" },
    { FLASH_FS_TR069_SERIAL,      "tr069_serial" },
    { FLASH_FS_URLADER_VERSION,   "urlader-version" },
    { FLASH_FS_MAC_USB_BOARD,     "usb_board_mac" },
    { FLASH_FS_MAC_USB_RNDIS,     "usb_rndis_mac" },
    { FLASH_FS_USB_DEVICE_ID,     "usb_device_id" },
    { FLASH_FS_USB_REVISION_ID,   "usb_revision_id" },
    { FLASH_FS_USB_DEVICE_NAME,   "usb_device_name" },
    { FLASH_FS_USB_MANUFACTURER_NAME,   "usb_manufacturer_name" },
    { FLASH_FS_WLAN_KEY,          "wlan_key" },
    { FLASH_FS_WLAN_CAL,          "wlan_cal" },

    /*--- ende ---*/

    { 0, "zuende" }
};
/*--- !!! <- alphabetisch sortiert !!!!! ---*/
#endif /*--- #if defined(TFFS_NAME_TABLE) ---*/

/*-----------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------*/
struct _tffs_cmd {
    enum _tffs_id id;
    unsigned int size;
    unsigned int status;
    void *buffer;
};

/*-----------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------*/
#if defined(__KERNEL__) || defined(URLADER) || defined(FLASH_TFFS_IMAGE)
struct _TFFS_Entry {
    unsigned short ID;
    unsigned short Length;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
union _tffs_segment_entry {
    struct _TFFS_Entry Entry;
    unsigned char Buffer[sizeof(struct _TFFS_Entry) + sizeof(unsigned int)];
};

#define TFFS_GET_SEGMENT_VALUE(E)  ~( \
                                        ((unsigned int)((E)->Buffer[sizeof(struct _TFFS_Entry) + 3]) <<  0) | \
                                        ((unsigned int)((E)->Buffer[sizeof(struct _TFFS_Entry) + 2]) <<  8) | \
                                        ((unsigned int)((E)->Buffer[sizeof(struct _TFFS_Entry) + 1]) << 16) | \
                                        ((unsigned int)((E)->Buffer[sizeof(struct _TFFS_Entry) + 0]) << 24)   \
                                    )

#define TFFS_SET_SEGMENT_VALUE(E, value)   ( \
                                         (E)->Buffer[sizeof(struct _TFFS_Entry) + 3] = ((~(value) >>  0) & 0xFF), \
                                         (E)->Buffer[sizeof(struct _TFFS_Entry) + 2] = ((~(value) >>  8) & 0xFF), \
                                         (E)->Buffer[sizeof(struct _TFFS_Entry) + 1] = ((~(value) >> 16) & 0xFF), \
                                         (E)->Buffer[sizeof(struct _TFFS_Entry) + 0] = ((~(value) >> 24) & 0xFF)  \
                                    )

#endif /*--- #if defined(__KERNEL__) || defined(URLADER) ---*/


/*-----------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------*/
#if !defined(URLADER)
#define _TFFS_READ_ID           0x01
#define _TFFS_WRITE_ID          0x02
#define _TFFS_FORMAT            0x03
#define _TFFS_CLEAR_ID          0x04
#define _TFFS_REINDEX           0x05
#define _TFFS_CLEANUP           0x06
#define _TFFS_INFO              0x07
#define _TFFS_WERKSEINSTELLUNG  0x08

#define _TFFS_TYPE_RAW          0x00

#include <asm/ioctl.h>

#define TFFS_READ_ID            _IOC(_IOC_READ | _IOC_WRITE, _TFFS_TYPE_RAW,         _TFFS_READ_ID, sizeof(struct _tffs_cmd))
#define TFFS_WRITE_ID           _IOC(_IOC_READ | _IOC_WRITE, _TFFS_TYPE_RAW,         _TFFS_WRITE_ID, sizeof(struct _tffs_cmd))
#define TFFS_FORMAT             _IOC(_IOC_READ | _IOC_WRITE, _TFFS_TYPE_RAW,         _TFFS_FORMAT, sizeof(struct _tffs_cmd))
#define TFFS_CLEAR_ID           _IOC(_IOC_READ | _IOC_WRITE, _TFFS_TYPE_RAW,         _TFFS_CLEAR_ID, sizeof(struct _tffs_cmd))
#define TFFS_REINDEX            _IOC(_IOC_READ | _IOC_WRITE, _TFFS_TYPE_RAW,         _TFFS_REINDEX, sizeof(struct _tffs_cmd))
#define TFFS_CLEANUP            _IOC(_IOC_READ | _IOC_WRITE, _TFFS_TYPE_RAW,         _TFFS_CLEANUP, sizeof(struct _tffs_cmd))
#define TFFS_INFO               _IOC(_IOC_READ | _IOC_WRITE, _TFFS_TYPE_RAW,         _TFFS_INFO, sizeof(struct _tffs_cmd))
#define TFFS_WERKSEINSTELLUNG   _IOC(_IOC_READ | _IOC_WRITE, _TFFS_WERKSEINSTELLUNG, _TFFS_INFO, sizeof(struct _tffs_cmd))

#define MAX_MINOR_100_BLOCK_SIZE        (32 * 1024)

/*-----------------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------------*/
#if defined(__KERNEL__)

#if defined(CONFIG_TFFS)
#if defined(CONFIG_TFFS_DOUBLE_BUFFER)
extern unsigned int TFFS_Init(unsigned int, unsigned int);
#else /*--- #if defined(CONFIG_TFFS_DOUBLE_BUFFER) ---*/
extern unsigned int TFFS_Init(unsigned int);
#endif /*--- #else ---*/ /*--- #if defined(CONFIG_TFFS_DOUBLE_BUFFER) ---*/
extern void TFFS_Deinit(void);
extern void *TFFS_Open(unsigned int, unsigned int, unsigned int);
extern void TFFS_Close(void *);
extern unsigned int TFFS_Werkseinstellungen(void *);
extern unsigned int TFFS_Minor(void *handle);
extern unsigned int TFFS_Clear(void *, enum _tffs_id);
extern unsigned int TFFS_Format(void *);
extern unsigned int TFFS_Write(void *, enum _tffs_id, unsigned char *, unsigned int, unsigned int);
extern unsigned int TFFS_Read(void *, enum _tffs_id, unsigned char *, unsigned int *);
extern unsigned int TFFS_Create_Index(void *);
extern unsigned int TFFS_Cleanup(void *);
extern unsigned int TFFS_Info(void *, unsigned int *);
extern unsigned char *TFFS_Read_Buffer(void *, unsigned int **);
extern unsigned char *TFFS_Write_Buffer(void *, unsigned int **);
void tffs_panic_log_open(void);
void tffs_panic_log_close(void);
extern void tffs_panic_log_write(char *buffer, unsigned int len);
#endif /*--- #if defined(CONFIG_TFFS) ---*/

#if defined(CONFIG_TFFS2)
struct mtd_info;

extern unsigned int TFFS_Init(unsigned int, unsigned int);
extern void TFFS_Deinit(void);
extern void *TFFS_Open(void);
extern void TFFS_Close(void *);
extern unsigned int TFFS_Werkseinstellungen(void *);
extern unsigned int TFFS_Minor(void *handle);
extern unsigned int TFFS_Clear(void *, enum _tffs_id);
extern unsigned int TFFS_Format(void *, struct mtd_info *mtd);
extern unsigned int TFFS_Write(void *, enum _tffs_id, unsigned char *, unsigned int, unsigned int);
extern unsigned int TFFS_Read(void *, enum _tffs_id, unsigned char *, unsigned int *);
extern unsigned int TFFS_Create_Index(void);
extern unsigned int TFFS_Cleanup(void *);
extern unsigned int TFFS_Info(void *, unsigned int *);
extern unsigned char *TFFS_Read_Buffer(void *, unsigned int **);
extern unsigned char *TFFS_Write_Buffer(void *, unsigned int **);
#endif /*--- #if defined(CONFIG_TFFS2) ---*/

#define TFFS_EVENT_CLEANUP      (1 << 0)
extern void tffs_send_event(unsigned int event);
#endif /*--- #if defined(__KERNEL__) ---*/
#endif /*--- #if !defined(URLADER) ---*/

#endif /*--- #ifndef _tffs_h_ ---*/
