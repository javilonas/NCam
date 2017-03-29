#if !defined(__ur8_mcbsp_h__)
#define __ur8_mcbsp_h__

/******************************************************************************\
* _____________________
* |                   |
* |  S P C R          |
* |___________________|
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) FREE (2)
* (rw) SOFT (2)
* (rw) FRST
* (rw) GRST
* (rw) XINTM
* (rw) XSYNCERR
* (r)  XEMPTY
* (r)  XRDY
* (rw) XRST
* (rw) DLB
* (rw) RJUST
* (rw) CLKSTP
* (rw) DXENA (2)
* (rw) RINTM
* (rw) RSYNCERR
* (r)  RFULL
* (r)  RRDY
* (rw) RRST
*
* (2) - C11_SUPPORT/C64_SUPPORT/C6713 only
*
\******************************************************************************/
  #define _MCBSP_SPCR_FRST_MASK        0x00800000u
  #define _MCBSP_SPCR_FRST_SHIFT       0x00000017u
  #define  MCBSP_SPCR_FRST_YES         0x00000000u
  #define  MCBSP_SPCR_FRST_0           0x00000000u
  #define  MCBSP_SPCR_FRST_NO          0x00000001u
  #define  MCBSP_SPCR_FRST_1           0x00000001u

  #define _MCBSP_SPCR_GRST_MASK        0x00400000u
  #define _MCBSP_SPCR_GRST_SHIFT       0x00000016u
  #define  MCBSP_SPCR_GRST_YES         0x00000000u
  #define  MCBSP_SPCR_GRST_0           0x00000000u
  #define  MCBSP_SPCR_GRST_NO          0x00000001u
  #define  MCBSP_SPCR_GRST_1           0x00000001u

  #define _MCBSP_SPCR_XINTM_MASK       0x00300000u
  #define _MCBSP_SPCR_XINTM_SHIFT      0x00000014u
  #define  MCBSP_SPCR_XINTM_XRDY       0x00000000u
  #define  MCBSP_SPCR_XINTM_EOS        0x00000001u
  #define  MCBSP_SPCR_XINTM_FRM        0x00000002u
  #define  MCBSP_SPCR_XINTM_XSYNCERR   0x00000003u

  #define _MCBSP_SPCR_XSYNCERR_MASK    0x00080000u
  #define _MCBSP_SPCR_XSYNCERR_SHIFT   0x00000013u
  #define  MCBSP_SPCR_XSYNCERR_NO      0x00000000u
  #define  MCBSP_SPCR_XSYNCERR_0       0x00000000u
  #define  MCBSP_SPCR_XSYNCERR_YES     0x00000001u
  #define  MCBSP_SPCR_XSYNCERR_1       0x00000001u

  #define _MCBSP_SPCR_XEMPTY_MASK      0x00040000u
  #define _MCBSP_SPCR_XEMPTY_SHIFT     0x00000012u
  #define  MCBSP_SPCR_XEMPTY_YES       0x00000000u
  #define  MCBSP_SPCR_XEMPTY_0        0x00000000u
  #define  MCBSP_SPCR_XEMPTY_NO        0x00000001u
  #define  MCBSP_SPCR_XEMPTY_1         0x00000001u

  #define _MCBSP_SPCR_XRDY_MASK        0x00020000u
  #define _MCBSP_SPCR_XRDY_SHIFT       0x00000011u
  #define  MCBSP_SPCR_XRDY_NO          0x00000000u
  #define  MCBSP_SPCR_XRDY_YES         0x00000001u

  #define _MCBSP_SPCR_XRST_MASK        0x00010000u
  #define _MCBSP_SPCR_XRST_SHIFT       0x00000010u
  #define  MCBSP_SPCR_XRST_YES         0x00000000u
  #define  MCBSP_SPCR_XRST_0           0x00000000u
  #define  MCBSP_SPCR_XRST_NO          0x00000001u
  #define  MCBSP_SPCR_XRST_1           0x00000001u

  #define _MCBSP_SPCR_DLB_MASK         0x00008000u
  #define _MCBSP_SPCR_DLB_SHIFT        0x0000000Fu
  #define  MCBSP_SPCR_DLB_OFF          0x00000000u
  #define  MCBSP_SPCR_DLB_ON           0x00000001u

  #define _MCBSP_SPCR_RJUST_MASK       0x00006000u
  #define _MCBSP_SPCR_RJUST_SHIFT      0x0000000Du
  #define  MCBSP_SPCR_RJUST_RZF        0x00000000u
  #define  MCBSP_SPCR_RJUST_RSE        0x00000001u
  #define  MCBSP_SPCR_RJUST_LZF        0x00000002u

  #define _MCBSP_SPCR_CLKSTP_MASK      0x00001800u
  #define _MCBSP_SPCR_CLKSTP_SHIFT     0x0000000Bu
  #define  MCBSP_SPCR_CLKSTP_DISABLE   0x00000000u
  #define  MCBSP_SPCR_CLKSTP_NODELAY   0x00000002u
  #define  MCBSP_SPCR_CLKSTP_DELAY     0x00000003u

  #define _MCBSP_SPCR_RINTM_MASK       0x00000030u
  #define _MCBSP_SPCR_RINTM_SHIFT      0x00000004u
  #define  MCBSP_SPCR_RINTM_RRDY       0x00000000u
  #define  MCBSP_SPCR_RINTM_EOS        0x00000001u
  #define  MCBSP_SPCR_RINTM_FRM        0x00000002u
  #define  MCBSP_SPCR_RINTM_RSYNCERR   0x00000003u

  #define _MCBSP_SPCR_RSYNCERR_MASK    0x00000008u
  #define _MCBSP_SPCR_RSYNCERR_SHIFT   0x00000003u
  #define  MCBSP_SPCR_RSYNCERR_NO      0x00000000u
  #define  MCBSP_SPCR_RSYNCERR_0       0x00000000u
  #define  MCBSP_SPCR_RSYNCERR_YES     0x00000001u
  #define  MCBSP_SPCR_RSYNCERR_1       0x00000001u

  #define _MCBSP_SPCR_RFULL_MASK       0x00000004u
  #define _MCBSP_SPCR_RFULL_SHIFT      0x00000002u
  #define  MCBSP_SPCR_RFULL_NO         0x00000000u
  #define  MCBSP_SPCR_RFULL_YES        0x00000001u

  #define _MCBSP_SPCR_RRDY_MASK        0x00000002u
  #define _MCBSP_SPCR_RRDY_SHIFT       0x00000001u
  #define  MCBSP_SPCR_RRDY_NO          0x00000000u
  #define  MCBSP_SPCR_RRDY_YES         0x00000001u

  #define _MCBSP_SPCR_RRST_MASK        0x00000001u
  #define _MCBSP_SPCR_RRST_SHIFT       0x00000000u 
  #define  MCBSP_SPCR_RRST_YES         0x00000000u
  #define  MCBSP_SPCR_RRST_0           0x00000000u
  #define  MCBSP_SPCR_RRST_NO          0x00000001u
  #define  MCBSP_SPCR_RRST_1           0x00000001u

