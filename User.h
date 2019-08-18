#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
	int userId;
	string login;
	string password;
	string name;
	string surname;

public:

	void setUserId(int Id);
	void setUserLogin(string newLogin);
	void setUserPassword(string newPassword);
	void setUserName(string newName);
	void setUserSurname(string newSurname);

	int getUserId();
	string getUserLogin();
	string getUserPassword();
	string getUserName();
	string getUserSurname();

};
#endif
