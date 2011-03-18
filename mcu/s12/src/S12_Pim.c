/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
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
#include "S12_Pim.h"
#include "Hw_Cfg.h"

/*
**
**  REFERENCES:
**  ===========
**  MC9S12DP256 Port Intergration Module (PIM) Block User Guide V02.07.
**
*/

/*
    • Port A, B, E, and K related to the core logic and multiplexed bus interface
    • Port T connected to the timer module
    • The serial port S associated with 2 SCI and 1 SPI modules
    • Port M associated with 4 CAN and 1 BDLC module
    • Port P connected to the PWM and 2 SPI modules, which also can be used as an external interrupt source
    • The standard I/O ports H and J associated with the fifth CAN module and the IIC interface. These ports
      can also be used as external interrupt sources.
*/

// Added shortcircuit-/collision detection for PIM.

#define S12PIM_ASSERT_VALID_PORT(port)  \
    _BEGIN_BLOCK                        \
        if (port>PIO_PORT_MAX) {        \
/*            ErrorHandler(...); */     \
            return FALSE;               \
        }                               \
    _END_BLOCK


void S12Pim_Init(void)
{
    S12PIM_REG8(MODRR)=PIM.Modrr;

    /* PortT */
    S12PIM_REG8(RDRT)=PIM.RdrT;
    S12PIM_REG8(PERT)=PIM.PerT;
    S12PIM_REG8(PPST)=PIM.PpsT;
    S12PIM_REG8(PTT)=PIM.PtT;
    S12PIM_REG8(DDRT)=PIM.DdrT;

    /* PortS */
    S12PIM_REG8(RDRS)=PIM.RdrS;
    S12PIM_REG8(PERS)=PIM.PerS;
    S12PIM_REG8(PPSS)=PIM.PpsS;
    S12PIM_REG8(WOMS)=PIM.WomsS;
    S12PIM_REG8(PTS)=PIM.PtS;
    S12PIM_REG8(DDRS)=PIM.DdrS;

    /* PortM */
    S12PIM_REG8(RDRM)=PIM.RdrM;
    S12PIM_REG8(PERM)=PIM.PerM;
    S12PIM_REG8(PPSM)=PIM.PpsM;
    S12PIM_REG8(WOMM)=PIM.WomM;
    S12PIM_REG8(PTM)=PIM.PtM;
    S12PIM_REG8(DDRM)=PIM.DdrM;

    /* PortP */
    S12PIM_REG8(RDRP)=PIM.RdrP;
    S12PIM_REG8(PERP)=PIM.PerP;
    S12PIM_REG8(PPSP)=PIM.PpsP;
    S12PIM_REG8(PIEP)=PIM.PieP;
    S12PIM_REG8(PTP)=PIM.PtP;
    S12PIM_REG8(DDRP)=PIM.DdrP;

    /* PortH */
    S12PIM_REG8(RDRH)=PIM.RdrH;
    S12PIM_REG8(PERH)=PIM.PerH;
    S12PIM_REG8(PPSH)=PIM.PpsH;
    S12PIM_REG8(PIEH)=PIM.PieH;
    S12PIM_REG8(PTH)=PIM.PtH;
    S12PIM_REG8(DDRH)=PIM.DdrH;

    /* PortJ */
    S12PIM_REG8(RDRJ)=PIM.RdrJ;
    S12PIM_REG8(PERJ)=PIM.PerJ;
    S12PIM_REG8(PPSJ)=PIM.PpsJ;
    S12PIM_REG8(PIEJ)=PIM.PieJ;
    S12PIM_REG8(PTJ)=PIM.PtJ;
    S12PIM_REG8(DDRJ)=PIM.DdrJ;
}


boolean S12Pim_WritePort(S12Pim_PortType port,uint8 value)
{
    S12PIM_ASSERT_VALID_PORT(port);

    S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT)=value;
#if defined(S12PIM_OUTPUT_CHECKED)
    return S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PTI)==value;
#else
    return TRUE;
#endif /* S12PIM_OUTPUT_CHECKED */
}


S12Pim_PortType S12Pim_ReadPort(S12Pim_PortType port)
{
    S12PIM_ASSERT_VALID_PORT(port);

#if defined(S12PIM_READ_OUTPUT_LATCH)
    return S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT);   /* output-latch   */
#else
    return S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PTI)   /* input register */
#endif /* S12PIM_READ_OUTPUT_LATCH */
}

/*
**
**  USE-CASES for 'S12PIM_OUTPUT_CHECKED' and 'S12PIM_READ_OUTPUT_LATCH'.
**  =====================================================================
**
**  - 'S12PIM_OUTPUT_CHECKED': read back the value written from input-register,
**                             return 'FALSE' if not equal.
**  - 'S12PIM_READ_OUTPUT_LATCH': read port output-latch instead of input-register.
**
**
**  a) Short-/Open-Circuit detection:
**  ---------------------------------
**  Obviously, the written should equal to the value read back.
**  'S12Pim_WritePort' returns FALSE, if this is not the case.
**  (requires 'S12PIM_OUTPUT_CHECKED'-Option).
**
**  b) Bit-banged implementation of a Bus-Protocol in a wired-AND, open-drain fashion:
**  ----------------------------------------------------------------------------------
**
**  w  | rb | description
**  ---------------------
**  0  | 0  | OK
**  1  | 1  | OK
**  0  | 1  | short circuit to VCC
**  1  | 0  | collision - passive H-level overridden by an active L-level
**
**  (requires 'S12PIM_OUTPUT_CHECKED'- and 'S12PIM_READ_OUTPUT_LATCH'-Options,
**   furthermore either 'real' (appropriate bit in Wired-Or mode register set)
**   or 'pseudo' (diode-circuit) opendrain outputs).
**
*/
