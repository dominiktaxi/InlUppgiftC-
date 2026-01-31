#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "eventqueue.h"
#include "eventlog.h"
#include "sensornetwork.h"
#include "insertionsort.h"

class Application
{
    public:
    enum class SORTING_TYPE
    {
        INSERTION
    };
    Application(int, int);
    
    void selectSorting(SORTING_TYPE);
    void sort(EventList*);
    void runTick(int);
    private:
    SensorNetwork _sensorNetwork;
    EventLog _eventLog;
    EventQueue _eventQueue;
    SortStrategy* _sortStrategy;

    void _scanSensors();
    void _logEvents();
};


#endif