#!/usr/bin/python
# -*- coding: latin-1 -*-

__version__="0.9.0"

__copyright__="""
Copyright (c) 2009 Christoph Schueler. All rights reserved.
"""

"""
uint16 CRC_CalculateCRC16(const uint8 *Crc_DataPtr,uint32 Crc_Length,uint16 Crc_StartValue16);

uint16 CRC_CalculateCRC16(const uint8 *data_ptr,uint32 length,uint16 initial_value,uint16 final_xor_value);

"""

import sys
import os
from optparse import OptionParser,OptionGroup


##  Some standards such as SDLC expect the data to come into the processor least
##  significant bit first, e.g. from a UART. Because of this, the standard
##  specifies that the incoming data and the resulting CRC must be bit reflected.
##  This means that the bits are swapped around their center position, e.g., in a
##  16-bit word, b0<->b15, b1<->b14, b2<->b13, etc. So rather than waste processor
##  time reflecting the input bits and then the CRC, the algorithm is reflected.
##  So for each normal algorithm, an associated reflected algorithm exists.
##  This saves both CPU time and power.

"""
unsigned short crc16MakeTableMethod(unsigned short crc, TBL_MEM unsigned short *table,
									unsigned char *pbuffer, unsigned int length)
{
    while(length--) 
        crc = table[((crc >> 8) ^ *pbuffer++)] ^ (crc << 8);	// normal

    return(crc ^ CRC16_FINAL_XOR);
}

unsigned short crc16rMakeTableMethod(unsigned short crc, TBL_MEM unsigned short *table,
									unsigned char *pbuffer, unsigned int length)
{
    while(length--) 
        crc = table[(crc & 0xFF) ^ *pbuffer++] ^ (crc >> 8);	// reflected

    return(crc ^ CRC16R_FINAL_XOR);
}

unsigned long crc32MakeTableMethod(unsigned long crc, TBL_MEM unsigned long *table, 
								   unsigned char *pbuffer, unsigned int length)
{
    while(length--) 
        crc = table[((crc >> 24) ^ *pbuffer++)] ^ (crc << 8);	// normal

    return(crc ^ CRC32_FINAL_XOR);
}

unsigned long crc32rMakeTableMethod(unsigned long crc, TBL_MEM unsigned long *table, 
								   unsigned char *pbuffer, unsigned int length)
{
    while(length--) 
        crc = table[(crc ^ *pbuffer++) & 0xFFL] ^ (crc >> 8);	// reflected

    return(crc ^ CRC32R_FINAL_XOR);
}
"""

"""
void crc16BuildTable(unsigned short *ptable, unsigned short poly)
{
	unsigned int i, j;

    for(i = 0; i <= 255; i++)
    {
        ptable[i] = i << 8;
        for(j = 0; j < 8; j++)
            ptable[i] = (ptable[i] << 1) ^ (ptable[i] & 0x8000 ? poly : 0);
    }
}

void crc32BuildTable(unsigned long *ptable, unsigned long poly)
{
	unsigned int i, j;

    for(i = 0; i <= 255; i++)
    {
        ptable[i] = (long)i << 24;        
        for(j = 0; j < 8; j++)
            ptable[i] = (ptable[i] << 1) ^ (ptable[i] & 0x80000000 ? poly : 0);
    }
}

"""


GENPOLY_FT3     =   0x3D65  ## FT3 (IEC870-5-2) (e.g. KNX/RF, wireless MBus("Wireless Meter Readout", CEN TC 294 WG 5))
                            ## Example: the sequence 01 02 03 04 05 06 07 08 has the CRC 'FCBC'
GENPOLY_CCITT   =   0x1021  ## SDLC,HDLC,ITU-T Q.921,V.41...
GENPOLY_MODBUS  =   0xa001  ## MODBus
GENPOLY_CANBUS  =   0xC599  ## CANBus

##
## BDLC (SAE J1850)
## CRC generation uses the divisor polynomial X8+X4+X3+X2+1. The remainder polynomial is
## initially set to all ones, and then each byte in the message after the SOF symbol is serially processed
## through the CRC generation circuitry. The one’s complement of the remainder then becomes the
## 8-bit CRC byte, which is appended to the message after the data bytes, in MSB to LSB order

##
## 8Bit-CRCs
##
## GSM 05.03 g(D) = D8 + D4 + D3 + D2 + 1
##

