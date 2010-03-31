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
#if !defined(__S12_PIM_H)
#define __S12_PIM_H

#include "S12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/

/*  PortT */
#define PTT             ((uint8)0x00)
    /*  PTT-Bits. */
    #define PTT7        ((uint8)0x80)
    #define PTT6        ((uint8)0x40)
    #define PTT5        ((uint8)0x20)
    #define PTT4        ((uint8)0x10)
    #define PTT3        ((uint8)0x08)
    #define PTT2        ((uint8)0x04)
    #define PTT1        ((uint8)0x02)
    #define PTT0        ((uint8)0x01)

#define PTIT            ((uint8)0x01)
    /*  PTIT-Bits.  */
    #define PTIT7       ((uint8)0x80)
    #define PTIT6       ((uint8)0x40)
    #define PTIT5       ((uint8)0x20)
    #define PTIT4       ((uint8)0x10)
    #define PTIT3       ((uint8)0x08)
    #define PTIT2       ((uint8)0x04)
    #define PTIT1       ((uint8)0x02)
    #define PTIT0       ((uint8)0x01)

#define DDRT            ((uint8)0x02)
    /*  DDRT-Bits.  */
    #define DDRT7       ((uint8)0x80)
    #define DDRT6       ((uint8)0x40)
    #define DDRT5       ((uint8)0x20)
    #define DDRT4       ((uint8)0x10)
    #define DDRT3       ((uint8)0x08)
    #define DDRT2       ((uint8)0x04)
    #define DDRT1       ((uint8)0x02)
    #define DDRT0       ((uint8)0x01)

#define RDRT            ((uint8)0x03)
    /*  RDRT-Bits.  */
    #define RDRT7       ((uint8)0x80)
    #define RDRT6       ((uint8)0x40)
    #define RDRT5       ((uint8)0x20)
    #define RDRT4       ((uint8)0x10)
    #define RDRT3       ((uint8)0x08)
    #define RDRT2       ((uint8)0x04)
    #define RDRT1       ((uint8)0x02)
    #define RDRT0       ((uint8)0x01)

#define PERT            ((uint8)0x04)
    /*  PERT-Bits.  */
    #define PERT7       ((uint8)0x80)
    #define PERT6       ((uint8)0x40)
    #define PERT5       ((uint8)0x20)
    #define PERT4       ((uint8)0x10)
    #define PERT3       ((uint8)0x08)
    #define PERT2       ((uint8)0x04)
    #define PERT1       ((uint8)0x02)
    #define PERT0       ((uint8)0x01)

#define PPST            ((uint8)0x05)
    /*  PPST-Bits.  */
    #define PPST7       ((uint8)0x80)
    #define PPST6       ((uint8)0x40)
    #define PPST5       ((uint8)0x20)
    #define PPST4       ((uint8)0x10)
    #define PPST3       ((uint8)0x08)
    #define PPST2       ((uint8)0x04)
    #define PPST1       ((uint8)0x02)
    #define PPST0       ((uint8)0x01)
/*
**  0x06-0x07 Reserved.
*/

/*  PortS */
#define PTS             ((uint8)0x08)
    /*  PTS-Bits. */
    #define PTS7        ((uint8)0x80)
    #define PTS6        ((uint8)0x40)
    #define PTS5        ((uint8)0x20)
    #define PTS4        ((uint8)0x10)
    #define PTS3        ((uint8)0x08)
    #define PTS2        ((uint8)0x04)
    #define PTS1        ((uint8)0x02)
    #define PTS0        ((uint8)0x01)

#define PTIS            ((uint8)0x09)
    /*  PTIS-Bits.  */
    #define PTIS7       ((uint8)0x80)
    #define PTIS6       ((uint8)0x40)
    #define PTIS5       ((uint8)0x20)
    #define PTIS4       ((uint8)0x10)
    #define PTIS3       ((uint8)0x08)
    #define PTIS2       ((uint8)0x04)
    #define PTIS1       ((uint8)0x02)
    #define PTIS0       ((uint8)0x01)

