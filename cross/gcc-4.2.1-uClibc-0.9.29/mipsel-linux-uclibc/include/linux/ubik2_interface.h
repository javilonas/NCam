/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ubik2_interface_h_
#define _ubik2_interface_h_

/*-----------------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------------*/
#define MODULE_NAME     "ubik2"
#define UBIK2_DEBUG      

/*-----------------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------------*/
#if defined(__KERNEL__)
#if defined(UBIK2_DEBUG)
#define DEB_ERR(args...)     printk(KERN_ERR args)
/*--- #define DEB_WARN(args...)    printk(KERN_WARNING args) ---*/
#define DEB_WARN(args...) 
/*--- #define DEB_INFO(args...)    if(ubik2.boot_phase == ubik2_boot_phase_run) printk(KERN_INFO args) ---*/
/*--- #define DEB_INFO(args...)    printk(KERN_INFO args) ---*/
/*--- #define DEB_INFO(args...)    CA_PRINTF(KERN_INFO args) ---*/
#define DEB_INFO(args...)
/*--- #define DEB_TRC(args...)     if(ubik2.boot_phase == ubik2_boot_phase_run) printk(KERN_ERR args) ---*/
/*--- #define DEB_TRC(args...)     printk(KERN_INFO args) ---*/
/*--- #define DEB_TRC(args...)     CA_PRINTF(KERN_INFO args) ---*/
#define DEB_TRC(args...)
#else /*--- #if defined(MANU_DEBUG) ---*/
#define DEB_ERR(args...)     printk(KERN_ERR args)
#define DEB_WARN(args...)
#define DEB_INFO(args...)
#define DEB_TRC(args...)
#endif /*--- #else ---*/ /*--- #if defined(MANU_DEBUG) ---*/

#include <asm/ioctl.h>
#endif /*--- #if defined(__KERNEL__) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _ubik2_tasklet_control {
    ubik2_tasklet_control_enter_critical,
    ubik2_tasklet_control_leave_critical,
    ubik2_tasklet_control_retrigger
};
extern void ubik2_rx_tasklet_control(enum _ubik2_tasklet_control);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef __CAPI_OSLIB__

