/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
 *                                      cpu12.gems@googlemail.com>
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

#include "HC12_Pwm.h"


/*
**
**  Stepping Lights
**  ===============
**  Phased PWM (90 degree phase-shift).
**  check/correct Base-Address of PWM-Module!
**  Connect LEDs to PP0 to PP3 (opt: OSC/LA).
**
*/

/*
**  Exercises:
**  =========
**  - Change Duty-Cycles.
**  - try centered PWM.
*/

void Pwm_Phase(void);

/*
**
**  Generate four PWM-Outputs shifted by 90 degrees.
**
*/
void Pwm_Phase(void)
{
    WAIT_FOR(HC12Pwm_GetCounter8((uint8)0)==(uint8)50);
    HC12Pwm_ResetCounter((uint8)1);

    WAIT_FOR(HC12Pwm_GetCounter8((uint8)1)==(uint8)50);
    HC12Pwm_ResetCounter((uint8)2);

    WAIT_FOR(HC12Pwm_GetCounter8((uint8)2)==(uint8)50);
    HC12Pwm_ResetCounter((uint8)3);
}
