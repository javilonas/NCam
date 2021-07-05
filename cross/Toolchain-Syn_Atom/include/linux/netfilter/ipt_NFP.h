/*
 * Copyright (C) 2010 Semihalf.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _IPT_NFP_H
#define _IPT_NFP_H

#define IPT_NFP_F_SET_DSCP           0x1
#define IPT_NFP_F_SET_DSCP_DEF       0x2
#define IPT_NFP_F_SET_VLAN_PRIO      0x4
#define IPT_NFP_F_SET_VLAN_PRIO_DEF  0x8
#define IPT_NFP_F_SET_TXQ            0x10
#define IPT_NFP_F_SET_TXP            0x20
#define IPT_NFP_F_SET_MH             0x40
#define IPT_NFP_F_SET_LIMIT          0x80
#define IPT_NFP_F_SET_BURST          0x100
#define IPT_NFP_F_SET_TXQ_DEF        0x200

enum ipt_nfp_mode {
	IPT_NFP_INIT   = -1,
	IPT_NFP_FWD    = 0,
	IPT_NFP_DROP   = 1,
	IPT_NFP_MANGLE = 2,
};

/* 0..7 + one cell for global mapping regardless of the old VLAN Prio value (the '-1' option) */
#define IPT_NFP_VPRI_MAP_SIZE	9
#define IPT_NFP_VPRI_MAP_GLOBAL	8 /* index in the array for the global mapping */

typedef struct {
	unsigned char new_prio;
	unsigned char valid;
} IPT_NFP_VPRI_MAP_INFO;

/* 0..63 + one cell for global mapping regardless of the old DSCP value (the '-1' option) */
#define IPT_NFP_DSCP_MAP_SIZE	65
#define IPT_NFP_DSCP_MAP_GLOBAL	64 /* index in the array for the global mapping */

typedef struct {
	unsigned char new_dscp;
	unsigned char valid;
} IPT_NFP_DSCP_MAP_INFO;

typedef struct {
	unsigned char txq;
	unsigned char valid;
} IPT_NFP_TXQ_MAP_INFO;

struct ipt_nfp_info {
	unsigned int		mode;
	unsigned int		flags;

	int			burst;
	int			limit;

	int			dscp;
	int			new_dscp;
	IPT_NFP_DSCP_MAP_INFO	dscp_map[IPT_NFP_DSCP_MAP_SIZE];

	int			vlanprio;
	int			new_vlanprio;
	IPT_NFP_VPRI_MAP_INFO	vpri_map[IPT_NFP_VPRI_MAP_SIZE];

	int			dscp_txq; /* map DSCP to TXQ */
	int			txq;
	IPT_NFP_TXQ_MAP_INFO	txq_map[IPT_NFP_DSCP_MAP_SIZE];

	int			txp;
	int			mh;

	/* private */
	struct ipt_entry	*entry;
};


static inline void nfp_update_tuple_info(struct ipt_nfp_info *dst, struct ipt_nfp_info *src)
{
	/* we copy (override) some of the parameters, but update (accumulate) others */

	dst->mode = src->mode;
	dst->flags |= src->flags;

	if (src->flags & IPT_NFP_F_SET_BURST)
		dst->burst = src->burst;

	if (src->flags & IPT_NFP_F_SET_LIMIT)
		dst->limit = src->limit;

	if (src->flags & IPT_NFP_F_SET_DSCP) {
		dst->dscp_map[src->dscp].new_dscp = src->new_dscp;
		dst->dscp_map[src->dscp].valid = 1;
	}

	if (src->flags & IPT_NFP_F_SET_DSCP_DEF) {
		dst->dscp_map[IPT_NFP_DSCP_MAP_GLOBAL].new_dscp = src->new_dscp;
		dst->dscp_map[IPT_NFP_DSCP_MAP_GLOBAL].valid = 1;
	}

	if (src->flags & IPT_NFP_F_SET_VLAN_PRIO) {
		dst->vpri_map[src->vlanprio].new_prio = src->new_vlanprio;
		dst->vpri_map[src->vlanprio].valid = 1;
	}

	if (src->flags & IPT_NFP_F_SET_VLAN_PRIO_DEF) {
		dst->vpri_map[IPT_NFP_VPRI_MAP_GLOBAL].new_prio = src->new_vlanprio;
		dst->vpri_map[IPT_NFP_VPRI_MAP_GLOBAL].valid = 1;
	}

	if (src->flags & IPT_NFP_F_SET_TXQ) {
		dst->txq_map[src->dscp].txq = src->txq;
		dst->txq_map[src->dscp].valid = 1;
	}

	if (src->flags & IPT_NFP_F_SET_TXQ_DEF) {
		dst->txq_map[IPT_NFP_DSCP_MAP_GLOBAL].txq = src->txq;
		dst->txq_map[IPT_NFP_DSCP_MAP_GLOBAL].valid = 1;
	}

	if (src->flags & IPT_NFP_F_SET_TXP)
		dst->txp = src->txp;

	if (src->flags & IPT_NFP_F_SET_MH)
		dst->mh = src->mh;

	dst->entry = src->entry;
}


#endif
