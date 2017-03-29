/****************************************************************************
**      ADM6996L support
**      Copyright(c) 2005, AVM GmbH
*****************************************************************************/
#ifndef _INC_ADM_REG
#define _INC_ADM_REG

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
struct adm_struct {
    unsigned int reserved00;
    struct {
        unsigned int port0linkup      : 1;
        unsigned int port0speed       : 1;
        unsigned int port0duplex      : 1;
        unsigned int port0flowcontrol : 1;
        unsigned int reserved0        : 4;
        unsigned int port1linkup      : 1;
        unsigned int port1speed       : 1;
        unsigned int port1duplex      : 1;
        unsigned int port1flowcontrol : 1;
        unsigned int reserved1        : 4;
        unsigned int port2linkup      : 1;
        unsigned int port2speed       : 1;
        unsigned int port2duplex      : 1;
        unsigned int port2flowcontrol : 1;
        unsigned int reserved2        : 4;
        unsigned int port3linkup      : 1;
        unsigned int port3speed       : 1;
        unsigned int port3duplex      : 1;
        unsigned int port3flowcontrol : 1;
        unsigned int port4linkup      : 1;
        unsigned int port4speed       : 1;
        unsigned int port4duplex      : 1;
        unsigned int port4flowcontrol : 1;
    } status;
    struct {
        unsigned int port5linkup      : 1;
        unsigned int port5speed       : 1;
        unsigned int port5duplex      : 1;
        unsigned int port5flowcontrol : 1;
        unsigned int reserved0        : 28;
    } status2;
    struct {
        unsigned int port0length : 2;
        unsigned int port0       : 1;
        unsigned int reserved0   : 3;
        unsigned int port1length : 2;
        unsigned int port1       : 1;
        unsigned int reserved1   : 3;
        unsigned int port2length : 2;
        unsigned int port2       : 1;
        unsigned int reserved2   : 3;
        unsigned int port3length : 2;
        unsigned int port3       : 1;
        unsigned int port4length : 2;
        unsigned int port4       : 1;
        unsigned int reserved3   : 8;
    } cablebroken;
    struct {
        unsigned int pktcnt0;
        unsigned int reserved0517;
        unsigned int pktcnt1;
        unsigned int reserved0719;
        unsigned int pktcnt2;
        unsigned int reserved091b;
        unsigned int pktcnt3;
        unsigned int pktcnt4;
        unsigned int pktcnt5;
        unsigned int pktbytecnt0;
        unsigned int reserved0e20;
        unsigned int pktbytecnt1;
        unsigned int reserved1022;
        unsigned int pktbytecnt2;
        unsigned int reserved1224;
        unsigned int pktbytecnt3;
        unsigned int pktbytecnt4;
        unsigned int pktbytecnt5;
    } rx, tx;
    struct {
        unsigned int port0;
        unsigned int reserved2932;
        unsigned int port1;
        unsigned int reserved2b34;
        unsigned int port2;
        unsigned int reserved2d36;
        unsigned int port3;
        unsigned int port4;
        unsigned int port5;
    } collisions, errors;
    struct {
        struct {
            unsigned int pktcntport0         : 1;
            unsigned int pktcntreserved0     : 1;
            unsigned int pktcntport1         : 1;
            unsigned int pktcntreserved1     : 1;
            unsigned int pktcntport2         : 1;
            unsigned int pktcntreserved2     : 1;
            unsigned int pktcntport3         : 1;
            unsigned int pktcntport4         : 1;
            unsigned int pktcntport5         : 1;
            unsigned int pktbytecntport0     : 1;
            unsigned int pktbytecntreserved0 : 1;
            unsigned int pktbytecntport1     : 1;
            unsigned int pktbytecntreserved1 : 1;
            unsigned int pktbytecntport2     : 1;
            unsigned int pktbytecntreserved2 : 1;
            unsigned int pktbytecntport3     : 1;
            unsigned int pktbytecntport4     : 1;
            unsigned int pktbytecntport5     : 1;
            unsigned int reserved            : 14;
        } rx, tx;
        struct {
            unsigned int collisionsport0 : 1;
            unsigned int reserved0       : 1;
            unsigned int collisionsport1 : 1;
            unsigned int reserved1       : 1;
            unsigned int collisionsport2 : 1;
            unsigned int reserved2       : 1;
            unsigned int collisionsport3 : 1;
            unsigned int collisionsport4 : 1;
            unsigned int collisionsport5 : 1;
            unsigned int errorsport0     : 1;
            unsigned int reserved3       : 1;
            unsigned int errorsport1     : 1;
            unsigned int reserved4       : 1;
            unsigned int errorsport2     : 1;
            unsigned int reserved5       : 1;
            unsigned int errorsport3     : 1;
            unsigned int errorsport4     : 1;
            unsigned int errorsport5     : 1;
            unsigned int reserved6       : 14;
        } misc;
    } overflow;
};
extern struct adm_struct adm_serial_register;


