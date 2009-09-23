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
#if !defined(__CPRI_H)
#define __CPRI_H


/*
**  Powerdown(Wait)-Mode.
*/
#elif defined(__HIWARE__)
#define CPU_POWERDOWN_MODE()            __asm wai


/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        __asm swi


/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     __asm rti


/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                __asm bgnd


/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              __asm nop


/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    __asm sei


/*
**  Enable All Interrupts.
*/  
#define CPU_ENABLE_ALL_INTERRUPTS()     \
    _BEGIN_BLOCK                        \
        __asm cli;                      \
        __asm nop;                      \
    _END_BLOCK


/*
**  Check for Interrupts disabled.
*/
boolean Cpu_InterruptsDisabled(void);

#endif /* __CPRI_H */

