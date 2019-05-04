cmake_minimum_required(VERSION 3.13)
project(vuopp2)

set(-DCMAKE_SH="CMAKE_SH-NOTFOUND")
set(CMAKE_CXX_STANDARD 20)
if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -Wextra)
endif(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(vuopp2 main.cpp ./headers/main.h ./headers/student.h ./headers/studs.h ./headers/timer.h ./headers/functions.cpp)