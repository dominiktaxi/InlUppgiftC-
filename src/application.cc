#include "application.h"
#include <iostream>
#include <assert.h>
Application::Application(int queueCapacity, int logCapacity) : _eventLog(logCapacity), _eventQueue(queueCapacity),
_menu(this)
{
    _sensorNetwork.addSensor(Sensor::TYPE::HUMIDITY);
    _sensorNetwork.addSensor(Sensor::TYPE::TEMPERATURE);
    _sensorNetwork.addSensor(Sensor::TYPE::MOTION);
}

Application::~Application()
{
    
}

void Application::awaitCommand()
{
    _menu.awaitCommand();
}

void Application::runTick(int n)
{
    for(int i = 0; i < n; i++)
    {
        _scanSensors();
        
        for(int j = 0; j < _sensorNetwork.amount(); j++)
        {
            _logEvents();
        }
    }
}

void Application::_scanSensors()
{
    _sensorNetwork.scan(&_eventQueue);
}

void Application::_logEvents()
{
    Event* event = _eventQueue.dequeue();
    _eventLog.append( event );
    _lastEvent.add( event );
}


void Application::printAll()
{
    assert(_eventLog.list() != nullptr);
    Node* temp = _eventLog.list()->head;
    const char * name;
    
    while(temp != nullptr)
    {
        _printEvent(*temp->event);
        temp = temp->next;
    }
}

void Application::findEvent(int id)
{
    Node* temp = _eventLog.list()->head;
    while(temp != nullptr)
    {
        if(temp->event->sensorId() == id)
        {

        }
    }
}

void Application::sort( SortStrategy& strategy, SortStrategy::SORT_BY sortBy)
{
    strategy.sortList(_eventLog.list(), sortBy);
}

void Application::_printEvent(const Event& event)
{
    const char * name;
        
    if(event.type() == Event::TYPE::HUMIDITY_SAMPLE)     { name = "Humidity"; }
    if(event.type() == Event::TYPE::MOTION)              { name = "Motion"; }
    if(event.type() == Event::TYPE::OVERTEMPERATURE)     { name = "Temperature alarm"; }
    if(event.type() == Event::TYPE::TEMPERATURE_SAMPLE)  { name = "Temperature"; }
    if(event.type() == Event::TYPE::OVERHUMIDITY)        { name = "Humidity alarm"; }

    std::cout << "TimeStamp: " << event.timestamp() << std::endl;
    std::cout << "Name: " << name  << std::endl;
    std::cout << "Reading: " << event.value() << std::endl;
    std::cout << "ID: " << event.sensorId() << "\n" << std::endl;
}