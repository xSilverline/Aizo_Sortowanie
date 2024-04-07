//
// Created by Silver on 07.04.2024.
//

#ifndef AIZO_SORTOWANIE_GENERATEPARTIALYSORTEDDATA_H
#define AIZO_SORTOWANIE_GENERATEPARTIALYSORTEDDATA_H


class GeneratePartialySortedData
        {
public:
    GeneratePartialySortedData(int part);
    static int * generateInt(int size);
    static float * generateFloat(int size);
    static double * generateDouble(int size);
    static char * generateChar(int size);


};


#endif //AIZO_SORTOWANIE_GENERATEPARTIALYSORTEDDATA_H
