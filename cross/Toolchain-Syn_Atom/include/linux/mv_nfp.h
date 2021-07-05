/*******************************************************************************
Copyright (C) Marvell International Ltd. and its affiliates

This software file (the "File") is owned and distributed by Marvell
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the two
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.

********************************************************************************
Marvell Commercial License Option

If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.

********************************************************************************
Marvell GPL License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File in accordance with the terms and conditions of the General
Public License Version 2, June 1991 (the "GPL License"), a copy of which is
available along with the File in the license.txt file or by writing to the Free
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or
on the worldwide web at http://www.gnu.org/licenses/gpl.txt.

THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED
WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY
DISCLAIMED.  The GPL License provides additional details about this warranty
disclaimer.
********************************************************************************
Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    *   Redistributions of source code must retain the above copyright notice,
	this list of conditions and the following disclaimer.

    *   Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in the
	documentation and/or other materials provided with the distribution.

    *   Neither the name of Marvell nor the names of its contributors may be
	used to endorse or promote products derived from this software without
	specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/
/*  mv_nfp.h */

#ifndef LINUX_MV_NFP_H
#define LINUX_MV_NFP_H

#ifdef CONFIG_NETFILTER
#include <net/netfilter/nf_conntrack.h>
#include <net/netfilter/nf_nat.h>
#endif
#include <linux/types.h>
#include <linux/netdevice.h>


#if defined(CONFIG_MV_ETH_NFP) || defined(CONFIG_MV_ETH_NFP_MODULE)

/* Supported flags */
#define MV_EXT_L3_VALID_MASK	0x0001
#define MV_EXT_L4_VALID_MASK	0x0002
#define MV_EXT_VLAN_EXIST_MASK  0x0004
#define MV_EXT_PPP_EXIST_MASK	0x0008
#define MV_EXT_IP_FRAG_MASK	0x0010

typedef struct {
	u16 flags;
	u16 l3_type;
	u16 l3_offset;
	u8  l3_hdrlen;
	u8  l4_proto;
} MV_EXT_PKT_INFO;

struct nfp_core_ops {
	int (*nfp_rx_ext)(struct net_device *dev, struct sk_buff *skb, MV_EXT_PKT_INFO *pktInfo);
};

extern struct nfp_core_ops *nfp_core_p;
int nfp_core_ops_init(void);

struct nfp_hook_ops {
	int (*nfp_is_learning_enabled)(void);

	int (*nfp_hook_fib_rule_add)(int family, u8 *src_l3, u8 *dst_l3, u8 *gw, int iif, int oif);
	int (*nfp_hook_fib_rule_del)(int family, u8 *src_l3, u8 *dst_l3, int iif, int oif);
	int (*nfp_hook_fib_rule_age)(int family, u8 *src_l3, u8 *dst_l3, int iif, int oif);
	int (*nfp_hook_arp_add)(int family, u8 *ip, u8 *mac, int if_index);
	int (*nfp_hook_arp_delete)(int family, u8 *ip);
	int (*nfp_hook_arp_is_confirmed)(int family, u8 *ip);

	int (*nfp_hook_fdb_rule_add)(int br_index, int if_index, u8 *mac, int is_local);
	int (*nfp_hook_fdb_rule_age)(int br_index, int if_index, u8 *mac);
	int (*nfp_hook_fdb_rule_del)(int br_index, int if_index, u8 *mac);

	int (*nfp_hook_br_del)(int ifindex);
	int (*nfp_hook_br_port_del)(int bridge_if, int port_if);

	int (*nfp_hook_vlan_add)(int if_index, struct net_device *dev, int real_if_index, int vlan_id);
	int (*nfp_hook_vlan_del)(int if_index);

	int (*nfp_hook_ppp_add)(int ppp_if, int eth_iif, u16 sid, u8 *remote_mac);
	int (*nfp_hook_ppp_del)(int ppp_iif);

	int (*nfp_hook_ct_del)(int family, u8 *src_l3, u8 *dst_l3, u16 sport, u16 dport, u8 proto);
	int (*nfp_hook_ct_age)(int family, u8 *src_l3, u8 *dst_l3, u16 sport, u16 dport, u8 proto);
#ifdef CONFIG_NETFILTER
	int (*nfp_hook_ct_nat_add)(const struct nf_conntrack_tuple *tuple,
				const struct nf_conntrack_tuple *target, enum nf_nat_manip_type maniptype);
	int  (*nfp_hook_ct_fwd_add)(const struct nf_conntrack_tuple *tuple, int mode);
#else
	int (*nfp_hook_ct_nat_add)(void);
	int (*nfp_hook_ct_fwd_add)(void);
#endif
	int  (*nfp_ct_is_learning_enabled)(void);
};

extern struct nfp_hook_ops *nfp_mgr_p;
int nfp_hook_ops_init(void);

#endif /* CONFIG_MV_ETH_NFP || CONFIG_MV_ETH_NFP_MODULE */

#endif /* LINUX_MV_NFP_H */
