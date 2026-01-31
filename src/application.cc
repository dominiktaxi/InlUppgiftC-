#include "application.h"

Application::Application(int logCapacity, int queueCapacity) : _eventLog(logCapacity), _eventQueue(queueCapacity)
{
    _sensorNetwork.addSensor(Sensor::TYPE::HUMIDITY);
    _sensorNetwork.addSensor(Sensor::TYPE::TEMPERATURE);
    _sensorNetwork.addSensor(Sensor::TYPE::MOTION);
}

void Application::selectSorting(SORTING_TYPE type)
{
    if(type == Application::SORTING_TYPE::INSERTION)
    {
        _sortStrategy = new InsertionSort;
    }
}

void Application::sort(EventList* list)
{
    _sortStrategy->sortList( list );
}

void Application::runTick(int n)
{
    for(int i = 0; i < n; i++)
    {
        _scanSensors();
        
        for(int j = 0; i < _sensorNetwork.amount(); j++)
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
    _eventLog.append(_eventQueue.dequeue() );
}