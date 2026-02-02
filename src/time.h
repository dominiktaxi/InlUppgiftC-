#ifndef TIME_H
#define TIME_H
#include <chrono>
#include <ctime>
#include <string>

class Time
{
    public:

    Time();

    int time() const;
    private:
    std::chrono::steady_clock::time_point start;
};

#endif