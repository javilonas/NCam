/**
***    (C) Copyright 2008-2010 Marvell International Ltd.
***    All Rights Reserved
**/
/**
*** MARVELL INTERNATIONAL LTD., ON BEHALF OF ITSELF AND ITS AFFILIATES
*** (COLLECTIVELY, "MARVELL") AND ITS SUPPLIERS MAKE NO WARRANTY OF
*** ANY KIND WITH REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO,
*** THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
*** PARTICULAR PURPOSE.  MARVELL AND ITS SUPPLIERS ASSUME NO RESPONSIBILITY
*** FOR ANY ERRORS THAT MAY APPEAR IN THIS DOCUMENT. MARVELL AND ITS
*** SUPPLIERS MAKE NO COMMITMENT TO UPDATE NOR TO KEEP CURRENT THE
*** INFORMATION CONTAINED IN THIS DOCUMENT.
**/

/**
*** Marvell GPL License Option
***
*** If you received this File from Marvell, you may opt to use, redistribute and/or 
*** modify this File in accordance with the terms and conditions of the General 
*** Public License Version 2, June 1991 (the "GPL License"), a copy of which is 
*** available along with the File in the license.txt file or by writing to the Free 
*** Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or 
*** on the worldwide web at http://www.gnu.org/licenses/gpl.txt. 
***
*** THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED 
*** WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY 
*** DISCLAIMED.  The GPL License provides additional details about this warranty 
*** disclaimer.
**/

/* Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 2, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
   02110-1301, USA.  */

/* As a special exception, if you include this header file into source
   files compiled by GCC, this header file does not by itself cause
   the resulting executable to be covered by the GNU General Public
   License.  This exception does not however invalidate any other
   reasons why the executable file might be covered by the GNU General
   Public License.  */
/*
 *  Definition of a C++ class interface to WMMX(TM) instruction intrinsics.
 *
 */

#ifndef MMCLASS_H_INCLUDED
#define MMCLASS_H_INCLUDED

#if !defined __cplusplus
	#error ERROR: This file is only supported in C++ compilations!
#endif /* ! defined __cplusplus */

#include <mmintrin.h>

class I64vec1;	
class I32vec2;	
class Is32vec2;	
class Iu32vec2;	
class I16vec4;	
class Is16vec4;	
class Iu16vec4;	
class I8vec8;			
class Is8vec8;	
class Iu8vec8;	

#define _wmmx_all_ones ((__m64)0xffffffffffffffffLL)


class M64  
{
protected:
		__m64 __m ;

public:
	M64()									{ __m = 0x0; } 
	M64(__m64 mm)							{ __m = mm; }
	M64(__int64 mm)							{ __m = _mm_set_pi32((int)(mm >> 32), (int)mm); }
	M64(int i)								{ __m = _mm_cvtsi32_si64(i); }

	operator __m64() const		{ return __m; }

};


/*
 * 1 element , each element 64-bits
 *
 */

class I64vec1 : public M64  
{
public:
	I64vec1()								{ }
	explicit I64vec1(__m64 mm) : M64(mm)				{ }
	explicit I64vec1(int i) : M64(i)		{ } 
	explicit I64vec1(__int64 mm) : M64(mm)	{ } 

	I64vec1& operator= (const M64 &__m1) { return *this = (I64vec1) __m1; }
	I64vec1& operator&=(const I64vec1 &__m1) { return *this = (I64vec1) _mm_and_si64(__m,__m1); }
	I64vec1& operator|=(const I64vec1 &__m1) { return *this = (I64vec1) _mm_or_si64(__m,__m1); }
	I64vec1& operator^=(const I64vec1 &__m1) { return *this = (I64vec1) _mm_xor_si64(__m,__m1); }

