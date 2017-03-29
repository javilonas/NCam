#ifndef SC_MATH_GENERIC
#define SC_MATH_GENERIC
/*
 * Copyright 2003 MontaVista Software.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */
/*
 * More information on scaled math, the why and how of it can be found
 * in .../Documentation/scaled_math.txt
 *
 * These are generic scaling functions for all machines.
 * With the exception of the u32=u64/u32, u32=u64%u32 operations
 * all of this is standard C.  Gcc produces quite reasonable code for 
 * these.
 * For the "/" and '%" operations we depend on  <asm/div64.h>  which
 * defines u32 = do_div(u64, u32) where the u64 is overwritten 
 * with the u64 result of the div.  The function return is the remainder.
 * We recommend that archs also provide a simple u64/u32 returning both the 
 * result and the remainder.  This should be defined as follows:

 *  #define div_long_long_rem(a,b,c) div_ll_X_l_rem(a,b,c)

 * extern inline long
 * div_ll_X_l_rem(long long divs, long div, long *rem)
 * {
 * 	long dum2;
 *       __asm__("divl %2":"=a"(dum2), "=d"(*rem)
 *       :	"rm"(div), "A"(divs));
 * 
 * 	return dum2;
 * }
 *
 * with, of course, changes for your asm notation.  It is important to use
 * a define for div_long_long_rem as this is used here and else where
 * to figure out if the function exists.

 */
#define SC_32(x) ((unsigned long long)(x) << 32)

#define SC_n(n,x) (((long long)(x))<<(n))

#if (BITS_PER_LONG < 64)

#define SCC_SHIFT 16
#define SCC_MASK ((1 << SCC_SHIFT) -1)
/*
 * mpy a long by a long and return a long long
 */

static inline long long mpy_l_X_l_ll(long mpy1, long mpy2)
{
	return (s64)mpy1 * mpy2;
}
/*
 * mpy a long long by a long and return a long long
 * If you try this signed, it takes an additional mpy.
 */

static inline long long mpy_ll_X_l_ll(unsigned long long mpy1,
				      unsigned long mpy2)
{
	/*
	 * Actually gcc can do this, but this seems to be a few
	 * instructions shorter.
	 */
	long long result = mpy_l_X_l_ll((unsigned long)mpy1, mpy2);
	result +=  (mpy_l_X_l_ll((long)(mpy1 >> 32), mpy2) << 32);
	return result;
}
/*
 * mpy a long by a long and return the low part and a seperate hi part
 */


static inline long  mpy_l_X_l_h(long mpy1,
				long mpy2,
				long *hi)
{
	long long it = mpy_l_X_l_ll(mpy1, mpy2);
	*hi = (unsigned long)(it >> 32);
        return (unsigned long)it;

}
/*
 * This routine preforms the following calculation:
 *
 * X = (a*b)>>32
 * we could, (but don't) also get the part shifted out.
 */
static inline long mpy_sc32(long a, long b)
{
        return (long)(mpy_l_X_l_ll(a, b) >> 32);
}
/*
 * X = (a*b)>>24
 * we could, (but don't) also get the part shifted out.
 */

#define mpy_sc24(a,b) mpy_sc_n(24,(a),(b))

/*
 * The routines allow you to do x = ((a<< N)/b) and
 * x=(a*b)>>N for values of N from 1 to 32.
 *
 * These are handy to have to do scaled math.
 * Scaled math has two nice features:
 * A.) A great deal more precision can be maintained by
 *     keeping more signifigant bits.
 * B.) Often an in line div can be replaced with a mpy
 *     which is a LOT faster.
 */

/* x = (aa * bb) >> N */
#define mpy_sc_n(N,aa,bb) ({(long)(mpy_l_X_l_ll((aa), (bb)) >> (N));})

#include <asm/div64.h>
#if 0  // maybe one day we will do signed numbers...
/*
 * do_div doesn't handle signed numbers, so:
 */
#define do_div_signed(result, div)					\
({									\
        long rem, flip = 0;						\
	if (result < 0){						\
		result = -result;					\
		flip = 2;                 /* flip rem & result sign*/	\
		if (div < 0){						\
			div = -div;					\
			flip--;          /* oops, just flip rem */	\
		}							\
	}								\
	rem = do_div(result,div);					\
	rem = flip ? -rem : rem;					\
	if ( flip == 2)							\
		result = -result;					\
	rem;								\
})
#endif




#ifndef div_long_long_rem
  
/*
 * (long)X = ((long long)divs) / (long)div
 * (long)rem = ((long long)divs) % (long)div
 *
 * Warning, this will do an exception if X overflows.
 * Well, it would if done in asm, this code just truncates..
 */

#define div_long_long_rem(a,b,c) div_ll_X_l_rem((a),(b),(c))
/* x = divs / div; *rem = divs % div; */
static inline unsigned long div_ll_X_l_rem(unsigned long long divs, 
					   unsigned long div, 
					   unsigned long * rem)
{
	unsigned long long it = divs;
	*rem = do_div(it, div);
	return (unsigned long)it;
}
/*
 * same as above, but no remainder
 */
