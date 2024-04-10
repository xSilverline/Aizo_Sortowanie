//
// Created by Silver on 26.03.2024.
//

#include "../Headers/ShellSort.h"
void calculate(auto *tab,int size);
int getShift(int size);

void ShellSort::sortInt(int *tab, int size) {
    calculate(tab,size);
}

void ShellSort::sortFloat(float *tab, int size) {
    calculate(tab,size);
}

void ShellSort::sortDouble(double *tab, int size) {
    calculate(tab,size);
}

void ShellSort::sortChar(char *tab, int size) {
    calculate(tab,size);
}
void calculate(auto *tab,int size)
{
    int s = getShift(size);


    for(s;s>0;s/=3)
    {
        for(int i = 0; i<s; i++)
        {

            int j = i+s;
            while(j<size)
            {
                auto current = tab[j];
                if(tab[j-s] > current)
                {
                    tab[j-s] = tab[j];
                    tab[j] = current;
                }
                j+=s;
            }

        }
    }

}


int getShift(int size)
{ // Odstęp (3^k-1)/2 , Knuth 1973 ( O N^(3/2) )
    int shift = 1;
    while(shift<size)
    {
        shift = shift*3 + 1;
    }
    shift = shift/9;

    if(shift == 0)
        return 1;
    else
        return shift;

}

