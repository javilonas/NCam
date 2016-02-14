#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/home/lonas/toolchains/arm-unknown-linux-gnueabi/bin:$MYPATH
echo "#################### Eliminando Restos anteriores  ####################"
sh ./clean_all.sh > /dev/null 2>&1
sleep 3
make clean > /dev/null 2>&1
export ARCH=arm
export target=arm
echo ""
export TOOLCHAIN=/home/lonas/toolchains/arm-unknown-linux-gnueabi/bin/arm-unknown-linux-gnueabi-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-arm-tuxbox.cmake ..
make -j6 ARCH=arm target=arm CROSS_COMPILE=$TOOLCHAIN
chmod 755 install_armv7l.sh
