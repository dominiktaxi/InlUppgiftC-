#include "setup.h"

Setup::Setup() : _app(Application(10, 10000))
{}

void Setup::addSensors()
{
    _app.addSensors(Sensor::TYPE::HUMIDITY, 10, 60);
    _app.addSensors(Sensor::TYPE::MOTION, 0, 1);
    _app.addSensors(Sensor::TYPE::TEMPERATURE, 5, 25);
}

void Setup::attachObservers()
{
    _app.attachObserver(&_alarmSet);
    Utils::printer("Observer attached");
}

void Setup::runApp()
{
    _app.awaitCommand();
}