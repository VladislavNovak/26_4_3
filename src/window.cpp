#include "../include/window.h"

// Private
void Window::putSize(SizeType mode, int constrain) {
    std::string msg = mode == SizeType::height ? "height" : "width";
    auto firstPoint = putNumeric({0, constrain}, {}, ("first point by " + msg));
    auto secondPoint = putNumeric({-firstPoint, constrain - firstPoint}, {0}, ("window " + msg));

    if (secondPoint < 0) { std::swap(firstPoint, secondPoint); }

    if (mode == SizeType::height) { heightW = {firstPoint, secondPoint}; }
    else { widthW = {firstPoint, secondPoint}; }
}

Window::Window(WindowType type, int height, int width) : windowType(type), maxHeight(height), maxWidth(width) {}

// ћожет использоватьс€ самосто€тельно, если нужно изменить высоту окна
void Window::changeHeight() {
    if (windowType == WindowType::display) {
        std::cout << "This window type does not support changes" << std::endl;
        return;
    }
    putSize(SizeType::height, maxHeight);
}

// ћожет использоватьс€ самосто€тельно, если нужно изменить ширину окна
void Window::changeWidth() {
    if (windowType == WindowType::display) {
        std::cout << "This window type does not support changes" << std::endl;
        return;
    }
    putSize(SizeType::width, maxWidth);
}

//  омплексна€ установка размеров окна. »спользовать при создании окна
void Window::setSize() {
    changeHeight();
    changeWidth();
}

[[nodiscard]] int Window::getMaxHeight() const { return maxHeight; }

[[nodiscard]] int Window::getMaxWidth() const { return maxWidth; }

vector<vector<int>> Window::getWindowSize() { return {heightW, widthW}; }

