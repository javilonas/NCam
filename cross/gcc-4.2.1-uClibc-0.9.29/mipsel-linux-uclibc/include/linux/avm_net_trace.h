#ifndef _AVM_NET_TRACE_H
#define _AVM_NET_TRACE_H

#include <linux/if.h>
#include <linux/skbuff.h>

#define AVM_NET_TRACE_VERSION		1

#define AVM_NET_TRACE_USE_SKB		0
#define AVM_NET_TRACE_CLONE_SKB		1
#define AVM_NET_TRACE_COPY_SKB		2

#define AVM_NET_TRACE_DIRECTION_HOST		0
#define AVM_NET_TRACE_DIRECTION_OUTGOING 	1

#define PCAP_ENCAP_RFC1483	11
#define PCAP_ENCAP_ETHER	1
#define PCAP_ENCAP_PPP		9
#define PCAP_ENCAP_IP		14
#define PCAP_ENCAP_IEEE802_11	105
#define PCAP_ENCAP_PRISM_HEADER	119

struct avm_net_trace {
	struct avm_net_trace_device 	*ntd;
	unsigned int			minor;
	volatile int			is_open;
	int				got_header;
	unsigned long			dropped;
	wait_queue_head_t		recvwait;
	struct sk_buff_head		recvqueue;
};

struct avm_net_trace_device {
	/* global */
	char	name[IFNAMSIZ];
	int	pcap_encap;
	int	pcap_protocol;

	/* private */
	struct avm_net_trace *ant;
};

#ifdef CONFIG_AVM_NET_TRACE

extern int __avm_net_trace_func (
		struct avm_net_trace *ant, struct sk_buff *skb, 
		int skb_property, int direction);

static inline int __avm_net_trace_in_progress (struct avm_net_trace_device *ntd) {

	struct avm_net_trace *ant;

	ant = ntd->ant;

	if (ant == NULL)
		return 0;

	if (!ant->is_open)
		return 0;

	if (skb_queue_len (&ant->recvqueue) > 20) {
		ant->dropped++;
		return 0;
	}

	return 1;
}

static inline int avm_net_trace_func (
		struct avm_net_trace_device *ntd, struct sk_buff *skb, 
		int skb_property, int direction) {

	struct avm_net_trace *ant = ntd->ant;

	if (__avm_net_trace_in_progress (ntd))
		return __avm_net_trace_func (ant, skb, skb_property, direction);

	return -1;
}

extern int register_avm_net_trace_device (struct avm_net_trace_device *ntd);
extern void deregister_avm_net_trace_device (struct avm_net_trace_device *ntd);

#else /* CONFIG_AVM_NET_TRACE  */

static inline int __avm_net_trace_in_progress (struct avm_net_trace_device *ntd) { return 0; }

static inline int avm_net_trace_func (
		struct avm_net_trace_device *ntd, struct sk_buff *skb, 
		int skb_property, int direction) { return 0; }

static inline int register_avm_net_trace_device (struct avm_net_trace_device *ntd) { return 0; }
static inline void deregister_avm_net_trace_device (struct avm_net_trace_device *ntd) { return 0; }

#endif /* CONFIG_AVM_NET_TRACE  */

#endif /* _AVM_NET_TRACE_H */

