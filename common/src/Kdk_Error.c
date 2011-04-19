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
 * s. FLOSS-EXCEPTION.txt
 */

#include "Kdk_Error.h"

// _DEV_ERROR_DETECT
#if 0
#if AR_DEV_ERROR_DETECT(DIO_4711_MEBI)==STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(DIO_4711_MEBI);
#endif

#if AR_DEV_ERROR_DETECT(PORT)==STD_ON
    AR_ASSERT_MODULE_INITIALZATION(PORT,AR_SERVICE_PORT_SET_PIN_DIRECTION);

#if 0
    if (!AR_MODULE_IS_INITIALIZED(PORT)) {
        Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,AR_SERVICE_PORT_SET_PIN_DIRECTION,PORT_E_UNINIT);
    }
#endif
#endif
#endif

void KDKError_Init(void)
{

}

void KDKError_ReportError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId)
{

}

void KDKError_Start(void)
{

}
