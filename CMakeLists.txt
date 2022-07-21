cmake_minimum_required(VERSION 3.22)
project(ReinforcementLearning)

set(CMAKE_CXX_STANDARD 23)

add_executable(ReinforcementLearning

        src/main.cpp
        src/environments/frozen_lake/environment.cpp
        src/algorithms/frozen_lake/q_learning_frozen_lake.cpp
        src/utils/utils.cpp

        headers/environments/frozen_lake/environment.h
        headers/utils/utils.h
        headers/algorithms/frozen_lake/q_learning_frozen_lake.h)