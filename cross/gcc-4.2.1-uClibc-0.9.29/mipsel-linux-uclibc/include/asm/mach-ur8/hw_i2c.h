/*------------------------------------------------------------------------------------------------------------------------*\
 *
 *      $Id: hw_i2c.h 1.5 2004/03/29 13:24:06Z mpommerenke Exp $
 *
 *      $Log: hw_i2c.h $
 *      Revision 1.5  2004/03/29 13:24:06Z  mpommerenke
 *      Revision 1.4  2004/03/23 16:27:01Z  mpommerenke
 *      Revision 1.3  2004/02/13 15:30:33Z  mpommerenke
 *      Revision 1.2  2004/02/04 17:32:59Z  mpommerenke
 *
\*------------------------------------------------------------------------------------------------------------------------*/
#ifndef _hw_i2c_h_
#define _hw_i2c_h_

/*--------------------------------------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------------------------------------*/
#define I2C_DATA_HI    	(*(volatile unsigned int *)(OHIO_I2C_BASE + 0x0000))
#define I2C_DATA_HI_DEVICE_ADDRESS_MASK             (0x7F <<  0)
#define I2C_DATA_HI_READ_MODE                       (0x03 <<  8)
#define I2C_DATA_HI_WRITE_MODE                      (0x02 <<  8)
#define I2C_DATA_HI_END_BUSRT                       (0x01 << 10)

#define I2C_DATA_LOW   	(*(volatile unsigned int *)(OHIO_I2C_BASE + 0x0004))
#define I2C_DATA_LOW_DATA_MASK                      (0xFF <<  0)

#define I2C_CONFIG     	(*(volatile unsigned int *)(OHIO_I2C_BASE + 0x0008))
#define I2C_CONFIG_SPIKE_MASK(mask)                 ((mask) << 12)
#define I2C_CONFIG_IRQ_MASK                         (0x01 <<  0)

#define I2C_DATA_READ  	(*(volatile unsigned int *)(OHIO_I2C_BASE + 0x000C))
#define I2C_DATA_READ_ERROR                         (0x01 << 15)
#define I2C_DATA_READ_IRQ                           (0x01 << 14)
#define I2C_DATA_READ_WRITE_NOT_ALLOWED             (0x01 << 13)
#define I2C_DATA_READ_DATA_MASK                     (0xFF <<  0)

#define I2C_CLOCK_DIV  	(*(volatile unsigned int *)(OHIO_I2C_BASE + 0x0010))

struct _hw_i2c {
    union _hw_i2c_data_high {
        struct __hw_i2c_data_high {
            unsigned int device_address : 7;
            unsigned int mode : 2;
            unsigned int end_burst : 1;
            unsigned int reserved : (5 + 16);
        } Bits;
        unsigned int Register;
    } data_hi;
    union _hw_i2c_data_low {
        struct __hw_i2c_data_low {
            unsigned char data;
            unsigned char reserved[3];
        } Bits;
        unsigned int Register;
    } data_low;
    union _hw_i2c_config {
        struct __hw_i2c_config {
            unsigned int irq_enable : 1;
            unsigned int reserved0 : 12;
            unsigned int spike_mask : 3;
            unsigned int reserved2 : 17;
        } Bits;
        unsigned int Register;
    } config;
    union _hw_i2c_read_data {
        struct __hw_i2c_read_data {
            unsigned int data : 8;
            unsigned int reserved1 : 5;
            unsigned int write_allowed : 1;
            unsigned int interrupt : 1;
            unsigned int error : 1;
            unsigned int reserved2 : 16;
        } Bits;
        unsigned int Register;
    } read_data;
};


/*--- #define I2C_CLOCK_DIV_MAX_CLOCK		                 100000 ---*/          /* 100kHz */
#define I2C_CLOCK_DIV_MAX_CLOCK		                 (100000*4)          /* 400kHz */

#define I2C_PAGE_SIZE                                32


#endif /*--- #ifndef _hw_i2c_h_ ---*/
