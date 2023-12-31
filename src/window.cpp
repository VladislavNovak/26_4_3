#include "../include/window.h"

// Private
void Window::putSize(SizeType mode, int constrain) {
    std::string msg = mode == SizeType::HEIGHT ? "HEIGHT" : "WIDTH";
    auto firstPoint = putNumeric({0, constrain}, {}, ("first point by " + msg));
    auto secondPoint = putNumeric({-firstPoint, constrain - firstPoint}, {0}, ("window " + msg));

    if (secondPoint < 0) { std::swap(firstPoint, secondPoint); }

    if (mode == SizeType::HEIGHT) { heightW = {firstPoint, secondPoint}; }
    else { widthW = {firstPoint, secondPoint}; }
}

Window::Window(WindowType type, int height, int width) : windowType(type), maxHeight(height), maxWidth(width) {}

// ����� �������������� ��������������, ���� ����� �������� ������ ����
void Window::changeHeight() {
    if (windowType == WindowType::MONITOR) {
        std::cout << "This window type does not support changes" << std::endl;
        return;
    }
    putSize(SizeType::HEIGHT, maxHeight);
}

// ����� �������������� ��������������, ���� ����� �������� ������ ����
void Window::changeWidth() {
    if (windowType == WindowType::MONITOR) {
        std::cout << "This window type does not support changes" << std::endl;
        return;
    }
    putSize(SizeType::WIDTH, maxWidth);
}

// ����������� ��������� �������� ����. ������������ ��� �������� ����
void Window::setSize() {
    changeWidth();
    changeHeight();
}

[[nodiscard]] int Window::getMaxHeight() const { return maxHeight; }

[[nodiscard]] int Window::getMaxWidth() const { return maxWidth; }

vector<vector<int>> Window::getWindowSize() { return {heightW, widthW}; }

