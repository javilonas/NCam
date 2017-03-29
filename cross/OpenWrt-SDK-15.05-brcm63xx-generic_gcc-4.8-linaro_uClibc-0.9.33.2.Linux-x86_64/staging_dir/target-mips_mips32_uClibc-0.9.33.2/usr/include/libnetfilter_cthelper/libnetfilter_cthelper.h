#ifndef _LIBNETFILTER_ACCT_H_
#define _LIBNETFILTER_ACCT_H_

#include <sys/types.h>
#include <linux/netfilter/nfnetlink_cthelper.h>

struct nfct_helper_policy;

enum nfct_helper_policy_attr_type {
	NFCTH_ATTR_POLICY_NAME = 0,
	NFCTH_ATTR_POLICY_TIMEOUT,
	NFCTH_ATTR_POLICY_MAX,
};

struct nfct_helper_policy *nfct_helper_policy_alloc(void);
void nfct_helper_policy_free(struct nfct_helper_policy *p);

void nfct_helper_policy_attr_set(struct nfct_helper_policy *p, enum nfct_helper_policy_attr_type type, const void *data);
void nfct_helper_policy_attr_set_str(struct nfct_helper_policy *p, enum nfct_helper_policy_attr_type type, const char *name);
void nfct_helper_policy_attr_set_u32(struct nfct_helper_policy *p, enum nfct_helper_policy_attr_type type, uint32_t value);
void nfct_helper_policy_attr_unset(struct nfct_helper_policy *p, enum nfct_helper_policy_attr_type type);

enum nfct_helper_attr_type {
	NFCTH_ATTR_NAME = 0,
	NFCTH_ATTR_QUEUE_NUM,
	NFCTH_ATTR_PROTO_L3NUM,
	NFCTH_ATTR_PROTO_L4NUM,
	NFCTH_ATTR_PRIV_DATA_LEN,
	NFCTH_ATTR_POLICY,
	NFCTH_ATTR_POLICY1 = NFCTH_ATTR_POLICY,
	NFCTH_ATTR_POLICY2,
	NFCTH_ATTR_POLICY3,
	NFCTH_ATTR_POLICY4,
	NFCTH_ATTR_STATUS,
};

struct nfct_helper;

struct nfct_helper *nfct_helper_alloc(void);
void nfct_helper_free(struct nfct_helper *h);

void nfct_helper_attr_set(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type, const void *data);
void nfct_helper_attr_set_str(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type, const char *name);
void nfct_helper_attr_set_u8(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type, uint8_t value);
void nfct_helper_attr_set_u16(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type, uint16_t value);
void nfct_helper_attr_set_u32(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type, uint32_t value);
void nfct_helper_attr_unset(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type);

const void *nfct_helper_attr_get(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type);
const char *nfct_helper_attr_get_str(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type);
uint8_t nfct_helper_attr_get_u8(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type);
uint16_t nfct_helper_attr_get_u16(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type);
uint32_t nfct_helper_attr_get_u32(struct nfct_helper *nfct_helper, enum nfct_helper_attr_type type);

struct nlmsghdr;

struct nlmsghdr *nfct_helper_nlmsg_build_hdr(char *buf, uint8_t cmd, uint16_t flags, uint32_t seq);
void nfct_helper_nlmsg_build_payload(struct nlmsghdr *nlh, struct nfct_helper *nfct_helper);
int nfct_helper_nlmsg_parse_payload(const struct nlmsghdr *nlh, struct nfct_helper *nfct_helper);

int nfct_helper_snprintf(char *buf, size_t size, struct nfct_helper *nfct_helper, unsigned int type, unsigned int flags);

#endif
