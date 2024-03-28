cmake_minimum_required(VERSION 3.27)
project(Aizo_Sortowanie)

set(CMAKE_CXX_STANDARD 20)

add_executable(Aizo_Sortowanie Class/main.cpp
        Class/InsertionSort.cpp
        Headers/InsertionSort.h
        Class/HeapSort.cpp
        Headers/HeapSort.h
        Class/QuickSort.cpp
        Headers/QuickSort.h
        Class/ShellSort.cpp
        Headers/ShellSort.h
        Class/GenerateData.cpp
        Headers/GenerateData.h)
