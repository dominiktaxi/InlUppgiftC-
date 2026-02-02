#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "eventqueue.h"
#include "eventlog.h"
#include "sensornetwork.h"
#include "selectionsort.h"
#include "lastevent.h"
#include "alarmset.h"
#include "menu.h"
#include "observer.h"
class Application
{
    public:
    enum class SORTING_TYPE
    {
        INSERTION
    };
    Application(int, int);
    ~Application();
    void addSensors(Sensor::TYPE, int);
    void attachObserver(Observer*);
    void notifyObservers(Event*);
    void awaitCommand();
    void runTick(int);
    void printAll();
    void findEvent(int);
    void printLastSensorEvent(int);
    void sort(SortStrategy&, SortStrategy::SORT_BY);
    void checkAlarms() const;
    
    private:
    SensorNetwork _sensorNetwork;
    EventLog _eventLog;
    EventQueue _eventQueue;
    Menu _menu;
    LastEvent _lastEvent;
    AlarmSet _alarmSet;
    struct ObserverData
    {
        Observer** _observers;
        int _size;
    };
    ObserverData _observerData;

    void _scanSensors();
    void _logEvents(Event*);
    void _printEvent(const Event*);
};


#endif