/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#ifndef _hw_clock_h_
#define _hw_clock_h_


/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#if defined(CONFIG_MIPS_AR7)
#define CLK_PDCR 	(*(volatile unsigned *)(AVALANCHE_CLOCK_CONTROL_BASE + 0x00))
#define CLOCK_BASE                  AR7_CLOCK_BASE
#endif /*--- #if defined(CONFIG_MIPS_AR7) ---*/

#if defined(CONFIG_MIPS_OHIO)
#define CLK_PDCR 	(*(volatile unsigned *)(OHIO_CLOCK_BASE + 0x00))
#define CLOCK_BASE                  OHIO_CLOCK_BASE
#endif /*--- #if defined(CONFIG_MIPS_OHIO) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define PDCR_CMD_GIBPD(mode)                 ((mode) << 30)
#define PDCR_CMD_GIBPD_MODE_RUN		     0
#define PDCR_CMD_GIBPD_MODE_IDLE	     1
#define PDCR_CMD_GIBPD_MODE_STANDBY          2
#define PDCR_CMD_GIBPD_MODE_POWER_DOWN       3

/*--- bit 29-28 reserved ---*/
#define PDCR_BIT_VLYNQ0                27
/*--- bit 26-25 reserved ---*/
#define PDCR_BIT_EPHY                  24
/*--- bit 23 reserved ---*/
#define PDCR_BIT_EMAC1                 22
/*--- bit 21 reserved ---*/
#define PDCR_BIT_EMAC0                 20
#define PDCR_BIT_TIMER1                19
#define PDCR_BIT_TIMER0                18
/*--- bit 17 reserved ---*/
#define PDCR_BIT_BIST                  16
#define PDCR_BIT_DMA                   15
#define PDCR_BIT_ROM                   14
#define PDCR_BIT_RAM                   13
#define PDCR_BIT_ADSP                  12
/*--- bit 11 reserved ---*/
#define PDCR_BIT_EMIF                  10
#define PDCR_BIT_ADSL                   9
#define PDCR_BIT_SAR                    8
#define PDCR_BIT_VLYNQ1                 7
#define PDCR_BIT_GPIO                   6
#define PDCR_BIT_VDMA                   5
#define PDCR_BIT_IIC                    4
#define PDCR_BIT_UART1                  3
#define PDCR_BIT_UART0                  2
#define PDCR_BIT_WDT                    1
#define PDCR_BIT_USB                    0

/*--- bit 29-28 reserved ---*/
#define PDCR_MASK_VLYNQ0                (1 << 27)
/*--- bit 26-25 reserved ---*/
#define PDCR_MASK_EPHY                  (1 << 24)
/*--- bit 23 reserved ---*/
#define PDCR_MASK_EMAC1                 (1 << 22)
/*--- bit 21 reserved ---*/
#define PDCR_MASK_EMAC0                 (1 << 20)
#define PDCR_MASK_TIMER1                (1 << 19)
#define PDCR_MASK_TIMER0                (1 << 18)
/*--- bit 17 reserved ---*/
#define PDCR_MASK_BIST                  (1 << 16)
#define PDCR_MASK_DMA                   (1 << 15)
#define PDCR_MASK_ROM                   (1 << 14)
#define PDCR_MASK_RAM                   (1 << 13)
#define PDCR_MASK_ADSP                  (1 << 12)
/*--- bit 11 reserved ---*/
#define PDCR_MASK_EMIF                  (1 << 10)
#define PDCR_MASK_ADSL                  (1 <<  9)
#define PDCR_MASK_SAR                   (1 <<  8)
#define PDCR_MASK_VLYNQ1                (1 <<  7)
#define PDCR_MASK_GPIO                  (1 <<  6)
#define PDCR_MASK_VDMA                  (1 <<  5)
#define PDCR_MASK_IIC                   (1 <<  4)
#define PDCR_MASK_UART1                 (1 <<  3)
#define PDCR_MASK_UART0                 (1 <<  2)
#define PDCR_MASK_WDT                   (1 <<  1)
#define PDCR_MASK_USB                   (1 <<  0)

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_CLKCR 	(*(volatile unsigned *)(CLOCK_BASE+0x04))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_PDUCR 	(*(volatile unsigned *)(CLOCK_BASE+0x08))

