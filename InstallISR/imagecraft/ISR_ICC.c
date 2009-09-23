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
#if defined(_AVR)
    #define II_INC_TARGET_C   "./avr/ISR_ICC_AVR.c"
#elif defined(_HC12)
    #define II_INC_TARGET_C   "./hcs12/ISR_ICC_HCS12.c"
#elif defined(_MSP430)
    #define II_INC_TARGET_C   "./msp430/ISR_ICC_MSP430.c"
#else
    #error Unsupported Target for Imagecraft-Compiler.
#endif

#include II_INC_TARGET_C
