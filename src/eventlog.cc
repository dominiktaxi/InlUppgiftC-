#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include "eventlog.h"


EventLog::EventLog(int capacity) : _list(nullptr), _capacity(capacity) 
{
    _list = new EventList;
    _list->head = nullptr;
    _list->tail = nullptr;
}

//create finns inte, men fixar samma i konstruktorn

EventLog::~EventLog()
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


void EventLog::append(Event* event)
{
    assert(_list->size < _capacity);

    if(_list->head == nullptr)
    {
        _list->head = new Node;
        assert(_list->head != nullptr);
        _list->tail = _list->head;
        _list->head->event = event;
        _list->head->next = nullptr;
    }
    else
    {
        _list->tail->next = new Node;
        assert(_list->tail->next != nullptr);
        _list->tail->next->event = event;
        _list->tail = _list->tail->next;
        _list->tail->next = nullptr;
    }
    _list->size++;
}

const Event& EventLog::eventByIndex(int index) const
{
    assert (index < _list->size && index >= 0);
    Node* temp = _list->head;
    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    assert(temp != nullptr);
    return *(temp->event);
}

void EventLog::set(int index, Event* event)
{
    assert(_list != nullptr);
    assert(index < _list->size && index >= 0);
    Node* temp = _list->head;

    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    assert(temp != nullptr);
    _list->head->event = event;
}

void EventLog::printAll() const
{
    Node* temp = _list->head;
    while(temp != nullptr)
    {
        if(temp->event->type() == Event::TYPE::MOTION)
        {
            std::cout << "MOTION" << std::endl;
        }
        else if(temp->event->type() == Event::TYPE::TEMPERATURE_SAMPLE)
        {
            std::cout << "TEMPERATURE" << std::endl;
        }
        temp = temp->next;
    }
}