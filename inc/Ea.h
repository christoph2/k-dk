#ifndef	__EA_H
#define	__EA_H

#include <Ea_Cfg.h>
#include <Eep.h>

typedef struct tagEa_ConfigType {
	unsigned filler; // Hardware and/or implementation specific.
} Ea_ConfigType;

void Ea_Init(const Ea_ConfigType *ConfigPtr);
void Ea_SetMode(MemIf_ModeType Mode);
Std_ReturnType Ea_Read(uint16 BlockNumber,uint16 BlockOffset,uint8 *DataBufferPtr,uint16  Length);
Std_ReturnType Ea_Write(uint16 BlockNumber,uint8 *DataBufferPtr);
void Ea_Cancel(void);
MemIf_StatusType Ea_GetStatus(void);
MemIf_JobResultType Ea_GetJobResult(void);
Std_ReturnType Ea_InvalidateBlock(uint16 BlockNumber);
void Ea_GetVersionInfo(Std_VersionInfotype *VersionInfoPtr);
Std_ReturnType Ea_EraseImmediateBlock(uint16 BlockNumber);


#endif	// __EA_H
