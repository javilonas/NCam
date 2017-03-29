/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#ifndef _hw_gpio_h_
#define _hw_gpio_h_

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
/* GPIO registers */
#define GPIO_R_IN           (*(volatile unsigned int *)(UR8_GPIO_BASE+0x0))
#define GPIO_R_OUT   		(*(volatile unsigned int *)(UR8_GPIO_BASE+0x4))
#define GPIO_R_DIR   		(*(volatile unsigned int *)(UR8_GPIO_BASE+0x8))     /* 0=o/p, 1=i/p */
#define GPIO_R_EN    		(*(volatile unsigned int *)(UR8_GPIO_BASE+0xc))     /* 0=GPIO Mux 1=GPIO */
#define GPIO_VERSION        (*(volatile unsigned int *)(UR8_GPIO_BASE+0x14))

#define UR8_CVR (*(volatile unsigned int *)(UR8_GPIO_BASE+0x14)) /* see _chip_version */

#define GPIO_BIT_MII2RD1            11
#define GPIO_BIT_MII2RD0            10
#define GPIO_BIT_MII2TD1             9
#define GPIO_BIT_MII2TD0             8
#define GPIO_BIT_PREQ2               7
#define GPIO_BIT_PREQ1               6
#define GPIO_BIT_EINT                5
#define GPIO_BIT_MII2RER             4
#define GPIO_BIT_MII2RDV             3
#define GPIO_BIT_MII2CRS             2
#define GPIO_BIT_MII2COL             1
#define GPIO_BIT_MII2TCLK            0

#define GPIO_BIT_MII2RCLK           31
#define GPIO_BIT_MII2RD3            30
#define GPIO_BIT_MII2RD2            29
#define GPIO_BIT_VLRXD1             28
#define GPIO_BIT_VLRXD0             27
#define GPIO_BIT_PINTB  		    26
#define GPIO_BIT_PGNT2            	25
#define GPIO_BIT_PGNT1            	24
#define GPIO_BIT_CE3               	23
#define GPIO_BIT_MII2TEN           	22
#define GPIO_BIT_MII2TD3         	21
#define GPIO_BIT_MII2TD2         	20
#define GPIO_BIT_UARTB_RD          	19
#define GPIO_BIT_UARTB_TD          	18
#define GPIO_BIT_UARTA_CTS         	17
#define GPIO_BIT_UARTA_TD         	16
#define GPIO_BIT_UARTA_RD       	15
#define GPIO_BIT_SPI_RX           	14
#define GPIO_BIT_SPI_TX           	13
#define GPIO_BIT_SPI_CLK           	12
#define GPIO_BIT_SPI_S1            	11
#define GPIO_BIT_SPI_S0            	10
#define GPIO_BIT_UARTA_RTS        	 9
#define GPIO_BIT_UARTC_RD            8
#define GPIO_BIT_UARTC_TD         	 7
#define GPIO_BIT_TDMTD             	 6
#define GPIO_BIT_TDMFS           	 5
#define GPIO_BIT_TDMCLK            	 4
#define GPIO_BIT_TDMRD            	 3
#define GPIO_BIT_JEMU1            	 2
#define GPIO_BIT_PINTC             	 1
#define GPIO_BIT_DRVVBUS           	 0

#define GPIO_MASK_MII2RD1            (1 << 11)
#define GPIO_MASK_MII2RD0            (1 << 10)
#define GPIO_MASK_MII2TD1            (1 <<  9)
#define GPIO_MASK_MII2TD0            (1 <<  8)
#define GPIO_MASK_PREQ2              (1 <<  7)
#define GPIO_MASK_PREQ1              (1 <<  6)
#define GPIO_MASK_EINT               (1 <<  5)
#define GPIO_MASK_MII2RER            (1 <<  4)
#define GPIO_MASK_MII2RDV            (1 <<  3)
#define GPIO_MASK_MII2CRS            (1 <<  2)
#define GPIO_MASK_MII2COL            (1 <<  1)
#define GPIO_MASK_MII2TCLK           (1 <<  0)

