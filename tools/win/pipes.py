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
import random
import sys
import time
import win32api
import win32file
import win32pipe

PIPE_BROADCAST              = '*'
PIPE_LOCALHOST              = '.'

#ERROR_BROKEN_PIPE           = 109
ERROR_PIPE_CONNECTED        = 535
ERROR_PIPE_LISTENING        = 536


class NamedPipeServer(ipc.IPC):
    objType = 'pipe'

    numberOfInstances = 0

    def __init__(self, logger, level):
        super(NamedPipeServer, self).__init__(logger, level)

    @classmethod
    def create(cls, name, path = '', host = PIPE_LOCALHOST, blocking = True, msgLimit = 0,
               logger = logging.getLogger("k_os.ipc"), level = logging.INFO):
        pname = cls.getCanoicalName(host, path, name)
        sa = pywintypes.SECURITY_ATTRIBUTES()
        instance = cls(logger, level)
        instance.name = name
        instance.handle = win32pipe.CreateNamedPipe(pname,
            win32pipe.PIPE_ACCESS_DUPLEX,
            win32pipe.PIPE_TYPE_MESSAGE or win32pipe.PIPE_READMODE_MESSAGE or (
                blocking and win32pipe.PIPE_WAIT or win32pipe.PIPE_NOWAIT
            ),
            win32pipe.PIPE_UNLIMITED_INSTANCES,
            100,
            100,
            win32pipe.NMPWAIT_USE_DEFAULT_WAIT,
            sa
        )
        NamedPipeServer.numberOfInstances += 1
        instance._logger.debug("Created NamedPipe '%s'." % pname)
        instance._logger.debug("Current # of instances = %u." % NamedPipeServer.numberOfInstances)
        res = win32pipe.ConnectNamedPipe(instance.handle, None)
        instance._logger.debug("Client connected to NamedPipe.")
        return instance


class NamedPipeClient(ipc.IPC):
    objType = 'pipe'

    def __init__(self, logger = logging.getLogger("k_os.server"), level = logging.INFO):
        super(NamedPipeClient, self).__init__(logger, level)

    def wait(self, blocking = True):
        win32pipe.WaitNamedPipe(self.name,
            blocking and win32pipe.NMPWAIT_WAIT_FOREVER or win32pipe.NMPWAIT_USE_DEFAULT_WAIT
        )

    def peek(self):
        win32pipe.peek()


    @classmethod
    def call(cls, name, data, inBufferSize, timeOut = win32pipe.NMPWAIT_USE_DEFAULT_WAIT, \
             path = '', host = PIPE_LOCALHOST):
        pipeName = cls.getCanoicalName(host, path, name)
        result = win32pipe.CallNamedPipe(pipeName, data , inBufferSize, timeOut)
        return result



    def transact(self, name, writeData):
        buf = win32file.AllocateReadBuffer(length)
        win32pipe.TransactNamedPipe(name, writeData, buf, None)
        """
        string/buffer = TransactNamedPipe(pipeName, writeData , buffer/bufSize , overlapped )
            Combines the functions that write a message to and read a message from the specified named pipe into a single network operation.


        Parameters
            pipeName : PyUNICODE
                The name of the pipe.

            writeData : string/buffer
                The data to write to the pipe.

            buffer/bufSize : PyOVERLAPPEDReadBuffer/int
                Size of the buffer to create for the result, or a buffer to fill
                with the result. If a buffer object and overlapped is passed, the
                result is the buffer itself. If a buffer but no overlapped is passed,
                the result is a new string object, built from the buffer, but with a
                length that reflects the data actually read.

            overlapped=None : PyOVERLAPPED
                An overlapped structure or None
        """
        pass

##
##
##

def main():
    if sys.argv[ 1 : ] and sys.argv[1].upper() == 'S':
        Server = True
    else:
        Server = False

    if Server:
        print "Starting NamedPipe-Server"
        ms = NamedPipeServer.create(ur'\KOS\SERVER', blocking = True)
        while True:
            #ms.wait()
            res = ms.read(100)
            #if res:
            print str(res)
            #time.sleep(1)
    else:
        print "Starting NamedPipe-Client"
        ms = NamedPipeClient.open(ur'\KOS\SERVER')
        #ms.wait(True)
        while True:
            res, _, _ = ms.write('Hello world!!!')
            if not res:
                print "Exiting..."
                sys.exit(1)
            time.sleep(1)

