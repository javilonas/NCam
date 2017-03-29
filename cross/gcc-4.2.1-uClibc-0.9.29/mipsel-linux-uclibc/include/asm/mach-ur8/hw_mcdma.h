/* $Id: avalanche_dma.h,v 1.1 2002/04/02 19:19:43 jharrell Exp $
 * linux/include/asm/dma.h: Defines for using and allocating dma channels.
 *
 * Texas Instruments Avalanche ASIC DMA support
 * Jeff Harrell (jharrell@ti.com) 07/27/2000 
 *
 */

#ifndef __HW_MCDMA_H
#define __HW_MCDMA_H

#include <linux/config.h>
#include <asm/io.h>			/* need byte IO */
#include <linux/delay.h>
#include <asm/system.h>
#include <asm/mips-boards/ohio.h>

#ifdef HAVE_REALLY_SLOW_DMA_CONTROLLER
#define dma_outb	outb_p
#else
#define dma_outl	outl
#endif /* HAVE_REALLY_SLOW_DMA_CONTROLLER */

#define dma_inl		inl

#define MAX_DMA_CHANNELS	4

/*
 * The maximum address in KSEG0 that we can perform a DMA transfer to on this
 * platform.  This describes only the PC style part of the DMA logic like on
 * Deskstations or Acer PICA but not the much more versatile DMA logic used
 * for the local devices on Acer PICA or Magnums.
 */
#define MAX_DMA_ADDRESS         (PAGE_OFFSET + 0x1fffffff)

#define OHIO_MCDMA_BASE_1 (OHIO_MCDMA_BASE & 0x1fffffff)

/* DMA controller registers */

/* DMA channel 0 */
#define DMA_CHANNEL0            0x0
#define DMA0_SOURCE_ADDR        OHIO_MCDMA_BASE_1 + 0x0  /* source address */
#define DMA0_DEST_ADDR          OHIO_MCDMA_BASE_1 + 0x4  /* destination address */
#define DMA0_TRANS_CTRL         OHIO_MCDMA_BASE_1 + 0x8  /* transfer control */
                                                               
/* DMA channel 1 */                                            
#define DMA_CHANNEL1            0x1                            
#define DMA1_SOURCE_ADDR        OHIO_MCDMA_BASE_1 + 0x40 /* source address */
#define DMA1_DEST_ADDR          OHIO_MCDMA_BASE_1 + 0x44 /* destination address */
#define DMA1_TRANS_CTRL         OHIO_MCDMA_BASE_1 + 0x48 /* transfer control */
                                                               
/* DMA channel 2 */                                            
#define DMA_CHANNEL2            0x2                            
#define DMA2_SOURCE_ADDR        OHIO_MCDMA_BASE_1 + 0x80 /* source address */
#define DMA2_DEST_ADDR          OHIO_MCDMA_BASE_1 + 0x84 /* destination address */
#define DMA2_TRANS_CTRL         OHIO_MCDMA_BASE_1 + 0x88 /* transfer control */
                                                               
/* DMA channel 3 */                                            
#define DMA_CHANNEL3            0x3                            
#define DMA3_SOURCE_ADDR        OHIO_MCDMA_BASE_1 + 0xC0 /* source address */
#define DMA3_DEST_ADDR          OHIO_MCDMA_BASE_1 + 0xC4 /* destination address */
#define DMA3_TRANS_CTRL         OHIO_MCDMA_BASE_1 + 0xC8 /* transfer control */

/* DMA transfer control bits */
/* Burst mode */
#define DMA_BURST_MODE_1_WORD        0<<(20) /* single word */
#define DMA_BURST_MODE_2_WORD        1<<(20) /* double word */
#define DMA_BURST_MODE_4_WORD        2<<(20) /* quad word   */
#define DMA_BURST_MODE_RESERVERD     3<<(20) /* reserved    */

/* Source address mode */
#define DMA_SRC_ADDR_MODE_INCR       0<<(22) /* increment */
#define DMA_SRC_ADDR_MODE_RESERVED_1 1<<(22) /* reserved  */
#define DMA_SRC_ADDR_MODE_FIXED      2<<(22) /* fixed     */
#define DMA_SRC_ADDR_MODE_RESERVED_2 3<<(22) /* reserved  */