#define DDRS            ((uint8)0x0A)
    /*  DDRS-Bits.  */
    #define DDRS7       ((uint8)0x80)
    #define DDRS6       ((uint8)0x40)
    #define DDRS5       ((uint8)0x20)
    #define DDRS4       ((uint8)0x10)
    #define DDRS3       ((uint8)0x08)
    #define DDRS2       ((uint8)0x04)
    #define DDRS1       ((uint8)0x02)
    #define DDRS0       ((uint8)0x01)

#define RDRS            ((uint8)0x0B)
    /*  RDRS-Bits.  */
    #define RDRS7       ((uint8)0x80)
    #define RDRS6       ((uint8)0x40)
    #define RDRS5       ((uint8)0x20)
    #define RDRS4       ((uint8)0x10)
    #define RDRS3       ((uint8)0x08)
    #define RDRS2       ((uint8)0x04)
    #define RDRS1       ((uint8)0x02)
    #define RDRS0       ((uint8)0x01)

#define PERS            ((uint8)0x0C)
    /*   PERS-Bits. */
    #define PERS7       ((uint8)0x80)
    #define PERS6       ((uint8)0x40)
    #define PERS5       ((uint8)0x20)
    #define PERS4       ((uint8)0x10)
    #define PERS3       ((uint8)0x08)
    #define PERS2       ((uint8)0x04)
    #define PERS1       ((uint8)0x02)
    #define PERS0       ((uint8)0x01)

#define PPSS            ((uint8)0x0D)
    /*  PPSS-Bits.  */
    #define PPSS7       ((uint8)0x80)
    #define PPSS6       ((uint8)0x40)
    #define PPSS5       ((uint8)0x20)
    #define PPSS4       ((uint8)0x10)
    #define PPSS3       ((uint8)0x08)
    #define PPSS2       ((uint8)0x04)
    #define PPSS1       ((uint8)0x02)
    #define PPSS0       ((uint8)0x01)

#define WOMS            ((uint8)0x0E)
    /*  WOMS-Bits. */
    #define WOMS7       ((uint8)0x80)
    #define WOMS6       ((uint8)0x40)
    #define WOMS5       ((uint8)0x20)
    #define WOMS4       ((uint8)0x10)
    #define WOMS3       ((uint8)0x08)
    #define WOMS2       ((uint8)0x04)
    #define WOMS1       ((uint8)0x02)
    #define WOMS0       ((uint8)0x01)
/*
**  0x0F Reserved.
*/

/* PortM */
    #define PTM         ((uint8)0x10)
    /*  PTM-Bits. */
    #define PTM7        ((uint8)0x80)
    #define PTM6        ((uint8)0x40)
    #define PTM5        ((uint8)0x20)
    #define PTM4        ((uint8)0x10)
    #define PTM3        ((uint8)0x08)
    #define PTM2        ((uint8)0x04)
    #define PTM1        ((uint8)0x02)
    #define PTM0        ((uint8)0x01)

#define PTIM            ((uint8)0x11)
    /*  PTIM-Bits.  */
    #define PTIM7       ((uint8)0x80)
    #define PTIM6       ((uint8)0x40)
    #define PTIM5       ((uint8)0x20)
    #define PTIM4 	((uint8)0x10)
    #define PTIM3 	((uint8)0x08)
    #define PTIM2 	((uint8)0x04)
    #define PTIM1 	((uint8)0x02)
    #define PTIM0	((uint8)0x01)

#define DDRM            ((uint8)0x12)
    /*  DDRM-Bits.  */
    #define DDRM7       ((uint8)0x80)
    #define DDRM6       ((uint8)0x40)
    #define DDRM5       ((uint8)0x20)
    #define DDRM4       ((uint8)0x10)
    #define DDRM3       ((uint8)0x08)
    #define DDRM2       ((uint8)0x04)
    #define DDRM1       ((uint8)0x02)
    #define DDRM0       ((uint8)0x01)

#define RDRM            ((uint8)0x13)
    /*  RDRM-Bits.  */
    #define RDRM7       ((uint8)0x80)
    #define RDRM6       ((uint8)0x40)
    #define RDRM5       ((uint8)0x20)
    #define RDRM4       ((uint8)0x10)
    #define RDRM3       ((uint8)0x08)
    #define RDRM2       ((uint8)0x04)
    #define RDRM1       ((uint8)0x02)
    #define RDRM0       ((uint8)0x01)

