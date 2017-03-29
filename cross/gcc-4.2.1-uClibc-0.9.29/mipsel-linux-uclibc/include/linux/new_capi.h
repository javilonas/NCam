#ifndef _linux_new_capi_h_
#define _linux_new_capi_h_

#include <linux/wait.h>

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
enum _bt20_profile {
    bt20_profile_reserved    = 0,
    bt20_profile_cmtp        = 1,
    bt20_profile_dun         = 2,
    bt20_profile_pan         = 3,
    bt20_profile_spp         = 4,   /*--- Serial Port Profile ---*/
    bt20_profile_fax         = 5,
    bt20_profile_lan         = 6,
    bt20_profile_headset     = 7,
    bt20_profile_cts         = 8,

    bt20_profile_management  = 59,
    bt20_profile_sdp_client  = 60,
    bt20_profile_l2cap       = 61,
    bt20_profile_acl         = 62,
    bt20_profile_hci         = 63
};
typedef enum _bt20_profile bt20_profile_t;

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
enum _CapiErrors {
    ERR_NoError               = 0x0000, /*--- TEXT: Request accepted ---*/
    ERR_NCPI_ignored          = 0x0001, /*--- TEXT: NCPI not supported by current protocol, NCPI ignored ---*/
    ERR_Flags_ignored         = 0x0002, /*--- TEXT: Flags not supported by current protocol, flags ignored ---*/
    ERR_AlertAlreadySend      = 0x0003, /*--- TEXT: Alert already sent by another application ---*/

    ERR_ToManyApplications    = 0x1001, /*--- TEXT: Too many applications ---*/
    ERR_BlockToSmall          = 0x1002, /*--- TEXT: Logical block size too small; must be at least 128 bytes ---*/
    ERR_Buffer64k             = 0x1003, /*--- TEXT: Buffer exceeds 64 kbytes ---*/
    ERR_MessageToSmall        = 0x1004, /*--- TEXT: Message buffer size too small, must be at least 1024 bytes ---*/
    ERR_MaxLogicalConnections = 0x1005, /*--- TEXT: Max. number of logical connections not supported ---*/
    ERR_1006_Reserved         = 0x1006, /*--- TEXT: reserved ---*/
    ERR_SendBusy              = 0x1007, /*--- TEXT: The message could not be accepted because of an internal busy condition ---*/
    ERR_ResourceError         = 0x1008, /*--- TEXT: OS resource error (e.g. no memory) ---*/
    ERR_No_CAPI               = 0x1009, /*--- TEXT: COMMON-ISDN-API not installed ---*/
    ERR_No_External           = 0x100A, /*--- TEXT: Controller does not support external equipment ---*/
    ERR_Only_External         = 0x100B, /*--- TEXT: Controller does only support external equipment ---*/

    ERR_IllegalApplId         = 0x1101, /*--- TEXT: Illegal application number ---*/
    ERR_IllegalMessage        = 0x1102, /*--- TEXT: Illegal command or subcommand, or message length less than 12 octets ---*/
    ERR_QueueFull             = 0x1103, /*--- TEXT: The message could not be accepted because of a queue full condition. The error code does not imply that COMMON-ISDN-API cannot receive messages directed to another controller, PLCI or NCCI. ---*/
    ERR_QueueEmpty            = 0x1104, /*--- TEXT: Queue is empty ---*/
    ERR_MessageLost           = 0x1105, /*--- TEXT: Queue overflow: a message was lost. This indicates a configuration error. The only recovery from this error is to do the CAPI_RELEASE operation. ---*/
    ERR_UnknownNotification   = 0x1106, /*--- TEXT: Unknown notification parameter ---*/
    ERR_InternalBusy          = 0x1107, /*--- TEXT: The message could not be accepted because of an internal busy condition ---*/
    ERR_OS_Resource           = 0x1108, /*--- TEXT: 0x1108 OS resource error (e.g. no memory) ---*/
    ERR_No_CAPI_11            = 0x1109, /*--- TEXT: 0x1109 COMMON-ISDN-API not installed ---*/
    ERR_No_External_11        = 0x110A, /*--- TEXT: 0x110A Controller does not support external equipment ---*/
    ERR_Only_External_11      = 0x110B, /*--- TEXT: 0x110B Controller supports only external equipment ---*/

