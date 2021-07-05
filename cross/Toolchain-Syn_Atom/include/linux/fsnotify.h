#ifndef _LINUX_FS_NOTIFY_H
#define _LINUX_FS_NOTIFY_H

/*
 * include/linux/fsnotify.h - generic hooks for filesystem notification, to
 * reduce in-source duplication from both dnotify and inotify.
 *
 * We don't compile any of this away in some complicated menagerie of ifdefs.
 * Instead, we rely on the code inside to optimize away as needed.
 *
 * (C) Copyright 2005 Robert Love
 */

#include <linux/fsnotify_backend.h>
#include <linux/audit.h>
#include <linux/slab.h>
#include <linux/nsproxy.h>
#include <linux/mount.h>
#include <linux/mnt_namespace.h>
#include <linux/path.h>
#include <linux/namei.h>
#include <linux/fs_struct.h>

#ifdef MY_ABC_HERE
#include <linux/xattr.h>
#endif

#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
static inline void SYNO_ArchiveModify(struct inode *TargetInode)
{
#ifdef MY_ABC_HERE
	int old_version;
	int new_version;
#endif
	int markDirty = 0;
	if (NULL == TargetInode) {
		return;
	}
	if (S_ISCHR(TargetInode->i_mode) || S_ISBLK(TargetInode->i_mode) ||
		S_ISFIFO(TargetInode->i_mode) || S_ISSOCK(TargetInode->i_mode)) {
		return;
	}
#ifdef MY_ABC_HERE
	mutex_lock(&TargetInode->i_syno_mutex);
	TargetInode->i_mode2 |= ALL_SYNO_ARCHIVE;
	mutex_unlock(&TargetInode->i_syno_mutex);
	markDirty = 1;
#endif
#ifdef MY_ABC_HERE
	old_version = TargetInode->i_archive_version;
	new_version = TargetInode->i_sb->s_archive_version + 1;
	if (old_version != new_version) {
		TargetInode->i_archive_version = new_version;
		if (TargetInode->i_op->synosetxattr) {
			struct syno_xattr_archive_version value;
			value.v_magic = cpu_to_le16(0x2552);
			value.v_struct_version = cpu_to_le16(1);
			value.v_archive_version = cpu_to_le32(new_version);
			TargetInode->i_op->synosetxattr(TargetInode, XATTR_SYNO_PREFIX XATTR_SYNO_ARCHIVE_VERSION, &value, sizeof(value), 0);
		}
		markDirty = 1;
}
#endif

	if(markDirty) {
		mark_inode_dirty_sync(TargetInode);
	}
}
#endif

#ifdef CONFIG_SYNO_NOTIFY
/* Retrieve vfsmount by given super block, remember to invoke mntput afterward.
 * Note: In the case that different mount has same super block, it will get the first matching vfsmount
 * It is undefined behavior on mount bind case.
 */
static inline struct vfsmount *get_vfsmount_by_sb(struct super_block *sb)
{
	struct list_head *head = NULL;
	struct vfsmount *mnt = NULL;
	struct nsproxy *nsproxy = NULL;
	if (!sb)
		return NULL;

	nsproxy = current->nsproxy;
	if (nsproxy) {
		struct mnt_namespace *mnt_space = nsproxy->mnt_ns;
		if(mnt_space){
			list_for_each(head, &mnt_space->list) {
				mnt = list_entry(head, struct vfsmount, mnt_list);
				if (mnt && mnt->mnt_sb == sb) {
					return mnt;
				}
			}
		}
	}
	return NULL;
}

/* Do syno notify according to given dentry and mask */
static inline int SYNONotify(struct dentry *dentry, __u32 mask)
{
	char *dentry_path = NULL;
	struct path path;
	char *dentry_buf = NULL;
	int ret = 0;
	memset (&path, 0, sizeof(struct path));
	if(!dentry){
		ret = -EINVAL;
		goto ERR;
	}
	path.mnt = get_vfsmount_by_sb(dentry->d_sb);
	if(!path.mnt){
		ret = -EINVAL;
		goto ERR;
	}
	mntget(path.mnt);
	dentry_buf = kmalloc(PATH_MAX, GFP_NOFS);
	if(!dentry_buf){
		ret = -ENOMEM;
		goto ERR;
	}
	dentry_path = dentry_path_raw(dentry, dentry_buf, PATH_MAX-1);
	if (IS_ERR(dentry_path)) {
		ret = PTR_ERR(dentry_path);
		goto ERR;
	}
	SYNOFsnotify(mask, &path, FSNOTIFY_EVENT_SYNO, dentry_path, 0);
ERR:
	if (path.mnt)
		mntput(path.mnt);
	kfree(dentry_buf);
	return ret;
}
#endif /* CONFIG_SYNO_NOTIFY */

