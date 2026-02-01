#include "sortstrategy.h"

void SortStrategy::swap(Event** e1, Event** e2)
{
    Event* temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}