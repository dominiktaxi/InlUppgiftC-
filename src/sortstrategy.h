#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H
#include "eventlog.h"
class EventList;
class SortStrategy
{
    public:
    virtual void sortList(EventList*) = 0;
    private:
    
};

#endif