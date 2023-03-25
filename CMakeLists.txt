cmake_minimum_required(VERSION 3.24)
project(DiningPhilosophers_v2)

set(CMAKE_CXX_STANDARD 17)

add_executable(DiningPhilosophers_v2 main.cpp view/IView.cpp view/IView.h view/ConsoleView.cpp view/ConsoleView.h view/TerminalView.cpp view/TerminalView.h EatingTable.cpp EatingTable.h PhilosopherState.h)
