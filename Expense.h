#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Event.h"

using namespace std;

class Expense: public Event
{
    double amount;

public:
    void setAmount(double newAmount);

    double getAmount();

    bool operator<(Expense& expense);
    bool operator>(const Expense& expense) const;
};
#endif
