/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined( __PLATFORM_TYPES_PIC_H)
#define __PLATFORM_TYPES_PIC_H

/* Definitions for PIC. */

/* Symbols  */
#define   CPU_TYPE          CPU_TYPE_16
#define   CPU_BIT_ORDER     LSB_FIST
#define   CPU_BYTE_ORDER    HIGH_BYTE_FIRST

#if ((defined(__PCH__) || defined(__PCB__) || defined(__PCM__)) && defined(_DLIB_ADD_C99_SYMBOLS)) || (defined(_C99_COMPILER)) || \
    (defined(_CPP_COMPILER))

#include <stdint.h>
#include <stdbool.h>

typedef unsigned char boolean;

typedef /*@signed-integral-type@*/ int8_t       sint8;
typedef /*@unsigned-integral-type@*/ int8_t     uint8;
typedef /*@signed-integral-type@*/ int16_t      sint16;
typedef /*@unsigned-integral-type@*/ uint16_t   uint16;
typedef /*@signed-integral-type@*/ int32_t      sint32;
typedef /*@unsigned-integral-type@*/ uint32_t   uint32;

typedef /*@signed-integral-type@*/ int_least8_t     sint8_least;
typedef /*@unsigned-integral-type@*/ uint_least8_t  uint8_least;
typedef /*@signed-integral-type@*/ int_least16_t    sint16_least;
typedef /*@unsigned-integral-type@*/ uint_least16_t uint16_least;
typedef /*@signed-integral-type@*/ int_least32_t    sint32_least;
typedef /*@unsigned-integral-type@*/ uint_least32_t uint32_least;

#if !defined(TRUE)
    #define TRUE    ((boolean)true)
#endif

#if !defined(FALSE)
    #define FALSE   ((boolean)false)
#endif

#else
/* Types  */
typedef int1 boolean;
#if 0
typedef signed int8     sint8;
typedef unsigned int8   uint8;
#endif
typedef signed char     sint8;
typedef unsigned char   uint8;

typedef signed int16    sint16;
typedef unsigned int16  uint16;
typedef signed int32    sint32;
typedef unsigned int32  uint32;

typedef signed int8     sint8_least;
typedef unsigned int8   uint8_least;
typedef signed int16    sint16_least;
typedef unsigned int16  uint16_least;
typedef signed int32    sint32_least;
typedef unsigned int32  uint32_least;

#if !defined(TRUE)
    #define TRUE    ((boolean)1)
#endif

#if !defined(FALSE)
    #define FALSE   ((boolean)0)
#endif

#endif

/* typedef float           float32; */
/* typedef double          float64; */
typedef void *          pvoid;
typedef unsigned int16  SizeType;
typedef signed int16    PtrDiffType;

#endif /* __PLATFORM_TYPES_PIC_H  */

