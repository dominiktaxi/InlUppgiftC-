#ifndef EventQueue_H
#define EventQueue_H
#include <stddef.h> 
#include <stdlib.h>
#include <vector>
#include "event.h"

class EventQueue
{
public:
EventQueue(int);
~EventQueue();
void destroy(EventQueue*);
bool isEmpty() const;
bool isFull() const;
void enqueue(Event*);
Event* dequeue();
void clear();
int size() const;
void printAll() const;
private:
    int _front;
    int _size;
    int _capacity;
    Event** _events;
};
#endif