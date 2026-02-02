#include "event.h"

Event::Event(const TYPE type, const SENSOR_TYPE sensorType, const int value, const int timeStamp, const int id) : _type(type), _value(value),
 _timeStamp(timeStamp),_sensorId(id), _sensorType(sensorType) {}

Event::TYPE Event::type() const
{
    return _type;
}

Event::SENSOR_TYPE Event::sensorType() const
{
    return _sensorType;
}

int Event::value() const
{
    return _value;
}

int Event::timestamp() const
{
    return _timeStamp;
}

int Event::sensorId() const
{
    return _sensorId;
}