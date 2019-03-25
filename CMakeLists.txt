cmake_minimum_required(VERSION 3.13)
project(vuopp2)

set(CMAKE_CXX_STANDARD 17)

add_executable(vuopp2 main.cpp ./headers/main.h ./headers/student.h ./headers/studs.h ./headers/functions.cpp)