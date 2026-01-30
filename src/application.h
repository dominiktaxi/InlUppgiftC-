#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include "eventqueue.h"
#include "eventlog.h"
#include "sensor.h"
#include "event.h"


class Application
{
    public:
    void scanSensors();
    private:
    std::vector<Sensor> _sensors;
};


#endif