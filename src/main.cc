#include "application.h"
#include "time.h"
#include "lastevent.h"
int main()
{
    Application app(10, 10000);
    app.awaitCommand();
    Time time;
    time.time();
    return 0;
}