#include <linux/ubik2_ul.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define LOGIC_CHAN_LL_NAMES     { \
    "chan_ubik2_boot_phase_0", \
    "chan_ubik2_boot_phase_1", \
    "chan_ubik2_boot_phase_2", \
    "chan_ubik2_boot_phase_last", \
    "chan_ubik2_unused_4", \
    "chan_ubik2_unused_5", \
    "chan_ubik2_unused_6", \
    "chan_ubik2_dsp_loopback", \
    "chan_ubik2_through_data", \
    "chan_ubik2_remote_loopback", \
    "chan_fpga_voip", \
    "chan_ubik2_unused_11", \
    "chan_ubik2_unused_12", \
    "chan_ubik2_unused_13", \
    "chan_ubik2_unused_14", \
    "chan_ubik2_unused_15", \
    "chan_ubik2_unused_16", \
    "chan_ubik2_unused_17", \
    "chan_ubik2_unused_18", \
    "chan_ubik2_unused_19", \
    "chan_ubik2_unused_20", \
    "chan_ubik2_unused_21", \
    "chan_ubik2_unused_22", \
    "chan_ubik2_unused_23", \
    "chan_ubik2_unused_24", \
    "chan_ubik2_unused_25", \
    "chan_ubik2_unused_26", \
    "chan_ubik2_unused_27", \
    "chan_ubik2_unused_28", \
    "chan_ubik2_unused_29", \
    "no_chan", \
    "chan_last" \
}

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _ubik2_boot_phase {
    ubik2_boot_phase_reset,
    ubik2_boot_phase_0_send,
    ubik2_boot_phase_0_done,
    ubik2_boot_phase_1_send,
    ubik2_boot_phase_1_done,
    ubik2_boot_phase_2_send,
    ubik2_boot_phase_2_done,
    ubik2_boot_phase_3_send,
    ubik2_boot_phase_run
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
union __transport_header {
	struct _transport_header_ul {  /*--- Upper Layer ---*/
		unsigned int Len 	       : 13;
        enum _logic_chan_ul chan   :  5;
		unsigned int BlockNr       :  5;
		unsigned int FreeUpTo      :  5;
        unsigned int Ready         :  1;
		unsigned int PoolFlag      :  3;  /*--- undef only for local use ---*/
	} header_ul;
	struct _transport_header_ll {  /*--- Lower Layer ---*/
		unsigned int Len 	       : 13;
        enum _logic_chan_ll chan   :  5;
		unsigned int BlockNr       :  5;
		unsigned int FreeUpTo      :  5;
        unsigned int Ready         :  1;
		unsigned int PoolFlag      :  3;  /*--- undef only for local use ---*/
	} header_ll;
	unsigned int i;
};

#define UBIK2_LL_DEFAULT_DATA_BLOCK_SIZE    256
#define UBIK2_LL_WINDOWSIZE         7
#define UBIK2_LL_TRIGGER_LEVEL      (UBIK2_LL_WINDOWSIZE / 4 + 1)
#if defined(__KERNEL__)
/*------------------------------------------------------------------------------------------*\
     * KERNEL INCLUDE * KERNEL INCLUDE * KERNEL INCLUDE * KERNEL INCLUDE * KERNEL INCLUDE * 
\*------------------------------------------------------------------------------------------*/
struct _ubik2_queue {
    volatile unsigned int read;      /*--- index in das array ---*/
    volatile unsigned int write;     /*--- index in das array ---*/
    unsigned int size;      /*--- anzahl der void * elemente in der Queue ---*/
    void * volatile *ptr[2];            /*--- pointer auf Queue buffer (index 0: DSP, index 1: MIPS Adresssicht) ---*/
#define UBIK2_ADDRESS_MAP_DSP       0
#define UBIK2_ADDRESS_MAP_COUNT     0  /*--- nur gültig fuer LocalToMips ---*/
#define UBIK2_ADDRESS_MAP_MIPS      1
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _ubik2_thread_state {
    ubik2_thread_state_off,
    ubik2_thread_state_init,
    ubik2_thread_state_idle,
    ubik2_thread_state_process,
    ubik2_thread_state_down
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(UBIK2_DEBUG)
extern char *ubik2_chan_names[];
extern char *ubik2_error_names[];
#endif /*--- #if defined(UBIK2_DEBUG) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _ubik2 {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0)
    dev_t        device;
    struct cdev *cdev;
#else/*--- #if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0) ---*/
    unsigned int major;
#endif/*--- #else ---*//*--- #if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0) ---*/
    unsigned int ToUbik2BufferCount;
    unsigned int protokoll_fehler;
    enum _ubik2_boot_phase boot_phase;

    /*--- aus ubik2_interface uebertragen ---*/
    volatile unsigned int received_ToMIPS_Number;   /*--- Nummer des letzten empfangenen Blockes vom DSP zum MIPS ---*/
    volatile unsigned int FromMIPS_Number;          /*--- Nummer des Blockes vom MIPS zum DSP ---*/
    volatile unsigned int Maximal_FromMIPS_SendNumber; /*--- vom DSP empfangen: Nummer bis zu der gesendet werden darf ---*/
    volatile unsigned int Maximal_ToMIPS_SendNumber;
    volatile unsigned int ToMIPS_Block_Count;
    volatile unsigned int FromMIPS_Block_Count;
    volatile unsigned int LastMaxSendNumber;
    struct timer_list ack_timer;
    unsigned int debug_flag;
#define DEBUG_BUFFER_SIZE   (10 * 1024)
    char *debug_buffer;
    struct _ubik2_debug_queue {
        unsigned char read, write, size;
        unsigned char *Buffer;
    } *debug_queue;
    unsigned int FromMIPS_WindowSize;
    struct _ubik2_queue LocalFromMIPS;
    struct _ubik2_queue SavedFreeToMIPS;
    wait_queue_head_t wait_for_memory_queue;
    wait_queue_head_t wait_for_activate;
    volatile unsigned int activate_done;
    unsigned int queues_initialized;
};
extern struct _ubik2 ubik2;

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _ubik2_device_list {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0)
    void *dummy;
#else/*--- #if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0) ---*/
	devfs_handle_t devfs_handle;
#endif/*--- #else ---*//*--- #if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0) ---*/
    unsigned int minor;
    char *Name;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _ubik2_open_data {
#define UBIK2_READ_KENNUNG      0x12538aDf
#define UBIK2_WRITE_KENNUNG     0x43fea7A0
    unsigned int kennung;
#define UBIK2_WAIT_READ     1
#define UBIK2_WAIT_WRITE    2
#define UBIK2_WAKEUP_WRITE  3
#define UBIK2_WAKEUP_READ   4
    unsigned int open_index;
    volatile unsigned int wait_flag;
    unsigned int kernel_open;
    enum _logic_chan_ll chan;
    unsigned int do_signal;
    wait_queue_head_t wait_queue;
    struct _ubik2_ll_handle *ll_handle;
    struct fown_struct *pf_owner;
    struct fasync_struct *fasync;
    struct _ubik2_queue LocalToMIPS;
    unsigned int last_block_len;
    unsigned int stack;
    unsigned int debug_printed;     /*--- Debugdaten erfolgreich ausgegeben ---*/
};

enum ubik2_task_state {
    ubik2_task_idle  = 0,
    ubik2_tx_task_running  = 1,
    ubik2_rx_tasklet_running  = 2,
    ubik2_tx_start_running = 3,
    ubik2_tx_timer_running = 4,
    ubik2_rx_conf_running = 5
};

struct _ubik2_ll_handle {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0)
    void *read_thread;
    long write_thread;
#endif/*--- #if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0) ---*/
    struct ll_channel {
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 0)
        unsigned int thread_pid;
#endif/*--- #if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 0) ---*/
        struct completion completion_event;
        struct _ubik2_open_data *open_data;
    } write, read;
    wait_queue_head_t     trigger_queue;
    volatile unsigned int tx_trigger;
    unsigned int          shutdown_threads;
    enum ubik2_task_state tx_task_running;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
int ubik2_wait_for_FreeToMIPS(void);
union __transport_header *ubik2_dequeue_FreeToMIPS(void);
unsigned int ubik2_put(struct _ubik2_open_data *open_data, void *data, unsigned int *write_length);
unsigned int ubik2_final_put(struct _ubik2_open_data *open_data);
unsigned int ubik2_get(struct _ubik2_open_data *open_data, unsigned char **rx_buffer, unsigned int *rx_buffer_length);
unsigned int ubik2_commit(struct _ubik2_open_data *open_data);
unsigned int ubik2_init_interface(unsigned int *, unsigned int);
void ubik2_deinit_interface(void);
void ubik2_init_debug(unsigned int queue_size);
int ubik2_rx_thread(void *reply_data);
int ubik2_tx_thread(void *reply_data);
#define UBIK2_EVENT_CLEANUP      (1 << 0)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define UBIK2_OPEN_READ      0
#define UBIK2_OPEN_WRITE     1
extern volatile struct _ubik2_open_data *ubik2_open_chan[2][logic_chan_last + 1];


/*------------------------------------------------------------------------------------------*\
 * durch dem ATM Treiber exportierte Funktionen
\*------------------------------------------------------------------------------------------*/
enum _status_ubik2_proto {
    status_rx_avail         =  0,
    status_tx_done          =  1,

    status_dsp_activate     =  2,
    status_dsp_deactivate   =  3,

    status_dsp_proto_error  =  4,
    status_dsp_packet_lost  =  5,
    status_dsp_ubik2_failed =  6,
    status_ubik2_memerror   =  7,

    status_dsp_reactivate   =  9,

    status_boot_0_done      = 10,
    status_boot_1_done      = 11,
    status_boot_2_done      = 12,
    status_boot_3_done      = 13
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define STATUS_UBIK2_PROTO      { \
    "status_rx_avail", \
    "status_tx_done", \
    "status_dsp_activate", \
    "status_dsp_deactivate", \
    "status_dsp_proto_error", \
    "status_dsp_packet_lost", \
    "status_dsp_ubik2_failed", \
    "status_ubik2_memerror", \
    "status_unused_8", \
    "status_dsp_reactivate", \
    "status_boot_0_done", \
    "status_boot_1_done", \
    "status_boot_2_done", \
    "status_boot_3_done", \
    "status_unused_14", \
    "status_unused_15" \
}

/*------------------------------------------------------------------------------------------*\
 * Funktionen die ATM Treiber definiert sind
\*------------------------------------------------------------------------------------------*/
extern void *atm_dsp_register_ubik2(unsigned int (*ubik2_Status_notify)(enum _status_ubik2_proto),
                                    void (*DebugPrintf)(const char *format, ...)
                                   );
extern void atm_dsp_release_ubik2(void);
extern void atm_dsp_trigger_ubik2(void);
extern void atm_dsp_activate_ubik2(void);
extern void atm_dsp_reactivate_ubik2(void);
extern void atm_dsp_deactivate_ubik2(void);
extern void atm_dsp_unlock_addr(unsigned int);
extern unsigned int atm_dsp_lock_addr(void *);

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
extern int ubik2_kernel_open(struct file *filp, enum _logic_chan_ll chan);
extern int ubik2_kernel_close(struct file *filp);
extern int ubik2_kernel_read(struct file *filp, char **read_buffer, size_t max_read_length, loff_t *read_pos);
extern ssize_t ubik2_kernel_write(struct file *filp, const char *write_buffer, size_t write_length, loff_t *write_pos);


void ubik2_set_call_context(enum ubik2_task_state state);
char *ubik2_get_call_context(void);

/*-------------------------------------------------------------------------------------*\
 * Upper-Layer Definitionen jeweils in Linux und UBIK2 eingesetzt
\*-------------------------------------------------------------------------------------*/
#if !defined(__KERNEL__)

/*-----------------------------------------------------------------------------*\
	ubik2_ul_rx_getbuffer  muss solange kein Protokollfehler vorliegt
      immer einen Buffer zurückliefern.

	Params: 1. Handle logischen Kanal
		    2. Doppelpointer auf Buffer

	Returnwert ist das Handle, welches bei ubik2_ul_rx_putbuffer angegeben
	wird.
\*-----------------------------------------------------------------------------*/
typedef void *(*ubik2_ul_rx_alloc_buffer_t)(void *, unsigned char **);

/*-----------------------------------------------------------------------------*\
	Ein zuvor mit ubik2_ul_rx_alloc_buffer(_t) allozieerter Buffer
	ist mit Informationen gefüllt und wird als empfangene Daten zurück
	geliefert.

	Params: 1. Handle logischen Kanal
		    2. Handle vom ubik2_ul_rx_alloc_buffer(_t)
		    3. Länge der Daten im Buffer
            4. empfangener Poolflag-Value (max. 3 Bit!)
	Return:  void
\*-----------------------------------------------------------------------------*/
typedef void (*ubik2_ul_rx_put_buffer_t)(void *, void *, int, unsigned int );


/*-----------------------------------------------------------------------------*\
	Fordert einen Buffer mit Sendedaten an. Ein weitere Aufruf dieser
	Funktion gibt den vorigen (Sende) Buffer free.
	Params:   1. Handle für logischen Kanal 
		      2. Doppelpointer auf Buffer
              3. Header/Poolflag-Value  (max. 3 Bit!)
	Return:  Länge
\*-----------------------------------------------------------------------------*/
typedef int (*ubik2_ul_tx_get_buffer_t)(void *, char **, unsigned *);

/*-----------------------------------------------------------------------------*\
	Registrieren eines logischen Kanals
	Return: Handle, oder NULL für Fehler
\*-----------------------------------------------------------------------------*/
void *ubik2_ul_register(enum _logic_chan_ul chan, 	
			    unsigned int free_buffer_count,  /*--- Anzahl der freien Buffer fuer Empfang ---*/
			    unsigned int buffer_size,        /*--- groesse eines Buffers in Bytes ---*/
			    ubik2_ul_rx_alloc_buffer_t,
	            ubik2_ul_rx_put_buffer_t,
			    ubik2_ul_tx_get_buffer_t);

/*-----------------------------------------------------------------------------*\
 * gibt logischen Chan zurück vom logischen Handle
\*-----------------------------------------------------------------------------*/
enum _logic_chan_ul ubik2_ul_getchanfromhandle(void *ulHandle); 

/*-----------------------------------------------------------------------------*\
	Information, dass ein zuvor verwendetet Rx Buffer, dem Buffer-Pool
	wieder zur Verfügung steht. "Handle" ist das jenige, welches bei register
	geliefert wurde.
\*-----------------------------------------------------------------------------*/
void ubik2_ul_rx_buffer_conf(void *Handle);

/*-----------------------------------------------------------------------------*\
    Sendewunsch signalisieren, hat einen Tx-Callback zur Folge.
	"Handle" ist dasjenige, welches bei register geliefert wurde.
\*-----------------------------------------------------------------------------*/
void ubik2_ul_tx_trigger(void *Handle);

/*-----------------------------------------------------------------------------*\
    Logischen Kanal freigeben. 
	"Handle" ist dasjenige, welches bei register geliefert wurde.
\*-----------------------------------------------------------------------------*/
void ubik2_ul_release(void *Handle);

#if defined(UL_STATISTIC)
/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
void ubik2_ul_statistic(void *ll_Handle, char *Buffer, unsigned int MaxBufferLen);
#endif/*--- #if defined(UL_STATISTIC) ---*/
#endif /*--- #if !defined(__KERNEL__) ---*/

#endif/*--- #if defined(__KERNEL__) ---*/
#endif /*--- #ifndef __CAPI_OSLIB__ ---*/
#endif /*--- #ifndef _ubik2_interface_h_ ---*/
