#ifndef _IP_NAT_H
#define _IP_NAT_H
#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv4/ip_conntrack_tuple.h>

#define IP_NAT_MAPPING_TYPE_MAX_NAMELEN 16

enum ip_nat_manip_type
{
	IP_NAT_MANIP_SRC,
	IP_NAT_MANIP_DST
};

/* SRC manip occurs POST_ROUTING or LOCAL_IN */
#define HOOK2MANIP(hooknum) ((hooknum) != NF_IP_POST_ROUTING && (hooknum) != NF_IP_LOCAL_IN)

#define IP_NAT_RANGE_MAP_IPS 1
#define IP_NAT_RANGE_PROTO_SPECIFIED 2

/* NAT sequence number modifications */
struct ip_nat_seq {
	/* position of the last TCP sequence number 
	 * modification (if any) */
	u_int32_t correction_pos;
	/* sequence number offset before and after last modification */
	int32_t offset_before, offset_after;
};

/* Single range specification. */
struct ip_nat_range
{
	/* Set to OR of flags above. */
	unsigned int flags;

	/* Inclusive: network order. */
	u_int32_t min_ip, max_ip;

	/* Inclusive: network order */
	union ip_conntrack_manip_proto min, max;
};

/* A range consists of an array of 1 or more ip_nat_range */
struct ip_nat_multi_range_compat
{
	unsigned int rangesize;

	/* hangs off end. */
	struct ip_nat_range range[1];
};

/* Worst case: local-out manip + 1 post-routing, and reverse dirn. */
#define IP_NAT_MAX_MANIPS (2*3)

struct ip_nat_info_manip
{
	/* The direction. */
	u_int8_t direction;

	/* Which hook the manipulation happens on. */
	u_int8_t hooknum;

	/* The manipulation type. */
	u_int8_t maniptype;

	/* Manipulations to occur at each conntrack in this dirn. */
	struct ip_conntrack_manip manip;
};

#define ip_nat_multi_range ip_nat_multi_range_compat

#endif