#define PERM            ((uint8)0x14)
    /*  PERM-Bits.  */
    #define PERM7       ((uint8)0x80)
    #define PERM6       ((uint8)0x40)
    #define PERM5       ((uint8)0x20)
    #define PERM4       ((uint8)0x10)
    #define PERM3       ((uint8)0x08)
    #define PERM2       ((uint8)0x04)
    #define PERM1       ((uint8)0x02)
    #define PERM0       ((uint8)0x01)

#define PPSM            ((uint8)0x15)
    /*  PPSM-Bits.  */
    #define PPSM7       ((uint8)0x80)
    #define PPSM6       ((uint8)0x40)
    #define PPSM5       ((uint8)0x20)
    #define PPSM4       ((uint8)0x10)
    #define PPSM3       ((uint8)0x08)
    #define PPSM2       ((uint8)0x04)
    #define PPSM1       ((uint8)0x02)
    #define PPSM0       ((uint8)0x01)

#define WOMM            ((uint8)0x16)
    /*  WOMM-Bits.  */
    #define WOMM7       ((uint8)0x80)
    #define WOMM6       ((uint8)0x40)
    #define WOMM5       ((uint8)0x20)
    #define WOMM4       ((uint8)0x10)
    #define WOMM3       ((uint8)0x08)
    #define WOMM2       ((uint8)0x04)
    #define WOMM1       ((uint8)0x02)
    #define WOMM0       ((uint8)0x01)

#define MODRR           ((uint8)0x17)
    /* MODRR-Bits.  */
    /* !!! */


/*  PortP   */
#define PTP             ((uint8)0x18)
    /*  PTP-Bits. */
    #define PTP7        ((uint8)0x80)
    #define PTP6        ((uint8)0x40)
    #define PTP5        ((uint8)0x20)
    #define PTP4        ((uint8)0x10)
    #define PTP3        ((uint8)0x08)
    #define PTP2        ((uint8)0x04)
    #define PTP1        ((uint8)0x02)
    #define PTP0        ((uint8)0x01)

#define PTIP            ((uint8)0x19)
    /*  PTIP-Bits.  */
    #define PTIP7       ((uint8)0x80)
    #define PTIP6       ((uint8)0x40)
    #define PTIP5       ((uint8)0x20)
    #define PTIP4       ((uint8)0x10)
    #define PTIP3       ((uint8)0x08)
    #define PTIP2       ((uint8)0x04)
    #define PTIP1       ((uint8)0x02)
    #define PTIP0       ((uint8)0x01)

#define DDRP            ((uint8)0x1A)
    /*  DDRP-Bits.  */
    #define DDRP7       ((uint8)0x80)
    #define DDRP6       ((uint8)0x40)
    #define DDRP5       ((uint8)0x20)
    #define DDRP4       ((uint8)0x10)
    #define DDRP3       ((uint8)0x08)
    #define DDRP2       ((uint8)0x04)
    #define DDRP1       ((uint8)0x02)
    #define DDRP0       ((uint8)0x01)

#define RDRP            ((uint8)0x1B)
    /*  RDRP-Bits.  */
    #define RDRP7       ((uint8)0x80)
    #define RDRP6       ((uint8)0x40)
    #define RDRP5       ((uint8)0x20)
    #define RDRP4       ((uint8)0x10)
    #define RDRP3       ((uint8)0x08)
    #define RDRP2       ((uint8)0x04)
    #define RDRP1       ((uint8)0x02)
    #define RDRP0       ((uint8)0x01)

#define PERP            ((uint8)0x1C)
    /*  PERP-Bits.  */
    #define PERP7       ((uint8)0x80)
    #define PERP6       ((uint8)0x40)
    #define PERP5       ((uint8)0x20)
    #define PERP4       ((uint8)0x10)
    #define PERP3       ((uint8)0x08)
    #define PERP2       ((uint8)0x04)
    #define PERP1       ((uint8)0x02)
    #define PERP0       ((uint8)0x01)

