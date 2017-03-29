#if !defined(__ur8_tdm_h__)
#define __ur8_tdm_h__

/*--- TDM_SPCR ---*/
#define _TDM_SPCR_XINTM_MASK       0x00300000u
#define _TDM_SPCR_XINTM_SHIFT      0x00000014u
#define  TDM_SPCR_XINTM_XRDY       0x00000000u
#define  TDM_SPCR_XINTM_EOS        0x00000001u
#define  TDM_SPCR_XINTM_FRM        0x00000002u
#define  TDM_SPCR_XINTM_XSYNCERR   0x00000003u

#define _TDM_SPCR_XSYNCERR_MASK    0x00080000u
#define _TDM_SPCR_XSYNCERR_SHIFT   0x00000013u
#define  TDM_SPCR_XSYNCERR_NO      0x00000000u
#define  TDM_SPCR_XSYNCERR_0       0x00000000u
#define  TDM_SPCR_XSYNCERR_YES     0x00000001u
#define  TDM_SPCR_XSYNCERR_1       0x00000001u

#define _TDM_SPCR_XEMPTY_MASK      0x00040000u
#define _TDM_SPCR_XEMPTY_SHIFT     0x00000012u
#define  TDM_SPCR_XEMPTY_YES       0x00000000u
#define  TDM_SPCR_XEMPTY_0        0x00000000u
#define  TDM_SPCR_XEMPTY_NO        0x00000001u
#define  TDM_SPCR_XEMPTY_1         0x00000001u

#define _TDM_SPCR_XRDY_MASK        0x00020000u
#define _TDM_SPCR_XRDY_SHIFT       0x00000011u
#define  TDM_SPCR_XRDY_NO          0x00000000u
#define  TDM_SPCR_XRDY_YES         0x00000001u

#define _TDM_SPCR_XRST_MASK        0x00010000u
#define _TDM_SPCR_XRST_SHIFT       0x00000010u
#define  TDM_SPCR_XRST_YES         0x00000000u
#define  TDM_SPCR_XRST_0           0x00000000u
#define  TDM_SPCR_XRST_NO          0x00000001u
#define  TDM_SPCR_XRST_1           0x00000001u

#define _TDM_SPCR_RINTM_MASK       0x00000030u
#define _TDM_SPCR_RINTM_SHIFT      0x00000004u
#define  TDM_SPCR_RINTM_RRDY       0x00000000u
#define  TDM_SPCR_RINTM_EOS        0x00000001u
#define  TDM_SPCR_RINTM_FRM        0x00000002u
#define  TDM_SPCR_RINTM_RSYNCERR   0x00000003u

#define _TDM_SPCR_RSYNCERR_MASK    0x00000008u
#define _TDM_SPCR_RSYNCERR_SHIFT   0x00000003u
#define  TDM_SPCR_RSYNCERR_NO      0x00000000u
#define  TDM_SPCR_RSYNCERR_0       0x00000000u
#define  TDM_SPCR_RSYNCERR_YES     0x00000001u
#define  TDM_SPCR_RSYNCERR_1       0x00000001u

#define _TDM_SPCR_RFULL_MASK       0x00000004u
#define _TDM_SPCR_RFULL_SHIFT      0x00000002u
#define  TDM_SPCR_RFULL_NO         0x00000000u
#define  TDM_SPCR_RFULL_YES        0x00000001u

#define _TDM_SPCR_RRDY_MASK        0x00000002u
#define _TDM_SPCR_RRDY_SHIFT       0x00000001u
#define  TDM_SPCR_RRDY_NO          0x00000000u
#define  TDM_SPCR_RRDY_YES         0x00000001u

#define _TDM_SPCR_RRST_MASK        0x00000001u
#define _TDM_SPCR_RRST_SHIFT       0x00000000u 
#define  TDM_SPCR_RRST_YES         0x00000000u
#define  TDM_SPCR_RRST_0           0x00000000u
#define  TDM_SPCR_RRST_NO          0x00000001u
#define  TDM_SPCR_RRST_1           0x00000001u