/*-------------------------------------------------------------------------------------*\
SmartCalc-CAPITERM:
SPCR_RRst=S:0,0
SPCR_RRdy=S:1,1
SPCR_RFull=S:2,2
SPCR_SynErr=S:3,3
SPCR_RIntm=S:4,5
SPCR_DxEna=S:7,7
SPCR_ClkStp=S:11,12
SPCR_RJust=S:13,14
SPCR_Dlb=S:15,15
SPCR_XRst=S:16,16
SPCR_XRdy=S:17,17
SPCR_XEmpty=S:18,18
SPCR_XSyncErr=S:19,19
SPCR_XIntm=S:21,20
SPCR_GRST=S:22,22
SPCR_Frst=S:23,23
SPCR_Soft=S:24,24
SPCR_Free=S:25,25
\*-------------------------------------------------------------------------------------*/
union _McBSP_SPCR {
    volatile unsigned int Register;
    struct __McBSP_SPCR {
        /*--- McBSP page 12-10 ---*/ 
        volatile unsigned int _RRST      : 1;    /*--- 0 receiver reset  and enable 1-> enable ---*/ 
        volatile unsigned int RRDY       : 1;    /*--- 1 receiver ready ---*/
        volatile unsigned int RFULL      : 1;    /*--- 2 receive shift register full error condition ---*/
        volatile unsigned int RSYNCERR   : 1;    /*--- 3 frame sync error detected ---*/
        volatile unsigned int RINTM      : 2;    /*--- 4,5 Receive interrupt mode---*/
        volatile unsigned int Reserved0  : 1;    /*--- 6 ---*/
        volatile unsigned int DXENA      : 1;    /*--- 7  DX Enabler ---*/
        volatile unsigned int Reserved1  : 3;    /*--- 8,9,10 ---*/
        volatile unsigned int CLKSTP     : 2;    /*--- 11,12 Clock Stop Mode ---*/
        volatile unsigned int RJUST     : 2;    /*--- 13,14 receive data sign extension and justification mode ---*/
        volatile unsigned int DLB        : 1;    /*--- 15 digital loopbackmode  ---*/
        volatile unsigned int _XRST      : 1;    /*--- 16 transmitter reset and enable 1-> enable ---*/
        volatile unsigned int XRDY       : 1;    /*--- 17 transmitter ready ---*/
        volatile unsigned int _XEMPTY    : 1;    /*--- 18 transmit shift register (XSR) empty ---*/
        volatile unsigned int XSYNCERR   : 1;    /*--- 19 transmit sync error ---*/
        volatile unsigned int XINTM      : 2;    /*--- 20,21 transmit interrupt mode ---*/
        volatile unsigned int _GRST      : 1;    /*--- 22    sample rate generator reset ---*/
        volatile unsigned int _FRST      : 1;    /*--- 23    frame sync generator reset ---*/
        volatile unsigned int SOFT       : 1;    /*--- 24    serial clock emulation mode ---*/
        volatile unsigned int FREE       : 1;    /*--- 25    serial clock free running mode ---*/
        volatile unsigned int Reserved2  : 6;    /*--- 26,27,28,29,30,31 ---*/
    } Bits;
};

