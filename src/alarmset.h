#ifndef ALARMSET_H
#define ALARMSET_H
#include "sensornetwork.h"
#include "observer.h"

class AlarmSet : public Observer
{
    public:
    AlarmSet();
    void notifyObservers(Event*) override;
    bool isInSet(int) const;
    void add(int);
    void remove(int);
    void list() const;
    bool alarmExists() const;
    int amountOfAlarms() const;
    private:
    int _set[MAX_SENSORS];
    int _capacity;
    int _amount;
};

#endif