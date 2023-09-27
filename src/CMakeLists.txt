cmake_minimum_required(VERSION 3.26)

add_executable(26_4_3 ../main.cpp
        ../include/constants.h
        ../include/utilities.h
        ../include/window.h
        ../include/screen.h
        utilities.cpp
        window.cpp
        screen.cpp
)

target_include_directories(26_4_3 PUBLIC ${CMAKE_SOURCE_DIR}/include)