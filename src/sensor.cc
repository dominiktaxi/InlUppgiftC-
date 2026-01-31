#include "sensor.h"

Sensor::Sensor(TYPE type, int id) : _type(type), _id(id) {}

int Sensor::readValue()
{
    return 0;
}

Sensor::TYPE Sensor::type() const
{
    return _type;
}

int Sensor::id() const
{
    return _id;
}