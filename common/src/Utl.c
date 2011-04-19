/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
 *
 * All Rights Reserved
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#include "Utl.h"

const uint8 Utl_SetBitTab8[8]={
    (uint8)0x01,(uint8)0x02,(uint8)0x04,(uint8)0x08,(uint8)0x10,(uint8)0x20,(uint8)0x40,(uint8)0x80
};

const uint8 Utl_ClearBitTab8[8]={
    (uint8)0xFE,(uint8)0xFD,(uint8)0xFB,(uint8)0xF7,(uint8)0xEF,(uint8)0xDF,(uint8)0xBF,(uint8)0x7F
};

const uint16 Utl_SetBitTab16[16]={
    (uint16)0x0001U,(uint16)0x0002U,(uint16)0x0004U,(uint16)0x0008U,
    (uint16)0x0010U,(uint16)0x0020U,(uint16)0x0040U,(uint16)0x0080U,
    (uint16)0x0100U,(uint16)0x0200U,(uint16)0x0400U,(uint16)0x0800U,
    (uint16)0x1000U,(uint16)0x2000U,(uint16)0x4000U,(uint16)0x8000U
};

const uint16 Utl_ClearBitTab16[16]={
    (uint16)0xFFFEU,(uint16)0xFFFDU,(uint16)0xFFFBU,(uint16)0xFFF7U,
    (uint16)0xFFEFU,(uint16)0xFFDFU,(uint16)0xFFBFU,(uint16)0xFF7FU,
    (uint16)0xFEFFU,(uint16)0xFDFFU,(uint16)0xFBFFU,(uint16)0xF7FFU,
    (uint16)0xEFFFU,(uint16)0xDFFFU,(uint16)0xBFFFU,(uint16)0x7FFFU
};

#if 0
#define BIT_8(n)    ((const uint8[8]){1,2,4,8,16,32,64,128})[n];
#endif

static uint32 NextRandomNumber=1;

#if 0
boolean Utl_BitGet(uint16 w,uint8 num)
{
    return ((w & Utl_SetBitTab16[num])!=(uint16)0x0000U);
}

uint16 Utl_BitSet(uint16 w,uint8 num)
{
    return w|=Utl_SetBitTab16[num];
}


uint16 Utl_BitReset(uint16 w,uint8 num)
{
    return w&=~(Utl_SetBitTab16[num]);
}


uint16 Utl_BitToggle(uint16 w,uint8 num)
{
    return w^=Utl_SetBitTab16[num];
}
#endif

uint16 Utl_BitGetHighest(uint16 w)
{
    w|=w>>1;
    w|=w>>2;
    w|=w>>4;
    w|=w>>8;

    return w^(w>>1);
}


uint16 Utl_BitGetLowest(uint16 w)
{
    return (~w+1) & w;
}


uint16 Utl_BitSetLowest(uint16 w)
{
    return w | (w+1);
}


uint16 Utl_BitResetLowest(uint16 w)
{
    return w & (w-1);
}


uint8 Utl_Log2(uint16 num)
{
    uint8 res=(uint8)0x00;

    while (num>>=1) {
        res++;
    }

    return res;
}


Utl_EndianessType Utl_CheckEndianess(void)
{
    const uint16 foo=0xaa55U;
    uint8 *ptr=(uint8*)&foo;

    if (0[ptr]==(uint8)0xaa) {
        return UTL_BIG_ENDIAN;
    } else {
        return UTL_LITTLE_ENDIAN;
    }
}


void Utl_MemCopy(void * RESTRICT dst,void * RESTRICT src,SizeType len)
{
    uint8 *pd=(uint8*)dst;
    uint8 *ps=(uint8*)src;

    ASSERT(dst!=(void*)NULL);
    ASSERT(pd>=ps+len || ps>=pd+len);
    ASSERT(len!=(SizeType)0);

    while (len--) {
        *pd++=*ps++;
    }

}


void Utl_MemSet(void *dest,uint8 fill_char,SizeType len)
{
    uint8 *p=(uint8*)dest;

    ASSERT(dest!=(void*)NULL);

    while (len--) {
        *p++=fill_char;
    }
}


void Utl_Randomize(uint16 seed)
{
    NextRandomNumber=(uint32)seed;
}


uint16 Utl_Random(void)
{
    NextRandomNumber=NextRandomNumber * (uint32)0x41C64E6DUL + (uint32)0x3039UL;
    return (uint16)(NextRandomNumber/(uint32)0x10000UL) % (uint32)0x8000UL;

}


