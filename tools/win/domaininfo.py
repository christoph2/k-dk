#!/usr/bin/python
# -*- coding: utf-8 -*-

__version__ = '0.9.0'
__author__ = 'Christoph Schueler'
__copyright__ = \
    """
   k_os (Konnex Operating-System based on the OSEK/VDX-Standard).

  (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
                                       cpu12.gems@googlemail.com>

  All Rights Reserved

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

   s. FLOSS-EXCEPTION.txt
"""

import ntsecuritycon
import win32api
import win32security
import winerror

SID_TYPE_USER               = 1
SID_TYPE_GROUP              = 2
SID_TYPE_DOMAIN             = 3
SID_TYPE_ALIAS              = 4
SID_TYPE_WELL_KNOWN_GROUP   = 5
SID_TYPE_DELETED_ACCOUNT    = 6
SID_TYPE_INVALID            = 7
SID_TYPE_UNKNOWN            = 8
SID_TYPE_COMPUTER           = 9
SID_TYPE_LABEL              = 10

def getDomainInfo():
    try:
        token = win32security.OpenThreadToken(win32api.GetCurrentThread(), ntsecuritycon.TOKEN_QUERY, 1)
    except win32api.error, exc:
        if exc[0] != winerror.ERROR_NO_TOKEN:
            raise
        token = win32security.OpenProcessToken(win32api.GetCurrentProcess(), ntsecuritycon.TOKEN_QUERY)
    sid, attr = win32security.GetTokenInformation(token, ntsecuritycon.TokenUser)
    name, domain, type_ = win32security.LookupAccountSid(None, sid)
    win32api.CloseHandle(token)
    return name, domain, type_

def SIDTypeToString(type_):
    TYPE_MAP = {
        SID_TYPE_USER               : "user",
        SID_TYPE_GROUP              : "group",
        SID_TYPE_DOMAIN             : "domain",
        SID_TYPE_ALIAS              : "alias",
        SID_TYPE_WELL_KNOWN_GROUP   : "well-known group",
        SID_TYPE_DELETED_ACCOUNT    : "deleted account",
        SID_TYPE_INVALID            : "invalid",
        SID_TYPE_UNKNOWN            : "unknown",
        SID_TYPE_COMPUTER           : "computer",
        SID_TYPE_LABEL              : "label"
    }
    return TYPE_MAP.get(type_, '???')


if __name__=='__main__':
    name, domain, type_ = getDomainInfo()
    print "System-Name: '%s'\nDomain: '%s'\nType: '%s SID'." % (name, domain, SIDTypeToString(type_))