#define GPIO_MASK_MII2RCLK           (1 << 31)
#define GPIO_MASK_MII2RD3            (1 << 30)
#define GPIO_MASK_MII2RD2            (1 << 29)
#define GPIO_MASK_VLRXD1             (1 << 28)
#define GPIO_MASK_VLRXD0             (1 << 27)
#define GPIO_MASK_PINTB  		    (1 << 26)
#define GPIO_MASK_PGNT2            	(1 << 25)
#define GPIO_MASK_PGNT1            	(1 << 24)
#define GPIO_MASK_CE3               (1 << 23)
#define GPIO_MASK_MII2TEN           (1 << 22)
#define GPIO_MASK_MII2TD3         	(1 << 21)
#define GPIO_MASK_MII2TD2         	(1 << 20)
#define GPIO_MASK_UARTB_RD          (1 << 19)
#define GPIO_MASK_UARTB_TD          (1 << 18)
#define GPIO_MASK_UARTA_CTS         (1 << 17)
#define GPIO_MASK_UARTA_TD         	(1 << 16)
#define GPIO_MASK_UARTA_RD       	(1 << 15)
#define GPIO_MASK_SPI_RX           	(1 << 14)
#define GPIO_MASK_SPI_TX           	(1 << 13)
#define GPIO_MASK_SPI_CLK           (1 << 12)
#define GPIO_MASK_SPI_S1            (1 << 11)
#define GPIO_MASK_SPI_S0            (1 << 10)
#define GPIO_MASK_UARTA_RTS        	(1 <<  9)
#define GPIO_MASK_UARTC_RD          (1 <<  8)
#define GPIO_MASK_UARTC_TD         	(1 <<  7)
#define GPIO_MASK_TDMTD             (1 <<  6)
#define GPIO_MASK_TDMFS           	(1 <<  5)
#define GPIO_MASK_TDMCLK            (1 <<  4)
#define GPIO_MASK_TDMRD            	(1 <<  3)
#define GPIO_MASK_JEMU1            	(1 <<  2)
#define GPIO_MASK_PINTC             (1 <<  1)
#define GPIO_MASK_DRVVBUS           (1 <<  0)

#define UR8_CHIP_ID 0x14 

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
union _hw_gpio_bits {
    struct __hw_gpio_bits {
#if defined(CONFIG_MIPS_AR7) 
        /*--- Bit  0 ----*/ unsigned int uart0_rd : 1;
        /*--- Bit  1 ----*/ unsigned int uart0_td : 1;
        /*--- Bit  2 ----*/ unsigned int uart0_cts : 1;
        /*--- Bit  3 ----*/ unsigned int uart0_rts : 1;
        /*--- Bit  4 ----*/ unsigned int fser_clk : 1;
        /*--- Bit  5 ----*/ unsigned int fser_d : 1;
        /*--- Bit  6 ----*/ unsigned int ext_afe_sclk : 1;
        /*--- Bit  7 ----*/ unsigned int ext_afe_tx_fs : 1;
        /*--- Bit  8 ----*/ unsigned int ext_afe_txd : 1;
        /*--- Bit  9 ----*/ unsigned int ext_afe_rx_fs : 1;
        /*--- Bit 10 ----*/ unsigned int ext_afe_rxd1 : 1;
        /*--- Bit 11 ----*/ unsigned int ext_afe_rxd0 : 1;
        /*--- Bit 12 ----*/ unsigned int ext_afe_cdin : 1;
        /*--- Bit 13 ----*/ unsigned int ext_afe_cdout : 1;
        /*--- Bit 14 ----*/ unsigned int ephy_speed100 : 1;
        /*--- Bit 15 ----*/ unsigned int ephy_linkon : 1;
        /*--- Bit 16 ----*/ unsigned int ephy_activity : 1;
        /*--- Bit 17 ----*/ unsigned int ephy_fduplex : 1;
        /*--- Bit 18 ----*/ unsigned int eint0 : 1;
        /*--- Bit 29 ----*/ unsigned int eint1 : 1;
        /*--- Bit 20 ----*/ unsigned int mbsp0_tclk : 1;
        /*--- Bit 21 ----*/ unsigned int mbsp0_rclk : 1;
        /*--- Bit 22 ----*/ unsigned int mbsp0_rd : 1;
        /*--- Bit 23 ----*/ unsigned int mbsp0_td : 1;
        /*--- Bit 24 ----*/ unsigned int mbsp0_rfs : 1;
        /*--- Bit 25 ----*/ unsigned int mbsp0_tfs : 1;
        /*--- Bit 26 ----*/ unsigned int mii_dio : 1;
        /*--- Bit 27 ----*/ unsigned int mii_dclk : 1;
        /*--- Bit 28 ----*/ unsigned int mii_mdix : 1;
        /*--- Bit 29 ----*/ unsigned int reserved : 3;
#endif /*--- #if defined(CONFIG_MIPS_AR7) ---*/
#if defined(CONFIG_MIPS_UR8)
        /*--- Bit  0 ----*/ unsigned int drvvbus : 1;
        /*--- Bit  1 ----*/ unsigned int pintc : 1;
        /*--- Bit  2 ----*/ unsigned int jemu1 : 1;
        /*--- Bit  3 ----*/ unsigned int tdmrd : 1;
        /*--- Bit  4 ----*/ unsigned int tdmclk : 1;
        /*--- Bit  5 ----*/ unsigned int tdmfs : 1;
        /*--- Bit  6 ----*/ unsigned int tdmtd : 1;
        /*--- Bit  7 ----*/ unsigned int uart2td : 1;
        /*--- Bit  8 ----*/ unsigned int uart2rd: 1;
        /*--- Bit  9 ----*/ unsigned int uart0rts: 1;
        /*--- Bit 10 ----*/ unsigned int spics0: 1;
        /*--- Bit 11 ----*/ unsigned int spics1: 1;
        /*--- Bit 12 ----*/ unsigned int spiclk: 1;
        /*--- Bit 13 ----*/ unsigned int spitx: 1;
        /*--- Bit 14 ----*/ unsigned int spirx: 1;
        /*--- Bit 15 ----*/ unsigned int uart0_rd : 1;
        /*--- Bit 16 ----*/ unsigned int uart0_td : 1;
        /*--- Bit 17 ----*/ unsigned int uart0_cts : 1;
        /*--- Bit 18 ----*/ unsigned int uart1_rd : 1;
        /*--- Bit 19 ----*/ unsigned int uart1_td : 1;
        /*--- Bit 20 ----*/ unsigned int mii2td2 : 1;
        /*--- Bit 21 ----*/ unsigned int mii2td3 : 1;
        /*--- Bit 22 ----*/ unsigned int mii2ten : 1;
        /*--- Bit 23 ----*/ unsigned int ce3 : 1;
        /*--- Bit 24 ----*/ unsigned int pgnt1 : 1;
        /*--- Bit 25 ----*/ unsigned int pgnt2 : 1;
        /*--- Bit 26 ----*/ unsigned int pintb : 1;
        /*--- Bit 27 ----*/ unsigned int vlrxd0 : 1;
        /*--- Bit 28 ----*/ unsigned int vlrxd1 : 1;
        /*--- Bit 29 ----*/ unsigned int mii2rd2 : 1;
        /*--- Bit 30 ----*/ unsigned int mii2rd3 : 1;
        /*--- Bit 31 ----*/ unsigned int mii2rclk : 1;
#endif /*--- #if defined(CONFIG_MIPS_UR8) ---*/
    } Bits;
    volatile unsigned int Register;
};

