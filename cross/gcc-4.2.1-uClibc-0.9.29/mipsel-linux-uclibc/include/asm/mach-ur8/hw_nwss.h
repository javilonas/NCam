#ifndef _HW_NWSS_H_
#define _HW_NWSS_H_

/*------------------------------------------------------------------------------------------*\
 * NWSS DMA Register
\*------------------------------------------------------------------------------------------*/
union nwss_status {
    struct __nwss_status {
        volatile unsigned int  soft_status : 24;
        volatile unsigned int  gpr_status : 8;
    } Bits;
    volatile unsigned int Register;
};

struct __nwss_channel_cfg {
    union _tx_A {
        struct __tx_A {
            volatile unsigned int desc_copy_bytecnt : 7;
            volatile unsigned int reserved          : 25;
        } Bits;
        volatile unsigned int Register;
    } tx_A;
    union _tx_B {
        struct __tx_B {
            volatile unsigned int cq_index     : 3;
            volatile unsigned int reserved0    : 5;
            volatile unsigned int packet_type  : 4;
            volatile unsigned int channel_mode : 1;
            volatile unsigned int reserved2    : 3;
            volatile unsigned int tx_endian    : 1;
            volatile unsigned int reserved3    : 13;
            volatile unsigned int teardown     : 1;
            volatile unsigned int enable       : 1;
        } Bits;
        volatile unsigned int Register;
    } tx_B;
    union _rx_A {
        struct __rx_A {
            volatile unsigned int fbq0_index : 2;
            volatile unsigned int reserved0  : 6;
            volatile unsigned int fbq1_index : 2;
            volatile unsigned int reserved1  : 6;
            volatile unsigned int fbq2_index : 2;
            volatile unsigned int reserved2  : 6;
            volatile unsigned int fbq3_index : 2;
            volatile unsigned int reserved3  : 6;
        } Bits;
        volatile unsigned int Register;
    } rx_A;
    union _rx_B {
        struct __rx_B {
            volatile unsigned int rq_index       : 12;
            volatile unsigned int fdp_index      : 1;
            volatile unsigned int reserved0      : 3;
            volatile unsigned int sop_offset     : 8;
            volatile unsigned int error_handling : 1;
            volatile unsigned int channel_mode   : 1;
            volatile unsigned int rx_endian      : 1;
            volatile unsigned int reserved1      : 3;
            volatile unsigned int teardown       : 1;
            volatile unsigned int enable         : 1;
        } Bits;
        volatile unsigned int Register;
    } rx_B;
};
    
union nwss_dma_fetch {
    struct __dma_fetch {
        volatile unsigned int channel      : 4;
        volatile unsigned int reserved0    : 20;
        volatile unsigned int fetch_lentgh : 7;
        volatile unsigned int ready        : 1;
    } Bits;
    volatile unsigned int Register;
};

struct __nwss_global_registers {
    volatile unsigned int  ident; 
    volatile unsigned int  reserved0; 
    union nwss_status status_set;
    union nwss_status status_clear;
    union nwss_status int_enable_set;
    union nwss_status int_enable_clear;
    union nwss_status pdsp_enable_set;
    union nwss_status pdsp_enable_clear;
    volatile unsigned int  gp_mailbox[8]; 
};

/*------------------------------------------------------------------------------------------*\
 * Global Register zusammen auf 0x030000000
\*------------------------------------------------------------------------------------------*/
struct ur8_nwss_register {
    struct __nwss_global_registers  global;
    volatile unsigned int           DSP_Register[(0xA000-0x40)/sizeof(unsigned int)];
    struct __nwss_channel_cfg       Channel_Cfg[18];
    volatile unsigned int           reserved[(0xB000-0xA120)/sizeof(unsigned int)];
    volatile unsigned int           TearDown_Array_Pointer;
    volatile unsigned int           TearDown_Array_pSize;
};

/*------------------------------------------------------------------------------------------*\
 * NWSS Queue Manager Register
\*------------------------------------------------------------------------------------------*/
struct __free_buffer_pool {
    volatile unsigned int pointer; 
    volatile unsigned int size; 
};

struct __free_descr_buffer_queue {
    volatile unsigned int pointer; 
    volatile unsigned short reserved; 
    volatile unsigned short size; 
};

union tx_compl_queue_int_mask {
    struct __tx_completion {
        volatile unsigned int txcq0_int_enable : 1; 
        volatile unsigned int txcq1_int_enable : 1; 
        volatile unsigned int txcq2_int_enable : 1; 
        volatile unsigned int txcq3_int_enable : 1; 
        volatile unsigned int reserved : 28; 
    } Bits;
    volatile unsigned int Register;
};

union rx_compl_queue_int_mask {
    struct __rx_completion {
        volatile unsigned int rxcq0_int_enable : 1; 
        volatile unsigned int rxcq1_int_enable : 1; 
        volatile unsigned int rxcq2_int_enable : 1; 
        volatile unsigned int rxcq3_int_enable : 1; 
        volatile unsigned int rxcq4_int_enable : 1; 
        volatile unsigned int rxcq5_int_enable : 1; 
        volatile unsigned int rxcq6_int_enable : 1; 
        volatile unsigned int rxcq7_int_enable : 1; 
        volatile unsigned int reserved : 24; 
    } Bits;
    volatile unsigned int Register;
};

