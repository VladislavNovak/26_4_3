#include "../include/utilities.h"

template<typename T, typename N>
bool isIncludes(const T &range, const N &item) {
    return std::any_of(range.begin(),
                       range.end(),
                       [&item](const N &c) { return c == item; });
}

template<typename T>
std::stringstream joinListToStream(const std::vector<T> &list, const char* delim) {
    std::stringstream ss;
    std::copy(list.begin(), std::prev(list.end()), std::ostream_iterator<T>(ss, delim));
    if (!list.empty()) { ss << list.back(); }
    return ss;
}

void resetBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int putInput() {
    int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cout << "Input is invalid. Please try again:";
            resetBuffer();
            continue;
        }
        break;
    }
    resetBuffer();
    return input;
}

int selectMenuItem(const std::vector<std::string> &list, const std::string &msg) {
    std::string commands;
    for (const auto &item : list)
        commands += (item + (item != list[list.size() - 1] ? "|" : ""));

    printf("%s enter (%s):", msg.c_str(), commands.c_str());
    while (true) {
        std::string userInput;
        std::getline(std::cin, userInput);

        for (int i = 0; i < list.size(); ++i)
            if (list[i] == userInput) return i;

        std::cout << "Error. Try again:";
    }
}

int putNumeric(const std::vector<int> &list, const std::vector<int> &excludedList, const std::string &msg) {
    bool isRange = (list.size() == 2) && (list[0] < list[1]);
    bool isList = !list.empty() && (list.size() != 2 || ((list.size() == 2) && (list[0] > list[1])));
    bool isExcluded = !excludedList.empty();

    std::cout << "Enter";
    if (isRange) std::cout << " (in the range "  << joinListToStream(list, " - ").str() << ")";
    else if (isList) std::cout << " (in a list of " << joinListToStream(list).str() << ")";
    if (isExcluded) std::cout << " (excluded " << joinListToStream(excludedList).str() << ")";
    std::cout << (msg.length() ? " " + msg + ":" : ":");


    int userInput;

    while (true) {
        userInput = putInput();

        bool isTrouble = false;
        if (isRange && (userInput < list[0] || userInput > list[1])) isTrouble = true;
        if (isList && !isIncludes(list, userInput)) isTrouble = true;
        if (isExcluded && isIncludes(excludedList, userInput)) isTrouble = true;

        if (!isTrouble) { break; }
        std::cout << "Error.Try again:";
    }
    return userInput;
}

void about() {
    std::cout << "You can create a buffer of multiple windows." << std::endl;
    std::cout << "The first is the screen itself, which is a limitation for the rest of the windows." << std::endl;
    std::cout << "The rest are windows that save data between calls" << std::endl;
}
