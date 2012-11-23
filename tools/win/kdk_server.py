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

import array

import logging
import pipes
import Queue
import struct
import sys
import threading
import win32api


class Server(object):
    def __init__(self, logger = logging.getLogger("k_os.server"), level = logging.INFO):
        self._logger = logger
        self._level = level
        self._logger.setLevel(level)
        self._logger.info('Starting K_OS server.')

    def waitConnect(self):
        pipe = pipes.NamedPipeServer.create(ur'\KOS\SERVER', blocking = True, level = self._level)
        return pipe

    def _clientThread(self, pipe):
        storage = threading.local()
        while True:
            try:
                res = pipe.read()
            except win32api.error as error:
                ec, fct, msg = error.args
                if ec == pipes.ipc.ERROR_BROKEN_PIPE:
                    self._logger.info("NamedPipe closed by client.")    # NodeID:
                    break
                else:
                    self._logger.error( "%s failed with %u - '%s'" % (fct , ec, msg))
                    break
            except:
                exc_type, exc_value, _  = sys.exc_info()
                self._logger.error("Unexpected exception: %s - %s" % (exc_type, exc_value))
                break
            #print "LEN: %u" % len(res)
            print
            command, subCommand = res[0], res[1]
            payload = struct.unpack('<L', res[2 : ])
            print "CMD: %s SC: %s PAYLOAD: %s" % (command, subCommand, payload)
#            for h in res:
#                print ord(h),
            print

    def createClientThread(self, pipe):
        thread = threading.Thread(target = self._clientThread, args = (pipe, ))
        #thread.start()
        return thread


def main():
    threadList = []
    srv = Server(level = logging.DEBUG)
    pipe = srv.waitConnect()
    thread =  srv.createClientThread(pipe)
    threadList.append(thread)
    thread.start()

    thread.join()
    print "Finished."

    # supervisor = threading.Thread(target = self._supervisor, args = (self,), name= 'supervisor')
    # supervisor.start()

if __name__ == '__main__':
    main()

##
## Practical experience has shown that plain VFB-simulation, offered by any other BSW-supplier,
## simply isn't enough to ... ??? (WEITER!!!)
##      - to answer important questions, like
##

"""
ORTI-debuggers are often ziemlich kleinlich wenn es um KOIL und ORTI versionsnummern geht.
Before loading an ORTI-file, one has to patch this version-numbers, which can be
rather pesky.
But wait!
K_OS offers a clean solution for this issue:
???
"""

""""
Consider the following:
=======================

uint32 foo;
uint32 bar;

void veryFrequentlyCallOSFunction(uint8 n, uint8 m)
{
    foo <<= n;
    bar >> m;
}

"""
##
## ... aber was herragend simuliert, nachgebildet werden kann, ist das Verhalten
## von komplexen, verteilten Statemachines (eine große Hilfe für mich bei der
## Entwicklung von Netzwerk-Management Protokollen).
##

##
##  OoW - OSEK on Windows.
##
