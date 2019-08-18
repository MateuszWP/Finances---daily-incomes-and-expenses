#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class HelperMethods
{
public:
    static string intToString(int number);
    static string doubleToString(double number);
    static int conversionStringToInteger(string liczba);
    static double conversionStringToDouble(string liczba);

    static bool isNumber(string number);
    static int downloadNumber();
    static char loadCharacter();
    static string loadLine();

    static string convertFirstLetterIntoCapitalLetterAndAnotherIntoLower(string tekst);
    static string changeCommaToDot(string number);
    static string getFullDateAsStringWithDashes(int date);
    static int getFullDateFromString(string date);
    static char selectOptionFromMainMenu();
    static char selectOptionFromUserMenu();

};
#endif
