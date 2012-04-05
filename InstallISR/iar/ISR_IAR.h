/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined(__ISR_IAR_H)
#define __ISR_IAR_H

#if defined(__ICCARM__)
    #define II_INC_TARGET_H "arm/ISR_IAR_ARM.h"
#elif defined(__ICCHCS12__)
    #define II_INC_TARGET_H "s12/ISR_IAR_HCS12.h"
#else
    #error Unsupported Target for IAR-ICC.
#endif

#include II_INC_TARGET_H

#endif /* __ISR_IAR_H */
