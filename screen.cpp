#include "screen.h"

// Private. Вызывает отрисовку указанного window
void Screen::print(int index) {
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

// При инициализации создаёт первый элемент vector<Window*>, который является представлением дисплея
Screen::Screen() {
    auto maxHeight = putNumeric({ 20, DISPLAY_HEIGHT }, {}, "max height of display");
    auto maxWidth = putNumeric({ 20, DISPLAY_WIDTH }, {}, "max width of display");
    auto* display = new Window{WindowType::display, maxHeight, maxWidth};
    windows.emplace_back(display);
    std::cout << std::flush << "Display created" << std::endl;
}

// Вызывать при добавлении нового window. Добавляет в vector<Window*> окна начиная с index > 0
void Screen::addWindow() {
    auto* simpleWindow = new Window{WindowType::simple, windows[0]->getMaxHeight() , windows[0]->getMaxWidth()};
    simpleWindow->setSize();
    windows.emplace_back(simpleWindow);
}

// Вызывает отрисовку экранов. Можно передать индекс интересующего
void Screen::doPrint(int index) {
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

// Вызывать при размонтировании
void Screen::doExit() {
    if (!windows.empty()) {
        for (const auto &i : windows) delete i;
        windows.clear();
    }
}