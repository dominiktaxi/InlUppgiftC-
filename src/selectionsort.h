#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include "sortstrategy.h"
class SelectionSort : public SortStrategy
{
    public:
    virtual void sortList(EventList*, SORT_BY) override;
    private:
};

#endif