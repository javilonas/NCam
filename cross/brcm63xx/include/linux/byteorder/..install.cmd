cmd_/build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-dev//include/linux/byteorder/.install := perl scripts/headers_install.pl /build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-3.3.8/include/linux/byteorder /build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-dev//include/linux/byteorder mips big_endian.h little_endian.h; perl scripts/headers_install.pl /build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-3.3.8/include/linux/byteorder /build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-dev//include/linux/byteorder mips ; perl scripts/headers_install.pl /build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-3.3.8/include/generated/linux/byteorder /build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-dev//include/linux/byteorder mips ; for F in ; do echo "\#include <asm-generic/$$F>" > /build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-dev//include/linux/byteorder/$$F; done; touch /build/brcm63xx/build_dir/toolchain-mips_gcc-4.6-linaro_uClibc-0.9.33.2/linux-dev//include/linux/byteorder/.install