/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2014 by Christoph Schueler <github.com/Christoph2,
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

#include <malloc.h>
#include <stdio.h>
#if _WIN32_WINNT <= 0x0601
    #define _WIN32_WINNT 0x0601
#endif
#include <windows.h>

void Win_Error(char * function)
{
    char * szBuf;
    LPWSTR  lpMsgBuf;
    WORD len, idx;
    DWORD err = GetLastError();

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, err,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR) &lpMsgBuf, 0, NULL );
   
    len = lstrlen(lpMsgBuf) + 1;
    szBuf = (char *)_alloca((len * sizeof(lpMsgBuf[0])));
    for (idx = 0; idx < len; ++idx) {
        szBuf[idx] = lpMsgBuf[idx];
    }
//_tprintf(szBuf, "%s failed with error %d: %s",  lpszFunction, err, szBuf); 
    printf("%s failed with error %d: %s", function, err, szBuf); 

    _freea(szBuf);
    LocalFree(lpMsgBuf);
}
