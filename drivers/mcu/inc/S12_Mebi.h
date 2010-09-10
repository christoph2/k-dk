/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the 
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
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
#if !defined(__S12_MEBI_H)
#define __S12_MEBI_H

#include "S12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define	PORTA       ((uint8)0x00)

#define	PORTB       ((uint8)0x01)

#define	DDRA        ((uint8)0x02)

#define	DDRB        ((uint8)0x03)

/*
0x04-0x07 Reserved
*/

#define	PORTE       ((uint8)0x08)

#define	DDRE        ((uint8)0x09)

#define	PEAR        ((uint8)0x0A)
    /*  PEAR-Bits.  */
    #define NOACCE  ((uint8)0x80)
    #define PIPOE   ((uint8)0x20)
    #define NECLK   ((uint8)0x10)
    #define LSTRE   ((uint8)0x08)
    #define RDWE    ((uint8)0x04)

#define	MODE        ((uint8)0x0B)
    /*  MODE-Bits.  */
    #define MODC    ((uint8)0x80)
    #define MODB    ((uint8)0x40)
    #define MODA    ((uint8)0x20)
    #define IVIS    ((uint8)0x08)
    #define EMK     ((uint8)0x02)
    #define EME     ((uint8)0x01)

#define	PUCR        ((uint8)0x0C)
    /*  PUCR-Bits.  */
    #define PUPKE   ((uint8)0x80)
    #define PUPEE   ((uint8)0x10)
    #define PUPBE   ((uint8)0x02)
    #define PUPAE   ((uint8)0x01)

#define	RDRIV       ((uint8)0x0D)
    /*  RDRIV-Bits. */
    #define RDPK    ((uint8)0x80)
    #define RDPE    ((uint8)0x10)
    #define RDPB    ((uint8)0x02)
    #define RDPA    ((uint8)0x01)

#define	EBICTL      ((uint8)0x0E)
    /*  EBICTL-Bits.  */
    #define ESTR    ((uint8)0x01)

/*
**  0x0f - Reserved.
*/

#define IRQCR       ((uint8)0x1E)
    /*  INTCR-Bits. */
    #define IRQE    ((uint8)0x80)
    #define IRQEN   ((uint8)0x40)

#define PORTK       ((uint8)0x32)

#define DDRK        ((uint8)0x33)

/*
**  Defines for AUTOSAR.
*/
#define DIO_CHANNEL_A_0             ((uint8)0x00)
#define DIO_CHANNEL_A_1             ((uint8)0x01)
#define DIO_CHANNEL_A_2             ((uint8)0x02)
#define DIO_CHANNEL_A_3             ((uint8)0x03)
#define DIO_CHANNEL_A_4             ((uint8)0x04)
#define DIO_CHANNEL_A_5             ((uint8)0x05)
#define DIO_CHANNEL_A_6             ((uint8)0x06)
#define DIO_CHANNEL_A_7             ((uint8)0x07)

#define DIO_CHANNEL_B_0             ((uint8)0x08)
#define DIO_CHANNEL_B_1             ((uint8)0x09)
#define DIO_CHANNEL_B_2             ((uint8)0x0a)
#define DIO_CHANNEL_B_3             ((uint8)0x0b)
#define DIO_CHANNEL_B_4             ((uint8)0x0c)
#define DIO_CHANNEL_B_5             ((uint8)0x0d)
#define DIO_CHANNEL_B_6             ((uint8)0x0e)
#define DIO_CHANNEL_B_7             ((uint8)0x0f)

#define DIO_CHANNEL_E_0             ((uint8)0x10)
#define DIO_CHANNEL_E_1             ((uint8)0x11)
#define DIO_CHANNEL_E_2             ((uint8)0x12)
#define DIO_CHANNEL_E_3             ((uint8)0x13)
#define DIO_CHANNEL_E_4             ((uint8)0x14)
#define DIO_CHANNEL_E_5             ((uint8)0x15)
#define DIO_CHANNEL_E_6             ((uint8)0x16)
#define DIO_CHANNEL_E_7             ((uint8)0x17)

#define DIO_CHANNEL_K_0             ((uint8)0x18)
#define DIO_CHANNEL_K_1             ((uint8)0x19)
#define DIO_CHANNEL_K_2             ((uint8)0x1a)
#define DIO_CHANNEL_K_3             ((uint8)0x1b)
#define DIO_CHANNEL_K_4             ((uint8)0x1c)
#define DIO_CHANNEL_K_5             ((uint8)0x1d)
#define DIO_CHANNEL_K_6             ((uint8)0x1e)
#define DIO_CHANNEL_K_7             ((uint8)0x1f)

#define DIO_PORT_A                  ((uint8)0x00)
#define DIO_PORT_B                  ((uint8)0x01)
#define DIO_PORT_E                  ((uint8)0x02)
#define DIO_PORT_K                  ((uint8)0x04)


/*
**  Global Types.
*/
typedef enum tagS12Mebi_ModeType {
    S12MODE_SPECIAL_SINGLE_CHIP,
    S12MODE_EMULATION_NARROW,
    S12MODE_SPECIAL_TEST,
    S12MODE_EMULATION_WIDE,
    S12MODE_NORMAL_SINGLE_CHIP,
    S12MODE_NORMAL_EXPANDED_NARROW,
    S12MODE_SPECIAL_PERIPHAL,
    S12MODE_NORMAL_EXPANDED_WIDE
} S12Mebi_ModeType;


typedef struct tagS12Mebi_ConfigType {
    uint16 BaseAddr;

    uint8 Pucr;
    uint8 Rdriv;
    uint8 IrqCr;

    /* PortA */
    uint8 DdrA;
    uint8 PortA;

    /* PortB */
    uint8 DdrB;
    uint8 PortB;

    /* PortE */
    uint8 DdrE;
    uint8 PortE;

    /* PortK */
    uint8 DdrK;
    uint8 PortK;

} S12Mebi_ConfigType;


/*
**  Global Functions.
*/
void S12Mebi_Init(S12Mebi_ConfigType const * ConfigPtr);
S12Mebi_ModeType S12Mebi_GetMode(void);
boolean S12Mebi_SpecialMode(void);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __S12_MEBI_H */
