/*
   k_os (Konnex Operating-System based on the OSEK/VDX-Standard).

   (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
/*
**
**  CPU-Primitives.
**
*/

#if !defined(__CPU_PRIMITIVES_MCU_H)
#define __CPU_PRIMITIVES_MCU_H

#include <intrinsics.h>

/*
**  Powerdown(Wait)-Mode.
*/
#define CPU_ENTER_POWERDOWN_MODE()      __wait_for_interrupt()

/* __stop_CPU() */

/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        __software_interrupt()

/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     asm ("rti")

/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                asm ("bgnd")

/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              __no_operation()

/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    __disable_interrupt()

/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS() \
    _BEGIN_BLOCK                    \
    __enable_interrupt();           \
    __no_operation();               \
    _END_BLOCK

/*
**  Check for Interrupts disabled.
*/
#define CPU_INTERRUPTS_DISABLED() (((boolean)__get_ccr_register() & ((uint8)0x10)) == ((uint8)0x10))

/*
**  Save Interrupt-State before Disabling.
*/
#define CPU_SAVE_AND_DISABLE_INTERRUPTS(state)           \
    _BEGIN_BLOCK                                         \
    state = (InterruptStateType)__get_interrupt_state(); \
    CPU_DISABLE_ALL_INTERRUPTS();                        \
    _END_BLOCK

/*
**  Restore Interrupt-State.
*/
#define CPU_RESTORE_INTERRUPTS(state)         \
    _BEGIN_BLOCK                              \
    __set_interrupt_state((__istate_t)state); \
    __no_operation();                         \
    _END_BLOCK

/*
**  Platform specific Macros.
*/
#define CPU12_ENABLE_STOP_MODE()    asm ("andcc #$7f")

#define CPU12_DISABLE_STOP_MODE()   asm ("orcc  #$80")

#define CPU12_ENTER_STOP_MODE()     asm ("stop")

#define CPU12_ENABLE_XIRQ()         asm ("andcc #$bf")

#endif /* __CPU_PRIMITIVES_MCU_H */

