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
#include "Std_Types.h"

void bs_test(void);


typedef sint8 (*Utl_CompareFuncType)(const void * , const void * );

void * Utl_BinSearch(const void * key, const void *  base, uint16 num_elems, uint16 elem_size, Utl_CompareFuncType compare_func);


void *  Utl_BinSearch(const void * key, const void *  base, uint16 num_elems, uint16 elem_size, Utl_CompareFuncType compare_func)
{
    uint16  mid;
    sint16  left, right;
    uint8 * cmp_key;
    sint8   res;

    left   = (sint32)0;
    right  = (sint32)(num_elems - 1);

    do {
        mid        = (uint16)(left + right) >> 1;
        cmp_key    = (uint8 *)((uint8 *)base + (mid * elem_size));
        res        = compare_func(key, cmp_key);

        if (res == (sint16)0) {
            return cmp_key;
        } else if (res < (uint8)0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    } while (left <= right);

    return (void * )NULL;
}


uint32 table[] = {0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555, 0x66666666, 0x77777777, 0x88888888, 0x99999999};

sint8 UlongCompare(void * lhs, void *  rhs);


void bs_test(void)
{
    const uint32    key = 0x99199999;
    boolean         f;

    void * res = Utl_BinSearch((void * )&key, &table, SIZEOF_ARRAY(table), sizeof(uint32), UlongCompare);

    if (res == (void * )NULL) {
        f = FALSE;
    } else {
        f = TRUE;
    }
}


sint8 UlongCompare(void * lhs, void *  rhs)
{
    sint32 res = (((uint32) * (uint32 *)lhs) - ((uint32) * (uint32 *)rhs));

    if (res == (sint32)0) {
        return (sint8)0;
    } else if (res < (sint32)0) {
        return (sint8) - 1;
    } else {
        return (sint8)1;
    }
}


