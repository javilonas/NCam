#ifndef _LINUX_BYTEORDER_SWAB_H
#define _LINUX_BYTEORDER_SWAB_H

/*
 * linux/byteorder/swab.h
 * Byte-swapping, independently from CPU endianness
 *	swabXX[ps]?(foo)
 *
 * Francois-Rene Rideau <fare@tunes.org> 19971205
 *    separated swab functions from cpu_to_XX,
 *    to clean up support for bizarre-endian architectures.
 *
 * See asm-i386/byteorder.h and suches for examples of how to provide
 * architecture-dependent optimized versions
 *
 */

/* for userspace, just use glibc macros */

#include <byteswap.h>

/* __bswap_constant_{16,32} are missing in generic <bits/byteswap.h> in glibc,
 * thus available only on x86 and few other archs */
#ifndef __bswap_constant_16
#define __bswap_constant_16(x) \
     ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))
#endif
#ifndef __bswap_constant_32
#define __bswap_constant_32(x) \
     ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) |		      \
      (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
#endif
#if (!defined(__bswap_constant_64)) && defined __GNUC__ && __GNUC__ >= 2
/* Swap bytes in 64 bit value.  */
#define __bswap_constant_64(x) \
     ((((x) & 0xff00000000000000ull) >> 56)				      \
      | (((x) & 0x00ff000000000000ull) >> 40)				      \
      | (((x) & 0x0000ff0000000000ull) >> 24)				      \
      | (((x) & 0x000000ff00000000ull) >> 8)				      \
      | (((x) & 0x00000000ff000000ull) << 8)				      \
      | (((x) & 0x0000000000ff0000ull) << 24)				      \
      | (((x) & 0x000000000000ff00ull) << 40)				      \
      | (((x) & 0x00000000000000ffull) << 56))
#endif

#define ___constant_swab16(x) __bswap_constant_16(x)
#define ___constant_swab32(x) __bswap_constant_32(x)
#define ___constant_swab64(x) __bswap_constant_64(x)

#define __swab16(x) bswap_16(x)
#define __swab32(x) bswap_32(x)
#define __swab64(x) bswap_64(x)

#define __swab16p(x) __swab16(*(x))
#define __swab32p(x) __swab32(*(x))
#define __swab64p(x) __swab64(*(x))

#define __swab16s(x) do { *(x) = __swab16p((x)); } while (0)
#define __swab32s(x) do { *(x) = __swab32p((x)); } while (0)
#define __swab64s(x) do { *(x) = __swab64p((x)); } while (0)

#endif /* _LINUX_BYTEORDER_SWAB_H */
