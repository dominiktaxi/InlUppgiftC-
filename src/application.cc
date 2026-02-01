#include "application.h"

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
    _eventLog.append(_eventQueue.dequeue() );
}


void Application::printAll() const
{
    _eventLog.printAll();
}

void Application::sort( SortStrategy& strategy, SortStrategy::SORT_BY sortBy)
{
    strategy.sortList(_eventLog.list(), sortBy);
}