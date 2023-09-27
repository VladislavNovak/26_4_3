#ifndef INC_26_4_3_WINDOW_H
#define INC_26_4_3_WINDOW_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "constants.h"
#include "utilities.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Window {
    WindowType windowType;
    // По сути, это высота дисплея
    const int maxHeight = 50;
    // По сути, это ширина дисплея
    const int maxWidth = 80;
    // Высота окна. Где [0] это базовая точка по Y, а [1] это высота
    vector<int> heightW = {0, 0};
    // Ширина окна. Где [0] это базовая точка по X, а [1] это ширина
    vector<int> widthW = {0, 0};

    void putSize(SizeType, int);

public:

    // Устанавливает константы для maxHeight и maxWidth
    Window(WindowType, int, int);

    void changeHeight();

    void changeWidth();

    void setSize();

    [[nodiscard]] int getMaxHeight() const;

    [[nodiscard]] int getMaxWidth() const;

    vector<vector<int>> getWindowSize();
};

#endif //INC_26_4_3_WINDOW_H
