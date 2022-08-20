CMAKE_MINIMUM_REQUIRED(VERSION 3.24)

project(tictactoe)

#language standards
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 23)

#flags
set(CMAKE_CXX_FLAGS "-Wall")

#source files
FILE(GLOB SOURCE_FILES src/**/*.cpp)

#include
include_directories(src/include)
include_directories(lib/include)

add_executable(tictactoe src/main.cpp ${SOURCE_FILES})

#link libs
target_link_libraries(tictactoe ncurses)