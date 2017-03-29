#if !defined(_HW_SPI_H_)
#define _HW_SPI_H_

union _spi_clk_ctrl {
    volatile unsigned int Register;
    struct __spi_clk_ctrl {
        unsigned int dclk_div       : 16;
        unsigned int reserved       : 15;
        unsigned int enable         : 1;
    } Bits;
};

union _spi_device_cfg {
    volatile unsigned int Register;
    struct __spi_device_cfg {
        unsigned int ckp0       : 1;
        unsigned int csp0       : 1;
        unsigned int ckph0      : 1;
        unsigned int dd0        : 1;
        unsigned int reserved0  : 3;
        unsigned int ckp1       : 1;
        unsigned int csp1       : 1;
        unsigned int ckph1      : 1;
        unsigned int dd1        : 1;
        unsigned int reserved1  : 3;
        unsigned int ckp2       : 1;
        unsigned int csp2       : 1;
        unsigned int ckph2      : 1;
        unsigned int dd2        : 1;
        unsigned int reserved2  : 3;
        unsigned int ckp3       : 1;
        unsigned int csp3       : 1;
        unsigned int ckph3      : 1;
        unsigned int dd3        : 1;
        unsigned int reserved3  : 3;
    } Bits;
};

#define SPI_CMD_READ        (1 << 16)
#define SPI_CMD_WRITE       (2 << 16)
#define SPI_WORD_LEN_8      (7 << 19)  
#define SPI_WORD_LEN_16    (15 << 19)  
#define SPI_WORD_LEN_24    (23 << 19)  
#define SPI_WORD_LEN_32    (31 << 19)  
#define SPI_USE_CS0         (0 << 28)
#define SPI_USE_CS1         (1 << 28)
#define SPI_USE_CS2         (2 << 28)
#define SPI_USE_CS3         (3 << 28)

#define SPI_MAX_FRAME_LEN   (4096 - 4)  /*--- 1xCMD + 3xADDRESS ---*/

union _spi_cmd {
    volatile unsigned int Register;
    struct __spi_cmd {
        unsigned int flen       : 12;
        unsigned int reserved0  : 2;
        unsigned int wirq       : 1;
        unsigned int firq       : 1;
        unsigned int cmd        : 2;
        unsigned int reserved1  : 1;
        unsigned int wlen       : 5;
        unsigned int reserved2  : 4;
        unsigned int cs_num     : 2;
        unsigned int reserved3  : 2;
    } Bits;
};

union _spi_sr {
    volatile unsigned int Register;
    struct __spi_sr {
        volatile unsigned int busy       : 1;
        volatile unsigned int wc         : 1;
        volatile unsigned int fc         : 1;
        volatile unsigned int ae         : 1;
        unsigned int reserved0  : 12;
        volatile unsigned int wdcnt      : 13;
        unsigned int reserved1  : 3;
    } Bits;
};

union _data_sr {
    volatile unsigned int Register;
    unsigned char Byte[4];
} data;

struct _spi_register {
    union _spi_clk_ctrl         clk_ctrl;
    union _spi_device_cfg       device_cfg;
    union _spi_cmd              cmd;
    union _spi_sr               status;
    union _data_sr              data;
};

#endif