/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
union _TDM_SPCR {
    volatile unsigned int Register;
    struct __TDM_SPCR {
        /*--- McBSP page 12-10 ---*/ 
        volatile unsigned int _RRST      : 1;    /*--- 0 receiver reset  and enable 1-> enable ---*/ 
        volatile unsigned int RRDY       : 1;    /*--- 1 receiver ready ---*/
        volatile unsigned int RFULL      : 1;    /*--- 2 receive shift register full error condition ---*/
        volatile unsigned int RSYNCERR   : 1;    /*--- 3 frame sync error detected ---*/
        volatile unsigned int RINTM      : 2;    /*--- 4,5 Receive interrupt mode---*/
        volatile unsigned int Reserved0  : 8;    /*--- 6 ---*/
        volatile unsigned int _XRST      : 1;    /*--- 16 transmitter reset and enable 1-> enable ---*/
        volatile unsigned int XRDY       : 1;    /*--- 17 transmitter ready ---*/
        volatile unsigned int _XEMPTY    : 1;    /*--- 18 transmit shift register (XSR) empty ---*/
        volatile unsigned int XSYNCERR   : 1;    /*--- 19 transmit sync error ---*/
        volatile unsigned int XINTM      : 2;    /*--- 20,21 transmit interrupt mode ---*/
        volatile unsigned int Reserved1  : 10;    /*--- 22,23,24,25,26,27,28,29,30,31 ---*/
    } Bits;
};

/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
#define TDM_CR_WDLEN_8BIT       0
#define TDM_CR_WDLEN_12BIT      1
#define TDM_CR_WDLEN_16BIT      2
#define TDM_CR_WDLEN_20BIT      3
#define TDM_CR_WDLEN_24BIT      4
#define TDM_CR_WDLEN_32BIT      5

#define _TDM_CR_FLEN_SHIFT        8
#define _TDM_CR_WDLEN_SHIFT       5
#define _TDM_CR_MUSTBE_ONE        (1 << 16)

/*-------------------------------------------------------------------------------------*\
 * TDM_RCR
    SmartCalc-CAPITERM:
 RCR_WDLEN =S:5,7
 RCR_FLEN =S:8,14
 Rsvd1 =S:20,31
\*-------------------------------------------------------------------------------------*/
union _TDM_RCR {
    volatile unsigned int Register;
    struct __TDM_RCR{ 
        volatile unsigned int Rsvd1:5;
        volatile unsigned int RWDLEN:3;
        volatile unsigned int RFRLEN:7;
        volatile unsigned int SetToOne:1;   /*--- should be set to 1 !! ---*/
        volatile unsigned int Rsvd2:16;
    }Bits;
};

/*--------------------------------------------------------------------------------*\
 * TDM_XCR
\*--------------------------------------------------------------------------------*/
union _TDM_XCR {
    volatile unsigned int Register;
    struct __mcBSP_XCR { 
        /*--- McBSP page 12-13 ---*/ 
        volatile unsigned int Rsvd1:5;
        volatile unsigned int XWDLEN:3;
        volatile unsigned int XFRLEN:7;
        volatile unsigned int SetToOne:1;
        volatile unsigned int Rsvd2:16;
    }Bits;
};
/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
union  _TDM_PCMCR1 {
    volatile unsigned int Register;
    struct __TDM_PCMCR1 {
        volatile unsigned int PCM_CLK_DIV:12;
        volatile unsigned int Reserved0:4;
        volatile unsigned int PCM_FS_PER:14;
        volatile unsigned int Reserved1:2;
    }Bits;
};
#define TDM_PCMCR2_PSEL_EXTERNAL        (0 << 0)
#define TDM_PCMCR2_PSEL_INTERNAL        (1 << 0)
#define TDM_PCMCR2_CDIR_EXTERNAL        (1 << 1)
#define TDM_PCMCR2_CDIR_INTERNAL        (0 << 1)
#define TDM_PCMCR2_FDIR_EXTERNAL        (1 << 2)
#define TDM_PCMCR2_FDIR_INTERNAL        (0 << 2)
/*--------------------------------------------------------------------------------*\
    SmartCalc-CAPITERM:
 PSEL =S:0,0
 CDIR =S:1,1
 FDIR =S:2,2
 CR   =S:3,3
\*--------------------------------------------------------------------------------*/
union  _TDM_PCMCR2 {
    volatile unsigned int Register;
    struct __TDM_PCMCR2 {
        volatile unsigned int PSEL:1;
        volatile unsigned int CDIR:1;
        volatile unsigned int FDIR:1;
        volatile unsigned int CR:1;
        volatile unsigned int Reserved:28;
    }Bits;
};

