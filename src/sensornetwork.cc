#include "sensornetwork.h"

#include <assert.h>

int SensorNetwork::_amount = 0;
const int SensorNetwork::_MAX = MAX_SENSORS;

SensorNetwork::SensorNetwork()
{
    _sensors = new Sensor*[MAX_SENSORS];
    for(int i = 0; i < MAX_SENSORS; i++)
    {
        _sensors[i] = nullptr;
    }
}

SensorNetwork::~SensorNetwork()
{
    for (int i = 0; i < MAX_SENSORS; i++)
    {
        delete _sensors[ i ];
        _sensors[ i ] = nullptr;
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
        int sensorId = _sensors[ i ]->id();
        int timeStamp = _time.time();
        if( _sensors[ i ]->type() == Sensor::TYPE::TEMPERATURE )
        {
            if ( value > 30 )   { event = new Event( Event::TYPE::OVERTEMPERATURE, value, timeStamp, sensorId ); }
            else                { event = new Event( Event::TYPE::TEMPERATURE_SAMPLE, value, timeStamp, sensorId ); }
            
        }
        else if( _sensors[ i ]->type() == Sensor::TYPE::HUMIDITY )
        {
            if( value > 60 )    { event = new Event( Event::TYPE::OVERHUMIDITY, value, timeStamp, sensorId ); }
            else                { event = new Event( Event::TYPE::HUMIDITY_SAMPLE, value, timeStamp, sensorId ); }
        }
        else if( _sensors[ i ]->type() == Sensor::TYPE::MOTION)
        {
                                  event = new Event( Event::TYPE::MOTION, value, timeStamp, sensorId );
        }
        queue->enqueue( event );
    }
}

int SensorNetwork::amount() const
{
    return _amount;
}