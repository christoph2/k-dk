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
#if !defined(__KDK_ERROR_H)
#define __KDK_ERROR_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "Std_Types.h"
#include "KDK_ModuleIDs.h"

/*
**  Global Macros.
*/
#define KDK_DEV_ERROR_DETECT(mod) GLUE2(mod, _DEV_ERROR_DETECT)

/*
**  Global Types.
*/
typedef void (*KDKError_Hook)(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/*
**  Global Functions.
*/
void    KDKError_Init(void);
void    KDKError_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
void    KDKError_Start(void);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __KDK_ERROR_H */
