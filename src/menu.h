#ifndef MENU_H
#define MENU_H

#include "utils.h"
class Application;
class Menu
{
    public:
    Menu(Application*);
    void awaitCommand();
    void sortBy() const;
    private:
    Application* _app;
};

#endif