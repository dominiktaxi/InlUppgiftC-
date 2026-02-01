#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "sortstrategy.h"

class InsertionSort : public SortStrategy
{
    public:
    void sortList(EventList*, SORT_BY) override;
    private:
};
#endif