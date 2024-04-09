//
// Created by Silver on 09.04.2024.
//

#include "../Headers/ShellNotOptimal.h"
void calculate(auto *tab,int size);

int getShift(int size);

void ShellNotOptimal::sortInt(int *tab, int size) {
    calculate(tab,size);
}

void ShellNotOptimal::sortFloat(float *tab, int size) {
    calculate(tab,size);
}

void ShellNotOptimal::sortDouble(double *tab, int size) {
    calculate(tab,size);
}

void ShellNotOptimal::sortChar(char *tab, int size) {
    calculate(tab,size);
}

void calculate(auto *tab,int size)
{
    int s = size/2; // Odstęp N/2^k - Shell 1959 (O N^2)

    for(s;s>0;s/=2)
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
