/*------------------------------------------------------------------------------------------*\
\*------------------------------------------------------------------------------------------*/
#ifndef _hw_boot_h_
#define _hw_boot_h_

#if defined(CONFIG_MIPS_AR7)

struct _hw_boot {
    union _hw_boot_config {
        struct __hw_boot_config {
            unsigned int boots : 3;
            unsigned int wsdp : 1;
            unsigned int wdhe : 1;
            unsigned int pll_byp : 1;
            unsigned int endian : 1;
            unsigned int flashw : 2;
            unsigned int emifrate : 1;
            unsigned int emiftest : 1;
            unsigned int boots_int : 3;
            unsigned int syspllsel : 2;
            unsigned int mipspllsel : 2;
            unsigned int usbpllsel : 2;
            unsigned int ephypllsel : 2;
            unsigned int adslpllsel : 2;
            unsigned int adsl_rst : 1;
            unsigned int mips_async : 1;
            unsigned int def : 1;
            unsigned int reserved : 5;
        } Bits;
        volatile unsigned int Register;
    } hw_boot_config;

    union _hw_boot_test_mux_1 {
        struct __hw_boot_test_mux_1 {
            unsigned int mbsp1_sel : 1;
            unsigned int codec_char_en : 1;
        } Bits;
        volatile unsigned int Register;
    } hw_boot_test_mux_1 ;

    union _hw_boot_test_mux_2 {
        struct __hw_boot_test_mux_2 {
            unsigned int mii0_sel : 1;
        } Bits;
        volatile unsigned int Register;
    } hw_boot_test_mux_2 ;

    union _hw_boot_test_mux_3 {
        struct __hw_boot_test_mux_3 {
            unsigned int pll_pin_output_enable : 1;
            unsigned int pll_pin_out_id : 2; /* 0: System, 1: MIPS, 2: USB, 3: adsl */
            unsigned int pll_pin_out_div_enable : 1;
        } Bits;
        volatile unsigned int Register;
    } hw_boot_test_mux_3 ;

    union _hw_boot_adsl_pll_select {
        struct __hw_boot_adsl_pll_select {
            unsigned int pll_0_select : 1;
        } Bits;
        volatile unsigned int Register;
    } hw_boot_adsl_pll_select ;

    union _hw_boot_speed_control {
        struct __hw_boot_speed_control {
            unsigned int gated_ring_oscillator_enable : 1;
            unsigned int input_counter_enable : 1;
            unsigned int gated_oscillator_select : 3;
        } Bits;
        volatile unsigned int Register;
    } hw_boot_speed_control ;

    union _hw_boot_speed_control_password {
        struct __hw_boot_speed_control_password {
            unsigned int passwd_enable : 1;
        } Bits;
        volatile unsigned int Register;
    } hw_boot_speed_control_password ;

    union _hw_boot_speed_control_capture {
        struct __hw_boot_speed_control_capture {
            unsigned int out : 16;
        } Bits;
        volatile unsigned int Register;
    } hw_boot_speed_control_capture ;

};

#endif/*--- #if defined(CONFIG_MIPS_AR7) ---*/

#endif /*--- #ifndef _hw_boot_h_ ---*/
