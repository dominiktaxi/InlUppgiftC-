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

    Event(const TYPE type, const int value, const int timeStamp) : _type(type), _value(value), _timeStamp(timeStamp) {}
    Event() = default;
    
    TYPE type() const;
    int value() const;
    int timestamp() const;
    private:
    TYPE _type;
    int _value;
    int _timeStamp;
};



#endif