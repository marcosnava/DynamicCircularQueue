cmake_minimum_required(VERSION 3.26)
project(DynamicCircularQueue C)

set(CMAKE_C_STANDARD 11)

add_executable(DynamicCircularQueue main.c
        Boolean.h
        CircularQueue.h
        CircularQueue.c)
