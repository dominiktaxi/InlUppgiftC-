#include "lastevent.h"
#include <assert.h>
LastEvent::LastEvent() : _capacity( MAX_SENSORS ), _size(0)
{
    _events = new Event*[ _capacity ];
    for( int i = 0; i < _capacity; i++)
    {
        _events[ i ] = nullptr;
    }
}

LastEvent::~LastEvent()
{
    delete[] _events;
}

void LastEvent::add(Event* event)
{
    assert(event != nullptr && event->sensorId() >= 0 && event->sensorId() < _capacity);
    _events[ event->sensorId() ] = event;
}

Event* LastEvent::event(int sensorId) const
{
    assert(sensorId >= 0 && sensorId < _capacity);
    return _events[ sensorId ];
}

