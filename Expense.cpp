#include "Expense.h"

void Expense::setAmount(double newAmount)
{
    if(newAmount > 0)
    {
        newAmount *= -1;
        amount = newAmount;
    }
    else
    {
        amount = newAmount;
    }
}

double Expense::getAmount()
{
    return amount;
}

bool Expense::operator<(Expense& expense)
{
    return (date < expense.getDate());
}

bool Expense::operator>(const Expense& expense)const
{
    return (date > expense.date);
}