#if defined(CONFIG_MIPS_UR8)
union _hw_gpio2_bits {
    struct __hw_gpio2_bits {
        /*--- Bit  0 ----*/ unsigned int mii2tclk : 1; // 32
        /*--- Bit  1 ----*/ unsigned int mii2col : 1; // 33
        /*--- Bit  2 ----*/ unsigned int mii2crs : 1; // 34
        /*--- Bit  3 ----*/ unsigned int mii2rdv : 1; // 35
        /*--- Bit  4 ----*/ unsigned int mii2rer : 1; // 36
        /*--- Bit  5 ----*/ unsigned int eint : 1; // 37
        /*--- Bit  6 ----*/ unsigned int preq1 : 1; // 38
        /*--- Bit  7 ----*/ unsigned int preq2 : 1; // 39
        /*--- Bit  8 ----*/ unsigned int mii2td0 : 1; // 40
        /*--- Bit  9 ----*/ unsigned int mii2td1 : 1; // 41
        /*--- Bit 10 ----*/ unsigned int mii2rd0 : 1; // 42
        /*--- Bit 11 ----*/ unsigned int mii2rd1 : 1; // 43
    } Bits;
    volatile unsigned int Register;
};
#endif /*--- #if defined(CONFIG_MIPS_UR8) ---*/

struct _hw_gpio {
    union _hw_gpio_bits InputData;
    union _hw_gpio_bits OutputData;
    union _hw_gpio_bits Direction;
    union _hw_gpio_bits Enable;
#if defined(CONFIG_MIPS_UR8)
    unsigned char reserved[0x40 - 0x10];
    union _hw_gpio2_bits InputData2;
    union _hw_gpio2_bits OutputData2;
    union _hw_gpio2_bits Direction2;
    union _hw_gpio2_bits Enable2;
#endif /*--- #if defined(CONFIG_MIPS_UR8) ---*/
};

enum _hw_gpio_direction {
    GPIO_OUTPUT_PIN = 0,
    GPIO_INPUT_PIN  = 1
};

enum _hw_gpio_function {
    GPIO_PIN     = 1,
    FUNCTION_PIN = 0
};

typedef enum _hw_gpio_direction GPIO_DIR;
typedef enum _hw_gpio_function  GPIO_MODE;


union _chip_version {
    volatile unsigned int Reg;
    struct __chip_version {
        unsigned int Id             : 16;
        unsigned int revision       : 8;
        unsigned int reserved       : 8;
    } Bits;
};

#endif /*--- #if !defined(NO_TYPES) ---*/