    ERR_MessageNotSupportedInCurrentState = 0x2001,
    ERR_IllegalController                 = 0x2002,
    ERR_IllegalPLCI                       = 0x2002,
    ERR_IllegalNCCI                       = 0x2002,
    ERR_OutOfPLCI                         = 0x2003,
    ERR_OutOfNCCI                         = 0x2004,
    ERR_OutOfLISTEN                       = 0x2005,
    ERR_OutOfFaxResources                 = 0x2006,
    ERR_IllegalMessageParameterCoding     = 0x2007,

    ERR_B1ProtocolNotSupported            = 0x3001,
    ERR_B2ProtocolNotSupported            = 0x3002,
    ERR_B3ProtocolNotSupported            = 0x3003,
    ERR_B1ProtocolParameterNotSupported   = 0x3004,
    ERR_B2ProtocolParameterNotSupported   = 0x3005,
    ERR_B3ProtocolParameterNotSupported   = 0x3006,
    ERR_BProtocolCombinationNotSupported  = 0x3007,
    ERR_NCPINotSupported                  = 0x3008,
    ERR_CIPValueUnknown                   = 0x3009,
    ERR_FlagsNotSupported                 = 0x300A,
    ERR_FacilitiesNotSupported            = 0x300B,
    ERR_DataLengthNotSupported            = 0x300C,
    ERR_ResetProcedureNotSupported        = 0x300D,
    ERR_SupplServicesNotSupported         = 0x300E,

    ERR_RequestNotAllowedInThisState      = 0x3010,

    ERR_AnotherApplicationGotCall         = 0x3304,

    ERR_L2CAP_No_Error                    = 0x6500,
    ERR_L2CAP_PSM_Not_Supported           = 0x6501,
    ERR_L2CAP_Security_Block              = 0x6502,
    ERR_L2CAP_No_Resources                = 0x6503,
    ERR_L2CAP_Timeout                     = 0x6504,
    ERR_L2CAP_QoS_Failure                 = 0x6505,

    ERR_RFCOMM_Protocol_Error             = 0x6601,
    ERR_RFCOMM_Remote_Protocol_Error      = 0x6602,
    ERR_RFCOMM_Timeout                    = 0x6603,
    ERR_HigherLayer_Unknown               = 0x66FF,

    ERR_NameResolution_Failed             = 0x6701,
    ERR_ConnRefused_Role_Reject           = 0x6702
};

typedef enum _CapiErrors CapiErrors_t;

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
extern unsigned char *CAPI_Version;  /*--- CAPI_Version[MAX_CONTROLLERS][256] ---*/

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
void CAPI_INIT(void);
void CAPI_MESSAGE(unsigned int ApplId, unsigned char *Msg, unsigned int MsgLen);

/*-------------------------------------------------------------------------------------*\
    Diese Function wird durch den CAPI Treiber aufgerufen nachdem CAPI vorhanden
    ist.
\*-------------------------------------------------------------------------------------*/
unsigned int APPLICATION_INIT(unsigned int FirstController);

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------*\
    CAPI_REGISTER:

    Paramenter:
        unsigned int MessageBufferSize          größte Message die empfangen werden kann
        unsigned int MaxNCCIs                   anzahl der logischen Verbindungen
        unsigned int WindowSize                 ...
        unsigned int B3BlockSize
        unsigned int *ApplId                    zeigt ggf. auf neue ApplId (1 - 20)

    Returnwerte:
        ERR_ToManyApplications    0x1001
        ERR_ResourceError         0x1008
        ERR_NoError               0x0000

\*-------------------------------------------------------------------------------------*/
unsigned int CAPI_REGISTER(unsigned int MessageBufferSize,
                           unsigned int MaxNCCIs,
                           unsigned int WindowSize,
                           unsigned int B3BlockSize,
                           unsigned int *ApplId);
#define CAPI_REGISTER_MAJOR_FLAG        (1U << 30)
#define CAPI_REGISTER_MINOR_FLAG        (1U << 31)
#define CAPI_REGISTER_FLAG_MASK         (CAPI_REGISTER_MINOR_FLAG | CAPI_REGISTER_MAJOR_FLAG)

