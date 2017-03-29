/*--------------------------------------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------------------------------------*/
#ifndef _hw_reset_h_
#define _hw_reset_h_

/*--------------------------------------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------------------------------------*/
#define RESET_PRCR      (*(volatile unsigned *)(RESET_BASE+0x0))

/* Reset Control bits */
#define UART0_RESET_BIT		      0
#define UART1_RESET_BIT		      1
#define IIC_RESET_BIT  		      2
#define TIMER0_RESET_BIT  	      3
#define TIMER1_RESET_BIT  	      4
#define RESERVED5_RESET_BIT       5
#define GPIO_RESET_BIT 		      6
#define ADSLSS_RESET_BIT  		  7
#define USB_RESET_BIT  		      8
#define SAR_RESET_BIT  		      9
#define RESERVED10_RESET_BIT  	 10
#define VDMAVT_RESET_BIT  		 11
#define FSER_RESET_BIT  		 12
#define RESERVED13_RESET_BIT  	 13
#define RESERVED14_RESET_BIT  	 14
#define RESERVED15_RESET_BIT 	 15
#define VLYNQ1_RESET_BIT  		 16
#define EMACA_RESET_BIT 	     17
#define DMA_RESET_BIT            18
#define BIST_RESET_BIT           19
#define VLYNQ0_RESET_BIT         20
#define EMACB_RESET_BIT      	 21
#define MDIO_RESET_BIT	    	 22
#define ADSLSS_DSP_RESET_BIT     23
#define RESERVED24_RESET_BIT     24
#define RESERVED25_RESET_BIT     25
#define EMAC_PHY_RESET_BIT  	 26

union _hw_non_reset {
    volatile unsigned int Reg;
    struct __hw_non_reset {
        unsigned int uart0_unreset	    : 1;
        unsigned int uart1_unreset	    : 1;
        unsigned int iic_unreset  	    : 1;
        unsigned int timer0_unreset  	: 1;
        unsigned int timer1_unreset     : 1;
        unsigned int reserved5_unreset  : 1;
        unsigned int gpio_unreset 	    : 1;
        unsigned int adslss_unreset     : 1;
        unsigned int usb_unreset  	    : 1;
        unsigned int sar_unreset  	    : 1;
        unsigned int reserved10_unreset : 1;
        unsigned int vdmavt_unreset     : 1;
        unsigned int fser_unreset  	    : 1;
        unsigned int reserved13_unreset : 1;
        unsigned int reserved14_unreset : 1;
        unsigned int reserved15_unreset : 1;
        unsigned int vlynq1_unreset     : 1;
        unsigned int emaca_unreset 	    : 1;
        unsigned int dma_unreset        : 1;
        unsigned int bist_unreset       : 1;
        unsigned int vlynq0_unreset     : 1;
        unsigned int emacb_unreset      : 1;
        unsigned int mdio_unreset	    : 1;
        unsigned int adslss_dsp_unreset : 1;
        unsigned int reserved24_unreset : 1;
        unsigned int reserved25_unreset : 1;
        unsigned int emac_phy_unreset   : 1;
        unsigned int reserved1          : 5;
    } Bits;
};
/*--- extern union _hw_non_reset * const RESET; ---*/

struct _hw_reset {
    union _hw_non_reset non_reset;
    union _hw_reset_ctrl {
        struct __hw_reset_ctrl {
            unsigned int swr0 : 1;
            unsigned int swr1 : 1;
            unsigned int reserved : 30;
        } Bits;
        volatile unsigned int Register;
    } reset_ctrl;
    union _hw_reset_status {
        struct __hw_reset_status {
            unsigned int cause : 2;
            unsigned int reserved : 30;
        } Bits;
        volatile unsigned int Register;
    } reset_status;
};


/*--------------------------------------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------------------------------------*/
#define RESET_SWRCR     (*(volatile unsigned *)(RESET_BASE+0x4))

/*--------------------------------------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------------------------------------*/
#define RESET_RSR       (*(volatile unsigned *)(RESET_BASE+0x8))


#endif /*--- #ifndef _hw_reset_h_ ---*/
