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
export PARCH_LOGS=$ROOTFS_PATH/build_dir/logs
export ARCH=mips
export target=mips
export NCAM_BIN=ncam-libusb-pcsc.mips
export CROSS=$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/bin/mipsel-tuxbox-linux-gnu-
export CC=$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/bin/mipsel-tuxbox-linux-gnu-gcc
export RANLIB=$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/bin/mipsel-tuxbox-linux-gnu-ranlib
export DCMAKE=cross-mipsel-tuxbox-linux-gnu-libusb-pcsc
export SCRIPT=build_mips-libusb-pcsc.sh

export EXTRA_LIBS="-lrt"

export OPENSSLDIR=$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/mipsel-tuxbox-linux-gnu/sysroot/usr/include/openssl/

export LIB_RT="$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/mipsel-tuxbox-linux-gnu/sysroot/usr/lib/librt.a -lrt"
export LIB_PTHREAD="$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/mipsel-tuxbox-linux-gnu/sysroot/usr/lib/libpthread.a -lrt"
export LIBCRYPT="$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/mipsel-tuxbox-linux-gnu/sysroot/usr/lib/libcrypt.a -lrt"

export LIBCRYPTO="$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/mipsel-tuxbox-linux-gnu/sysroot/usr/lib/libcrypto.a -lrt"
export LIB_SSL="$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/mipsel-tuxbox-linux-gnu/sysroot/usr/lib/libssl.a -lrt"

export PCSC_LIB="$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/mipsel-tuxbox-linux-gnu/sysroot/usr/lib/libpcsclite.a -lrt"
export LIBUSB_LIB="$ROOTFS_PATH/cross/mipsel-tuxbox-linux-gnu/mipsel-tuxbox-linux-gnu/sysroot/usr/lib/libusb-1.0.a -lrt"
export LIST_SMARGO=list_smargo-*-mipsel-tuxbox-linux-gnu-libusb-pcsc
export LIST_SMARGO2=list_smargo-*-mipsel-tuxbox-linux-gnu-ssl-libusb-pcsc

# BEGIN THE LOG
cd $PARCH_LOGS/
echo ">> LOG BUILD $NCAM_BIN >>" >> .build_$NCAM_BIN.$TIME_LOG.log 2>&1 || exit -1
(
echo ""
echo ""
echo "=============================================="
echo "   ASSIGNING PERMISSIONS"
echo "=============================================="
echo ""
echo ""
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
chmod 777 $PARCH_LOGS > /dev/null 2>&1
chmod 777 $ROOTFS_PATH/build > /dev/null 2>&1
chmod 777 $ROOTFS_PATH/Distribution > /dev/null 2>&1
sleep 0.8s
sync
echo " Permissions applied correctly"
echo ""
echo ""
echo "=============================================="
echo "   REMOVE OLD REMAINS"
echo "=============================================="
echo ""
echo ""
rm -f $ROOTFS_PATH/Distribution/$LIST_SMARGO > /dev/null 2>&1
rm -f $ROOTFS_PATH/Distribution/$LIST_SMARGO2 > /dev/null 2>&1
rm -f $ROOTFS_PATH/Distribution/$NCAM_BIN > /dev/null 2>&1
rm -f $ROOTFS_PATH/Distribution/$NCAM_BIN.debug > /dev/null 2>&1
rm -f $ROOTFS_PATH/webif/pages_gen $ROOTFS_PATH/webif/pages.dep $ROOTFS_PATH/webif/pages.bin $ROOTFS_PATH/webif/pages.bin.compressed \
      $ROOTFS_PATH/webif/pages.h $ROOTFS_PATH/webif/pages.c $ROOTFS_PATH/webif/is_defined.txt > /dev/null 2>&1
echo ""
cd $ROOTFS_PATH/webif
make clean > /dev/null 2>&1
cd ..
sleep 0.8s
sync
echo " Cleaning performed correctly"
echo ""
echo ""
sleep 0.8s
sync
cd $ROOTFS_PATH
echo ""
echo "=============================================="
echo "   START : BUILD"
echo "=============================================="
echo ""
echo ""
echo " starting Compilation"
echo ""
sleep 0.8s
sync
echo "+-------------------------------------------------------------------------------"
nice -n 10 make NCAM_BIN=$NCAM_BIN ARCH=$ARCH target=$target -j`grep 'processor' /proc/cpuinfo | wc -l` $DCMAKE || exit 1
sleep 0.8s
sync
echo ""
echo "=============================================="
echo "   END   : BUILD"
echo "=============================================="
echo ""
echo ""
find . -name "$NCAM_BIN*" -exec cp -av {} $ROOTFS_PATH/Distribution/ \; > /dev/null 2>&1
sleep 0.5s
sync
rm -f $NCAM_BIN > /dev/null 2>&1
rm -f $NCAM_BIN.debug > /dev/null 2>&1
rm -f $ROOTFS_PATH/Distribution/$NCAM_BIN.debug > /dev/null 2>&1
rm -f $ROOTFS_PATH/Distribution/$LIST_SMARGO > /dev/null 2>&1
rm -r $ROOTFS_PATH/build/* > /dev/null 2>&1
chmod 755 $ROOTFS_PATH/build_dir/$SCRIPT > /dev/null 2>&1
sleep 0.5s
sync
END_TIME=`date +%s`
echo ""
echo "Build Ncam Started  : $INIT_TIME"
echo "Build Ncam Finished : `date +'%d/%m/%y %H:%M:%S'`"
let "ELAPSED_TIME=$END_TIME-$START_TIME"
echo "Total compile time is $ELAPSED_TIME seconds"
echo ""
find . -name "$NCAM_BIN*"
echo ""
) 2>&1	 | tee -a .build_$NCAM_BIN.$TIME_LOG.log
