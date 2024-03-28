//
// Created by Silver on 26.03.2024.
//

#include "../Headers/InsertionSort.h"

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
}



InsertionSort::~InsertionSort() = default;


