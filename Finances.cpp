#include "Finances.h"

Finances::Finances(string fileName, string fileNameWithIncomes, string fileNameWithExpenses)
    :userManager(fileName)
    ,FILE_NAME_WITH_INCOMES(fileNameWithIncomes)
    ,FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)
{

}

void Finances::userRegistration()
{
    userManager.userRegistration();
}

void Finances::userLogin()
{
    userManager.userLoging();
    if (userManager.isUserLogged())
    {
        incomesAndExpansesManager = new IncomesAndExpansesManager(userManager.getLoggedUserId(), FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES);
    }
}

void Finances::logout()
{
    userManager.setLoggedUserId(0);

    delete incomesAndExpansesManager;
    incomesAndExpansesManager = NULL;
}

void Finances::changePassword()
{
    userManager.changePassword();
}

void Finances::addNewIncome()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->addNewIncome(userManager.getLoggedUserId());
    else
        cout<<"Uzytkowanik nie jest zalogowany."<<endl;
}

void Finances::addNewExpense()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->addNewExpense(userManager.getLoggedUserId());
    else
        cout<<"Uzytkowanik nie jest zalogowany."<<endl;
}

void Finances::showBalanceForCurretnMonth()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->showBalanceForCurretnMonth();
    else
        cout<<"Uzytkowanik nie jest zalogowany."<<endl;
}

void Finances::shwoBalanceForPreviouslyMonth()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->shwoBalanceForPreviouslyMonth();
    else
        cout<<"Uzytkowanik nie jest zalogowany."<<endl;
}

void Finances::showBalanceForPeriodOfTime()
{
    if(userManager.isUserLogged())
        incomesAndExpansesManager->showBalanceForPeriodOfTime();
    else
        cout<<"Uzytkowanik nie jest zalogowany."<<endl;
}

bool Finances::isUserLogged()
{
    return userManager.isUserLogged();
}