FILE_CASE_SENSITIVE_SEARCH      = 0x00000001
FILE_CASE_PRESERVED_NAMES       = 0x00000002
FILE_UNICODE_ON_DISK            = 0x00000004
FILE_PERSISTENT_ACLS            = 0x00000008
FILE_FILE_COMPRESSION           = 0x00000010
FILE_VOLUME_QUOTAS              = 0x00000020
FILE_SUPPORTS_SPARSE_FILES      = 0x00000040
FILE_SUPPORTS_REPARSE_POINTS    = 0x00000080
FILE_SUPPORTS_REMOTE_STORAGE    = 0x00000100
FILE_VOLUME_IS_COMPRESSED       = 0x00008000
FILE_SUPPORTS_OBJECT_IDS        = 0x00010000
FILE_SUPPORTS_ENCRYPTION        = 0x00020000
FILE_NAMED_STREAMS              = 0x00040000
FILE_READ_ONLY_VOLUME           = 0x00080000
FILE_SEQUENTIAL_WRITE_ONCE      = 0x00100000
FILE_SUPPORTS_TRANSACTIONS      = 0x00200000

FS_CASE_IS_PRESERVED            = FILE_CASE_PRESERVED_NAMES
FS_CASE_SENSITIVE               = FILE_CASE_SENSITIVE_SEARCH
FS_UNICODE_STORED_ON_DISK       = FILE_UNICODE_ON_DISK
FS_PERSISTENT_ACLS              = FILE_PERSISTENT_ACLS
FS_VOL_IS_COMPRESSED            = FILE_VOLUME_IS_COMPRESSED
FS_FILE_COMPRESSION             = FILE_FILE_COMPRESSION
FS_FILE_ENCRYPTION              = FILE_SUPPORTS_ENCRYPTION

FILE_SYSTEM_FLAGS = (
    (FILE_CASE_SENSITIVE_SEARCH, 'caseSensitiveFileNames'),
    (FILE_CASE_PRESERVED_NAMES, 'casePreservedFileNames'),
    (FILE_UNICODE_ON_DISK, 'unicodeFileNames'),
    (FILE_PERSISTENT_ACLS , 'enforceACLs'),
    (FILE_FILE_COMPRESSION, 'supportsCompression'),
    (FILE_VOLUME_QUOTAS, 'supportsQuotas'),
    (FILE_SUPPORTS_SPARSE_FILES, 'supportsSparseFiles'),
    (FILE_SUPPORTS_REPARSE_POINTS, 'supportsReparsePoints'),
    (FILE_SUPPORTS_REMOTE_STORAGE, 'supportsRemoteStorage'),
    (FILE_VOLUME_IS_COMPRESSED, 'volumeIsCompressed'),
    (FILE_SUPPORTS_OBJECT_IDS, 'supportsObjectIdentifiers'),
    (FILE_SUPPORTS_ENCRYPTION, 'supportsEncryption'),
    (FILE_NAMED_STREAMS, 'supportsNamedStreams'),
    (FILE_READ_ONLY_VOLUME, 'isReadOnly'),
    (FILE_SEQUENTIAL_WRITE_ONCE, 'supportsSequentialWriteOnce'),
    (FILE_SUPPORTS_TRANSACTIONS, 'supportsTransactions'),
)


def volumeInformation(driveLetter):
    if len(driveLetter) != 1:
        raise ValueError('Driver letter must be a single char.')
    volumeName, volumeSerialNumber, maxComponentLen, sysFlags, fileSystemName = \
        win32api.GetVolumeInformation(r'%c:\\' % driveLetter)
    return (volumeName, volumeSerialNumber, maxComponentLen, sysFlags, fileSystemName)

def volumeTraits(driveLetter):
    class VolumeTraits(object):
        def __repr__(self):
            result = []
            for attr in sorted([a for a in self.__dict__ if not (a.startswith('_') or a.endswith('_'))]):
                result.append("%s = %s" % (attr, getattr(self, attr)))
            return '\n'.join(result)

    _, _, _, flags,_ = volumeInformation(driveLetter)
    vt = VolumeTraits()
    vt.driveLetter = driveLetter.upper()
    for fsFlag, attr in FILE_SYSTEM_FLAGS:
        if (flags & fsFlag) == fsFlag:
            setattr(vt, attr, True)
        else:
            setattr(vt, attr, False)
    return vt

if __name__ == '__main__':
    t0 = volumeTraits('n')
    print t0
    t1 = volumeTraits('l')
    print t1
    main()

