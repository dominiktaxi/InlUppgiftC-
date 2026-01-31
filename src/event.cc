#include "event.h"

Event::TYPE Event::type() const
{
    return _type;
}

int Event::value() const
{
    return _value;
}