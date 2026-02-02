#ifndef LASTEVENT_H
#define LASTEVENT_H
#include "sensornetwork.h"
#include "event.h"
class LastEvent
{
    public:
    LastEvent();
    ~LastEvent();
    LastEvent(const LastEvent&) = delete;
    LastEvent& operator=(const LastEvent&) = delete;
    void add(Event*);
    Event* event(int) const;
    private:
    int _capacity;
    int _size;
    Event** _events;
};

#endif