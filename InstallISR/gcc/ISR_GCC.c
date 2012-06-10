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
#if defined(__arm__)
    #define II_INC_TARGET_C "./arm/ISR_GCC_ARM.c"
#elif defined(__AVR__)
    #define II_INC_TARGET_C "./avr/ISR_GCC_AVR.c"
#elif defined(MC6812)

    #if CPU_FAMILY == CPU12_HC12

        #if CPU_DERIVATE == CPU12_HC12B32 || CPU_DERIVATE == CPU12_HC12BC32
            #define II_INC_TARGET_C "./hc12/ISR_GCC_HC12B.c"
        #elif CPU_DERIVATE == CPU12_HC12DG128A || CPU_DERIVATE == CPU12_HC12DT128A
            #define II_INC_TARGET_C "./hc12/ISR_GCC_HC12Dx128.c"
        #elif CPU_DERIVATE == CPU12_HC12A4
            #define II_INC_TARGET_C "./hc12/ISR_GCC_HC12A4.c"
	#elif CPU_DERIVATE == CPU12_HC12D60 || CPU_DERIVATE == CPU12_HC12D60A
	    #define II_INC_TARGET_C "./hc12/ISR_GCC_HC12D60.c"
        #endif

    #elif CPU_FAMILY == CPU12_S12
        #define II_INC_TARGET_C     "./s12/ISR_GCC_HCS12.c"
    #else

#elif defined(__MSP430__)
    #define II_INC_TARGET_C "./msp430/ISR_GCC_MSP430.c"
#elif defined(_X86_)
/* Dummy Target. */
#else
    #error Unsupported Target for GCC-Compiler.
#endif

#include II_INC_TARGET_C

