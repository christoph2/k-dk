/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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
 * s. FLOSS-EXCEPTION.txt
 */

#include "HC12_Si.h"
#include "Hw_Cfg.h"


#if HC12SI_DEV_ERROR_DETECT == STD_ON
#define HC12SI_ASSERT_VALID_PORT(port) \
_BEGIN_BLOCK \
if (port > HC12SI_PORT_MAX) { \
/*            ErrorHandler(...); */ \
    return; \
} \
_END_BLOCK
#else
#define HC12SI_ASSERT_VALID_PORT(port)
#endif /* HC12SI_DEV_ERROR_DETECT */

#if HC12SI_DEV_ERROR_DETECT == STD_ON
#define HC12SI_ASSERT_VALID_CHANNEL(channel) \
_BEGIN_BLOCK \
if (channel > HC12SI_CHANNEL_MAX) { \
    /*            ErrorHandler(...); */ \
    return; \
} \
_END_BLOCK
#else
#define HC12SI_ASSERT_VALID_CHANNEL(channel)
#endif  /* HC12SI_DEV_ERROR_DETECT */


/*
** Local Constants.
*/
static const uint8 HC12Si_Ports[] = {
    PORTS
};

static const uint8 HC12Si_PortDDRs[] = {
    DDRS
};

void HC12Si_Init(HC12Si_ConfigType const * const ConfigPtr)
{
    HC12SI_REG8(PORTS) = ConfigPtr->PortS;
    HC12SI_REG8(DDRS)  = ConfigPtr->DdrS;

#if (CPU_DERIVATE != CPU12_HC12A4)
    HC12SI_REG8(PURDS)  = ConfigPtr->PurdS;
#endif
}

/*
**  Implementation of common functions.
*/

IMPLEMENT_IO_WRITE_PORT(HC12SI, HC12Si)
IMPLEMENT_IO_READ_PORT(HC12SI, HC12Si)

IMPLEMENT_IO_WRITE_CHANNEL(HC12SI, HC12Si)
IMPLEMENT_IO_READ_CHANNEL(HC12SI, HC12Si)

IMPLEMENT_IO_WRITE_CHANNEL_GROUP(HC12SI, HC12Si)
IMPLEMENT_IO_READ_CHANNEL_GROUP(HC12SI, HC12Si)

IMPLEMENT_IO_SET_PIN_DIRECTION(HC12SI, HC12Si)
