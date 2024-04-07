//
// Created by Silver on 26.03.2024.
//

#include <functional>
#include <chrono>
#include "../Headers/GenerateSortedData.h"

//std::default_random_engine generator;
//std::uniform_int_distribution<int> distribution(0,1000);
//std::uniform_int_distribution<char> charDist(32,126);
//std::uniform_real_distribution<> dist(0.0,1000.0);
int increasing = 0;

GenerateSortedData::GenerateSortedData(int flag)
{
    increasing = flag;
//    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
}
int * GenerateSortedData::generateInt(int size)
{

    int *randomData= new int[size];

    if(increasing)
    {
        for(int i = 0;i<size;i++)
        {
            randomData[i] = i;
        }
    }
    else
    {
        for(int i = 0; i<size; i++)
        {
            randomData[i] = size-i;
        }
    }


    return randomData;
}

float *GenerateSortedData::generateFloat(int size) {
    float *randomData= new float[size];


    if(increasing)
    {
        for(int i = 0;i<size;i++)
        {
            randomData[i] = static_cast<float>(i)/10.f ;
        }
    }
    else
    {
        for(int i = 0; i<size; i++)
        {
            randomData[i] = static_cast<float>(size-i)/10.f;
        }
    }
    return randomData;
}

double *GenerateSortedData::generateDouble(int size) {
    double *randomData= new double[size];
    if(increasing)
    {
        for(int i = 0;i<size;i++)
        {
            randomData[i] = static_cast<double>(i)/10.0 ;
        }
    }
    else
    {
        for(int i = 0; i<size; i++)
        {
            randomData[i] = static_cast<double>(size-i)/10.0;
        }
    }
    return randomData;
}


char *GenerateSortedData::generateChar(int size) {
    char *randomData= new char[size];
    if(size > 94)
        size = 94;
    if(increasing)
    {
        for(int i = 0;i<size;i++)
        {
            randomData[i] = static_cast<char>(i+32) ;
        }
    }
    else
    {
        for(int i = 0; i<size; i++)
        {
            randomData[i] = static_cast<char>(size-i+32);
        }
    }
    return randomData;
}


