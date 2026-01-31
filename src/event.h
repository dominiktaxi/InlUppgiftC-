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

    Event(const TYPE type, const int value) : _type(type), _value(value) {}
    Event() = default;
    
    TYPE type() const;
    int value() const;
    private:
    TYPE _type;
    int _value;
};



#endif