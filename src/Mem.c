/*
**  todo: Vielleicht besser 'MemBase' oder 'MemLowLevel' ???
*/


#include "Mem.h"

static SizeType brk=(SizeType)NULL;

void *Mem_SBrk(SizeType size)
{
    SizeType brk_old;
    /* todo: Healthy-Check ('Mem_StackCheck()') !? */
            
    if (brk==(SizeType)NULL) {
        /* First call. */
        brk=(SizeType)Mem_GetFreePointer();
    }
        
    if ((brk+size)<Mem_GetStackBOS()) {
        brk_old=brk;
        brk=brk+size;
        return (void*)brk_old;
    } else {
        /* no memory left. */
        return (void*)NULL;   
    }
}

SizeType Mem_TotalMemory(void)
{
    SizeType total;
    total=Mem_GetStackBOS()-(SizeType)Mem_GetFreePointer(); /* check +/-1 ??? */
    
    return total;
}

SizeType Mem_MemoryLeft(void)
{
    SizeType start,left;
    
    if (brk==(SizeType)NULL) {
        start=(SizeType)Mem_GetFreePointer();
    } else {
        start=brk;
    }
    
    left=Mem_GetStackBOS()-start;
    
    return left;
}
