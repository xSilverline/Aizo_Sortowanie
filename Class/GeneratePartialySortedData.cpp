//
// Created by Silver on 07.04.2024.
//

#include <random>
#include <chrono>
#include "../Headers/GeneratePartialySortedData.h"

std::default_random_engine generatorP;




int partOfArray = 0;

GeneratePartialySortedData::GeneratePartialySortedData(int part)
{
    partOfArray = part;
    generatorP.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

int * GeneratePartialySortedData::generateInt(int size)
{
    int *randomData= new int[size];

    int sortedSize = (size * partOfArray) / 100;
    std::uniform_int_distribution<int> distribution(sortedSize,1000);

    for(int i = 0; i<sortedSize; i++)
    {
        randomData[i] = i;
    }

    for(int i = sortedSize; i<size; i++)
    {
        randomData[i] = distribution(generatorP);
    }

    return randomData;
}

float *GeneratePartialySortedData::generateFloat(int size) {
    float *randomData= new float[size];

    int sortedSize = (size * partOfArray) / 100;
    std::uniform_real_distribution<> dist(double(sortedSize)/10.f,1000.0);
    for(int i = 0; i<sortedSize; i++)
    {
        randomData[i] = float(i)/10.f;
    }
    for(int i = sortedSize; i<size; i++)
    {
        randomData[i] =(float) dist(generatorP);
    }
    return randomData;
}

double *GeneratePartialySortedData::generateDouble(int size) {
    double *randomData= new double[size];

    int sortedSize = (size * partOfArray) / 100;
    std::uniform_real_distribution<> dist(double(sortedSize)/10.0,1000.0);
    for(int i = 0; i<sortedSize; i++)
    {
        randomData[i] = static_cast<double>(i)/10.0;
    }
    for(int i = sortedSize; i<size; i++)
    {
        randomData[i] = dist(generatorP);
    }
    return randomData;
}

char *GeneratePartialySortedData::generateChar(int size) {
    char *randomData= new char[size];
    int sortedSize = (size * partOfArray) / 100;
    std::uniform_int_distribution<char> charDist(32,126);
    for(int i = 0; i<sortedSize; i++)
    {
        randomData[i] = static_cast<char>(i);
    }
    for(int i = sortedSize ; i<size; i++)
    {
        randomData[i] = charDist(generatorP);
    }
    return randomData;
}