#include <iostream>

#include "UserManager.h"
#include "IncomesAndExpansesManager.h"
#include "Finances.h"

using namespace std;

int main()
{
    Finances finances("users.xml", "incomes.xml", "expenses.xml");

    char wybor;

    while (true)
    {
        if (finances.isUserLogged() == false)
        {
            wybor = HelperMethods::selectOptionFromMainMenu();

            switch (wybor)
            {
            case '1':
                finances.userRegistration();
                break;
            case '2':
                finances.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            wybor = HelperMethods::selectOptionFromUserMenu();

            switch (wybor)
            {
            case '1':
                finances.addNewIncome();
                break;
            case '2':
                finances.addNewExpense();
                break;
            case '3':
                finances.showBalanceForCurretnMonth();
                break;
            case '4':
                finances.shwoBalanceForPreviouslyMonth();
                break;
            case '5':
                finances.showBalanceForPeriodOfTime();
                break;
            case '6':
                finances.changePassword();
                break;
            case '7':
                finances.logout();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
