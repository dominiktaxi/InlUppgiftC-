#include "event.h"

Event::TYPE Event::type() const
{
    return _type;
}

int Event::value() const
{
    return _value;
}

int Event::timestamp() const
{
    return _timeStamp;
}