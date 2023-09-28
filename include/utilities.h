#ifndef INC_26_4_3_UTILITIES_H
#define INC_26_4_3_UTILITIES_H

#include <iostream>
#include <limits>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>
#include <typeinfo>

using std::cout;
using std::endl;
using std::vector;

template<typename T, typename N>
bool isIncludes(const T &, const N &);

template<typename T>
std::stringstream joinListToStream(const std::vector<T> &, const char* delim = ", ");

void resetBuffer();

int putInput();

int selectMenuItem(const std::vector<std::string> &, const std::string &msg = "Select and");

int putNumeric(const std::vector<int> &list = {}, const std::vector<int> &excludedList = {}, const std::string &msg = "");

void about();

#endif //INC_26_4_3_UTILITIES_H