/*-------------------------------------------------------------------------------------*\
 * DMA-Part
\*-------------------------------------------------------------------------------------*/
struct  _TDM_TransferLength {
    volatile unsigned int ElementNmb:16;
    volatile unsigned int Reserved:16;
};

/*-------------------------------------------------------------------------------------*\
SmartCalc-CAPITERM:
Transfer_Control_Stop_ElementSize=S:1,0
Transfer_Control_Stop_IrqOnError=S:2,2
Transfer_Control_Stop_Load=S:3,3
Transfer_Control_DMA_Start=S:31,31
\*-------------------------------------------------------------------------------------*/
union  _TDM_TransferControl {
    volatile unsigned int Register;
    struct __TDM_TransferControl {
        volatile unsigned int ElementSize:2;
        volatile unsigned int IrqOnError:1;
        volatile unsigned int StopReload:1;
        volatile unsigned int Rsvd:27;
        volatile unsigned int DMAStart:1;
    }Bits;
};
/*-------------------------------------------------------------------------------------*\
SmartCalc-CAPITERM:
TransferStatus_TransferCount=S:0,15
TransferStatus_DMABusy=S:16,16
TransferStatus_Empty=S:17,17
TransferStatus_Full=S:18,18
TransferStatus_RxError=S:19,19
\*-------------------------------------------------------------------------------------*/
union  _TDM_DMAStatus {
 volatile unsigned int Register;
 struct __TDM_DMAStatus {
     volatile unsigned int TransferCount:16;
     volatile unsigned int DMA_Busy:1;
     volatile unsigned int FIFO_Empty:1;
     volatile unsigned int FIFO_Full:1;
     volatile unsigned int RxTxError:1;
     volatile unsigned int Rsvd:12;
 } Bits;
};
/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
struct _TDM_DMA {
    volatile unsigned int TDM_SRCADDR;             /*--- Rx: only R == DRR ---*/
    volatile unsigned int TDM_DESTADDR;            /*--- Tx: only R == DXR ---*/
    struct _TDM_TransferLength  TDM_TransferLength; 
    union _TDM_TransferControl  TDM_TransferControl; 
    volatile unsigned int TDM_SRCADDR_Reload;          /*--- Rx: only R == DRR ---*/
    volatile unsigned int TDM_DESTADDR_Reload;         /*--- Tx: only R == DXR ---*/
    struct  _TDM_TransferLength TDM_TransferLength_Reload; 
    union _TDM_TransferControl  TDM_TransferControl_Reload; 
    union _TDM_DMAStatus  TDM_DMAStatus; 
};
/*-------------------------------------------------------------------------------------*\
 * der Adressraum TDM: beginnend ab UR8_TDM_BASE
\*-------------------------------------------------------------------------------------*/
struct _TDM {
    volatile unsigned int TDM_DRR_ADDR;     /*--- 0x0  ---*/
    volatile unsigned int TDM_DXR_ADDR;     /*--- 0x4  ---*/
    union _TDM_SPCR TDM_SPCR_ADDR;          /*--- 0x8  ---*/
    union _TDM_RCR  TDM_RCR_ADDR;           /*--- 0xC  ---*/
    union _TDM_RCR  TDM_XCR_ADDR;           /*--- 0x10 ---*/
    unsigned int Reserved1[11];        
    struct _TDM_DMA TDM_RxDMA;              /*--- 0x40 ---*/
    unsigned int Reserved2[7];        
    struct _TDM_DMA TDM_TxDMA;              /*--- 0x80 ---*/
    unsigned int Reserved3[7];        
    union  _TDM_PCMCR1 TDM_PCMCR1;          /*--- 0xC0 ---*/
    union  _TDM_PCMCR2 TDM_PCMCR2;          /*--- 0xC4 ---*/
};

#endif/*--- #if !defined(__ur8_tdm_h__) ---*/