	/* Shift Logical Operations */
	I64vec1 operator<<(const I64vec1 &__m1)				{ return (I64vec1) _mm_sll_si64(__m, __m1); }
	I64vec1 operator<<(int count) 				    { return (I64vec1) _mm_slli_si64(__m, count); }
	I64vec1& operator<<=(const I64vec1 &__m1)				{ return *this = (I64vec1) _mm_sll_si64(__m, __m1); }
	I64vec1& operator<<=(int count) 				{ return *this = (I64vec1) _mm_slli_si64(__m, count); }
};


/*
 * 2 elements , each element 32-bits
 *
 */


class I32vec2 : public M64  
{
public:
	I32vec2() { }
	I32vec2(int i0, int i1) { __m = _mm_set_pi32(i0, i1); }
	explicit I32vec2(__m64 mm) : M64(mm) { }
	explicit I32vec2(int i) : M64 (i) { }  
	explicit I32vec2(__int64 i): M64(i) {} 

	I32vec2& operator= (const M64 &__m1) { return *this = (I32vec2) __m1; }

	I32vec2& operator&=(const I32vec2 &__m1) { return *this = (I32vec2) _mm_and_si64(__m,__m1); }
	I32vec2& operator|=(const I32vec2 &__m1) { return *this = (I32vec2) _mm_or_si64(__m,__m1); }
	I32vec2& operator^=(const I32vec2 &__m1) { return *this = (I32vec2) _mm_xor_si64(__m,__m1); }

	I32vec2& operator +=(const I32vec2 &__m1)			{ return *this = (I32vec2) _mm_add_pi32(__m,__m1); }
	I32vec2& operator -=(const I32vec2 &__m1)			{ return *this = (I32vec2) _mm_sub_pi32(__m,__m1); }   
	
	I32vec2& operator *=(const I32vec2 &__m1)	{ return *this = (I32vec2)_mm_mullo_pi32(__m,__m1); }   

	I32vec2 operator<<(const I32vec2 &__m1) 			{ return (I32vec2) _mm_sll_pi32(__m,__m1); }
	I32vec2 operator<<(int count) 				    { return (I32vec2) _mm_slli_pi32(__m,count); }
	I32vec2& operator<<=(const I32vec2 &__m1)			{ return *this = (I32vec2) _mm_sll_pi32(__m,__m1); }
	I32vec2& operator<<=(int count) 				{ return *this = (I32vec2) _mm_slli_pi32(__m,count); }
};

class Is32vec2 : public M64  
{
public:
	Is32vec2() { }
	Is32vec2(signed int i0, signed int i1) { __m = _mm_set_pi32(i0, i1); }
	explicit Is32vec2(__m64 mm) : M64(mm) { }
	explicit Is32vec2(int i) : M64 (i)		{} 
	explicit Is32vec2(__int64 i): M64(i)	{} 

	Is32vec2& operator= (const M64 &__m1)		{ return *this = (Is32vec2) __m1; }

	Is32vec2& operator&=(const Is32vec2 &__m1)		{ return *this = (Is32vec2) _mm_and_si64(__m,__m1); }
	Is32vec2& operator|=(const Is32vec2 &__m1)		{ return *this = (Is32vec2) _mm_or_si64(__m,__m1); }
	Is32vec2& operator^=(const Is32vec2 &__m1)		{ return *this = (Is32vec2) _mm_xor_si64(__m,__m1); }

	Is32vec2& operator +=(const Is32vec2 &__m1)	{ return *this = (Is32vec2) _mm_add_pi32(__m,__m1); }
	Is32vec2& operator -=(const Is32vec2 &__m1)	{ return *this = (Is32vec2) _mm_sub_pi32(__m,__m1); }   

	Is32vec2& operator *=(const Is32vec2 &__m1)	{ return *this = (Is32vec2)_mm_mullo_pi32(__m,__m1); }   


