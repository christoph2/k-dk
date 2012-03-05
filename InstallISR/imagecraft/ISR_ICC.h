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
 */
#if !defined(__ISR_ICC_H)
#define __ISR_ICC_H

void _start(void);


#define IISR_ENTRY_POINT    _start

#if defined(_AVR)
    #define II_INC_PATH_H   "./avr/ISR_ICC_AVR.h"
#elif defined(_HC12)
    #define II_INC_PATH_H   "imagecraft/s12/ISR_ICC_HCS12.h"
#elif defined(_MSP430)
    #define II_INC_PATH_H   "./msp430/ISR_ICC_MSP430.h"
#else
    #error Unspupported Target for Imagecraft ICC.
#endif

/* #include II_INC_TARGET_H */
#include II_INC_PATH_H

#endif /* __ISR_ICC_H */
