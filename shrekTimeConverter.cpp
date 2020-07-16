#include "shrekTimeConverter.h"

#include <exception>
#include <stdexcept>
#include <math.h>

using namespace shrek;

Date shrek::shrekEpoch()
    {
    Date shrekEpoch;
    shrekEpoch.year = 2001;
    shrekEpoch.month = 4;
    shrekEpoch.day = 22;
    }

bool shrek::isLeapYear(int year)
    {
    return year % 4 == 0;
    }

Shrek shrek::shreksFromEpoch(Date date)
    {
    Date epoch = shrekEpoch();

    const int* const daysPerMonth = isLeapYear(date.year)
                                    ? daysInLeapMonth : daysInMonth;

    int daysSinceEpoch = 0; // The number of days passed since epoch

    // Input validation
    if(date.month  == 0  ||  date.month  > 12 ||
       date.day    == 0  ||  date.day    > daysPerMonth[date.month-1])
      throw std::runtime_error("Invalid date");

    // Count the leap days
    int yearsFromEpoch = date.year - epoch.year;

    if(yearsFromEpoch >= 0)
        {
        for( int leapDaysIndex = epoch.year; leapDaysIndex <= date.year;  leapDaysIndex++ )
            {
            if(leapDaysIndex == date.year)
                {
                if(isLeapYear(leapDaysIndex) && date.month > 2)
                    ++daysSinceEpoch;
                }
            else
                {
                  if(isLeapYear(leapDaysIndex) )
                    ++daysSinceEpoch;
                }
            }
        for( int monthsIndex = 1;  monthsIndex < date.month;  monthsIndex++ )
          daysSinceEpoch += daysPerMonth[ monthsIndex - 1 ];

        int daysComputedSinceEpoch = (yearsFromEpoch) * 365 + daysSinceEpoch + date.day;
        return static_cast<Shrek>(daysComputedSinceEpoch) * shreksInADay;
        }
    else
        {
        for( int leapDaysIndex = date.year; leapDaysIndex <= epoch.year;  leapDaysIndex++ )
            {
            if(leapDaysIndex == epoch.year)
                ++daysSinceEpoch;
            else
                {
                  if(isLeapYear(leapDaysIndex) )
                    ++daysSinceEpoch;
                }
            }

        for( int monthsIndex = date.month;  monthsIndex < 13;  monthsIndex++ )
          daysSinceEpoch += daysPerMonth[ monthsIndex - 1 ];
        daysSinceEpoch -= date.day;
        daysSinceEpoch += 22 + daysInMonth[2] + daysInMonth[1] + daysInMonth[0];

        int daysComputedSinceEpoch = (yearsFromEpoch) * 365 + daysSinceEpoch;
        return static_cast<Shrek>(daysComputedSinceEpoch) * shreksInADay * -1;
        }
    }

Shrek shrek::shreksFromMidnight(Time time)
    {
    double t = time.ms;
    t += time.seconds*1000;
    t += time.minutes*1000*60;
    t += time.hours*1000*60*60;
    return t/shrekUnitMs;
    }

Shrek shrek::shreksFromDateTime(DateTime dt)
    {
    Shrek shreks = shreksFromEpoch(dt.date);
    if(shreks < 0)
        {
        Time newT;
        newT.hours = 24 - dt.time.hours;
        newT.minutes = 60 - dt.time.minutes;
        newT.seconds = 60 - dt.time.seconds;
        newT.ms = 1000 - dt.time.ms;
        shreks += shreksFromMidnight(newT);
        }
    else
        shreks += shreksFromMidnight(dt.time);

    return shreks;
    }

Shrek shrek::shreksFromDays(int days)
    {
    return days*shreksInADay;
    }

Shrek shrek::shreksFromHours(int hours)
    {
    return hours/shrekUnitH;
    }

Shrek shrek::shreksFromMinutes(int minutes)
    {
    return minutes/shrekUnitM;
    }

Shrek shrek::shreksFromSeconds(int seconds)
    {
    return seconds/shrekUnitS;
    }

Shrek shrek::shreksFromMs(int ms)
    {
    return ms/shrekUnitMs;
    }
