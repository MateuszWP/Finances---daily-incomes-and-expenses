#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <string>
#include <ctime>
#include "HelperMethods.h"

using namespace std;

class DateManager
{

public:
    static int getCurrentDate();
    static int getCurrentDay();
    static int getCurrentMonth();
    static int getCurrentYear();

    static int getDayFromString(string date);
    static int getMonthFromString(string date);
    static int getYearFromString(string date);

    static bool isDateCorrect(string date);
    static bool isDateGreaterThanCurrentDate(string date);
    static bool isDayCorrect(int day, int month, int year);
    static bool isMonthCorrect(int month);
    static bool isYearCorrect(int year);
};
#endif
