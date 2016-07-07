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
echo "> MAIN MENU"
echo
echo "  1 - Build ALL. (Including versions smargo)"
echo "  2 - Build x86 Linux PC (32 bit - i686)."
echo "  3 - Build x86_64 Linux PC (64-bits)."
echo "  4 - Build mips (Gigablue, Dream, Vu+, Xtrend, Formuler...)."
echo "  5 - Build mips (Tiviar Plus and similar)."
echo "  6 - Build sh4 (Golden Media, Galaxy Innovations, Amiko...)."
echo "  7 - Build ppc (Power PC - DM600, 7000, 7020, 7020si...)."
echo "  8 - Build ppc (Power PC OLD - DM500, 500S, DBox2...)."
echo "  9 - Build arm (Cortex-A9 - Wetek Play and similar)."
echo " 10 - Build mips-router (Routers MIPSEL DD-WRT)."
echo
echo "  a - Advanced Options."
echo "  i - About Build System NCam."
echo "  x - Exit"
echo 
echo "- Enter option:"
  read opt


  if [ "$?" != "1" ]
  then
    case $opt in
      1) build_dir/build_all.sh;;
      2) build_dir/build_x86.sh;;
      3) build_dir/build_x86_64.sh;;
      4) build_dir/build_mips.sh;;
      5) build_dir/build_mips-uclibc.sh;;
      6) build_dir/build_sh4.sh;;
      7) build_dir/build_ppc.sh;;
      8) build_dir/build_ppc-old.sh;;
      9) build_dir/build_cortexa9hf-vfp-neon.sh;;
      10) build_dir/build_mips-router.sh;;
      a) build_dir/advanced.sh $version; continue;;
      i) build_dir/info.sh $version; continue;;
      x) clear; echo; echo "Goodbye ;)"; echo; exit 1;;
      *) echo "Invalid option"; continue;;
    esac
  fi

done