#define PPSP            ((uint8)0x1D)
    /*  PPSP-Bits.  */
    #define PPSP7       ((uint8)0x80)
    #define PPSP6       ((uint8)0x40)
    #define PPSP5       ((uint8)0x20)
    #define PPSP4       ((uint8)0x10)
    #define PPSP3       ((uint8)0x08)
    #define PPSP2       ((uint8)0x04)
    #define PPSP1       ((uint8)0x02)
    #define PPSP0       ((uint8)0x01)

#define PIEP            ((uint8)0x1E)
    /*  PIEP-Bits.  */
    #define PIEP7       ((uint8)0x80)
    #define PIEP6       ((uint8)0x40)
    #define PIEP5       ((uint8)0x20)
    #define PIEP4       ((uint8)0x10)
    #define PIEP3       ((uint8)0x08)
    #define PIEP2       ((uint8)0x04)
    #define PIEP1       ((uint8)0x02)
    #define PIEP0       ((uint8)0x01)

#define PIFP            ((uint8)0x1F)
    /*  PIFP-Bits.  */
    #define PIFP7       ((uint8)0x80)
    #define PIFP6       ((uint8)0x40)
    #define PIFP5       ((uint8)0x20)
    #define PIFP4       ((uint8)0x10)
    #define PIFP3       ((uint8)0x08)
    #define PIFP2       ((uint8)0x04)
    #define PIFP1       ((uint8)0x02)
    #define PIFP0       ((uint8)0x01)

/*  PortH   */
#define PTH             ((uint8)0x20)
    /*  PTH-Bits. */
    #define PTH7        ((uint8)0x80)
    #define PTH6        ((uint8)0x40)
    #define PTH5        ((uint8)0x20)
    #define PTH4        ((uint8)0x10)
    #define PTH3        ((uint8)0x08)
    #define PTH2        ((uint8)0x04)
    #define PTH1        ((uint8)0x02)
    #define PTH0        ((uint8)0x01)

#define PTIH            ((uint8)0x21)
    /*  PTIH-Bits.  */
    #define PTIH7       ((uint8)0x80)
    #define PTIH6       ((uint8)0x40)
    #define PTIH5       ((uint8)0x20)
    #define PTIH4       ((uint8)0x10)
    #define PTIH3       ((uint8)0x08)
    #define PTIH2       ((uint8)0x04)
    #define PTIH1       ((uint8)0x02)
    #define PTIH0       ((uint8)0x01)

#define DDRH            ((uint8)0x22)
    /*  DDRH-Bits.  */
    #define DDRH7       ((uint8)0x80)
    #define DDRH6       ((uint8)0x40)
    #define DDRH5       ((uint8)0x20)
    #define DDRH4       ((uint8)0x10)
    #define DDRH3       ((uint8)0x08)
    #define DDRH2       ((uint8)0x04)
    #define DDRH1       ((uint8)0x02)
    #define DDRH0       ((uint8)0x01)

#define RDRH            ((uint8)0x23)
    /*  RDRH-Bits.  */
    #define RDRH7       ((uint8)0x80)
    #define RDRH6       ((uint8)0x40)
    #define RDRH5       ((uint8)0x20)
    #define RDRH4       ((uint8)0x10)
    #define RDRH3       ((uint8)0x08)
    #define RDRH2       ((uint8)0x04)
    #define RDRH1       ((uint8)0x02)
    #define RDRH0       ((uint8)0x01)

#define PERH            ((uint8)0x24)
    /*  PERH-Bits.  */
    #define PERH7       ((uint8)0x80)
    #define PERH6       ((uint8)0x40)
    #define PERH5       ((uint8)0x20)
    #define PERH4       ((uint8)0x10)
    #define PERH3       ((uint8)0x08)
    #define PERH2       ((uint8)0x04)
    #define PERH1       ((uint8)0x02)
    #define PERH0       ((uint8)0x01)

#define PPSH            ((uint8)0x25)
    /*  PPSH-Bits.  */
    #define PPSH7       ((uint8)0x80)
    #define PPSH6       ((uint8)0x40)
    #define PPSH5       ((uint8)0x20)
    #define PPSH4       ((uint8)0x10)
    #define PPSH3       ((uint8)0x08)
    #define PPSH2       ((uint8)0x04)
    #define PPSH1       ((uint8)0x02)
    #define PPSH0       ((uint8)0x01)

