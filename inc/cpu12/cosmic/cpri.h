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
#define CPU_POWERDOWN_MODE()            _asm("wai")


/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        _asm("swi")


/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     _asm("rti")


/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                _asm("bgnd")


/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              _asm("nop")


/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    _asm("sei")


/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        _asm("cli");                        \
        _asm("nop");                        \
    _END_BLOCK


/*
**
**  COSMIC-Makros
**  --------------
**  #define SWI _asm("swi")
**  #define GET_CCR (unsigned char)(_asm("tfr ccr, b") )
**  #define PUT_CCR(X) (_asm("tfr b,ccr", ((unsigned char)X )) )
*/

/*
**  Check for Interrupts disabled.
*/
#define Cpu_InterruptsDisabled()  (((uint8)_asm("tfr ccr,b\n") & ((uint8)0x10))==((uint8)0x10))

#endif /* __CPRI_H */

