#!/usr/bin/python
# -*- coding: utf-8 -*-

__version__ = '0.9.0'
__author__ = 'Christoph Schueler'
__copyright__ = """
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
"""

import ipc
import logging
import pywintypes
import socket
import sys
import time
import unittest
import win32api
import win32file

MAILSLOT_NO_MESSAGE     = -1
MAILSLOT_WAIT_FOREVER   = -1

MS_BROADCAST            = '*'
MS_LOCALHOST            = '.'

MAILSLOT_MAX_MSG_LEN    = 424


class MailslotServer(ipc.IPC):
    objType = 'mailslot'

    @classmethod
    def create(cls, name, path = '', host = MS_LOCALHOST, blocking = True, msgLimit = 0):
        name = cls.getCanoicalName(host, path, name)
        sa = pywintypes.SECURITY_ATTRIBUTES()
        instance = cls()
        instance.name = name
        instance.handle = win32file.CreateMailslot(name, msgLimit, blocking and MAILSLOT_WAIT_FOREVER or 0, sa)
        return instance

    def check(self):
        max_msg_size, next_msg_size, msg_count, timeout = win32file.GetMailslotInfo(self.handle)
        return max_msg_size, next_msg_size, msg_count, timeout

    def write(self, data):
        raise NotImplementedError("Servers can't write to a MailSlot.")


class MailslotClient(ipc.IPC):
    objType = 'mailslot'

    def read(self, length):
        raise NotImplementedError("Clients can't read from a MailSlot.")

    def write(self, data):
        if len(data) > MAILSLOT_MAX_MSG_LEN:
            raise RuntimeError("MailSlot messages can't be larger than %u bytes." % MAILSLOT_MAX_MSG_LEN)
        return super(MailslotClient, self).write(data)


print socket.gethostname()

def main():
    if sys.argv[1:] and sys.argv[1].upper() == 'S':
        Server = True
    else:
        Server = False

    if Server:
        print "Starting MailSlot-Server"
        ms = MailslotServer.create('foobar', blocking = True)
        while True:
            max_msg_size, next_msg_size, msg_count, timeout = ms.check()
            if msg_count > 0:
                res = ms.read(next_msg_size)
                print str(res)
            time.sleep(1)
    else:
        print "Starting MailSlot-Client..."
        try:
            ms = MailslotClient.open('foobar')
        except RuntimeError as e:
            print e.args[0] + " Exiting."
            sys.exit(1)
        while True:
            res, _, _ = ms.write('Hello world!!!')
            if not res:
                print "Exiting..."
                sys.exit(1)
            time.sleep(1)


COMPUTER_NAME_PHYSICAL_NETBIOS = 0

def getComputerNBName():
    return win32api.GetComputerNameEx(COMPUTER_NAME_PHYSICAL_NETBIOS)

print getComputerNBName()

##
##  Unit-Tests.
##
class TestClient(unittest.TestCase):
    def testInvalidServer(self):
        self.assertRaises(RuntimeError, MailslotClient.open('foobar'))

if __name__ == '__main__':
    #unittest.main()
    main()

