/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#ifndef _hw_mdio_h_
#define _hw_mdio_h_

#if defined(CONFIG_MIPS_OHIO)
#define MDIO_BASE                  OHIO_MDIO_BASE
#endif /*--- #if defined(CONFIG_MIPS_OHIO) ---*/

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_VERSION                 (*(volatile unsigned *)(MDIO_BASE + 0x00))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_CR                      (*(volatile unsigned *)(MDIO_BASE + 0x04))
#define MDIO_CR_CLKDIV(clkdiv)       ((clkdiv) << 0)
#define MDIO_CR_MAXCHAN(maxchan)     ((maxchan) << 8)
#define MDIO_CR_IRQ_TEST_EN          (1 << 17)
#define MDIO_CR_FAULT_DETECT_EN      (1 << 18)
#define MDIO_CR_FAULT                (1 << 19)
#define MDIO_CR_PREAMBLE             (1 << 20)
#define MDIO_CR_ENABLE               (1 << 30)
#define MDIO_CR_IDLE                 (1 << 31)

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_ALIVE                   (*(volatile unsigned *)(MDIO_BASE + 0x08))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_LINK                    (*(volatile unsigned *)(MDIO_BASE + 0x0C))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_IRQ_RAW                 (*(volatile unsigned *)(MDIO_BASE + 0x10))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_IRQ_MASK                (*(volatile unsigned *)(MDIO_BASE + 0x14))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_USER_IRQ_RAW            (*(volatile unsigned *)(MDIO_BASE + 0x20))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_USER_IRQ_MASK           (*(volatile unsigned *)(MDIO_BASE + 0x24))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_USER_IRQ_MASK           (*(volatile unsigned *)(MDIO_BASE + 0x24))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_USER_IRQ_SET_MASK       (*(volatile unsigned *)(MDIO_BASE + 0x28))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_USER_IRQ_CLEAR_MASK     (*(volatile unsigned *)(MDIO_BASE + 0x2C))

/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_USER_ACCESS_0           (*(volatile unsigned *)(MDIO_BASE + 0x80))
#define MDIO_USER_ACCESS_1           (*(volatile unsigned *)(MDIO_BASE + 0x88))
#define MDIO_USER_ACCESS(inst)       (*(volatile unsigned *)(MDIO_BASE + 0x80 + ((inst) ? 8 : 0)))
#define MDIO_USER_ACCESS_DATA(data)       ((data) << 0)
#define MDIO_USER_ACCESS_PHYADDR(addr)    ((addr) << 16)
#define MDIO_USER_ACCESS_REGADDR(addr)    ((addr) << 21)
#define MDIO_USER_ACCESS_ACK              (1 << 29)
#define MDIO_USER_ACCESS_WRITE            (1 << 30)
#define MDIO_USER_ACCESS_GO               (1U << 31)


/*-------------------------------------------------------------------------------------*\
\*-------------------------------------------------------------------------------------*/
#define MDIO_USER_PHY_SELECT_0           (*(volatile unsigned *)(MDIO_BASE + 0x84))
#define MDIO_USER_PHY_SELECT_1           (*(volatile unsigned *)(MDIO_BASE + 0x8C))
#define MDIO_USER_PHY_SELECT(inst)       (*(volatile unsigned *)(MDIO_BASE + 0x84 + ((inst) ? 8 : 0)))
#define MDIO_USER_PHY_SELECT_PHY_MON(addr)  ((addr) << 0)
#define MDIO_USER_PHY_SELECT_LINK_IRQ_EN    (1 << 6)
#define MDIO_USER_PHY_SELECT_LINK_SEL       (1 << 7)



/****************************************************************************/
/*                                                                          */
/*         P H Y   R E G I S T E R  D E F I N I T I O N S                   */
/*                                                                          */
/****************************************************************************/


#define PHY_CONTROL_REG                  0
  #define PHY_RESET                      (1<<15)
  #define PHY_LOOP                       (1<<14)
  #define PHY_100                        (1<<13)
  #define AUTO_NEGOTIATE_EN              (1<<12)
  #define PHY_PDOWN                      (1<<11)
  #define PHY_ISOLATE                    (1<<10)
  #define RENEGOTIATE                    (1<<9)
  #define PHY_FD                         (1<<8)

#define PHY_STATUS_REG                   1
  #define NWAY_COMPLETE                  (1<<5)
  #define NWAY_CAPABLE                   (1<<3)
  #define PHY_LINKED                     (1<<2)

#define PHY_Identifier_1                 2
#define PHY_Identifier_2                 3

#define NWAY_ADVERTIZE_REG               4

#define NWAY_REMADVERTISE_REG            5
  #define NWAY_FD100                     (1<<8)
  #define NWAY_HD100                     (1<<7)
  #define NWAY_FD10                      (1<<6)
  #define NWAY_HD10                      (1<<5)
  #define NWAY_SEL                       (1<<0)
  #define NWAY_AUTO                      (1<<0)

#define PHY_AUTO_NEG_EXPANSION           6

#define PHY_GENERIC_CONFIG_REG           0x10
  #define PHY_IFSEL                      (3<<14)
  #define PHY_LBKMD                      (3<<12)
  /*--- #define PHY_                     (3<<10) ---*/
  #define PHY_FLTLED                     (1<<9)
  #define PHY_CONV                       (1<<8)
  /*--- #define PHY_                     (1<<5) ---*/
  #define PHY_XOVEN                     (1<<4)
  /*--- #define PHY_                     (3<<2) ---*/
  #define PHY_ENREG8                     (1<<1)
  #define PHY_DISPMG                     (1<<0)

#define PHY_GENERIC_STATUS_REG           0x16
  #define PHY_STATUS_MD                  (1<<10)

#define PHY_SPECIFIC_STATUS_REG          0x17
  #define PHY_STATUS_LINK                (1<<4)

#define PHY_INTERRUPT_STATUS             0x19
  #define PHY_INT_XOVCHG                 (1<<9)
  #define PHY_INT_SPDCHG                 (1<<8)
  #define PHY_INT_DUPCHG                 (1<<7)
  #define PHY_INT_PGRCHG                 (1<<6)
  #define PHY_INT_LNKCHG                 (1<<5)
  #define PHY_INT_SYMERR                 (1<<4)
  #define PHY_INT_FCAR                   (1<<3)
  #define PHY_INT_TJABINT                (1<<2)
  #define PHY_INT_RJABINT                (1<<1)
  #define PHY_INT_ESDERR                 (1<<0)

#define PHY_RXERR_COUNT                  0x1D

/* TODO Stimmen die naechsten Defines ueberhaupt??? */
#define PHY_LINK_PARTNER_NEXT_PAGE_ABILITY 8
#define PHY_INTERRUPT                    0x1B
#define PHY_100BaseTx_CONTROL            0x1F

#endif /*--- #ifndef _hw_mdio_h_ ---*/
