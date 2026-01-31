#ifndef EVENTLOG_H
#define EVENTLOG_H
#include "event.h"

struct Node
{
    Event* event;
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
int size() const;
void append(Event*);
const Event& eventByIndex(int index) const;
void set(int, Event*);
void printAll() const;
EventList* list();
private:
EventList* _list;
int _capacity;


};
#endif