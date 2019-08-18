#include "FileWithExpenses.h"

FileWithExpenses::FileWithExpenses(string fileName)
    :TextFile(fileName)
{
    lastExpenseId = 0;
}

void FileWithExpenses::saveExpense(Expense expense)
{
    CMarkup xml;
    bool fileExists = xml.Load( loadFileName() );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expenses");
    xml.IntoElem();
    xml.AddElem("ExpenseId", HelperMethods::intToString(expense.getEventId()));
    xml.AddElem("UserId", HelperMethods::intToString(expense.getUserId()));
    xml.AddElem("Date", HelperMethods::getFullDateAsStringWithDashes(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", HelperMethods::doubleToString(expense.getAmount()));

    xml.Save(loadFileName());
    lastExpenseId+=1;
}

vector <Expense> FileWithExpenses::loadData(int loggedUserId)
{
    vector <Expense> expenses;
    Expense expense;

    CMarkup xml;
    string expenseId, userId, date, item, amount;

    bool fileExists = xml.Load( loadFileName() );

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        //    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        while(xml.FindElem())
        {
            xml.SavePos();
            xml.IntoElem();

            xml.FindElem("ExpenseId");
            expenseId = xml.GetData();
            expense.setEventId(HelperMethods::conversionStringToInteger(expenseId));
            lastExpenseId = HelperMethods::conversionStringToInteger(expenseId);

            xml.FindElem("UserId");
            userId = xml.GetData();
            if(loggedUserId == HelperMethods::conversionStringToInteger(userId))
            {
                expense.setUserId(HelperMethods::conversionStringToInteger(userId));
            }
            else
            {
                xml.RestorePos();
                continue;
            }

            xml.FindElem("Date");
            date = xml.GetData();
            expense.setDate(HelperMethods::getFullDateFromString(date));

            xml.FindElem("Item");
            item = xml.GetData();
            expense.setItem(item);

            xml.FindElem("Amount");
            amount = xml.GetData();
            expense.setAmount(HelperMethods::conversionStringToDouble(amount));

            expenses.push_back(expense);
            xml.RestorePos();
        }
    }
    return expenses;
}

int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

void FileWithExpenses::setLastExpenseId(int id)
{
    lastExpenseId=id;
}
