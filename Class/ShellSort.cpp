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

//    for(s;s>0;s/=3)
//    {
//        for(int i = s; i<size; i++)
//        {
//            auto current = tab[i];
//
//            for(int j = i-s; j>=0; j-=s)
//            {
//                if(tab[j] > current)
//                {
//                    tab[j+s] = tab[j];
//                    tab[j] = current;
//                }
//            }
//
//        }
//    }

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

//    while(s>0)
//    {
//        for(int j = size-s-1;j>=0;j--)
//        {
//            auto x = tab[j];
//            int i = j+s;
//            while(i<=size-1 && x > tab[i])
//            {
//                tab[i-s] = tab[i];
//                i += s;
//            }
//            tab[i-s] = x;
//        }
//        s/=3;
//    }


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

