#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Income.h"
#include "Expense.h"
#include "HelperMethods.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "DateManager.h"

#include <algorithm>
#include <functional>

using namespace std;

class IncomesAndExpansesManager
{
	vector <Income> incomes;
	vector <Expense> expenses;
	FileWithIncomes incomesFile;
	FileWithExpenses expensesFile;
    int loggedUserId;

    Income setNewIncome(int id);
    int getNewIncomeId();

    Expense setNewExpense(int id);
    int getNewExpenseId();

    vector <Income> sortIncomesFromGreater(vector <Income> tmpIncomes);
    vector <Income> sortIncomesFromLower(vector <Income> tmpIncomes);
    vector <Expense> sortExpensesFromGreater(vector <Expense> tmpExpenses);
    vector <Expense> sortExpensesFromLower(vector <Expense> tmpExpenses);

public:
    IncomesAndExpansesManager(int id, string fileNameWithIncomes, string fileNameWithExpenses);
    void addNewIncome(int id);
    void showIncomes();
    void addNewExpense(int id);
    void showExpenses();
    void setLoggedUserId(int id);
    void showBalanceForCurretnMonth();
    void shwoBalanceForPreviouslyMonth();
    void showBalanceForPeriodOfTime();
};
#endif
