cmd_/home/gccbuilder-i386/work/mgcc4.6/Release/build/armv7-marvell-linux-gnueabi-hard_i686_64K/obj/linux-header-install/include/linux/mmc/.install := perl scripts/headers_install.pl /home/gccbuilder-i386/work/mgcc4.6/Release/build/armv7-marvell-linux-gnueabi-hard_i686_64K/obj/linux-tmp-src/include/linux/mmc /home/gccbuilder-i386/work/mgcc4.6/Release/build/armv7-marvell-linux-gnueabi-hard_i686_64K/obj/linux-header-install/include/linux/mmc arm ioctl.h; perl scripts/headers_install.pl /home/gccbuilder-i386/work/mgcc4.6/Release/build/armv7-marvell-linux-gnueabi-hard_i686_64K/obj/linux-tmp-src/include/linux/mmc /home/gccbuilder-i386/work/mgcc4.6/Release/build/armv7-marvell-linux-gnueabi-hard_i686_64K/obj/linux-header-install/include/linux/mmc arm ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/gccbuilder-i386/work/mgcc4.6/Release/build/armv7-marvell-linux-gnueabi-hard_i686_64K/obj/linux-header-install/include/linux/mmc/$$F; done; touch /home/gccbuilder-i386/work/mgcc4.6/Release/build/armv7-marvell-linux-gnueabi-hard_i686_64K/obj/linux-header-install/include/linux/mmc/.install
