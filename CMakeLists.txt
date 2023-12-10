cmake_minimum_required(VERSION 3.24)
project(agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(agenda "Partie 1-2/main.c" "Partie 1-2/list.c" "Partie 1-2/list.h" "Partie 1-2/cell.c" "Partie 1-2/cell.h" "Partie 1-2/timer.c"
        main.c
        storage.c
        storage.h
        3cell.c
        3cell.h
        3list.c
        3list.h
        agenda.c
        agenda.h)
