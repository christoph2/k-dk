
#include "DS1904.h"

#define DS1904_OSC_ENABLE   ((uint8)0x0c)
#define DS1904_CLOCK_READ   ((uint8)0x66)
#define DS1904_CLOCK_WRITE  ((uint8)0x99)


/*
**
**  Device Driver for the Dallas DS1904/DS2415 (Family-Code: 0x24).
**
**  - Real-Time Clock in binary format.
**  - Resolution: 1 Second.
**
*/

void DS1904_ClockRead(OW_ConfigType const * const ConfigPtr,DS1904_ClockType * Clock)
{
    uint8 buf[5];

    OW_WriteByte(ConfigPtr,DS1904_CLOCK_READ);

    OW_ReadBlock(ConfigPtr,buf,5);
    Clock->OscEnable=(buf[0] & DS1904_OSC_ENABLE)==DS1904_OSC_ENABLE;
    Clock->UserFlags=(buf[0] & (uint8)0xf0)>>4;
    Clock->RefPoint=MAKEDWORD(MAKEWORD(buf[4],buf[3]),MAKEWORD(buf[2],buf[1]));
}


void DS1904_ClockWrite(OW_ConfigType const * const ConfigPtr,DS1904_ClockType const * Clock)
{
    OW_WriteByte(ConfigPtr,DS1904_CLOCK_WRITE);

    OW_WriteByte(ConfigPtr,(((Clock->UserFlags & (uint8)0x0f)<<4) | (Clock->OscEnable ? DS1904_OSC_ENABLE : (uint8)0x00)));
    OW_WriteByte(ConfigPtr,LOBYTE(LOWORD(Clock->RefPoint)));
    OW_WriteByte(ConfigPtr,HIBYTE(LOWORD(Clock->RefPoint)));
    OW_WriteByte(ConfigPtr,LOBYTE(HIWORD(Clock->RefPoint)));
    OW_WriteByte(ConfigPtr,HIBYTE(HIWORD(Clock->RefPoint)));
}
