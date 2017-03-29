/*-------------------------------------------------------------------------------------*\

    $Header$

    $Id$

    $Log$

\*-------------------------------------------------------------------------------------*/

#ifndef EMIF_H
#define EMIF_H

union EMIF_AsyncBankCR {
    struct _EMIF_AsyncBankCR {
        volatile unsigned int asize : 2;
        volatile unsigned int ta : 2;
        volatile unsigned int r_hold : 3;
        volatile unsigned int r_strobe : 6;
        volatile unsigned int r_setup : 4;
        volatile unsigned int w_hold : 3;
        volatile unsigned int w_strobe : 6;
        volatile unsigned int w_setup : 4;
        volatile unsigned int ew : 1;
        volatile unsigned int ss : 1;
    } Bits;
    volatile unsigned int i;
};

union EMIF_AsyncWaitCR {
    struct _EMIF_AsyncWaitCR {
        volatile unsigned int max_ext_wait : 8;
        volatile unsigned int reserved8 : 22;
        volatile unsigned int wp : 1;
        volatile unsigned int reserved31 : 1;
    } Bits;
    volatile unsigned int i;
};

union EMIF_SDRAM_RefreshCR {
    struct _EMIF_SDRAM_RefreshCR {
        volatile unsigned int refresh_rate : 13;
        volatile unsigned int reserved : 17;
        volatile unsigned int at : 1;
        volatile unsigned int lt : 1;
    } Bits;
    volatile unsigned int i;
};      

union EMIF_SDRAMTimingReg {
    struct _EMIF_SDRAMTimingReg {
        volatile unsigned int t_rfc : 4;
        volatile unsigned int t_rrd : 3;
        volatile unsigned int reserved1 : 1;
        volatile unsigned int t_rc : 4;
        volatile unsigned int t_ras : 4;
        volatile unsigned int t_wr : 3;
        volatile unsigned int reserved2 : 1;
        volatile unsigned int t_rcd : 3;
        volatile unsigned int reserved3 : 1;
        volatile unsigned int t_rp : 3;
        volatile unsigned int reserved4 : 5;
    } Bits;
    volatile unsigned int i;
};

union EMIF_SDRAMBankCR {
    struct _EMIF_SDRAMBankCR {
        volatile unsigned int pagesize : 3;
        volatile unsigned int ebank : 1;
        volatile unsigned int ibank : 3;
        volatile unsigned int pa : 1;
        volatile unsigned int reserved1 : 5;
        volatile unsigned int cl : 1;
        volatile unsigned int nm : 1;
        volatile unsigned int reserved2 : 16;
        volatile unsigned int sr : 1;
    } Bits;
    volatile unsigned int i;
};


struct EMIF_register_memory_map {
    /* offset 0x00 */ volatile unsigned int   RevCodeSR : 32;
    /* offset 0x04 */ volatile unsigned int   AsyncWaitCycleCR : 32;
    /* offset 0x08 */ union EMIF_SDRAMBankCR  SDRAMBankCR;
    /* offset 0x0C */ volatile unsigned int   SDRAMRefreshCR : 32;
    /* offset 0x10 */ union EMIF_AsyncBankCR  AsyncBankCR[4];
    /* offset 0x20 */ union EMIF_SDRAMTimingReg SDRAMTimingReg;
    /* offset 0x24 */ volatile unsigned int   empty0 : 32;
    /* offset 0x28 */ volatile unsigned int   empty1 : 32;
    /* offset 0x2C */ volatile unsigned int   empty2 : 32;
    /* offset 0x30 */ volatile unsigned int   TotalAccesses : 32;
    /* offset 0x34 */ volatile unsigned int   TotalActivate : 32;
};

    
#endif /*--- #ifndef EMIF_H ---*/
