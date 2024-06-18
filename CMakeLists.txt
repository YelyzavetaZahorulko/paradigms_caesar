cmake_minimum_required(VERSION 3.28)
project(paradigms_caesar)

set(CMAKE_CXX_STANDARD 17)

add_executable(paradigms_caesar main.cpp
        math.cpp
        encrypt_decrypt.h)