union compl_queue_end_int {
    struct __completion_end {
        volatile unsigned int cq_num   : 2; 
        volatile unsigned int reserved : 30; 
    } Bits;
    volatile unsigned int Register;
};

union rx_free_buffer_starvation {
    struct __queue_starv_count {
        volatile unsigned int fdbq0_starve_cnt : 8; 
        volatile unsigned int fdbq1_starve_cnt : 8; 
        volatile unsigned int fdbq2_starve_cnt : 8; 
        volatile unsigned int fdbq3_starve_cnt : 8; 
    } Bits;
    volatile unsigned int Register;
};

union revision_field {
    struct __revision {
        volatile unsigned int reserved  :  2;
        volatile unsigned int modId     : 14;
        volatile unsigned int revrtl    :  5;
        volatile unsigned int revmaj    :  3;
        volatile unsigned int revmin    :  8;
    } Bits;
    volatile unsigned int Register;
};

struct __queue_manager_ctrl {
    union tx_compl_queue_int_mask   tx_int_enable_set;
    union tx_compl_queue_int_mask   tx_int_enable_clear;
    union compl_queue_end_int       tx_int_end;
    volatile unsigned int           reserved0[(0x9040-0x900C)/sizeof(unsigned int)];
    union rx_compl_queue_int_mask   rx_int_enable_set;
    union rx_compl_queue_int_mask   rx_int_enable_clear;
    union compl_queue_end_int       rx_int_end;
    volatile unsigned int           reserved1[(0x9050-0x904C)/sizeof(unsigned int)];
    union rx_free_buffer_starvation queue_starvation_count;
    volatile unsigned int           reserved2[(0x9078-0x9054)/sizeof(unsigned int)];
    union revision_field            revision;
    volatile unsigned int           soft_reset;
};

/*------------------------------------------------------------------------------------------*\
 * TX-Queue Register
\*------------------------------------------------------------------------------------------*/
struct __prio0_tx_queue {
    volatile unsigned int channel;
    volatile unsigned int reserved[3];
};

struct __emac_queue {
    volatile unsigned int prio[2];
    volatile unsigned int reserved[2];
};

/*------------------------------------------------------------------------------------------*\
 * Rx-Queue Register
\*------------------------------------------------------------------------------------------*/
struct __rx_prio {
    volatile unsigned int   prio[4];
};

/*------------------------------------------------------------------------------------------*\
 * Queue Manager alle zusammen auf 0x03068000
\*------------------------------------------------------------------------------------------*/
struct ur8_queue_manager {
    volatile unsigned int               reserved0[(0x8010-0x8000)/sizeof(unsigned int)];
    volatile unsigned int               descriptor_reclamation;
    volatile unsigned int               reserved1[(0x8020-0x8014)/sizeof(unsigned int)];
    volatile unsigned int               buffer_reclamation;
    volatile unsigned int               reserved2[(0x8040-0x8024)/sizeof(unsigned int)];
    volatile unsigned int               free_descriptor_pool[16];   /*--- embedded mode ---*/
    volatile unsigned int               reserved3[(0x8100-0x8080)/sizeof(unsigned int)];
    struct __free_buffer_pool           free_buffer_pool[32];       /*--- embedded mode ---*/
    /*--- rx-Free-Descriptor / Buffer Queues ---*/
    struct __free_descr_buffer_queue    free_db_queue[32];          /*--- host mode ---*/
    volatile unsigned int               reserved4[(0x9000-0x8300)/sizeof(unsigned int)];
    /*--- Queue Manager Control ---*/
    union tx_compl_queue_int_mask       tx_int_enable_set;
    union tx_compl_queue_int_mask       tx_int_enable_clear;
    union compl_queue_end_int           tx_int_end;
    volatile unsigned int               reserved5[(0x9040-0x900C)/sizeof(unsigned int)];
    union rx_compl_queue_int_mask       rx_int_enable_set;
    union rx_compl_queue_int_mask       rx_int_enable_clear;
    union compl_queue_end_int           rx_int_end;
    volatile unsigned int               reserved6[(0x9050-0x904C)/sizeof(unsigned int)];
    union rx_free_buffer_starvation     queue_starvation_count;
    volatile unsigned int               reserved7[(0x9078-0x9054)/sizeof(unsigned int)];
    union revision_field                revision;
    volatile unsigned int               soft_reset;
    volatile unsigned int               reserved8[(0xD000-0x9080)/sizeof(unsigned int)];
    /*--- tx-Queues ---*/
    volatile unsigned int               tx_sar_channel0_prio[4];
    struct __prio0_tx_queue             tx_sar_prio0_channel[15];
    struct __emac_queue                 tx_emac[2];
    volatile unsigned int               reserved9[(0xF000-0xD120)/sizeof(unsigned int)];
    /*--- tx-completion Queues ---*/
    volatile unsigned int               tx_completion_queue[4]; 
    volatile unsigned int               reserved10[(0xF800-0xF010)/sizeof(unsigned int)];
    /*--- rx-Queues ---*/
    struct __rx_prio                    rx_queue[8];
};



#endif /*--- #ifndef _HW_NWSS_H_ ---*/