/******************************************************************************\
* _____________________
* |                   |
* |  P C R            |
* |___________________|
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) XIOEN
* (rw) RIOEN
* (rw) FSXM
* (rw) FSRM
* (rw) CLKXM
* (rw) CLKRM
* (rw) CLKSSTAT
* (rw) DXSTAT
* (r)  DRSTAT
* (rw) FSXP
* (rw) FSRP
* (rw) CLKXP
* (rw) CLKRP
*
\******************************************************************************/
  #define _MCBSP_PCR_XIOEN_MASK        0x00002000u
  #define _MCBSP_PCR_XIOEN_SHIFT       0x0000000Du
  #define  MCBSP_PCR_XIOEN_SP          0x00000000u
  #define  MCBSP_PCR_XIOEN_GPIO        0x00000001u

  #define _MCBSP_PCR_RIOEN_MASK        0x00001000u
  #define _MCBSP_PCR_RIOEN_SHIFT       0x0000000Cu
  #define  MCBSP_PCR_RIOEN_SP          0x00000000u
  #define  MCBSP_PCR_RIOEN_GPIO        0x00000001u

  #define _MCBSP_PCR_FSXM_MASK         0x00000800u
  #define _MCBSP_PCR_FSXM_SHIFT        0x0000000Bu
  #define  MCBSP_PCR_FSXM_EXTERNAL     0x00000000u
  #define  MCBSP_PCR_FSXM_INTERNAL     0x00000001u

  #define _MCBSP_PCR_FSRM_MASK         0x00000400u
  #define _MCBSP_PCR_FSRM_SHIFT        0x0000000Au
  #define  MCBSP_PCR_FSRM_EXTERNAL     0x00000000u
  #define  MCBSP_PCR_FSRM_INTERNAL     0x00000001u

  #define _MCBSP_PCR_CLKXM_MASK        0x00000200u
  #define _MCBSP_PCR_CLKXM_SHIFT       0x00000009u
  #define  MCBSP_PCR_CLKXM_INPUT       0x00000000u
  #define  MCBSP_PCR_CLKXM_OUTPUT      0x00000001u

  #define _MCBSP_PCR_CLKRM_MASK        0x00000100u
  #define _MCBSP_PCR_CLKRM_SHIFT       0x00000008u
  #define  MCBSP_PCR_CLKRM_INPUT       0x00000000u
  #define  MCBSP_PCR_CLKRM_OUTPUT      0x00000001u

  #define _MCBSP_PCR_CLKSSTAT_MASK     0x00000040u
  #define _MCBSP_PCR_CLKSSTAT_SHIFT    0x00000006u
  #define  MCBSP_PCR_CLKSSTAT_0        0x00000000u
  #define  MCBSP_PCR_CLKSSTAT_1        0x00000001u

  #define _MCBSP_PCR_DXSTAT_MASK       0x00000020u
  #define _MCBSP_PCR_DXSTAT_SHIFT      0x00000005u
  #define  MCBSP_PCR_DXSTAT_0          0x00000000u
  #define  MCBSP_PCR_DXSTAT_1          0x00000001u

  #define _MCBSP_PCR_DRSTAT_MASK       0x00000010u
  #define _MCBSP_PCR_DRSTAT_SHIFT      0x00000004u
  #define  MCBSP_PCR_DRSTAT_0          0x00000000u
  #define  MCBSP_PCR_DRSTAT_1          0x00000001u

  #define _MCBSP_PCR_FSXP_MASK         0x00000008u
  #define _MCBSP_PCR_FSXP_SHIFT        0x00000003u
  #define  MCBSP_PCR_FSXP_ACTIVEHIGH   0x00000000u
  #define  MCBSP_PCR_FSXP_ACTIVELOW    0x00000001u

  #define _MCBSP_PCR_FSRP_MASK         0x00000004u
  #define _MCBSP_PCR_FSRP_SHIFT        0x00000002u
  #define  MCBSP_PCR_FSRP_ACTIVEHIGH   0x00000000u
  #define  MCBSP_PCR_FSRP_ACTIVELOW    0x00000001u

  #define _MCBSP_PCR_CLKXP_MASK        0x00000002u
  #define _MCBSP_PCR_CLKXP_SHIFT       0x00000001u
  #define  MCBSP_PCR_CLKXP_RISING      0x00000000u
  #define  MCBSP_PCR_CLKXP_FALLING     0x00000001u

  #define _MCBSP_PCR_CLKRP_MASK        0x00000001u
  #define _MCBSP_PCR_CLKRP_SHIFT       0x00000000u
  #define  MCBSP_PCR_CLKRP_FALLING     0x00000000u
  #define  MCBSP_PCR_CLKRP_RISING      0x00000001u