#define PIEH            ((uint8)0x26)
    /*  PIEH-Bits.  */
    #define PIEH7       ((uint8)0x80)
    #define PIEH6       ((uint8)0x40)
    #define PIEH5       ((uint8)0x20)
    #define PIEH4       ((uint8)0x10)
    #define PIEH3       ((uint8)0x08)
    #define PIEH2       ((uint8)0x04)
    #define PIEH1       ((uint8)0x02)
    #define PIEH0       ((uint8)0x01)

#define PIFH            ((uint8)0x27)
    /*  PIFH-Bits.  */
    #define PIFH7       ((uint8)0x80)
    #define PIFH6       ((uint8)0x40)
    #define PIFH5       ((uint8)0x20)
    #define PIFH4       ((uint8)0x10)
    #define PIFH3       ((uint8)0x08)
    #define PIFH2       ((uint8)0x04)
    #define PIFH1       ((uint8)0x02)
    #define PIFH0       ((uint8)0x01)


/*  PortJ   */
#define PTJ             ((uint8)0x28)
    /*  PTJ-Bits. */
    #define PTJ7        ((uint8)0x80)
    #define PTJ6        ((uint8)0x40)
    #define PTJ1        ((uint8)0x02)
    #define PTJ0        ((uint8)0x01)

#define PTIJ            ((uint8)0x29)
    /*  PTIJ-Bits.  */
    #define PTIJ7       ((uint8)0x80)
    #define PTIJ6       ((uint8)0x40)
    #define PTIJ1       ((uint8)0x02)
    #define PTIJ0       ((uint8)0x01)

#define DDRJ            ((uint8)0x2A)
    /*  DDRJ-Bits.  */
    #define DDRJ7       ((uint8)0x80)
    #define DDRJ6       ((uint8)0x40)
    #define DDRJ1       ((uint8)0x02)
    #define DDRJ0       ((uint8)0x01)

#define RDRJ            ((uint8)0x2B)
    /*  RDRJ-Bits.  */
    #define RDRJ7       ((uint8)0x80)
    #define RDRJ6       ((uint8)0x40)
    #define RDRJ1       ((uint8)0x02)
    #define RDRJ0       ((uint8)0x01)

#define PERJ            ((uint8)0x2C)
    /*  PERJ-Bits.  */
    #define PERJ7       ((uint8)0x80)
    #define PERJ6       ((uint8)0x40)
    #define PERJ1       ((uint8)0x02)
    #define PERJ0       ((uint8)0x01)

#define PPSJ            ((uint8)0x2D)
    /*  PPSJ-Bits.  */
    #define PPSJ7       ((uint8)0x80)
    #define PPSJ6       ((uint8)0x40)
    #define PPSJ1       ((uint8)0x02)
    #define PPSJ0       ((uint8)0x01)

#define PIEJ            ((uint8)0x2E)
    /*  PIEJ-Bits.  */
    #define PIEJ7       ((uint8)0x80)
    #define PIEJ6       ((uint8)0x40)
    #define PIEJ1       ((uint8)0x02)
    #define PIEJ0       ((uint8)0x01)

#define PIFJ            ((uint8)0x2F)
    /*  PIFJ-Bits.  */
    #define PIFJ7       ((uint8)0x80)
    #define PIFJ6       ((uint8)0x40)
    #define PIFJ1       ((uint8)0x02)
    #define PIFJ0       ((uint8)0x01)
/*
**  0x30-0x3f - Reserved.
*/


/*
**  Defines for AUTOSAR.
*/
#define DIO_CHANNEL_T_0     BIT(0)
#define DIO_CHANNEL_T_1     BIT(1)
#define DIO_CHANNEL_T_2     BIT(2)
#define DIO_CHANNEL_T_3     BIT(3)
#define DIO_CHANNEL_T_4     BIT(4)
#define DIO_CHANNEL_T_5     BIT(5)
#define DIO_CHANNEL_T_6     BIT(6)
#define DIO_CHANNEL_T_7     BIT(7)