#define PDUCR_BIT_EMIF                      30
#define PDUCR_BIT_JTAG                      29
#define PDUCR_BIT_MBSP0_TFS                 28
#define PDUCR_BIT_MBSP0_RFS                 27
#define PDUCR_BIT_MBSP0_TD                  26
#define PDUCR_BIT_MBSP0_RD                  25
#define PDUCR_BIT_MBSP0_RCLK                24
#define PDUCR_BIT_MBSP0_TCLK                23
#define PDUCR_BIT_EPHY_FDUPLEX              22
#define PDUCR_BIT_EPHY_ACTIVITY             21
#define PDUCR_BIT_EPHY_LINKON               20
#define PDUCR_BIT_EPHY_SPEED100             19
#define PDUCR_BIT_EINT1                     18
#define PDUCR_BIT_EINT0                     17
#define PDUCR_BIT_MII_DCLK                  16
#define PDUCR_BIT_MII_DIO                   15
#define PDUCR_BIT_RESERVED_14               14
#define PDUCR_BIT_EXT_AFE_CDOUT             13
#define PDUCR_BIT_EXT_AFE_CDIN              12
#define PDUCR_BIT_EXT_AFE_RXD0              11
#define PDUCR_BIT_EXT_AFE_RXD1              10
#define PDUCR_BIT_EXT_AFE_RX_FS              9
#define PDUCR_BIT_EXT_AFE_TXD                8
#define PDUCR_BIT_EXT_AFE_TX_FS              7
#define PDUCR_BIT_EXT_AFE_SCLK               6
#define PDUCR_BIT_FSER_CLK                   5
#define PDUCR_BIT_FSER_D                     4
#define PDUCR_BIT_UART0_RTS                  3
#define PDUCR_BIT_UART0_CTS                  2
#define PDUCR_BIT_UART0_TDx                  1
#define PDUCR_BIT_UART0_RDx                  0

#define PDUCR_MASK_EMIF                      (1 << 30)
#define PDUCR_MASK_JTAG                      (1 << 29)
#define PDUCR_MASK_MBSP0_TFS                 (1 << 28)
#define PDUCR_MASK_MBSP0_RFS                 (1 << 27)
#define PDUCR_MASK_MBSP0_TD                  (1 << 26)
#define PDUCR_MASK_MBSP0_RD                  (1 << 25)
#define PDUCR_MASK_MBSP0_RCLK                (1 << 24)
#define PDUCR_MASK_MBSP0_TCLK                (1 << 23)
#define PDUCR_MASK_EPHY_FDUPLEX              (1 << 22)
#define PDUCR_MASK_EPHY_ACTIVITY             (1 << 21)
#define PDUCR_MASK_EPHY_LINKON               (1 << 20)
#define PDUCR_MASK_EPHY_SPEED100             (1 << 19)
#define PDUCR_MASK_EINT1                     (1 << 18)
#define PDUCR_MASK_EINT0                     (1 << 17)
#define PDUCR_MASK_MII_DCLK                  (1 << 16)
#define PDUCR_MASK_MII_DIO                   (1 << 15)
#define PDUCR_MASK_RESERVED_14               (1 << 14)
#define PDUCR_MASK_EXT_AFE_CDOUT             (1 << 13)
#define PDUCR_MASK_EXT_AFE_CDIN              (1 << 12)
#define PDUCR_MASK_EXT_AFE_RXD0              (1 << 11)
#define PDUCR_MASK_EXT_AFE_RXD1              (1 << 10)
#define PDUCR_MASK_EXT_AFE_RX_FS             (1 <<  9)
#define PDUCR_MASK_EXT_AFE_TXD               (1 <<  8)
#define PDUCR_MASK_EXT_AFE_TX_FS             (1 <<  7)
#define PDUCR_MASK_EXT_AFE_SCLK              (1 <<  6)
#define PDUCR_MASK_FSER_CLK                  (1 <<  5)
#define PDUCR_MASK_FSER_D                    (1 <<  4)
#define PDUCR_MASK_UART0_RTS                 (1 <<  3)
#define PDUCR_MASK_UART0_CTS                 (1 <<  2)
#define PDUCR_MASK_UART0_TDx                 (1 <<  1)
#define PDUCR_MASK_UART0_RDx                 (1 <<  0)

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_WKCR 	(*(volatile unsigned *)(CLOCK_BASE+0x0C))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_SCLKCR_DIV  (*(volatile unsigned *)(CLOCK_BASE+0x20))
#define SCLKCR_DIV      CLK_SCLKCR_DIV      

