#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/home/lonas/toolchains/powerpc-tuxbox-linux-gnu/bin:$MYPATH
echo "#################### Eliminando Restos anteriores  ####################"
sh ./clean_all.sh > /dev/null 2>&1
sleep 3
make clean > /dev/null 2>&1
export ARCH=ppc
export target=ppc
echo ""
export TOOLCHAIN=/home/lonas/toolchains/powerpc-tuxbox-linux-gnu/bin/powerpc-linux-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-ppc-tuxbox.cmake ..
make -j6 ARCH=ppc target=ppc CROSS_COMPILE=$TOOLCHAIN
chmod 755 install_ppc.sh
