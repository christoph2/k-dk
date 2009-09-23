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
#include "Mem.h"


static SizeType brk=(SizeType)NULL;


void *Mem_SBrk(SizeType size)
{
    SizeType brk_old;

    if (brk==(SizeType)NULL) {
        /* First call. */
        brk=(SizeType)Mem_GetFreePointer();
    }
        
    if ((brk+size)<Mem_GetStackBOS()) {
        brk_old=brk;
        brk=brk+size;
        return (void*)brk_old;
    } else {
        /* no memory left. */
        return (void*)NULL;   
    }
}


SizeType Mem_TotalMemory(void)
{
    SizeType total;
    total=Mem_GetStackBOS()-(SizeType)Mem_GetFreePointer();
    
    return total;
}


SizeType Mem_MemoryLeft(void)
{
    SizeType start,left;
    
    if (brk==(SizeType)NULL) {
        start=(SizeType)Mem_GetFreePointer();
    } else {
        start=brk;
    }
    
    left=Mem_GetStackBOS()-start;
    
    return left;
}
