#include "IncomesAndExpansesManager.h"

IncomesAndExpansesManager::IncomesAndExpansesManager(int id, string fileNameWithIncomes, string fileNameWithExpenses)
    :loggedUserId(id)
    ,incomesFile(fileNameWithIncomes)
    ,expensesFile(fileNameWithExpenses)
{
    incomes = incomesFile.loadData(loggedUserId);
    expenses = expensesFile.loadData(loggedUserId);
}

void IncomesAndExpansesManager::addNewIncome(int id)
{
    Income income = setNewIncome(id);
    incomes.push_back(income);

    incomesFile.saveIncome(income);
//    usersFile.saveUser(user);
    cout << endl << "Przychod wpisano pomyslnie" << endl << endl;
    system("pause");
}

Income IncomesAndExpansesManager::setNewIncome(int id)
{
    Income income;
    income.setEventId(getNewIncomeId());
    income.setUserId(id);

    string date;
    string item;
    string amountAsString;
    double amount;
    char choice;

    cout<<endl<<"Ustawic dzisiejsza date przychodu?: [y] ";
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        income.setDate(getCurrentDate());
    }
    else
    {
        do
        {
            cout<<endl<<"Podaj date nowego przychodu w formacie rrrr-mm-dd: ";
            cin>>date;
        }
        while(!isDateCorrect(date));
        income.setDate(HelperMethods::getFullDateFromString(date));
    }

//    newDate.showDate();

    cout<<"Skad przychod?: ";
    cin.sync();
    getline(cin,item);
    income.setItem(item);

    cout<<"Jaka wartosc przychodu?: ";
    while(true)
    {
        cin>>amountAsString;
        amountAsString = HelperMethods::changeCommaToDot(amountAsString);
        cout<<amountAsString<<endl;
        if(HelperMethods::isNumber(amountAsString))
        {
            break;
        }
        cout<<"To nie jest liczba. Wpisz ponownie: ";
    }
    amount = HelperMethods::conversionStringToDouble(amountAsString);
    income.setAmount(amount);
    return income;
}

int IncomesAndExpansesManager::getNewIncomeId()
{
    return incomesFile.getLastIncomeId()+1;
}

void IncomesAndExpansesManager::addNewExpense(int id)
{
    Expense expense = setNewExpense(id);
    expenses.push_back(expense);

    expensesFile.saveExpense(expense);

    cout << endl << "Wydatek wpisano pomyslnie" << endl << endl;
    system("pause");

}

Expense IncomesAndExpansesManager::setNewExpense(int id)
{
    Expense expense;
    expense.setEventId(getNewExpenseId());
    expense.setUserId(id);

    string date;
    string item;
    string amountAsString;
    double amount;
    char choice;

    cout<<endl<<"Ustawic dzisiejsza date wydatku?: [y] ";
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        expense.setDate(getCurrentDate());
    }
    else
    {
        do
        {
            cout<<endl<<"Podaj date nowego wydatku w formacie rrrr-mm-dd: ";
            cin>>date;
        }
        while(!isDateCorrect(date));
        expense.setDate(HelperMethods::getFullDateFromString(date));
    }
//    newDate.showDate();
    cout<<"Skad wydatek?: ";
    cin.sync();
    getline(cin,item);
    expense.setItem(item);

    cout<<"Jaka wartosc wydatku?: ";
    while(true)
    {
        cin>>amountAsString;
        amountAsString = HelperMethods::changeCommaToDot(amountAsString);
        cout<<amountAsString<<endl;
        if(HelperMethods::isNumber(amountAsString))
        {
            break;
        }
        cout<<"To nie jest liczba. Wpisz ponownie: ";
    }
    amount = HelperMethods::conversionStringToDouble(amountAsString);
    expense.setAmount(amount);

    return expense;

}

int IncomesAndExpansesManager::getNewExpenseId()
{
    return expensesFile.getLastExpenseId()+1;
}

int IncomesAndExpansesManager::getCurrentDate()
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

int IncomesAndExpansesManager::getCurrentDay()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return time->tm_mday;
}

int IncomesAndExpansesManager::getCurrentMonth()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return (1 + time->tm_mon);
}

int IncomesAndExpansesManager::getCurrentYear()
{
    time_t currentTime = time( 0 );
    tm * time = localtime( & currentTime );
    return (1900 + time->tm_year);
}

bool IncomesAndExpansesManager::isDateCorrect(string date)
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

int IncomesAndExpansesManager::getDayFromString(string date)
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

int IncomesAndExpansesManager::getMonthFromString(string date)
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

int IncomesAndExpansesManager::getYearFromString(string date)
{
    string year;
    for(int i=0; i<4; i++)
    {
        year+=date[i];
    }
    return HelperMethods::conversionStringToInteger(year);
}

bool IncomesAndExpansesManager::isDateGreaterThanCurrentDate(string date)
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

bool IncomesAndExpansesManager::isDayCorrect(int day, int month, int year)
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

bool IncomesAndExpansesManager::isMonthCorrect(int month)
{
    if(month>=1&&month<=12)
        return true;
    else
        return false;
}