	Is32vec2 operator<<(const Is32vec2 &__m1) 		{ return (Is32vec2) _mm_sll_pi32(__m,__m1); }
	Is32vec2 operator<<(int count) 			{ return (Is32vec2) _mm_slli_pi32(__m,count); }
	Is32vec2& operator<<=(const Is32vec2 &__m1)		{ return *this = (Is32vec2) _mm_sll_pi32(__m,__m1); }
	Is32vec2& operator<<=(int count) 		{ return *this = (Is32vec2) _mm_slli_pi32(__m,count); }
	Is32vec2 operator>>(const Is32vec2 &__m1) 		{ return (Is32vec2) _mm_sra_pi32(__m, __m1); }
	Is32vec2 operator>>(int count) 	  		{ return (Is32vec2) _mm_srai_pi32(__m, count); }
	Is32vec2& operator>>=(const Is32vec2 &__m1)		{ return *this = (Is32vec2) _mm_sra_pi32(__m, __m1); }
	Is32vec2& operator>>=(int count) 		{ return *this = (Is32vec2) _mm_srai_pi32(__m, count); }

};

class Iu32vec2 : public M64  
{
public:
	Iu32vec2() { }
	Iu32vec2(unsigned int i0, unsigned int i1) { __m = _mm_set_pi32(i0, i1); }
	explicit Iu32vec2(__m64 mm) : M64(mm) { }
	explicit Iu32vec2(int i) : M64 (i)		{ } 
	explicit Iu32vec2(__int64 i) : M64 (i)	{ } 

	Iu32vec2& operator= (const M64 &__m1)		{ return *this = (Iu32vec2) __m1; }

	Iu32vec2& operator&=(const Iu32vec2 &__m1)		{ return *this = (Iu32vec2) _mm_and_si64(__m,__m1); }
	Iu32vec2& operator|=(const Iu32vec2 &__m1)		{ return *this = (Iu32vec2) _mm_or_si64(__m,__m1); }
	Iu32vec2& operator^=(const Iu32vec2 &__m1)		{ return *this = (Iu32vec2) _mm_xor_si64(__m,__m1); }

	Iu32vec2& operator +=(const Iu32vec2 &__m1)	{ return *this = (Iu32vec2) _mm_add_pi32(__m,__m1); }
	Iu32vec2& operator -=(const Iu32vec2 &__m1)	{ return *this = (Iu32vec2) _mm_sub_pi32(__m,__m1); }   

	Iu32vec2& operator *=(const Iu32vec2 &__m1)	{ return *this = (Iu32vec2)_mm_mullo_pi32(__m,__m1); }   

	Iu32vec2 operator<<(const Iu32vec2 &__m1) 		{ return (Iu32vec2) _mm_sll_pi32(__m,__m1); }
	Iu32vec2 operator<<(int count) 			{ return (Iu32vec2) _mm_slli_pi32(__m,count); }
	Iu32vec2& operator<<=(const Iu32vec2 &__m1)		{ return *this = (Iu32vec2) _mm_sll_pi32(__m,__m1); }
	Iu32vec2& operator<<=(int count) 		{ return *this = (Iu32vec2) _mm_slli_pi32(__m,count); }
	Iu32vec2 operator>>(const Iu32vec2 &__m1) 		{ return (Iu32vec2) _mm_srl_pi32(__m,__m1); }
	Iu32vec2 operator>>(int count) 			{ return (Iu32vec2) _mm_srli_pi32(__m,count); }
	Iu32vec2& operator>>=(const Iu32vec2 &__m1)		{ return *this = (Iu32vec2) _mm_srl_pi32(__m,__m1); }
	Iu32vec2& operator>>=(int count) 		{ return *this = (Iu32vec2) _mm_srli_pi32(__m,count); }

};

/*
 * 4 elements , each element 16-bits
 *
 */

class I16vec4 : public M64  
{
public:
	I16vec4() { }
	I16vec4(short i0, short i1, short i2, short i3)  {  __m = _mm_set_pi16(i0, i1, i2, i3);   }
	explicit I16vec4(__m64 mm) : M64(mm) { }
	explicit I16vec4(__int64 i) : M64 (i) { }	
	explicit I16vec4(int i) : M64 (i) { }		