/*-------------------------------------------------------------------------------------*\
    SmartCalc-CAPITERM:
PCR_CLKRP=S:0,0
PCR_CLKXP=S:1,1 
PCR_FSRP=S:2,2 
PCR_FSXP=S:3,3  
PCR_DRSTAT=S:4,4
PCR_DXSTAT=S:5,5
PCR_CLKS_STAT=S:6,6
PCR_CLKRM=S:8,8 
PCR_CLKXM=S:9,9 
PCR_FSRM=S:10,10  
PCR_FSXM=S:11,11  
PCR_RIOEN=S:12,12 
PCR_XIOEN=S:13,13 
\*-------------------------------------------------------------------------------------*/
union _McBSP_PCR {
    volatile unsigned int Register;
    struct __McBSP_PCR { 
        /*--- McBSP page 12-11 ---*/ 
        volatile unsigned int CLKRP:1;      /*--- receive clock polarity ---*/ 
        volatile unsigned int CLKXP:1;      /*--- transmit clock polarity ---*/ 
        volatile unsigned int FSRP:1;       /*--- receive frame sync polarity ---*/ 
        volatile unsigned int FSXP:1;       /*--- receive frame sync polarity ---*/ 
        volatile unsigned int DRSTAT:1;     /*--- DR Pin when GPIO in ---*/ 
        volatile unsigned int DXSTAT:1;     /*--- DX Pin when GPIO out ---*/ 
        volatile unsigned int CLKS_STAT:1;  /*--- CLKS Pin when GPIO in ---*/ 
        volatile unsigned int Rsvd1:1;
        volatile unsigned int CLKRM:1;      /*--- receiver clock mode ---*/
        volatile unsigned int CLKXM:1;      /*--- transmit clock mode ---*/
        volatile unsigned int FSRM:1;       /*--- receive frame sync mode ---*/
        volatile unsigned int FSXM:1;       /*--- transmit frame sync mode ---*/
        volatile unsigned int RIOEN:1;      /*--- receiver in GPIO mode ... ---*/
        volatile unsigned int XIOEN:1;      /*--- transmitter in GPIO mode ... ---*/
        volatile unsigned int Rsvd2:18;
    } Bits;
};

/******************************************************************************\
* _____________________
* |                   |
* |  R C R            |
* |___________________|
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) RPHASE 
* (rw) RFRLEN2
* (rw) RWDLEN2
* (rw) RCOMPAND
* (rw) RFIG
* (rw) RDATDLY
* (rw) RFRLEN1
* (rw) RWDLEN1
* (rw) RWDREVRS (2)
*
* (2) - C11_SUPPORT / C64_SUPPORT/ C6713 only
*
\******************************************************************************/
  #define _MCBSP_RCR_RPHASE_MASK       0x80000000u
  #define _MCBSP_RCR_RPHASE_SHIFT      0x0000001Fu
  #define  MCBSP_RCR_RPHASE_SINGLE     0x00000000u
  #define  MCBSP_RCR_RPHASE_DUAL       0x00000001u

  #define _MCBSP_RCR_RFRLEN2_MASK      0x7F000000u
  #define _MCBSP_RCR_RFRLEN2_SHIFT     0x00000018u

  #define _MCBSP_RCR_RWDLEN2_MASK      0x00E00000u
  #define _MCBSP_RCR_RWDLEN2_SHIFT     0x00000015u
  #define  MCBSP_RCR_RWDLEN2_8BIT      0x00000000u
  #define  MCBSP_RCR_RWDLEN2_12BIT     0x00000001u
  #define  MCBSP_RCR_RWDLEN2_16BIT     0x00000002u
  #define  MCBSP_RCR_RWDLEN2_20BIT     0x00000003u
  #define  MCBSP_RCR_RWDLEN2_24BIT     0x00000004u
  #define  MCBSP_RCR_RWDLEN2_32BIT     0x00000005u

  #define _MCBSP_RCR_RCOMPAND_MASK     0x00180000u
  #define _MCBSP_RCR_RCOMPAND_SHIFT    0x00000013u
  #define  MCBSP_RCR_RCOMPAND_MSB      0x00000000u
  #define  MCBSP_RCR_RCOMPAND_8BITLSB  0x00000001u
  #define  MCBSP_RCR_RCOMPAND_ULAW     0x00000002u
  #define  MCBSP_RCR_RCOMPAND_ALAW     0x00000003u

  #define _MCBSP_RCR_RFIG_MASK         0x00040000u
  #define _MCBSP_RCR_RFIG_SHIFT        0x00000012u
  #define  MCBSP_RCR_RFIG_NO           0x00000000u
  #define  MCBSP_RCR_RFIG_YES          0x00000001u

  #define _MCBSP_RCR_RDATDLY_MASK      0x00030000u
  #define _MCBSP_RCR_RDATDLY_SHIFT     0x00000010u
  #define  MCBSP_RCR_RDATDLY_0BIT      0x00000000u
  #define  MCBSP_RCR_RDATDLY_1BIT      0x00000001u
  #define  MCBSP_RCR_RDATDLY_2BIT      0x00000002u

  #define _MCBSP_RCR_RFRLEN1_MASK      0x00007F00u
  #define _MCBSP_RCR_RFRLEN1_SHIFT     0x00000008u

  #define _MCBSP_RCR_RWDLEN1_MASK      0x000000E0u
  #define _MCBSP_RCR_RWDLEN1_SHIFT     0x00000005u
  #define  MCBSP_RCR_RWDLEN1_8BIT      0x00000000u
  #define  MCBSP_RCR_RWDLEN1_12BIT     0x00000001u
  #define  MCBSP_RCR_RWDLEN1_16BIT     0x00000002u
  #define  MCBSP_RCR_RWDLEN1_20BIT     0x00000003u
  #define  MCBSP_RCR_RWDLEN1_24BIT     0x00000004u
  #define  MCBSP_RCR_RWDLEN1_32BIT     0x00000005u

