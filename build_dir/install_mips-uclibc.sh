#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
export MYPATH=$PATH
export PATH=/home/lonas/toolchains/stbgcc-4.5.3-2.4/bin:$MYPATH
echo "#################### Eliminando Restos anteriores  ####################"
sh ./clean_all.sh > /dev/null 2>&1
sleep 3
make clean > /dev/null 2>&1
export ARCH=mips
export target=mips
echo ""
export TOOLCHAIN=/home/lonas/toolchains/stbgcc-4.5.3-2.4/bin/mipsel-linux-uclibc-
echo ""
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchains/toolchain-mips-tiviar.cmake ..
make -j6 ARCH=mips target=mips CROSS_COMPILE=$TOOLCHAIN 
chmod 755 install_mips-uclibc.sh
