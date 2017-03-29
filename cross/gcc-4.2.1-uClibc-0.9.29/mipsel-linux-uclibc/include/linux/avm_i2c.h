/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _avm_i2c_h_
#define _avm_i2c_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
enum _avm_i2c_type {
    avm_i2c_type_16_bit,
    avm_i2c_type_12_bit,
    avm_i2c_type_8_bit
};


/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _i2c_cmd {
    unsigned int device_address;
    unsigned int register_address;
    unsigned int data_length;
    enum _avm_i2c_type device_type;
    unsigned char Buffer[32];
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
unsigned int i2c_hw_init(unsigned int freq);
void i2c_hw_deinit(void);
unsigned int i2c_hw_set_speed(unsigned int i2c_frequency);

unsigned int i2c_read(unsigned int dev_address, unsigned char *ReadData, unsigned int ReadLength);
unsigned int i2c_write(unsigned int dev_address, unsigned char *WriteData, unsigned int WriteLength);
unsigned int i2c_hw_read(unsigned int dev_address, unsigned char *ReadData, unsigned int ReadLength);
unsigned int i2c_hw_write(unsigned int dev_address, unsigned char *WriteData, unsigned int WriteLength);

unsigned int i2c_block_read(struct _i2c_cmd *Cmd);
unsigned int i2c_block_write(struct _i2c_cmd *Cmd);



/*-----------------------------------------------------------------------------------------*\
\*-----------------------------------------------------------------------------------------*/
#define _I2C_READ_ID           0x01
#define _I2C_WRITE_ID          0x02
#define _I2C_RAW_READ_ID       0x03
#define _I2C_RAW_WRITE_ID      0x04
#define _I2C_SET_SPEED_ID      0x10

#define _I2C_TYPE_RAW          0x00

#include <asm/ioctl.h>

#define I2C_READ_ID            _IOC(_IOC_READ | _IOC_WRITE, _I2C_TYPE_RAW, _I2C_READ_ID,      sizeof(struct _i2c_cmd))
#define I2C_WRITE_ID           _IOC(_IOC_READ | _IOC_WRITE, _I2C_TYPE_RAW, _I2C_WRITE_ID,     sizeof(struct _i2c_cmd))
#define I2C_RAW_READ_ID        _IOC(_IOC_READ | _IOC_WRITE, _I2C_TYPE_RAW, _I2C_RAW_READ_ID,  sizeof(struct _i2c_cmd))
#define I2C_RAW_WRITE_ID       _IOC(_IOC_READ | _IOC_WRITE, _I2C_TYPE_RAW, _I2C_RAW_WRITE_ID, sizeof(struct _i2c_cmd))
#define I2C_SET_SPEED_ID       _IOC(_IOC_READ | _IOC_WRITE, _I2C_TYPE_RAW, _I2C_SET_SPEED_ID, sizeof(struct _i2c_cmd))



#endif /*--- #ifndef _avm_i2c_h_ ---*/
