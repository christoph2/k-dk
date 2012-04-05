/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#include "Cal.h"

/*
**  Local Defines.
*/
#define SECS_PER_MINUTE ((uint32)60UL)
#define SECS_PER_HOUR   ((uint32)SECS_PER_MINUTE * 60UL)
#define SECS_PER_DAY    ((uint32)SECS_PER_HOUR * 24UL)
#define SECS_PER_YEAR   ((uint32)SECS_PER_DAY * 365UL)

#define EPOCH_YEAR      ((uint16)1970U)

static const char Tab_MonthNames[12][4] = {
    "JAN", "FEB", "MAR",
    "APR", "MAY", "JUN",
    "JUL", "AUG", "SEP",
    "OCT", "NOV", "DEC"
};

static const char Tab_DayNames[7][4] = {
    "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

/*
**  Local Constants.
*/
static const uint8 Tab_DaysInMonth[12] = {
    (uint8)31, (uint8)28, (uint8)31, (uint8)30, (uint8)31, (uint8)30,
    (uint8)31, (uint8)31, (uint8)30, (uint8)31, (uint8)30, (uint8)31
};

static const uint16 Tab_DaysBeforeMonth[] = {
    (uint16)0u,   (uint16)31u,  (uint16)59u,  (uint16)90u,  (uint16)120u, (uint16)151u,
    (uint16)181u, (uint16)212u, (uint16)243u, (uint16)273u, (uint16)304u, (uint16)334u
};

typedef struct tagDate {
    uint16  year;
    uint8   month;
    uint8   day;
    uint8   hour;
    uint8   min;
    uint8   sec;
} Date;

void To_UTime(uint32 utime, Date * date);


/*
** Global Functions.
*/
boolean Cal_IsLeapYear(uint16 year)
{
    return ((year % 0x0004u) == 0x0000u) && ((year % 0x0064u) != 0x0000u )  || ((year % 0x0190u) == 0x0000u );
}


uint8 Cal_DaysInMonth(uint16 year, uint8 month)
{
    uint8 days;

    if ((month == (uint8)0) || (month > (uint8)12)) {
        return (uint8)0;
    }

    days = Tab_DaysInMonth[month - 1];

    if ((month == CAL_FEB) && (Cal_IsLeapYear(year))) {
        days++;
    }

    return days;
}


uint16 Cal_DaysBeforeMonth(uint16 year, uint8 month)
{
    uint16 days;

    if ((month == (uint8)0) || (month > (uint8)12)) {
        return (uint16)0xffffU;
    }

    days = Tab_DaysBeforeMonth[month - 1];

    if ((month > CAL_FEB) && (Cal_IsLeapYear(year))) {
        days++;
    }

    return days;
}


void To_UTime(uint32 utime, Date * date)
{
    uint32  remaining_seconds  = utime;
    uint16  year               = EPOCH_YEAR;
    boolean leap_year;

/*    uint8 quarter;    */

    while (remaining_seconds >= SECS_PER_YEAR) {
        remaining_seconds -= SECS_PER_YEAR;
        year++;
        leap_year = Cal_IsLeapYear(year);

        if (leap_year) {
            if (remaining_seconds >= SECS_PER_DAY) {
                remaining_seconds -= SECS_PER_DAY;
            }
        }
    }

    date->year = year;

/*    Tab_DaysInMonth   */
/*    quarter=(uint8)(remaining_seconds >> 23); */
    /* todo: Adjust slope/gradient */
    /* 0x14B */
#if 0
    month = (uint8)((HIWORD(remaining_seconds)) >> 5);    /* very raw estimation of month. */
#endif

    date->month = CAL_JAN;

    while (remaining_seconds >= Tab_DaysInMonth[date->month - 1] * SECS_PER_DAY) {
        remaining_seconds -= Tab_DaysInMonth[date->month - 1] * SECS_PER_DAY;
#if 0

        if ((date->month == CAL_FEB) && (leap_year == TRUE)) {
            if (remaining_seconds >= SECS_PER_DAY) {
                remaining_seconds -= SECS_PER_DAY;
            }
        }

#endif
        date->month++;
    }

    date->day = (uint8)1;

    while (remaining_seconds >= SECS_PER_DAY) {
        remaining_seconds -= SECS_PER_DAY;
        date->day++;
    }

/* Ab hhier 16-Bit-Arithmetrik!!! */
    date->hour = (uint8)0;

    while (remaining_seconds >= SECS_PER_HOUR) {
        remaining_seconds -= SECS_PER_HOUR;
        date->hour++;
    }

    date->min = (uint8)0;

    while (remaining_seconds >= SECS_PER_MINUTE) {
        remaining_seconds -= SECS_PER_MINUTE;
        date->min++;
    }

    date->sec = (uint8)remaining_seconds;
}


void CalTest(void);


void CalTest(void)
{
    Date date;

    To_UTime(100000000, &date);         /*	3. März 1973 09:46:40       */
    To_UTime(1234567890, &date);        /* 13. Februar 2009 23:31:30    */
    To_UTime(1000000000, &date);        /* 9. September 2001 01:46:40   */
    To_UTime(2222222222, &date);        /* 2. Juni 2040 02:57:02        */
    To_UTime(1259050546, &date);
    To_UTime(1259354756, &date);
    To_UTime(0xffffffff, &date);     /* 7. Februar 2106 05:28:16     */
}


