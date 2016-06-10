#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/home/lonas/toolchains/arm-none-linux-gnueabi-4.7.3/bin:$MYPATH
echo "#################### Eliminando Restos anteriores  ####################"
sh ./clean_all.sh > /dev/null 2>&1
sleep 3
make clean > /dev/null 2>&1
export ARCH=arm
export target=arm
echo ""
export TOOLCHAIN=/home/lonas/toolchains/arm-none-linux-gnueabi-4.7.3/bin/arm-none-linux-gnueabi-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-arm-mca.cmake ..
make USE_PCSC=1 USE_LIBUSB=1 -j6 ARCH=arm target=arm CROSS_COMPILE=$TOOLCHAIN
chmod 755 install_arm-mca.sh