/*-------------------------------------------------------------------------------------*\
    SmartCalc-CAPITERM:
 RCR_RWDREVRS=S:4,4
 RCR_RWDLEN1 =S:5,7
 RCR_RFRLEN1 =S:8,14
 RCR_RDATDLY = S:16,17
 RCR_RFIG    = S:18,18
 RCR_RCOMPAND= S:19,20
 RCR_RWDLEN2 = S:21,23
 RCR_RFRLEN2 = S:24,30
 RCR_RPHASE  = S:31,31
\*-------------------------------------------------------------------------------------*/
union _McBSP_RCR {
    volatile unsigned int Register;
    struct __mcBSP_RCR{ 
        /*--- McBSP page 12-13 ---*/ 
        volatile unsigned int Rsvd1:4;
        volatile unsigned int RWDREVRS:1;
        volatile unsigned int RWDLEN1:3;
        volatile unsigned int RFRLEN1:7;
        volatile unsigned int Rsvd2:1;
        volatile unsigned int RDATDLY:2;
        volatile unsigned int RFIG:1;
        volatile unsigned int RCOMPAND:2;
        volatile unsigned int RWDLEN2:3;
        volatile unsigned int RFRLEN2:7;
        volatile unsigned int RPHASE:1;
    }Bits;
};

/******************************************************************************\
* _____________________
* |                   |
* |  X C R            |
* |___________________|
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) XPHASE 
* (rw) XFRLEN2
* (rw) XWDLEN2
* (rw) XCOMPAND
* (rw) XFIG
* (rw) XDATDLY 
* (rw) XFRLEN1
* (rw) XWDLEN1
* (rw) XWDREVRS (2)
*
* (2) - C11_SUPPORT /C64_SUPPORT/C6713 only
*
\******************************************************************************/
  #define _MCBSP_XCR_XPHASE_MASK       0x80000000u
  #define _MCBSP_XCR_XPHASE_SHIFT      0x0000001Fu
  #define  MCBSP_XCR_XPHASE_SINGLE     0x00000000u
  #define  MCBSP_XCR_XPHASE_DUAL       0x00000001u

  #define _MCBSP_XCR_XFRLEN2_MASK      0x7F000000u
  #define _MCBSP_XCR_XFRLEN2_SHIFT     0x00000018u

  #define _MCBSP_XCR_XWDLEN2_MASK      0x00E00000u
  #define _MCBSP_XCR_XWDLEN2_SHIFT     0x00000015u
  #define  MCBSP_XCR_XWDLEN2_8BIT      0x00000000u
  #define  MCBSP_XCR_XWDLEN2_12BIT     0x00000001u
  #define  MCBSP_XCR_XWDLEN2_16BIT     0x00000002u
  #define  MCBSP_XCR_XWDLEN2_20BIT     0x00000003u
  #define  MCBSP_XCR_XWDLEN2_24BIT     0x00000004u
  #define  MCBSP_XCR_XWDLEN2_32BIT     0x00000005u

  #define _MCBSP_XCR_XCOMPAND_MASK     0x00180000u
  #define _MCBSP_XCR_XCOMPAND_SHIFT    0x00000013u
  #define  MCBSP_XCR_XCOMPAND_MSB      0x00000000u
  #define  MCBSP_XCR_XCOMPAND_8BITLSB  0x00000001u
  #define  MCBSP_XCR_XCOMPAND_ULAW     0x00000002u
  #define  MCBSP_XCR_XCOMPAND_ALAW     0x00000003u

  #define _MCBSP_XCR_XFIG_MASK         0x00040000u
  #define _MCBSP_XCR_XFIG_SHIFT        0x00000012u
  #define  MCBSP_XCR_XFIG_NO           0x00000000u
  #define  MCBSP_XCR_XFIG_YES          0x00000001u

  #define _MCBSP_XCR_XDATDLY_MASK      0x00030000u
  #define _MCBSP_XCR_XDATDLY_SHIFT     0x00000010u
  #define  MCBSP_XCR_XDATDLY_0BIT      0x00000000u
  #define  MCBSP_XCR_XDATDLY_1BIT      0x00000001u
  #define  MCBSP_XCR_XDATDLY_2BIT      0x00000002u

  #define _MCBSP_XCR_XFRLEN1_MASK      0x00007F00u
  #define _MCBSP_XCR_XFRLEN1_SHIFT     0x00000008u

  #define _MCBSP_XCR_XWDLEN1_MASK      0x000000E0u
  #define _MCBSP_XCR_XWDLEN1_SHIFT     0x00000005u
  #define  MCBSP_XCR_XWDLEN1_8BIT      0x00000000u
  #define  MCBSP_XCR_XWDLEN1_12BIT     0x00000001u
  #define  MCBSP_XCR_XWDLEN1_16BIT     0x00000002u
  #define  MCBSP_XCR_XWDLEN1_20BIT     0x00000003u
  #define  MCBSP_XCR_XWDLEN1_24BIT     0x00000004u
  #define  MCBSP_XCR_XWDLEN1_32BIT     0x00000005u

