#ifndef  FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

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
#include "Income.h"

using namespace std;

class FileWithIncomes: public TextFile
{
    int lastIncomeId;
public:

    FileWithIncomes(string fileName);
    void saveIncome(Income income);
    vector <Income> loadData(int loggedUserId);

    int getLastIncomeId();
    void setLastIncomeId(int id);
};

#endif
