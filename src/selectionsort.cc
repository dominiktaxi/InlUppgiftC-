#include "selectionsort.h"
#include "eventlog.h"
#include "utils.h"


void SelectionSort::sortList(EventList* list, SortStrategy::SORT_BY sortBy)
{
    if(list->size <= 0) return;

    Node* temp = list->head;
    std::vector<Event**> events;
    while(temp != nullptr)
    {
        events.push_back( &temp->event );
        temp = temp->next;
    }

    auto isLess = [&](Event* a, Event* b) -> bool
    {
        switch (sortBy)
        {
            case SortStrategy::SORT_BY::TIMESTAMP:  return a->timestamp()   < b->timestamp();
            case SortStrategy::SORT_BY::READING:    return a->value()       < b->value();
            case SortStrategy::SORT_BY::ID:         return a->sensorId()    < b->sensorId();
        }
        return false;
    };


    int end = events.size();
    int biggestIndex = 0;
    while(end > 0)
    {
        biggestIndex = 0;
        for(int i = 1; i < end; i++)
        {
            if(isLess(*events[ biggestIndex ], *events[ i ]))
            {
                biggestIndex = i;
            }
        }
        if (biggestIndex != end - 1)
        {
            swap(events[biggestIndex], events[end - 1]);
        }
        end--;
    }
}