def CRCCalculate16(genpoly,data,accum):
    data <<= 8
    data &= 0xffff

    for i in xrange(8,0,-1):
        if ((data ^ accum) & 0x8000):
            accum=((accum << 1) ^ genpoly) & 0xffff
        else:
            accum <<= 1
            accum &= 0xffff
        data <<= 1
        data &= 0xffff

    return accum & 0xffff    


def CRCCalculate32(genpoly,data,accum):
    data <<= 24
    data &= 0xffffffff

    for i in xrange(8,0,-1):
        if ((data ^ accum) & 0x80000000):
            accum=((accum << 1) ^ genpoly) & 0xffffffff
        else:
            accum <<= 1
            accum &= 0xffffffff
        data <<= 1
        data &= 0xffffffff

    return accum & 0xffffffff   



def CRCGenerateTable(poly,py=False):
    str=""
    if py:
        str+="CRCTab=["
    else:
        str+="\nstatic const unsigned short CRCTab[256] = \n\t{"
    
    for j in xrange(32):
        str+="\n\t"
        for i in xrange(8*j,8*j+8):
            str+=("0x%04x,\t" % (CRCCalculate16(poly,i,0)))
##            str+=("0x%08x,\t" % (CRCCalculate32(poly,i,0)))
    if py:
        str+="\n]"
    else:
        str+="\n};"

    return str        

def PyPrologue(outf,polynome):
    print >> outf,"""
#!/usr/bin/python

__all__=[POLYNOME,CalculateCRC]

POLYNOME=0x%04x
    """ % (polynome)

"""
def CalculateCRC(data,initial_value,final_xor_value):   ## 32Bit-Version.
    accu=initial_value

    if isinstance(data,type(str)):        
        data=map(lambda x: ord(x),list(data))

    for b in data:
        accu=((accu <<8 ) ^ CRCTab[(accu >> 24 ) ^ b ]) & 0xffffffff
    accu ^= final_xor_value
    return accu & 0xffffffff
"""


def PyEpilogue(outf):
    print >> outf,"""
def CalculateCRC(data,initial_value,final_xor_value):   # todo: Values mit Default-Parametern.
    accu=initial_value

    if isinstance(data,type(str)):        
        data=map(lambda x: ord(x),list(data))

    for b in data:
        accu=((accu <<8 ) ^ CRCTab[(accu >>8 ) ^ b ]) & 0xffff
    accu ^= final_xor_value
    return accu & 0xffff

## todo: 'Reflected' als eigenständige Funktion!!!

def test():
    sq=[0,1,2,3,4,5,6,7,8,9]

    print "MODULE-TEST for '%s'" % (os.path.basename(sys.argv[0]))
    print
    print "calculation CRC for sequence '"+repr(sq)+"'."
    print "using generator-polynome: 0x%04x." % (POLYNOME)

    crc=CalculateCRC(sq,0,0)
    print "CRC ==> 0x%04x" % (crc)

if __name__=='__main__':
    test()
    """    


def test():
    usage = "usage: %prog [options] polynome"
    desc="""Generate CRC16 functions and table.
    e.g. ITU-T V.41-CRC (x^16 + x^12 + x^15 + 1) ==> 0x1021."""

    options=[]
    args=[]

    op=OptionParser(usage=usage,version="%prog " +__version__,description=desc)

    op.add_option("-n","--name",type="string",dest="name",help="Name for output-files. if not given, write to STDOUT")
    op.add_option("-c","",action="store_const",const=0,dest="language",help="C-Language output (.c and .h-file)")
    op.add_option("-p","",action="store_const",const=1,dest="language",help="Python output (.py-file)",default=0)
    op.add_option("-x","--show-examples",action="store_true",default=False,help="show example polynomes")
##
## todo: Options for Initial-Value, Final-Xor-Value.
##       außerden 'Show-Examples' (-x --show-examples).
##       Sowie für die Test-Sequenz.
##

    (options, args) = op.parse_args()

    if options.show_examples==True: ## for pretty printing reasons...
        pass

    if len(args)==0:
        op.error("no polynome.\n\ntry '-h' or '--help' for usage.\n")

    if not args[0].startswith('0x'):
        print "\nerror: polynome must be hexadecimal ('0x').\n"
        sys.exit(2)
        
    polynome=int(args[0][2:],16)
    outf=sys.stdout
#    polynome=0x04c11db7
    table=CRCGenerateTable(polynome,options.language)

    if options.language==1:
        PyPrologue(outf,polynome)
        print >> outf,table
        PyEpilogue(outf)        
    else:
        pass


if __name__=='__main__':
    test()
