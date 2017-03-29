/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#ifndef _hw_clock_h_
#define _hw_clock_h_


/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_PDCR 	(*(volatile unsigned *)(UR8_CLOCK_BASE + 0x00))

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define PDCR_BIT_GIBPD(mode)                ((mode) << 0)
#define PDCR_BIT_GIBPD_MODE_RUN		        0
#define PDCR_BIT_GIBPD_MODE_IDLE	        1
#define PDCR_BIT_GIBPD_MODE_STANDBY         2
#define PDCR_BIT_GIBPD_MODE_POWER_DOWN      3

#define PDCR_BIT_PBIST          23
#define PDCR_BIT_FILTER         22
#define PDCR_BIT_DMA            21
#define PDCR_BIT_DSLSS          20
#define PDCR_BIT_TDM            19
#define PDCR_BIT_EMIF           18
#define PDCR_BIT_PCI            17
#define PDCR_BIT_VLYNQ          16
#define PDCR_BIT_BIST           15
#define PDCR_BIT_USB            14
#define PDCR_BIT_UART           13
#define PDCR_BIT_MCBSP          12
#define PDCR_BIT_NWSS           11
#define PDCR_BIT_GPIO           10
#define PDCR_BIT_WDT            9
#define PDCR_BIT_TIMER0         8
#define PDCR_BIT_TIMER1         7
#define PDCR_BIT_RAM            6
#define PDCR_BIT_C55XX          5
#define PDCR_BIT_SPI            4
#define PDCR_BIT_MDIO           3
#define PDCR_BIT_ROM            2

#define PDCR_MASK_PBIST          (1 << 23)
#define PDCR_MASK_FILTER         (1 << 22)
#define PDCR_MASK_DMA            (1 << 21)
#define PDCR_MASK_DSLSS          (1 << 20)
#define PDCR_MASK_TDM            (1 << 19)
#define PDCR_MASK_EMIF           (1 << 18)
#define PDCR_MASK_PCI            (1 << 17)
#define PDCR_MASK_VLYNQ          (1 << 16)
#define PDCR_MASK_BIST           (1 << 15)
#define PDCR_MASK_USB            (1 << 14)
#define PDCR_MASK_UART           (1 << 13)
#define PDCR_MASK_MCBSP          (1 << 12)
#define PDCR_MASK_NWSS           (1 << 11)
#define PDCR_MASK_GPIO           (1 << 10)
#define PDCR_MASK_WDT            (1 << 9)
#define PDCR_MASK_TIMER0         (1 << 8)
#define PDCR_MASK_TIMER1         (1 << 7)
#define PDCR_MASK_RAM            (1 << 6)
#define PDCR_MASK_C55XX          (1 << 5)
#define PDCR_MASK_SPI            (1 << 4)
#define PDCR_MASK_MDIO           (1 << 3)
#define PDCR_MASK_ROM            (1 << 2)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#if defined(CONFIG_MIPS_AR7)
union __clock_PLLCR {
    struct _clock_PLLCR {
        unsigned int status   : 1;
        unsigned int pllndiv  : 1;
        unsigned int plonoff  : 1;
        unsigned int plcount  : 8;
        unsigned int pldiv    : 1;
        unsigned int pllmul   : 4;
        unsigned int reserved : 16;
    } Bits;
    volatile unsigned int Register;
};

union __clock_CR1 {
    struct _clock_CR1 {
        unsigned int postclkdiv : 5;
        unsigned int reserved0  : 11;
        unsigned int preclkdiv  : 5;
        unsigned int reserved1  : 11;
    } Bits;
    volatile unsigned int Register;
};
#endif /*--- #if defined(CONFIG_MIPS_AR7) ---*/

#if defined(CONFIG_MIPS_UR8)
union _ur8_clock_cfg {
    struct __ur8_clock_cfg {
        unsigned int vlynq_mux_sel : 1;
        unsigned int pci_mux_sel : 1;
        unsigned int pci_div_sel : 5;
        unsigned int pci_clk_dir : 1;
        unsigned int ephy_div_sel : 5;
        unsigned int vlynq_div_sel : 3;
        unsigned int freeze_div_by : 1;
        unsigned int reserved0 : 1;
        unsigned int c55ss_div_sel : 5;
        unsigned int sys_asyc_clk_sel : 1;
        unsigned int clk_debug_out : 5;
        unsigned int reserved1 : 3;
    } Bits;
    volatile unsigned int Register;
};

