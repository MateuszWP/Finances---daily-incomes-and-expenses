#include "HelperMethods.h"

string HelperMethods::intToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelperMethods::doubleToString(double number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelperMethods::convertFirstLetterIntoCapitalLetterAndAnotherIntoLower(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

int HelperMethods::conversionStringToInteger(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

double HelperMethods::conversionStringToDouble(string liczba)
{
    double liczbaDouble;
    istringstream iss(liczba);
    iss >> liczbaDouble;

    return liczbaDouble;
}

bool HelperMethods::isNumber(string number)
{
    for(int i=0; i<number.length(); i++)
    {
        if(!(number[i] >=48 && number[i] <=57) && number[i] != '.')
        {
            return false;
        }
    }
    return true;
}

int HelperMethods::downloadNumber()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

char HelperMethods::loadCharacter()
{
    string wejscie = "";
    char znak = { 0 };

    while (true)
    {
        cin.clear();
        cin.sync();
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

string HelperMethods::loadLine()
{
    string wejscie = "";
//	cin.ignore();
    getline(cin, wejscie);
    return wejscie;
}

string HelperMethods::changeCommaToDot(string number)
{
    for(int i =0; i<number.length(); i++)
    {
        if(number[i] == ',')
        {
            number[i] = '.';
            break;
        }
    }
    return number;
}

string HelperMethods::getFullDateAsStringWithDashes(int date)
{
    string dateAsString = HelperMethods::intToString(date);
    dateAsString.insert(4,"-");
    dateAsString.insert(7,"-");
    return dateAsString;
}

int HelperMethods::getFullDateFromString(string date)
{
    date.erase(4,1);
    date.erase(6,1);
    return HelperMethods::conversionStringToInteger(date);
}

char HelperMethods::selectOptionFromMainMenu()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = loadCharacter();

    return wybor;
}

char HelperMethods::selectOptionFromUserMenu()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod." << endl;
    cout << "2. Dodaj wydatek." << endl;
    cout << "3. Pokaz bilans z aktualnego miesiaca." << endl;
    cout << "4. Pokaz bilans z poprzedniego miesiaca." << endl;
    cout << "5. Pokaz bilans z wybranego okresu." << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = loadCharacter();

    return wybor;
}