/*
 * fsnotify_d_instantiate - instantiate a dentry for inode
 */
static inline void fsnotify_d_instantiate(struct dentry *dentry,
					  struct inode *inode)
{
	__fsnotify_d_instantiate(dentry, inode);
}

/* Notify this dentry's parent about a child's events. */
static inline int fsnotify_parent(struct path *path, struct dentry *dentry, __u32 mask)
{
	if (!dentry)
		dentry = path->dentry;

	return __fsnotify_parent(path, dentry, mask);
}

/* simple call site for access decisions */
static inline int fsnotify_perm(struct file *file, int mask)
{
	struct path *path = &file->f_path;
	struct inode *inode = path->dentry->d_inode;
	__u32 fsnotify_mask = 0;
	int ret;

	if (file->f_mode & FMODE_NONOTIFY)
		return 0;
	if (!(mask & (MAY_READ | MAY_OPEN)))
		return 0;
	if (mask & MAY_OPEN)
		fsnotify_mask = FS_OPEN_PERM;
	else if (mask & MAY_READ)
		fsnotify_mask = FS_ACCESS_PERM;
	else
		BUG();

	ret = fsnotify_parent(path, NULL, fsnotify_mask);
	if (ret)
		return ret;

	return fsnotify(inode, fsnotify_mask, path, FSNOTIFY_EVENT_PATH, NULL, 0);
}

/*
 * fsnotify_d_move - dentry has been moved
 */
static inline void fsnotify_d_move(struct dentry *dentry)
{
	/*
	 * On move we need to update dentry->d_flags to indicate if the new parent
	 * cares about events from this dentry.
	 */
	__fsnotify_update_dcache_flags(dentry);
}

/*
 * fsnotify_link_count - inode's link count changed
 */
static inline void fsnotify_link_count(struct inode *inode)
{
	fsnotify(inode, FS_ATTRIB, inode, FSNOTIFY_EVENT_INODE, NULL, 0);
}

/*
 * fsnotify_move - file old_name at old_dir was moved to new_name at new_dir
 */
#ifdef CONFIG_SYNO_NOTIFY
static inline void fsnotify_move(struct inode *old_dir, struct inode *new_dir,
				 const unsigned char *old_name,
				 int isdir, struct inode *target, struct dentry *moved, char *old_full_name, char *new_full_name)
#else
static inline void fsnotify_move(struct inode *old_dir, struct inode *new_dir,
				 const unsigned char *old_name,
				 int isdir, struct inode *target, struct dentry *moved)
#endif
{
	struct inode *source = moved->d_inode;
	u32 fs_cookie = fsnotify_get_cookie();
	__u32 old_dir_mask = (FS_EVENT_ON_CHILD | FS_MOVED_FROM);
	__u32 new_dir_mask = (FS_EVENT_ON_CHILD | FS_MOVED_TO);
	const unsigned char *new_name = moved->d_name.name;

#ifdef CONFIG_SYNO_NOTIFY
	struct path path;
	memset (&path, 0, sizeof(struct path));
#endif
	if (old_dir == new_dir)
		old_dir_mask |= FS_DN_RENAME;

	if (isdir) {
		old_dir_mask |= FS_ISDIR;
		new_dir_mask |= FS_ISDIR;
	}

#ifdef CONFIG_SYNO_NOTIFY
	/* handle syno notify:
	 * 1. we should check if file/dir moved within same mnt point. If does, we simply
	 *    notify a rename event.
	 * 2. if this rename does not occur within same mnt point, then we have to send MOVE_FROM
	 *    and MOVE_TO to mnt points respectively.
	 */

	// prepare source notify data
	path.mnt = get_vfsmount_by_sb(old_dir->i_sb);
	if(path.mnt){
		mntget(path.mnt);
		SYNOFsnotify(old_dir_mask, &path, FSNOTIFY_EVENT_SYNO, old_full_name, fs_cookie);
		SYNOFsnotify(new_dir_mask, &path, FSNOTIFY_EVENT_SYNO, new_full_name, fs_cookie);
		mntput(path.mnt);
	}
#endif

	fsnotify(old_dir, old_dir_mask, old_dir, FSNOTIFY_EVENT_INODE, old_name, fs_cookie);
	fsnotify(new_dir, new_dir_mask, new_dir, FSNOTIFY_EVENT_INODE, new_name, fs_cookie);

#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
	SYNO_ArchiveModify(old_dir);
	if (old_dir != new_dir) {
		SYNO_ArchiveModify(new_dir);
	}
#endif

	if (target) {
		fsnotify_link_count(target);
#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
		SYNO_ArchiveModify(target);
#endif
	}

	if (source) {
		fsnotify(source, FS_MOVE_SELF, moved->d_inode, FSNOTIFY_EVENT_INODE, NULL, 0);
#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
		SYNO_ArchiveModify(source);
#endif
	}
	audit_inode_child(moved, new_dir);
}

