#include <sstream>
#include <iostream>
#include "menu.h"
#include "application.h"
#include "sortstrategy.h"
#include "selectionsort.h"

Menu::Menu(Application* app) : _app(app) {}

void Menu::awaitCommand()
{
    Utils::printer("Type command:");
    std::string line;


    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, line);

        std::istringstream ss(line);
        std::string cmd;
        ss >> cmd;

        if (cmd == "") 
        {
            continue;
        }
        else if (cmd == "exit") 
        {
            break;
        }
        else if (cmd == "help") 
        {
            Utils::printer("Commands:");
            Utils::printer("tick <n>");
            Utils::printer("printlog <n>");
            Utils::printer("selectionsort *timestamp | reading | id*");
            Utils::printer("find <sensorID>");
            Utils::printer("help");
            Utils::printer("exit");
        }
        else if (cmd == "tick") 
        {
            int n;
            if (!(ss >> n)) 
            {
                Utils::printer("invalid command");
            } 
            else 
            {
                _app->runTick(n);
                std::cout << n;
                Utils::printer(" ticks called");
            }
        }
        else if (cmd == "find") 
        {
            int id;
            if (!(ss >> id)) 
            {
                Utils::printer("invalid command");
            } else 
            {
                
            }
        }
        else if (cmd == "selectionsort") 
        {
            SelectionSort selectionSort;
            std::string argument;
            if(!(ss >> argument)) { Utils::printer("missing sort argument: timestamp | reading | id"); }
            else if(argument == "timestamp") _app->sort( selectionSort, SortStrategy::SORT_BY::TIMESTAMP ); 
            else if(argument == "reading")   {  _app->sort( selectionSort, SortStrategy::SORT_BY::READING ); }
            else if (argument == "id")        {  _app->sort( selectionSort, SortStrategy::SORT_BY::ID );}
            else Utils::printer("Unknown sort type");
        }
        else if (cmd == "bubblesort")
        {

        }
        
        

        else if (cmd == "printlog") 
        {
            _app->printAll();
        }
        else 
        {
            Utils::printer("Invalid command, type 'help' for help");
        }
    }
}