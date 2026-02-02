#include "sensornetwork.h"
#include <iostream>
#include <assert.h>


const int SensorNetwork::_MAX = MAX_SENSORS;

SensorNetwork::SensorNetwork() : _amount(0)
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
    delete[] _sensors;
}

void SensorNetwork::addSensor(Sensor::TYPE type, int lowerThreshold, int upperThreshold)
{
    assert(_amount < MAX_SENSORS);
    _sensors[_amount] = new Sensor(type, _amount, lowerThreshold, upperThreshold);
    std::cout << "sensor added" << std::endl;
    _amount++;
}

void SensorNetwork::scan(EventQueue* queue)
{
    assert(_amount > 0);
    Event* event;
    for(int i = 0; i < _amount; i++)
    {
        int lowerThreshold = _sensors[i]->lowerThreshold();
        int upperThreshold = _sensors[i]->upperThreshold();
        int value = _sensors[ i ]->readValue();
        int sensorId = _sensors[ i ]->id();
        int timeStamp = _time.time();
        Event::SENSOR_TYPE type = static_cast<Event::SENSOR_TYPE>(_sensors[i]->type() ) ;

       //SENSOR_TYPE WORKING
       //value working
       //threshold working

        if( _sensors[ i ]->type() == Sensor::TYPE::TEMPERATURE )
        {
            if ( value > upperThreshold ) 
            { event = new Event( Event::TYPE::OVER_THRESHOLD, type,  value, timeStamp, sensorId ); }

            else if( value < lowerThreshold )
            { event = new Event( Event::TYPE::UNDER_THRESHOLD, type, value, timeStamp, sensorId ); }

            else
            { event = new Event( Event::TYPE::TEMPERATURE_SAMPLE, type, value, timeStamp, sensorId ); }
            
        }
        else if( _sensors[ i ]->type() == Sensor::TYPE::HUMIDITY )
        {
            if( value > upperThreshold )    
            { event = new Event( Event::TYPE::OVER_THRESHOLD, type, value, timeStamp, sensorId ); }
            else if( value < lowerThreshold )
            { event = new Event(Event::TYPE::UNDER_THRESHOLD, type, value, timeStamp, sensorId); }
            
            else
            { event = new Event( Event::TYPE::HUMIDITY_SAMPLE, type, value, timeStamp, sensorId ); }
        }
        else if( _sensors[ i ]->type() == Sensor::TYPE::MOTION)
        {
            event = new Event( Event::TYPE::MOTION, type, value, timeStamp, sensorId );
        }
        queue->enqueue( event );
    }
}

int SensorNetwork::amount() const
{
    return _amount;
}

int SensorNetwork::sensorCapacity()
{
    return _MAX;
}