#if !defined(__MEM_H)
#define __MEM_H

#include "autosar/Std_Types.h"
#include "autosar/CPU_Primitives.h"


typedef enum tagMem_StackStatus {
    MEM_STACK_OK,
    MEM_STACK_OVERFLOW,
    MEM_STACK_UNDERFLOW
} Mem_StackStatus;

void *Mem_SBrk(SizeType size);
SizeType Mem_TotalMemory(void);
SizeType Mem_MemoryLeft(void);

/*
**  todo: die beiden folgenden Funktionen für 'Mem_StackCheck()' verwenden!!!
*/
SizeType Mem_GetStackTOS(void);
SizeType Mem_GetStackBOS(void);
Mem_StackStatus Mem_StackCheck(void);

#if defined(__CSMC__)
#define Mem_GetFreePointer()    (void*)_asm("xref __memory\nldd #__memory")
#else
void *Mem_GetFreePointer(void); /* todo: als 'SizeType' deklarieren (GetFreeAddress) !!! */
#endif

/*
** Get Stack-Pointer
*/
#if defined(__IMAGECRAFT__)
#define Mem_GetStackPointer()          asm("tfr sp,d")
#elif defined(__CSMC__)
#define Mem_GetStackPointer()          ((SizeType)(_asm("tfr sp,d")))
#elif defined(__GNUC__)
#define Mem_GetStackPointer()          __asm__("tfr sp,d")
#else
SizeType Mem_GetStackPointer(void);
#endif

#endif /* __MEM_H */
