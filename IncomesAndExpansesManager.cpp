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
        income.setDate(DateManager::getCurrentDate());
    }
    else
    {
        do
        {
            cout<<endl<<"Podaj date nowego przychodu w formacie rrrr-mm-dd: ";
            cin>>date;
        }
        while(!DateManager::isDateCorrect(date));
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
        expense.setDate(DateManager::getCurrentDate());
    }
    else
    {
        do
        {
            cout<<endl<<"Podaj date nowego wydatku w formacie rrrr-mm-dd: ";
            cin>>date;
        }
        while(!DateManager::isDateCorrect(date));
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
    int monthBeginning = (DateManager::getCurrentYear()*10000) + (DateManager::getCurrentMonth()*100) +1;
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
    int currentMonthBeginning = (DateManager::getCurrentYear()*10000) + (DateManager::getCurrentMonth()*100) + 1;

    int previouslyMonthBeginning;
    if(DateManager::getCurrentMonth() == 1)
    {
        int previouslyMonth = 12;
        //format daty ma byc rrrrmmdd
        previouslyMonthBeginning = ((DateManager::getCurrentYear()-1)*10000) + (previouslyMonth *100) + 1;
    }
    else
    {
        int previouslyMonth = DateManager::getCurrentMonth() - 1;
        previouslyMonthBeginning = (DateManager::getCurrentYear()*10000) + (previouslyMonth *100) + 1;
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
    while(!DateManager::isDateCorrect(date));
    beginningDate = HelperMethods::getFullDateFromString(date);

    //ustawianie endingDate

    cout<<"Czy chcesz ustawic koniec okresu na dzien dzisiejszy?: [y] ";
    cin>> choice;
    if(choice == 'y' || choice == 'Y')
    {
        endingDate = DateManager::getCurrentDate();
    }
    else
    {
        do
        {
            cout<<"Podaj date konca okresu w formacie rrrr-mm-dd: ";
            cin>>date;
        }
        while(!DateManager::isDateCorrect(date));
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