/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
union _McBSP_XCR {
    volatile unsigned int Register;
    struct __mcBSP_XCR { 
        /*--- McBSP page 12-13 ---*/ 
        volatile unsigned int Rsvd1:4;
        volatile unsigned int XWDREVRS:1;
        volatile unsigned int XWDLEN1:3;
        volatile unsigned int XFRLEN1:7;
        volatile unsigned int Rsvd2:1;
        volatile unsigned int XDATDLY:2;
        volatile unsigned int XFIG:1;
        volatile unsigned int XCOMPAND:2;
        volatile unsigned int XWDLEN2:3;
        volatile unsigned int XFRLEN2:7;
        volatile unsigned int XPHASE:1;
    }Bits;
};

/******************************************************************************\
* _____________________
* |                   |
* |  M C R            |
* |___________________|
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) XMCME (1) 
* (rw) XPBBLK
* (rw) XPABLK
* (r)  XCBLK
* (rw) XMCM
* (rw) RMCME (1) 
* (rw) RPBBLK
* (rw) RPABLK
* (r)  RCBLK
* (rw) RMCM
*
* (1) C64_SUPPORT only 
\******************************************************************************/
  #define _MCBSP_MCR_XPBBLK_MASK       0x01800000u
  #define _MCBSP_MCR_XPBBLK_SHIFT      0x00000017u
  #define  MCBSP_MCR_XPBBLK_SF1        0x00000000u
  #define  MCBSP_MCR_XPBBLK_SF3        0x00000001u
  #define  MCBSP_MCR_XPBBLK_SF5        0x00000002u
  #define  MCBSP_MCR_XPBBLK_SF7        0x00000003u

  #define _MCBSP_MCR_XPABLK_MASK       0x00600000u
  #define _MCBSP_MCR_XPABLK_SHIFT      0x00000015u
  #define  MCBSP_MCR_XPABLK_SF0        0x00000000u
  #define  MCBSP_MCR_XPABLK_SF2        0x00000001u
  #define  MCBSP_MCR_XPABLK_SF4        0x00000002u
  #define  MCBSP_MCR_XPABLK_SF6        0x00000003u

  #define _MCBSP_MCR_XCBLK_MASK        0x001C0000u
  #define _MCBSP_MCR_XCBLK_SHIFT       0x00000012u
  #define  MCBSP_MCR_XCBLK_SF0         0x00000000u
  #define  MCBSP_MCR_XCBLK_SF1         0x00000001u
  #define  MCBSP_MCR_XCBLK_SF2         0x00000002u
  #define  MCBSP_MCR_XCBLK_SF3         0x00000003u
  #define  MCBSP_MCR_XCBLK_SF4         0x00000004u
  #define  MCBSP_MCR_XCBLK_SF5         0x00000005u
  #define  MCBSP_MCR_XCBLK_SF6         0x00000006u
  #define  MCBSP_MCR_XCBLK_SF7         0x00000007u

  #define _MCBSP_MCR_XMCM_MASK         0x00030000u
  #define _MCBSP_MCR_XMCM_SHIFT        0x00000010u
  #define  MCBSP_MCR_XMCM_ENNOMASK     0x00000000u
  #define  MCBSP_MCR_XMCM_DISXP        0x00000001u
  #define  MCBSP_MCR_XMCM_ENMASK       0x00000002u
  #define  MCBSP_MCR_XMCM_DISRP        0x00000003u


  #define _MCBSP_MCR_RPBBLK_MASK       0x00000180u
  #define _MCBSP_MCR_RPBBLK_SHIFT      0x00000007u
  #define  MCBSP_MCR_RPBBLK_SF1        0x00000000u
  #define  MCBSP_MCR_RPBBLK_SF3        0x00000001u
  #define  MCBSP_MCR_RPBBLK_SF5        0x00000002u
  #define  MCBSP_MCR_RPBBLK_SF7        0x00000003u

  #define _MCBSP_MCR_RPABLK_MASK       0x00000060u
  #define _MCBSP_MCR_RPABLK_SHIFT      0x00000005u
  #define  MCBSP_MCR_RPABLK_SF0        0x00000000u
  #define  MCBSP_MCR_RPABLK_SF2        0x00000001u
  #define  MCBSP_MCR_RPABLK_SF4        0x00000002u
  #define  MCBSP_MCR_RPABLK_SF6        0x00000003u

  #define _MCBSP_MCR_RCBLK_MASK        0x0000001Cu
  #define _MCBSP_MCR_RCBLK_SHIFT       0x00000002u
  #define  MCBSP_MCR_RCBLK_SF0         0x00000000u
  #define  MCBSP_MCR_RCBLK_SF1         0x00000001u
  #define  MCBSP_MCR_RCBLK_SF2         0x00000002u
  #define  MCBSP_MCR_RCBLK_SF3         0x00000003u
  #define  MCBSP_MCR_RCBLK_SF4         0x00000004u
  #define  MCBSP_MCR_RCBLK_SF5         0x00000005u
  #define  MCBSP_MCR_RCBLK_SF6         0x00000006u
  #define  MCBSP_MCR_RCBLK_SF7         0x00000007u

  #define _MCBSP_MCR_RMCM_MASK         0x00000001u
  #define _MCBSP_MCR_RMCM_SHIFT        0x00000000u
  #define  MCBSP_MCR_RMCM_CHENABLE     0x00000000u
  #define  MCBSP_MCR_RMCM_ELDISABLE    0x00000001u

