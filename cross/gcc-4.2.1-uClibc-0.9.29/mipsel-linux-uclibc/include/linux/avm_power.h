/*------------------------------------------------------------------------------------------*\
 *   
 *   Copyright (C) 2006 AVM GmbH <fritzbox_info@avm.de>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
\*------------------------------------------------------------------------------------------*/
#ifndef _AR7_AVMPOWER_H_
#define _AR7_AVMPOWER_H_

/*-------------------------------------------------------------------------------------*\
 * Powermanagment des Treibers anmelden
 * adsl: state
 *  0	Power Off
 *  1	Low Power (kein DSL)
 *  20	nur Request (kein State aendern!): IsATA  Returnwert 0: ja sonst anderer Mode
 *  10	Full Speed (jetziger Stand)
 *
 *  piglet: state 
 *  0 normal clocks
 *  1 high clocks 
 *  2 low  clocks 
 *  0x10 Abfrage ob Piglet unabhängig von Systemfrequenz liefere 1 sonst 0
 *  verodert mit 0x80: Moeglichkeit testen, wenn möglich, so werden die Codecs allerdings auch gleich gestoppt!
 *  UR8:
 *  0x100: 40V disable
 *  0x101: 40V enable
 *  
 *  speedup: 
 * state:
 *  0 normal clocks
 *  1 high clocks 
 *  2 low  clocks 
 *  0x8x setze clock (0,1,2) - ab jetzt kein idleabhängiges Speedup-Control
 *  0x10x Setzen der unterstuetzten Modi: (1 Fast, 2 Slow (verodern))
 *  0x18x Setzen der unterstuezten Modi - allerdings nur manuelle Switching (idleunabhaengig)
 *  0x201 kein speed-down mehr - nur noch speedup (Telefonapplikation)
 *  0x200 speed-down entlocken
 *  0x40x Abfrage ob diese entsprechende Speedup erlaubt     
 *  0x801 kein speedup/down       (USB-Treiber)
 *  0x800 speed-down entlocken
 *  0x1001 kein speedup/down       (ATM-Treiber)
 *  0x1000 speed-down entlocken
 * Initial sind Änderungen an der Clock nicht freigeschaltet
 *  ethernet: 
 *  siehe union  _powermanagment_ethernet_state
 *
 *  isdn:
 *  state:  
 *  0x10        SLIC 1 aus
 *  0x11        SLIC 1 an
 *  0x20        SLIC 2 aus
 *  0x21        SLIC 2 an
\*-------------------------------------------------------------------------------------*/
void *PowerManagmentRegister(char *client_name, int (*CallBackPowerManagmentControl)(int state));

/*-------------------------------------------------------------------------------------*\
 * Treiber abmelden
\*-------------------------------------------------------------------------------------*/
void PowerManagmentRelease(void *Handle);

/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
union  _powermanagment_ethernet_state {
    unsigned int Register;
    struct {
        unsigned int port:8;        /*--- auszuwaehlender port ---*/ 
        unsigned int status:2;      /*--- 0: aus, 1: power_save, 2: normal ---*/
        unsigned int reserved:22; 
    } Bits;
};
/*-------------------------------------------------------------------------------------*\
 * vom Kernel den Powermode ändern
 * Returnwert: 0 ok sonst Abbruch mit Fehler
\*-------------------------------------------------------------------------------------*/
int PowerManagmentActivatePowerMode(char *powermodename);

