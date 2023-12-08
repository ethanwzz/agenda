cmake_minimum_required(VERSION 3.24)
project(agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(agenda main.c list.c list.h cell.c cell.h timer.c)
