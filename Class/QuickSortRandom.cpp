//
// Created by Silver on 09.04.2024.
//
#include <cstdlib>
#include <ctime>
#include "../Headers/QuickSortRandom.h"
void calculate(auto *tab,int p,int r);
int partition(auto *tab,int p, int r);
int partitionRand(auto *tab,int p, int r);


void QuickSortRandom::sortInt(int *tab, int size)
{
    srand(time(nullptr));
    calculate(tab,0,size-1);
}

void QuickSortRandom::sortFloat(float *tab, int size)
{
    srand(time(nullptr));
    calculate(tab,0,size-1);
}

void QuickSortRandom::sortDouble(double *tab, int size)
{
    srand(time(nullptr));
    calculate(tab,0,size-1);
}

void QuickSortRandom::sortChar(char *tab, int size)
{
    srand(time(nullptr));
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

int partition(auto *tab, int p, int r) // Random pivot - Cormen (IV), Rozd. 8
{
    auto pivot = tab[r];
    int piv = p;
    for(int i = p; i<r;i++)
    {
        if(tab[i] <= pivot)
        {
            auto temp = tab[i];
            tab[i] = tab[piv];
            tab[piv] = temp;
            piv++;
        }
    }
    auto temp = tab[piv];
    tab[piv] = tab[r];
    tab[r] = temp;

    return piv;

}
int partitionRand(auto *tab, int p, int r)
{
    int randomPivot = rand()%r+p;
    auto temp = tab[randomPivot];
    tab[randomPivot] = tab[r];
    return partition(tab,p,r);
}