/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
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
#if !defined(__S12_INT_H)
#define __S12_INT_H

#include "S12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define	ITCR        ((uin8t)0x15)
    /*  ITCR-Bits.  */
    #define WRINT   ((uin8t)0x10)
    #define ADR3    ((uin8t)0x08)
    #define ADR2    ((uin8t)0x04)
    #define ADR1    ((uin8t)0x02)
    #define ADR0    ((uin8t)0x01)

#define ITEST       ((uin8t)0x16)
    /*  ITEST-Bits. */
    #define INTE    ((uin8t)0x80)
    #define INTC    ((uin8t)0x40)
    #define INTA    ((uin8t)0x20)
    #define INT8    ((uin8t)0x10)
    #define INT6    ((uin8t)0x08)
    #define INT4    ((uin8t)0x04)
    #define INT2    ((uin8t)0x02)
    #define INT0    ((uin8t)0x01)

#define HPRIO       ((uin8t)0x1F)
	/*  HPRIO-Bits. */
    #define PSEL7   ((uin8t)0x80)
    #define PSEL6   ((uin8t)0x40)
    #define PSEL5   ((uin8t)0x20)
    #define PSEL4   ((uin8t)0x10)
    #define PSEL3   ((uin8t)0x08)
    #define PSEL2   ((uin8t)0x04)
    #define PSEL1   ((uin8t)0x02)


typedef struct tagS12Int_ConfigType {
    uint16 BaseAddr;
} S12Int_ConfigType;

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __S12_INT_H */
