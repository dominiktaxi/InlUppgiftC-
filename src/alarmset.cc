#include "alarmset.h"
#include <assert.h>
#include <utility>
AlarmSet::AlarmSet() : _amount(0), _capacity(MAX_SENSORS)
{
    for(int i = 0; i < _capacity; i++)
    {
        _set[i] = -1;
    }
}

void AlarmSet::notifyObservers(Event* event)
{
    if( event->type() == Event::TYPE::OVER_THRESHOLD || event->type() == Event::TYPE::UNDER_THRESHOLD )
    {
        add( event->sensorId() );
    }
    else
    {
        remove( event->sensorId() );
    }
}

bool AlarmSet::isInSet(int id) const
{
    if( _set[ id ] == id )
    {
        return true;
    }
    return false;
}

void AlarmSet::add( int id )
{
    assert(id < _capacity && id >= 0);
    _set[ id ] = id;
    _amount++;
}

void AlarmSet::remove( int id )
{
    assert( id >= 0 && id < _capacity );
    _set[ id ] = -1;
    _amount--;
}

bool AlarmSet::alarmExists() const
{
    for(int i = 0; i < _capacity; i++)
    {
        if(_set[ i ] >= 0)
        {
            return true;
        }
    }
    return false;
}

int AlarmSet::amountOfAlarms() const
{
    return _amount;
}