static inline unsigned long div_ll_X_l(unsigned long long divs, 
				       unsigned long div)
{
	unsigned long long it = divs;
        do_div(it, div);
        return (unsigned long)it;
}
#else
#define  div_ll_X_l(divs, div) ({unsigned long d; div_ll_X_l_rem(divs, div, &d);})
#endif
/*
 * X = (a/b)<<32 or more precisely x = (a<<32)/b
 */
static inline unsigned long div_sc32(unsigned long a, unsigned long b)
{
	return div_ll_X_l(SC_32(a), b);
}
/*
 * X = (a/b)<<24 or more precisely x = (a<<24)/b
 */
#define div_sc24(a,b) div_sc_n(24,(a),(b))
/* x = (aa << N / bb)  */
#define div_sc_n(N,aa,bb) ({unsigned long long result = SC_n((N), (aa)); \
                             div_ll_X_l(result, (bb));})  
/*
 * (long)X = (((long)divh<<32) | (long)divl) / (long)div
 * (long)rem = (((long)divh<<32) % (long)divl) / (long)div
 *
 * Warning, this will do an exception if X overflows.
 * Well, it would if done in asm, this code just truncates..
 */
static inline unsigned long div_h_or_l_X_l_rem(unsigned long divh,
					       unsigned long divl, 
					       unsigned long div,
					       unsigned long* rem)
{
	unsigned long long result = SC_32(divh) + (divl);

        return div_ll_X_l_rem(result, (div), (rem));

}
#else
/* The 64-bit long version */

/* 
 * The 64-bit long machine can do most of these in native C.  We assume that 
 * the "long long" of 32-bit machines is typedefed away so the we need only
 * deal with longs.  This code should be tight enought that asm code is not
 * needed.
 */

/*
 * mpy a long by a long and return a long
 */

static inline long mpy_l_X_l_ll(long mpy1, long mpy2)
{

        return (mpy1) * (mpy2);

}
/*
 * mpy a long by a long and return the low part and a separate hi part
 * This code always returns 32 values... may not be what you want...
 */


static inline long  mpy_l_X_l_h(long mpy1,
					 long mpy2,
					 long *hi)
{
	long it = mpy1 * mpy2;
	*hi = (it >> 32);
        return it & 0xffffffff;

}
/*
 * This routine preforms the following calculation:
 *
 * X = (a*b)>>32
 * we could, (but don't) also get the part shifted out.
 */
static inline long mpy_sc32(long a, long b)
{
        return ((a * b) >> 32);
}
/*
 * X = (a/b)<<32 or more precisely x = (a<<32)/b
 */

static inline long div_sc32(long a, long b)
{
	return  SC_32(a) / (b);
}
/*
 * X = (a*b)>>24
 * we could, (but don't) also get the part shifted out.
 */

#define mpy_sc24(a,b) mpy_sc_n(24,a,b)
/*
 * X = (a/b)<<24 or more precisely x = (a<<24)/b
 */
#define div_sc24(a,b) div_sc_n(24,a,b)

/*
 * The routines allow you to do x = ((a<< N)/b) and
 * x=(a*b)>>N for values of N from 1 to 32.
 *
 * These are handy to have to do scaled math.
 * Scaled math has two nice features:
 * A.) A great deal more precision can be maintained by
 *     keeping more signifigant bits.
 * B.) Often an in line div can be replaced with a mpy
 *     which is a LOT faster.
 */

/* x = (aa * bb) >> N */


#define mpy_sc_n(N,aa,bb) (((aa) * (bb)) >> N)

/* x = (aa << N / bb)  */
#define div_sc_n(N,aa,bb) (SC_n((N), (aa)) / (bb))

  
/*
 * (long)X = ((long long)divs) / (long)div
 * (long)rem = ((long long)divs) % (long)div
 *
 * Warning, this will do an exception if X overflows.
 * Well, it would if done in asm, this code just truncates..
 */
#define div_long_long_rem(a,b,c) div_ll_X_l_rem(a, b, c)

/* x = divs / div; *rem = divs % div; */
static inline unsigned long div_ll_X_l_rem(unsigned long divs, 
					   unsigned long div, 
					   unsigned long * rem)
{
	*rem = divs % div;
	return divs / div;
}
/*
 * same as above, but no remainder
 */
static inline unsigned long div_ll_X_l(unsigned long divs, 
				       unsigned long div)
{
        return divs / div;
}
/*
 * (long)X = (((long)divh<<32) | (long)divl) / (long)div
 * (long)rem = (((long)divh<<32) % (long)divl) / (long)div
 *
 * Warning, this will do an exception if X overflows.
 * Well, it would if done in asm, this code just truncates..
 */
static inline unsigned long div_h_or_l_X_l_rem(unsigned long divh,
					       unsigned long divl, 
					       unsigned long div,
					       unsigned long* rem)
{
	long result = SC_32(divh) + divl;

        return div_ll_X_l_rem(result, div, rem);

}
#endif  /* else(BITS_PER_LONG < 64) */
#endif
