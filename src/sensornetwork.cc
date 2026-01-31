#include "sensornetwork.h"
#include <assert.h>
SensorNetwork::SensorNetwork()
{
    _sensors = new Sensor*[MAX_SENSORS];
    for(int i = 0; i < MAX_SENSORS; i++)
    {
        _sensors[i] = nullptr;
    }
}

void SensorNetwork::addSensor(Sensor::TYPE type)
{
    assert(_amount < MAX_SENSORS);
    _sensors[_amount] = new Sensor(type, _amount);
    _amount++;
}

void SensorNetwork::scan(EventQueue* queue)
{
    assert(_amount > 0);
    Event* event;
    for(int i = 0; i < _amount; i++)
    {
        int value = _sensors[ i ]->readValue();
        if( _sensors[ i ]->type() == Sensor::TYPE::TEMPERATURE )
        {
            if ( value > 30 )   { event = new Event( Event::TYPE::OVERTEMPERATURE, value ); }
            else                { event = new Event( Event::TYPE::TEMPERATURE_SAMPLE, value ); }
            
        }
        else if( _sensors[ i ]->type() == Sensor::TYPE::HUMIDITY )
        {
            if( value > 60 )    { event = new Event( Event::TYPE::OVERHUMIDITY, value ); }
            else                { event = new Event( Event::TYPE::HUMIDITY_SAMPLE, value); }
        }
        else if( _sensors[ i ]->type() == Sensor::TYPE::MOTION)
        {
                                  event = new Event( Event::TYPE::MOTION, value );
        }
        queue->enqueue( event );
    }
}

int SensorNetwork::amount() const
{
    return _amount;
}