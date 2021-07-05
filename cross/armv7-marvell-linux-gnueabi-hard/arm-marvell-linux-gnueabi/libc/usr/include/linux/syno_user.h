/* Copyright (c) 2010 Synology Inc. All rights reserved. */

#ifndef __SYNO_USER_H_
#define __SYNO_USER_H_

/**
 * Dsc: Synology multimedia server feature. For indexing video, photo,
 *      music.
 * Ref: libsynosdk, lnxnetatalk, lnxsdk, rsync, samba, smbftpd
 */
#define SYNO_INDEXING
#define SYNO_INDEX_SHARES		"photo,video,music"

/**
 * Dsc: This definition is used to enhance samba's performance. 
 *      This modify should sync with samba
 */
#define SYNO_SMB_PERF

/**
 * Dsc: This modify should sync with netatalk
 */
#define SYNO_EA

/**
 * Dsc: This modify should sync with samba
 */
#ifndef SYNO_UNICODE
#define SYNO_UNICODE
#endif

#ifdef SYNO_UNICODE
#define SYNO_MAXPATH    4095
#define SYNO_MAXNAME    491
#endif

/**
 * Fix: DS20 bug #1405
 * Dsc: Avoid scan all inodes of ext3 while doing quotacheck
 */
#define SYNO_DS20_BUG_1405

#if defined(SYNO_X64)
#define SYNO_RESIZE_INODE_SIZE_EXTEND_USER
#endif

#define SYNO_PPPOL2PT_FIX

#endif /* __SYNO_USER_H_ */