#define DIO_CHANNEL_S_0     BIT(0)
#define DIO_CHANNEL_S_1     BIT(1)
#define DIO_CHANNEL_S_2     BIT(2)
#define DIO_CHANNEL_S_3     BIT(3)
#define DIO_CHANNEL_S_4     BIT(4)
#define DIO_CHANNEL_S_5     BIT(5)
#define DIO_CHANNEL_S_6     BIT(6)
#define DIO_CHANNEL_S_7     BIT(7)

#define DIO_CHANNEL_M_0     BIT(0)
#define DIO_CHANNEL_M_1     BIT(1)
#define DIO_CHANNEL_M_2     BIT(2)
#define DIO_CHANNEL_M_3     BIT(3)
#define DIO_CHANNEL_M_4     BIT(4)
#define DIO_CHANNEL_M_5     BIT(5)
#define DIO_CHANNEL_M_6     BIT(6)
#define DIO_CHANNEL_M_7     BIT(7)

#define DIO_CHANNEL_P_0     BIT(0)
#define DIO_CHANNEL_P_1     BIT(1)
#define DIO_CHANNEL_P_2     BIT(2)
#define DIO_CHANNEL_P_3     BIT(3)
#define DIO_CHANNEL_P_4     BIT(4)
#define DIO_CHANNEL_P_5     BIT(5)
#define DIO_CHANNEL_P_6     BIT(6)
#define DIO_CHANNEL_P_7     BIT(7)

#define DIO_CHANNEL_H_0     BIT(0)
#define DIO_CHANNEL_H_1     BIT(1)
#define DIO_CHANNEL_H_2     BIT(2)
#define DIO_CHANNEL_H_3     BIT(3)
#define DIO_CHANNEL_H_4     BIT(4)
#define DIO_CHANNEL_H_5     BIT(5)
#define DIO_CHANNEL_H_6     BIT(6)
#define DIO_CHANNEL_H_7     BIT(7)

#define DIO_CHANNEL_J_0     BIT(0)
#define DIO_CHANNEL_J_1     BIT(1)
#define DIO_CHANNEL_J_2     BIT(2)
#define DIO_CHANNEL_J_3     BIT(3)
#define DIO_CHANNEL_J_4     BIT(4)
#define DIO_CHANNEL_J_5     BIT(5)
#define DIO_CHANNEL_J_6     BIT(6)
#define DIO_CHANNEL_J_7     BIT(7)

#define DIO_PORT_T          ((uint8)0x00)
#define DIO_PORT_S          ((uint8)0x01)
#define DIO_PORT_M          ((uint8)0x02)
#define DIO_PORT_P          ((uint8)0x03)
#define DIO_PORT_H          ((uint8)0x04)
#define DIO_PORT_J          ((uint8)0x05)


/*
**  Global Types.
*/
typedef enum tagS12Pim_StatusType {
    S12PIM_OK
} S12Pim_StatusType;

typedef struct tagS12Pim_ConfigType {
    const uint16 BaseAddr;
    uint8 Modrr;

    /* PortT */
    uint8 DdrT;
    uint8 PtT;
    uint8 RdrT;
    uint8 PerT;
    uint8 PpsT;

    /* PortS */
    uint8 DdrS;
    uint8 PtS;
    uint8 RdrS;
    uint8 PerS;
    uint8 PpsS;
    uint8 WomsS;

    /* PortM */
    uint8 DdrM;
    uint8 PtM;
    uint8 RdrM;
    uint8 PerM;
    uint8 PpsM;
    uint8 WomM;

    /* PortP */
    uint8 DdrP;
    uint8 PtP;
    uint8 RdrP;
    uint8 PerP;
    uint8 PpsP;
    uint8 PieP;

    /* PortH */
    uint8 DdrH;
    uint8 PtH;
    uint8 RdrH;
    uint8 PerH;
    uint8 PpsH;
    uint8 PieH;

    /* PortJ */
    uint8 DdrJ;
    uint8 PtJ;
    uint8 RdrJ;
    uint8 PerJ;
    uint8 PpsJ;
    uint8 PieJ;

} S12Pim_ConfigType;


/*
**  Global Functions.
*/
S12Pim_StatusType S12Pim_Init(void);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __S12_MMC_H*/
