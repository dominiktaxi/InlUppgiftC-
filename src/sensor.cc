#include "sensor.h"
#include "utils.h"

Sensor::Sensor(TYPE type, int id, int lowerThreshold, int upperThreshold) : _type(type), _id(id), 
_lowerThreshold(lowerThreshold), _upperThreshold(upperThreshold)
{
}

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

int Sensor::lowerThreshold() const
{
    return _lowerThreshold;
}

int Sensor::upperThreshold() const
{
    return _upperThreshold;
}