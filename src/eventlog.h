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
    EventLog(const EventLog&) = delete;
    EventLog& operator=(const EventLog&) = delete;
    int size() const;
    void append(Event*);
    const Event& getEventByIndex(int index) const;
    void set(int, Event*);
    Event event(int) const;
    EventList* list();
    
    private:
    EventList* _list;
    int _capacity;


};
#endif