/****************************************************************************/
/*                                                                          */
/*  ADMTEK 6996L EEPROM register definitions                                */
/*                                                                          */
/****************************************************************************/

#define REG_ADM_SIGNATURE                  0x00
#define REG_ADM_CONF_PORT0                 0x01
#define REG_ADM_CONF_PORT1                 0x03
#define REG_ADM_CONF_PORT2                 0x05
#define REG_ADM_CONF_PORT3                 0x07
#define REG_ADM_CONF_PORT4                 0x08
#define REG_ADM_CONF_PORT5                 0x09
  #define ADM_CONF_FLOW_CONTROL            (1 <<  0)
  #define ADM_CONF_AUTO_NEGOTIATION        (1 <<  1)
  #define ADM_CONF_SPEED_100               (1 <<  2)
  #define ADM_CONF_DUPLEX_FULL             (1 <<  3)
  #define ADM_CONF_OUTPUT_PKT_TAG          (1 <<  4)
  #define ADM_CONF_PORT_DISABLE            (1 <<  5)
  #define ADM_CONF_PORT_BASE_PRIO_ENABLE   (1 <<  6)
  #define ADM_CONF_PORT_BASE_PRIO          (3 <<  7)
  #define ADM_CONF_PORT_VLAN_ID            (15 << 10)
  #define ADM_CONF_SELECT_FX               (1 << 14)
  #define ADM_CONF_AUTO_MDIX               (1 << 15)


/****************************************************************************/
/*                                                                          */
/*  ADMTEK 6996L serial register definitions                                */
/*                                                                          */
/****************************************************************************/

#define REG_ADM_ID                         0x00

#define REG_ADM_STATUS0                    0x01
  #define ADM_STATUS_LINKUP                (1 <<  0)
  #define ADM_STATUS_SPEED                 (1 <<  1)
  #define ADM_STATUS_DUPLEX                (1 <<  2)
  #define ADM_STATUS_FLOWCONTROL           (1 <<  3)
/* Shift bits for ports 0-4 */
  #define ADM_STATUS_PORT0_SHIFT           0
  #define ADM_STATUS_PORT1_SHIFT           8
  #define ADM_STATUS_PORT2_SHIFT           16
  #define ADM_STATUS_PORT3_SHIFT           24
  #define ADM_STATUS_PORT4_SHIFT           28

  #define ADM_STATUS0_PORT0_LINKUP         (ADM_STATUS_LINKUP      << ADM_STATUS_PORT0_SHIFT)
  #define ADM_STATUS0_PORT0_SPEED          (ADM_STATUS_SPEED       << ADM_STATUS_PORT0_SHIFT)
  #define ADM_STATUS0_PORT0_DUPLEX         (ADM_STATUS_DUPLEX      << ADM_STATUS_PORT0_SHIFT)
  #define ADM_STATUS0_PORT0_FLOWCONTROL    (ADM_STATUS_FLOWCONTROL << ADM_STATUS_PORT0_SHIFT)
  #define ADM_STATUS0_PORT1_LINKUP         (ADM_STATUS_LINKUP      << ADM_STATUS_PORT1_SHIFT)
  #define ADM_STATUS0_PORT1_SPEED          (ADM_STATUS_SPEED       << ADM_STATUS_PORT1_SHIFT)
  #define ADM_STATUS0_PORT1_DUPLEX         (ADM_STATUS_DUPLEX      << ADM_STATUS_PORT1_SHIFT)
  #define ADM_STATUS0_PORT1_FLOWCONTROL    (ADM_STATUS_FLOWCONTROL << ADM_STATUS_PORT1_SHIFT)
  #define ADM_STATUS0_PORT2_LINKUP         (ADM_STATUS_LINKUP      << ADM_STATUS_PORT2_SHIFT)
  #define ADM_STATUS0_PORT2_SPEED          (ADM_STATUS_SPEED       << ADM_STATUS_PORT2_SHIFT)
  #define ADM_STATUS0_PORT2_DUPLEX         (ADM_STATUS_DUPLEX      << ADM_STATUS_PORT2_SHIFT)
  #define ADM_STATUS0_PORT2_FLOWCONTROL    (ADM_STATUS_FLOWCONTROL << ADM_STATUS_PORT2_SHIFT)
  #define ADM_STATUS0_PORT3_LINKUP         (ADM_STATUS_LINKUP      << ADM_STATUS_PORT3_SHIFT)
  #define ADM_STATUS0_PORT3_SPEED          (ADM_STATUS_SPEED       << ADM_STATUS_PORT3_SHIFT)
  #define ADM_STATUS0_PORT3_DUPLEX         (ADM_STATUS_DUPLEX      << ADM_STATUS_PORT3_SHIFT)
  #define ADM_STATUS0_PORT3_FLOWCONTROL    (ADM_STATUS_FLOWCONTROL << ADM_STATUS_PORT3_SHIFT)
  #define ADM_STATUS0_PORT4_LINKUP         (ADM_STATUS_LINKUP      << ADM_STATUS_PORT4_SHIFT)
  #define ADM_STATUS0_PORT4_SPEED          (ADM_STATUS_SPEED       << ADM_STATUS_PORT4_SHIFT)
  #define ADM_STATUS0_PORT4_DUPLEX         (ADM_STATUS_DUPLEX      << ADM_STATUS_PORT4_SHIFT)
  #define ADM_STATUS0_PORT4_FLOWCONTROL    (ADM_STATUS_FLOWCONTROL << ADM_STATUS_PORT4_SHIFT)