	I16vec4& operator= (const M64 &__m1)				{ return *this = (I16vec4) __m1; }

	I16vec4& operator&=(const I16vec4 &__m1)				{ return *this = (I16vec4) _mm_and_si64(__m,__m1); }
	I16vec4& operator|=(const I16vec4 &__m1)				{ return *this = (I16vec4) _mm_or_si64(__m,__m1); }
	I16vec4& operator^=(const I16vec4 &__m1)				{ return *this = (I16vec4) _mm_xor_si64(__m,__m1); }

	I16vec4& operator +=(const I16vec4 &__m1)			{ return *this = (I16vec4)_mm_add_pi16(__m,__m1); }
	I16vec4& operator -=(const I16vec4 &__m1)			{ return *this = (I16vec4)_mm_sub_pi16(__m,__m1); }   
	I16vec4& operator *=(const I16vec4 &__m1)			{ return *this = (I16vec4)_mm_mullo_pi16(__m,__m1); }   

	I16vec4 operator<<(const I16vec4 &__m1) 			{ return (I16vec4) _mm_sll_pi16(__m,__m1); }
	I16vec4 operator<<(int count) 				    { return (I16vec4) _mm_slli_pi16(__m,count); }
	I16vec4& operator<<=(const I16vec4 &__m1)			{ return *this = (I16vec4)_mm_sll_pi16(__m,__m1); }
	I16vec4& operator<<=(int count) 				{ return *this = (I16vec4)_mm_slli_pi16(__m,count); }

};

class Is16vec4 : public M64
{
public:
	Is16vec4() { }
	Is16vec4(short i0, short i1, short i2, short i3){ __m = _mm_set_pi16(i0, i1, i2, i3);}
	explicit Is16vec4(__m64 mm) : M64(mm) { }
	explicit Is16vec4(__int64 i) : M64 (i)	{ }	
	explicit Is16vec4(int i) : M64 (i)		{ }		

	Is16vec4& operator= (const M64 &__m1)		{ return *this = (Is16vec4) __m1; }

	Is16vec4& operator&=(const Is16vec4 &__m1)		{ return *this = (Is16vec4) _mm_and_si64(__m,__m1); }
	Is16vec4& operator|=(const Is16vec4 &__m1)		{ return *this = (Is16vec4) _mm_or_si64(__m,__m1); }
	Is16vec4& operator^=(const Is16vec4 &__m1)		{ return *this = (Is16vec4) _mm_xor_si64(__m,__m1); }

	Is16vec4& operator +=(const Is16vec4 &__m1)	{ return *this = (Is16vec4)_mm_add_pi16(__m,__m1); }
	Is16vec4& operator -=(const Is16vec4 &__m1)	{ return *this = (Is16vec4)_mm_sub_pi16(__m,__m1); }   
	Is16vec4& operator *=(const Is16vec4 &__m1)	{ return *this = (Is16vec4)_mm_mullo_pi16(__m,__m1); }   

	Is16vec4 operator<<(const Is16vec4 &__m1) 		{ return (Is16vec4)_mm_sll_pi16(__m,__m1); }
	Is16vec4 operator<<(int count) 			{ return (Is16vec4)_mm_slli_pi16(__m,count); }
	Is16vec4& operator<<=(const Is16vec4 &__m1)		{ return *this = (Is16vec4)_mm_sll_pi16(__m,__m1); }
	Is16vec4& operator<<=(int count) 		{ return *this = (Is16vec4)_mm_slli_pi16(__m,count); }
	Is16vec4 operator>>(const Is16vec4 &__m1) 		{ return (Is16vec4)_mm_sra_pi16(__m,__m1); } 
	Is16vec4 operator>>(int count) 			{ return (Is16vec4)_mm_srai_pi16(__m,count); }
	Is16vec4& operator>>=(const Is16vec4 &__m1)		{ return *this = (Is16vec4) _mm_sra_pi16(__m,__m1); } 
	Is16vec4& operator>>=(int count) 		{ return *this = (Is16vec4) _mm_srai_pi16(__m,count); }

};

