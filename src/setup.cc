#include "setup.h"

Setup::Setup() : _app(Application(10, 10000))
{}

void Setup::addSensors()
{
    _app.addSensors(Sensor::TYPE::HUMIDITY, 60);
    _app.addSensors(Sensor::TYPE::MOTION, 0);
    _app.addSensors(Sensor::TYPE::TEMPERATURE, 30);
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