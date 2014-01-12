#!/usr/bin/python
# -*- coding: utf-8 -*-

__version__ = '0.9.0'
__author__ = 'Christoph Schueler'
__copyright__ = """
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
"""

import abc
import logging
import pywintypes
import time
import threading
import sys
import win32con
import win32file
import win32api

MAILSLOT_NO_MESSAGE     = -1
MAILSLOT_WAIT_FOREVER   = -1

ERROR_SUCCESS               = 0
ERROR_FILE_NOT_FOUND        = 2
ERROR_HANDLE_EOF            = 38
ERROR_BROKEN_PIPE           = 109
ERROR_OPEN_FAILED           = 110
ERROR_SEM_TIMEOUT           = 121
ERROR_NO_DATA               = 232
ERROR_MORE_DATA             = 234
ERROR_IO_PENDING            = 997
ERROR_IO_INCOMPLETE         = 996
ERROR_NO_SYSTEM_RESOURCES   = 1450

def configureLogger(level = logging.INFO):
    kwargs = {
        'level':    level,
        'format':   "%(asctime)s - %(name)s[%(levelname)s]: %(message)s"
        }
    logging.basicConfig(**kwargs)

configureLogger()


class IPC(object):
    __metaclass__ = abc.ABCMeta

    handle = None
    objType = None

    def __init__(self, logger = logging.getLogger("k_os.ipc"), level = logging.INFO):
        self._logger = logger
        self._logger.setLevel(level)
        self._opened = False

    def __del__(self):
        if self._opened:
            self.close()

    def close(self):
        win32api.CloseHandle(self.handle)

    def read(self, length = 1024):
        #buf = win32file.AllocateReadBuffer(length)
        try:
            #(hr, result) = win32file.ReadFile(self.handle, buf, None)
            (hr, result) = win32file.ReadFile(self.handle, length, None)
        except win32api.error as exc:
            ec = win32api.FormatMessage()
            if exc.args[0] == ERROR_SEM_TIMEOUT:
                return buf
            else:
                raise
        if hr == 0:
            pass
        elif hr == ERROR_MORE_DATA:
            pass
        elif hr == ERROR_IO_PENDING:
            pass
        else:
            raise Exception("unknown return code '%u'." % hr)
#       return buf
        return result

    @classmethod
    @abc.abstractmethod
    def create(cls, logger, level):
        pass

    @classmethod
    def getCanoicalName(cls, host, path, name):
        if path and not path.endswith('\\'):
            path = '%s\\' % path
        return r"\\%s\%s\%s%s" % (host, cls.objType, path, name)

    def write(self, data):
        try:
            (errCode, nBytesWritten) = win32file.WriteFile(self.handle, data)
        except pywintypes.error as exc:
            if exc.args[0] in (ERROR_HANDLE_EOF, ERROR_NO_SYSTEM_RESOURCES, ERROR_NO_DATA):
                return (False, 0, exc.args[0])
            else:
                raise
        if nBytesWritten != len(data):
            return (False, nBytesWritten, errCode)
        else:
            return (True, nBytesWritten, ERROR_SUCCESS)

    @classmethod
    def open(cls, name, path = '', host = '.'):
        sa = pywintypes.SECURITY_ATTRIBUTES()
        name = cls.getCanoicalName(host, path, name)
        instance = cls()
        instance.name = name
        try:
            instance.handle = win32file.CreateFile(name,
                win32file.GENERIC_WRITE | win32file.GENERIC_WRITE,
                win32file.FILE_SHARE_READ | win32file.FILE_SHARE_WRITE,
                sa,
                win32con.OPEN_ALWAYS,
                0,
                None
            )
        except pywintypes.error as exc:
            if exc.args[0] == ERROR_FILE_NOT_FOUND:
                raise RuntimeError("Server for %s '%s' not started." % (cls.objType, name))
        self._opened = True
        return instance

