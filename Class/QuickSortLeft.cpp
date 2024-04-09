//
// Created by Silver on 09.04.2024.
//

#include "../Headers/QuickSortLeft.h"
void calculate(auto *tab,int p,int r);
int partition(auto *tab,int p, int r);

void QuickSortLeft::sortInt(int *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSortLeft::sortFloat(float *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSortLeft::sortDouble(double *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSortLeft::sortChar(char *tab, int size)
{
    calculate(tab,0,size-1);
}
void calculate(auto *tab,int p,int r)
{
    if(p<r)
    {
        int q = partition(tab,p,r);
        calculate(tab,p,q-1);
        calculate(tab,q+1,r);
    }
}

int partition(auto *tab, int p, int r) // dwa indeksy z obu stron, pivot po środku - Cormen (IV), Rozd. 8
{
    auto pivot = tab[p];
    int j = r;

    for(int i = r; i>p;i--)
    {
        if(tab[i] > pivot)
        {
            auto temp = tab[i];
            tab[i] = tab[j];
            tab[j]=temp;
            j--;
        }
    }
    auto temp = tab[j];
    tab[j] = tab[p];
    tab[p] = temp;

    return j;

}