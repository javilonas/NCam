/*
 *  linux/include/linux/sunrpc/clnt.h
 *
 *  Declarations for the high-level RPC client interface
 *
 *  Copyright (C) 1995, 1996, Olaf Kirch <okir@monad.swb.de>
 */

#ifndef _LINUX_SUNRPC_CLNT_H
#define _LINUX_SUNRPC_CLNT_H

#include <asm/types.h>

#include <linux/sunrpc/sched.h>
#include <linux/sunrpc/xprt.h>
#include <linux/sunrpc/stats.h>
#include <linux/sunrpc/timer.h>

/*
 * This defines an RPC port mapping
 */
struct rpc_portmap {
	__u32			pm_prog;
	__u32			pm_vers;
	__u32			pm_prot;
	__u16			pm_port;
	unsigned char		pm_binding : 1;	/* doing a getport() */
	struct rpc_wait_queue	pm_bindwait;	/* waiting on getport() */
};

struct rpc_inode;

/*
 * The high-level client handle
 */
struct rpc_clnt {
	atomic_t		cl_count;	/* Number of clones */
	atomic_t		cl_users;	/* number of references */
	struct rpc_xprt *	cl_xprt;	/* transport */
	struct rpc_procinfo *	cl_procinfo;	/* procedure info */
	__u32			cl_maxproc;	/* max procedure number */

	char *			cl_server;	/* server machine name */
	char *			cl_protname;	/* protocol name */
	struct rpc_auth *	cl_auth;	/* authenticator */
	struct rpc_stat *	cl_stats;	/* statistics */

	unsigned int		cl_softrtry : 1,/* soft timeouts */
				cl_intr     : 1,/* interruptible */
				cl_chatty   : 1,/* be verbose */
				cl_autobind : 1,/* use getport() */
				cl_oneshot  : 1,/* dispose after use */
				cl_dead     : 1;/* abandoned */

	struct rpc_rtt *	cl_rtt;		/* RTO estimator data */
	struct rpc_portmap *	cl_pmap;	/* port mapping */

	int			cl_nodelen;	/* nodename length */
	char 			cl_nodename[UNX_MAXNODENAME];
	char			cl_pathname[30];/* Path in rpc_pipe_fs */
	struct dentry *		cl_dentry;	/* inode */
	struct rpc_clnt *	cl_parent;	/* Points to parent of clones */
	struct rpc_rtt		cl_rtt_default;
	struct rpc_portmap	cl_pmap_default;
	char			cl_inline_name[32];
};
#define cl_timeout		cl_xprt->timeout
#define cl_prog			cl_pmap->pm_prog
#define cl_vers			cl_pmap->pm_vers
#define cl_port			cl_pmap->pm_port
#define cl_prot			cl_pmap->pm_prot

/*
 * General RPC program info
 */
#define RPC_MAXVERSION		4
struct rpc_program {
	char *			name;		/* protocol name */
	__u32			number;		/* program number */
	unsigned int		nrvers;		/* number of versions */
	struct rpc_version **	version;	/* version array */
	struct rpc_stat *	stats;		/* statistics */
	char *			pipe_dir_name;	/* path to rpc_pipefs dir */
};

struct rpc_version {
	__u32			number;		/* version number */
	unsigned int		nrprocs;	/* number of procs */
	struct rpc_procinfo *	procs;		/* procedure array */
};

/*
 * Procedure information
 */
struct rpc_procinfo {
	__u32			p_proc;		/* RPC procedure number */
	kxdrproc_t		p_encode;	/* XDR encode function */
	kxdrproc_t		p_decode;	/* XDR decode function */
	unsigned int		p_bufsiz;	/* req. buffer size */
	unsigned int		p_count;	/* call count */
	unsigned int		p_timer;	/* Which RTT timer to use */
};

#define RPC_CONGESTED(clnt)	(RPCXPRT_CONGESTED((clnt)->cl_xprt))
#define RPC_PEERADDR(clnt)	(&(clnt)->cl_xprt->addr)

#endif /* _LINUX_SUNRPC_CLNT_H */