#define REG_ADM_STATUS1                    0x02
  #define ADM_STATUS1_PORT5_LINKUP         (1 << 0)
  #define ADM_STATUS1_PORT5_SPEED          (3 << 1)
  #define ADM_STATUS1_PORT5_DUPLEX         (1 << 3)
  #define ADM_STATUS1_PORT5_FLOWCONTROL    (1 << 4)

#define REG_ADM_CABLEBROKENSTATUS          0x03
  #define ADM_CABLEBROKEN_LENGTH           (3 <<  0)
  #define ADM_CABLEBROKEN                  (1 <<  2)
/* Shift bits for ports 0-4 */
  #define ADM_CABLEBROKEN_PORT0_SHIFT      0
  #define ADM_CABLEBROKEN_PORT1_SHIFT      6
  #define ADM_CABLEBROKEN_PORT2_SHIFT      12
  #define ADM_CABLEBROKEN_PORT3_SHIFT      18
  #define ADM_CABLEBROKEN_PORT4_SHIFT      21

  #define ADM_CABLEBROKEN_PORT0_LENGTH     (ADM_CABLEBROKEN_LENGTH << ADM_CABLEBROKEN_PORT0_SHIFT)
  #define ADM_CABLEBROKEN_PORT0            (ADM_CABLEBROKEN        << ADM_CABLEBROKEN_PORT0_SHIFT)
  #define ADM_CABLEBROKEN_PORT1_LENGTH     (ADM_CABLEBROKEN_LENGTH << ADM_CABLEBROKEN_PORT1_SHIFT)
  #define ADM_CABLEBROKEN_PORT1            (ADM_CABLEBROKEN        << ADM_CABLEBROKEN_PORT1_SHIFT)
  #define ADM_CABLEBROKEN_PORT2_LENGTH     (ADM_CABLEBROKEN_LENGTH << ADM_CABLEBROKEN_PORT2_SHIFT)
  #define ADM_CABLEBROKEN_PORT2            (ADM_CABLEBROKEN        << ADM_CABLEBROKEN_PORT2_SHIFT)
  #define ADM_CABLEBROKEN_PORT3_LENGTH     (ADM_CABLEBROKEN_LENGTH << ADM_CABLEBROKEN_PORT3_SHIFT)
  #define ADM_CABLEBROKEN_PORT3            (ADM_CABLEBROKEN        << ADM_CABLEBROKEN_PORT3_SHIFT)
  #define ADM_CABLEBROKEN_PORT4_LENGTH     (ADM_CABLEBROKEN_LENGTH << ADM_CABLEBROKEN_PORT4_SHIFT)
  #define ADM_CABLEBROKEN_PORT4            (ADM_CABLEBROKEN        << ADM_CABLEBROKEN_PORT4_SHIFT)

