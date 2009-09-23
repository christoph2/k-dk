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

/* todo: 'char's in  'uint8's umwandeln!!! */

#if !defined(__UTL_H)
#define __UTL_H

#include "Std_Types.h"
#include "CPU_Primitives.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

typedef enum tagUtl_EndianessType {
    UTL_BIG_ENDIAN,
    UTL_LITTLE_ENDIAN
} Utl_EndianessType;

typedef struct tagUtl_DivremType {
    uint16 div,rem;
} Utl_DivremType;


typedef sint8 (*Utl_CompareFuncType)(void const * lhs,void const * rhs);

Utl_EndianessType Utl_CheckEndianess(void);

boolean Utl_BitGet(uint16 w,uint8 num);
uint16 Utl_BitSet(uint16 w,uint8 num);
uint16 Utl_BitReset(uint16 w,uint8 num);
uint16 Utl_BitToggle(uint16 w,uint8 num);
uint16 Utl_BitGetHighest(uint16 w);
uint16 Utl_BitGetLowest(uint16 w);
uint16 Utl_BitSetLowest(uint16 w);
uint16 Utl_BitResetLowest(uint16 w);

uint8 Utl_Log2(uint16 num);

void Utl_Itoa(uint32 value,uint8 base,uint8 *buf);

void Utl_MemCopy(void * RESTRICT dst,void * RESTRICT src,SizeType len);
void Utl_MemSet(void *dest,uint8 fill_char,SizeType len);

SizeType Utl_StrLen(const uint8 *src);
void Utl_StrCat(/*@out@*/uint8 * RESTRICT dst,/*@in@*/const uint8 * RESTRICT src);
void Utl_StrCpy(/*@out@*/uint8 * RESTRICT dst,/*@in@*/const uint8 * RESTRICT  src);
void Utl_StrNCpy(/*@out@*/uint8 * RESTRICT dst,/*@in@*/const uint8 * RESTRICT  src,SizeType maxlen);
void Utl_StrRev(/*@in@*//*@out@*/uint8 *str);
const uint8 *Utl_StrChr(/*@in@*/const uint8 * str,uint8 ch);

void const * Utl_BinSearch(void const * key,void const * base,uint16 num_elems,uint16 elem_size,Utl_CompareFuncType compare_func);

void Utl_Divrem(uint16 dividend,uint16 divisor,/*@out@*/Utl_DivremType *res);
boolean Utl_FloatsAreNearlyEqual(float32 lhs,float32 rhs,sint32 max_difference);

void Utl_Randomize(uint16 seed);
uint16 Utl_Random(void);

typedef struct tagUtl_JumpBufType {
    SizeType pc;
    SizeType sp;
} Utl_JumpBufType;

void Utl_LongJump(Utl_JumpBufType *buf,sint16 val);
uint16 Utl_SetJump(Utl_JumpBufType *buf);

/*@nullwhentrue@*/boolean Utl_IsNull(void *Ptr);


#define ASSERT_IS_NOT_NULL(ptr) ASSERT(!Utl_IsNull((ptr)))
#if 0
#define ASSERT_IS_NOT_NULL(ptr)             \
    _BEGIN_BLOCK                            \
        if (Utl_IsNull((ptr))) {            \
              CPU_SOFTWARE_INTERRUPT();     \
            return;                         \
        }                                   \
    _END_BLOCK
#endif

#define Utl_PlainCharIsSigned() ((int)((char)0x80)<0)

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __UTL_H */
