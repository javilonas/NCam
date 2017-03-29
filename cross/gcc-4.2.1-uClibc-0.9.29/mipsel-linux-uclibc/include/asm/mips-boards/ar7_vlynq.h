/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _ar7_vlynq_h_
#define _ar7_vlynq_h_

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#include <linux/interrupt.h>
#include <asm/mach-ar7/hw_vlynq.h>

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#define MAX_VLYNQ_DEVICES       2
#define MAX_VLYNQ_INT_VECTORS   8           /*--- mehr Interruptvektoren sind nicht erlaubt ---*/
#define VLYNQ_NUM_INT_BITS		32			/* Maximale Anzahl von Pins auf die ein Interrupt gemappt werden darf */

#define AR7_VLYNQ_INIT_RETRY   25

#define AR7_VLYNQ_INT_SHIFT        7
#define AR7_VLYNQ_TYPE_SHIFT       6
#define AR7_VLYNQ_POLARITY_SHIFT   5

enum _vlynq_vector_typ {
    VLYNQ_VECTOR_LEVEL = 0,
    VLYNQ_VECTOR_PULSE
};

enum _vlynq_vector_polarity {
    VLYNQ_VECTOR_ACTIVE_HIGH = 0,
    VLYNQ_VECTOR_ACTIVE_LOW
};

/*------------------------------------------------------------------------------------------*\
 * forwand decl. 
\*------------------------------------------------------------------------------------------*/
struct _vlynq_registers;

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _vlynq_memory_windows {
    struct ___vlynq_Rx_Address Windows[4];
    unsigned int WindowCount;
    unsigned int Tx_Address;
};

enum _vlynq_interrupt_types {
    VLYNQ_INT_OFF = 0,
    VLYNQ_INT_LOCAL,
    VLYNQ_INT_REMOTE,
    VLYNQ_INT_ROOT_ISR
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _vlynq_interrupts {
    enum _vlynq_interrupt_types LocalEnable;
    enum _vlynq_interrupt_types RemoteEnable;
    unsigned int vector : 5;
    unsigned int irq;   /*--- wird von ar7_vlynq_init_link() gefuellt ---*/
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct _vlynq_context {
    unsigned int instance;
    volatile struct _vlynq_registers *vlynq;
    unsigned int data_base;

    struct _vlynq_memory_windows Local2Remote;
    struct _vlynq_memory_windows Remote2Local;
    struct _vlynq_interrupts LocalIrq;
    struct _vlynq_interrupts RemoteIrq;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
extern struct _vlynq_context *vlynq_config[MAX_VLYNQ_DEVICES];

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
unsigned int vlynq_get_irq(unsigned int instance);
unsigned int vlynq_irq_status(unsigned int instance);
unsigned int vlynq_irq_enable_mask(unsigned int instance);
unsigned int vlynq_irq_enable(unsigned int instance, enum _vlynq_interrupt_types dev_type, unsigned int irq);
unsigned int vlynq_irq_disable(unsigned int instance, enum _vlynq_interrupt_types dev_type, unsigned int irq);
unsigned int vlynq_irq_ack(unsigned int instance, unsigned int irq);
unsigned int vlynq_vector_to_irq(unsigned int instance, unsigned int vector);

unsigned int vlynq_irq_vector_setup(unsigned int instance, unsigned int irq, unsigned int map_vector, unsigned int dev_type, 
                                    enum _vlynq_vector_typ type, enum _vlynq_vector_polarity polarity);
/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
unsigned int ar7_vlynq_init(unsigned int instance);
/*unsigned int ar7_vlynq_init_link(unsigned int instance, struct _vlynq_context *context);*/
unsigned int ar7_vlynq_init_link(unsigned int instance);

struct _vlynq_context *ar7_vlynq_alloc_context(unsigned int instance);
unsigned int ar7_vlynq_free_context(unsigned int instance);

irqreturn_t vlynq_interrupt(int irq, void *dev_id, struct pt_regs *regs);

#endif /*--- #ifndef _ar7_vlynq_h_ ---*/
