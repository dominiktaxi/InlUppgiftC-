#include "eventqueue.h"
#include <iostream>
#include <assert.h>

EventQueue::EventQueue(int capacity) : _events(nullptr), _front(0), _size(0), _capacity(capacity)
{
    _events = new Event*[capacity];
    for(int i = 0; i < capacity; i++)
    {
        _events[i] = nullptr;
    }
    _front = 0;
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
void EventQueue::enqueue(Event* event)
{
    assert( !isFull() );
    int index = (_front + _size) % _capacity;
    _events[index] = event;
    _size++;
}
    
Event* EventQueue::dequeue()
{
    assert( !EventQueue::isEmpty() );
    Event* ret = _events[ _front ];
    _events[ _front ] = nullptr;
    _front = (_front + 1) % _capacity;
    _size--;
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

void EventQueue::printAll() const
{
    int index = _front;
    for(int i = 0; i < _size; i++)
    {
        if(_events[ index ]->type() == Event::TYPE::TEMPERATURE_SAMPLE) std::cout << "temperature reading:" << _events[index]->value() << std::endl;
        if(_events[ index ]->type() == Event::TYPE::MOTION) std::cout << "motion reading: " << _events[index]->value() << std::endl;

        index++;
        index = index % _capacity;
    }
}
