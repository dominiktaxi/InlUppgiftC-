#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H
#include "eventlog.h"
class SortStrategy
{
    public:
    virtual void sortList(EventList*) = 0;
    private:
    
};

#endif