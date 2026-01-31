#include "application.h"
#include "time.h"
int main()
{
    Application app(10, 1000);
    app.selectSorting(Application::SORTING_TYPE::INSERTION);
    app.awaitCommand();
    Time time;
    time.time();
    return 0;
}