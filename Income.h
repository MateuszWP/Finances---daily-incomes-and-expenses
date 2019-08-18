#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Event.h"

using namespace std;

class Income: public Event
{
    double amount;

public:
    bool setAmount(double newAmount);
    double getAmount();

    bool operator<(Income& income);
    bool operator>(const Income& income) const;
};
#endif
