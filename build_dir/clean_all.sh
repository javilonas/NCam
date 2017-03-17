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

export ROOTFS_PATH=/home/*/NCam
export PARCH_LOGS=$ROOTFS_PATH/build_dir/logs
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
echo ""
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
sh clean_distri.sh > /dev/null 2>&1
sync
echo " Clean all!!"
