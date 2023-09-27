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
    // �� ����, ��� ������ �������
    const int maxHeight = 50;
    // �� ����, ��� ������ �������
    const int maxWidth = 80;
    // ������ ����. ��� [0] ��� ������� ����� �� Y, � [1] ��� ������
    vector<int> heightW = {0, 0};
    // ������ ����. ��� [0] ��� ������� ����� �� X, � [1] ��� ������
    vector<int> widthW = {0, 0};

    void putSize(SizeType, int);

public:

    // ������������� ��������� ��� maxHeight � maxWidth
    Window(WindowType, int, int);

    void changeHeight();

    void changeWidth();

    void setSize();

    [[nodiscard]] int getMaxHeight() const;

    [[nodiscard]] int getMaxWidth() const;

    vector<vector<int>> getWindowSize();
};

#endif //INC_26_4_3_WINDOW_H
