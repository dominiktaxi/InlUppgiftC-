#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H
#include "eventlog.h"
#include <vector>
class EventList;
class SortStrategy
{
    public:
    enum class SORT_BY
    {
        TIMESTAMP,
        READING,
        ID
    };
    virtual void sortList(EventList*, SORT_BY) = 0;
    protected:
    void swap(Event** e1, Event** e2);
    private:
    
};

#endif