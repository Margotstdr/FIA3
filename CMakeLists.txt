cmake_minimum_required(VERSION 4.0)
project(FIA3 C)

set(CMAKE_C_STANDARD 11)


add_executable(FIA3 main.c
        pilotes.c
        pilotes.h
        ecuries.c
        ecuries.h
        grandprix.c
        grandprix.h
        initialisation.c
        initialisation.h
        classement.c
        classement.h
        couleurs.c
        couleurs.h)