/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
union _McBSP_MCR {
    volatile unsigned int Register;
    struct __McBSP_MCR {
        volatile unsigned int RMCM        : 1; /*--- 0 ---*/
        volatile unsigned int RCBLK       : 3; /*--- 2,3,4 ---*/
        volatile unsigned int RPABLK      : 2; /*--- 5,6 ---*/
        volatile unsigned int RPBBLK      : 2; /*--- 7,8 ---*/
        volatile unsigned int RMCME       : 1; /*--- 9 ---*/
        volatile unsigned int Reserved0   : 6; /*--- 10,11,12,13,14,15 ---*/
        volatile unsigned int XMCM        : 2; /*--- 16,17 ---*/
        volatile unsigned int XCBLK       : 3; /*--- 18,19,20 ---*/
        volatile unsigned int XPABLK      : 2; /*--- 21,22 ---*/
        volatile unsigned int XPBBLK      : 2; /*--- 23,24 ---*/
        volatile unsigned int XMCME       : 1; /*--- 25 ---*/
        volatile unsigned int Reserved1   : 6; /*--- 26-31 ---*/
    } Bits;
};

/******************************************************************************\
* _____________________
* |                   |
* |  S R G R          |
* |___________________|
*
* (1) only supported on devices with three serial ports
*
* FIELDS (msb -> lsb)
* (rw) GSYNC
* (rw) CLKSP
* (rw) CLKSM
* (rw) FSGM
* (rw) FPER
* (rw) FWID
* (rw) CLKGDV
*
\******************************************************************************/
  #define _MCBSP_SRGR_GSYNC_MASK       0x80000000u
  #define _MCBSP_SRGR_GSYNC_SHIFT      0x0000001Fu
  #define  MCBSP_SRGR_GSYNC_FREE       0x00000000u
  #define  MCBSP_SRGR_GSYNC_SYNC       0x00000001u

  #define _MCBSP_SRGR_CLKSP_MASK       0x40000000u
  #define _MCBSP_SRGR_CLKSP_SHIFT      0x0000001Eu
  #define  MCBSP_SRGR_CLKSP_RISING     0x00000000u
  #define  MCBSP_SRGR_CLKSP_FALLING    0x00000001u

  #define _MCBSP_SRGR_CLKSM_MASK       0x20000000u
  #define _MCBSP_SRGR_CLKSM_SHIFT      0x0000001Du
  #define  MCBSP_SRGR_CLKSM_CLKS       0x00000000u
  #define  MCBSP_SRGR_CLKSM_INTERNAL   0x00000001u

  #define _MCBSP_SRGR_FSGM_MASK        0x10000000u
  #define _MCBSP_SRGR_FSGM_SHIFT       0x0000001Cu
  #define  MCBSP_SRGR_FSGM_DXR2XSR     0x00000000u
  #define  MCBSP_SRGR_FSGM_FSG         0x00000001u

  #define _MCBSP_SRGR_FPER_MASK        0x0FFF0000u
  #define _MCBSP_SRGR_FPER_SHIFT       0x00000010u

  #define _MCBSP_SRGR_FWID_MASK        0x0000FF00u
  #define _MCBSP_SRGR_FWID_SHIFT       0x00000008u

  #define _MCBSP_SRGR_CLKGDV_MASK      0x000000FFu
  #define _MCBSP_SRGR_CLKGDV_SHIFT     0x00000000u

