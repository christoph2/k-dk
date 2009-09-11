#!/usr/bin/python
# -*- coding: latin-1 -*-

__version__="0.9.0"


COLUMNS=7
ROWS=16
DIVIDER=[ [[]] * COLUMNS for x in range(ROWS)]

from optparse import OptionParser,OptionGroup

def BuildArray():
    for row in range(16):
        for col in range(7):
            DIVIDER[row][col]=(2 ** (10+col))*(row+1)            
    

def CalculateFreqs(freq):
    arr=[[[]]*8 for x in range(16)]

    print "Freqency (Hz)"
    print "=" * 62,
    print
    for row in range(1,17):
        for col in range(1,8):            
            prescaler=2 ** (10+col-1)
            divider=prescaler*row

            arr[row-1][col-1]=divider
            DIVIDER[row-1][col-1]=divider
                               
            print "%8.2f" % (float(freq)/float(divider),),
        print    

    print DIVIDER
    """    
    print "Freqency (Hz)"
    print "=" * 145,
    for p in range(0,7):
        print
        pv=2 ** (10+p)
        print p,
        for m in range(1,17):
            fr=float(freq)/float(m*pv)            
            print "%05d %8.2f" % (pv,fr,),
    print
    """
    """
    print
    print "Cycletime (µS)"
    print "=" * 145,    
    for p in range(0,7):
        print
        pv=2 ** (10+p)
        print p,
        for m in range(1,17):
            fr=float(freq)/float(m*pv)
            inv_fr=(1/fr)*1000*1000
            print "%8.2f" % (inv_fr,),
    print
    """


def main():
    usage = "usage: %prog [options]"
    desc="""Calculate S12-RTI-Parameters"""

    options=[]
    args=[]

    op=OptionParser(usage=usage,version="%prog " +__version__,description=desc)
    op.add_option("-f","--freq",type="float",default=16.0,dest="frequency",help="Oscillator frequency in MHz (default: 16.0)")
    
    
    """
    op.add_option("-n","--name",type="string",dest="name",help="Name for output-files. if not given, write to STDOUT")
    op.add_option("-c","",action="store_const",const=0,dest="language",help="C-Language output (.c and .h-file)")
    op.add_option("-p","",action="store_const",const=1,dest="language",help="Python output (.py-file)",default=0)
    op.add_option("-x","--show-examples",action="store_true",default=False,help="show example polynomes")
    """
    (options, args) = op.parse_args()
    
    BuildArray()

    CygPathToWindows("/cygdrive/c/projekte/eOSEK/trunk/app.c")
    
##    CalculateFreqs(options.frequency*1000*1000)        

if __name__=="__main__":
    main()
    
