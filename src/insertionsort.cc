#include "insertionsort.h"
#include <vector>
void InsertionSort::sortList(EventList* list)
{
    if(list->size <= 0) return;

    Node* temp = list->head;
    std::vector<Event*> events;
    while(temp != nullptr)
    {
        events.push_back( temp->event );
        temp = temp->next;
    }



    int end = list->size;
    int biggestFound = list->head->event->value();
    int indexFound = 0;
    while(end > 0)
    {
        biggestFound = events[0]->value();
        indexFound = 0;
        for(int i = 0; i < end - 1; i++)
        {
            if(biggestFound < events[ i + 1 ]->value())
            {
                biggestFound = events[ i + 1 ]->value();
                indexFound = i + 1;
            }
        }
        if (indexFound != end - 1)
        {
            _swap(&events[indexFound], &events[end - 1]);
        }

        end--;
        //swap(&arr[indexFound], &arr[indexReducing - 1]);
    }
}

void InsertionSort::_swap(Event** e1, Event** e2)
{
    Event** temp = e1;
    *e1 = *e2;
    *e2 = *temp;
}