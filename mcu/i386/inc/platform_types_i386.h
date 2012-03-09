/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
#if !defined( __PLATFORM_TYPES_I386_H)
#define __PLATFORM_TYPES_I386_H

/* Definitions for i386 / MSVC. */

/* Symbols  */
#define CPU_TYPE        CPU_TYPE_32
#define CPU_BIT_ORDER   MSB_FIST
#define CPU_BYTE_ORDER  LOW_BYTE_FIRST

typedef unsigned char boolean;

typedef /*@signed-integral-type@*/ __int8               sint8;
typedef /*@unsigned-integral-type@*/ unsigned __int8    uint8;
typedef /*@signed-integral-type@*/ __int16              sint16;
typedef /*@unsigned-integral-type@*/ unsigned __int16   uint16;
typedef /*@signed-integral-type@*/ __int32              sint32;
typedef /*@unsigned-integral-type@*/ unsigned __int32  uint32;

typedef /*@signed-integral-type@*/ __int8               sint8_least;
typedef /*@unsigned-integral-type@*/ unsigned __int8    uint8_least;
typedef /*@signed-integral-type@*/ __int16              sint16_least;
typedef /*@unsigned-integral-type@*/ unsigned __int16   uint16_least;
typedef /*@signed-integral-type@*/ __int32              sint32_least;
typedef /*@unsigned-integral-type@*/ unsigned __int32   uint32_least;

#if !defined(TRUE)
    #define TRUE    ((boolean)1)
#endif

#if !defined(FALSE)
    #define FALSE   ((boolean)0)
#endif

typedef float           float32;
typedef double          float64;
typedef void *          pvoid;
typedef unsigned int    SizeType;
typedef int             PtrDiffType;

#endif /* __PLATFORM_TYPES_I386_H  */
