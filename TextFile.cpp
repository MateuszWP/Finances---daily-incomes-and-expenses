#include "TextFile.h"

TextFile::TextFile(string nameFile):NAME_FILE(nameFile)
{
}
string TextFile::loadFileName()
{
    return NAME_FILE;
}

bool TextFile::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    int position = textFile.tellg();
    if (position == 0)
    {
        return true;
    }
    else
        return false;
}
