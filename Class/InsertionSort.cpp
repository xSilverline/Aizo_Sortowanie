//
// Created by Silver on 26.03.2024.
//

#include "../Headers/InsertionSort.h"
//#include <iostream>
//#include <windows.h>

//using namespace std;

//double freqi = 0.0;
//long long int counterStarti = 0;

//
//void startCounteri() // FUNKCJA STARTUJĄCA LICZNIK DO POMIARU CZASU
//{
//    LARGE_INTEGER largeInteger;
//    if(!QueryPerformanceFrequency(& largeInteger))
//        cout<<"Blad zliczania czasu"<<endl;
//
//    freqi = double(largeInteger.QuadPart) / 1000.0;
//
//    QueryPerformanceCounter(& largeInteger);
//    counterStarti = largeInteger.QuadPart;
//}
//
//double getCounteri() // FUNKCJA ZWRACAJĄCA OBECNY STAN LICZNIKA
//{
//    LARGE_INTEGER largeInteger;
//    QueryPerformanceCounter(& largeInteger);
//    return double(largeInteger.QuadPart-counterStarti)/freqi;
//}

void calculate(auto *tab,int size);

void InsertionSort::sortInt(int *tab, int size)
{
    calculate(tab,size);

}
void InsertionSort::sortFloat(float *tab, int size)
{
    calculate(tab,size);

}

void InsertionSort::sortDouble(double *tab, int size)
{
    calculate(tab,size);
}

void InsertionSort::sortChar(char *tab, int size)
{
    calculate(tab,size);
}

void calculate(auto *tab,int size)
{
//    startCounteri();
    for(int i = 1; i<size; i++)
    {
        auto current = tab[i];

        for(int j = i-1; j>=0; j--)
        {
            if(tab[j] > current)
            {
                tab[j+1] = tab[j];
                tab[j] = current;
            }
        }

    }
//    cout<<"TEST XX: "<<getCounteri()<<endl<<endl;
}



InsertionSort::~InsertionSort() = default;


