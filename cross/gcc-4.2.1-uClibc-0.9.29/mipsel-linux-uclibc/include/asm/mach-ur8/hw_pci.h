#if !defined ( __YAMUNA_PCI_H_ )
#define __YAMUNA_PCI_H_


/*------#defines for memory and IO--------
* if another platform comes with different values, guard with CONFIG_YAMUNA
*/
#define UR8_PCI_IO_START		0x7FFF0000
#define UR8_PCI_IO_END			0x7FFFFFFF
#define UR8_PCI_MEM_START		0x40000000
#define UR8_PCI_MEM_END			0x50000000
#define UR8_PCI_INTR_MASK		0x0000000B	


#ifdef CONFIG_UR8_EVM
#define MIN_PCI_SLOT_NO			6
#define MAX_PCI_SLOT_NO			8
#else
#define MIN_PCI_SLOT_NO			14
#define MAX_PCI_SLOT_NO			14
#endif

#define UR8_PCI_SLOTS                   3                       /* max number of pci slots */



#define UR8_PCI   	                25 /* Yamuna Interrupt Map (Primary Interrupts) aus yamuna.h */
#define UR8_PCI_HWIRQ			UR8_PCI /* this will come in from yamuna.h, war AVALANCHE_PCI */
#define UR8_PCI_HW_BASE			UR8_PCI_HWIRQ
#define UR8_PCI_HW_END			UR8_PCI_HWIRQ
#define UR8_Y_INTA_BIT			16

#define UR8_PCI_SPEED                    33                      /* in Mhz */
#define UR8_PCI_MAX_GRANT                255                     /* number of PCI clocks each master can take */


/*----------------------------------------
* the defines for the PCI configuration space
*
* mostly just defining the values should be enough for a new board as the basic PCIIF is
* pretty similar. but cross validate the programming when adding new board
*
*/
#define UR8_PCI_MASTER_CONTROL		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x310 ) )
#define UR8_PCI_ARBITER_CONTROL		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x184 ) )
#define UR8_PCI_COMMAND			(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x308 ) )
#define UR8_PCI_ADDRESS			(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x304 ) )
#define UR8_PCI_DATA			(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x300 ) )
#define UR8_PCI_INTR_CLEAR		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x14 ) )
#define UR8_PCI_INTR_STATE		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x10 ) )
#define UR8_PCI_INTR_ENABLE		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x20 ) )
#define UR8_PCI_INTR_DISABLE		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x24 ) )
#define UR8_PCI_BE_INTR_ENABLE		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x30 ) )
#define UR8_PCI_BE_INTR_DISABLE		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x34 ) )
#define UR8_PCI_SLAVE_CACHE		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x10C ) )
#define UR8_PCI_SLAVE_MASK_0		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x110 ) )
#define UR8_PCI_SLAVE_TRANS_0		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x1c0 ) )
#define UR8_PCI_CFG_DONE_REG		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x180 ) )
#define UR8_PCI_SLAVE_CONTROL		UR8_PCI_CFG_DONE_REG
#define UR8_PCI_READ_CFG			0x1
#define UR8_PCI_WRITE_CFG		0x0
#define UR8_PCI_READ_IO			0x5
#define UR8_PCI_WRITE_IO			0x4
#define UR8_PCI_RUN_COMMAND		0x2
#define UR8_PCI_BUSY_MASK		0x80000000
#define UR8_PCI_BUSY			0

#ifdef CONFIG_UR8_EVM
#define UR8_PCIIF_MASTER_DEVICE		0x10000
#else
#define UR8_PCIIF_MASTER_DEVICE		0x40000000
#endif

#define UR8_PCI_ALL_BYTES		0xf0
#define UR8_PCI_CFG_DONE			0x1		
#define UR8_PCI_ENABLE_BUSMASTER		0x700			/* enable cfg, io, mem of io master even if slave not enabled */
#define UR8_PCI_ARBITER_ON		0x8000000f			/* turn on arbiter, clear all masters as sane to start */
#define UR8_PCI_VBUS_SPACE_BEGIN 	0x40000000
#define UR8_PCI_VBUS_SPACE_END		0x7fffffff
#define UR8_PCI_MASTER_ABORT		0x4
#define UR8_PCI_TARGET_ABORT		0x2

#define UR8_PCI_SLAVE_0_ENABLE		0x00010000
#define UR8_PCI_SLAVE_1_ENABLE		0x00020000
#define UR8_PCI_SLAVE_2_ENABLE		0x00040000
#define UR8_PCI_SLAVE_3_ENABLE		0x00080000
#define UR8_PCI_SLAVE_4_ENABLE		0x00100000
#define UR8_PCI_SLAVE_5_ENABLE		0x00200000

#define UR8_PCI_SLAVE_MASK_VALUE		0xe0000000		/* pci_space_begin to end of address space, nonprefetchable, anywhere */
#define UR8_PCI_SLAVE_0_MIRROR		(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x1e0 ) )
#define UR8_PCI_SLAVE_0_BASE		0x00000000
#define UR8_PCI_SLAVE_CMD_STATUS	(*(volatile unsigned long *) ( UR8_PCI_CFG_BASE + 0x104 ) )
#define UR8_PCI_SLAVE_RUN_CMD		0xf0000006
#define UR8_PCI_BUSMASTER_ENABLE     	0x4
#define UR8_PCI_MEMRESPONSE_ENABLE	0x2
#define UR8_PCI_IORESPONSE_ENABLE	0x1
#define UR8_PCI_PREFETCH_ENABLE          (1<<3)
#define PREFETCH_SIZE_32		(1<<5)
#define UR8_PCI_SLAVE_START		( UR8_PCI_BUSMASTER_ENABLE | UR8_PCI_MEMRESPONSE_ENABLE | UR8_PCI_IORESPONSE_ENABLE )


//struct ___pci_Rx_Address {
//    volatile unsigned int Size;
//    volatile unsigned int Offset;
//};

struct _pci_registers {

    /*--- 0x00 Vendor/Device ID Register ---*/
    unsigned int Vendor_ID ;

    /*--- 0x04 Command/Status Register ---*/
    union __pci_CmdStatus  {
        struct _pci_Status {
            unsigned int iopace : 1;         // 0
            unsigned int memspace : 1;       // 1
            unsigned int busmaster : 1;      // 2
            unsigned int specialcycles : 1;  // 3
            unsigned int memwinvlen : 1;     // 4
            unsigned int vgasnoopy : 1;      // 5
            unsigned int parityerr : 1;      // 6
            unsigned int waitcyclc : 1;      // 7
            unsigned int serr_n : 1;         // 8
            unsigned int fbacktoback_en : 1; // 9
            unsigned int irqdisable : 1;     // 10
            unsigned int reserved1 : 8;      // 11-18
            unsigned int irqstatus : 1;      // 19
            unsigned int caplist : 1;        // 20
            unsigned int hispdcap : 1;       // 21
            unsigned int reserves2 : 1;      // 22
            unsigned int fbacktoback_cap : 1;// 23
	    unsigned int mdataparity : 1;    // 24
	    unsigned int devsel_timing : 2;  // 25:26
	    unsigned int starget_abrt : 1;   // 27
	    unsigned int rtarget_abrt : 1;   // 28
	    unsigned int rmaster_abrt : 1;   // 29
	    unsigned int sigsys_error : 1;   // 30
	    unsigned int det_parity_error: 1;// 31
        } Bits;
        volatile unsigned int Register;
    } Status;
  
    /*--- 0x08 Revision/ID Register ---*/
    unsigned int Revision_ID ;
};

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/


#endif /* __YAMUNA_PCI_H_ */
