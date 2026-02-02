#include "utils.h"
#include <iostream>
 #include <random>
void Utils::printer(const char* printout)
{
    std::cout << printout << std::endl;
} 

void Utils::endl()
{
    std::cout << std::endl;
}

int Utils::randomInt(int min, int max)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    int x = dist(rng);
    return x;
}

