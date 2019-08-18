#include "FileWithUsers.h"

FileWithUsers::FileWithUsers(string fileName)
    :TextFile(fileName)
{
}

void FileWithUsers::saveUser(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load( loadFileName() );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", HelperMethods::intToString(user.getUserId()));
    xml.AddElem("Login", user.getUserLogin());
    xml.AddElem("Password", user.getUserPassword());
    xml.AddElem("Name", user.getUserName());
    xml.AddElem("Surname", user.getUserSurname());

    xml.Save(loadFileName());
}

vector <User> FileWithUsers::loadData()
{
    vector <User> users;
    User user;
    CMarkup xml;

    string id, login, password, name, surname;
    bool fileExists = xml.Load(loadFileName());

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        //    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        while(xml.FindElem())
        {
            xml.SavePos();
            xml.IntoElem();

            xml.FindElem("UserId");
            id = xml.GetData();
            user.setUserId(HelperMethods::conversionStringToInteger(id));

            xml.FindElem("Login");
            login = xml.GetData();
            user.setUserLogin(login);

            xml.FindElem("Password");
            password = xml.GetData();
            user.setUserPassword(password);

            xml.FindElem("Name");
            name = xml.GetData();
            user.setUserName(name);

            xml.FindElem("Surname");
            surname = xml.GetData();
            user.setUserSurname(surname);

            users.push_back(user);
            xml.RestorePos();
        }
    }
    return users;
}

void FileWithUsers::saveLoggedUser(int id, string newPassword)
{
    CMarkup xml;
    string password;
    bool fileExists = xml.Load( loadFileName() );
    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();

        for(int i=0; i<id; i++)
        {
            xml.FindElem();
        }
        xml.IntoElem();
        xml.FindElem("Password");
        xml.RemoveElem();
        xml.AddElem("Password", newPassword);
        xml.Save(loadFileName());
    }
}
