#!/bin/bash
#
# Copyright (c) 2017 Javier Sayago <admin@lonasdigital.com>
# Contact: javilonas@esp-desarrolladores.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

version=0.3

while :
do

  clear

echo "============================================================"
echo " Build System NCam Version $version by Javier Sayago (Javilonas). "
echo "============================================================"
echo 
echo "> ADVANCED OPTIONS"
echo
echo " 20 - Build libusb-pcsc.x86 (Linux PC 32 bit - i686)."
echo " 21 - Build libusb-pcsc.x86_64 (Linux PC 64-bits)."
echo " 22 - Build libusb-pcsc.mips (Gigablue, Dream, Vu+, Xtrend, Formuler...)."
echo " 23 - Build libusb-pcsc.mips-uclibc (Tiviar Plus and similar)."
echo " 24 - Build libusb-pcsc.sh4 (Golden Media, Galaxy Innovations, Amiko...)."
echo " 25 - Build libusb.ppc (Power PC - DM600, 7000, 7020, 7020si...)."
echo " 26 - Build libusb.ppc-old (Power PC OLD - DM500, 500S, DBox2...)."
echo " 27 - Build libusb.cortexa9hf-vfp-neon (Cortex-A9 - Wetek, Vu+4k and similar)."
echo " 28 - Build router-libusb.mips (Routers Mips DDWRT)."
echo " 29 - Build router-openwrt-brcm47xx-libusb.mips (Routers openwrt brcm47xx)."
echo " 30 - Build router-openwrt-ar71xx-libusb.mips (Routers openwrt ar71xx)."
echo " 31 - Build router-openwrt-brcm63xx-libusb.mips (Routers openwrt brcm63xx)."
echo " 32 - Build libusb.arm-raspbian (Rasp and similar)."
echo " 33 - Build libusb.arm-marvell (Synology Armada 375)."
echo " 34 - Build libusb.arm-armada37xx (Synology Armada 37xx)."
echo " 35 - Build libusb.arm-android (For Android ARM (API 24+))."
echo " 36 - Build arm-samsungtv (For Samsung TV)."
echo " 37 - Build x86_64-syn_atom (For Synology ATOM (x86_64))."
echo
echo " 38 - Remove logs."
echo " 39 - Remove distribution."
echo " 40 - Remove all (log and distribution)."
echo "  0 - Back to main menu."
echo 
echo "- Enter option:"
  read opt


  if [ "$?" != "1" ]
  then
    case $opt in
      20) build_dir/build_x86-libusb-pcsc.sh;;
      21) build_dir/build_x86_64-libusb-pcsc.sh;;
      22) build_dir/build_mips-libusb-pcsc.sh;;
      23) build_dir/build_mips-uclibc-libusb-pcsc.sh;;
      24) build_dir/build_sh4-libusb-pcsc.sh;;
      25) build_dir/build_ppc-libusb.sh;;
      26) build_dir/build_ppc-old-libusb.sh;;
      27) build_dir/build_cortexa9hf-vfp-neon-libusb.sh;;
      28) build_dir/build_mips-router-libusb.sh;;
      29) build_dir/build_mips-router-openwrt-brcm47xx-libusb.sh;;
      30) build_dir/build_mips-router-openwrt-ar71xx-libusb.sh;;
      31) build_dir/build_mips-router-openwrt-brcm63xx-libusb.sh;;
      32) build_dir/build_arm-raspbian-libusb.sh;;
      33) build_dir/build_arm-marvell-libusb.sh;;
      34) build_dir/build_arm-armada37xx-libusb.sh;;
      35) build_dir/build_arm-android-libusb.sh;;
      36) build_dir/build_arm-samsungtv.sh;;
      37) build_dir/build_x86_64_syn_atom.sh;;
      38) build_dir/clean_logs.sh;;
      39) build_dir/clean_distri.sh;;
      40) build_dir/clean_all.sh;;
      0) exit 1;;
      *) echo "Invalid option"; continue;;
    esac
  fi

done
