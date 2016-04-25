#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/home/lonas/toolchains/i686-unknown-linux-gnu/bin:$MYPATH
echo "#################### Eliminando Restos anteriores  ####################"
sh ./clean_all.sh > /dev/null 2>&1
sleep 3
make clean > /dev/null 2>&1
export ARCH=x32
export target=x32
echo ""
export TOOLCHAIN=/home/lonas/toolchains/i686-unknown-linux-gnu/bin/i686-unknown-linux-gnu-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-x86-tuxbox.cmake ..
make USE_PCSC=1 USE_LIBUSB=1 -j6 ARCH=x32 target=x32 CROSS_COMPILE=$TOOLCHAIN
chmod 755 install_x86.sh > /dev/null 2>&1
