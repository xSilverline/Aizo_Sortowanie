//
// Created by Silver on 26.03.2024.
//

#include "../Headers/HeapSort.h"
void calculate(auto *tab,int size);
void heapify(auto *tab, int size, int i);
void buildHeap(auto*tab, int size);

void HeapSort::sortInt(int *tab, int size) {
    calculate(tab,size);
}

void HeapSort::sortFloat(float *tab, int size) {
    calculate(tab,size);
}

void HeapSort::sortDouble(double *tab, int size) {
    calculate(tab,size);
}

void HeapSort::sortChar(char *tab, int size) {
    calculate(tab,size);
}
void calculate(auto *tab,int size)
{
    buildHeap(tab,size); // budowanie kopca
    int heapsize = size-1;
    for(int i = size-1; i>0;i--)
    {
        auto temp = tab[i]; // swap
        tab[i] = tab[0];
        tab[0] = temp;
        heapsize -=1; // ostatni element jest już posortowany
        heapify(tab,heapsize,0); // przywracanie własności
    }

}

void heapify(auto *tab, int size, int i) //left 2i , right 2i+1 , parent i/2
{
    int l = 1+2*i; // index od 0
    int r = 1+2*i+1;
    int largest = 0;

    if(l<=size && tab[l] > tab[i])
        largest = l;
    else
        largest = i;
    if(r<=size && tab[r] > tab[largest])
        largest = r;
    if(largest != i)
    {
        auto temp = tab[i];
        tab[i] = tab[largest];
        tab[largest] = temp;
        heapify(tab,size,largest);
    }
}

void buildHeap(auto *tab, int size)
{

    for(int i = (size-1)/2; i>0;i--)
    {
        heapify(tab,size,i);
    }
}