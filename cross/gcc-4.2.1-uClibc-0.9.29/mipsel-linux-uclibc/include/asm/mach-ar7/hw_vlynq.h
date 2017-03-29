/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _vlynq_h_
#define _vlynq_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
union __vlynq_Interrupt_Vector {
    struct _vlynq_Interrupt_Vector_1 {
        unsigned int intvec0 : 5;
        unsigned int intpol0 : 1;
        unsigned int inttype0 : 1;
        unsigned int inten0 : 1;
        unsigned int intvec1 : 5;
        unsigned int intpol1 : 1;
        unsigned int inttype1 : 1;
        unsigned int inten1 : 1;
        unsigned int intvec2 : 5;
        unsigned int intpol2 : 1;
        unsigned int inttype2 : 1;
        unsigned int inten2 : 1;
        unsigned int intvec3 : 5;
        unsigned int intpol3 : 1;
        unsigned int inttype3 : 1;
        unsigned int inten3 : 1;
    } Bits;
    volatile unsigned int Register;
};

struct ___vlynq_Rx_Address {
    volatile unsigned int Size;
    volatile unsigned int Offset;
};

struct ___vlynq_Chip_Version {
    unsigned int devid : 16;
    unsigned int devrev: 16;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
/*--- Address Offset Register ---*/
struct _vlynq_registers_half {

    /*--- 0x00 Revision/ID Register ---*/
    unsigned int Revision_ID ;

    /*--- 0x04 Control Register ---*/
    union __vlynq_Control  {
        struct _vlynq_Control {
#define VLYNQ_CTL_CTRL_SHIFT            0
            unsigned int reset : 1;
#define VLYNQ_CTL_ILOOP_SHIFT           1
            unsigned int iloop : 1;
#define VLYNQ_CTL_AOPT_DISABLE_SHIFT    2
            unsigned int aopt_disable : 1;
            unsigned int reserved1 : 4;
#define VLYNQ_CTL_INT2CFG_SHIFT         7
            unsigned int int2cfg : 1;
#define VLYNQ_CTL_INTVEC_SHIFT          8
            unsigned int intvec : 5;
#define VLYNQ_CTL_INTEN_SHIFT           13
            unsigned int intenable : 1;
#define VLYNQ_CTL_INTLOCAL_SHIFT        14
            unsigned int intlocal : 1;
#define VLYNQ_CTL_CLKDIR_SHIFT          15
            unsigned int clkdir : 1;
#define VLYNQ_CTL_CLKDIV_SHIFT          16
            unsigned int clkdiv : 3;
            unsigned int reserved2 : 2;
#define VLYNQ_CTL_TXFAST_SHIFT          21
            unsigned int txfastpath : 1;
#define VLYNQ_CTL_RTMEN_SHIFT           22
            unsigned int rtmenable : 1;
#define VLYNQ_CTL_RTMVALID_SHIFT        23
            unsigned int rtmvalidwr : 1;
#define VLYNQ_CTL_RTMSAMPLE_SHIFT       24
            unsigned int rxsampleval : 3;
            unsigned int reserved3 : 3;
#define VLYNQ_CTL_SCLKUDIS_SHIFT        30
            unsigned int sclkpudis : 1;
#define VLYNQ_CTL_PMEM_SHIFT            31
            unsigned int pmen : 1;
        } Bits;
        volatile unsigned int Register;
    } Control;

    /*--- 0x08 Status Register ---*/
    union __vlynq_Status  {
        struct _vlynq_Status {
            unsigned int link : 1;
            unsigned int mpend : 1;
            unsigned int spend : 1;
            unsigned int nfempty0 : 1;
            unsigned int nfempty1 : 1;
            unsigned int nfempty2 : 1;
            unsigned int nfempty3 : 1;
            unsigned int lerror : 1;
            unsigned int rerror : 1;
            unsigned int oflow : 1;
            unsigned int iflow : 1;
            unsigned int rtm : 1;
            unsigned int rxcurrent_sample : 3;
            unsigned int reserved1 : 5;
            unsigned int swidthout : 4;
            unsigned int swidthin : 4;
            unsigned int reserved2 : 4;
        } Bits;
        volatile unsigned int Register;
    } Status;

    /*--- 0x0C Interrupt Priority Vector Status/Clear Register ---*/
    union __vlynq_Interrupt_Priority  {
        struct _vlynq_Interrupt_Priority  {
            unsigned int intstat : 5;
            unsigned int reserved : (32 - 5 - 1);
            unsigned int nointpend : 1;
        } Bits;
        volatile unsigned int Register;
    } Interrupt_Priority;

    /*--- 0x10 Interrupt Status/Clear Register ---*/
    volatile unsigned int Interrupt_Status;

    /*--- 0x14 Interrupt Pending/Set Register ---*/
    volatile unsigned int Interrupt_Pending_Set;

    /*--- 0x18 Interrupt Pointer Register ---*/
    volatile unsigned int Interrupt_Pointer;

    /*--- 0x1C Tx Address Map ---*/
    volatile unsigned int Tx_Address;

    /*--- 0x20 Rx Address Map Size 1 ---*/
    /*--- 0x24 Rx Address Map Offset 1 ---*/
    /*--- 0x28 Rx Address Map Size 2 ---*/
    /*--- 0x2c Rx Address Map Offset 2 ---*/
    /*--- 0x30 Rx Address Map Size 3 ---*/
    /*--- 0x34 Rx Address Map Offset 3 ---*/
    /*--- 0x38 Rx Address Map Size 4 ---*/
    /*--- 0x3c Rx Address Map Offset 4 ---*/
    struct ___vlynq_Rx_Address Rx_Address[4]; 

    /*--- 0x40 Chip Version Register ---*/
    struct ___vlynq_Chip_Version Chip_Version;

    /*--- 0x44 Auto Negotiation Register ---*/
    union __Auto_Negotiation  {
        struct _Auto_Negotiation {
            unsigned int reserved1 : 16;
            unsigned int _2_x : 1;
            unsigned int reserved2 : 15;
        } Bits;
        volatile unsigned int Register;
    } Auto_Negotiation;

    /*--- 0x48 Manual Negotiation Register ---*/
    volatile unsigned int Manual_Negotiation;

    /*--- 0x4C Negotiation Status Register ---*/
    union __Negotiation_Status  {
        struct _Negotiation_Status {
            unsigned int status : 1;
            unsigned int reserved : 31;
        } Bits;
        volatile unsigned int Register;
    } Negotiation_Status;

    /*--- 0x50-0x5C Reserved ---*/
    unsigned char reserved1[0x5C - 0x4C];

    /*--- 0x60 Interrupt Vector 3-0 ---*/
    union __vlynq_Interrupt_Vector Interrupt_Vector_1;

    /*--- 0x64 Interrupt Vector 7-4 ---*/
    union __vlynq_Interrupt_Vector Interrupt_Vector_2;

    /*--- 0x68-0x7C Reserved for Interrupt Vectors 8-31 ---*/
    unsigned char reserved2[0x7C - 0x64];
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _vlynq_registers {
    struct _vlynq_registers_half local;
    struct _vlynq_registers_half remote;
};



#endif /*--- #ifndef _vlynq_h_ ---*/