class Iu16vec4 : public M64
{
public:
	Iu16vec4() { }
	Iu16vec4(unsigned short ui0, unsigned short ui1,
                 unsigned short ui2, unsigned short ui3) {__m = _mm_set_pi16(ui0, ui1, ui2, ui3);}
	explicit Iu16vec4(__m64 mm) : M64(mm) { }
	explicit Iu16vec4(__int64 i) : M64 (i) { }	
	explicit Iu16vec4(int i) : M64 (i) { }		

	Iu16vec4& operator= (const M64 &__m1)		{ return *this = (Iu16vec4) __m1; }

	Iu16vec4& operator&=(const Iu16vec4 &__m1)		{ return *this = (Iu16vec4) _mm_and_si64(__m,__m1); }
	Iu16vec4& operator|=(const Iu16vec4 &__m1)		{ return *this = (Iu16vec4) _mm_or_si64(__m,__m1); }
	Iu16vec4& operator^=(const Iu16vec4 &__m1)		{ return *this = (Iu16vec4) _mm_xor_si64(__m,__m1); }

	Iu16vec4& operator +=(const Iu16vec4 &__m1)	{ return *this = (Iu16vec4)_mm_add_pi16(__m,__m1); }
	Iu16vec4& operator -=(const Iu16vec4 &__m1)	{ return *this = (Iu16vec4)_mm_sub_pi16(__m,__m1); }   
	Iu16vec4& operator *=(const Iu16vec4 &__m1)	{ return *this = (Iu16vec4)_mm_mullo_pi16(__m,__m1); }   

	Iu16vec4 operator<<(const Iu16vec4 &__m1) 				{ return (Iu16vec4)_mm_sll_pi16(__m,__m1); }
	Iu16vec4 operator<<(int count) 				    { return (Iu16vec4)_mm_slli_pi16(__m,count); }
	Iu16vec4& operator<<=(const Iu16vec4 &__m1)				{ return *this = (Iu16vec4)_mm_sll_pi16(__m,__m1); }
	Iu16vec4& operator<<=(int count) 				{ return *this = (Iu16vec4)_mm_slli_pi16(__m,count); }
	Iu16vec4 operator>>(const Iu16vec4 &__m1) 				{ return (Iu16vec4)_mm_srl_pi16(__m,__m1); }
	Iu16vec4 operator>>(int count) 				    { return (Iu16vec4)_mm_srli_pi16(__m,count); }
	Iu16vec4& operator>>=(const Iu16vec4 &__m1)				{ return *this = (Iu16vec4) _mm_srl_pi16(__m,__m1); }
	Iu16vec4& operator>>=(int count) 				{ return *this = (Iu16vec4) _mm_srli_pi16(__m,count); }

};

/*
 * 8 elements , each element 8-bits
 *
 */

class I8vec8 : public M64  
{
public:
	I8vec8() { }
	I8vec8(char s0, char s1, char s2, char s3, char s4, char s5, char s6, char s7) 
            {
                __m = _mm_set_pi8(s0, s1, s2, s3, s4, s5, s6, s7);
            }
	explicit I8vec8(__m64 mm) : M64(mm) { }
	explicit I8vec8(__int64 i) : M64 (i) { }	
	explicit I8vec8(int i) : M64 (i) { }		

	I8vec8& operator= (const M64 &__m1)		{ return *this = (I8vec8) __m1; }

