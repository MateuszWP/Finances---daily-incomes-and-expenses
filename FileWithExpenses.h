#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include "Markup.h"

#include "HelperMethods.h"
#include "TextFile.h"
#include "Expense.h"

using namespace std;

class FileWithExpenses: public TextFile
{
    int lastExpenseId;
public:
    FileWithExpenses(string fileName);
    void saveExpense(Expense expense);
    vector <Expense> loadData(int loggedUserId);

    int getLastExpenseId();
    void setLastExpenseId(int id);
};

#endif
