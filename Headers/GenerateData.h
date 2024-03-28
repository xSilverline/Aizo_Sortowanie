//
// Created by Silver on 26.03.2024.
//

#ifndef AIZO_SORTOWANIE_GENERATEDATA_H
#define AIZO_SORTOWANIE_GENERATEDATA_H

#include <random>
#include <iostream>

class GenerateData{

public:
    GenerateData();
    static int * generateInt(int size);
    static float * generateFloat(int size);
    static double * generateDouble(int size);
    static char * generateChar(int size);


};


#endif //AIZO_SORTOWANIE_GENERATEDATA_H