SizeType Utl_StrLen(const uint8 *src)
{
    SizeType len=(SizeType)0x0000;

    while (*(src++)) {
        len++;
    }

    return len;
}


void Utl_StrCat(uint8 * RESTRICT dst,const uint8 * RESTRICT  src)
{
    ASSERT(dst!=(void*)NULL);

    while (*(dst++))
        {}
    --dst;

    while (*(dst++)=*(src++))
        {}
}


void Utl_StrCpy(uint8 * RESTRICT dst,const uint8 * RESTRICT  src)
{
    ASSERT(dst!=(void*)NULL);

    while (*(dst++)=*(src++))
        {}
}



#if 0
void Utl_StrNCpy(uint8 * RESTRICT dst,const uint8 * RESTRICT  src,SizeType maxlen)
{
    ASSERT(dest!=(void*)NULL);

    while ((*(dst++)=*(src++)) && (maxlen--))
        {}
}
#endif


void Utl_StrRev(uint8 *str)
{
    SizeType idx;
    SizeType dpos;
    uint8 ch;

    ASSERT(str!=(void*)NULL);

    for (idx=(SizeType)0,dpos=Utl_StrLen(str)-1;dpos>idx;idx++,dpos--) {
        ch=dpos[str];
        dpos[str]=idx[str];
        idx[str]=ch;
    }
}


const uint8 * Utl_StrChr(const uint8 * str,uint8 ch)
{
    ASSERT(str!=(void*)NULL);

    while (*str) {
        if (*(str++)==ch) {
            return str;
        }
    }

    return (const uint8 *)NULL;
}


void Utl_Itoa(uint32 value,uint8 base,uint8 * buf)
{
    uint32 mod;
    uint8 pos=(uint8)0x00,swap_pos=(uint8)0x00;
    uint8 ch;

    ASSERT(buf!=(void*)NULL);

    if (((sint32)value)<0L && base==(uint8)10) {
        value=(uint32)((sint32)value*-1L);
        buf[0]='-';
        swap_pos=1;
        pos=1;
    }

    if (value==0L) {
        buf[pos++]='0';
    }

    while (value) {
        mod=value%base;
        if (mod<10) {
            buf[pos++]='0'+mod;
        } else {
            buf[pos++]='A'+mod-(uint8)10;
        }
        value/=base;
    }

    buf[pos--]='\0';

    while (pos>swap_pos) {
        ch=buf[swap_pos];
        buf[swap_pos]=buf[pos];
            buf[pos]=ch;
        swap_pos++;
        pos--;
    }
}

#if 0
void const * Utl_BinSearch(void const * key,void const * base,uint16 num_elems,uint16 elem_size,Utl_CompareFuncType compare_func)
{
    uint16 mid;
    sint16 left,right;
    uint8 *cmp_key;
    sint8 res;

    left=(sint16)0x0000;
    right=(sint16)(num_elems-1);

    do {
        mid=(uint16)(left+right)>>1;
        cmp_key=(uint8*)((uint8*)base+(mid*elem_size));
        res=compare_func(key,cmp_key);
        if (res==(sint16)0) {
            return cmp_key;
        } else if (res<(uint8)0) {
            right=mid-1;
        } else {
            left=mid+1;
        }
    } while (left<=right);

    return (void const *)NULL;
}
#endif

boolean Utl_FloatsAreNearlyEqual(float lhs,float rhs,sint32 max_difference)
{
    sint32 lhs_int=*(sint32*)&lhs;
    sint32 rhs_int=*(sint32*)&rhs;
    sint32 int_difference;

    if (lhs_int<(sint32)0) {
        lhs_int=(sint32)(0x80000000-lhs_int);
    }

    if (rhs_int<(sint32)0) {
        rhs_int=(sint32)(0x80000000-rhs_int);
    }

    int_difference=ABS(lhs_int-rhs_int);

    return ((int_difference<=max_difference) ? TRUE : FALSE);
}

boolean Utl_IsNull(void *Ptr)
{
    return (Ptr==(void*)NULL) ? TRUE : FALSE;
}


uint16 Utl_Swap16(uint16 *w)
{
    return MAKEWORD(LOBYTE(*w),HIBYTE(*w));
}


uint32 Utl_Swap32(uint32 *dw)
{
    return MAKEDWORD(MAKEWORD(LOBYTE(LOWORD(*dw)),HIBYTE(LOWORD(*dw))),MAKEWORD(LOBYTE(HIWORD(*dw)),HIBYTE(HIWORD(*dw))));
}
