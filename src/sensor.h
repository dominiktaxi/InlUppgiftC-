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
    int readValue();
    private:
    
};
#endif