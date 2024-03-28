//
// Created by Silver on 26.03.2024.
//

#include "../Headers/QuickSort.h"
void calculate(auto *tab,int p,int r);
int partition(auto *tab,int p, int r);

void QuickSort::sortInt(int *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSort::sortFloat(float *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSort::sortDouble(double *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSort::sortChar(char *tab, int size)
{
    calculate(tab,0,size-1);
}
void calculate(auto *tab,int p,int r)
{
    if(p<r)
    {
        int q = partition(tab,p,r);
        calculate(tab,p,q);
        calculate(tab,q+1,r);
    }
}

int partition(auto *tab, int p, int r) // dwa pivoty z obu stron - Cormen (IV), Rozd. 8
{
    auto x = tab[p];
    int i = p-1;
    int j = r+1;
    while(true)
    {
        do
        {
           j--;
        } while(x<tab[j]);

        do
        {
            i++;
        } while (x>tab[i]);

        if(i<j)
        {
            auto temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
        else
            return j;
    }

}