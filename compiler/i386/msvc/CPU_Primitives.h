/*
 *  k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * s. FLOSS-EXCEPTION.txt
 */
#if !defined(__CPU_PRIMITIVES_MCU_H)
#define __CPU_PRIMITIVES_MCU_H


boolean OsPort_InitializeCriticalSection(void);
void OsPort_DeleteCriticalSection(void);
void OsPort_EnterCriticalSection(void);
void OsPort_LeaveCriticalSection(void);
boolean OsPort_InCriticalSection(void);
void OsPort_EnterPowerdownMode(void);

/*
**
**  CPU-Primitives.
**
*/

/*
**  Enter Powerdown-Mode.
*/
#define CPU_ENTER_POWERDOWN_MODE()              OsPort_EnterPowerdownMode()

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
#define CPU_SOFTWARE_INTERRUPT()

/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()

/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                        __debugbreak()

/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()

/*
**  Disable All Interrupts.
*/

/* todo: Zustand speichern!!! */
#define CPU_DISABLE_ALL_INTERRUPTS()

/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS()

/*
**  Check for Interrupts disabled.
*/
#define CPU_INTERRUPTS_DISABLED()               OsPort_InCriticalSection()

/*
**  Save Interrupt-State before Disabling.
*/
#define CPU_SAVE_AND_DISABLE_INTERRUPTS(state)  OsPort_EnterCriticalSection()

/*
**  Restore Interrupt-State.
*/
#define CPU_RESTORE_INTERRUPTS(state)           OsPort_LeaveCriticalSection();

#endif /* __CPU_PRIMITIVES_MCU_H */

