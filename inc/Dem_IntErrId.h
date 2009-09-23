#ifndef __DEM_INTERRID_H
#define	__DEM_INTERRID_H

/* EEPROM-Abstraction. */
#define	EA_E_PARAM_CONFIG       ((uint8)0x01)
#define	EA_E_INVALID_BLOCK_NO   ((uint8)0x02)

/* MCU-Driver */
    /* Development */
#define MCU_E_PARAM_CONFIG      ((uint8)0x0A)
#define MCU_E_PARAM_CLOCK       ((uint8)0x0B)
#define MCU_E_PARAM_MODE        ((uint8)0x0C)
#define MCU_E_PARAM_RAMSECTION  ((uint8)0x0D)
#define MCU_E_PLL_NOT_LOCKED    ((uint8)0x0E)
#define MCU_E_UININIT           ((uint8)0x0F)
    /* Production */
/* #define MCU_E_CLOCK_FAILURE     *** ASSIGNED BY DEM *** */

#endif	/* __DEM_INTERRID_H */