/*
 * fsnotify_inode_delete - and inode is being evicted from cache, clean up is needed
 */
static inline void fsnotify_inode_delete(struct inode *inode)
{
	__fsnotify_inode_delete(inode);
}

/*
 * fsnotify_vfsmount_delete - a vfsmount is being destroyed, clean up is needed
 */
static inline void fsnotify_vfsmount_delete(struct vfsmount *mnt)
{
	__fsnotify_vfsmount_delete(mnt);
}

/*
 * fsnotify_nameremove - a filename was removed from a directory
 */
static inline void fsnotify_nameremove(struct dentry *dentry, int isdir)
{
	__u32 mask = FS_DELETE;

	if (isdir)
		mask |= FS_ISDIR;

#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
	SYNO_ArchiveModify(dentry->d_parent->d_inode);
#endif

#ifdef CONFIG_SYNO_NOTIFY
	SYNONotify(dentry, mask);
#endif

	fsnotify_parent(NULL, dentry, mask);
}

/*
 * fsnotify_inoderemove - an inode is going away
 */
static inline void fsnotify_inoderemove(struct inode *inode)
{
	fsnotify(inode, FS_DELETE_SELF, inode, FSNOTIFY_EVENT_INODE, NULL, 0);
	__fsnotify_inode_delete(inode);
}

/*
 * fsnotify_create - 'name' was linked in
 */
static inline void fsnotify_create(struct inode *inode, struct dentry *dentry)
{
	audit_inode_child(dentry, inode);

#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
	SYNO_ArchiveModify(inode);
	SYNO_ArchiveModify(dentry->d_inode);
#endif

#ifdef CONFIG_SYNO_NOTIFY
	SYNONotify(dentry, FS_CREATE);
#endif

	fsnotify(inode, FS_CREATE, dentry->d_inode, FSNOTIFY_EVENT_INODE, dentry->d_name.name, 0);
}

/*
 * fsnotify_link - new hardlink in 'inode' directory
 * Note: We have to pass also the linked inode ptr as some filesystems leave
 *   new_dentry->d_inode NULL and instantiate inode pointer later
 */
static inline void fsnotify_link(struct inode *dir, struct inode *inode, struct dentry *new_dentry)
{
	fsnotify_link_count(inode);
	audit_inode_child(new_dentry, dir);

#ifdef CONFIG_SYNO_NOTIFY
	SYNONotify(new_dentry, FS_CREATE);
#endif
	fsnotify(dir, FS_CREATE, inode, FSNOTIFY_EVENT_INODE, new_dentry->d_name.name, 0);
}

/*
 * fsnotify_mkdir - directory 'name' was created
 */
static inline void fsnotify_mkdir(struct inode *inode, struct dentry *dentry)
{
	__u32 mask = (FS_CREATE | FS_ISDIR);
	struct inode *d_inode = dentry->d_inode;

	audit_inode_child(dentry, inode);

#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
	SYNO_ArchiveModify(inode);
	SYNO_ArchiveModify(d_inode);
#endif

#ifdef CONFIG_SYNO_NOTIFY
	SYNONotify(dentry, mask);
#endif
	fsnotify(inode, mask, d_inode, FSNOTIFY_EVENT_INODE, dentry->d_name.name, 0);
}

/*
 * fsnotify_access - file was read
 */
static inline void fsnotify_access(struct file *file)
{
	struct path *path = &file->f_path;
	struct inode *inode = path->dentry->d_inode;
	__u32 mask = FS_ACCESS;

	if (S_ISDIR(inode->i_mode))
		mask |= FS_ISDIR;

	if (!(file->f_mode & FMODE_NONOTIFY)) {
		fsnotify_parent(path, NULL, mask);
		fsnotify(inode, mask, path, FSNOTIFY_EVENT_PATH, NULL, 0);
	}
}

/*
 * fsnotify_modify - file was modified
 */
