#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
 
#ifndef __SYNO_H_
#define __SYNO_H_

#include <linux/syno_autoconf.h>

#ifndef LINUX_VERSION_CODE
#include <linux/version.h>
#endif
#define SYNO_HAVE_KERNEL_VERSION(a,b,c) (LINUX_VERSION_CODE >= KERNEL_VERSION((a),(b),(c)) )
#define SYNO_HAVE_GCC_VERSION(a,b) (__GNUC__ > (a) || (__GNUC__ == (a) && __GNUC_MINOR__ >= (b)))
#define SYNO_HAVE_GLIBC_VERSION(a,b) ( __GLIBC__ > (a) || (__GLIBC__ == (a) && __GLIBC_MINOR__ >= (b)))

#define SYNO_INDEX_SHARES		"photo,video,music"

#ifdef MY_ABC_HERE
#define SYNO_MAXPATH    4095
#define SYNO_MAXNAME    491
#endif

#ifdef CONFIG_SYNO_FS_ARCHIVE_BIT
#if defined (F_CLEAR_ARCHIVE) || defined (F_SETSMB_ARCHIVE) || defined (F_SETSMB_HIDDEN) || \
	defined (F_SETSMB_SYSTEM) || defined (F_CLRSMB_ARCHIVE) || defined (F_CLRSMB_HIDDEN) || \
	defined (F_CLRSMB_SYSTEM) || defined (F_CLEAR_S3_ARCHIVE) || \
	defined (F_SETSMB_SPARSE) || defined (F_CLRSMB_SPARSE)
#error "Samba archive bit redefine."
#endif

#ifdef CONFIG_SYNO_FS_WINACL

#if defined (F_CLRSMB_READONLY) || defined (F_SETSMB_READONLY) || \
	defined (F_CLRACL_INHERIT)  || defined (F_SETACL_INHERIT)  || \
	defined (F_CLRACL_OWNER_IS_GROUP) || defined (F_SETACL_OWNER_IS_GROUP)  || \
	defined (F_SETACL_SUPPORT) || defined (F_SETACL_SUPPORT)
#error "ACL archive bit redefine."
#endif  
#endif  

#define SYNO_FCNTL_BASE             513
#define F_CLEAR_ARCHIVE             (SYNO_FCNTL_BASE + 0)
#define F_SETSMB_ARCHIVE            (SYNO_FCNTL_BASE + 1)
#define F_SETSMB_HIDDEN             (SYNO_FCNTL_BASE + 2)
#define F_SETSMB_SYSTEM             (SYNO_FCNTL_BASE + 3)
#define F_CLRSMB_ARCHIVE            (SYNO_FCNTL_BASE + 4)
#define F_CLRSMB_HIDDEN             (SYNO_FCNTL_BASE + 5)
#define F_CLRSMB_SYSTEM             (SYNO_FCNTL_BASE + 6)
#define F_CLEAR_S3_ARCHIVE          (SYNO_FCNTL_BASE + 7)

#ifdef CONFIG_SYNO_FS_WINACL
#define F_CLRSMB_READONLY           (SYNO_FCNTL_BASE + 8)
#define F_SETSMB_READONLY           (SYNO_FCNTL_BASE + 9)
#define F_CLRACL_INHERIT            (SYNO_FCNTL_BASE + 10)
#define F_SETACL_INHERIT            (SYNO_FCNTL_BASE + 11)
#define F_CLRACL_HAS_ACL            (SYNO_FCNTL_BASE + 12)
#define F_SETACL_HAS_ACL            (SYNO_FCNTL_BASE + 13)
#define F_CLRACL_SUPPORT            (SYNO_FCNTL_BASE + 14)
#define F_SETACL_SUPPORT            (SYNO_FCNTL_BASE + 15)
#define F_CLRACL_OWNER_IS_GROUP     (SYNO_FCNTL_BASE + 16)
#define F_SETACL_OWNER_IS_GROUP     (SYNO_FCNTL_BASE + 17)
#define F_SETSMB_SPARSE				(SYNO_FCNTL_BASE + 18)
#define F_CLRSMB_SPARSE				(SYNO_FCNTL_BASE + 19)
#define SYNO_FCNTL_LAST             F_CLRSMB_SPARSE
#else
#define F_SETSMB_SPARSE				(SYNO_FCNTL_BASE + 8)
#define F_CLRSMB_SPARSE				(SYNO_FCNTL_BASE + 9)

#define SYNO_FCNTL_LAST             F_CLRSMB_SPARSE
#endif  

#endif  

#ifdef CONFIG_SYNO_USB_COPY
#define USBCOPY_PORT_LOCATION 99
#endif  

#ifdef CONFIG_SYNO_USB_SD_COPY
#define SDCOPY_PORT_LOCATION 98
#endif  

#endif  
