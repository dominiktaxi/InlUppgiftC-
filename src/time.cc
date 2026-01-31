#include "time.h"
#include <iostream>

int Time::time() const
{
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = now - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
    
    return ms;
}