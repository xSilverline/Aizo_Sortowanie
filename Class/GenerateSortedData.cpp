//
// Created by Silver on 26.03.2024.
//

#include <functional>
#include "../Headers/GenerateSortedData.h"


int increasing = 0;

GenerateSortedData::GenerateSortedData(int flag)
{
    increasing = flag;

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
    int limit = 1;
    int top = 95;
    int i=0;

    if(size > 95)
        limit = size/95;
    if(size < top)
        top = size;
    if(increasing)
    {
        for(i;i<top;i++)
        {
            for(int j = 0; j<limit;j++)
            {
                randomData[i*limit+j] = static_cast<char>(i+32) ;
            }
        }
        if(size > top) {
            for (int k = size % 95; k > 0; k--) {
                randomData[size - k] = static_cast<char>(127);
            }
        }


    }
    else
    {
        for(i;i<top;i++)
        {
            for(int j = 0; j<limit;j++)
            {
                randomData[i*limit+j] = static_cast<char>(top-i+32) ;
            }
        }
        if(size > top) {
            for (int k = size % 95; k > 0; k--) {
                randomData[size - k] = static_cast<char>(32);
            }
        }
//        for(i = 0; i<size; i++)
//        {
//            randomData[i] = static_cast<char>(size-i+32);
//        }
    }
    return randomData;
}


