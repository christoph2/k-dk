/*
 * cpu_primitives_arm.h - Generic ARM Cortex-M CPU Primitives for GCC
 */
#ifndef __CPU_PRIMITIVES_ARM_H
#define __CPU_PRIMITIVES_ARM_H

#include <stdint.h>

#include <stm32l4xx.h>

#define __FPU_PRESENT 1U
#define __FPU_USED    1U


#if defined(__CORTEX_M)
#if (__CORTEX_M == 0)
#include "core_cm0.h"
#elif (__CORTEX_M == 3)
#include "core_cm3.h"
#elif (__CORTEX_M == 4)
#include "core_cm4.h"
#elif (__CORTEX_M == 7)
#include "core_cm7.h"
#else
#error "Unsupported Cortex-M core"
#endif
#else
#error "__CORTEX_M not defined"
#endif

/*
**  Generic Cortex-M CPU Primitives
*/

/* Power Management */
#define CPU_ENTER_POWERDOWN_MODE()                                                                                     \
    do {                                                                                                               \
        __DSB();                                                                                                       \
        __WFI();                                                                                                       \
        __ISB();                                                                                                       \
    } while (0)

#define CPU_LEAVE_POWERDOWN_MODE() /* Wake up by interrupt */

/* Watchdog Timer (optional, platform-specific) */
#ifdef IWDG
#define CPU_DISABLE_WATCHDOG_TIMER()                                                                                   \
    do {                                                                                                               \
        IWDG->KR = 0xAAAA;                                                                                             \
    } while (0)
#else
#define CPU_DISABLE_WATCHDOG_TIMER() /* Not available */
#endif

/* Software Interrupt - Use PendSV */
#define CPU_SOFTWARE_INTERRUPT()                                                                                       \
    do {                                                                                                               \
        SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;                                                                           \
        __DSB();                                                                                                       \
        __ISB();                                                                                                       \
    } while (0)

/* Return from Interrupt */
#define CPU_RETURN_FROM_INTERRUPT() __asm__ __volatile__("bx lr" : : : "memory")

/* Debugging */
#define CPU_BREAKPOINT() __BKPT(0)

/* No Operation */
#define CPU_NO_OPERATION() __NOP()

/* Interrupt Control - Use BASEPRI for OSEK compliance */
#define CPU_DISABLE_ALL_INTERRUPTS()                                                                                   \
    do {                                                                                                               \
        __set_BASEPRI(0xFF);                                                                                           \
        __DSB();                                                                                                       \
        __ISB();                                                                                                       \
    } while (0)

#define CPU_ENABLE_ALL_INTERRUPTS()                                                                                    \
    do {                                                                                                               \
        __set_BASEPRI(0);                                                                                              \
        __DSB();                                                                                                       \
        __ISB();                                                                                                       \
    } while (0)

#define CPU_INTERRUPTS_DISABLED() (__get_BASEPRI() != 0)

/* Interrupt State Management */
#define CPU_SAVE_AND_DISABLE_INTERRUPTS(state)                                                                         \
    do {                                                                                                               \
        (state) = __get_BASEPRI();                                                                                     \
        __set_BASEPRI(0xFF);                                                                                           \
        __DSB();                                                                                                       \
        __ISB();                                                                                                       \
    } while (0)

#define CPU_RESTORE_INTERRUPTS(state)                                                                                  \
    do {                                                                                                               \
        __set_BASEPRI(state);                                                                                          \
        __DSB();                                                                                                       \
        __ISB();                                                                                                       \
    } while (0)

/* Memory Barriers */
#define CPU_MEMORY_BARRIER() __DMB()
#define CPU_COMPILER_BARRIER() __asm__ __volatile__("" : : : "memory")
#define CPU_DATA_SYNC_BARRIER() __DSB()
#define CPU_INSTRUCTION_SYNC_BARRIER() __ISB()

/* Cache Operations (optional, platform-specific) */
#define CPU_INVALIDATE_ICACHE() /* Optional */
#define CPU_INVALIDATE_DCACHE() /* Optional */
#define CPU_FLUSH_DCACHE() /* Optional */

/* System Control */
#define CPU_SYSTEM_RESET()                                                                                             \
    do {                                                                                                               \
        __DSB();                                                                                                       \
        SCB->AIRCR = (0x5FA << SCB_AIRCR_VECTKEY_Pos) | SCB_AIRCR_SYSRESETREQ_Msk;                                     \
        __DSB();                                                                                                       \
        while (1)                                                                                                      \
            ;                                                                                                          \
    } while (0)

/* Performance Monitoring */
#define CPU_ENABLE_CYCLE_COUNT()                                                                                       \
    do {                                                                                                               \
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;                                                                \
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;                                                                           \
    } while (0)

#define CPU_GET_CYCLE_COUNT() (DWT->CYCCNT)
#define CPU_RESET_CYCLE_COUNT() (DWT->CYCCNT = 0)

#endif /* __CPU_PRIMITIVES_ARM_H */
