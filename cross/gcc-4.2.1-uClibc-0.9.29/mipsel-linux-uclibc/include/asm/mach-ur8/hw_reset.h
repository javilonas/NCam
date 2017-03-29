/*--------------------------------------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------------------------------------*/
#ifndef _hw_reset_h_
#define _hw_reset_h_

/*--------------------------------------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------------------------------------*/
#define RESET_PRCR      (*(volatile unsigned *)(RESET_BASE+0x0))

/* Reset Control bits */
#define UART0_RESET_BIT         0
#define UART1_RESET_BIT         1
#define SPI_RESET_BIT           2
#define TIMER0_RESET_BIT        3
#define TIMER1_RESET_BIT        4
#define RESERVED5_RESET_BIT     5
#define GPIO_RESET_BIT          6
#define ADSLSS_RESET_BIT        7
#define USB_RESET_BIT           8
#define NWSS_RESET_BIT          9
#define TDM_RESET_BIT           10
#define RESERVED11_RESET_BIT    11
#define RESERVED12_RESET_BIT    12
#define RESERVED13_RESET_BIT    13
#define RESERVED14_RESET_BIT    14
#define VLYNQ0_RESET_BIT        15
#define PCI_RESET_BIT           16
#define RESERVED17_RESET_BIT    17
#define UART_DMA_RESET_BIT      18
#define RESERVED19_RESET_BIT    19
#define C55X_RESET_BIT          20
#define RESERVED21_RESET_BIT    21
#define MDIO_RESET_BIT          22
#define ADSLSS_DSP_RESET_BIT    23
#define RESERVED24_RESET_BIT    24
#define RESERVED25_RESET_BIT    25
#define USB_PHY_RESET_BIT       26
#define RESERVED27_BIT          27
#define RESERVED28_BIT          28
#define MCSP_RESET_BIT          29
#define PCI_RESET_OUT_BIT       30
#define PCI_OUTPUT_EN_BIT       31

#define UART0_RESET_MASK         (1 <<  0)
#define UART1_RESET_MASK		 (1 <<  1)
#define SPI_RESET_MASK  		 (1 <<  2)
#define TIMER0_RESET_MASK  	     (1 <<  3)
#define TIMER1_RESET_MASK  	     (1 <<  4)
#define RESERVED5_RESET_MASK     (1 <<  5)
#define GPIO_RESET_MASK 		 (1 <<  6)
#define ADSLSS_RESET_MASK  		 (1 <<  7)
#define USB_RESET_MASK  		 (1 <<  8)
#define NWSS_RESET_MASK  	     (1 <<  9)
#define TDM_RESET_MASK  	     (1 << 10)
#define RESERVED11_RESET_MASK  	 (1 << 11)
#define RESERVED12_RESET_MASK  	 (1 << 12)
#define RESERVED13_RESET_MASK  	 (1 << 13)
#define RESERVED14_RESET_MASK  	 (1 << 14)
#define VLYNQ_RESET_MASK 	     (1 << 15)
#define PCI_RESET_MASK  		 (1 << 16)
#define RESERVED17_RESET_MASK    (1 << 17)
#define UART_DMA_RESET_MASK      (1 << 18)
#define RESERVED19_RESET_MASK    (1 << 19)
#define C55X_RESET_MASK          (1 << 20)
#define RESERVED21_RESET_MASK  	 (1 << 21)
#define MDIO_RESET_MASK	    	 (1 << 22)
#define ADSLSS_DSP_RESET_MASK    (1 << 23)
#define RESERVED24_RESET_MASK    (1 << 24)
#define RESERVED25_RESET_MASK    (1 << 25)
#define USB_PHY_RESET_MASK       (1 << 26)
#define RESERVED27_MASK          (1 << 27)
#define RESERVED28_MASK          (1 << 28)
#define MCSP_RESET_MASK          (1 << 29)
#define PCI_RESET_OUT_MASK       (1 << 30)
#define PCI_OUTPUT_EN_MASK       (1 << 31)

/*--------------------------------------------------------------------------------*\
 * Capiterm: SmartCalc
PRCR_unresetPCIoutbuf=S:31,31
PRCR_unresetPCIout=S:30,30
PRCR_unresetMCSP=S:29,29
PRCR_unresetUSBPHY=S:26,26
PRCR_unresetDSLSS=S:23,23
PRCR_unresetMDIO=S:22,22
PRCR_unresetc55x=S:20,20
PRCR_unresetUARTDMA=S:18,18
PRCR_unresetPCI=S:16,16
PRCR_unresetVLYNQ=S:15,15
PRCR_unresetTDM=S:10,10
PRCR_unresetNet=S:9,9
PRCR_unresetUSBC=S:8,8
PRCR_unresetDSLSSC=S:7,7
PRCR_unresetGPIO=S:6,6
PRCR_unresetTimer1=S:4,4
PRCR_unresetTimer0=S:3,3
PRCR_unresetSPI=S:2,2
PRCR_unresetUartB=S:1,1
PRCR_unresetUartA=S:0,0
\*--------------------------------------------------------------------------------*/
union _hw_non_reset {
    volatile unsigned int Reg;
#if defined(CONFIG_MIPS_AR7)
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
#else
    struct __hw_non_reset {
        unsigned int uart0_unreset	    : 1;
        unsigned int uart1_unreset	    : 1;
        unsigned int spi_unreset  	    : 1;
        unsigned int timer0_unreset  	: 1;
        unsigned int timer1_unreset     : 1;
        unsigned int reserved5_unreset  : 1;
        unsigned int gpio_unreset 	    : 1;
        unsigned int adslss_unreset     : 1;
        unsigned int usb_unreset  	    : 1;
        unsigned int nwss_unreset  	    : 1;
        unsigned int tdm_unreset        : 1;
        unsigned int reserved11_unreset : 1;
        unsigned int reserved12_unreset : 1;
        unsigned int reserved13_unreset : 1;
        unsigned int reserved14_unreset : 1;
        unsigned int vlynq0_unreset     : 1;
        unsigned int pci_unreset        : 1;
        unsigned int reserved17_unreset : 1;
        unsigned int uart_dma_unreset   : 1;
        unsigned int reserved19_unreset : 1;
        unsigned int c55x_unreset       : 1;
        unsigned int reserved21_unreset : 1;
        unsigned int mdio_unreset	    : 1;
        unsigned int adslss_dsp_unreset : 1;
        unsigned int reserved24_unreset : 1;
        unsigned int reserved25_unreset : 1;
        unsigned int usb_phy_unreset    : 1;
        unsigned int reserved27_unreset : 1;
        unsigned int reserved28_unreset : 1;
        unsigned int mcsp_unreset       : 1;
        unsigned int pci_reset_out      : 1;
        unsigned int pci_output_en      : 1;
    } Bits;
#endif
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
