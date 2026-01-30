#ifndef EVENT_H
#define EVENT_H

class Event
{
    public:
    enum class TYPE {TEMPERATURE_SAMPLE, UNDERTEMPERATURE, OVERTEMPERATURE, MOTION};

    Event(const TYPE type, const float value) : _type(type), _value(value) {}
    TYPE type() const;
    private:
    const TYPE _type;
    const float _value;
};



#endif