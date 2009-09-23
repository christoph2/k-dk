
#ifndef __CRC_H
#define __CRC_H

#include "types.h"
#include <stdio.h>

void CRCInit(uint16 data);
void CRCUpdate(uint16 data);
uint16 CRCGet(void);
uint16 CRCCalculate(uint16 genpoly,uint16 data,uint16 accum);
void CRCGenerateTable(void);

#endif /* __CRC_H   */
