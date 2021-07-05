#ifndef _LINUX_STAT_H
#define _LINUX_STAT_H

#if defined(__KERNEL__) || !defined(__GLIBC__) || (__GLIBC__ < 2)

#define S_IFMT  00170000
#define S_IFSOCK 0140000
#define S_IFLNK	 0120000
#define S_IFREG  0100000
#define S_IFBLK  0060000
#define S_IFDIR  0040000
#define S_IFCHR  0020000
#define S_IFIFO  0010000
#define S_ISUID  0004000
#define S_ISGID  0002000
#define S_ISVTX  0001000

#define S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)
#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)

#define S_IRWXU 00700
#define S_IRUSR 00400
#define S_IWUSR 00200
#define S_IXUSR 00100

#define S_IRWXG 00070
#define S_IRGRP 00040
#define S_IWGRP 00020
#define S_IXGRP 00010

#define S_IRWXO 00007
#define S_IROTH 00004
#define S_IWOTH 00002
#define S_IXOTH 00001

#endif

#ifdef CONFIG_SYNO_FS_ARCHIVE_BIT
/* Ext4 has only 16 bits for archive bit. */
#define S2_IARCHIVE    (1<<0)	// synology backup archive bit
#define S2_SMB_ARCHIVE (1<<1)	// samba backup archive bit (some other windows ap)
#define S2_SMB_HIDDEN  (1<<2)	// hidden attribute in samba
#define S2_SMB_SYSTEM  (1<<3)	// system attribute in samba
#define S3_IARCHIVE    (1<<4)	// synology S3 backup archive bit (amazon ap)
#ifdef CONFIG_SYNO_FS_WINACL
#define S2_SMB_READONLY    					(1<<5)	// Read-Only attribute of samba
#define S2_SYNO_ACL_INHERIT				    (1<<6)	// inherited from parent
#define S2_SYNO_ACL_IS_OWNER_GROUP			(1<<7)	// owner tag of SYNO ACL
#define S2_SYNO_ACL_EXIST					(1<<8)	// is there SYNO ACL
#define S2_SYNO_ACL_SUPPORT  				(1<<9)	// is support ACL
#define ALL_SYNO_ACL_ARCHIVE	(S2_SMB_READONLY|S2_SYNO_ACL_INHERIT|S2_SYNO_ACL_IS_OWNER_GROUP|S2_SYNO_ACL_EXIST|S2_SYNO_ACL_SUPPORT)
#endif /* CONFIG_SYNO_FS_WINACL */
#define S2_SMB_SPARSE						(1<<10)	// sparse file support bit used by samba 4.4
#define ALL_IARCHIVE (S2_IARCHIVE|S3_IARCHIVE)	// All synology archive bit.
#define ALL_SYNO_ARCHIVE (S2_IARCHIVE|S2_SMB_ARCHIVE|S3_IARCHIVE)	// All backup archive bit, if there is new one, it should be added here.
#ifdef CONFIG_SYNO_FS_WINACL
#define ALL_ARCHIVE_BIT (S2_IARCHIVE|S2_SMB_ARCHIVE|S2_SMB_HIDDEN|S2_SMB_SYSTEM|S3_IARCHIVE|ALL_SYNO_ACL_ARCHIVE|S2_SMB_SPARSE)
#else
#define ALL_ARCHIVE_BIT (S2_IARCHIVE|S2_SMB_ARCHIVE|S2_SMB_HIDDEN|S2_SMB_SYSTEM|S3_IARCHIVE|S2_SMB_SPARSE)
#endif /* CONFIG_SYNO_FS_WINACL */

#endif /* CONFIG_SYNO_FS_ARCHIVE_BIT */

#endif /* _LINUX_STAT_H */
