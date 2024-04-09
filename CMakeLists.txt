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
        Headers/GenerateData.h
        Class/GenerateSortedData.cpp
        Class/GeneratePartialySortedData.cpp
        Headers/GeneratePartialySortedData.h
        Class/Tester.cpp
        Headers/Tester.h
        Class/QuickSortRight.cpp
        Headers/QuickSortRight.h
        Class/ShellNotOptimal.cpp
        Headers/ShellNotOptimal.h
        Class/QuickSortLeft.cpp
        Headers/QuickSortLeft.h
        Class/QuickSortRandom.cpp
        Headers/QuickSortRandom.h
        Class/IntMenu.cpp
        Headers/IntMenu.h
        Class/FloatMenu.cpp
        Class/DoubleMenu.cpp
        Headers/DoubleMenu.h
        Class/CharMenu.cpp
        Headers/CharMenu.h)
