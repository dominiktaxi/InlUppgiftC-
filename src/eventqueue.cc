#include "eventqueue.h"
#include <assert.h>

EventQueue::EventQueue(int capacity) : _events(nullptr), _front(0), _size(0), _capacity(capacity)
{
    _events = new Event*[capacity];
    for(int i = 0; i < capacity; i++)
    {
        _events[i] = nullptr;
    }
}


EventQueue::~EventQueue()
{
    for(int i = 0; i < _capacity; i++)
    {
        delete _events[i];
    }
    delete[] _events;
}
void EventQueue::create(int capacity)
{
    _size = capacity;

    _events = new Event*[capacity];

    _front = 0;
}

bool EventQueue::isEmpty() const
{
    return _size == 0;
}

bool EventQueue::isFull() const
{
    return _size == _capacity;
}

//ingen assert q != NULL för att Eventq skapas på stacken per definition
int EventQueue::enqueue(Event::TYPE type, float value)
{
    assert( !isFull() );
    int index = (_front + _size) % _capacity;
    _events[index] = new Event(type, value);
    _size++;
}
    
Event EventQueue::dequeue()
{
   assert( !EventQueue::isEmpty() );
   int index = _front;
   _front = (_front + 1) % _capacity;
   _size--;
   Event ret = *_events[ index ];
   delete _events[ index ];
   _events[ index ] = nullptr;
   return ret;
}

void EventQueue::clear()
{
    _size = 0;
    _front = 0;
}

int EventQueue::size() const
{
    return _size;
}