	I8vec8& operator&=(const I8vec8 &__m1)		{ return *this = (I8vec8) _mm_and_si64(__m,__m1); }
	I8vec8& operator|=(const I8vec8 &__m1)		{ return *this = (I8vec8) _mm_or_si64(__m,__m1); }
	I8vec8& operator^=(const I8vec8 &__m1)		{ return *this = (I8vec8) _mm_xor_si64(__m,__m1); }

	I8vec8& operator +=(const I8vec8 &__m1)	{ return *this = (I8vec8) _mm_add_pi8(__m,__m1); }
	I8vec8& operator -=(const I8vec8 &__m1)	{ return *this = (I8vec8) _mm_sub_pi8(__m,__m1); }   

};

class Is8vec8 : public M64  
{
public:
	Is8vec8() { }
	Is8vec8(signed char s0, signed char s1, signed char s2, signed char s3,
                signed char s4, signed char s5, signed char s6, signed char s7)
            {
                __m = _mm_set_pi8(s0, s1, s2, s3, s4, s5, s6, s7);
            }
	explicit Is8vec8(__m64 mm) : M64(mm) { }
 	explicit Is8vec8(__int64 i) : M64 (i) { }	
	explicit Is8vec8(int i) : M64 (i) { }		

	Is8vec8& operator= (const M64 &__m1)		{ return *this = (Is8vec8) __m1; }

	Is8vec8& operator&=(const Is8vec8 &__m1)		{ return *this = (Is8vec8) _mm_and_si64(__m,__m1); }
	Is8vec8& operator|=(const Is8vec8 &__m1)		{ return *this = (Is8vec8) _mm_or_si64(__m,__m1); }
	Is8vec8& operator^=(const Is8vec8 &__m1)		{ return *this = (Is8vec8) _mm_xor_si64(__m,__m1); }

	Is8vec8& operator +=(const Is8vec8 &__m1)	{ return *this = (Is8vec8) _mm_add_pi8(__m,__m1); }
	Is8vec8& operator -=(const Is8vec8 &__m1)	{ return *this = (Is8vec8) _mm_sub_pi8(__m,__m1); }   

};

class Iu8vec8 : public M64  
{
public:
	Iu8vec8() { }
	Iu8vec8(unsigned char s0, unsigned char s1, unsigned char s2,
                unsigned char s3, unsigned char s4, unsigned char s5,
                unsigned char s6, unsigned char s7)
           {
                __m = _mm_set_pi8(s0, s1, s2, s3, s4, s5, s6, s7);
            }
	explicit Iu8vec8(__m64 mm) : M64(mm) { }
	explicit Iu8vec8(__int64 i) : M64 (i) { }	
	explicit Iu8vec8(int i) : M64 (i) { }		

	Iu8vec8& operator= (const M64 &__m1)		{ return *this = (Iu8vec8) __m1; }

	Iu8vec8& operator&=(const Iu8vec8 &__m1)		{ return *this = (Iu8vec8) _mm_and_si64(__m,__m1); }
	Iu8vec8& operator|=(const Iu8vec8 &__m1)		{ return *this = (Iu8vec8) _mm_or_si64(__m,__m1); }
	Iu8vec8& operator^=(const Iu8vec8 &__m1)		{ return *this = (Iu8vec8) _mm_xor_si64(__m,__m1); }

	Iu8vec8& operator +=(const Iu8vec8 &__m1)	{ return *this = (Iu8vec8) _mm_add_pi8(__m,__m1); }
	Iu8vec8& operator -=(const Iu8vec8 &__m1)	{ return *this = (Iu8vec8) _mm_sub_pi8(__m,__m1); }   

};



