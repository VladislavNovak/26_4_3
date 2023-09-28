#include <iostream>
#include <vector>
#include "utilities.h"
#include "screen.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    std::vector<std::string> mainMenu = { "add", "print", "about", "exit" };
    Screen screen{};

    while(true) {
        std::cout << "--- Main menu ---" << std::endl;
        int command = selectMenuItem(mainMenu, "To create and display new window");

        if (command == static_cast<int>(Menu::ADD)) {
            std::cout << "Menu --> add mode -->" << std::endl;
            screen.addWindow();
        }
        else if (command == static_cast<int>(Menu::PRINT)) {
            if (screen.getCount() < 2) {
                std::cout << "Add at least one window" << std::endl;
                continue;
            }

            std::cout << "Menu -> print mode -> select index of window ->" << std::endl;

            int index = (screen.getCount() == 2) ?
                        FIRST_WINDOW :
                        putNumeric({FIRST_WINDOW, screen.getCount() - 1}, {}, "index of window");
            std::cout << "PRINT window " << index << std::endl;
            screen.doPrint(index);
        }
        else if (command == static_cast<int>(Menu::ABOUT)) {
            std::cout << "Menu -> about mode ->" << std::endl;
            about();
        }
        else if (command == static_cast<int>(Menu::EXIT)) {
            std::cout << "Menu --> exit mode -->" << std::endl;
            screen.doExit();
            break;
        }
    }

    std::cout << "POWER OFF" << std::endl;

    return 0;
}