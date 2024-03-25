cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        algorithm.cpp
        daily/225.cpp
        daily/299.cpp
        daily/1261.cpp
        daily/2789.cpp
        daily/2129.cpp
        daily/2368.cpp
        daily/2386.cpp
        daily/2575.cpp
        daily/2834.cpp
        daily/2312.cpp
        daily/2684.cpp
        daily/310.cpp
        daily/1793.cpp
        daily/1969.cpp
        daily/322.cpp
        daily/518.cpp # hard
)
add_executable(leetcode ${SOURCE_FILES})
