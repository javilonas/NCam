/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _hw_usb_h_
#define _hw_usb_h_

struct _usb_hw {
    volatile unsigned int usb_slave_buff_space_reg[0X1bc0/sizeof(unsigned int)];
    volatile unsigned int usb_slave_oep0_buff_reg_addr[8];
    volatile unsigned int usb_slave_iep0_buff_reg_addr[8];
    volatile unsigned int usb_slave_setup_pkt_block_addr[8];

    struct _usb_output_ep_config {
        volatile unsigned int usb_slave_oep_cfg_reg;
        struct _usb_slave_oep_base_reg {
            volatile unsigned int usb_slave_oep_base_addr_reg; /*--- index 1 unused ---*/
            volatile unsigned int usb_slave_oep_byte_cnt_reg;  /*--- index 1 unused ---*/
        } usb_slave_oep_base_reg[3];
        volatile unsigned int usb_slave_oep_siz_xy_reg;
    } usb_output_ep_config[7];

    unsigned char reserved1[0x1D20 - 0x1D00]; 

    struct _usb_input_ep_config {
        volatile unsigned int usb_slave_iep_cfg_reg;
        struct _usb_slave_iep_base_reg {
            volatile unsigned int usb_slave_iep_base_addr_reg; /*--- index 1 unused ---*/
            volatile unsigned int usb_slave_iep_byte_cnt_reg;  /*--- index 1 unused ---*/
        } usb_slave_iep_base_reg[3];
        volatile unsigned int usb_slave_iep_siz_xy_reg;
    } usb_input_ep_config[7];

    volatile unsigned int usb_slave_iep0_cfg_reg;
    volatile unsigned int usb_slave_iep0_byte_cnt_reg;
    volatile unsigned int usb_slave_oep0_cfg_reg;
    volatile unsigned int usb_slave_oep0_byte_cnt_reg;
    unsigned char reserved3[0x1E48 - 0x1E10];
    volatile unsigned int usb_slave_vec_int_reg;
    volatile unsigned int usb_slave_iep_int_reg;
    volatile unsigned int usb_slave_oep_int_reg;
    unsigned char reserved4[0x1E80 - 0x1E54];
    volatile unsigned int usb_slave_tx_dma_cfg_reg;
    volatile unsigned int usb_slave_tx_dma_status_reg;
    unsigned char reserved5[0x1EC0 - 0x1E88];
    volatile unsigned int usb_slave_rx_dma_cfg_reg;
    unsigned char reserved6[0x1ED4 - 0x1EC4];
    volatile unsigned int usb_slave_rx_dma_status_reg;
    unsigned char reserved7[0x1F00 - 0x1ED8];
    volatile unsigned int usb_slave_host_dma_read_channel_reg;
    volatile unsigned int usb_slave_host_dma_write_channel_reg;
    volatile unsigned int usb_slave_host_dma_interrupt_channel_reg;
    volatile unsigned int usb_slave_host_dma_control_reg;
    unsigned char reserved8[0x1F80 - 0x1F10];
    volatile unsigned int usb_slave_vbus_data_0;
    volatile unsigned int usb_slave_vbus_data_1;
    volatile unsigned int usb_slave_vbus_data_2;
    volatile unsigned int usb_slave_vbus_data_3;
    volatile unsigned int usb_slave_vbus_addr_0;
    volatile unsigned int usb_slave_vbus_addr_1;
    volatile unsigned int usb_slave_vbus_addr_2;
    volatile unsigned int usb_slave_vbus_addr_3;
    union __usb_slave_vbus_ctl_reg {
        struct _usb_slave_vbus_ctl_reg {
            unsigned int byte_enable : 4;
            unsigned int reserved    : 1;
            unsigned int dir         : 1;  /*--- 1: read, 0: write ---*/
            unsigned int req         : 1;  /*--- set for new request ---*/
            unsigned int ready       : 1;  
        } bits;
        volatile unsigned int i;
    } usb_slave_vbus_ctl_reg;
    unsigned char reserved9[0x1FF0 - 0x1FA4];
    volatile unsigned int usb_slave_usb_ctl_reg;
    volatile unsigned int usb_slave_usb_msk_reg;
    volatile unsigned int usb_slave_usb_sta_reg;
    volatile unsigned int usb_slave_fun_adr_reg;
};

extern struct _usb_hw *U;

struct _usbirq_header {
    volatile unsigned int status;
    volatile unsigned int general;
} __attribute__ ((packed));

#define HAL_USB_BULK_NUM_BUFFERS            256

struct _usbdma_header {
    volatile unsigned char read_pointer;
    volatile unsigned char write_pointer;
    unsigned short         reserved;
    unsigned char          data[HAL_USB_BULK_NUM_BUFFERS]; 
} __attribute__ ((packed));

struct _usbdma_hw {
    volatile unsigned int usb_slave_usbv_cfg_reg;
    unsigned int reserved1[7]; /*--- 04, 08, 0C, 10, 14, 18, 1C ---*/
    volatile unsigned int usb_slave_usbv_tx_fifo_ptrs_addr_reg;
    volatile unsigned int usb_slave_usbv_tx_fifo_base_addr_reg;
    volatile unsigned int usb_slave_usbv_tx_fifo_length_reg;
    volatile unsigned int usb_slave_usbv_tx_fifo_poll_rate_reg;
    volatile unsigned int usb_slave_usbv_tx_fifo_curr_ptr_addr_reg;
    unsigned int reserved2[3]; /*--- 34, 38, 3C ---*/
    volatile unsigned int usb_slave_usbv_rx_fifo_ptrs_addr_reg;
    volatile unsigned int usb_slave_usbv_rx_fifo_base_addr_reg;
    volatile unsigned int usb_slave_usbv_rx_fifo_length_reg;
    volatile unsigned int usb_slave_usbv_rx_fifo_poll_rate_reg;
    volatile unsigned int usb_slave_usbv_rx_fifo_curr_ptr_addr_reg; /*--- offset 0x50 ---*/
    unsigned int reserved3[7]; /*--- 54, 58, 5C, 60, 64, 68, 6C ---*/
    volatile unsigned int usb_slave_usbv_host_irq_addr_reg; /*--- offset 0x70 ---*/
    volatile unsigned int usb_slave_usbv_host_irq_reg;
    unsigned int reserved4[2]; /*--- 78, 7C ---*/
    volatile unsigned int usb_slave_usbv_mailbox_1_reg;
    volatile unsigned int usb_slave_usbv_mailbox_2_reg;
    volatile struct _usb_slave_usbv_revision {
        unsigned int rev_minor : 8;
        unsigned int rev_major : 8;
        unsigned int module_id : 14;
        unsigned int reserved  : 2;
    } usb_slave_usbv_revision_reg;
};
extern struct _usbdma_hw *Udma;


#endif /*--- #ifndef _hw_usb_h_ ---*/
