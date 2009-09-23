
#include "ISR.h"

DECLARE_ISR(SCI0Handler);

int main(int argc,char **argv)
{
    return 0;   
}


ISR(SCI0Handler)
{
    unsigned i;
    
    i++;
}