bool IncomesAndExpansesManager::isYearCorrect(int year)
{
    if(year>2000)
        return true;
    else
        return false;
}

void IncomesAndExpansesManager::showIncomes()
{
    for (int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].getEventId() << endl;
        cout << incomes[i].getUserId() << endl;
        cout << HelperMethods::getFullDateAsStringWithDashes(incomes[i].getDate())<<endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
        cout << endl;
    }
    system("pause");
}

void IncomesAndExpansesManager::showExpenses()
{
    for (int i = 0; i < expenses.size(); i++)
    {
        cout << expenses[i].getEventId() << endl;
        cout << expenses[i].getUserId() << endl;
        cout << HelperMethods::getFullDateAsStringWithDashes(expenses[i].getDate())<<endl;
        cout << expenses[i].getItem() << endl;
        cout << expenses[i].getAmount() << endl;
        cout << endl;
    }
    system("pause");
}

void IncomesAndExpansesManager::setLoggedUserId(int id)
{
    loggedUserId = id;
}

void IncomesAndExpansesManager::showBalanceForCurretnMonth()
{
    vector <Income> tmpIncomes;
    vector <Expense> tmpExpenses;
    //format daty ma byc rrrrmmdd
    int monthBeginning = (getCurrentYear()*10000) + (getCurrentMonth()*100) +1;
    int i=0;
    double incomesSum = 0, expensesSum = 0;

    tmpIncomes = sortIncomesFromGreater(tmpIncomes);
    system("cls");
    cout << " >>> PRZYCHODY UZYTKOWNIKA <<<" << endl;
    cout << "------------------------------" << endl;
    while(i < tmpIncomes.size() && tmpIncomes[i].getDate() >= monthBeginning)
    {
        cout << HelperMethods::getFullDateAsStringWithDashes(tmpIncomes[i].getDate())<<"\t";
        cout << tmpIncomes[i].getItem()<<"\t";
        cout << tmpIncomes[i].getAmount() << endl;
        incomesSum +=tmpIncomes[i].getAmount();
        i++;
    }
    cout<<endl<<"Suma przychodow z biezacego miesiaca: "<<incomesSum<<endl;
    cout<<endl<<endl;

    i=0;
    tmpExpenses = sortExpensesFromGreater(tmpExpenses);
    cout << " >>> WYDATKI UZYTKOWNIKA <<<" << endl;
    cout << "----------------------------" << endl;
    while(i < tmpExpenses.size() && tmpExpenses[i].getDate() >= monthBeginning)
    {
        cout << HelperMethods::getFullDateAsStringWithDashes(tmpExpenses[i].getDate())<<"\t";
        cout << tmpExpenses[i].getItem()<<"\t";
        cout << tmpExpenses[i].getAmount() << endl;
        expensesSum += tmpExpenses[i].getAmount();
        i++;
    }
    cout<<endl<<"Suma wydatkow z biezacego miesiaca: "<<expensesSum<<endl;
    cout<<endl<<endl;

    cout<<"Roznica przychodow i wydatkow: "<<incomesSum + expensesSum<<endl;

    system("pause");
}

void IncomesAndExpansesManager::shwoBalanceForPreviouslyMonth()
{
    vector <Income> tmpIncomes;
    vector <Expense> tmpExpenses;
    //format daty ma byc rrrrmmdd
    int currentMonthBeginning = (getCurrentYear()*10000) + (getCurrentMonth()*100) + 1;

    int previouslyMonthBeginning;
    if(getCurrentMonth() == 1)
    {
        int previouslyMonth = 12;
        //format daty ma byc rrrrmmdd
        previouslyMonthBeginning = ((getCurrentYear()-1)*10000) + (previouslyMonth *100) + 1;
    }
    else
    {
        int previouslyMonth = getCurrentMonth() - 1;
        previouslyMonthBeginning = (getCurrentYear()*10000) + (previouslyMonth *100) + 1;
    }

    int i=0;
    double incomesSum = 0, expensesSum = 0;

    tmpIncomes = sortIncomesFromGreater(tmpIncomes);
    system("cls");
    cout << " >>> PRZYCHODY UZYTKOWNIKA <<<" << endl;
    cout << "------------------------------" << endl;
    while(i < tmpIncomes.size() && tmpIncomes[i].getDate() >= previouslyMonthBeginning)
    {
        if(tmpIncomes[i].getDate() < currentMonthBeginning)
        {
            cout << HelperMethods::getFullDateAsStringWithDashes(tmpIncomes[i].getDate())<<"\t";
            cout << tmpIncomes[i].getItem()<<"\t";
            cout << tmpIncomes[i].getAmount() << endl;
            incomesSum +=tmpIncomes[i].getAmount();
        }
        i++;
    }
    cout<<endl<<"Suma przychodow z poprzedniego miesiaca: "<<incomesSum<<endl;

    cout<<endl<<endl;
    i=0;
    tmpExpenses = sortExpensesFromGreater(tmpExpenses);
    cout << " >>> WYDATKI UZYTKOWNIKA <<<" << endl;
    cout << "----------------------------" << endl;
    while(i < tmpExpenses.size() && tmpExpenses[i].getDate() >= previouslyMonthBeginning)
    {
        if(tmpExpenses[i].getDate() < currentMonthBeginning)
        {
            cout << HelperMethods::getFullDateAsStringWithDashes(tmpExpenses[i].getDate())<<"\t";
            cout << tmpExpenses[i].getItem()<<"\t";
            cout << tmpExpenses[i].getAmount() << endl;
            expensesSum += tmpExpenses[i].getAmount();
        }
        i++;
    }
    cout<<endl<<"Suma wydatkow z poprzedniego miesiaca: "<<expensesSum<<endl;
    cout<<endl<<endl;

    cout<<"Roznica przychodow i wydatkow: "<<incomesSum + expensesSum<<endl;

    system("pause");
}