/* Destination address mode */
#define DMA_DST_ADDR_MODE_INCR       0<<(24) /* increment */
#define DMA_DST_ADDR_MODE_RESERVED_1 1<<(24) /* reserved  */
#define DMA_DST_ADDR_MODE_FIXED      2<<(24) /* fixed     */
#define DMA_DST_ADDR_MODE_RESERVED_2 3<<(24) /* reserved  */

/* Start/Active */
#define DMA_CHANNEL_ACTIVE           1<<(30)   
#define DMA_TRANSFER_START           1<<(31)   /* 1=start transfer 0=stop transfer */
#define DMA_TRANSFER_LENGTH          (0x3FFFC)

#define DMA_SOURCE                   1        
#define DMA_DEST                     0

static __inline__ void init_dma(unsigned int dmanr)
{
	switch(dmanr)
    {
      case  (DMA_CHANNEL0):
        dma_outl(0, DMA0_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL1):
        dma_outl(0, DMA1_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL2):
        dma_outl(0, DMA2_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL3):
        dma_outl(0, DMA3_TRANS_CTRL);
        break;
    }
}

/* enable/disable a specific DMA channel */
static __inline__ void enable_dma(unsigned int dmanr)
{
  switch(dmanr)
    {
      case  (DMA_CHANNEL0):
        dma_outl((dma_inl(DMA0_TRANS_CTRL) | DMA_TRANSFER_START), DMA0_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL1):
        dma_outl((dma_inl(DMA1_TRANS_CTRL) | DMA_TRANSFER_START), DMA1_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL2):
        dma_outl((dma_inl(DMA2_TRANS_CTRL) | DMA_TRANSFER_START), DMA2_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL3):
        dma_outl((dma_inl(DMA3_TRANS_CTRL) | DMA_TRANSFER_START), DMA3_TRANS_CTRL);
        break;
    }
}

static __inline__ void disable_dma(unsigned int dmanr)
{
  switch(dmanr)
    {
      case  (DMA_CHANNEL0):
        dma_outl((dma_inl(DMA0_TRANS_CTRL) & ~DMA_TRANSFER_START), DMA0_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL1):
        dma_outl((dma_inl(DMA1_TRANS_CTRL) & ~DMA_TRANSFER_START), DMA1_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL2):
        dma_outl((dma_inl(DMA2_TRANS_CTRL) & ~DMA_TRANSFER_START), DMA2_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL3):
        dma_outl((dma_inl(DMA3_TRANS_CTRL) & ~DMA_TRANSFER_START), DMA3_TRANS_CTRL);
        break;
    }    
}

/* 
 *  function: set_dma_mode():   
 *      This function sets the mode of the dma channel. This function can set
 *      the Source/Destination modes as well as the burst mode of the Channel.
 *      NOTE: when using this routine make sure to pass in all settings for the
 *      Source/Destination mode and burst mode!
 */

static __inline__ void set_dma_mode(unsigned int dmanr, int mode)
{
  switch(dmanr)
    {
      case  (DMA_CHANNEL0):
        dma_outl(((dma_inl(DMA0_TRANS_CTRL) & ~0x03F00000) | mode), DMA0_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL1):
        dma_outl(((dma_inl(DMA1_TRANS_CTRL) & ~0x03f00000) | mode), DMA1_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL2):
        dma_outl(((dma_inl(DMA2_TRANS_CTRL) & ~0x03f00000) | mode), DMA2_TRANS_CTRL);
        break;
      case  (DMA_CHANNEL3):
        dma_outl(((dma_inl(DMA3_TRANS_CTRL) & ~0x03f00000) | mode), DMA3_TRANS_CTRL);
        break;
    }     
}

