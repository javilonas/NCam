/*------------------------------------------------------------------------------------------*\
 *
 *  $Id: hw_irq.h 1.2 2004/03/29 13:24:07Z mpommerenke Exp $
 *
 *  $Log: hw_irq.h $
 *  Revision 1.2  2004/03/29 13:24:07Z  mpommerenke
 *
\*------------------------------------------------------------------------------------------*/
#ifndef _hw_irq_h_
#define _hw_irq_h_


#define INTR_EXCR		(*(volatile unsigned *)(INTR_BASE + 0x088))

#if !defined(NO_TYPES)
/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
union _irq_hw_spacing_prescale {
    struct __irq_hw_spacing_prescale {
        unsigned int IPACEP : 12;
        unsigned int reserved : 19;
        unsigned int TEST : 1;
    } Bits;
    volatile unsigned int Register;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
union _irq_hw_spacing_map {
    struct __irq_hw_spacing_map {
        unsigned int IPACEMAP0 : 6;
        unsigned int Reserved0 : 2;
        unsigned int IPACEMAP1 : 6;
        unsigned int Reserved1 : 2;
        unsigned int IPACEMAP2 : 6;
        unsigned int Reserved2 : 2;
        unsigned int IPACEMAP3 : 6;
        unsigned int Reserved3 : 2;
    } Bits;
    volatile unsigned int Register;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
union _irq_hw_spacing_max {
    struct __irq_hw_spacing_max {
        unsigned int IPACEMAX0 : 6;
        unsigned int Reserved0 : 1;
        unsigned int IPACEN0   : 1;
        unsigned int IPACEMAX1 : 6;
        unsigned int Reserved1 : 1;
        unsigned int IPACEN1   : 1;
        unsigned int IPACEMAX2 : 6;
        unsigned int Reserved2 : 1;
        unsigned int IPACEN2   : 1;
        unsigned int IPACEMAX3 : 6;
        unsigned int Reserved3 : 1;
        unsigned int IPACEN3   : 1;
    } Bits;
    volatile unsigned int Register;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _irq_hw {
    /* 0x000 */ volatile unsigned int status_set_reg[2];
    /* 0x008 */ unsigned int reserved1[(0x10 - 0x08)/sizeof(unsigned int)];
    /* 0x010 */ volatile unsigned int status_clear_reg[2];
    /* 0x018 */ unsigned int reserved2[(0x20 - 0x18)/sizeof(unsigned int)];
    /* 0x020 */ volatile unsigned int enable_set_reg[2];
    /* 0x028 */ unsigned int reserved3[(0x30 - 0x28)/sizeof(unsigned int)];
    /* 0x030 */ volatile unsigned int enable_clear_reg[2];
    /* 0x038 */ unsigned int reserved4[(0x40 - 0x38)/sizeof(unsigned int)];
    /* 0x040 */ volatile unsigned int priority_index_reg;
    /* 0x044 */ volatile unsigned int priority_mask_index_reg;
    /* 0x048 */ unsigned int reserved5[(0x50 - 0x48)/sizeof(unsigned int)];
    /* 0x050 */ volatile unsigned int polarity_reg[2];
    /* 0x058 */ unsigned int reserved6[(0x60 - 0x58)/sizeof(unsigned int)];
    /* 0x060 */ volatile unsigned int type_reg[2];
    /* 0x068 */ unsigned int reserved7[(0x80 - 0x68)/sizeof(unsigned int)];
    /* 0x080 */ volatile unsigned int exception_set_status_reg;
    /* 0x084 */ unsigned int reserved8;
    /* 0x088 */ volatile unsigned int exception_clear_status_reg;
    /* 0x08C */ unsigned int reserved9;
    /* 0x090 */ volatile unsigned int exception_enable_set_reg;
    /* 0x094 */ unsigned int reserved10;
    /* 0x098 */ volatile unsigned int exception_enable_clear_reg;
    /* 0x09C */ unsigned int reserved11;
    /* 0x0A0 */ union _irq_hw_spacing_prescale pacing_prescale_reg;
    /* 0x0A4 */ union _irq_hw_spacing_map pacing_map_reg;
    /* 0x0A8 */ union _irq_hw_spacing_max pacing_max_reg;
    /* 0x0AC */ unsigned int reserved12[(0x200 - 0xAC)/sizeof(unsigned int)];
    /* 0x200 */ volatile unsigned int channel_number_reg[40];
};


extern struct _irq_hw *Irq __attribute__ ((section(".bss")));

#endif /*--- #if !defined(NO_TYPES) ---*/














#endif /*--- #ifndef _hw_irq_h_ ---*/
