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
#if !defined(__S12_BKP_H)
#define __S12_BKP_H

#include "S12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define BKPCT0          ((uint8))0x00)
    /*  BKPCT0-Bits.  */
    #define BKEN        ((uint8))0x80)
    #define BKFULL      ((uint8))0x40)
    #define BKBDM       ((uint8))0x20)
    #define BKTAG       ((uint8))0x10)

#define BKPCT1          ((uint8))0x01)
    /*  BKPCT1-Bits.  */
    #define BK0MBH      ((uint8))0x80)
    #define BK0MBL      ((uint8))0x40)
    #define BK1MBH      ((uint8))0x20)
    #define BK1MBL      ((uint8))0x10)
    #define BK0RWE      ((uint8))0x08)
    #define BK0RW       ((uint8))0x04)
    #define BK1RWE      ((uint8))0x02)
    #define BK1RW       ((uint8))0x01)

#define BKP0X           ((uint8))0x02)
    /*  BKP0X-Bits. */
    #define BK0V5       ((uint8))0x20)
    #define BK0V4       ((uint8))0x10)
    #define BK0V3       ((uint8))0x08)
    #define BK0V2       ((uint8))0x04)
    #define BK0V1       ((uint8))0x02)
    #define BK0V0       ((uint8))0x01)

#define BKP0            ((uint8))0x03)

#define BKP0H           ((uint8))0x03)

#define BKP0L           ((uint8))0x04)

#define BKP1X           ((uint8))0x05)
    /*  BKP1X-Bits. */
    #define	BK1V5 	((uint8))0x20)
    #define	BK1V4 	((uint8))0x10)
    #define	BK1V3 	((uint8))0x08)
    #define	BK1V2 	((uint8))0x04)
    #define	BK1V1 	((uint8))0x02)
    #define	BK1V0	((uint8))0x01)

#define BKP1            ((uint8))0x06)

#define BKP1H           ((uint8))0x06)

#define BKP1L           ((uint8))0x07)


typedef struct tagS12Bkp_ConfigType {
    uint16 BaseAddr;
} S12Bkp_ConfigType;


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __S12_BKP_H */
