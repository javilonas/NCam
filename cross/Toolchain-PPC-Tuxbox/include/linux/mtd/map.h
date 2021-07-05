
/* Overhauled routines for dealing with different mmap regions of flash */

#ifndef __LINUX_MTD_MAP_H__
#define __LINUX_MTD_MAP_H__

#include <linux/types.h>
#include <asm/system.h>
#include <asm/io.h>

/* The map stuff is very simple. You fill in your struct map_info with
   a handful of routines for accessing the device, making sure they handle
   paging etc. correctly if your device needs it. Then you pass it off
   to a chip driver which deals with a mapped device - generally either
   do_cfi_probe() or do_ram_probe(), either of which will return a 
   struct mtd_info if they liked what they saw. At which point, you
   fill in the mtd->module with your own module address, and register 
   it.
   
   The mtd->priv field will point to the struct map_info, and any further
   private data required by the chip driver is linked from the 
   mtd->priv->fldrv_priv field. This allows the map driver to get at 
   the destructor function map->fldrv_destroy() when it's tired
   of living.
*/

struct map_info {
	char *name;
	unsigned long size;
	unsigned long phys;
#define NO_XIP (-1UL)

	void *virt;
	void *cached;

	int buswidth; /* in octets */

#ifdef CONFIG_MTD_COMPLEX_MAPPINGS
	__u8 (*read8)(struct map_info *, unsigned long);
	__u16 (*read16)(struct map_info *, unsigned long);
	__u32 (*read32)(struct map_info *, unsigned long);  
	__u64 (*read64)(struct map_info *, unsigned long);  
	/* If it returned a 'long' I'd call it readl.
	 * It doesn't.
	 * I won't.
	 * dwmw2 */
	
	void (*copy_from)(struct map_info *, void *, unsigned long, ssize_t);
	void (*write8)(struct map_info *, __u8, unsigned long);
	void (*write16)(struct map_info *, __u16, unsigned long);
	void (*write32)(struct map_info *, __u32, unsigned long);
	void (*write64)(struct map_info *, __u64, unsigned long);
	void (*copy_to)(struct map_info *, unsigned long, const void *, ssize_t);

	/* We can perhaps put in 'point' and 'unpoint' methods, if we really
	   want to enable XIP for non-linear mappings. Not yet though. */
#endif
	/* set_vpp() must handle being reentered -- enable, enable, disable 
	   must leave it enabled. */
	void (*set_vpp)(struct map_info *, int);

	unsigned long map_priv_1;
	unsigned long map_priv_2;
	void *fldrv_priv;
	struct mtd_chip_driver *fldrv;
};

struct mtd_chip_driver {
	struct mtd_info *(*probe)(struct map_info *map);
	void (*destroy)(struct mtd_info *);
	struct module *module;
	char *name;
	struct list_head list;
};

void register_mtd_chip_driver(struct mtd_chip_driver *);
void unregister_mtd_chip_driver(struct mtd_chip_driver *);

struct mtd_info *do_map_probe(const char *name, struct map_info *map);
void map_destroy(struct mtd_info *mtd);

#define ENABLE_VPP(map) do { if(map->set_vpp) map->set_vpp(map, 1); } while(0)
#define DISABLE_VPP(map) do { if(map->set_vpp) map->set_vpp(map, 0); } while(0)

#define INVALIDATE_CACHED_RANGE(map, from, size) \
	do { if(map->inval_cache) map->inval_cache(map, from, size); } while(0)


static inline int map_word_equal(struct map_info *map, map_word val1, map_word val2)
{
	int i;
	for (i=0; i<map_words(map); i++) {
		if (val1.x[i] != val2.x[i])
			return 0;
	}
	return 1;
}

static inline map_word map_word_and(struct map_info *map, map_word val1, map_word val2)
{
	map_word r;
	int i;

	for (i=0; i<map_words(map); i++) {
		r.x[i] = val1.x[i] & val2.x[i];
	}
	return r;
}

static inline map_word map_word_or(struct map_info *map, map_word val1, map_word val2)
{
	map_word r;
	int i;

	for (i=0; i<map_words(map); i++) {
		r.x[i] = val1.x[i] | val2.x[i];
	}
	return r;
}
#define map_word_andequal(m, a, b, z) map_word_equal(m, z, map_word_and(m, a, b))

static inline int map_word_bitsset(struct map_info *map, map_word val1, map_word val2)
{
	int i;

	for (i=0; i<map_words(map); i++) {
		if (val1.x[i] & val2.x[i])
			return 1;
	}
	return 0;
}