static inline void fsnotify_modify(struct file *file)
{
	struct path *path = &file->f_path;
	struct inode *inode = path->dentry->d_inode;
	__u32 mask = FS_MODIFY;

	if (S_ISDIR(inode->i_mode))
		mask |= FS_ISDIR;

	if (!(file->f_mode & FMODE_NONOTIFY)) {
#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
		SYNO_ArchiveModify(inode);
#endif
		fsnotify_parent(path, NULL, mask);
		fsnotify(inode, mask, path, FSNOTIFY_EVENT_PATH, NULL, 0);
	}
}

/*
 * fsnotify_open - file was opened
 */
static inline void fsnotify_open(struct file *file)
{
	struct path *path = &file->f_path;
	struct inode *inode = path->dentry->d_inode;
	__u32 mask = FS_OPEN;

	if (S_ISDIR(inode->i_mode))
		mask |= FS_ISDIR;

	fsnotify_parent(path, NULL, mask);
	fsnotify(inode, mask, path, FSNOTIFY_EVENT_PATH, NULL, 0);
}

/*
 * fsnotify_close - file was closed
 */
static inline void fsnotify_close(struct file *file)
{
	struct path *path = &file->f_path;
	struct inode *inode = file->f_path.dentry->d_inode;
	fmode_t mode = file->f_mode;
	__u32 mask = (mode & FMODE_WRITE) ? FS_CLOSE_WRITE : FS_CLOSE_NOWRITE;

	if (S_ISDIR(inode->i_mode))
		mask |= FS_ISDIR;

	if (!(file->f_mode & FMODE_NONOTIFY)) {
		fsnotify_parent(path, NULL, mask);
		fsnotify(inode, mask, path, FSNOTIFY_EVENT_PATH, NULL, 0);
	}
}

/*
 * fsnotify_xattr - extended attributes were changed
 */
static inline void fsnotify_xattr(struct dentry *dentry)
{
	struct inode *inode = dentry->d_inode;
	__u32 mask = FS_ATTRIB;

	if (S_ISDIR(inode->i_mode))
		mask |= FS_ISDIR;

#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
	SYNO_ArchiveModify(inode);
#endif
	fsnotify_parent(NULL, dentry, mask);

#ifdef CONFIG_SYNO_NOTIFY
	SYNONotify(dentry, mask);
#endif

	fsnotify(inode, mask, inode, FSNOTIFY_EVENT_INODE, NULL, 0);
}

/*
 * fsnotify_change - notify_change event.  file was modified and/or metadata
 * was changed.
 */
static inline void fsnotify_change(struct dentry *dentry, unsigned int ia_valid)
{
	struct inode *inode = dentry->d_inode;
	__u32 mask = 0;

	if (ia_valid & ATTR_UID)
		mask |= FS_ATTRIB;
	if (ia_valid & ATTR_GID)
		mask |= FS_ATTRIB;
	if (ia_valid & ATTR_SIZE)
#if defined(MY_ABC_HERE) || defined(MY_ABC_HERE)
	{
		mask |= FS_MODIFY;
		SYNO_ArchiveModify(inode);
	}
#else
		mask |= FS_MODIFY;
#endif

	/* both times implies a utime(s) call */
	if ((ia_valid & (ATTR_ATIME | ATTR_MTIME)) == (ATTR_ATIME | ATTR_MTIME))
		mask |= FS_ATTRIB;
	else if (ia_valid & ATTR_ATIME)
		mask |= FS_ACCESS;
	else if (ia_valid & ATTR_MTIME)
		mask |= FS_MODIFY;

	if (ia_valid & ATTR_MODE)
		mask |= FS_ATTRIB;

	if (mask) {
		if (S_ISDIR(inode->i_mode))
			mask |= FS_ISDIR;

		fsnotify_parent(NULL, dentry, mask);
#ifdef CONFIG_SYNO_NOTIFY
	SYNONotify(dentry, mask);
#endif
		fsnotify(inode, mask, inode, FSNOTIFY_EVENT_INODE, NULL, 0);
	}
}

#if defined(CONFIG_FSNOTIFY)	/* notify helpers */

/*
 * fsnotify_oldname_init - save off the old filename before we change it
 */
static inline const unsigned char *fsnotify_oldname_init(const unsigned char *name)
{
	return kstrdup(name, GFP_KERNEL);
}

/*
 * fsnotify_oldname_free - free the name we got from fsnotify_oldname_init
 */
static inline void fsnotify_oldname_free(const unsigned char *old_name)
{
	kfree(old_name);
}

#else	/* CONFIG_FSNOTIFY */

static inline const char *fsnotify_oldname_init(const unsigned char *name)
{
	return NULL;
}

static inline void fsnotify_oldname_free(const unsigned char *old_name)
{
}

#endif	/*  CONFIG_FSNOTIFY */

#endif	/* _LINUX_FS_NOTIFY_H */
