#ifndef EVENT_H
#define EVENT_H

#include <iostream>

using namespace std;

class Event
{
protected:
    int eventId;
    int userId;
    int date;
    string item;

public:

    void setEventId(int id);
    void setUserId(int id);
    void setDate(int newDate);
    void setItem(string newItem);

    int getEventId();
    int getUserId();
    int getDate();
    string getItem();
};
#endif
