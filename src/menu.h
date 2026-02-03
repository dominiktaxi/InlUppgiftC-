#ifndef MENU_H
#define MENU_H

#include "utils.h"
class Application;
class Menu
{
    public:
    Menu(Application*);
    void awaitCommand();
    private:
    Application* _app;
};

#endif