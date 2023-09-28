#include "../include/screen.h"

// Private. Вызывает отрисовку указанного window
void Screen::print(int index) {
    const int displayWidth = windows[0]->getMaxWidth();
    const int displayHeight = windows[0]->getMaxHeight();
    auto windowSize = windows[index]->getWindowSize();
    auto heightTop = windowSize[0][0];
    auto heightBottom = heightTop + windowSize[0][1];
    auto widthLeft = windowSize[1][0];
    auto widthRight = widthLeft + windowSize[1][1];

    std::cout << "display " << displayWidth << "(width) x " << displayHeight << "(height)" << std::endl;
    std::cout << "window width: " << widthLeft << " x " << widthRight << std::endl;
    std::cout << "window height: " << heightTop << " x " << heightBottom << std::endl;

    std::cout << std::endl;
    for (int i = 0; i < displayHeight; ++i) {
        for (int line = 0; line < displayWidth; ++line) {
            bool isSign = ((line >= widthLeft) && (line < widthRight) && ((i >= heightTop) && (i < heightBottom)));
            std::cout << (isSign ? "* " : "- ");
        }
        std::cout << std::endl;
    }
}

// При инициализации создаёт первый элемент vector<Window*>, который является представлением дисплея
Screen::Screen() {
    std::cout << "CREATE MONITOR:" << std::endl;
    auto maxWidth = putNumeric({20, MONITOR_MAX_WIDTH }, {}, "max WIDTH of MONITOR");
    auto maxHeight = putNumeric({20, MONITOR_MAX_HEIGHT }, {}, "max HEIGHT of MONITOR");
    auto* display = new Window{WindowType::MONITOR, maxHeight, maxWidth};
    windows.emplace_back(display);
    std::cout << "Display created" << std::endl;
}

// Вызывать при добавлении нового window. Добавляет в vector<Window*> окна начиная с index > 0
void Screen::addWindow() {
    auto* simpleWindow = new Window{WindowType::SIMPLE, windows[0]->getMaxHeight() , windows[0]->getMaxWidth()};
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

int Screen::getCount() {
    return !windows.empty() ? (int)windows.size() : 0;
}

// Вызывать при размонтировании
void Screen::doExit() {
    if (!windows.empty()) {
        for (const auto &i : windows) delete i;
        windows.clear();
    }
}
