#ifndef SETUP_H
#define SETUP_H
#include "application.h"
#include "alarmset.h"
class Setup
{
    public:
    Setup();
    void addSensors();
    void attachObservers();
    void runApp();
    private:
    Application _app;
    AlarmSet _alarmSet;
};

#endif