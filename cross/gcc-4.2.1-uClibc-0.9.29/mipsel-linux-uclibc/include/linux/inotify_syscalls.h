#ifndef _LINUX_INOTIFY_SYSCALLS_H
#define _LINUX_INOTIFY_SYSCALLS_H

#include <unistd.h>
#include <sys/syscall.h>
 
static inline int inotify_init (void)
{
     return syscall (__NR_inotify_init);
 }
 
 static inline int inotify_add_watch (int fd, const char *name, __u32 mask)
{
     return syscall (__NR_inotify_add_watch, fd, name, mask);
 }
 
 static inline int inotify_rm_watch (int fd, __u32 wd)
 {
     return syscall (__NR_inotify_rm_watch, fd, wd);
 }
 
 #endif /* _LINUX_INOTIFY_SYSCALLS_H */

