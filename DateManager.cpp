#include "DateManager.h"

int DateManager::getCurrentDate()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );

    int currentYear = getCurrentYear();
    int currentMonth = getCurrentMonth();
    int currentDay = getCurrentDay();

    int currentDate = (currentYear*10000) + (currentMonth*100) + currentDay;
//   cout << "Aktualna data:\t" << currentYear << "-" << currentMonth << "-" << currentDay << endl;
//   cout << "Aktualna data w int: " << currentDate << endl;

    return currentDate;
}

int DateManager::getCurrentDay()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return time->tm_mday;
}

int DateManager::getCurrentMonth()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return (1 + time->tm_mon);
}

int DateManager::getCurrentYear()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return (1900 + time->tm_year);
}

int DateManager::getDayFromString(string date)
{
    string day;
    if(date[8]!='0')
    {
        day+=date[8];
        day+=date[9];
    }
    else
        day=date[9];
    return HelperMethods::conversionStringToInteger(day);
}

int DateManager::getMonthFromString(string date)
{
    string month;

    if(date[5]!='0')
    {
        month+=date[5];
        month+=date[6];
    }
    else
        month=date[6];
    return HelperMethods::conversionStringToInteger(month);
}

int DateManager::getYearFromString(string date)
{
    string year;
    for(int i=0; i<4; i++)
    {
        year+=date[i];
    }
    return HelperMethods::conversionStringToInteger(year);
}

bool DateManager::isDateCorrect(string date)
{
    int day, month, year;

    year = getYearFromString(date);
    month = getMonthFromString(date);
    day = getDayFromString(date);

    if(isDayCorrect(day,month,year) && isMonthCorrect(month) && isYearCorrect(year) && !isDateGreaterThanCurrentDate(date) && date.length()==10)
    {
        //     cout<<"Data jest poprawana"<<endl;
        return true;
    }
    else
    {
        cout<<"Zla data"<<endl;
        return false;
    }
}

bool DateManager::isDateGreaterThanCurrentDate(string date)
{

//   int dateAsInt = getFullDateFromString(date);
    if(HelperMethods::getFullDateFromString(date) > getCurrentDate())
    {
        cout<<"Data wieksza od obecnej"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool DateManager::isDayCorrect(int day, int month, int year)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if(day>=1&&day<=31)
            return true;
        break;
    }
    case 2:
    {
        if(((year%4==0)&&(year%100!=0))||(year%100==0))
        {
            if(day>=1&&day<=29)
                return true;
        }
        else
        {
            if(day>=1&&day<=28)
                return true;
        }
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if(day>=1&&day<=30)
            return true;
        break;
    }
    }
    return false;
}

bool DateManager::isMonthCorrect(int month)
{
    if(month>=1&&month<=12)
        return true;
    else
        return false;
}

bool DateManager::isYearCorrect(int year)
{
    if(year>2000)
        return true;
    else
        return false;
}
