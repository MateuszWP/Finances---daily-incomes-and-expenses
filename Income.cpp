#include "Income.h"

bool Income::setAmount(double newAmount)
{
    if(newAmount >0)
    {
        amount=newAmount;
        return true;
    }
    else
    {
        cout<<"Przychod musi byc dodatni"<<endl;
        return false;
    }
}

double Income::getAmount()
{
    return amount;
}

bool Income::operator<(Income& income)
{
    return (date < income.getDate());
}

bool Income::operator>(const Income& income)const
{
    return (date > income.date);
}