#define CLK_PRE_CLK_DIV(factor)			(((factor) - 1) << 16)
#define CLK_POST_CLK_DIV(factor)		(((factor) - 1) <<  0)

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_SCLKCR_MUL  (*(volatile unsigned *)(CLOCK_BASE+0x30))
#define SCLKCR_MUL      CLK_SCLKCR_MUL 

#define CLK_CLKPLL_BIT_PLL_MUL(factor)		((factor) << 12)
#define CLK_CLKPLL_BIT_PLL_DIV			(1 << 11)
#define CLK_CLKPLL_BIT_PLL_COUNT(value)		((value) <<  3)
#define CLK_CLKPLL_BIT_EN_PLL			(1 <<  2)
#define CLK_CLKPLL_BIT_PLL_MODE			(1 <<  1)
#define CLK_CLKPLL_BIT_STATUS			(1 <<  0)

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_MCLKCR      (*(volatile unsigned *)(CLOCK_BASE+0x40))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_MCLKPLLCR   (*(volatile unsigned *)(CLOCK_BASE+0x50))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_UCLKCR      (*(volatile unsigned *)(CLOCK_BASE+0x60))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_UCLKPLLCR   (*(volatile unsigned *)(CLOCK_BASE+0x70))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_ADSL_CLK0_CR   (*(volatile unsigned *)(CLOCK_BASE+0x80))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_ADSL_CLKPLL0_CR   (*(volatile unsigned *)(CLOCK_BASE+0x90))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_ADSL_CLK1_CR   (*(volatile unsigned *)(CLOCK_BASE+0xA0))

/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#define CLK_ADSL_CLKPLL1_CR   (*(volatile unsigned *)(CLOCK_BASE+0xB0))
#define ADSL_CLKPLL_BIT_DIVM(Mode)		((Mode) << 4)
#define ADSL_CLKPLL_BIT_LOCK_TIME(LockTime)	((LockTime << 8)
#define ADSL_CLKPLL_BIT_STATUS			(1 << 16)


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

#if defined(CONFIG_MIPS_OHIO)
union _ohio_clock_pll_div {
    struct __ohio_clock_pll_div {
        unsigned int ratio : 5;
        unsigned int reserved1  : 10;
        unsigned int diven : 1;
        unsigned int reserved2  : 15;
    } Bits;
    volatile unsigned int Register;
};

