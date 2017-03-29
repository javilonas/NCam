/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _hw_boot_h_
#define _hw_boot_h_


union _hw_c55_irqmask {
    struct __hw_c55_irqmask {
        unsigned int srtr_rx_intr : 8;
        unsigned int srtr_tx_intr : 4;
        unsigned int tdm_rx_dma_intr : 1;
        unsigned int tdm_tx_dma_intr : 1;
        unsigned int tdm_tx_mcsp_intr : 1;
        unsigned int tdm_rx_mcsp_intr : 1;
        unsigned int sw_intr : 7;
    } Bits;
    volatile unsigned int Register;
};

union _hw_vbus_prio {
    struct __hw_vbus_prio {
        unsigned int prio_level : 3;
        unsigned int reserved1 : 13;
        unsigned int prio_escalation_count : 8;
        unsigned int lowest_priority_value_achieveable : 3;
        unsigned int reserved2 : 4;
        unsigned int enable : 1;
    } Bits;
    volatile unsigned int Register;
};

struct _hw_boot {
    union _hw_boot_config {
        struct __hw_boot_config {
            unsigned int boots : 3;
            unsigned int reserved1 : 1;
            unsigned int wdhe : 1;
            unsigned int reserved2 : 1;
            unsigned int endian : 1;
            unsigned int flashw : 2;
            unsigned int emifrate : 1;
            unsigned int emiftest : 1;
            unsigned int boots_int : 3; /* 11:13 */
            unsigned int vlynq_clk_dir : 1;
            unsigned int reserved3 : 9; /* 15:23 */
            unsigned int clk_ratio : 2;
            unsigned int mips_async : 1; /* 26 */
            unsigned int def : 1; /* 27 */
            unsigned int adsl_rst : 1; /* 28 */
            unsigned int reserved5 : 5; /* 27:31 */
        } Bits;
        volatile unsigned int Register;
    } hw_boot_config;

    unsigned int reserved1; /* offset: 0x04 */

    /* offset: 0x08  Power Down Register 1 */
    volatile unsigned int pdctrl;

    /* offset: 0x0C  Debug Clock Output Register */
    volatile unsigned int debugclkout;

    /* offset: 0x10  DSLSS PM2EMIF Offset Register */
    volatile unsigned int pm2emif;

    /* offset: 0x14  DSLSS DM2EMIF Offset Register */
    volatile unsigned int dm2emif;

    /* offset: 0x18  MII Select Register */
    volatile unsigned int mmi1selreg;

    /* offset: 0x1C  TDM Select Register */
    volatile unsigned int tdmselreg;

    /* offset: 0x20  C55 Test Output */
    volatile unsigned int c55testout;

    /* offset: 0x24  reserved */
    unsigned int reserved2; 

    /* offset: 0x28  C55 Retiming Register */
    volatile unsigned int c55_retiming;

    /* offset: 0x2C  C55 Interrupt Set Register */
    union _hw_c55_irqmask c55_irq_set;

    /* offset: 0x30  C55 Interrupt Clear Register */
    union _hw_c55_irqmask c55_irq_clear;

    /* offset: 0x34  C55 NMI Interrupt Register */
    volatile unsigned int c55_nmi;

    /* offset: 0x38  CPPI DMA Priority Register */
    union _hw_vbus_prio CPPI_Prio;

    /* offset: 0x3C  SAR PDSP Priority Register */
    union _hw_vbus_prio SAR_Prio;

    /* offset: 0x40  Buffer/Queue Manager Priority Register */
    union _hw_vbus_prio BufferManager_Prio;

    /* offset: 0x44  USB Priority Register */
    union _hw_vbus_prio USB_Prio;

    /* offset: 0x48  VLYNQ Priority Register */
    union _hw_vbus_prio VLYNQ_Prio;

    /* offset: 0x4C  PCI Priority Register */
    union _hw_vbus_prio PCI_Prio;

    /* offset: 0x50  C55 Priority Register */
    union _hw_vbus_prio C55_Prio;

    /* offset: 0x54  SBRM Priority Register */
    union _hw_vbus_prio SBRM_Prio;

    /* offset: 0x58  MIPS Priority Register */
    union _hw_vbus_prio MIPS_Prio;

    /* offset: 0x5C  MIPS2PERIPH Offset Register */
    volatile unsigned int mips2periph ;

    /* offset: 0x60  MIPS2DMEM Offset Register */
    volatile unsigned int mips2dmem ;

    /* offset: 0x64  Pullup/Pulldown Control Register */
    volatile unsigned int PullDown;

    /* offset: 0x68  Reserved */
    unsigned int reserved3; 

    /* offset: 0x6C  USB Data polarty control */
    volatile unsigned int USB_Data_polarty_control;

    /* offset: 0x70  USB PHY power down */
    volatile unsigned int USB_PHY_power_down;

    /* offset: 0x74  USB PWRCLKGOOD */
    volatile unsigned int USB_PWRCLKGOOD ;

    /* offset: 0x78  USB TM1 */
    volatile unsigned int USB_TM1;

    /* offset: 0x7C  USB DRVVBUS Polarity control */
    volatile unsigned int USB_DRVVBUS ;
};




#endif /*--- #ifndef _hw_boot_h_ ---*/
