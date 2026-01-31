#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "eventqueue.h"
#include "eventlog.h"
#include "sensornetwork.h"
#include "insertionsort.h"
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
    void selectSorting(SORTING_TYPE);
    void sort();
    void runTick(int);
    void printAll() const;
    private:
    SensorNetwork _sensorNetwork;
    EventLog _eventLog;
    EventQueue _eventQueue;
    SortStrategy* _sortStrategy;
    Menu _menu;

    void _scanSensors();
    void _logEvents();
};


#endif