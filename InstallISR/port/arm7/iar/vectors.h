#ifndef __VECTORS_H
#define __VECTORS_H

/* __irq __arm void my_handler(void); */
/*
__swi
Syntax Follows the generic syntax rules for type attributes that can be used on functions, see
Type attributes, page 229.
Description The __swi keyword declares a software interrupt function. It inserts an SVC (formerly
SWI) instruction and the specified software interrupt number to make a proper function
call. A function declared __swi accepts arguments and returns values. The __swi
keyword makes the compiler generate the correct return sequence for a specific software
interrupt function. Software interrupt functions follow the same calling convention
regarding parameters and return values as an ordinary function, except for the stack
usage.
The __swi keyword also expects a software interrupt number which is specified with
the #pragma swi_number=number directive. The swi_number is used as an
argument to the generated assembler SWC instruction, and can be used by the SVC
interrupt handler, for example SWI_Handler, to select one software interrupt function
in a system containing several such functions. Note that the software interrupt number
should only be specified in the function declaration—typically, in a header file that you
include in the source code file that calls the interrupt function—not in the function
definition.

Note: All interrupt functions must be compiled in ARM mode, except for Cortex-M.
Use either the __arm keyword or the #pragma type_attribute=__arm directive to
alter the default behavior if needed.
Example To declare your software interrupt function, typically in a header file, write for example
like this:
#pragma swi_number=0x23
__swi int swi0x23_function(int a, int b);
...
To call the function:
...
int x = swi0x23_function(1, 2); // Will be replaced by SVC 0x23, hence the linker will never try to locate swi0x23_function 
...
Somewhere in your application source code, you define your software interrupt
function:
...
__swi __arm int the_actual_swi0x23_function(int a, int b)
{
...
return 42;
}
See also Software interrupts, page 34 and Calling convention, page 97.
*/

/* neben 'ISR()' auch 'DECLARE_ISR()' definieren!!! */
#if defined(__CSMC__)
#define ISR(IsrName)                    \
@interrupt void IsrName(void)           
#elif defined(__IMAGECRAFT)
#define ISR(IsrName)                    \
#pragma interrupt_handler IsrName       \
void IsrName(void)
#elif defined(__HIWARE__)
#define ISR(IsrName)                    \
interrupt void IsrName(void)
#elif defined(__IAR_SYSTEMS_ICC__)
#define ISR(IsrName)                    \
__interrupt void IsrName(void)
#elif defined(__GNUC__)
#define ISR(IsrName) \
void IsrName(void) __attribute__((interrupt))
#endif

/* __interrupt void _ ##IsrName(void) */

#if defined(__CSMC__)
    #define II_INC_COMP     "./cosmic/vectors_comp.h"
#elif defined(__IMAGECRAFT)
    #define II_INC_COMP     "./imagecraft/vectors_comp.h"
#elif defined(__HIWARE__)
    #define II_INC_COMP     "./metrowerks/vectors_comp.h"
#elif defined(__IAR_SYSTEMS_ICC__)
    #define II_INC_COMP     "./iar/vectors_comp.h"
#elif defined(__GNUC__)
    #define II_INC_COMP     "./gcc/vectors_comp.h"
#endif

#include II_INC_COMP

#include "ISR_Cfg.h"

extern void (* const  interrupt_vectors[])(void);
typedef  void (* const IVF)(void);

#endif /* __VECTORS_H */