static __inline__ void set_dma_addr(unsigned int dmanr, unsigned int a, unsigned int src_dest)
{
  switch(dmanr)
   	{
      case  (DMA_CHANNEL0):
        if(src_dest == DMA_SOURCE)
          dma_outl( a, DMA0_SOURCE_ADDR);     /* DMA Channel 0 source address      */
        else
          dma_outl( a, DMA0_DEST_ADDR);       /* DMA Channel 0 destination address */
        break;
      case  (DMA_CHANNEL1):
        if(src_dest == DMA_SOURCE)
          dma_outl( a, DMA1_SOURCE_ADDR);     /* DMA Channel 1 source address      */
        else                                                                         
          dma_outl( a, DMA1_DEST_ADDR);     /* DMA Channel 1 destination address */
        break;
      case  (DMA_CHANNEL2):
        if(src_dest == DMA_SOURCE)
          dma_outl(a, DMA2_SOURCE_ADDR);      /* DMA Channel 2 source address      */
        else                                                                          
          dma_outl(a, DMA2_DEST_ADDR);      /* DMA Channel 2 destination address */
        break;
      case  (DMA_CHANNEL3):
        if(src_dest == DMA_SOURCE)
          dma_outl( a, DMA3_SOURCE_ADDR);      /* DMA Channel 3 source address      */
        else                                                                           
          dma_outl( a, DMA3_DEST_ADDR);      /* DMA Channel 3 destination address */
        break;
    }     
}

/* Set the transfer size for a dma channel */
static __inline__ void set_dma_count(unsigned int dmanr, unsigned int count)
{
  switch(dmanr)
    {
      case (DMA_CHANNEL0): 
        dma_outl(((dma_inl(DMA0_TRANS_CTRL) & ~0x3FFFF) | count), DMA0_TRANS_CTRL);
        break;
      case (DMA_CHANNEL1): 
        dma_outl(((dma_inl(DMA1_TRANS_CTRL) & ~0x3FFFF) | count), DMA1_TRANS_CTRL);
        break;
      case (DMA_CHANNEL2): 
        dma_outl(((dma_inl(DMA2_TRANS_CTRL) & ~0x3FFFF) | count), DMA2_TRANS_CTRL);
        break;
      case (DMA_CHANNEL3): 
        dma_outl(((dma_inl(DMA3_TRANS_CTRL) & ~0x3FFFF) | count), DMA3_TRANS_CTRL);
        break;
    }    
}


/* Get DMA residue count. After a DMA transfer, this
 * should return zero. Reading this while a DMA transfer is
 * still in progress will return unpredictable results.
 * If called before the channel has been used, it may return 1.
 * Otherwise, it returns the number of _bytes_ left to transfer.
 *
 * Assumes DMA flip-flop is clear.
 */
static __inline__ int get_dma_residue(unsigned int dmanr)
{

  switch(dmanr)                                                                    
    {                                                                              
      case (DMA_CHANNEL0):
        return (dma_inl(DMA0_TRANS_CTRL) & DMA_TRANSFER_LENGTH);                                                                     
      case (DMA_CHANNEL1):                                                         
        return (dma_inl(DMA1_TRANS_CTRL) & DMA_TRANSFER_LENGTH);                                                                     
      case (DMA_CHANNEL2):                                                         
        return (dma_inl(DMA2_TRANS_CTRL) & DMA_TRANSFER_LENGTH);                                                                     
      case (DMA_CHANNEL3):                                                         
        return (dma_inl(DMA3_TRANS_CTRL) & DMA_TRANSFER_LENGTH);                                                                     
    }                                                                              
    return -1;

}

static __inline__ int get_dma_status(unsigned int dmanr)
{

  switch(dmanr)                                                                    
    {                                                                              
      case (DMA_CHANNEL0):
        return (dma_inl(DMA0_TRANS_CTRL) & (DMA_CHANNEL_ACTIVE | DMA_TRANSFER_START));                                                                     
      case (DMA_CHANNEL1):                                                         
        return (dma_inl(DMA1_TRANS_CTRL) & (DMA_CHANNEL_ACTIVE | DMA_TRANSFER_START));                                                                     
      case (DMA_CHANNEL2):                                                         
        return (dma_inl(DMA2_TRANS_CTRL) & (DMA_CHANNEL_ACTIVE | DMA_TRANSFER_START));                                                                     
      case (DMA_CHANNEL3):                                                         
        return (dma_inl(DMA3_TRANS_CTRL) & (DMA_CHANNEL_ACTIVE | DMA_TRANSFER_START));                                                                     
    }                                                                              
    return -1;


}



/* These are in kernel/dma.c: */
extern int request_dma(unsigned int dmanr, const char * device_id);	/* reserve a DMA channel */
extern void free_dma(unsigned int dmanr);	/* release it again */

#endif /* __HW_MCDMA_H */








