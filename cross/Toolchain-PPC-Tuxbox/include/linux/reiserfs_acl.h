#include <linux/types.h>

#define REISERFS_ACL_VERSION	0x0001

typedef struct {
	__le16		e_tag;
	__le16		e_perm;
	__le32		e_id;
} reiserfs_acl_entry;

typedef struct {
	__le16		e_tag;
	__le16		e_perm;
} reiserfs_acl_entry_short;

typedef struct {
	__le32		a_version;
} reiserfs_acl_header;



