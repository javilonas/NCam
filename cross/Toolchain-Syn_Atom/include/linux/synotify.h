#ifndef _LINUX_SYNOTIFY_H
#define _LINUX_SYNOTIFY_H

#include <linux/types.h>

/* the following events that user-space can register for */
// Note: The following event bit mask should match FS_XXX
#define SYNO_ACCESS			0x00000001	/* File was accessed */
#define SYNO_MODIFY			0x00000002	/* File was modified */
#define SYNO_ATTRIB			0x00000004	/* File was modified */
#define SYNO_CLOSE_WRITE		0x00000008	/* Writtable file closed */
#define SYNO_CLOSE_NOWRITE	0x00000010	/* Unwrittable file closed */
#define SYNO_OPEN			0x00000020	/* File was opened */
#define SYNO_MOVE_FROM		0x00000040	/* File was opened */
#define SYNO_MOVE_TO		0x00000080	/* File was opened */
#define SYNO_CREATE			0x00000100	/* File was opened */
#define SYNO_DELETE			0x00000200	/* File was opened */
#define SYNO_Q_OVERFLOW		0x00004000	/* Event queued overflowed */
#define SYNO_ONDIR			0x40000000	/* event occurred against dir */

/* flags used for synotify_init() */
#define SYNO_CLOEXEC		0x00000001
#define SYNO_NONBLOCK		0x00000002

/* flags used for synotify_add_watch() */
#define SYNO_DONT_FOLLOW		0x01000000	/* don't follow a sym link */

#define SYNO_ALL_EVENTS (SYNO_ACCESS | \
						 SYNO_MODIFY | \
						 SYNO_ATTRIB | \
						 SYNO_CLOSE_WRITE | \
						 SYNO_CLOSE_NOWRITE | \
						 SYNO_OPEN | \
						 SYNO_MOVE_FROM | \
						 SYNO_MOVE_TO | \
						 SYNO_CREATE | \
						 SYNO_DELETE | \
						 SYNO_Q_OVERFLOW | \
						 SYNO_ONDIR| \
						 SYNO_Q_OVERFLOW)
/*
 * struct synotify_event - structure read from the inotify device for each event
 *
 * When you are watching a directory, you will receive the filename for events
 * such as IN_CREATE, IN_DELETE, IN_OPEN, IN_CLOSE, ...
 */
struct synotify_event {
	__u32		mask;		/* watch mask */
	__u32		cookie;		/* cookie to synchronize two events */
	__u32		len;		/* length (including nulls) of name */
	char		name[0];	/* stub for possible name */
};

#endif
