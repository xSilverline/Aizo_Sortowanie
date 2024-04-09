//
// Created by Silver on 09.04.2024.
//

#include "../Headers/QuickSortRight.h"

void calculate(auto *tab,int p,int r);
int partition(auto *tab,int p, int r);

void QuickSortRight::sortInt(int *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSortRight::sortFloat(float *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSortRight::sortDouble(double *tab, int size)
{
    calculate(tab,0,size-1);
}

void QuickSortRight::sortChar(char *tab, int size)
{
    calculate(tab,0,size-1);
}
void calculate(auto *tab,int p,int r)
{
    int piv = (p+r)/2;
    auto pivot = tab[piv];
    tab[piv] = tab[r];
    int j = p;

    for(int i = p; i<r;i++)
    {
        if(tab[i] >= pivot)
            continue;

        auto temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
        j++;
    }
    tab[r] = tab[j];
    tab[j] = pivot;

    if(p<j-1)
        calculate(tab,p,j-1);
    if(j+1<r)
        calculate(tab,j+1,r);
}

int partition(auto *tab, int p, int r) // dwa indeksy z obu stron, pivot po środku - Cormen (IV), Rozd. 8
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
