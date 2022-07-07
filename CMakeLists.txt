cmake_minimum_required(VERSION 3.22)
project(ReinforcementLearning)

set(CMAKE_CXX_STANDARD 23)

add_executable(ReinforcementLearning

        src/main.cpp
        src/frozen_lake/environment.cpp
        src/utils/utils.cpp

        headers/frozen_lake/environment.h
        headers/utils/utils.h)
