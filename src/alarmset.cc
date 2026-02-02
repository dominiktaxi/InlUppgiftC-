#include "alarmset.h"
#include <assert.h>
#include <utility>
AlarmSet::AlarmSet() : _size(0)
{}
    

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
}

void AlarmSet::remove( int id )
{
    assert( id >= 0 && id < _capacity );
    _set[ id ] = -1;
}