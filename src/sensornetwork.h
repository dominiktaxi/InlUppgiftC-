#ifndef SENSORNETWORK_H
#define SENSORNETWORK_H
#define MAX_SENSORS 3

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
    EventQueue _eventQueue;

    static int _amount;
    const static int _MAX;
};
int SensorNetwork::_amount = 0;
const int SensorNetwork::_MAX = MAX_SENSORS;
#endif