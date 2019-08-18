#include "UserManager.h"


UserManager::UserManager(string fileName):usersFile(fileName)
{
    loggedUserId = 0;
    users = usersFile.loadData();
}

void UserManager::setLoggedUserId(int Id)
{
    loggedUserId = Id;
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

void UserManager::userRegistration()
{
    User user = setNewUser();
    users.push_back(user);

    usersFile.saveUser(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr->getUserId() == loggedUserId)
        {
            itr->setUserPassword(newPassword);
            usersFile.saveLoggedUser(loggedUserId, newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
}

User UserManager::setNewUser()
{
    User user;
    user.setUserId(getNewUserId());

    string login, password, name, surname;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setUserLogin(login);
    }
    while (doesExistUser(user.getUserLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setUserPassword(password);

    cout << "Podaj imie: ";
    cin >> name;
    name = HelperMethods::convertFirstLetterIntoCapitalLetterAndAnotherIntoLower(name);
    user.setUserName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    surname = HelperMethods::convertFirstLetterIntoCapitalLetterAndAnotherIntoLower(surname);
    user.setUserSurname(surname);

    return user;
}

bool UserManager::doesExistUser(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUserLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::showRegistredUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getUserId() << endl;
        cout << users[i].getUserLogin() << endl;
        cout << users[i].getUserPassword() << endl;
        cout << users[i].getUserName() << endl;
        cout << users[i].getUserSurname() << endl;
        cout << endl;
    }

    system("pause");
}

void UserManager::userLoging()
{
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    vector<User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getUserLogin() == login)
        {
            for (int chances = 3; chances > 0; chances--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << chances << ": ";
                cin >> password;

                if (itr->getUserPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = itr->getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

bool UserManager::isUserLogged()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

