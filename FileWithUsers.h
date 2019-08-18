#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include "Markup.h"

#include "HelperMethods.h"
#include "TextFile.h"
#include "User.h"

using namespace std;

class FileWithUsers: public TextFile
{
public:
    FileWithUsers(string fileName);
    void saveUser(User user);
    vector <User> loadData();
    void saveLoggedUser(int id, string newPassword);
};

#endif
