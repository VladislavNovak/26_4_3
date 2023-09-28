#ifndef INC_26_4_3_CONSTANTS_H
#define INC_26_4_3_CONSTANTS_H

#include <vector>

const int MONITOR_MAX_WIDTH = 50;
const int MONITOR_MAX_HEIGHT = 50;
const int FIRST_WINDOW = 1;

enum class WindowType {
    MONITOR, SIMPLE
};

enum class SizeType {
    HEIGHT, WIDTH
};

enum class Menu {
    ADD, PRINT, ABOUT, EXIT
};

#endif //INC_26_4_3_CONSTANTS_H
