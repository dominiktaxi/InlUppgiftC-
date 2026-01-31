#include "sensor.h"
#include "utils.h"

Sensor::Sensor(TYPE type, int id) : _type(type), _id(id) {}

int Sensor::readValue()
{
    if(_type == Sensor::TYPE::HUMIDITY) {return Utils::randomInt(5, 99); }
    if(_type == Sensor::TYPE::MOTION) {return Utils::randomInt(0, 1); }
    if(_type == Sensor::TYPE::TEMPERATURE) {return Utils::randomInt(-40, 45); }

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