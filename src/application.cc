#include "application.h"

Application::Application(int queueCapacity, int logCapacity) : _eventLog(logCapacity), _eventQueue(queueCapacity),
_menu(this), _sortStrategy(nullptr)
{
    _sensorNetwork.addSensor(Sensor::TYPE::HUMIDITY);
    _sensorNetwork.addSensor(Sensor::TYPE::TEMPERATURE);
    _sensorNetwork.addSensor(Sensor::TYPE::MOTION);
}

Application::~Application()
{
    delete _sortStrategy;
}

void Application::awaitCommand()
{
    _menu.awaitCommand();
}

void Application::selectSorting(SORTING_TYPE type)
{
    if(type == Application::SORTING_TYPE::INSERTION)
    {
        _sortStrategy = new InsertionSort;
    }
}

void Application::sort()
{
    _sortStrategy->sortList(_eventLog.list());
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
    _eventLog.append(_eventQueue.dequeue() );
}


void Application::printAll() const
{
    _eventLog.printAll();
}