/*--------------------------------------------------------------------------------*\
SmartCalc-CAPITERM:
SRGR_CLKDV=S:0,7;
SRGR_FWID=S:8,15;
SRGR_FPER=S:16,27;
SRGR_FSGM=S:28,28;
SRGR_CLKSM=S:29,29; 
SRGR_CLKSP=S:30,30;
SRGR_GSYNC=S:31,31;
\*--------------------------------------------------------------------------------*/
union _McBSP_SRGR {
    volatile unsigned int Register;
    struct __McBSP_SRGR { 
        /*--- McBSP page 12-50 ---*/ 
        volatile unsigned int CLKDV:8; /*--- clock divdier ---*/ 
        volatile unsigned int FWID:8;  /*--- frame width ---*/
        volatile unsigned int FPER:12; /*--- frame period ---*/
        volatile unsigned int FSGM:1; /*--- trasnmit frame sync  mode  ---*/
        volatile unsigned int CLKSM:1; /*--- clock mode  ---*/
        volatile unsigned int CLKSP:1; /*--- polarity cleock edge select  ---*/
        volatile unsigned int GSYNC:1; /*--- clock syncronistaion  ---*/
    }Bits;
};

/*-------------------------------------------------------------------------------------*\
 * der Adressraum MCSP: beginnend ab UR8_MCSP_BASE
 *  struct _McBSP *McBSP =  (struct _McBSP *)UR8_MCSP_BASE;
\*-------------------------------------------------------------------------------------*/
struct _McBSP {
    volatile unsigned int MCBSP_DRR_ADDR;
    volatile unsigned int MCBSP_DXR_ADDR;
    union _McBSP_SPCR MCBSP_SPCR_ADDR;
    union _McBSP_RCR MCBSP_RCR_ADDR;
    union _McBSP_XCR MCBSP_XCR_ADDR;
    union _McBSP_SRGR MCBSP_SRGR_ADDR;
    union _McBSP_MCR MCBSP_MCR_ADDR;
    volatile unsigned int MCBSP_RCER_ADDR;
    volatile unsigned int MCBSP_XCER_ADDR;
    union _McBSP_PCR MCBSP_PCR_ADDR;
};
/*-------------------------------------------------------------------------------------*\
 * DMA-Part
\*-------------------------------------------------------------------------------------*/
struct  _McBSP_TransferLength {
 volatile unsigned int ElementNmb:16;
    volatile unsigned int Reserved:16;
};

/*-------------------------------------------------------------------------------------*\
SmartCalc-CAPITERM:
Transfer_Control_Stop_ElemntSize=S:1,0
Transfer_Control_Stop_IrqOnError=S:2,2
Transfer_Control_Stop_Load=S:3,3
Transfer_Control_DMA_Start=S:31,31
\*-------------------------------------------------------------------------------------*/
union  _McBSP_TransferControl {
 volatile unsigned int Register;
 struct __McBSP_TransferControl {
     volatile unsigned int ElementSize:2;
     volatile unsigned int IrqOnError:1;
     volatile unsigned int StopReload:1;
     volatile unsigned int Rsvd:27;
     volatile unsigned int DMAStart:1;
 } Bits;
};

/*-------------------------------------------------------------------------------------*\
SmartCalc-CAPITERM:
TransferStatus_TransferCount=S:0,15
TransferStatus_DMABusy=S:16,16
TransferStatus_Empty=S:17,17
TransferStatus_Full=S:18,18
TransferStatus_RxError=S:19,19
\*-------------------------------------------------------------------------------------*/
union  _McBSP_DMAStatus {
 volatile unsigned int Register;
 struct __McBSP_DMAStatus {
     volatile unsigned int TransferCount:16;
     volatile unsigned int DMA_Busy:1;
     volatile unsigned int FIFO_Empty:1;
     volatile unsigned int FIFO_Full:1;
     volatile unsigned int RxTxError:1;
     volatile unsigned int Rsvd:12;
 } Bits;
};

/*-------------------------------------------------------------------------------------*\
struct _McBSP_DMA *McBSP_TxDMA[2] = {(struct _McBSP_DMA *)(UR8_MCSP_BASE+0x400), (struct _McBSP_DMA *)(UR8_MCSP_BASE+0xC00)};
struct _McBSP_DMA *McBSP_RxDMA[2] = {(struct _McBSP_DMA *)(UR8_MCSP_BASE+0x600), (struct _McBSP_DMA *)(UR8_MCSP_BASE+0xE00)};
\*-------------------------------------------------------------------------------------*/
struct _McBSP_DMA {
    volatile unsigned int MCBSP_SRCADDR;             /*--- Rx: only R == DRR ---*/
    volatile unsigned int MCBSP_DESTADDR;            /*--- Tx: only R == DXR ---*/
    struct _McBSP_TransferLength  MCBSP_TransferLength; 
    union _McBSP_TransferControl  MCBSP_TransferControl; 
    volatile unsigned int MCBSP_SRCADDR_Reload;          /*--- Rx: only R == DRR ---*/
    volatile unsigned int MCBSP_DESTADDR_Reload;         /*--- Tx: only R == DXR ---*/
    struct  _McBSP_TransferLength MCBSP_TransferLength_Reload; 
    union _McBSP_TransferControl  MCBSP_TransferControl_Reload; 
    union _McBSP_DMAStatus  MCBSP_DMAStatus; 
};

extern struct _McBSP *McBSP[2];
extern struct _McBSP_DMA *McBSP_TxDMA[2];
extern struct _McBSP_DMA *McBSP_RxDMA[2];

#endif/*--- #if !defined(__ur8_mcbsp_h__) ---*/
