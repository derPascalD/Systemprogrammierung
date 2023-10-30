cmake_minimum_required(VERSION 3.26)
project(B03 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(B03
        main.c
        verwaltung.c
        verwaltung.h)
