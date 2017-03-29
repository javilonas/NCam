/*------------------------------------------------------------------------------------------*\
 * cpmac port management                                                                    *
 *                                                                                          * 
 * The idea is to provide a generalized interface to the cpmac driver. Each device can      *
 * return information about the existing hardware and can be used to configure any          *
 * existing switches for VLAN use.                                                          *
 *                                                                                          * 
 * To request information about the hardware, send an ioctl AVM_CPMAC_IOCTL_INFO to a       *
 * cpmac device and provide a pointer to a memory region for the port information. The      *
 * answer consists of the number of available devices (eth0...), called internal_ports,     *
 * and the number of external ports of the queried device.                                  *
 *                                                                                          * 
 * Configuring the switch hardware is done via sending an AVM_CPMAC_IOCTL_CONFIG to the     *
 * corresponding device. The parts of the configuration structure are:                      *
 *                                                                                          * 
 *   groups - Number of VLAN groups, that should be configured. 0 means none.               *
 *   vlan   - Structure to configure the given VLAN groups. The entries consist of          *
 *            id          - VLAN ID, for which information is given                         *
 *            source_mask - mask for ports that should tag packets with the given ID        *
 *            target_mask - mask for ports that should receive packets tagged with the      *
 *                          given ID                                                        *
 *   keep_tag_mask - mask for ports that keep tags on outgoing packets                      * 
 *                                                                                          * 
 * The same syntax is to be used for getting the current configuration. Provide an empty    * 
 * structure to the GET_CONFIG ioctl and it will be filled with the current configuration.  * 
 *                                                                                          * 
 * Comments: - Avoid assigning more than one source tag per port. Only the last one counts! * 
 *           - Ports that should keep their tag should appear in at least one source_mask   *
 *           - On ADM6996FC port 5 is the second MII (e.g. VDSL)                            *
 *                                                                                          *
 * Known bugs: - VLAN-IDs should be between 0 and 15 (12 bit support is to be done)         *
\*------------------------------------------------------------------------------------------*/

#if !defined(AVM_CPMAC_H)
#define AVM_CPMAC_H

#define AVM_CPMAC_MAX_VLAN_GROUPS  16
#define AVM_CPMAC_MAX_MAPPINGS     16
#define AVM_CPMAC_MAX_PORTS        6 
#define AVM_CPMAC_MAX_DEVICE_NAME_LENGTH 6
#define AVM_CPMAC_IOCTL_INFO       (SIOCDEVPRIVATE + 0)
#define AVM_CPMAC_IOCTL_SET_CONFIG_N (SIOCDEVPRIVATE + 5)
#define AVM_CPMAC_IOCTL_GET_CONFIG_N (SIOCDEVPRIVATE + 6)

#define AVM_CPMAC_IOCTL_GENERIC    (SIOCDEVPRIVATE + 3)

/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
/* data format for AVM_CPMAC_IOCTL_INFO */
struct avm_switch_info {
    unsigned int internal_ports; /* Number of overall internal ports */
    unsigned int external_ports; /* Number of external ports for the queried device */
};

/*------------------------------------------------------------------------------------------*\
  AVM_CPMAC_IOCTL_CONFIG
  AVM_CPMAC_IOCTL_GET_CONFIG
\*------------------------------------------------------------------------------------------*/
/* data format for ..CONFIG and ..GET_CONFIG */
struct avm_new_switch_struct {
    struct {
        unsigned char  written;           /* Flag, if info is already written */
        unsigned char  keep_tag_outgoing; /* Tag outgoing packets from this port */
        unsigned short vid;               /* Tag untagged incoming packets with this VID */
    } port[AVM_CPMAC_MAX_PORTS];
    struct {
        unsigned char  written : 1;       /* Flag, if info is already written */
        unsigned char  active  : 1;       /* Flag, if info is already written */
        unsigned char  target_mask;       /* Mask for the ports that should receive tagged packets */
        unsigned short vid;               /* ID of the VLAN group (preferrably 2-15) */
    } vlan[AVM_CPMAC_MAX_VLAN_GROUPS];
    unsigned char cpu_port;
};


/*------------------------------------------------------------------------------------------*\
 * CPMAC-Configuration                                                                      *
 *                                                                                          *
 * The following table lists the existing modi and their consequences for existing device   *
 * nodes on different FBoxes:                                                               *
 *                                                                                          *
 * Mode        7170             VDSL             ProfiVoIP                                  *
 *                                                                                          *
 * NORMAL      eth0             eth0, wan        eth0                                       *
 * ATA         eth0, wan        eth0, wan        eth0, wan                                  *
 * SPLIT       eth0-eth3        eth0-eth3, wan   eth0-eth4                                  *
 * SPLIT_ATA   eth0-eth2, wan   eth0-eth2, wan   eth0-eth3, wan                             *
 * ALL_PORTS   eth0             eth0             eth0                                       *
 * SPECIAL     ???              ???              ???                                        *
 *                                                                                          *
 * The ATA modi map the WAN port to an ethernet port. Therefor the connected target of the  *
 * wan device changes in the VDSL case in ATA mode.                                         *
 *                                                                                          *
 * In the ALL_PORTS mode all ports can communicate with each other.                         *
 *                                                                                          *
 * The SPECIAL mode is for special configuration and not preset. To use it call the ioctl   *
 * with type AVM_CPMAC_IOCTL_CONFIG_SET_SWITCH_MODE_SPECIAL to configure the mode, then     *
 * call AVM_CPMAC_IOCTL_CONFIG_SET_SWITCH_MODE with the SPECIAL mode.                       *
 *                                                                                          *
 * In configurations that provide a WAN port, VLANs can be routed through them.             *
\*------------------------------------------------------------------------------------------*/

