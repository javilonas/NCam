#ifndef _hw_cpgmac_h_
#define _hw_cpgmac_h_

struct _hw_cpgmac {
    volatile unsigned int  IDVER;                                 /*--- 0x000 IDVER ID Version Register ---*/
    volatile unsigned int  Mac_In_Vector;                         /*--- 0x004 Mac_In_Vector Mac Input Vector (read only) ---*/
    volatile unsigned int  Mac_EOI_Vector;                        /*--- 0x008 Mac_EOI_Vector Mac End Of Interrupt Vector ---*/
    volatile unsigned int  Mac_IntStat_Raw;                       /*--- 0x00c Mac_IntStat_Raw MAC Interrupt Status Register (reads raw value) ---*/
    volatile unsigned int  Mac_IntStat_Masked;                    /*--- 0x010 Mac_IntStat_Masked MAC Interrupt Status Register (reads masked value) ---*/
    volatile unsigned int  Mac_IntMask_Set;                       /*--- 0x014 Mac_IntMask_Set MAC Interrupt Mask Set Register ---*/
    volatile unsigned int  Mac_IntMask_Clear;                     /*--- 0x018 Mac_IntMask_Clear MAC Interrupt Mask Clear Register ---*/
    volatile unsigned int  Rx_MBP_Enable;                         /*--- 0x01c Rx_MBP_Enable RX Multicast/Broadcast/Promiscuous Channel Enable Register ---*/
    volatile unsigned int  Rx_Unicast_Set;                        /*--- 0x020 Rx_Unicast_Set RX Unicast Set Register ---*/
    volatile unsigned int  Rx_Unicast_Clear;                      /*--- 0x024 Rx_Unicast_Clear RX Unicast Clear Register ---*/
    volatile unsigned int  Rx_Maxlen;                             /*--- 0x028 Rx_Maxlen RX Maximum Length Register ---*/
    volatile unsigned int  MacControl;                            /*--- 0x02c MacControl Mac Control Register ---*/
    volatile unsigned int  MacStatus;                             /*--- 0x030 MacStatus Mac Status Register ---*/
    volatile unsigned int  EMControl;                             /*--- 0x034 EMControl Emulation Control Register ---*/
    volatile unsigned int  FifoControl;                           /*--- 0x038 FifoControl Transmit and Receive FIFO Control Register ---*/
    volatile unsigned int  Mac_Cfig;                              /*--- 0x03c Mac_Cfig MAC Configuration Read Register ---*/
    volatile unsigned int  Soft_Reset;                            /*--- 0x040 Soft_Reset Soft Reset Register ---*/
    volatile unsigned int  MacSrcAddr_Lo ;                        /*--- 0x044 MacSrcAddr_Lo Mac Source Address lower 32-bits ---*/
    volatile unsigned int  MacSrcAddr_Hi;                         /*--- 0x048 MacSrcAddr_Hi MAC Source Address upper 16-bits ---*/
    volatile unsigned int  MacHash1;                              /*--- 0x04c MacHash1 MAC Address Hash 1 ---*/
    volatile unsigned int  MacHash2;                              /*--- 0x050 MacHash2 MAC Address Hash 2 ---*/
    volatile unsigned int  BoffTest;                              /*--- 0x054 BoffTest Backoff Test Register ---*/
    volatile unsigned int  Tpace_Test;                            /*--- 0x058 Tpace_Test Transmit Pacing Test Register ---*/
    volatile unsigned int  Rx_Pause;                              /*--- 0x05c Rx_Pause Receive Pause Timer Register ---*/
    volatile unsigned int  Tx_Pause ;                             /*--- 0x060 Tx_Pause Transmit Pause Timer Register ---*/
    volatile unsigned int  Port_VLAN;                             /*--- 0x064 Port_VLAN Port VLAN Register ---*/
    volatile unsigned int  Rx_Flowthresh ;                        /*--- 0x068 Rx_Flowthresh Receive Flow Threshold Register ---*/
    unsigned int reserved1[(0x1fc - 0x06c)/sizeof(unsigned int)]; /*---  reserved ---*/
    volatile unsigned int  RxGoodFramesRxGoodFrames;              /*--- 0x200 RxGoodFrames Total number of good frames received ---*/
    volatile unsigned int  RxBroadcastFrames;                     /*--- 0x204 RxBroadcastFrames Total number of good broadcast frames received ---*/
    volatile unsigned int  RxMulticastFrames;                     /*--- 0x208 RxMulticastFrames Total number of good multicast frames received ---*/
    volatile unsigned int  RxPauseFrames;                         /*--- 0x20c RxPauseFrames PauseRxFrames ---*/
    volatile unsigned int  RxCRCErrors;                           /*--- 0x210 RxCRCErrors Total number of frames received with CRC errors ---*/
    volatile unsigned int  RxAlignCodeErrors;                     /*--- 0x214 RxAlignCodeErrors Total number of frames received with alignment/code errors ---*/
    volatile unsigned int  RxOversizedFrames;                     /*--- 0x218 RxOversizedFrames Total number of oversized frames received ---*/
    volatile unsigned int  RxJabberFrames;                        /*--- 0x21c RxJabberFrames Total number of jabber frames received ---*/
    volatile unsigned int  RxUndersizedFrames;                    /*--- 0x220 RxUndersizedFrames Total number of undersized frames received ---*/
    volatile unsigned int  RxFragments;                           /*--- 0x224 RxFragments RxFragments received ---*/
    volatile unsigned int  RxFilteredFrames;                      /*--- 0x228 RxFilteredFrames FilteredRxFrames ---*/
    volatile unsigned int  reserved2;                             /*--- 0x22c reserved ---*/
    volatile unsigned int  RxOctets;                              /*--- 0x230 RxOctets Total number of received bytes in good frames ---*/
    volatile unsigned int  TxGoodFrames;                          /*--- 0x234 TxGoodFrames GoodTxFrames ---*/
    volatile unsigned int  TxBroadcastFrames;                     /*--- 0x238 TxBroadcastFrames BroadcastTxFrames ---*/
    volatile unsigned int  TxMulticastFrames;                     /*--- 0x23c TxMulticastFrames MulticastTxFrames ---*/
    volatile unsigned int  TxPauseFrames;                         /*--- 0x240 TxPauseFrames PauseTxFrames ---*/
    volatile unsigned int  TxDeferredFrames;                      /*--- 0x244 TxDeferredFrames Deferred Frames ---*/
    volatile unsigned int  TxCollisionFrames;                     /*--- 0x248 TxCollisionFrames Collisions ---*/
    volatile unsigned int  TxSingleCollFrames;                    /*--- 0x24c TxSingleCollFrames SingleCollisionTxFrames ---*/
    volatile unsigned int  TxMultCollFrames;                      /*--- 0x250 TxMultCollFrames MultipleCollisionTxFrames ---*/
    volatile unsigned int  TxExcessiveCollisions;                 /*--- 0x254 TxExcessiveCollisions ExcessiveCollisions ---*/
    volatile unsigned int  TxLateCollisions;                      /*--- 0x258 TxLateCollisions LateCollisions ---*/
    volatile unsigned int  TxUnderrun;                            /*--- 0x25c TxUnderrun Transmit Underrun Error ---*/
    volatile unsigned int  TxCarrierSenseErrors;                  /*--- 0x260 TxCarrierSenseErrors CarrierSenseErrors ---*/
    volatile unsigned int  TxOctets;                              /*--- 0x264 TxOctets TxOctets ---*/
    volatile unsigned int  _64octetFrames;                        /*--- 0x268 64octetFrames 64octetFrames ---*/
    volatile unsigned int  _65t127octetFrames;                    /*--- 0x26c 65t127octetFrames 65-127octetFrames ---*/
    volatile unsigned int  _128t255octetFrames;                   /*--- 0x270 128t255octetFrames 128-255octetFrames ---*/
    volatile unsigned int  _256t511octetFrames;                   /*--- 0x274 256t511octetFrames 256-511octetFrames ---*/
    volatile unsigned int  _512t1023octetFrames;                  /*--- 0x278 512t1023octetFrames 512-1023octetFrames ---*/
    volatile unsigned int  _1024tUPoctetFrames;                   /*--- 0x27c 1024tUPoctetFrames 1023-1518octetFrames ---*/
    volatile unsigned int  NetOctets;                             /*--- 0x280 NetOctets NetOctets ---*/
    volatile unsigned int  RxSofOverruns;                         /*--- 0x284 RxSofOverruns Receive FIFO or DMA Start of Frame Overruns ---*/
    volatile unsigned int  RxMofOverruns;                         /*--- 0x288 RxMofOverruns Receive FIFO or DMA Middle of Frame Overruns ---*/
    volatile unsigned int  RxDmaOverruns;                         /*--- 0x28c RxDmaOverruns Receive DMA Start of Frame and Middle of Frame Overruns ---*/
    unsigned int reserved3[(0x2fc - 0x290)/sizeof(unsigned int)]; /*---  reserved ---*/
    volatile unsigned int  RxFifoProcessor[(0x3fc - 0x300)/sizeof(unsigned int)]; /*--- 0x300-0x3fc RX FIFO Processor Test Access Only accessible when the memtest bit in the MacControl register is set (32-bit access only). ---*/
    volatile unsigned int  RxFifoProcessor[(0x4fc - 0x400)/sizeof(unsigned int)]; /*--- 0x4fc-0x400 TX FIFO Processor Test Access Only accessible when the memtest bit in the MacControl register is set (32-bit access only). ---*/
    volatile unsigned int  MacAddr_Lo;                            /*--- 0x500 ---*/
    volatile unsigned int  MacAddr_Hi;                            /*--- 0x504 ---*/
    volatile unsigned int  MacIndex;                              /*--- 0x508 ---*/
    unsigned int reserved4[(0x7fc - 0x508)/sizeof(unsigned int)]; /*---  reserved ---*/
};


#endif /*--- #ifndef _hw_cpgmac_h_ ---*/
