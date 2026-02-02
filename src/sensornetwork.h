#ifndef SENSORNETWORK_H
#define SENSORNETWORK_H
#define MAX_SENSORS 15
#include "time.h"
#include "sensor.h"
#include "eventqueue.h"


class SensorNetwork
{
    public:
    SensorNetwork();
    ~SensorNetwork();
    void addSensor(Sensor::TYPE, int, int);
    void scan(EventQueue*);
    int amount() const;
    static int sensorCapacity();
    private:
    Sensor** _sensors;
    Time _time;
    int _amount;
    const static int _MAX;
};

#endif