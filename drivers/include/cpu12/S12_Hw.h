#if !defined(__S12_HW_H)
#define __S12_HW_H

#include "Std_Types.h"
#include "CPU_Primitives.h"
#include "ISR.h"

#define S12_REG8(mod,reg)       (BYTE_REG((mod)->BaseAddr,(reg)))
#define S12_REG16(mod,reg)      (WORD_REG((mod)->BaseAddr,(reg)))

#define S12CRG_REG8(reg)        (S12_REG8(&CRG,(reg)))
#define S12ECT_REG8(reg)        (S12_REG8(&ECT,(reg)))
#define S12ECT_REG16(reg)       (S12_REG16(&ECT,(reg)))
#define S12MEBI_REG8(reg)       (S12_REG8(&MEBI,(reg)))
#define S12MMC_REG8(reg)        (S12_REG8(&MMC,(reg)))
#define S12PIM_REG8(reg)        (S12_REG8(&PIM,(reg)))
#define S12PWM_REG8(reg)        (S12_REG8(&PWM,(reg)))
#define S12PWM_REG16(reg)       (S12_REG16(&PWM,(reg)))

#endif /* __S12_HW_H */
