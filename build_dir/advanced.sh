#!/bin/bash
#
# Copyright (c) 2016 Javier Sayago <admin@lonasdigital.com>
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

version=0.1

while :
do

  clear

echo "============================================================"
echo " Build System NCam Version $version by Javier Sayago (Javilonas). "
echo " Github: https://github.com/javilonas/NCam"
echo "============================================================"
echo 
echo "> ADVANCED OPTIONS"
echo
echo " 11 - Build x86-libusb-pcsc Linux PC (32 bit - i686)."
echo " 12 - Build x86_64-libusb-pcsc Linux PC (64-bits)."
echo " 13 - Build mips-libusb-pcsc (Gigablue, Dream, Vu+, Xtrend, Formuler...)."
echo " 14 - Build mips-libusb-pcsc (Tiviar Plus and similar)."
echo " 15 - Build sh4-libusb-pcsc (Golden Media, Galaxy Innovations, Amiko...)."
echo " 16 - Build ppc-libusb (Power PC - DM600, 7000, 7020, 7020si...)."
echo " 17 - Build arm-libusb (Cortex-A9 - Wetek Play and similar)."
echo " 18 - Build mips-router-libusb (Routers MIPSEL DD-WRT)."
echo
echo " 19 - Remove logs."
echo " 20 - Remove distribution."
echo "  0 - Back to main menu."
echo 
echo "- Enter option:"
  read opt


  if [ "$?" != "1" ]
  then
    case $opt in
      11) build_dir/build_x86-libusb-pcsc.sh;;
      12) build_dir/build_x86_64-libusb-pcsc.sh;;
      13) build_dir/build_mips-libusb-pcsc.sh;;
      14) build_dir/build_mips-uclibc-libusb-pcsc.sh;;
      15) build_dir/build_sh4-libusb-pcsc.sh;;
      16) build_dir/build_ppc-libusb.sh;;
      17) build_dir/build_cortexa9hf-vfp-neon-libusb.sh;;
      18) build_dir/build_mips-libusb-pcsc.sh;;
      19) build_dir/clean_logs.sh;;
      20) build_dir/clean_distri.sh;;
      0) exit 1;;
      *) echo "Invalid option"; continue;;
    esac
  fi

done
