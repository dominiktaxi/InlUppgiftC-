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
        UNDERTEMPERATURE, 
        OVERTEMPERATURE, 
        UNDERHUMIDITY,
        OVERHUMIDITY
    };

    Event(const TYPE type, const int value, const int timeStamp, const int id) : _type(type), _value(value), _timeStamp(timeStamp),
    _sensorId(id) {}
    Event() = default;
    
    TYPE type() const;
    int value() const;
    int timestamp() const;
    int sensorId() const;
    private:
    TYPE _type;
    int _value;
    int _timeStamp;
    int _sensorId;
};



#endif