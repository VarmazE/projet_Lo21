cmake_minimum_required(VERSION 3.27)
project(projet_Lo21 C)

set(CMAKE_C_STANDARD 11)

add_executable(projet_Lo21 sources/main.c
        headers/regles.h
        sources/regles.c
        sources/Bases_Connaissances.c
        headers/Bases_Connaissances.h
        sources/Base_faits.c
        headers/Base_faits.h)
