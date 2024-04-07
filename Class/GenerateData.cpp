//
// Created by Silver on 26.03.2024.
//

#include <functional>
#include <chrono>
#include "../Headers/GenerateData.h"

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0,1000);
std::uniform_int_distribution<char> charDist(32,126);
std::uniform_real_distribution<> dist(0.0,1000.0);

GenerateData::GenerateData()
{
    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
}
int * GenerateData::generateInt(int size)
{


    int *randomData= new int[size];
    for(int i = 0; i<size; i++)
    {
        randomData[i] = distribution(generator);
    }

    return randomData;
}

float *GenerateData::generateFloat(int size) {
    float *randomData= new float[size];
    for(int i = 0; i<size; i++)
    {
        randomData[i] =(float) dist(generator);
    }
    return randomData;
}

double *GenerateData::generateDouble(int size) {
    double *randomData= new double[size];
    for(int i = 0; i<size; i++)
    {
        randomData[i] = dist(generator);
    }
    return randomData;
}

char *GenerateData::generateChar(int size) {
    char *randomData= new char[size];
    for(int i = 0; i<size; i++)
    {
        randomData[i] = charDist(generator);
    }
    return randomData;
}


