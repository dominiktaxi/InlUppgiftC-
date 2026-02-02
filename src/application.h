#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "eventqueue.h"
#include "eventlog.h"
#include "sensornetwork.h"
#include "selectionsort.h"
#include "lastevent.h"
#include "menu.h"
class Application
{
    public:
    enum class SORTING_TYPE
    {
        INSERTION
    };
    Application(int, int);
    ~Application();
    void awaitCommand();
    void runTick(int);
    void printAll();
    void findEvent(int);
    void sort(SortStrategy&, SortStrategy::SORT_BY);
    private:
    SensorNetwork _sensorNetwork;
    EventLog _eventLog;
    EventQueue _eventQueue;
    Menu _menu;
    LastEvent _lastEvent;

    void _scanSensors();
    void _logEvents();
    void _printEvent(const Event&);
};


#endif