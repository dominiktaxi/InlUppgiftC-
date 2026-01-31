#include <sstream>
#include <iostream>
#include "menu.h"

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
            continue; // empty line
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
            Utils::printer("sort");
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
                _app.runTick(n);
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
        else if (cmd == "sort") 
        {
            std::string name;
            if (!(ss >> name)) 
            {
                Utils::printer("invalid command");
            } 
            else 
            {
                
            }
        }
        else if (cmd == "printlog") 
        {
            
        }
        else 
        {
            Utils::printer("Invalid command, type 'help' for help");
        }
    }
}