#define REG_ADM_RXPKTCNT0                  0x04
#define REG_ADM_RXPKTCNT1                  0x06
#define REG_ADM_RXPKTCNT2                  0x08
#define REG_ADM_RXPKTCNT3                  0x0a
#define REG_ADM_RXPKTCNT4                  0x0b
#define REG_ADM_RXPKTCNT5                  0x0c
#define REG_ADM_RXPKTBYTECNT0              0x0d
#define REG_ADM_RXPKTBYTECNT1              0x0f
#define REG_ADM_RXPKTBYTECNT2              0x11
#define REG_ADM_RXPKTBYTECNT3              0x13
#define REG_ADM_RXPKTBYTECNT4              0x14
#define REG_ADM_RXPKTBYTECNT5              0x15
#define REG_ADM_TXPKTCNT0                  0x16
#define REG_ADM_TXPKTCNT1                  0x18
#define REG_ADM_TXPKTCNT2                  0x1a
#define REG_ADM_TXPKTCNT3                  0x1c
#define REG_ADM_TXPKTCNT4                  0x1d
#define REG_ADM_TXPKTCNT5                  0x1e
#define REG_ADM_TXPKTBYTECNT0              0x1f
#define REG_ADM_TXPKTBYTECNT1              0x21
#define REG_ADM_TXPKTBYTECNT2              0x23
#define REG_ADM_TXPKTBYTECNT3              0x25
#define REG_ADM_TXPKTBYTECNT4              0x26
#define REG_ADM_TXPKTBYTECNT5              0x27
#define REG_ADM_COLLISIONCNT0              0x28
#define REG_ADM_COLLISIONCNT1              0x2a
#define REG_ADM_COLLISIONCNT2              0x2c
#define REG_ADM_COLLISIONCNT3              0x2e
#define REG_ADM_COLLISIONCNT4              0x2f
#define REG_ADM_COLLISIONCNT5              0x30
#define REG_ADM_ERRCNT0                    0x31
#define REG_ADM_ERRCNT1                    0x33
#define REG_ADM_ERRCNT2                    0x35
#define REG_ADM_ERRCNT3                    0x37
#define REG_ADM_ERRCNT4                    0x38
#define REG_ADM_ERRCNT5                    0x39

#define REG_ADM_OVERFLOWFLAG0              0x3a
#define REG_ADM_OVERFLOWFLAG1              0x3b
  #define ADM_OVERFLOW_PKTCNT_PORT0        (1 <<  0)
  #define ADM_OVERFLOW_PKTCNT_PORT1        (1 <<  2)
  #define ADM_OVERFLOW_PKTCNT_PORT2        (1 <<  4)
  #define ADM_OVERFLOW_PKTCNT_PORT3        (1 <<  6)
  #define ADM_OVERFLOW_PKTCNT_PORT4        (1 <<  7)
  #define ADM_OVERFLOW_PKTCNT_PORT5        (1 <<  8)
  #define ADM_OVERFLOW_PKTBYTECNT_PORT0    (1 <<  9)
  #define ADM_OVERFLOW_PKTBYTECNT_PORT1    (1 << 11)
  #define ADM_OVERFLOW_PKTBYTECNT_PORT2    (1 << 13)
  #define ADM_OVERFLOW_PKTBYTECNT_PORT3    (1 << 15)
  #define ADM_OVERFLOW_PKTBYTECNT_PORT4    (1 << 16)
  #define ADM_OVERFLOW_PKTBYTECNT_PORT5    (1 << 17)

#define REG_ADM_OVERFLOWFLAG2              0x3c
  #define ADM_OVERFLOW_COLLCNT_PORT0       (1 <<  0)
  #define ADM_OVERFLOW_COLLCNT_PORT1       (1 <<  2)
  #define ADM_OVERFLOW_COLLCNT_PORT2       (1 <<  4)
  #define ADM_OVERFLOW_COLLCNT_PORT3       (1 <<  6)
  #define ADM_OVERFLOW_COLLCNT_PORT4       (1 <<  7)
  #define ADM_OVERFLOW_COLLCNT_PORT5       (1 <<  8)
  #define ADM_OVERFLOW_ERRCNT_PORT0        (1 <<  9)
  #define ADM_OVERFLOW_ERRCNT_PORT1        (1 << 11)
  #define ADM_OVERFLOW_ERRCNT_PORT2        (1 << 13)
  #define ADM_OVERFLOW_ERRCNT_PORT3        (1 << 15)
  #define ADM_OVERFLOW_ERRCNT_PORT4        (1 << 16)
  #define ADM_OVERFLOW_ERRCNT_PORT5        (1 << 17)

#endif /*--- #define _INC_ADM_REG ---*/
