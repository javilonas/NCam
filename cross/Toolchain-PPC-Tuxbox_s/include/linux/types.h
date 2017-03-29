#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <sys/types.h>
#include <linux/posix_types.h>
#include <asm/types.h>

#ifndef __KERNEL_STRICT_NAMES

typedef __u32 __kernel_dev_t;

#if defined(WANT_KERNEL_TYPES) || !defined(__GLIBC__)
typedef __kernel_fd_set		fd_set;		/* <sys/select.h> */
typedef __kernel_dev_t		dev_t;		/* <sys/stat.h>, <sys/types.h> */
typedef __kernel_ino_t		ino_t;		/* <dirent.h>, <sys/stat.h>, <sys/types.h> */
typedef __kernel_mode_t		mode_t;		/* <sys/ipc.h>, <sys/mman.h>, <sys/stat.h>, <sys/types.h> */
typedef __kernel_nlink_t	nlink_t;	/* <sys/stat.h>, <sys/types.h> */
typedef __kernel_off_t		off_t;		/* <unistd.h>, <sys/mman.h>, <sys/stat.h>, <sys/types.h> */
typedef __kernel_pid_t		pid_t;		/* <signal.h>, <time.h>, <unistd.h>... (lots) */
typedef __kernel_daddr_t	daddr_t;	/* <sys/types.h> */
typedef __kernel_key_t		key_t;		/* <sys/ipc.h>, <sys/types.h> */
typedef __kernel_suseconds_t	suseconds_t;	/* <sys/select.h>, <sys/time.h>, <sys/types.h> */
typedef __kernel_timer_t	timer_t;	/* <time.h> [also from <sys/types.h>] */
typedef __kernel_clockid_t	clockid_t;	/* <time.h> [also from <sys/types.h>] */
typedef	__kernel_mqd_t		mqd_t;

typedef __kernel_uid_t		uid_t;		/* <pwd.h>, <signal.h>, <strops.h>... (lots) */
typedef __kernel_gid_t		gid_t;		/* <grp.h>, <pwd.h>, <strops.h>... (lots) */

#if (defined(__GNUC__) && !defined(__STRICT_ANSI__)) || (__STDC_VERSION__ >= 199901L)
typedef __kernel_loff_t		loff_t;		/* <sys/types.h> */
#endif

/*
 * The following typedefs are also protected by individual ifdefs for
 * historical reasons:
 */
#ifndef _SIZE_T
#define _SIZE_T
typedef __kernel_size_t		size_t;		/* <stddef.h> (gcc) */
#endif

#ifndef _SSIZE_T
#define _SSIZE_T
typedef __kernel_ssize_t	ssize_t;	/* <unistd.h>, <sys/types.h> */
#endif

#ifndef _PTRDIFF_T
#define _PTRDIFF_T
typedef __kernel_ptrdiff_t	ptrdiff_t;	/* <stddef.h> (gcc) */
#endif

#ifndef _TIME_T
#define _TIME_T
typedef __kernel_time_t		time_t;		/* <time.h>... (indirectly others) */
#endif

#ifndef _CLOCK_T
#define _CLOCK_T
typedef __kernel_clock_t	clock_t;	/* <time.h> [also from <times.h>, <sys/types.h>] */
#endif

#ifndef _CADDR_T
#define _CADDR_T
typedef __kernel_caddr_t	caddr_t;	/* <sys/types.h> */
#endif

/* bsd */
typedef unsigned char		u_char;		/* <sys/types.h> (if __USE_BSD) */
typedef unsigned short		u_short;	/* <sys/types.h> (if __USE_BSD) */
typedef unsigned int		u_int;		/* <sys/types.h> (if __USE_BSD) */
typedef unsigned long		u_long;		/* <sys/types.h> (if __USE_BSD) */

/* sysv */
typedef unsigned char		unchar;
typedef unsigned short		ushort;		/* <sys/types.h> (if __USE_MISC) */
typedef unsigned int		uint;		/* <sys/types.h> (if __USE_MISC) */
typedef unsigned long		ulong;		/* <sys/types.h> (if __USE_MISC) */

#ifndef __BIT_TYPES_DEFINED__
#define __BIT_TYPES_DEFINED__

typedef		__u8		u_int8_t;	/* <sys/types.h> */
typedef		__s8		int8_t;		/* <stdint.h>, <sys/types.h> */
typedef		__u16		u_int16_t;	/* <sys/types.h> */
typedef		__s16		int16_t;	/* <stdint.h>, <sys/types.h> */
typedef		__u32		u_int32_t;	/* <sys/types.h> */
typedef		__s32		int32_t;	/* <stdint.h>, <sys/types.h> */

#endif /* !(__BIT_TYPES_DEFINED__) */

typedef		__u8		uint8_t;	/* <stdint.h> */
typedef		__u16		uint16_t;	/* <stdint.h> */
typedef		__u32		uint32_t;	/* <stdint.h> */

#if (defined(__GNUC__) && !defined(__STRICT_ANSI__)) || (__STDC_VERSION__ >= 199901L)
typedef		__u64		uint64_t;	/* <stdint.h> */
typedef		__u64		u_int64_t;	/* <sys/types.h> */
typedef		__s64		int64_t;	/* <stdint.h>, <sys/types.h> */
#endif

/*
 * The type used for indexing onto a disc or disc partition.
 * If required, asm/types.h can override it and define
 * HAVE_SECTOR_T
 */
#ifndef HAVE_SECTOR_T
typedef unsigned long sector_t;
#endif

/*
 * The type of an index into the pagecache.  Use a #define so asm/types.h
 * can override it.
 */
#ifndef pgoff_t
#define pgoff_t unsigned long
#endif

#else /* WANT_KERNEL_TYPES || !defined(__GLIBC__) */

typedef unsigned char		unchar;		/* sysv, not defined in glibc */
#ifndef HAVE_SECTOR_T
typedef unsigned long sector_t;
#endif
#ifndef pgoff_t
#define pgoff_t unsigned long
#endif

#endif /* WANT_KERNEL_TYPES || !defined(__GLIBC__) */

#endif /* __KERNEL_STRICT_NAMES */

#ifdef __CHECKER__
#define __bitwise __attribute__((bitwise))
#else
#define __bitwise
#endif

typedef __u16 __bitwise __le16;
typedef __u16 __bitwise __be16;
typedef __u32 __bitwise __le32;
typedef __u32 __bitwise __be32;

#if defined(__GNUC__)
#if !defined(__STRICT_ANSI__) || (__STDC_VERSION__ >= 199901L) || defined(__LLH_TYPE_LONG_IS_64BIT__)
typedef __u64 __bitwise __le64;
typedef __u64 __bitwise __be64;
#endif
#endif


/*
 * Below are truly Linux-specific types that should never collide with
 * any application/library that wants linux/types.h.
 */

#if 0
/* Debian: This is available from <sys/ustat.h>.  */
struct ustat {
	__kernel_daddr_t	f_tfree;
	__kernel_ino_t		f_tinode;
	char			f_fname[6];
	char			f_fpack[6];
};
#endif

#endif /* _LINUX_TYPES_H */
