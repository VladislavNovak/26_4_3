#include <iostream>
#include <vector>
#include "screen.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    Screen screen{};
    std::cout << "ADD" << std::endl;
    screen.addWindow();
    std::cout << "PRINT" << std::endl;
    screen.doPrint();
    std::cout << "ADD" << std::endl;
    screen.addWindow();
    std::cout << "PRINT 1" << std::endl;
    screen.doPrint(1);
    std::cout << "PRINT 1" << std::endl;
    screen.doPrint(2);

    screen.doExit();

    return 0;
}
