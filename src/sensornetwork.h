#ifndef SENSORNETWORK_H
#define SENSORNETWORK_H
#define MAX_SENSORS 3
#include "time.h"
#include "sensor.h"
#include "eventqueue.h"


class SensorNetwork
{
    public:
    SensorNetwork();
    void addSensor(Sensor::TYPE);
    void scan(EventQueue*);
    int amount() const;
    private:
    Sensor** _sensors;
    Time _time;
    static int _amount;
    const static int _MAX;
};

#endif