/*-------------------------------------------------------------------------------------*\
    CAPI_RELEASE:

    Parameter:
        unsigned int ApplId

    Returnwerte:
        ERR_ResourceError         0x1008
        ERR_IllegalApplId         0x1101

\*-------------------------------------------------------------------------------------*/
unsigned int CAPI_RELEASE(unsigned int ApplId);

/*-------------------------------------------------------------------------------------*\
    CAPI_PUT_MESSAGE:

    Voraussetzungen:
        bei DATA_B3_REQ muß der Daten-Buffer mittels der Funktion
        CAPI_NEW_DATA_B3_REQ_BUFFER(ApplId, NCCI) gealloceiert werden.
        (freigegeben wird er durch den Stack)

    Randbedingungen:
        Der Prozess der CAPI_PUT_MESSAGE aufruft kann u.U. blockieren.

    Parameter:
        unsigned int ApplId
        unsigned char *CapiMessage

    Returnwerte
        ERR_ResourceError         0x1008
        ERR_IllegalApplId         0x1101

\*-------------------------------------------------------------------------------------*/
unsigned int CAPI_PUT_MESSAGE(unsigned int ApplId, unsigned char *CapiMessage);

/*-------------------------------------------------------------------------------------*\
    CAPI_GET_MESSAGE:

    Voraussetzungen:
        der Buffer auf den pCapiMessage zeigt kann entweder durch die CAPI_GET_MESSAGE
        funktion alloceiert werden (*pCapiMessage == NULL) oder zuvor selber angelegt
        werden.(*pCapiMessage != NULL)

        Wenn der Buffer durch die CAPI_GET_MESSAGE funktion allozeiert wurde ist dieser
        durch free() freizugeben.

    Randbedingungen:
        Der Prozess der CAPI_GET_MESSAGE aufruft kann blockieren (in der Regel ja).

    Parameter:
        unsigned int ApplId
        unsigned char **pCapiMessage

    Returnwerte
        ERR_ResourceError         0x1008
        ERR_IllegalApplId         0x1101

\*-------------------------------------------------------------------------------------*/
unsigned int CAPI_GET_MESSAGE(unsigned int ApplId, unsigned char **pCapiMessage, unsigned int Suspend);
unsigned int CAPI_GET_MESSAGE_WAIT_QUEUE(unsigned int ApplId, wait_queue_head_t *rx_wait_queue,
                                         wait_queue_head_t *tx_wait_queue);

/*-------------------------------------------------------------------------------------*\
    NEU: CAPI_NEW_DATA_B3_REQ_BUFFER

    Aufgabe:
        Allozeiert den Datenbuffer für DATA_B3_REQUESTS (werden vom Stack freigegeben)

    Randbedingungen:
        Wenn eine CAPI_Funktion mit ERR_IllegalApplId zurückkehrt darf der Buffer
        nicht mehr verwendet werden. Das gleichen gild nach dem Senden oder Empfangen eines
        B3_DISCONNECT  (NCCI nicht mehr gültig)

    Parameter:
        unsigned int ApplId         ApplId
        unsigned int NCCI           gültiger NCCI

    Returwert:
        NULL        keine Buffer vorhanden
        !NULL       gültiger Buffer

\*-------------------------------------------------------------------------------------*/
unsigned char *CAPI_NEW_DATA_B3_REQ_BUFFER(unsigned int ApplId, unsigned int NCCI);

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
/*--- unsigned int CAPI_SET_SIGNAL(unsigned int ApplId, struct capi_events *, unsigned int Bit); ---*/

/*-------------------------------------------------------------------------------------*\
    siehe CAPI Spec.
\*-------------------------------------------------------------------------------------*/
void CAPI_GET_MANUFACTURER(char *Buffer);

/*-------------------------------------------------------------------------------------*\
    siehe CAPI Spec.
\*-------------------------------------------------------------------------------------*/
unsigned int CAPI_GET_VERSION(unsigned int *pCAPIMajor,
                              unsigned int *pCAPIMinor,
                              unsigned int *pManufactuererMajor,
                              unsigned int *pManufactuererMinor);

