#ifndef TEMPHUM_H
#define TEMPHUM_H



class Sensor
{
    public:
    enum class TYPE
    {
        TEMPERATURE,
        HUMIDITY,
        MOTION
    };
    Sensor(TYPE, int);
    int readValue();
    TYPE type() const;
    int id() const;
    private:
    TYPE _type;
    int _id;
};
#endif