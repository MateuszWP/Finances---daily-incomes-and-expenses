#include "User.h"


void User::setUserId(int Id)
{
	userId = Id;
}
void User::setUserLogin(string newLogin)
{
	login = newLogin;
}
void User::setUserPassword(string newPassword)
{
	password = newPassword;
}
void User::setUserName(string newName)
{
	name = newName;
}
void User::setUserSurname(string newSurname)
{
	surname = newSurname;
}

int User::getUserId()
{
	return userId;
}
string User::getUserLogin()
{
	return login;
}
string User::getUserPassword()
{
	return password;
}
string User::getUserName()
{
	return name;
}
string User::getUserSurname()
{
	return surname;
}