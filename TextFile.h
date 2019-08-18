#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile
{
	const string NAME_FILE;

public:
	TextFile(string nameFile);
	string loadFileName();
	bool isFileEmpty(fstream &textFile);
};

#endif
