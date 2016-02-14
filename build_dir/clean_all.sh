#!/bin/bash
echo "#################### Asignando permisos correctos  ####################"
find . -type f -name '*.h' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.c' -exec chmod 644 {} \; > /dev/null 2>&1
find . -type f -name '*.sh' -exec chmod 755 {} \; > /dev/null 2>&1
echo ""
rm -r utils/CMakeFiles > /dev/null 2>&1
rm -r CMakeFiles > /dev/null 2>&1
rm -r cscrypt > /dev/null 2>&1
rm -r csctapi > /dev/null 2>&1
rm -r ffdecsa > /dev/null 2>&1
rm -r minilzo > /dev/null 2>&1
rm -f utils/cmake_install.cmake > /dev/null 2>&1
rm -f utils/list_smargo > /dev/null 2>&1
rm -f utils/Makefile > /dev/null 2>&1
rm -f CMakeCache.txt > /dev/null 2>&1
rm -f cmake_install.cmake > /dev/null 2>&1
rm -f config.c > /dev/null 2>&1
rm -f config.mak > /dev/null 2>&1
rm -f CPackConfig.cmake > /dev/null 2>&1
rm -f CPackSourceConfig.cmake > /dev/null 2>&1
rm -f libcsmodules.a > /dev/null 2>&1
rm -f libcsncam.a > /dev/null 2>&1
rm -f libcsreaders.a > /dev/null 2>&1
rm -f Makefile > /dev/null 2>&1
rm -f ncam > /dev/null 2>&1
rm -f SoftCam.Key > /dev/null 2>&1
make clean > /dev/null 2>&1
echo ""
echo ""
