#ifndef _ASM_X8664_NUMNODES_H
#define _ASM_X8664_NUMNODES_H 1


#ifdef CONFIG_NUMA
#define NODES_SHIFT	6
#else
#define NODES_SHIFT	0
#endif

#endif
