#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/home/lonas/toolchains/mipsel-unknown-linux-gnu/bin:$MYPATH
echo "#################### Eliminando Restos anteriores  ####################"
sh ./clean_all.sh > /dev/null 2>&1
sleep 3
make clean > /dev/null 2>&1
echo ""
export ARCH=mips
export target=mips
echo ""
export TOOLCHAIN=/home/lonas/toolchains/mipsel-unknown-linux-gnu/bin/mipsel-unknown-linux-gnu-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-mipsel-tuxbox.cmake ..
make -j6 ARCH=mips target=mips CROSS_COMPILE=$TOOLCHAIN
chmod 755 install_mips.sh
