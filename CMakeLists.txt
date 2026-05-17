cmake_minimum_required(VERSION 4.2)
project(Modelo2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Modelo2 main.cpp
        Personaje.cpp
        Personaje.h
        Guerrero.cpp
        Guerrero.h
        Mago.cpp
        Mago.h
        Equipo.cpp
        Equipo.h)
