/*
  File: linux/reiserfs_xattr.h
*/

#include <linux/init.h>
#include <linux/xattr.h>
#include <asm/types.h>

/* Magic value in header */
#define REISERFS_XATTR_MAGIC 0x52465841 /* "RFXA" */

struct reiserfs_xattr_header {
    __u32 h_magic;              /* magic number for identification */
    __u32 h_hash;               /* hash of the value */
};


