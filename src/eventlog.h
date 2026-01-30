#ifndef EVENTLOG_H
#define EVENTLOG_H
#include "event.h"
struct Node
{
    Event::TYPE type;
    struct Node* next;
};

struct EventList
{
    Node* head;
    Node* tail;
    int size;
};

class EventLog
{
public:
EventLog(int);
~EventLog();
void create();
int size() const;
void append(Event::TYPE);
Event::TYPE getEvent(int index);
void set(int, Event::TYPE);

private:
EventList* _list;
int _capacity;

};
#endif