/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
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
 * s. FLOSS-EXCEPTION.txt
 *
 */
#if !defined(__MSCAN_H)
#define __MSCAN_H

#include "Std_Types.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Global Defines.
*/
#define MSCAN_MAX_LSDU_LEN      ((uint8)0x08)
#define MSCAN_FILTER_LEN        ((uint8)0x08)

#define MSCAN_ACC_FLT_TWO_32    ((uint8)0x00)   /* Two 32 bit Acceptance Filters.               */
#define MSCAN_ACC_FLT_FOUR_16   ((uint8)0x10)   /* Four 16 bit Acceptance Filters.              */
#define MSCAN_ACC_FLT_EIGHT_8   ((uint8)0x20)   /* Eight 8 bit Acceptance Filters.              */
#define MSCAN_ACC_FLT_CLOSED    ((uint8)0x30)   /* Filter Closed.                               */

/*
**  Global Types.
*/
typedef uint32 MSCan_IdType;

typedef struct tagMSCan_BusTimingType {
    uint8   BTR0;
    uint8   BTR1;
} MSCan_BusTimingType;

typedef union tagMSCan_IdentifierOverlayType {
    uint8   b[4];
    uint16  w[2];
    uint32  d;
} MSCan_IdentifierOverlayType;

typedef uint8   MSCan_IdentifierType[MSCAN_FILTER_LEN];
typedef uint8   MSCan_SDUType[MSCAN_MAX_LSDU_LEN];

typedef struct tagMSCan_MessageType {
    MSCan_IdType    ID;
    uint8           DLR;
    MSCan_SDUType   SDU;
} MSCan_MessageType;

typedef struct tagMSCan_FilterType {
    MSCan_IdentifierOverlayType IdentifierAcceptance;
    MSCan_IdentifierOverlayType IdentifierMask;
} MSCan_FilterType;

/*
**  Global Functions.
*/
void    MSCan_Set11BitIdentifier(MSCan_IdentifierOverlayType * Identifier, MSCan_IdType ID);
void    MSCan_Set29BitIdentifier(MSCan_IdentifierOverlayType * Identifier, MSCan_IdType ID);
void    MSCan_Get11BitIdentifier(MSCan_IdentifierOverlayType const * Identifier, MSCan_IdType * ID);
void    MSCan_Get29BitIdentifier(MSCan_IdentifierOverlayType const * Identifier, MSCan_IdType * ID);


/*
**  Global Function-like Macros.
*/
#define MSCAN_8_8_FILTERS(a, b, c, d, e, f, g, h)   {(uint8)(a), (uint8)(b), (uint8)(c), (uint8)(d), \
                                                     (uint8)(e), (uint8)(f), (uint8)(g), (uint8)(h)}

#define MSCAN_4_16_FILTERS(a, b, c, d)              {HIBYTE(a), LOBYTE(a), HIBYTE(b), LOBYTE(b), HIBYTE(c), \
                                                     LOBYTE(c), HIBYTE(d), LOBYTE(d)}

#define MSCAN_2_32_FILTERS(a, b)                    {HIBYTE(HIWORD(a)), LOBYTE(HIWORD(a)), HIBYTE(LOWORD(a)),                    \
                                                     LOBYTE(LOWORD(a)), HIBYTE(HIWORD(b)), LOBYTE(HIWORD(b)), HIBYTE(LOWORD(b)), \
                                                     LOBYTE(LOWORD(b))}

#define MSCAN_SET_EXTENDED_ID(id)                   ((id)   |=  0x80000000UL)
#define MSCAN_CLR_EXTENDED_ID(id)                   ((id)   &= ~0x80000000UL)
#define MSCAN_IS_EXTENDED_ID(id)                    ((((id) &   0x80000000UL) == 0x80000000UL) ? TRUE : FALSE)

#define MSCAN_SET_RTR(id)                           ((id)   |=  0x40000000UL)
#define MSCAN_CLR_RTR(id)                           ((id)   &= ~0x40000000UL)
#define MSCAN_IS_RTR(id)                            ((((id) &   0x40000000UL) == 0x40000000UL) ? TRUE : FALSE)

/* todo: Makros für das CAN-Bit-Timing!!! */
#define MSCAN_BTR0(pr, sjw)                         ((((sjw) & (uint8)0x03) << 6) | ((pr) & (uint8)0x3f))
#define MSCAN_BTR1(propseg, phseg1, phseg2)         /* t.b.d. */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __MSCAN_H */

