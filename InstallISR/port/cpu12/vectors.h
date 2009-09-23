#ifndef __VECTORS_H
#define __VECTORS_H

/* neben 'ISR()' auch 'DECLARE_ISR()' definieren!!! */
#if defined(__CSMC__)
#define ISR(IsrName) 			\
@interrupt void IsrName(void)		
#elif defined(__IMAGECRAFT)
#define ISR(IsrName) 			\
#pragma interrupt_handler IsrName 	\
void IsrName(void)
#elif defined(__HIWARE__)
#define ISR(IsrName) 			\
interrupt void IsrName(void)
#elif defined(__IAR_SYSTEMS_ICC__)
#define ISR(IsrName) 			\
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

