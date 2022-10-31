cmake_minimum_required(VERSION 3.22)
project(CS_221_Assignment1)

set(CMAKE_CXX_STANDARD 20)

file(GLOB Prob1
        "Prob1/*.h"
        "Prob1/*.cpp"
        )

file(GLOB Prob2
        "Prob2/*.h"
        "Prob2/*.cpp"
        )

file(GLOB Prob3
        "Prob3/*.h"
        "Prob3/*.cpp"
        )

add_executable(CS-221_Assignment1 ${Prob1})