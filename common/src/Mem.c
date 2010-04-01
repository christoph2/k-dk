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

/*
	COSMIC
	========
The default _sbreak function provided by the library is as follows:
//  SET SYSTEM BREAK

void *sbreak(int size)
{
extern char _memory;
static char *_brk = NULL	//  memory break
char *obrk, yellow[40];
if (!_brk) 	// initialize on first call
_brk = &_memory;
obrk = _brk; // old top
_brk += size; // new top
if (yellow <= _brk || _brk < &_memory)
{	//  check boundaries
_brk = obrk;	// restore old top
return (NULL); 	// return NULL pointer
}
return (obrk); // return new area start
}

The yellow array is used to calculate the stack pointer value to check the
heap limits. This array is declared as the last local variable, so its
address is almost equal to the stack pointer once the function has been
entered. It is declared to be 40 bytes wide to allow for some security
margin. If the new top is outside the authorized limits, the function
returns a NULL pointer, otherwise, it returns the start of the new allocated
area. Note that the top variable _brk is a static variable initialized
to zero (NULL pointer). It is set to the heap start on the first call. It is
also possible to initialize it directly within the declaration, but in this
case, we create an initialized variable in the data segment which needs
to be initialized by the startup. The current code avoids such a requirement
by initializing the variable to zero (in the bss segment), which is
simply done by the standard startup sequence.
*/

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
