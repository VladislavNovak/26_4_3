#include <iostream>
#include <vector>
#include <algorithm>
#include "utilities.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

const int DISPLAY_HEIGHT = 30;
const int DISPLAY_WIDTH = 40;

enum class WindowType { display, simple };
enum class SizeType { height, width };

class Window {
    WindowType windowType;
    const int maxHeight = 50;
    const int maxWidth = 80;
    // Где [0] это базовая точка по Y, а [1] это высота
    vector<int> heightW = { 0, 0 };
    // Где [0] это базовая точка по X, а [1] это ширина
    vector<int> widthW = { 0, 0 };

    void putSize(SizeType mode, int constrain) {
        std::string msg = mode == SizeType::height ? "height" : "width";
        auto firstPoint = putNumeric({0, constrain}, {}, ("first point by " + msg));
        auto secondPoint = putNumeric({-firstPoint, constrain - firstPoint}, {0}, ("window " + msg));

        if (secondPoint < 0) { std::swap(firstPoint, secondPoint); }

        if (mode == SizeType::height) { heightW = {firstPoint, secondPoint}; }
        else { widthW = {firstPoint, secondPoint}; }
    }
public:

    Window(WindowType type, int height, int width) : windowType(type), maxHeight(height), maxWidth(width) {};

    void changeHeight() {
        if (windowType == WindowType::display) {
            std::cout << "This window type does not support changes" << std::endl;
            return;
        }
        putSize(SizeType::height, maxHeight);
    }

    void changeWidth() {
        if (windowType == WindowType::display) {
            std::cout << "This window type does not support changes" << std::endl;
            return;
        }
        putSize(SizeType::width, maxWidth);
    }

    void setSize() {
        changeHeight();
        changeWidth();
    }

    [[nodiscard]] int getMaxHeight() const { return maxHeight; }

    [[nodiscard]] int getMaxWidth() const { return maxWidth; }

    vector<vector<int>> getWindowSize() { return {heightW, widthW}; }
};

class Screen {
    vector<Window*> windows;

    void print(int index) {
        const int displayWidth = windows[0]->getMaxWidth();
        const int displayHeight = windows[0]->getMaxHeight();
        auto windowSize = windows[index]->getWindowSize();
        auto heightTop = windowSize[0][0];
        auto heightBottom = heightTop + windowSize[0][1];
        auto widthLeft = windowSize[1][0];
        auto widthRight = widthLeft + windowSize[1][1];

        std::cout << "heightTop:: " << heightTop << std::endl;
        std::cout << "heightBottom:: " << heightBottom << std::endl;
        std::cout << "widthLeft:: " << widthLeft << std::endl;
        std::cout << "widthRight:: " << widthRight << std::endl;

        std::cout << std::endl;
        for (int i = 0; i < displayWidth; ++i) {
            for (int j = 0; j < displayHeight; ++j) {
                if ((i >= widthLeft) && (i < widthRight) && ((j >= heightTop) && (j < heightBottom))) {
                    std::cout << "* ";
                }
                else { std::cout << "- "; }
            }
            std::cout << std::endl;
        }
    }
public:
    Screen() {
        auto maxHeight = putNumeric({ 20, DISPLAY_HEIGHT }, {}, "max height of display");
        auto maxWidth = putNumeric({ 20, DISPLAY_WIDTH }, {}, "max width of display");
        auto* display = new Window{WindowType::display, maxHeight, maxWidth};
        windows.emplace_back(display);
        std::cout << std::flush << "Display created" << std::endl;
    }

    void addWindow() {
        auto* simpleWindow = new Window{WindowType::simple, windows[0]->getMaxHeight() , windows[0]->getMaxWidth()};
        simpleWindow->setSize();
        windows.emplace_back(simpleWindow);
    }

    void doPrint(int index = 0) {
        if (windows.size() < 2) {
            std::cout << "Add at least one window!" << std::endl;
            return;
        }

        if (index >= windows.size() || index == 0) {
            std::cout << "The last window will be printed!" << std::endl;
            print((int)windows.size() - 1);
        }
        else { print(index); }
    }

    void doExit() {
        if (!windows.empty()) {
            for (const auto &i : windows) delete i;
            windows.clear();
        }
    }
};

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
