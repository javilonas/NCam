#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/home/lonas/toolchains/powerpc-old-tuxbox-linux/dm500/cdk/bin:$MYPATH
echo "#################### Eliminando Restos anteriores  ####################"
sh ./clean_all.sh > /dev/null 2>&1
sleep 3
make clean > /dev/null 2>&1
export ARCH=ppc
export target=ppc-old
echo ""
export TOOLCHAIN=/home/lonas/toolchains/powerpc-old-tuxbox-linux/dm500/cdk/bin/powerpc-tuxbox-linux-gnu-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-powerpc-tuxbox.cmake ..
make -j6 ARCH=ppc target=ppc-old CROSS_COMPILE=$TOOLCHAIN
chmod 755 install_ppc-old.sh
