#include "insertionsort.h"

void InsertionSort::sortList(EventList* eventList, InsertionSort::SORT_BY sortBy)
{
    Node* temp = eventList->head;
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

    for(int i = 1; i < events.size(); i++)
    {
        if( isLess( *events[i], *events[i - 1]) ) 
        {
            swap( events[ i - 1 ], events[ i ] );
            
            for(int j = i - 1; j > 0; j-- )
            {
                if(isLess(*events[j], *events[j - 1]))
                {
                    swap(events[ j ], events[ j - 1 ]);
                }
            }
        }
    }
}