/********************************* Logicals ****************************************/
#define MMCLASS_LOGICALS(vect,element) \
inline I##vect##vec##element operator& (const I##vect##vec##element &a, const I##vect##vec##element &b) \
{ return (I##vect##vec##element) _mm_and_si64( a,b); } \
inline I##vect##vec##element operator| (const I##vect##vec##element &a, const I##vect##vec##element &b) \
{ return (I##vect##vec##element) _mm_or_si64( a,b); } \
inline I##vect##vec##element operator^ (const I##vect##vec##element &a, const I##vect##vec##element &b) \
{ return (I##vect##vec##element) _mm_xor_si64( a,b); } \
inline I##vect##vec##element andnot (const I##vect##vec##element &a, const I##vect##vec##element &b) \
{ return (I##vect##vec##element) _mm_andnot_si64( a,b); } 

MMCLASS_LOGICALS(8,8)
MMCLASS_LOGICALS(u8,8)
MMCLASS_LOGICALS(s8,8)
MMCLASS_LOGICALS(16,4)
MMCLASS_LOGICALS(u16,4)
MMCLASS_LOGICALS(s16,4)
MMCLASS_LOGICALS(32,2)
MMCLASS_LOGICALS(u32,2)
MMCLASS_LOGICALS(s32,2)
MMCLASS_LOGICALS(64,1)
#undef MMCLASS_LOGICALS


/********************************* Add & Sub ****************************************/
#define MMCLASS_ADD_SUB(vect,element,opsize) \
inline I##vect##vec##element operator+ (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element) _mm_add_pi##opsize( __m1,__m2); } \
inline I##vect##vec##element operator- (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element) _mm_sub_pi##opsize( __m1,__m2); }
MMCLASS_ADD_SUB(8,8, 8)
MMCLASS_ADD_SUB(u8,8,8)
MMCLASS_ADD_SUB(s8,8,8)
MMCLASS_ADD_SUB(16,4,16)
MMCLASS_ADD_SUB(u16,4,16)
MMCLASS_ADD_SUB(s16,4,16)
MMCLASS_ADD_SUB(32,2, 32)
MMCLASS_ADD_SUB(u32,2,32)
MMCLASS_ADD_SUB(s32,2,32)

#undef MMCLASS_ADD_SUB

/********************************* SAT Add & Sub ****************************************/
#define MMCLASS_SAT_ADD_SUB(vect,element,opsize) \
inline I##vect##vec##element sat_add(const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_adds_p##opsize( __m1,__m2); }\
inline I##vect##vec##element sat_sub(const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_subs_p##opsize( __m1,__m2); }

MMCLASS_SAT_ADD_SUB(u8,8,u8)
MMCLASS_SAT_ADD_SUB(s8,8,i8)
MMCLASS_SAT_ADD_SUB(u16,4,u16)
MMCLASS_SAT_ADD_SUB(s16,4,i16)
MMCLASS_SAT_ADD_SUB(u32,2,u32)
MMCLASS_SAT_ADD_SUB(s32,2,i32)

#undef MMCLASS_SAT_ADD_SUB

/********************************* Compare Operator ****************************************/
#define MMCLASS_EQ(vect,element,opsize) \
inline I##vect##vec##element operator== (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_cmpeq_pi##opsize( __m1,__m2); }\
inline I##vect##vec##element operator!= (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_andnot_si64(_mm_cmpeq_pi##opsize(__m1,__m2), _wmmx_all_ones); } 

MMCLASS_EQ(8,8, 8)
MMCLASS_EQ(u8,8,8)
MMCLASS_EQ(s8,8,8)
MMCLASS_EQ(16,4,16)
MMCLASS_EQ(u16,4,16)
MMCLASS_EQ(s16,4,16)
MMCLASS_EQ(32,2, 32)
MMCLASS_EQ(u32,2,32)
MMCLASS_EQ(s32,2,32)

#undef MMCLASS_EQ

#define MMCLASS_GT(vect,element,opsize) \
inline I##vect##vec##element operator> (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_cmpgt_p##opsize( __m1,__m2); } \
inline I##vect##vec##element operator< (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_cmpgt_p##opsize( __m2,__m1); } \
inline I##vect##vec##element operator>= (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_andnot_si64(_mm_cmpgt_p##opsize( __m2,__m1), _wmmx_all_ones); } \
inline I##vect##vec##element operator<= (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_andnot_si64(_mm_cmpgt_p##opsize( __m1,__m2), _wmmx_all_ones); } 


MMCLASS_GT(u8,8,u8)
MMCLASS_GT(s8,8,i8)
MMCLASS_GT(u16,4,u16)
MMCLASS_GT(s16,4,i16)
MMCLASS_GT(u32,2,u32)
MMCLASS_GT(s32,2,i32)

#undef MMCLASS_GT

/********************************* Unpack ****************************************/
#define MMCLASS_UNPACK(vect,element,opsize) \
inline I##vect##vec##element unpack_low (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_unpacklo_pi##opsize( __m1,__m2); } \
inline I##vect##vec##element unpack_high (const I##vect##vec##element &__m1, const I##vect##vec##element &__m2) \
{ return (I##vect##vec##element)_mm_unpackhi_pi##opsize( __m1,__m2); } 

MMCLASS_UNPACK(8,8, 8)
MMCLASS_UNPACK(u8,8,8)
MMCLASS_UNPACK(s8,8,8)
MMCLASS_UNPACK(16,4,16)
MMCLASS_UNPACK(u16,4,16)
MMCLASS_UNPACK(s16,4,16)
MMCLASS_UNPACK(32,2, 32)
MMCLASS_UNPACK(u32,2,32)
MMCLASS_UNPACK(s32,2,32)

#undef MMCLASS_UNPACK

/********************************* Multiplication ****************************************/

#define MMCLASS_MULLO(vect,element,opsize) \
inline I##vect##vec##element operator*(const I##vect##vec##element &__m1, const I##vect##vec##element &__m2)\
{ return (I##vect##vec##element)_mm_mullo_pi##opsize(__m1,__m2); }

MMCLASS_MULLO(u16,4,16)
MMCLASS_MULLO(s16,4,16)
MMCLASS_MULLO(16,4,16)
MMCLASS_MULLO(u32,2,32)
MMCLASS_MULLO(s32,2,32)
MMCLASS_MULLO(32,2,32)

#undef MMCLASS_MULLO

#define MMCLASS_MULHI(vect,element,opsize) \
inline I##vect##vec##element mul_high(const I##vect##vec##element &__m1, const I##vect##vec##element &__m2)\
{ return (I##vect##vec##element)_mm_mulhi_p##opsize(__m1,__m2); }

MMCLASS_MULHI(s16,4,i16)
MMCLASS_MULHI(u16,4,u16)
MMCLASS_MULHI(s32,2,i32)
MMCLASS_MULHI(u32,2,u32)

#undef MMCLASS_MULLO

inline Is32vec2 mul_add(const Is16vec4 &__m1, const Is16vec4 &__m2)		{ return (Is32vec2)_mm_madd_pi16(__m1,__m2);}
inline Iu32vec2 mul_add(const Iu16vec4 &__m1, const Iu16vec4 &__m2)		{ return (Iu32vec2)_mm_madd_pu16(__m1,__m2);}

/********************************* Pack/Unpack ****************************************/

inline Is16vec4 pack_sat(const Is32vec2 &__m1, const Is32vec2 &__m2)		{ return (Is16vec4)_mm_packs_pi32(__m1,__m2); }
inline Is8vec8 pack_sat(const Is16vec4 &__m1, const Is16vec4 &__m2) 		{ return (Is8vec8)_mm_packs_pi16(__m1,__m2); }

inline Iu16vec4 packu_sat(const Iu32vec2 &__m1, const Iu32vec2 &__m2) 	{ return (Iu16vec4)_mm_packs_pu32(__m1,__m2); }
inline Iu8vec8 packu_sat(const Iu16vec4 &__m1, const Iu16vec4 &__m2) 	{ return (Iu8vec8)_mm_packs_pu16(__m1,__m2); }

#endif // MMCLASS_H_INCLUDED
