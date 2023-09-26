#include <iostream>
#include <vector>
#include <algorithm>
#include "utilities.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

enum class SizeType { height, width };

class Window {
    const int maxHeight = 50;
    const int maxWidth = 80;
    // Где [0] это базовая точка по Y, а [1] это высота
    vector<int> heightW = { 0, 0 };
    // Где [0] это базовая точка по X, а [1] это ширина
    vector<int> widthW = { 0, 0 };

    void putSize(SizeType mode, int constrain, const string &msg) {
        auto firstPoint = putNumeric({0, constrain}, {}, ("base point position by " + msg));
        auto secondPoint = putNumeric({-firstPoint, constrain - firstPoint}, {0}, ("window " + msg));

        if (secondPoint < 0) { std::swap(firstPoint, secondPoint); }

        if (mode == SizeType::height) { heightW = {firstPoint, secondPoint}; }
        else { widthW = {firstPoint, secondPoint}; }
    }
public:

    Window(int height, int width) : maxHeight(height), maxWidth(width) {};

    void changeHeight() {
        putSize(SizeType::height, maxHeight, "height");
    }

    void changeWidth() {
        putSize(SizeType::width, maxWidth, "width");
    }

    void setSize() {
        changeHeight();
        changeWidth();
    }

    void print() {
        std::cout << std::endl;
        for (int i = 0; i < maxWidth; ++i) {
            for (int j = 0; j < maxHeight; ++j) {
                if ((i > widthW[0] && (i < widthW[0] + widthW[1])) && (j > heightW[0] && (j < heightW[0] + heightW[1]))) {
                    std::cout << " * ";
                }
                else {
                    std::cout << " - ";
                }
            }
            std::cout << std::endl;
        }
    }
};

// class Screen {
//     vector<int> size = { 80, 50 };
// };

int main() {
    Window window{ 20, 20 };
    window.setSize();
    window.print();

    return 0;
}
