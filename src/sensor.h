#ifndef TEMPHUM_H
#define TEMPHUM_H



class Sensor
{
    public:
    enum class TYPE
    {
        TEMPERATURE = 0,
        HUMIDITY = 1,
        MOTION = 2
    };
    Sensor(TYPE, int, int, int);
    int readValue();
    TYPE type() const;
    int id() const;
    int lowerThreshold() const;
    int upperThreshold() const;
    private:
    TYPE _type;
    int _id;
    int _upperThreshold;
    int _lowerThreshold;
};
#endif