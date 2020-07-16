#ifndef SHREK_TIME_CONVERTER_H
#define SHREK_TIME_CONVERTER_H

namespace shrek
  {
  using Shrek = double;

  struct Date
      {
          int year;
          int month;
          int day;
      };

  struct Time
      {
          int hours;
          int minutes;
          int seconds;
          int ms;
      };

  struct DateTime
      {
          Date date;
          Time time;
      };

  static const Shrek shreksInADay = 15.157894736842104;
  static const double shrekUnitH = 1.35;
  static const double shrekUnitM = 95.;
  static const double shrekUnitS = 5700.;
  static const double shrekUnitMs = 5700000.;
  ///@note Shrek epoch is 22 april 2001
  Date shrekEpoch();
  bool isLeapYear(int year);

  Shrek shreksFromEpoch(Date date);
  Shrek shreksFromMidnight(Time time);
  Shrek shreksFromDateTime(DateTime dt);
  Shrek shreksFromDays(int days);
  Shrek shreksFromHours(int hours);
  Shrek shreksFromMinutes(int minutes);
  Shrek shreksFromSeconds(int seconds);
  Shrek shreksFromMs(int ms);

  static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  static const int daysInLeapMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  }

#endif // SHREK_TIME_CONVERTER_H
