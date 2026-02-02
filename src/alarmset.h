#ifndef ALARMSET_H
#define ALARMSET_H
#include "sensornetwork.h"

class AlarmSet
{
    public:
    AlarmSet();
    ~AlarmSet();
    

    bool isInSet(int) const;
    void add(int);
    void remove(int);
    void list() const;
    private:
    int _set[MAX_SENSORS];
    int _capacity;
    int _size;
};

#endif