/*-------------------------------------------------------------------------------------*\
    siehe CAPI Spec.  (zusätzllich Controller)
\*-------------------------------------------------------------------------------------*/
unsigned int CAPI_GET_SERIAL_NUMBER(unsigned int Controller, char *Buffer);

/*-------------------------------------------------------------------------------------*\
    siehe CAPI Spec.
\*-------------------------------------------------------------------------------------*/
unsigned int CAPI_GET_PROFILE(unsigned char *Buffer, unsigned int Controller);

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
unsigned char *CAPI_GET_BUFFER(unsigned int ApplId, unsigned int Size);

/*-------------------------------------------------------------------------------------*\
    siehe CAPI Spec.  (zusätzllich Controller)
    für welchen Controller CAPI installiert ist hängt von der Konfiguration im Host
    Rechner ab. (z.B 1. C4:  1-4 zweite C4 5-8)
\*-------------------------------------------------------------------------------------*/
unsigned int CAPI_INSTALLED(unsigned int Controller);

/*-------------------------------------------------------------------------------------*\
    gilt nur für dword align messages
\*-------------------------------------------------------------------------------------*/
#pragma pack(1)
#define __packed

struct __attribute__ ((packed)) _capi_message {
    struct __attribute__ ((packed)) _capi_message_header {
        unsigned short Length;
        unsigned short ApplId;
        unsigned char  Command;
        unsigned char  SubCommand;
        unsigned short MessageNr;
    } capi_message_header;
    /*--- Offset 8 Bytes ---*/
    __packed union __attribute__ ((packed)) _capi_message_part {
        __packed struct __attribute__ ((packed)) _interoperability_request {
            unsigned short selector;
            unsigned char  interoperability_request_parameter_len;
#ifdef NOCH_NICHT /*--- short und int align für BLKFN ---*/
            __packed struct __attribute__ ((packed)) _interoperability_request_parameter {
                unsigned short function;
                unsigned char bluetooth_interoperability_request_parameter_len;
                unsigned char bluetooth_interoperability_request_parameter[100];
            } interoperability_request_parameter;
#endif /*--- #ifdef NOCH_NICHT ---*/
        } interoperability_request;
        __packed struct __attribute__ ((packed)) _interoperability_conf {
            unsigned short Info;
            unsigned short selector;
            unsigned char  interoperability_conf_parameter_len;
            unsigned char function_low;  /*--- aus struct _interoperability_conf_parameter herausgezogen ---*/
            unsigned char function_high; /*--- aus struct _interoperability_conf_parameter herausgezogen ---*/
#ifdef NOCH_NICHT /*--- short und int align für BLKFN ---*/
            __packed struct __attribute__ ((packed)) _interoperability_conf_parameter {
                unsigned short function;
                unsigned char bluetooth_interoperability_conf_parameter_len;
                unsigned char bluetooth_interoperability_conf_parameter[100];
            } interoperability_conf_parameter;
#endif /*--- #ifdef NOCH_NICHT ---*/
        } interoperability_conf;
        __packed struct __attribute__ ((packed)) _data_b3_req {
            unsigned int NCCI;
            unsigned char *Data;
            unsigned short DataLen;
            unsigned short Handle;
            unsigned short Flags;
        } data_b3_req;
        __packed struct __attribute__ ((packed)) _data_b3_ind {
            unsigned int NCCI;
            unsigned char *Data;
            unsigned short DataLen;
            unsigned short Handle;
            unsigned short Flags;
        } data_b3_ind;
        __packed struct __attribute__ ((packed)) _data_b3_conf {
            unsigned int NCCI;
            unsigned short Handle;
            unsigned short Info;
        } data_b3_conf;
        __packed struct __attribute__ ((packed)) _data_b3_resp {
            unsigned int NCCI;
            unsigned short Handle;
        } data_b3_resp;
#ifdef NOCH_NICHT /*--- short und int align für BLKFN ---*/
        __packed struct __attribute__ ((packed)) _alert_req {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } alert_req;
        __packed struct __attribute__ ((packed)) _alert_conf {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } alert_conf;
        __packed struct __attribute__ ((packed)) _connect_req {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } connect_req;
        __packed struct __attribute__ ((packed)) _connect_conf {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } connect_conf;
        __packed struct __attribute__ ((packed)) _connect_ind {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } connect_ind;
#endif /*--- #ifdef NOCH_NICHT ---*/
        __packed struct __attribute__ ((packed)) _connect_resp {
            unsigned int PLCI;
            unsigned short reject;
            unsigned char params[1];
        } connect_resp;
        __packed struct __attribute__ ((packed)) _connect_active_ind {
            unsigned int PLCI;
            unsigned char params[1];
        } connect_active_ind;
        __packed struct __attribute__ ((packed)) _connect_active_resp {
            unsigned int PLCI;
        } connect_active_resp;
        __packed struct __attribute__ ((packed)) _connect_b3_active_ind {
            unsigned int NCCI;
            unsigned char NCPI[1];
        } connect_b3_active_ind;
        __packed struct __attribute__ ((packed)) _connect_b3_active_resp {
            unsigned int NCCI;
        } connect_b3_active_resp;
        __packed struct __attribute__ ((packed)) _connect_b3_req {
            unsigned int NCCI;
            unsigned char NCPI[1];
        } connect_b3_req;
        __packed struct __attribute__ ((packed)) _connect_b3_conf {
            unsigned int NCCI;
            unsigned short Info;
        } connect_b3_conf;
        __packed struct __attribute__ ((packed)) _connect_b3_ind {
            unsigned int NCCI;
            unsigned char NCPI[1];
        } connect_b3_ind;
        __packed struct __attribute__ ((packed)) _connect_b3_resp {
            unsigned int NCCI;
            unsigned short reject;
            unsigned char NCPI[1];
        } connect_b3_resp;
        __packed struct __attribute__ ((packed)) _connect_b3_t90_active_ind {
            unsigned int NCCI;
            unsigned char NCPI[1];
        } connect_b3_t90_active_ind;
        __packed struct __attribute__ ((packed)) _connect_b3_t90_active_resp {
            unsigned int NCCI;
        } connect_b3_t90_active_resp;
        __packed struct __attribute__ ((packed)) _disconnect_b3_req {
            unsigned int NCCI;
            unsigned char NCPI[1];
        } disconnect_b3_req;
        __packed struct __attribute__ ((packed)) _disconnect_b3_conf {
            unsigned int NCCI;
            unsigned short Info;
        } disconnect_b3_conf;
        __packed struct __attribute__ ((packed)) _disconnect_b3_ind {
            unsigned int NCCI;
            unsigned short reason;
            unsigned char NCPI[1];
        } disconnect_b3_ind;
        __packed struct __attribute__ ((packed)) _disconnect_b3_resp {
            unsigned int NCCI;
        } disconnect_b3_resp;
        __packed struct __attribute__ ((packed)) _disconnect_req {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } disconnect_req;
        __packed struct __attribute__ ((packed)) _disconnect_conf {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } disconnect_conf;
        __packed struct __attribute__ ((packed)) _disconnect_ind {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } disconnect_ind;
        __packed struct __attribute__ ((packed)) _disconnect_resp {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } disconnect_resp;
        __packed struct __attribute__ ((packed)) _facility_req {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } facility_req;
        __packed struct __attribute__ ((packed)) _facility_conf {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } facility_conf;
        __packed struct __attribute__ ((packed)) _facility_ind {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } facility_ind;
        __packed struct __attribute__ ((packed)) _facility_resp {
            unsigned int kommt_noch; /*--- parameter noch einzugeben ---*/
        } facility_resp;
        __packed struct __attribute__ ((packed)) _info_req {
            unsigned int controller;
            unsigned char params[1];
        } info_req;
        __packed struct __attribute__ ((packed)) _info_conf {
            unsigned int controller;
            unsigned short Info;
        } info_conf;
        __packed struct __attribute__ ((packed)) _info_ind {
            unsigned int controller;
            unsigned char params[1];
        } info_ind;
        __packed struct __attribute__ ((packed)) _info_resp {
            unsigned int controller;
        } info_resp;
        __packed struct __attribute__ ((packed)) _listen_req {
            unsigned int controller;
            unsigned int info_mask;
            unsigned int cip_mask;
            unsigned int cip_mask2;
            unsigned char params[1];
        } listen_req;
        __packed struct __attribute__ ((packed)) _listen_conf {
            unsigned int controller;
            unsigned short Info;
        } listen_conf;
        __packed struct __attribute__ ((packed)) _manufacturer_req {
            unsigned int controller;
            unsigned int manu_id;
            unsigned int Class;
            unsigned int function;
            unsigned char params[1];
        } manufacturer_req;
        __packed struct __attribute__ ((packed)) _manufacturer_conf {
            unsigned int controller;
            unsigned int manu_id;
            unsigned int Class;
            unsigned int function;
            unsigned char params[1];
        } manufacturer_conf;
        __packed struct __attribute__ ((packed)) _manufacturer_ind {
            unsigned int controller;
            unsigned int manu_id;
            unsigned int Class;
            unsigned int function;
            unsigned char params[1];
        } manufacturer_ind;
        __packed struct __attribute__ ((packed)) _manufacturer_resp {
            unsigned int controller;
            unsigned int manu_id;
            unsigned int Class;
            unsigned int function;
            unsigned char params[1];
        } manufacturer_resp;
        __packed struct __attribute__ ((packed)) _reset_b3_req {
            unsigned int NCCI;
            unsigned char NCPI[1];
        } reset_b3_req;
        __packed struct __attribute__ ((packed)) _reset_b3_conf {
            unsigned int NCCI;
            unsigned short Info;
        } reset_b3_conf;
        __packed struct __attribute__ ((packed)) _reset_b3_ind {
            unsigned int NCCI;
            unsigned char NCPI[1];
        } reset_b3_ind;
        __packed struct __attribute__ ((packed)) _reset_b3_resp {
            unsigned int NCCI;
        } reset_b3_resp;
        __packed struct __attribute__ ((packed)) _select_b_protocol_req {
            unsigned int PLCI;
            unsigned char BProotcol[1];
        } select_b_protocol_req;
        __packed struct __attribute__ ((packed)) _select_b_protocol_conf {
            unsigned int PLCI;
            unsigned short Info;
        } select_b_protocol_conf;
    } capi_message_part;
};

