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
 *
 */

#if !defined(__KDK_WIN_UTILS_H)
#define __KDK_WIN_UTILS_H

#include <windows.h>
#include <stdio.h>

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


/*
**  Global Types.
*/
typedef struct tagKDKWin_FileViewType {
    HANDLE mappingHandle;
    void * mappingAddress;
} KDKWin_FileViewType;


typedef struct tagKDKWin_PersistentArrayType {
    HANDLE fileHandle;
    HANDLE mappingHandle;
    void * mappingAddress;
} KDKWin_PersistentArrayType;


typedef enum tagOpenCreateType {
    OPEN_ERROR,
    OPEN_EXSISTING,
    NEW_FILE
} OpenCreateType;


/*
**  Global Functions.
*/

void printErrorMessage(wchar_t const * func, DWORD error);

HANDLE KDKWin_OpenCreateFile(wchar_t const * fileName, BOOL create);

BOOL KDKWin_CreateFileView(HANDLE handle, DWORD length, KDKWin_FileViewType * fileView);
void KDKWin_CloseFileView(KDKWin_FileViewType * fileView);

BOOL KDKWin_CreatePersitentArray(wchar_t const * fileName, DWORD size, KDKWin_PersistentArrayType * persistentArray);
void KDKWin_ClosePersitentArray(KDKWin_PersistentArrayType const * persistentArray);

/*
**  Global Function-like Macros.
*/
#if !defined(MIN)
#define MIN(l, r)   ((l) < (r) ? (l) : (r))
#endif /* MIN */

#if !defined(MAX)
#define MAX(l, r)   ((l) < (r) ? (r) : (l))
#endif /* MAX */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */


#endif /* __KDK_WIN_UTILS_H */
