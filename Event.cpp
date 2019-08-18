#include "Event.h"

void Event::setEventId(int id)
{
    eventId=id;
}
void Event::setUserId(int id)
{
    userId=id;
}
void Event::setDate(int newDate)
{
    date=newDate;
}
void Event::setItem(string newItem)
{
    item=newItem;
}

int Event::getEventId()
{
    return eventId;
}
int Event::getUserId()
{
    return userId;
}
int Event::getDate()
{
    return date;
}
string Event::getItem()
{
    return item;
}