struct _ohio_clock_pll {
    union _ohio_clock_pll_ctrl {   /*--- offset: 0x80, 0x100, 0x180 ---*/
        struct __ohio_clock_pll_ctrl {
            unsigned int pllen: 1;
            unsigned int pllpwdn: 1;
            unsigned int reserved1 : 3;
            unsigned int lock : 1;
            unsigned int stable : 1;
            unsigned int reserved2 : (8 + 15);
        } Bits;
        volatile unsigned int Register;
    } PLL_ctrl;
    unsigned int reserved0[(0x10 - 0x04)/sizeof(unsigned int)];
    union _ohio_clock_pll_mult {    /*--- offset: 0x90, 0x110, 0x190 ---*/
        struct __ohio_clock_pll_mult {
            unsigned int pllm : 4;
            unsigned int rsv : 1;
            unsigned int reserved1 : (15 + 11);
        } Bits;
        volatile unsigned int Register;
    } PLL_mult;
    union _ohio_clock_pll_div PLL_pre_div;    /*--- offset: 0x94, 0x114, 0x194 ---*/
    union _ohio_clock_pll_div PLL_post_div;   /*--- offset: 0x98, 0x118, 0x198 ---*/
    union _ohio_clock_pll_div PLL_post_div2;  /* only available on SYSTEM_PLL, offset: 0x11C */
    unsigned int reserved1[(0x38 - 0x20)/sizeof(unsigned int)];
    union _ohio_clock_pll_cmd { /*--- offset: 0xB8, 0x138, 0x1B8 ---*/
        struct __ohio_clock_pll_cmd {
            unsigned int goset : 1;
            unsigned int reserved1 : 31;
        } Bits;
        volatile unsigned int Register;
    } PLL_cmd;
    union _ohio_clock_pll_stat {  /*--- offset: 0xBC, 0x13C, 0x1BC ---*/
        struct __ohio_clock_pll_stat {
            unsigned int gostat : 1;
            unsigned int reserved1 : 31;
        } Bits;
        volatile unsigned int Register;
    } PLL_stat;
    union _ohio_clock_pll_cmd_en {  /*--- offset: 0xC0, 0x140, 0x1C0 ---*/
        struct __ohio_clock_pll_cmd_en {
            unsigned int goset : 2;     /*--- 2 bit nur bei System-PLL ---*/
            unsigned int reserved1 : 30;
        } Bits;
        volatile unsigned int Register;
    } PLL_cmd_en;
    unsigned int reserved2[(0x100 - 0xC4)/sizeof(unsigned int)];
};
#endif /*--- #if defined(CONFIG_MIPS_OHIO) ---*/

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _hw_clock {
    union __clock_PDCR {
        struct _clock_PDCR {
            unsigned int usbp      : 1;  /*  0 */
            unsigned int wdtp      : 1;  /*  1 */
            unsigned int ut0p      : 1;  /*  2 */
            unsigned int ut1p      : 1;  /*  3 */
            unsigned int iicp      : 1;  /*  4 */
            unsigned int vdmap     : 1;  /*  5 */
            unsigned int gpiop     : 1;  /*  6 */
            unsigned int vlynq1p   : 1;  /*  7 */
            unsigned int sarp      : 1;  /*  8 */
            unsigned int adslp     : 1;  /*  9 */
            unsigned int emifp     : 1;  /* 10 */
            unsigned int reserved0 : 1;  /* 11 */
            unsigned int adspp     : 1;  /* 12 */
            unsigned int ramp      : 1;  /* 13 */
            unsigned int romp      : 1;  /* 14 */
            unsigned int dmap      : 1;  /* 15 */
            unsigned int bistp     : 1;  /* 16 */
            unsigned int reserved1 : 1;  /* 17 */
            unsigned int timer0p   : 1;  /* 18 */
            unsigned int timer1p   : 1;  /* 19 */
            unsigned int emac0p    : 1;  /* 20 */
            unsigned int reserved2 : 1;  /* 21 */
            unsigned int emac1p    : 1;  /* 22 */
            unsigned int reserved3 : 1;  /* 23 */
            unsigned int ephyp     : 1;  /* 24 */
            unsigned int reserved4 : 2;  /* 25 */
            unsigned int vlynq0p   : 1;  /* 27 */
            unsigned int reserved5 : 2;  /* 28 */
            unsigned int glbpd     : 2;  /* 30 */
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
#if defined(CONFIG_MIPS_OHIO)
    const unsigned int PCPID; /*--- PLL Controller ID Register ---*/
    unsigned int reserved1[(0x80 - 0x14)/sizeof(unsigned int)];
    struct _ohio_clock_pll MIPS_PLL;
    struct _ohio_clock_pll SYSTEM_PLL;
    struct _ohio_clock_pll USB_PLL;
#endif /*--- #if defined(CONFIG_MIPS_OHIO) ---*/
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