#ifdef CONFIG_AVM_POWERMETER
/*--------------------------------------------------------------------------------*\
\*--------------------------------------------------------------------------------*/
enum _powermanagment_device {
    powerdevice_none        = 0,
    powerdevice_cpuclock    = 1,        /*--- power_rate in % Bezug: NormFrequenz 212 MHz ---*/
    powerdevice_dspclock    = 2,        /*--- power_rate in % Bezug: NormFrequenz 250 MHz ---*/
    powerdevice_systemclock = 3,        /*--- power_rate in % Bezug: NormFrequenz 150 MHz ---*/
    powerdevice_wlan        = 4,        /*--- power_rate in % Maximal-Last ---*/
    powerdevice_isdnnt      = 5,        /*--- power_rate 0 oder 100 % (Ebene 1 aktiv)  ---*/
    powerdevice_isdnte      = 6,        /*--- power_rate 0 oder 100 % (Ebene 1 aktiv)  ---*/
    powerdevice_analog      = 7,        /*--- power_rate 100 % pro abgehobenen Telefon ---*/    
    powerdevice_dect        = 8,        /*--- power_rate in % Maximal-Last ---*/
    powerdevice_ethernet    = 9,        /*--- power_rate 100 % pro aktiven Port ---*/
    powerdevice_dsl         = 10,       /*--- power_rate in % Maximal-Last (????) ---*/
    powerdevice_usb_host    = 11,       /*--- power_rate in Milli-Ampere ---*/ 
    powerdevice_usb_client  = 12,       /*--- power_rate 100 % der Maximal-Last ---*/   
    powerdevice_charge      = 13,       /*--- power_rate in Milli-Watt ---*/
    powerdevice_loadrate    = 14,       /*--- power_rate in % (100 - % Idle-Wert) ---*/    
    powerdevice_temperature = 15,       /*--- power_rate in Grad Celcius ---*/    
    powerdevice_maxdevices  = 16        
};

/*--------------------------------------------------------------------------------*\
 * Funktion wird von Treibern aufgerufen um Infos ueber den aktuellen Power-Status zu liefern
 *  powerdevice_wlan: 
\*--------------------------------------------------------------------------------*/
#define FREQUENZ_TO_PERCENT(freq, ref_freq)     (freq) / ((ref_freq) / 100)
#define PM_RATE_MASK                      0xFFFF  
#define PM_GET_RATE(param)                (((param)) & PM_RATE_MASK)
#define PM_WLAN_PARAM(eco, devices, rate) (((eco) ? (1 << 31) : 0) | ((devices & 0x7F) << 24) | ((rate) & PM_RATE_MASK))
#define PM_WLAN_GET_ECO(param)            ((param) & (1 << 31) ? 1 : 0)
#define PM_WLAN_GET_DEVICES(param)        (((param) >> 24) & 0x7F)  
#define PM_WLAN_TRANSMITPOWER_TO_RATE(rate) (rate) == 0 ? 0 : (100 >> ((rate) - 1))

#define PM_DECT_STATUS(eco, rate)             (((eco) ? (1 << 31) : 0) | ((rate) & PM_RATE_MASK))
#define PM_DECT_GET_ECO(param)                ((param) & (1 << 31) ? 1 : 0)
/*--- Controller zaehlt ab 1 !! ---*/
#define PM_E1STATUS(Controller)               (1 << (16 + ((Controller) - 1)))
#define PM_ISDN_SET_E1STATUS(Controller)      ((1 << 31) | PM_E1STATUS(Controller))
#define PM_ISDN_RESET_E1STATUS(Controller)    ((0 << 31) | PM_E1STATUS(Controller))

#define PM_E3STATUS(Controller)               (1 << (24 + ((Controller) - 1)))
#define PM_ISDN_SET_E3STATUS(Controller)      ((1 << 31) | PM_E3STATUS(Controller))
#define PM_ISDN_RESET_E3STATUS(Controller)    ((0 << 31) | PM_E3STATUS(Controller))

#define PM_ETHERNET_PARAM(devicemask, rate) ((((devicemask) & 0xFF) << 24) | (rate))
#define PM_ETHERNET_GET_DEVICEMASK(param)   (((param) >> 24) & 0xFF) 
void PowerManagmentRessourceInfo(enum _powermanagment_device device, int power_rate);

#endif/*--- #ifdef CONFIG_AVM_POWERMETER ---*/

#endif/*--- #ifndef _AR7_AVMPOWER_H_ ---*/