enum avm_cpmac_modes {
    CPMAC_MODE_NORMAL    = 1,
    CPMAC_MODE_ATA       = 2,
    CPMAC_MODE_SPLIT     = 3,
    CPMAC_MODE_SPLIT_ATA = 4,
    CPMAC_MODE_ALL_PORTS = 5,
    CPMAC_MODE_SPECIAL   = 6,
    CPMAC_MODE_MAX_NO    = 7
};

struct avm_cpmac_config_struct {
    enum avm_cpmac_modes cpmac_mode;       /* Mode of the cpmac as described above */
    unsigned int         wan_vlan_number;  /* Number of VLAN IDs to be passed through WAN */
    unsigned int         wan_vlan_id[4];   /* VLAN IDs to be passed through WAN */
};
    

/*------------------------------------------------------------------------------------------*\
 * Structure to define switch configuration                                                 *
 *                                                                                          *
 *  number_of_devices - Number of devices defined in this structure                         *
 *  wanport           - Port that is used for WAN; 0xff means that no ethernet port is WAN  *
 *  device            - List of devices with name for the netdevice and target mask for the *
 *                      switch ports to be used                                             *
\*------------------------------------------------------------------------------------------*/
typedef struct {
  char               name[AVM_CPMAC_MAX_DEVICE_NAME_LENGTH]; /* Name of device */
  unsigned char      target_mask; /* Mask for the ports that should receive tagged packets */
} cpmac_device_struct;

typedef struct {
  unsigned char number_of_devices;
  unsigned char wanport;
  cpmac_device_struct device[AVM_CPMAC_MAX_PORTS];
} cpmac_switch_configuration_t;

enum cpmac_adm_phy_power_mode {
    ADM_PHY_POWER_OFF = 0,
    ADM_PHY_POWER_SAVE = 1,
    ADM_PHY_POWER_ON = 2
};

typedef struct {
    unsigned int                  time_on;
    unsigned int                  time_off;
    enum cpmac_adm_phy_power_mode mode[5];
} adm_phy_power_setup_t;
        
/*------------------------------------------------------------------------------------------*\
 * Configuration structure for all cpmac related ioctl configuration                        *
 *                                                                                          *
 *   type            - Type of configuration included in this structure                     *
 *                                                                                          *
 *   switch_mode     - Mode of the switch with information about used VIDs                  *
 *                                                                                          *
 *   switch_config   - Used for special mode, that is freely configurable                   *
 *                                                                                          *
 *   switch_register - Direct access to switch registers                                    *
 *                                                                                          *
 *   phy_power_setup - Configuration of the power policy for the switch PHYs                *
 *                                                                                          *
\*------------------------------------------------------------------------------------------*/

#define AVM_CPMAC_IOCTL_CONFIG_GET_INFO                 0x01
#define AVM_CPMAC_IOCTL_CONFIG_SET_SWITCH_MODE          0x02
#define AVM_CPMAC_IOCTL_CONFIG_GET_SWITCH_MODE          0x03
#define AVM_CPMAC_IOCTL_CONFIG_SET_SWITCH_MODE_SPECIAL  0x04
#define AVM_CPMAC_IOCTL_CONFIG_GET_SWITCH_MODE_CURRENT  0x05
#define AVM_CPMAC_IOCTL_CONFIG_SET_SWITCH_REGISTER      0x06
#define AVM_CPMAC_IOCTL_CONFIG_GET_SWITCH_REGISTER      0x07
#define AVM_CPMAC_IOCTL_CONFIG_SET_PHY_POWER            0x08
#define AVM_CPMAC_IOCTL_CONFIG_GET_PHY_POWER            0x09
#define AVM_CPMAC_IOCTL_CONFIG_GET_SWITCH_REGISTER_DUMP 0x0a
#define AVM_CPMAC_IOCTL_CONFIG_TESTCMD                  0x0b
#define AVM_CPMAC_IOCTL_CONFIG_GET_WAN_KEEPTAG          0x0c
#define AVM_CPMAC_IOCTL_CONFIG_GET_PORT_OUT_VID_MAP     0x0d


struct avm_cpmac_ioctl_struct {
    unsigned int type; /* Type of configuration */
    union {
        struct avm_switch_info info;                /* GET_INFO */
        struct avm_cpmac_config_struct switch_mode; /* SET_SWITCH_MODE, GET_SWITCH_MODE */
        cpmac_switch_configuration_t switch_config; /* SET_SWITCH_MODE_SPECIAL, GET_SWITCH_MODE_CURRENT */
        struct {
            unsigned int reg, value;
        } switch_register;                          /* SET_SWITCH_REGISTER, GET_SWITCH_REGISTER */
        adm_phy_power_setup_t phy_power_setup;      /* SET_PHY_POWER, GET_PHY_POWER */
        unsigned int result;                        /* GET_WAN_KEEPTAG */
        unsigned short port_out_vid_map[4];         /* GET_PORT_OUT_VID_MAP */
    } u;
};



#ifdef __KERNEL__
void cpmac_register_wan_receive(void (*wan_receive)(struct sk_buff *skb));
void cpmac_unregister_wan_receive(void);
#define CPMACWAN_SET_WAN_KEEP_TAGGING_AVAILABLE
void cpmacwan_set_wan_keep_tagging(struct net_device *dev, int enable);
#endif

#endif /*--- #if !defined(AVM_CPMAC_H) ---*/

