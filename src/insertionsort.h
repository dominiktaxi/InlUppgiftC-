#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "sortstrategy.h"
class InsertionSort : public SortStrategy
{
    public:
    void sortList(EventList*) override;
    private:
    void _swap(Event**, Event**);
};

#endif