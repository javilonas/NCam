#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/home/lonas/toolchains/sh4-unknown-linux-gnu/bin:$MYPATH
echo "#################### Eliminando Restos anteriores  ####################"
sh ./clean_all.sh > /dev/null 2>&1
sleep 3
make clean > /dev/null 2>&1
export ARCH=sh4
export target=sh4
echo ""
export TOOLCHAIN=/home/lonas/toolchains/sh4-unknown-linux-gnu/bin/sh4-unknown-linux-gnu-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-sh4-tuxbox.cmake ..
make -j6 ARCH=sh4 target=sh4 CROSS_COMPILE=$TOOLCHAIN
chmod 755 install_sh4.sh
