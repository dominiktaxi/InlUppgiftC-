#ifndef EVENT_H
#define EVENT_H

class Event
{
    public:
    enum class TYPE 
    {
        TEMPERATURE_SAMPLE,
        HUMIDITY_SAMPLE, 
        MOTION,
        OVER_THRESHOLD,
        UNDER_THRESHOLD
    };
    enum class SENSOR_TYPE
    {
        TEMPERATURE = 0,
        HUMIDITY = 1,
        MOTION = 2
    };

    Event(const TYPE, const SENSOR_TYPE, const int, const int, const int);
    Event() = default;
    
    TYPE type() const;
    SENSOR_TYPE sensorType() const;
    int value() const;
    int timestamp() const;
    int sensorId() const;
    private:
    TYPE _type;
    SENSOR_TYPE _sensorType;
    int _value;
    int _timeStamp;
    int _sensorId;
};



#endif