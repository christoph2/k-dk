/*
   k_os (Konnex Operating-System based on the OSEK/VDX-Standard).

   (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
                                        cpu12.gems@googlemail.com>

   All Rights Reserved

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   s. FLOSS-EXCEPTION.txt
 */
#if !defined(__CPU_PRIMITIVES_MCU_H)
#define __CPU_PRIMITIVES_MCU_H

/*
**
**  CPU-Primitives.
**
*/

/*
**  Powerdown(Wait)-Mode.
*/
#define CPU_POWERDOWN_MODE()            SLEEP()

/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        _asm("swi")

/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     # asm RETFIE # endasm

/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                _asm("bgnd")

/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              # asm NOP # endasm

/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    disable_interrupts(GLOBAL)

/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS()     enable_interrupts(GLOBAL)

/*
**  Check for Interrupts disabled.
*/
#define CPU_INTERRUPTS_DISABLED()       (((uint8)_asm("tfr ccr,b\n") & ((uint8)0x10)) == ((uint8)0x10))

/*
**  Save Interrupt-State before Disabling.
*/
#define CPU_SAVE_AND_DISABLE_INTERRUPTS(state) \
    _BEGIN_BLOCK                               \
    state = CPU_INTERRUPTS_DISABLED();         \
    CPU_DISABLE_ALL_INTERRUPTS();              \
    _END_BLOCK

/* interrupt_active(GLOBAL); */

/*
**  Restore Interrupt-State.
*/
#define CPU_RESTORE_INTERRUPTS(state) \
    _BEGIN_BLOCK                      \
    if ((state) == TRUE) {            \
        CPU_ENABLE_ALL_INTERRUPTS();  \
    } else {                          \
        CPU_DISABLE_ALL_INTERRUPTS(); \
    }                                 \
    _END_BLOCK

#endif /* __CPU_PRIMITIVES_MCU_H */