struct _ur8_clock_pll {   
    union _ur8_clock_pll_ctrl {
        struct __ur8_clock_pll_ctrl {
            unsigned int mult: 5;
            unsigned int prediv: 3;
            unsigned int test_lock : 1;
            unsigned int unreset : 1;
            unsigned int nobypass : 1;
            unsigned int pwr_dwn : 1;
            unsigned int pll_disable : 1;
            unsigned int amux_sel : 2;
            unsigned int c2_sel : 3;
            unsigned int auto_detect_lock : 1;
            unsigned int ext_bypass : 1;
            unsigned int bg_sel : 1;
            unsigned int half_enable : 1;
            unsigned int reserved2 : 10;
        } Bits;
        volatile unsigned int Register;
    } PLL_ctrl;
};
#endif /*--- #if defined(CONFIG_MIPS_UR8) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _hw_clock {
    union __clock_PDCR {
        struct _clock_PDCR {
            unsigned int modep       : 2;
            unsigned int romp        : 1;
            unsigned int mdiop       : 1;
            unsigned int spip        : 1;
            unsigned int c55xxp      : 1;
            unsigned int ramp        : 1;
            unsigned int timer1p     : 1;
            unsigned int timer0p     : 1;
            unsigned int wdtp        : 1;
            unsigned int gpiop       : 1;
            unsigned int nwssp       : 1;
            unsigned int mcbspp      : 1;
            unsigned int uartp       : 1;
            unsigned int usbp        : 1;
            unsigned int bistp       : 1;
            unsigned int vlynqp      : 1;
            unsigned int pcip        : 1;
            unsigned int emifp       : 1;
            unsigned int tdmp        : 1;
            unsigned int dslssp      : 1;
            unsigned int dmap        : 1;
            unsigned int filterp     : 1;
            unsigned int pbistp      : 1;
            unsigned int reserved   : 8;
        } Bits;
        volatile unsigned int Register;
    } PDCR;
    unsigned int reserved0[(0x08 - 0x04)/sizeof(unsigned int)];
    union __clock_PDUCR {
        struct _clock_PDUCR {
            unsigned int uart0_rd      : 1;
            unsigned int uart0_td      : 1;
            unsigned int uart0_cts     : 1;
            unsigned int uart0_rts     : 1;
            unsigned int fser_d        : 1;
            unsigned int fser_clk      : 1;
            unsigned int ext_afe_sclk  : 1;
            unsigned int ext_afe_tx_fs : 1;
            unsigned int ext_afe_txd   : 1;
            unsigned int ext_afe_rx_fs : 1;
            unsigned int ext_afe_rxd1  : 1;
            unsigned int ext_afe_rxd0  : 1;
            unsigned int ext_afe_cdin  : 1;
            unsigned int ext_afe_cdout : 1;
            unsigned int reserved      : 1;
            unsigned int mii_dio       : 1;
            unsigned int mii_dclk      : 1;
            unsigned int eint0         : 1;
            unsigned int eint1         : 1;
            unsigned int ephy_speed100 : 1;
            unsigned int ephy_linkon   : 1;
            unsigned int ephy_activity : 1;
            unsigned int ephy_fduplex  : 1;
            unsigned int mcbsp0_tclk   : 1;
            unsigned int mcbsp0_rclk   : 1;
            unsigned int mcbsp0_rd     : 1;
            unsigned int mcbsp0_td     : 1;
            unsigned int mcbsp0_rfs    : 1;
            unsigned int mcbsp0_tfs    : 1;
            unsigned int jtag          : 1;
            unsigned int emif          : 1;
            unsigned int test          : 1;
        } Bits;
        volatile unsigned int Register;
    } PDUCR;
    union __clock_WKCR {
        struct _clock_WKCR {
            unsigned int wake_en   : 4;
            unsigned int reserved0 : 12;
            unsigned int wake_pol  : 4;
            unsigned int reserved1 : 12;
        } Bits;
        volatile unsigned int Register;
    } WKCR;
#if defined(CONFIG_MIPS_UR8)
    const unsigned int PCPID; /*--- PLL Controller ID Register ---*/
    unsigned int reserved1[(0x40 - 0x14)/sizeof(unsigned int)];
    union _ur8_clock_cfg  CLOCK_CFG;
    unsigned int reserved2[(0xA0 - 0x44)/sizeof(unsigned int)];
    struct _ur8_clock_pll  PLL2;
    unsigned int reserved3[(0xC0 - 0xA4)/sizeof(unsigned int)];
    struct _ur8_clock_pll  PLL1;
    unsigned int reserved4[(0xE0 - 0xC4)/sizeof(unsigned int)];
    struct _ur8_clock_pll  PLL3;
#endif /*--- #if defined(CONFIG_MIPS_UR8) ---*/
#if defined(CONFIG_MIPS_AR7)
    unsigned int reserved1[(0x20 - 0x10)/sizeof(unsigned int)];
    union __clock_CR SCLKCR;
    unsigned int reserved2[(0x30 - 0x24)/sizeof(unsigned int)];
    union __clock_PLLCR SCLKPLLCR;
    unsigned int reserved3[(0x40 - 0x34)/sizeof(unsigned int)];
    union __clock_CR MCLKCR;
    unsigned int reserved4[(0x50 - 0x44)/sizeof(unsigned int)];
    union __clock_PLLCR MCLKPLLCR;
    unsigned int reserved5[(0x60 - 0x54)/sizeof(unsigned int)];
    union __clock_CR UCLKCR;
    unsigned int reserved6[(0x70 - 0x64)/sizeof(unsigned int)];
    union __clock_PLLCR UCLKPLLCR;
    unsigned int reserved7[(0x80 - 0x74)/sizeof(unsigned int)];
    union __clock_CR0 ACLKCR0;
    unsigned int reserved8[(0x90 - 0x84)/sizeof(unsigned int)];
    union __clock_ACLKPLLCR0 ACLKPLLCR0;
    unsigned int reserved9[(0xA0 - 0x94)/sizeof(unsigned int)];
    union __clock_CR1 ACLKCR1;
    unsigned int reserved10[(0xB0 - 0xA4)/sizeof(unsigned int)];
    union __clock_ACLKPLLCR1 {
        struct _clock_ACLKPLLCR1 {
            unsigned int reserved0 : 4;
            unsigned int divm      : 2;
            unsigned int reserved1 : 2;
            unsigned int locktime  : 8;
            unsigned int status    : 1;
            unsigned int reserved2 : 15;
        } Bits;
        volatile unsigned int Register;
    } ACLKPLLCR1;
#endif /*--- #if defined(CONFIG_MIPS_AR7) ---*/
};
    
#endif /*--- #ifndef _hw_clock_h_ ---*/
