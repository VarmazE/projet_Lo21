cmake_minimum_required(VERSION 3.27)
project(projet_Lo21 C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_Lo21 sources/main.c
        headers/regles.h
        sources/regles.c)
