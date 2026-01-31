#ifndef MENU_H
#define MENU_H
#include "application.h"
#include "utils.h"
class Menu
{
    public:
    Menu();
    void awaitCommand();
    private:
    Application _app;
};

#endif