#pragma pack()

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define CAPI_ALERT                      0x01
#define CAPI_CONNECT                    0x02
#define CAPI_CONNECT_ACTIVE             0x03
#define CAPI_INTEROPERABILITY           0x20
#define CAPI_CONNECT_B3_ACTIVE          0x83
#define CAPI_CONNECT_B3                 0x82
#define CAPI_CONNECT_B3_T90_ACTIVE      0x88
#define CAPI_DATA_B3                    0x86
#define CAPI_DISCONNECT_B3              0x84
#define CAPI_DISCONNECT                 0x04
#define CAPI_FACILITY                   0x80
#define CAPI_INFO                       0x08
#define CAPI_LISTEN                     0x05
#define CAPI_MANUFACTURER               0xFF
#define CAPI_RESET_B3                   0x87
#define CAPI_SELECT_B_PROTOCOL          0x41

#define CAPI_REMOTE_REGISTER   0xFD
#define CAPI_REMOTE_RELEASE    0xFE

#define CAPI_REQ        0x80
#define CAPI_IND        0x82
#define CAPI_CONF       0x81
#define CAPI_RESP       0x83

#if defined(BT_ACCESS)
#define CAPI_INTEROPERABILITY_REGISTER          0x00
#define CAPI_INTEROPERABILITY_RELEASE           0x01
#define CAPI_INTEROPERABILITY_GET_PROFILE       0x02
#define CAPI_INTEROPERABILITY_GET_MANUFACTURER  0x03
#define CAPI_INTEROPERABILITY_GET_VERSION       0x04
#define CAPI_INTEROPERABILITY_GET_SERIAL_NUMBER 0x05
#define CAPI_INTEROPERABILITY_MANUFACTURER      0x06
#define CAPI_INTEROPERABILITY_ECHO              0x07

