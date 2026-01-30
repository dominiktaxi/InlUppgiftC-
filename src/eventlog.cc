#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "eventlog.h"


EventLog::EventLog(int capacity) : _list(nullptr), _capacity(capacity) {}

void EventLog::create()
{
    _list = new EventList;
    _list->head = nullptr;
    _list->tail = nullptr;
}

~EventLog::EventLog()
{
    Node* temp = _list->head;
    Node* next = nullptr;
    while(temp != nullptr)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
    _list->head = nullptr;
    _list->tail = nullptr;
    _list->size = 0;
}



int EventLog::size() const
{
    return _list->size;
}


void EventLog::append(Event::TYPE event)
{
    assert(_list->size < _capacity);

    if(_list->head == nullptr)
    {
        _list->head = new Node;
        assert(_list->head != nullptr);
        _list->tail = _list->head;
        _list->head->type = event;
        _list->head->next = nullptr;
    }
    else
    {
        _list->tail->next = new Node;
        assert(_list->tail->next != nullptr);
        _list->tail->next->type = event;
        _list->tail = _list->tail->next;
        _list->tail->next = nullptr;
    }
    _list->size++;
}

Event::TYPE EventLog::getEvent(int index)
{
    assert (index < _list->size && index >= 0);
    Node* temp = _list->head;
    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    assert(temp != nullptr);
    return temp->type;
}

void EventLog::set(int index, Event::TYPE type)
{
    assert(_list != nullptr);
    assert(index < _list->size && index >= 0);
    Node* temp = _list->head;

    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    assert(temp != nullptr);
    _list->head->type = type;
}

int EventLog::find(int key, int* outValue, const Table* table)
{

    return 0;
}




void eventlog_printAll(const Table* table)
{
   
}
