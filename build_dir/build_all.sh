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

# PREFERENCES FOR SCRIPT
export INIT_TIME=`date +'%d/%m/%y %H:%M:%S'`
export START_TIME=`date +%s`
export TIME_LOG=`date +%Y%m%d_%H%M`
export user=`id -g -n`
export ROOTFS_PATH=/home/$user/NCam
export BUILD_DIR=$ROOTFS_PATH/build_dir
export PARCH_LOGS=$ROOTFS_PATH/build_dir/logs
export NCAM_ALL=ncam_all
export SCRIPT=build_all.sh

echo ""
echo " This may take..."
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
echo ""
echo ""
sleep 0.8s
# BEGIN THE LOG
cd $PARCH_LOGS/
echo ">> LOG BUILD $NCAM_ALL >>" >> .build_$NCAM_ALL.$TIME_LOG.log 2>&1 || exit -1
(
echo ""
echo ""
echo "=============================================="
echo "   START BUILD ALL"
echo "=============================================="
echo ""
echo ""
echo " Build MIPS..."
echo ""
sh $BUILD_DIR/build_mips.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-LIBUSB-PCSC..."
echo ""
sh $BUILD_DIR/build_mips-libusb-pcsc.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-CORTEXA9HF-VFP-NEON..."
echo ""
sh $BUILD_DIR/build_cortexa9hf-vfp-neon.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-CORTEXA9HF-VFP-NEON-LIBUSB..."
echo ""
sh $BUILD_DIR/build_cortexa9hf-vfp-neon-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-ROUTER (DD-WRT)..."
echo ""
sh $BUILD_DIR/build_mips-router.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-ROUTER-LIBUSB (DD-WRT)..."
echo ""
sh $BUILD_DIR/build_mips-router-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-UCLIBC..."
echo ""
sh $BUILD_DIR/build_mips-uclibc.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-UCLIBC-LIBUSB-PCSC..."
echo ""
sh $BUILD_DIR/build_mips-uclibc-libusb-pcsc.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build PPC..."
echo ""
sh $BUILD_DIR/build_ppc.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build PPC-LIBUSB..."
echo ""
sh $BUILD_DIR/build_ppc-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build PPC-OLD..."
echo ""
sh $BUILD_DIR/build_ppc-old.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build PPC-OLD-LIBUSB..."
echo ""
sh $BUILD_DIR/build_ppc-old-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build PPC-OLD-EXP..."
echo ""
sh $BUILD_DIR/build_ppc-old-exp.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build PPC-OLD-EXP-LIBUSB..."
echo ""
sh $BUILD_DIR/build_ppc-old-exp-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build SH4..."
echo ""
sh $BUILD_DIR/build_sh4.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build SH4-LIBUSB-PCSC..."
echo ""
sh $BUILD_DIR/build_sh4-libusb-pcsc.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build X86..."
echo ""
sh $BUILD_DIR/build_x86.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build X86-LIBUSB-PCSC..."
echo ""
sh $BUILD_DIR/build_x86-libusb-pcsc.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build X86_64..."
echo ""
sh $BUILD_DIR/build_x86_64.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build X86_64-LIBUSB-PCSC..."
echo ""
sh $BUILD_DIR/build_x86_64-libusb-pcsc.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-RASP..."
echo ""
sh $BUILD_DIR/build_arm-raspbian.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-RASP-LIBUSB..."
echo ""
sh $BUILD_DIR/build_arm-raspbian-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-MARVELL..."
echo ""
sh $BUILD_DIR/build_arm-marvell.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-MARVELL-LIBUSB..."
echo ""
sh $BUILD_DIR/build_arm-marvell-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-ARMADA37XX..."
echo ""
sh $BUILD_DIR/build_arm-armada37xx.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-ARMADA37XX-LIBUSB..."
echo ""
sh $BUILD_DIR/build_arm-armada37xx-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-ANDROID..."
echo ""
sh $BUILD_DIR/build_arm-android.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-ANDROID-LIBUSB..."
echo ""
sh $BUILD_DIR/build_arm-android-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
echo ""
sleep 35
sync
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-ROUTER (DD-WRT-ar71xx)..."
echo ""
sh $BUILD_DIR/build_mips-router-openwrt-ar71xx.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-ROUTER-LIBUSB (DD-WRT-ar71xx)..."
echo ""
sh $BUILD_DIR/build_mips-router-openwrt-ar71xx-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
sleep 35
sync
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-ROUTER (DD-WRT-brcm47xx)..."
echo ""
sh $BUILD_DIR/build_mips-router-openwrt-brcm47xx.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-ROUTER-LIBUSB (DD-WRT-brcm47xx)..."
echo ""
sh $BUILD_DIR/build_mips-router-openwrt-brcm47xx-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-ROUTER (DD-WRT-brcm47xx)..."
echo ""
sh $BUILD_DIR/build_mips-router-openwrt-brcm63xx.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build MIPS-ROUTER-LIBUSB (DD-WRT-brcm63xx)..."
echo ""
sh $BUILD_DIR/build_mips-router-openwrt-brcm63xx-libusb.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build ARM-MCA (Matrix CAM Air)..."
echo ""
sh $BUILD_DIR/build_arm-mca.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build SamsungTV..."
echo ""
sh $BUILD_DIR/build_arm-samsungtv.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo ""
sleep 35
sync
echo ""
echo " Build x86_64 Synology-ATOM..."
echo ""
sh $BUILD_DIR/build_x86_64_syn_atom.sh > /dev/null 2>&1
sync
echo ""
echo ""
echo ""
sleep 0.8s
echo ""
echo ""
echo ""
echo " PLEASE WAIT..."
echo ""
sync
echo ""
echo " We are finalizing..."
echo ""
sleep 35
sync
echo ""
echo ""
echo "=============================================="
echo "   END BUILD ALL"
echo "=============================================="
echo ""
echo ""
chmod 755 $ROOTFS_PATH/build_dir/$SCRIPT > /dev/null 2>&1
echo ""
sleep 0.8s
sync
END_TIME=`date +%s`
echo ""
echo "Build Ncam all Started  : $INIT_TIME"
echo "Build Ncam all Finished : `date +'%d/%m/%y %H:%M:%S'`"
let "ELAPSED_TIME=$END_TIME-$START_TIME"
echo "Total compile time is $ELAPSED_TIME seconds"
echo ""
find . -name "ncam*"
echo ""
) 2>&1	 | tee -a .build_$NCAM_ALL.$TIME_LOG.log