#define CAPI_INTEROPERABILITY_TEST_CTRL         0x80

#define CAPI_INTEROPERABILITY_SELECTOR_USB       0
#define CAPI_INTEROPERABILITY_SELECTOR_BLUETOOTH 1
#endif /*--- #if defined(BT_ACCESS) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifdef OSLIB_DEBUG
extern char *CAPI_MESSAGE_NAME(unsigned char Command, unsigned char SubCommand);
extern void CapiTrace(unsigned char *Msg, void (*print)(const char *, ...));
#endif /*--- #ifdef OSLIB_DEBUG ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
typedef struct capi_register_params {	/* CAPI_REGISTER */
	__u32 level3cnt;	/* No. of simulatneous user data connections */
	__u32 datablkcnt;	/* No. of buffered data messages */
	__u32 datablklen;	/* Size of buffered data messages */
} capi_register_params;

#define	CAPI_REGISTER_IOCTL         0x01   	/*--- _IOW('C',0x01,struct capi_register_params) ---*/
#define CAPI_MANUFACTURER_LEN		64

#define	CAPI_GET_MANUFACTURER_IOCTL 0x06    /*---	_IOWR('C',0x06,int)	---*/

typedef struct capi_version {
	__u32 majorversion;
	__u32 minorversion;
	__u32 majormanuversion;
	__u32 minormanuversion;
} capi_version;

