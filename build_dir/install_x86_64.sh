#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/usr/bin:$MYPATH
make clean > /dev/null 2>&1
export ARCH=x64
export target=x64
echo ""
export TOOLCHAIN=/usr/bin/x86_64-linux-gnu-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-x86_64-tuxbox.cmake ..
make -j6 ARCH=x64 target=x64 CROSS_COMPILE=$TOOLCHAIN
chmod 755 install_x86_64.sh > /dev/null 2>&1
