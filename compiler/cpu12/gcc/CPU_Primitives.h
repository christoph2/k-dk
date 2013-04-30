/*
   k_os (Konnex Operating-System based on the OSEK/VDX-Standard).

   (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
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
**  Enter Powerdown-Mode.
*/
#define CPU_ENTER_POWERDOWN_MODE()      __asm__("wai")


/*
**  Leave Powerdown-Mode.
*/
#define CPU_LEAVE_POWERDOWN_MODE()


/*
**  Disable Watchdog Timer.
*/
#define CPU_DISABLE_WATCHDOG_TIMER()


/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        __asm__("swi")

/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     __asm__("rti")

/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                __asm__("bgnd")

/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              __asm__("nop")

/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    __asm__("sei")

/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS() \
    _BEGIN_BLOCK                    \
    __asm__("cli");                 \
    __asm__("nop");                 \
    _END_BLOCK

/*
**  Check for Interrupts disabled.
*/
boolean CPU_INTERRUPTS_DISABLED(void);


/*
**  Save Interrupt-State before Disabling.
*/
#define CPU_SAVE_AND_DISABLE_INTERRUPTS(state) \
    _BEGIN_BLOCK                               \
    state = CPU_INTERRUPTS_DISABLED();         \
    CPU_DISABLE_ALL_INTERRUPTS();              \
    _END_BLOCK

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

/*
**  Platform specific Macros.
*/
#define CPU12_ENABLE_STOP_MODE()    __asm__("andcc #$7f")

#define CPU12_DISABLE_STOP_MODE()   __asm__("orcc  #$80")

#define CPU12_ENTER_STOP_MODE()     __asm__("stop")

#define CPU12_ENABLE_XIRQ()         __asm__("andcc #$bf")

#endif /* __CPU_PRIMITIVES_MCU_H */

