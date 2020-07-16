#include "shrekTimeConverter.h"

#include <iostream>
#include <unistd.h>
#include <cstdint>
#include <chrono>

int main()
    {
    shrek::DateTime dt;
    std::chrono::high_resolution_clock::time_point currentPcTime
            = std::chrono::high_resolution_clock::now();

    time_t tt = std::chrono::high_resolution_clock::to_time_t(currentPcTime);
    tm local_tm = *localtime(&tt);

    dt.date.day = local_tm.tm_mday;
    //date.doy = local_tm.tm_yday;
    dt.date.month = local_tm.tm_mon + 1;
    dt.date.year = local_tm.tm_year + 1900;

    dt.time.hours = local_tm.tm_hour;
    dt.time.minutes = local_tm.tm_min;
    dt.time.seconds = local_tm.tm_sec;

    shrek::Shrek shrekDays = shrek::shreksFromEpoch(dt.date);
    shrek::Shrek shrekT = shrek::shreksFromMidnight(dt.time);
    shrek::Shrek shreksFromToday = shrek::shreksFromDateTime(dt);

    std::cout.precision(10);

    std::cout << std::fixed << "Shrek days from epoch: " << (double)shrekDays << std::endl;
    std::cout << "Shrek time from midnight: " << (double)shrekT << std::endl;
    std::cout << std::fixed << "Shrek converted from today: " << (double)shreksFromToday << std::endl;

    shrek::Shrek shreksFromDays = shrek::shreksFromDays(7);
    shrek::Shrek shreksFromMinutes = shrek::shreksFromMinutes(60);
    shrek::Shrek shreksFromSeconds = shrek::shreksFromSeconds(69);

    std::cout << std::fixed << "In a week " << (double)shreksFromDays << " shreks pass." << std::endl;
    std::cout << std::fixed << "In an hour " << (double)shreksFromMinutes << " shreks pass." << std::endl;
    std::cout << std::fixed << "In 69 seconds " << (double)shreksFromSeconds << " shreks pass." << std::endl;

    return 0;
    }
