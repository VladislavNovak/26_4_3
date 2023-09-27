#ifndef INC_26_4_3_SCREEN_H
#define INC_26_4_3_SCREEN_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "constants.h"
#include "utilities.h"
#include "window.h"

class Screen {
    vector<Window*> windows;

    void print(int);
public:
    Screen();

    void addWindow();

    void doPrint(int index = 0);

    void doExit();
};

#endif //INC_26_4_3_SCREEN_H