#define CAPI_GET_VERSION_IOCTL      0x07    /*---	_IOWR('C',0x07,struct capi_version) ---*/

#define CAPI_SERIAL_LEN		8
#define CAPI_GET_SERIAL_IOCTL       0x08    /*---	_IOWR('C',0x08,int)	---*/

typedef struct capi_profile {
	__u16 ncontroller;	/* number of installed controller */
	__u16 nbchannel;	/* number of B-Channels */
	__u32 goptions;		/* global options */
	__u32 support1;		/* B1 protocols support */
	__u32 support2;		/* B2 protocols support */
	__u32 support3;		/* B3 protocols support */
	__u32 reserved[6];	/* reserved */
	__u32 manu[5];		/* manufacturer specific information */
} capi_profile;

#define CAPI_GET_PROFILE_IOCTL      0x09    /*---	_IOWR('C',0x09,struct capi_profile) ---*/

typedef struct capi_manufacturer_cmd {
	unsigned long cmd;
	void __user *data;
} capi_manufacturer_cmd;

#define CAPI_MANUFACTURER_CMD_IOCTL 0x20    /*---	_IOWR('C',0x20, struct capi_manufacturer_cmd) ---*/
#define CAPI_GET_ERRCODE_IOCTL      0x21    /*---	_IOR('C',0x21, __u16) ---*/
#define CAPI_INSTALLED_IOCTL        0x22    /*---	_IOR('C',0x22, __u16) ---*/

/*------------------------------------------------------------------------------------------*\
 * member contr is input for
 * CAPI_GET_MANUFACTURER, CAPI_VERSION, CAPI_GET_SERIAL
 * and CAPI_GET_PROFILE
\*------------------------------------------------------------------------------------------*/
typedef union capi_ioctl_struct {
	__u32 contr;
	capi_register_params rparams;
	__u8 manufacturer[CAPI_MANUFACTURER_LEN];
	capi_version version;
	__u8 serial[CAPI_SERIAL_LEN];
	capi_profile profile;
	capi_manufacturer_cmd cmd;
	__u16 errcode;
} capi_ioctl_struct;

/*------------------------------------------------------------------------------------------*\
 * Middleware extension
\*------------------------------------------------------------------------------------------*/

#define CAPIFLAG_HIGHJACKING	0x0001

#define CAPI_GET_FLAGS_IOCTL        0x23    /*---	_IOR('C',0x23, unsigned) ---*/
#define CAPI_SET_FLAGS_IOCTL        0x24    /*---	_IOR('C',0x24, unsigned) ---*/
#define CAPI_CLR_FLAGS_IOCTL        0x25    /*---	_IOR('C',0x25, unsigned) ---*/
#define CAPI_NCCI_OPENCOUNT_IOCTL   0x26    /*---	_IOR('C',0x26, unsigned) ---*/
#define CAPI_NCCI_GETUNIT_IOCTL     0x27    /*---	_IOR('C',0x27, unsigned) ---*/

#endif /*--- #define _linux_new_capi_h_ ---*/
