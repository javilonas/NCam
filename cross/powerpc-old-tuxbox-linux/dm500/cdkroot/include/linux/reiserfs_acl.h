#include <asm/types.h>

#define REISERFS_ACL_VERSION	0x0001

typedef struct {
	__u16		e_tag;
	__u16		e_perm;
	__u32		e_id;
} reiserfs_acl_entry;

typedef struct {
	__u16		e_tag;
	__u16		e_perm;
} reiserfs_acl_entry_short;

typedef struct {
	__u32		a_version;
} reiserfs_acl_header;



