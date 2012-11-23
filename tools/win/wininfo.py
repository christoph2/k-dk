#!/usr/bin/env python
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

from collections import namedtuple
import os
import sys

if sys.platform != 'win32':
    print "Sorry, you a not using Windows!"
    sys.exit(1)

import win32api

PROCESSOR_ARCHITECTURE_AMD64    = 9
# PROCESSOR_ARCHITECTURE_ARM      = Reserved
PROCESSOR_ARCHITECTURE_IA64     = 6
PROCESSOR_ARCHITECTURE_INTEL    = 0
PROCESSOR_ARCHITECTURE_UNKNOWN  = 0xffff

PROCESSOR_INTEL_386             = 386
PROCESSOR_INTEL_486             = 486
PROCESSOR_INTEL_PENTIUM         = 586
PROCESSOR_INTEL_IA64            = 2200
PROCESSOR_AMD_X8664             = 8664
#PROCESSOR_ARM (Reserved)

ARCH_MAP = {
    PROCESSOR_ARCHITECTURE_AMD64:   "AMD64",
    PROCESSOR_ARCHITECTURE_IA64:    "IA64",
    PROCESSOR_ARCHITECTURE_INTEL:   "INTEL",
    PROCESSOR_ARCHITECTURE_UNKNOWN: "UNKNOWN",
}

TYPE_MAP = {
    PROCESSOR_INTEL_386:            "i386",
    PROCESSOR_INTEL_486:            "i486",
    PROCESSOR_INTEL_PENTIUM:        "Pentium",
    PROCESSOR_INTEL_IA64:           "ia64",
    PROCESSOR_AMD_X8664:            "AMD X8664",
}

def getArchStr(arch):
    return ARCH_MAP.get(arch, "UNKNOWN")

def getTypeStr(type_):
    return TYPE_MAP.get(type_, "UNKNOWN")


ProcessorInfo = namedtuple("ProcessorInfo", "processorLevel processorRevision")

Info = namedtuple('Info', """
        processorArchitecture pageSize minimumApplicationAddress
        maximumApplicationAddress activeProcessorMask
        numberOfProcessors processorType allocationGranularity
        processorInfo""")


def getInfo():
    return Info(*win32api.GetSystemInfo())

def prettyPrint():
    info = getInfo()
    print
    print "Architecture:\t\t%s" % getArchStr(info.processorArchitecture)
    print "Processor-Type:\t\t%s" % getTypeStr(info.processorType)
    print "Processor-Level:\t%u" % info.processorInfo[0]
    print "Processor-Revision:\t%#X" % info.processorInfo[1]
    print "Number of Processors:\t%u" % info.numberOfProcessors
    print "Active Processor Mask:\t%#0X" % info.activeProcessorMask
    print "Pagesize:\t\t%#X" % info.pageSize
    print "Allocation-Granularity:\t%#X" % info.allocationGranularity
    print "Min. Load Address:\t%#X" % info.minimumApplicationAddress
    print "Max. Load Address:\t%#X" % info.maximumApplicationAddress

def main():
    prettyPrint()

if __name__ == '__main__':
    main()