void IncomesAndExpansesManager::showBalanceForPeriodOfTime()
{
    vector <Income> tmpIncomes;
    vector <Expense> tmpExpenses;
    string date;
    int beginningDate, endingDate;
    char choice;
    int i=0;
    double incomesSum = 0, expensesSum = 0;
    //ustawianie beginningDate
    do
    {
        cout<<"Podaj date poczatku okresu z ktorego chcesz raport formacie rrrr-mm-dd: ";
        cin>>date;
    }
    while(!isDateCorrect(date));
    beginningDate = HelperMethods::getFullDateFromString(date);

    //ustawianie endingDate

    cout<<"Czy chcesz ustawic koniec okresu na dzien dzisiejszy?: [y] ";
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        endingDate = getCurrentDate();
    }
    else
    {
        do
        {
            cout<<"Podaj date konca okresu w formacie rrrr-mm-dd: ";
            cin>>date;
        }
        while(!isDateCorrect(date));
        endingDate = HelperMethods::getFullDateFromString(date);
    }
//    cout<<"Poczatek zakresu: "<<beginningDate<<"\tkoniec zakresu: "<<endingDate<<endl;

    tmpIncomes = sortIncomesFromGreater(tmpIncomes);
    system("cls");
    cout << " >>> PRZYCHODY UZYTKOWNIKA <<<" << endl;
    cout << "------------------------------" << endl;
    while(i < tmpIncomes.size() && tmpIncomes[i].getDate() >= beginningDate)
    {
        if(tmpIncomes[i].getDate() <= endingDate)
        {
            cout << HelperMethods::getFullDateAsStringWithDashes(tmpIncomes[i].getDate())<<"\t";
            cout << tmpIncomes[i].getItem()<<"\t";
            cout << tmpIncomes[i].getAmount() << endl;
            incomesSum +=tmpIncomes[i].getAmount();
        }
        i++;
    }
    cout<<endl<<"Suma przychodow z wybranego zakresu czasu: "<<incomesSum<<endl;
    cout<<endl<<endl;

    i=0;
    tmpExpenses = sortExpensesFromGreater(tmpExpenses);
    cout << " >>> WYDATKI UZYTKOWNIKA <<<" << endl;
    cout << "----------------------------" << endl;
    while(i < tmpExpenses.size() && tmpExpenses[i].getDate() >= beginningDate)
    {
        if(tmpExpenses[i].getDate() <= endingDate)
        {
            cout << HelperMethods::getFullDateAsStringWithDashes(tmpExpenses[i].getDate())<<"\t";
            cout << tmpExpenses[i].getItem()<<"\t";
            cout << tmpExpenses[i].getAmount() << endl;
            expensesSum += tmpExpenses[i].getAmount();
        }
        i++;
    }
    cout<<endl<<"Suma wydatkow z wybranego zakresu czasu: "<<expensesSum<<endl;
    cout<<endl<<endl;

    cout<<"Roznica przychodow i wydatkow: "<<incomesSum + expensesSum<<endl;

    system("pause");
}

vector <Income> IncomesAndExpansesManager::sortIncomesFromGreater(vector <Income> tmpIncomes)
{

    tmpIncomes = incomes;
    sort(tmpIncomes.begin(), tmpIncomes.end(),greater<Income>());
    return tmpIncomes;
}

vector <Income> IncomesAndExpansesManager::sortIncomesFromLower(vector <Income> tmpIncomes)
{

    tmpIncomes = incomes;
    sort(tmpIncomes.begin(), tmpIncomes.end());
    return tmpIncomes;
}

vector <Expense> IncomesAndExpansesManager::sortExpensesFromGreater(vector <Expense> tmpExpenses)
{
    tmpExpenses = expenses;
    int i;
    sort(tmpExpenses.begin(), tmpExpenses.end(),greater<Expense>());
    return tmpExpenses;
}

vector <Expense> IncomesAndExpansesManager::sortExpensesFromLower(vector <Expense> tmpExpenses)
{

    tmpExpenses = expenses;
    sort(tmpExpenses.begin(), tmpExpenses.end());
    return tmpExpenses;
}
