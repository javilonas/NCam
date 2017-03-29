/*------------------------------------------------------------------------------------------*\
 *
 *  $Id: hw_uart.h 1.2 2004/03/29 13:24:07Z mpommerenke Exp $
 *
 *  $Log: hw_uart.h $
 *  Revision 1.2  2004/03/29 13:24:07Z  mpommerenke
 *  Revision 1.1  2004/01/29 12:29:24Z  mpommerenke
 *  Initial revision
 *
\*------------------------------------------------------------------------------------------*/
#ifndef _hw_uart_h_
#define _hw_uart_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifdef EB
#define BEO 3
#else
#define BEO 0
#endif

#define SIO0__BASE    	UARTA_BASE 
#define SIO0__OFFSET   	4
#define SIO0__RSTMASK  	0x01

#define SIO0_RDAT (*(volatile char *)(SIO0__BASE+(SIO0__OFFSET*0)+BEO))
#define SIO0_TDAT (*(volatile char *)(SIO0__BASE+(SIO0__OFFSET*0)+BEO))
#define SIO0_IE   (*(volatile char *)(SIO0__BASE+(SIO0__OFFSET*1)+BEO))
#define SIO0_IIR  (*(volatile char *)(SIO0__BASE+(SIO0__OFFSET*2)+BEO))
#define SIO0_LC   (*(volatile char *)(SIO0__BASE+(SIO0__OFFSET*3)+BEO))
#define SIO0_MC   (*(volatile char *)(SIO0__BASE+(SIO0__OFFSET*4)+BEO))
#define SIO0_LS   (*(volatile char *)(SIO0__BASE+(SIO0__OFFSET*5)+BEO))
#define SIO0_MS   (*(volatile char *)(SIO0__BASE+(SIO0__OFFSET*6)+BEO))

#define SIO1_RDAT (*(volatile char *)(SIO1__BASE+(SIO1__OFFSET*0)+BEO))
#define SIO1_TDAT (*(volatile char *)(SIO1__BASE+(SIO1__OFFSET*0)+BEO))
#define SIO1_IE   (*(volatile char *)(SIO1__BASE+(SIO1__OFFSET*1)+BEO))
#define SIO1_IIR  (*(volatile char *)(SIO1__BASE+(SIO1__OFFSET*2)+BEO))
#define SIO1_LC   (*(volatile char *)(SIO1__BASE+(SIO1__OFFSET*3)+BEO))
#define SIO1_MC   (*(volatile char *)(SIO1__BASE+(SIO1__OFFSET*4)+BEO))
#define SIO1_LS   (*(volatile char *)(SIO1__BASE+(SIO1__OFFSET*5)+BEO))
#define SIO1_MS   (*(volatile char *)(SIO1__BASE+(SIO1__OFFSET*6)+BEO))



struct _hw_uart {
    union _hw_data {
        struct _hw_rx_data {
            volatile unsigned int data : 8;
            unsigned int reserved : 24;
        } rx;
        struct _hw_tx_data {
            volatile unsigned int data : 8;
            unsigned int reserved : 24;
        } tx;
        volatile unsigned int Register;
    } data;
    union _hw_ie {
        struct __hw_ie {
            volatile unsigned int erbi : 1;  /*--- rx data avail ---*/
            volatile unsigned int etbei : 1;  /*--- transmitter holöding register empty ---*/
            volatile unsigned int elsi : 1;  /*--- line status interrupt ---*/
            volatile unsigned int eddsi : 1;  /*--- modem status interrupt ---*/
            volatile unsigned int reserved : 4;
        } Bits;
        volatile unsigned int Register;
    } ie;
    union _hw_iir_fcr {
        struct _hw_fcr {    /*--- write only ---*/
            volatile unsigned int fen : 1;  /*--- enable Fifo ---*/
            volatile unsigned int rxrst : 1;  /*--- reset rx ---*/
            volatile unsigned int txrst : 1; /*--- reset tx ---*/
            volatile unsigned int dmam : 1;  /*--- dma mode ---*/
            volatile unsigned int rxtrg : 2; /*--- rx trigger level for fifo ---*/
        } Bits_fcr;
        struct _hw_iir {    /*--- read only ---*/
            volatile unsigned int no_int : 1;  /*--- no interrupt pending ---*/
            volatile unsigned int int_id : 4;
            volatile unsigned int reserved : 2;
            volatile unsigned int fifo_en : 1;
        } Bits_iir;
        volatile unsigned int Register;
    } iir_fcr;
    union _hw_lc {
        struct __hw_lc {
            volatile unsigned int ws : 2;
            volatile unsigned int stb : 1;
            volatile unsigned int pen : 1;
            volatile unsigned int eps : 1;
            volatile unsigned int spb : 1;
            volatile unsigned int bcb : 1;
            volatile unsigned int dlab : 1;
        } Bits;
        volatile unsigned int Register;
    } lc;
    union _hw_mc {
        struct __hw_mc {
            volatile unsigned int dtr : 1;
            volatile unsigned int rts : 1;
            volatile unsigned int out1 : 1;
            volatile unsigned int out2 : 1;
            volatile unsigned int loop : 1;
            volatile unsigned int afe : 1;
            volatile unsigned int reserved : 2;
        } Bits;
        volatile unsigned int Register;
        volatile unsigned int data : 8;
        unsigned int reserved : 24;
    } mc;
/* LSR status */
#define SIO_LS_RX            0x01    /* Character ready             */
#define SIO_LS_OE            0x02    /* RX-ERROR: Overrun           */
#define SIO_LS_PE            0x04    /* RX-ERROR: Parity            */
#define SIO_LS_FE            0x08    /* RX-ERROR: Framing (stop bit)*/
#define SIO_LS_BI            0x10    /* 'BREAK' detected            */
#define SIO_LS_TE            0x20    /* Transmit Holding empty      */
#define SIO_LS_TI            0x40    /* Transmitter empty (IDLE)    */
#define SIO_LS_FIFOERR       0x80    /* RX-ERROR: FIFO              */
    union __hw_ls {
        struct _hw_ls {
            volatile unsigned int rx : 1;
            volatile unsigned int oe : 1;
            volatile unsigned int pe : 1;
            volatile unsigned int fe : 1;
            volatile unsigned int bi : 1;
            volatile unsigned int te : 1;
            volatile unsigned int ti : 1;
            volatile unsigned int fifierr : 1;
            volatile unsigned int reserved : 24;
        } Bits;
        volatile unsigned int Register;
    } ls;
/* MSR status */
#define SIO_MS_CTS           0x10    /* Clear to send               */
#define SIO_MS_DSR           0x20    /* Data Set Ready              */
#define SIO_MS_RI            0x40    /* Ring Indicator              */
#define SIO_MS_DCD           0x80    /* Data carrier detect         */
    union __hw_ms {
        struct _hw_ms {
            unsigned int reserved : 4;
            volatile unsigned int cts : 1;
            volatile unsigned int dsr : 1;
            volatile unsigned int ri : 1;
            volatile unsigned int dcd : 1;
            unsigned int reserved2 : 24;
        } Bits;
        volatile unsigned int Register;
    } ms;
};




#endif /*--- #ifndef _hw_uart_h_ ---*/