static inline map_word map_word_load(struct map_info *map, const void *ptr)
{
	map_word r;

	if (map_bankwidth_is_1(map))
		r.x[0] = *(unsigned char *)ptr;
	else if (map_bankwidth_is_2(map))
		r.x[0] = get_unaligned((uint16_t *)ptr);
	else if (map_bankwidth_is_4(map))
		r.x[0] = get_unaligned((uint32_t *)ptr);
#if BITS_PER_LONG >= 64
	else if (map_bankwidth_is_8(map))
		r.x[0] = get_unaligned((uint64_t *)ptr);
#endif
	else if (map_bankwidth_is_large(map))
		memcpy(r.x, ptr, map->bankwidth);

	return r;
}

static inline map_word map_word_load_partial(struct map_info *map, map_word orig, const unsigned char *buf, int start, int len)
{
	int i;

	if (map_bankwidth_is_large(map)) {
		char *dest = (char *)&orig;
		memcpy(dest+start, buf, len);
	} else {
		for (i=start; i < start+len; i++) {
			int bitpos;
#ifdef __LITTLE_ENDIAN
			bitpos = i*8;
#else /* __BIG_ENDIAN */
			bitpos = (map_bankwidth(map)-1-i)*8;
#endif
			orig.x[0] &= ~(0xff << bitpos);
			orig.x[0] |= buf[i-start] << bitpos;
		}
	}
	return orig;
}

static inline map_word map_word_ff(struct map_info *map)
{
	map_word r;
	int i;

	for (i=0; i<map_words(map); i++) {
		r.x[i] = ~0UL;
	}
	return r;
}
static inline map_word inline_map_read(struct map_info *map, unsigned long ofs)
{
	map_word r;

	if (map_bankwidth_is_1(map))
		r.x[0] = __raw_readb(map->virt + ofs);
	else if (map_bankwidth_is_2(map))
		r.x[0] = __raw_readw(map->virt + ofs);
	else if (map_bankwidth_is_4(map))
		r.x[0] = __raw_readl(map->virt + ofs);
#if BITS_PER_LONG >= 64
	else if (map_bankwidth_is_8(map))
		r.x[0] = __raw_readq(map->virt + ofs);
#endif
	else if (map_bankwidth_is_large(map))
		memcpy_fromio(r.x, map->virt+ofs, map->bankwidth);

	return r;
}

static inline void inline_map_write(struct map_info *map, const map_word datum, unsigned long ofs)
{
	if (map_bankwidth_is_1(map))
		__raw_writeb(datum.x[0], map->virt + ofs);
	else if (map_bankwidth_is_2(map))
		__raw_writew(datum.x[0], map->virt + ofs);
	else if (map_bankwidth_is_4(map))
		__raw_writel(datum.x[0], map->virt + ofs);
#if BITS_PER_LONG >= 64
	else if (map_bankwidth_is_8(map))
		__raw_writeq(datum.x[0], map->virt + ofs);
#endif
	else if (map_bankwidth_is_large(map))
		memcpy_toio(map->virt+ofs, datum.x, map->bankwidth);
	mb();
}

static inline void inline_map_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
	if (map->cached)
		memcpy(to, (char *)map->cached + from, len);
	else
		memcpy_fromio(to, map->virt + from, len);
}

static inline void inline_map_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
	memcpy_toio(map->virt + to, from, len);
}

#ifdef CONFIG_MTD_COMPLEX_MAPPINGS
#define map_read(map, ofs) (map)->read(map, ofs)
#define map_copy_from(map, to, from, len) (map)->copy_from(map, to, from, len)
#define map_write(map, datum, ofs) (map)->write(map, datum, ofs)
#define map_copy_to(map, to, from, len) (map)->copy_to(map, to, from, len)

extern void simple_map_init(struct map_info *);
#define map_is_linear(map) (map->phys != NO_XIP)

#else
#define map_read(map, ofs) inline_map_read(map, ofs)
#define map_copy_from(map, to, from, len) inline_map_copy_from(map, to, from, len)
#define map_write(map, datum, ofs) inline_map_write(map, datum, ofs)
#define map_copy_to(map, to, from, len) inline_map_copy_to(map, to, from, len)


#define simple_map_init(map) BUG_ON(!map_bankwidth_supported((map)->bankwidth))
#define map_is_linear(map) (1)

#endif /* !CONFIG_MTD_COMPLEX_MAPPINGS */

#endif /* __LINUX_MTD_MAP_H__ */
