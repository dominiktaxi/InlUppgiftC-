#include "application.h"
#include <iostream>
#include <assert.h>
Application::Application(int queueCapacity, int logCapacity) : _eventLog(logCapacity), _eventQueue(queueCapacity),
_menu(this)
{
    _observerData._observers = new Observer*[MAX_OBSERVERS];
    for(int i = 0; i < MAX_OBSERVERS; i++)
    {
        _observerData._observers[i] = nullptr;
    }
    _observerData._size = 0;
}

void Application::addSensors(Sensor::TYPE type, int threshold)
{
    _sensorNetwork.addSensor( type, threshold );
}

// I dont delete the objects, user might choose to pass them from the stack, this is users responsibility
Application::~Application()
{
    delete[] _observerData._observers;
}

void Application::attachObserver(Observer* observer)
{
    assert(_observerData._size < MAX_OBSERVERS && _observerData._size >= 0);
    _observerData._observers[ _observerData._size ] = observer;
    _observerData._size++;
}

void Application::notifyObservers( Event* event )
{
    for(int i = 0; i < _observerData._size; i++)
    {
        _observerData._observers[i]->notifyObservers( event );
    }
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
            Event* event = _eventQueue.dequeue();
            _logEvents(event);
            _lastEvent.add( event );
            notifyObservers( event );
        }
    }
}

void Application::printAll()
{
    assert(_eventLog.list() != nullptr);
    Node* temp = _eventLog.list()->head;
    const char * name;
    
    while(temp != nullptr)
    {
        _printEvent(temp->event);
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
            _printEvent(temp->event);
            std::cout << "dude" << std::endl;
           
        }
        temp = temp->next;
    }
}

void Application::printLastSensorEvent( int id )
{
    _printEvent( _lastEvent.event( id ) );
}

void Application::sort( SortStrategy& strategy, SortStrategy::SORT_BY sortBy)
{
    strategy.sortList(_eventLog.list(), sortBy);
}

void Application::checkAlarms() const
{
    if(_alarmSet.alarmExists())
    {
        std::cout << "there are " << _alarmSet.amountOfAlarms() << " active alarms" << std::endl;
    }
}









// ******************************************** PRIVATE ********************************************  //
void Application::_scanSensors()
{
    _sensorNetwork.scan(&_eventQueue);
}

void Application::_logEvents(Event* event)
{
    _eventLog.append( event );
}

void Application::_printEvent(const Event* event)
{
    if(event != nullptr)
    {
        const char * name;
        if(event->sensorType() == Event::SENSOR_TYPE::HUMIDITY)
        {
            if(event->type() == Event::TYPE::OVER_THRESHOLD)     { name = "Humidity over threshold"; }
            if(event->type() == Event::TYPE::UNDER_THRESHOLD)    { name = "Humidity under threshold"; }
            else { name = "Humidity";}
        }
        else if( event->sensorType() == Event::SENSOR_TYPE::TEMPERATURE)
        {
            if(event->type() == Event::TYPE::OVER_THRESHOLD)     { name = "Temperature over threshold"; }
            if(event->type() == Event::TYPE::UNDER_THRESHOLD)    { name = "Temperature under threshold"; }
            else { name = "Temperature"; }
        }
        else if( event->sensorType() == Event::SENSOR_TYPE::MOTION)
        {
            if(event->value()) { name = "Motion Detected"; }
            else {name = "No motion detected";}
        }
        std::cout << "TimeStamp: " << event->timestamp() << std::endl;
        std::cout << "Name: " << name  << std::endl;
        std::cout << "Reading: " << event->value() << std::endl;
        std::cout << "ID: " << event->sensorId() << "\n" << std::endl;
        name = "";
    }
}