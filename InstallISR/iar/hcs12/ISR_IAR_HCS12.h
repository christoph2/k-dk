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
#if !defined(__ISR_IAR_HCS12_H)
#define __ISR_IAR_HCS12_H

#define DECLARE_ISR2_VECTOR(IsrName) __interrupt void IsrName(void)
#define DECLARE_ISR1_VECTOR(IsrName) __interrupt void IsrName(void)
#define ISR1(IsrName) __interrupt void IsrName(void)

#define IISR_ENTRY_POINT __program_start
void __program_start(void);
extern void (* const  interrupt_vectors[])(void);

#define IISR_DECLARE_VECTOR_TABLE
#define IISR_BEGIN_VECTOR_TABLE
#define IISR_END_VECTOR_TABLE

#endif /* __ISR_IAR_HCS12_H */
