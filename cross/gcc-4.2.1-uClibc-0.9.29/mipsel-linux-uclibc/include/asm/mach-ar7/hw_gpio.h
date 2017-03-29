/*------------------------------------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------------------------------------*/
#ifndef _hw_gpio_h_
#define _hw_gpio_h_

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
/* GPIO registers */
/*--- #define GPIO_IN         (*(volatile unsigned *)(AR7_GPIO_BASE+0x0)) ---*/
/*--- #define GPIO_OUT   		(*(volatile unsigned int *)(AR7_GPIO_BASE+0x4)) ---*/
/*--- #define GPIO_DIR   		(*(volatile unsigned int *)(AR7_GPIO_BASE+0x8)) ---*/ /* 0=o/p, 1=i/p */
/*--- #define GPIO_EN    		(*(volatile unsigned int *)(AR7_GPIO_BASE+0xc)) ---*/ /* 0=GPIO Mux 1=GPIO */

#define AR7_CVR     (*(volatile unsigned int *)(AR7_GPIO_BASE+0x14)) /* see _chip_version */
#define AR7_DIDR1   (*(volatile unsigned int *)(AR7_GPIO_BASE+0x18))
#define AR7_DIDR2   (*(volatile unsigned int *)(AR7_GPIO_BASE+0x1C))

#define GPIO_BIT_MII_MDIX           28
#define GPIO_BIT_MII_DCLK           27
#define GPIO_BIT_MII_DIO		    26
#define GPIO_BIT_MBSP0_TFS      	25
#define GPIO_BIT_MBSP0_RFS      	24
#define GPIO_BIT_MBSP0_TD       	23
#define GPIO_BIT_MBSP0_RD       	22
#define GPIO_BIT_MBSP0_RCLK     	21
#define GPIO_BIT_MBSP0_TCLK     	20
#define GPIO_BIT_EINT1          	19
#define GPIO_BIT_EINT0          	18
#define GPIO_BIT_EPHY_FDUPLEX   	17
#define GPIO_BIT_EPHY_ACTIVITY  	16
#define GPIO_BIT_EPHY_LINKON    	15
#define GPIO_BIT_EPHY_SPEED100  	14
#define GPIO_BIT_EXT_AFE_CDOUT  	13
#define GPIO_BIT_EXT_AFE_CDIN   	12
#define GPIO_BIT_EXT_AFE_RXD0   	11
#define GPIO_BIT_EXT_AFE_RXD1   	10
#define GPIO_BIT_EXT_AFE_RX_FS  	 9
#define GPIO_BIT_EXT_AFE_TXD    	 8
#define GPIO_BIT_EXT_AFE_TX_FS  	 7
#define GPIO_BIT_EXT_AFE_SCLK   	 6
#define GPIO_BIT_FSER_D         	 5
#define GPIO_BIT_FSER_CLK       	 4
#define GPIO_BIT_UART0_RTS      	 3
#define GPIO_BIT_UART0_CTS      	 2
#define GPIO_BIT_UART0_TD       	 1
#define GPIO_BIT_UART0_RD       	 0

#define GPIO_MASK_MII_MDIX          (1 << 28)
#define GPIO_MASK_MII_DCLK          (1 << 27)
#define GPIO_MASK_MII_DIO		    (1 << 26)
#define GPIO_MASK_MBSP0_TFS      	(1 << 25)
#define GPIO_MASK_MBSP0_RFS      	(1 << 24)
#define GPIO_MASK_MBSP0_TD       	(1 << 23)
#define GPIO_MASK_MBSP0_RD       	(1 << 22)
#define GPIO_MASK_MBSP0_RCLK     	(1 << 21)
#define GPIO_MASK_MBSP0_TCLK     	(1 << 20)
#define GPIO_MASK_EINT1          	(1 << 19)
#define GPIO_MASK_EINT0          	(1 << 18)
#define GPIO_MASK_EPHY_FDUPLEX   	(1 << 17)
#define GPIO_MASK_EPHY_ACTIVITY  	(1 << 16)
#define GPIO_MASK_EPHY_LINKON    	(1 << 15)
#define GPIO_MASK_EPHY_SPEED100  	(1 << 14)
#define GPIO_MASK_EXT_AFE_CDOUT  	(1 << 13)
#define GPIO_MASK_EXT_AFE_CDIN   	(1 << 12)
#define GPIO_MASK_EXT_AFE_RXD0   	(1 << 11)
#define GPIO_MASK_EXT_AFE_RXD1   	(1 << 10)
#define GPIO_MASK_EXT_AFE_RX_FS  	(1 <<  9)
#define GPIO_MASK_EXT_AFE_TXD    	(1 <<  8)
#define GPIO_MASK_EXT_AFE_TX_FS  	(1 <<  7)
#define GPIO_MASK_EXT_AFE_SCLK   	(1 <<  6)
#define GPIO_MASK_FSER_D         	(1 <<  5)
#define GPIO_MASK_FSER_CLK       	(1 <<  4)
#define GPIO_MASK_UART0_RTS      	(1 <<  3)
#define GPIO_MASK_UART0_CTS      	(1 <<  2)
#define GPIO_MASK_UART0_TD       	(1 <<  1)
#define GPIO_MASK_UART0_RD       	(1 <<  0)

#define AR7_CHIP_ID 0x05

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
union _hw_gpio_bits {
    struct __hw_gpio_bits {
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
    } Bits;
    volatile unsigned int Register;
};

struct _hw_gpio {
    union _hw_gpio_bits InputData;
    union _hw_gpio_bits OutputData;
    union _hw_gpio_bits Direction;
    union _hw_gpio_bits Enable;
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

