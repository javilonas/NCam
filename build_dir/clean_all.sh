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

export user=`id -g -n`
export ROOTFS_PATH=/home/$user/NCam
export PARCH_LOGS=$ROOTFS_PATH/build_dir/logs
export DISTRI=$ROOTFS_PATH/Distribution
export NCAM_BIN=ncam*
export SCRIPT=clean_all.sh
echo ""

rm -r $ROOTFS_PATH/build/* > /dev/null 2>&1
rm -f ncam.mips > /dev/null 2>&1
rm -f ncam.mips.debug > /dev/null 2>&1
rm -f ncam-libusb-pcsc.mips > /dev/null 2>&1
rm -f ncam-libusb-pcsc.mips.debug > /dev/null 2>&1
rm -f ncam.mips-uclibc > /dev/null 2>&1
rm -f ncam.mips-uclibc.debug > /dev/null 2>&1
rm -f ncam-libusb-pcsc.mips-uclibc > /dev/null 2>&1
rm -f ncam-libusb-pcsc.mips-uclibc.debug > /dev/null 2>&1
rm -f ncam-router.mips > /dev/null 2>&1
rm -f ncam-router.mips.debug > /dev/null 2>&1
rm -f ncam-router-libusb.mips > /dev/null 2>&1
rm -f ncam-router-libusb.mips.debug > /dev/null 2>&1
rm -f ncam.sh4 > /dev/null 2>&1
rm -f ncam.sh4.debug > /dev/null 2>&1
rm -f ncam-libusb-pcsc.sh4 > /dev/null 2>&1
rm -f ncam-libusb-pcsc.sh4.debug > /dev/null 2>&1
rm -f ncam.ppc > /dev/null 2>&1
rm -f ncam.ppc.debug > /dev/null 2>&1
rm -f ncam-libusb.ppc > /dev/null 2>&1
rm -f ncam-libusb.ppc.debug > /dev/null 2>&1
rm -f ncam.ppc-old > /dev/null 2>&1
rm -f ncam.ppc-old.debug > /dev/null 2>&1
rm -f ncam.cortexa9hf-vfp-neon > /dev/null 2>&1
rm -f ncam.cortexa9hf-vfp-neon.debug > /dev/null 2>&1
rm -f ncam-libusb.cortexa9hf-vfp-neon > /dev/null 2>&1
rm -f ncam-libusb.cortexa9hf-vfp-neon.debug > /dev/null 2>&1
rm -f ncam.x86 > /dev/null 2>&1
rm -f ncam.x86.debug > /dev/null 2>&1
rm -f ncam-libusb-pcsc.x86 > /dev/null 2>&1
rm -f ncam-libusb-pcsc.x86.debug > /dev/null 2>&1
rm -f ncam.x86_64 > /dev/null 2>&1
rm -f ncam.x86_64.debug > /dev/null 2>&1
rm -f ncam-libusb-pcsc.x86_64 > /dev/null 2>&1
rm -f ncam-libusb-pcsc.x86_64.debug > /dev/null 2>&1
rm -f ncam.arm-raspbian > /dev/null 2>&1
rm -f ncam.arm-raspbian.debug > /dev/null 2>&1
rm -f ncam-libusb.arm-raspbian > /dev/null 2>&1
rm -f ncam-libusb.arm-raspbian.debug > /dev/null 2>&1
rm -f ncam.arm-marvell > /dev/null 2>&1
rm -f ncam.arm-marvell.debug > /dev/null 2>&1
rm -f ncam-libusb.arm-marvell > /dev/null 2>&1
rm -f ncam-libusb.arm-marvell.debug > /dev/null 2>&1
rm -f ncam.arm-android > /dev/null 2>&1
rm -f ncam.arm-android.debug > /dev/null 2>&1
rm -f ncam-libusb.arm-android > /dev/null 2>&1
rm -f ncam-libusb.arm-android.debug > /dev/null 2>&1
rm -f ncam-router-OpenWrt-brcm47xx.mips > /dev/null 2>&1
rm -f ncam-router-OpenWrt-brcm47xx.mips.debug > /dev/null 2>&1
rm -f ncam-router-openwrt-brcm47xx-libusb.mips > /dev/null 2>&1
rm -f ncam-router-openwrt-brcm47xx-libusb.mips.debug > /dev/null 2>&1
rm -f ncam-router-OpenWrt-ar71xx.mips > /dev/null 2>&1
rm -f ncam-router-OpenWrt-ar71xx.mips.debug > /dev/null 2>&1
rm -f ncam-router-openwrt-ar71xx-libusb.mips > /dev/null 2>&1
rm -f ncam-router-openwrt-ar71xx-libusb.mips.debug > /dev/null 2>&1
rm -f ncam-router-OpenWrt-brcm63xx.mips > /dev/null 2>&1
rm -f ncam-router-OpenWrt-brcm63xx.mips.debug > /dev/null 2>&1
rm -f ncam-router-openwrt-brcm63xx-libusb.mips > /dev/null 2>&1
rm -f ncam-router-openwrt-brcm63xx-libusb.mips.debug > /dev/null 2>&1
rm -f ncam.arm-mca > /dev/null 2>&1
rm -f ncam.arm-mca.debug > /dev/null 2>&1
rm -f $ROOTFS_PATH/webif/pages_gen $ROOTFS_PATH/webif/pages.dep $ROOTFS_PATH/webif/pages.bin $ROOTFS_PATH/webif/pages.bin.compressed \
      $ROOTFS_PATH/webif/pages.h $ROOTFS_PATH/webif/pages.c $ROOTFS_PATH/webif/is_defined.txt > /dev/null 2>&1
echo ""
cd $ROOTFS_PATH/webif
make clean > /dev/null 2>&1
cd ..
make clean > /dev/null 2>&1
mkdir $ROOTFS_PATH/build > /dev/null 2>&1
echo ""
chmod 755 $ROOTFS_PATH/build_dir/$SCRIPT > /dev/null 2>&1
sleep 0.8s
echo ""
echo ""
echo " Remove Logs..."
echo ""
sleep 0.8s
echo ""
cd $PARCH_LOGS/
rm -f .build*.log > /dev/null 2>&1
cd ..
sync
echo ""
echo " Deleted logs"
echo ""
sleep 0.8s
echo ""
echo ""
cd $DISTRI/
rm -f $NCAM_BIN > /dev/null 2>&1
cd ..
chmod 755 $ROOTFS_PATH/build_dir/clean_distri.sh > /dev/null 2>&1
sh $ROOTFS_PATH/build_dir/clean_distri.sh > /dev/null 2>&1
sync
echo " Clean all!!"

