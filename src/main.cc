#include "setup.h"
int main()
{
    Setup setup;
    setup.addSensors();
    setup.attachObservers();
    setup.runApp();
    return 0;
}