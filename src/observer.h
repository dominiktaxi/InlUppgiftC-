#ifndef OBSERVER_H
#define OBSERVER_H
#define MAX_OBSERVERS 10
#include "event.h"
class Observer
{
    public:
    virtual void notifyObservers(Event*) = 0;
    virtual bool alarmExists() const = 0;
    virtual int amountOfAlarms() const = 0;
    private:
};

#endif