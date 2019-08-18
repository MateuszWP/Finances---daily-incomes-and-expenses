#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

#include "UserManager.h"
#include "IncomesAndExpansesManager.h"

using namespace std;

class Finances
{
	UserManager userManager;
	IncomesAndExpansesManager *incomesAndExpansesManager;

	string const FILE_NAME_WITH_INCOMES;
	string const FILE_NAME_WITH_EXPENSES;

public:
    Finances(string fileName, string fileNameWithIncomes, string fileNameWithExpenses);
    void userRegistration();
    void userLogin();
    void logout();
    void changePassword();
    void addNewIncome();
    void addNewExpense();
    void showBalanceForCurretnMonth();
    void shwoBalanceForPreviouslyMonth();
    void showBalanceForPeriodOfTime();
    bool isUserLogged();
};

#endif
