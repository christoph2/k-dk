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
#if !defined(__MEM_H)
#define __MEM_H

#include "Std_Types.h"
#include "CPU_Primitives.h"

typedef enum tagMem_StackStatus {
    MEM_STACK_OK,
    MEM_STACK_OVERFLOW,
    MEM_STACK_UNDERFLOW
} Mem_StackStatus;

void *      Mem_SBrk(SizeType size);
SizeType    Mem_TotalMemory(void);
SizeType    Mem_MemoryLeft(void);

SizeType        Mem_GetStackTOS(void);
SizeType        Mem_GetStackBOS(void);
Mem_StackStatus Mem_StackCheck(void);


#if defined(__CSMC__)
#define Mem_GetFreePointer() (void *)_asm("xref __memory\nldd #__memory")
#else
void * Mem_GetFreePointer(void);


#endif

/*
** Get Stack-Pointer
*/
#if defined(__IMAGECRAFT__)
#define Mem_GetStackPointer()   asm ("tfr sp,d")
#elif defined(__CSMC__)
#define Mem_GetStackPointer()   ((SizeType)(_asm("tfr sp,d")))
#elif defined(__GNUC__)
#define Mem_GetStackPointer()   __asm__("tfr sp,d")
#else
SizeType Mem_GetStackPointer(void);


#endif

#endif /* __MEM_H */
