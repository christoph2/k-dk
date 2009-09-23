/**********************************************************************************************************
*                                              xxx-OSEK
*                              An OpenSource OSEK/VDX-Implementation
*
*                          (c) Copyright 2006-2008, Christoph Schueler
*
*               All rights reserved.  Protected by international copyright laws.
*
*                         *** PRE-ALPHA, ONLY FOR INTERNAL USAGE ***
*
**********************************************************************************************************/

#include "Utl.h"

static uint32 NextRandomNumber=1;

static const uint16 PowerOfTwoTab16[16]={
    (uint16)0x0001,(uint16)0x0002,(uint16)0x0004,(uint16)0x0008,
    (uint16)0x0010,(uint16)0x0020,(uint16)0x0040,(uint16)0x0080,
    (uint16)0x0100,(uint16)0x0200,(uint16)0x0400,(uint16)0x0800,
    (uint16)0x1000,(uint16)0x2000,(uint16)0x4000,(uint16)0x8000
};


boolean Utl_BitGet(uint16 w,uint8 num)
{
    return ((w & PowerOfTwoTab16[num])!=(uint16)0x0000U);
}


uint16 Utl_BitSet(uint16 w,uint8 num)
{
    return w|=PowerOfTwoTab16[num];
}


uint16 Utl_BitReset(uint16 w,uint8 num)
{
    return w&=~(PowerOfTwoTab16[num]);
}


uint16 Utl_BitToggle(uint16 w,uint8 num)
{
    return w^=PowerOfTwoTab16[num];
}


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


/* 
**  Hinweis:    wenn die Konfiguration eine Memory-Map enthält, können Schreib-Zugriffe
**              in den Register-Bereich und in Read-Only-Bereiche mit einer
**              Assertion abgefangen werden.
*/

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
    /* 'assignment in condition' ist nicht MISRA-C konform!!! */
    while (*(dst++)=*(src++))
        {}
}


void Utl_StrCpy(uint8 * RESTRICT dst,const uint8 * RESTRICT  src)
{
    ASSERT(dst!=(void*)NULL);
    /* 'assignment in condition' ist nicht MISRA-C konform!!! */
    while (*(dst++)=*(src++))
        {}
}


/*
 *      Hinweis: Der COSMIC-Compiler generiert bei der folgenden Funktion ein 'TBEQ' ohne Register!!!
 */

#if 0
void Utl_StrNCpy(uint8 * RESTRICT dst,const uint8 * RESTRICT  src,SizeType maxlen)
{
    ASSERT(dest!=(void*)NULL);
    
    /* 'assignment in condition' ist nicht MISRA-C konform!!! */
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

/*
**  todo: 'StrCenter(uint8 * str,uint8 filler)' 'Str[e|L|R]Trim'  !!!
**          StrCmp, StrNCmp
**        
*/

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
