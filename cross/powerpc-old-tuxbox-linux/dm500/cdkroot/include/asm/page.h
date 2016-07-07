#ifndef _PPC_PAGE_H
#define _PPC_PAGE_H

#include <unistd.h>

#define PAGE_SIZE ((unsigned long)getpagesize())
#define PAGE_SHIFT ((PAGE_SIZE > 65536) ? -1 : ((unsigned long[]){12,13,14,-1,15,-1,-1,-1,16}[PAGE_SIZE>>13]))
#define PAGE_MASK    (~(PAGE_SIZE-1))

#endif /* _PPC_PAGE_H */
