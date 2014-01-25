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
#if !defined(__ISR_GCC_HCS12_H)
#define __ISR_GCC_HCS12_H

#if 0
#define DECLARE_ISR(IsrName)            void IsrName(void) __attribute__((interrupt))
#endif

#define DECLARE_ISR2_VECTOR(IsrName)    void IsrName(void) __attribute__((interrupt))
#define DECLARE_ISR1_VECTOR(IsrName)    void IsrName(void) __attribute__((interrupt))
#define ISR1(IsrName)                   void IsrName(void) __attribute__((interrupt))

extern void(*const interrupt_vectors[]) (void);

void _start(void);


#define IISR_ENTRY_POINT    _start
#define IISR_INTERUPT       __attribute__((interrupt))

#define IISR_DECLARE_VECTOR_TABLE
#define IISR_BEGIN_VECTOR_TABLE
#define IISR_END_VECTOR_TABLE

#endif /* __ISR_GCC_HCS12_H */
