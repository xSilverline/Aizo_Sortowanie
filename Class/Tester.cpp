//
// Created by Silver on 07.04.2024.
//
#include <windows.h>
#include "../Headers/Tester.h"
#include "../Headers/GenerateData.h"
#include "../Headers/GenerateSortedData.h"
#include "../Headers/GeneratePartialySortedData.h"
#include "../Headers/InsertionSort.h"
#include "../Headers/HeapSort.h"
#include "../Headers/QuickSort.h"
#include "../Headers/ShellSort.h"
#include "../Headers/ShellNotOptimal.h"
#include "../Headers/QuickSortRight.h"
#include "../Headers/QuickSortLeft.h"
#include "../Headers/QuickSortRandom.h"

using namespace std;

double testfreq = 0.0;
long long int testcounterStart = 0;
int sizeOfTestArray;
int testtype;

Tester::Tester(int s, int t)
{
    sizeOfTestArray = s;
    testtype=t;
}



void Tester::startCounter() // FUNKCJA STARTUJĄCA LICZNIK DO POMIARU CZASU
{
    LARGE_INTEGER largeInteger;
    if(!QueryPerformanceFrequency(&largeInteger))
        cout<<"Blad zliczania czasu"<<endl;

    testfreq = double(largeInteger.QuadPart) / 1000.0;

    QueryPerformanceCounter(& largeInteger);
    testcounterStart = largeInteger.QuadPart;
}

double Tester::getCounter() // FUNKCJA ZWRACAJĄCA OBECNY STAN LICZNIKA
{
    LARGE_INTEGER largeInteger;
    QueryPerformanceCounter(&largeInteger);
    return double(largeInteger.QuadPart-testcounterStart)/testfreq;
}

int checkData(auto *tab,int size) // FUNKCJA SPRAWDZAJĄCA POPRAWNOŚC SORTOWANIA
{
    int n=1;
    while(n<size)
    {
        if(tab[n] < tab[n-1])
        {

            return 0;
        }
        n++;
    }
    return 1;
}



void Tester::testDouble(int *passCounter, double *timeCounter, int gentype)
{
    double *tab;
    auto *p1 = new double [sizeOfTestArray];
    auto *p2 = new double [sizeOfTestArray];
    auto *p3 = new double [sizeOfTestArray];
    auto *p4 = new double [sizeOfTestArray];
    auto *p5 = new double [sizeOfTestArray];
    auto *p6 = new double [sizeOfTestArray];
    auto *p7= new double [sizeOfTestArray];
    auto *p8 = new double [sizeOfTestArray];

    if (gentype == 1)
        GenerateData generateData;
    else if (gentype == 2)
        GenerateSortedData sortedData(1);
    else if (gentype == 3)
        GenerateSortedData sortedData(0);
    else if (gentype == 4)
        GeneratePartialySortedData partialySortedData(33);
    else if (gentype == 5)
        GeneratePartialySortedData partialySortedData(66);


    for(int i = 0; i<100;i++)
    {
        if (gentype == 1)
            tab = GenerateData::generateDouble(sizeOfTestArray);
        else if (gentype == 2 || gentype == 3)
            tab = GenerateSortedData::generateDouble(sizeOfTestArray);
        else if (gentype == 4 || gentype == 5)
            tab = GeneratePartialySortedData::generateDouble(sizeOfTestArray);



        copy(tab, tab + sizeOfTestArray, p1);
        copy(tab, tab + sizeOfTestArray, p2);
        copy(tab, tab + sizeOfTestArray, p3);
        copy(tab, tab + sizeOfTestArray, p4);
        copy(tab, tab + sizeOfTestArray, p5);
        copy(tab, tab + sizeOfTestArray, p6);
        copy(tab, tab + sizeOfTestArray, p7);
        copy(tab, tab + sizeOfTestArray, p8);

        startCounter();
        InsertionSort::sortDouble(p1, sizeOfTestArray);
        timeCounter[0] += getCounter();

        if (checkData(p1, sizeOfTestArray) == 1)
            passCounter[0]--;

        startCounter();
        HeapSort::sortDouble(p2, sizeOfTestArray);
        timeCounter[1] += getCounter();

        if (checkData(p2, sizeOfTestArray) == 1)
            passCounter[1]--;

        startCounter();
        QuickSort::sortDouble(p3, sizeOfTestArray);
        timeCounter[2] += getCounter();

        if (checkData(p3, sizeOfTestArray) == 1)
            passCounter[2]--;

        startCounter();
        QuickSortRight::sortDouble(p4, sizeOfTestArray);
        timeCounter[3] += getCounter();

        if (checkData(p4, sizeOfTestArray) == 1)
            passCounter[3]--;

        startCounter();
        QuickSortLeft::sortDouble(p5, sizeOfTestArray);
        timeCounter[4] += getCounter();

        if (checkData(p5, sizeOfTestArray) == 1)
            passCounter[4]--;

        startCounter();
        QuickSortRandom::sortDouble(p6, sizeOfTestArray);
        timeCounter[5] += getCounter();

        if (checkData(p6, sizeOfTestArray) == 1)
            passCounter[5]--;

        startCounter();
        ShellNotOptimal::sortDouble(p7, sizeOfTestArray);
        timeCounter[6] += getCounter();

        if (checkData(p7, sizeOfTestArray) == 1)
            passCounter[6]--;

        startCounter();
        ShellSort::sortDouble(p8, sizeOfTestArray);
        timeCounter[7] += getCounter();

        if (checkData(p8, sizeOfTestArray) == 1)
            passCounter[7]--;
    }

}
void Tester::testChar(int *passCounter, double *timeCounter, int gentype)
{
//    char *tab = new char [sizeOfTestArray];
    char *tab;
    char *p1 = new char [sizeOfTestArray];
    char *p2 = new char [sizeOfTestArray];
    char *p3 = new char [sizeOfTestArray];
    char *p4 = new char [sizeOfTestArray];
    char *p5 = new char [sizeOfTestArray];
    char *p6 = new char [sizeOfTestArray];
    char *p7 = new char [sizeOfTestArray];
    char *p8 = new char [sizeOfTestArray];

    if (gentype == 1) {
        GenerateData generateData;
    } else if (gentype == 2) {
        GenerateSortedData sortedData(1);
    } else if (gentype == 3) {
        GenerateSortedData sortedData(0);
    } else if (gentype == 4) {
        GeneratePartialySortedData partialySortedData(33);
    } else if (gentype == 5) {
        GeneratePartialySortedData partialySortedData(66);
    }



    for(int i = 0; i<100;i++)
    {
        if (gentype == 1) {
            tab = GenerateData::generateChar(sizeOfTestArray);
        } else if (gentype == 2 || gentype == 3 ) {
            tab = GenerateSortedData::generateChar(sizeOfTestArray);
        } else if (gentype == 4 || gentype == 5) {
            tab = GeneratePartialySortedData::generateChar(sizeOfTestArray);
        }


        copy(tab, tab + sizeOfTestArray, p1);
        copy(tab, tab + sizeOfTestArray, p2);
        copy(tab, tab + sizeOfTestArray, p3);
        copy(tab, tab + sizeOfTestArray, p4);
        copy(tab, tab + sizeOfTestArray, p5);
        copy(tab, tab + sizeOfTestArray, p6);
        copy(tab, tab + sizeOfTestArray, p7);
        copy(tab, tab + sizeOfTestArray, p8);

        startCounter();
        InsertionSort::sortChar(p1, sizeOfTestArray);
        timeCounter[0] += getCounter();

        if (checkData(p1, sizeOfTestArray) == 1)
            passCounter[0]--;

        startCounter();
        HeapSort::sortChar(p2, sizeOfTestArray);
        timeCounter[1] += getCounter();

        if (checkData(p2, sizeOfTestArray) == 1)
            passCounter[1]--;

        startCounter();
        QuickSort::sortChar(p3, sizeOfTestArray);
        timeCounter[2] += getCounter();

        if (checkData(p3, sizeOfTestArray) == 1)
            passCounter[2]--;

        startCounter();
        QuickSortRight::sortChar(p4, sizeOfTestArray);
        timeCounter[3] += getCounter();

        if (checkData(p4, sizeOfTestArray) == 1)
            passCounter[3]--;

        startCounter();
        QuickSortLeft::sortChar(p5, sizeOfTestArray);
        timeCounter[4] += getCounter();

        if (checkData(p5, sizeOfTestArray) == 1)
            passCounter[4]--;

        startCounter();
        QuickSortRandom::sortChar(p6, sizeOfTestArray);
        timeCounter[5] += getCounter();

        if (checkData(p6, sizeOfTestArray) == 1)
            passCounter[5]--;

        startCounter();
        ShellNotOptimal::sortChar(p7, sizeOfTestArray);
        timeCounter[6] += getCounter();

        if (checkData(p7, sizeOfTestArray) == 1)
            passCounter[6]--;

        startCounter();
        ShellSort::sortChar(p8, sizeOfTestArray);
        timeCounter[7] += getCounter();

        if (checkData(p8, sizeOfTestArray) == 1)
            passCounter[7]--;
    }

}

void Tester::testSorting() // FUNKCJA TESTUJĄCA Z POWTÓRZENIEM 100 RAZY, POMIAREM CZASU ŚREDNIEGO, SPRAWDZENIEM POPRAWNOŚCI SORTOWANIA
{
    int n = 100;
    int c = n;
    int * passCounter = new int[8];
    double *timeCounter = new double [8];
    for(int i=0;i<8;i++)
    {
        passCounter[i] =n;
        timeCounter[i] = 0.0;
    }



    int gentype=0;

    cout<<"Rodzaj danych do wygenerowania: "<<endl;
    cout<<"1. Losowe\n2. Posortowane rosnaco\n3. Posortowane malejaco\n4. Czesciowo posortowane (33%)\n5. Czesciowo posortowane (66%)"<<endl;
    cin>>gentype;
    if(gentype < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore();

        cout<<"Blad danych! \n\n";
        return;
    }

    if(testtype == 1)
    {
        testInt(passCounter,timeCounter,gentype);
    }
    else if (testtype == 2)
    {
        testFloat(passCounter,timeCounter,gentype);
    }
    else if (testtype == 3)
    {
        testDouble(passCounter,timeCounter,gentype);
    }
    else if (testtype == 4)
    {
        testChar(passCounter,timeCounter,gentype);
    }


    if(passCounter[0] == 0)
        cout<<"Insertion sort -> OK"<<endl;
    else
        cout<<"Insertion sort -> FAIL"<<endl;

    if(passCounter[1] == 0)
        cout<<"Heap sort -> OK"<<endl;
    else
        cout<<"Heap sort -> FAIL"<<endl;

    if(passCounter[2] == 0)
        cout<<"Quick sort (mid) -> OK"<<endl;
    else
        cout<<"Quick sort (mid)-> FAIL"<<endl;

    if(passCounter[3] == 0)
        cout<<"Quick sort (right) -> OK"<<endl;
    else
        cout<<"Quick sort (right) -> FAIL"<<endl;

    if(passCounter[4] == 0)
        cout<<"Quick sort (left) -> OK"<<endl;
    else
        cout<<"Quick sort (left) -> FAIL"<<endl;

    if(passCounter[5] == 0)
        cout<<"Quick sort (random) -> OK"<<endl;
    else
        cout<<"Quick sort (random) -> FAIL"<<endl;

    if(passCounter[6] == 0)
        cout<<"Shell sort (N/2^k) -> OK"<<endl;
    else
        cout<<"Shell sort (N/2^k) -> FAIL"<<endl;

    if(passCounter[7] == 0)
        cout<<"Shell sort ((3^k-1)/2) -> OK"<<endl;
    else
        cout<<"Shell sort ((3^k-1)/2) -> FAIL"<<endl;

    cout<<endl<<"Sredni czas dzialania algorytmow ("<<c<<" powtorzen) : "<<endl<<endl;
    cout<<"Sortowanie przez wstawianie: "<<timeCounter[0]/100<<" ms"<<endl;
    cout<<"Sortowanie przez kopcowanie: "<<timeCounter[1]/100<<" ms"<<endl;
    cout<<"Sortowanie szybkie (mid): "<<timeCounter[2]/100<<" ms"<<endl;
    cout<<"Sortowanie szybkie (right): "<<timeCounter[3]/100<<" ms"<<endl;
    cout<<"Sortowanie szybkie (left): "<<timeCounter[4]/100<<" ms"<<endl;
    cout<<"Sortowanie szybkie (rand): "<<timeCounter[5]/100<<" ms"<<endl;
    cout<<"Sortowanie shella (N/2^k): "<<timeCounter[6]/100<<" ms"<<endl;
    cout<<"Sortowanie shella ((3^k-1)/2): "<<timeCounter[7]/100<<" ms"<<endl<<endl;


//    cout<<"TEST"<<endl;
//    startCounter();
//    Sleep(1000);
//    double test = getCounter();
//    cout<<"Dokladnosc zegara (1000): "<<test<<endl<<endl;

    delete[] passCounter;
    delete[] timeCounter;


}

void Tester::testFloat(int *passCounter, double *timeCounter, int gentype) {
    float *tab;
//    auto *tab = new float [sizeOfTestArray];
    auto *p1 = new float [sizeOfTestArray];
    auto *p2 = new float [sizeOfTestArray];
    auto *p3 = new float [sizeOfTestArray];
    auto *p4 = new float [sizeOfTestArray];
    auto *p5 = new float [sizeOfTestArray];
    auto *p6 = new float [sizeOfTestArray];
    auto *p7 = new float [sizeOfTestArray];
    auto *p8 = new float [sizeOfTestArray];

    if (gentype == 1) {
        GenerateData generateData;
    } else if (gentype == 2) {
        GenerateSortedData sortedData(1);
    } else if (gentype == 3) {
        GenerateSortedData sortedData(0);
    } else if (gentype == 4) {
        GeneratePartialySortedData partialySortedData(33);
    } else if (gentype == 5) {
        GeneratePartialySortedData partialySortedData(66);
    }



    for(int i = 0; i<100;i++)
    {
        if (gentype == 1) {
            tab = GenerateData::generateFloat(sizeOfTestArray);
        } else if (gentype == 2 || gentype == 3) {
            tab = GenerateSortedData::generateFloat(sizeOfTestArray);
        } else if (gentype == 4 || gentype == 5) {
            tab = GeneratePartialySortedData::generateFloat(sizeOfTestArray);
        }


        copy(tab, tab + sizeOfTestArray, p1);
        copy(tab, tab + sizeOfTestArray, p2);
        copy(tab, tab + sizeOfTestArray, p3);
        copy(tab, tab + sizeOfTestArray, p4);
        copy(tab, tab + sizeOfTestArray, p5);
        copy(tab, tab + sizeOfTestArray, p6);
        copy(tab, tab + sizeOfTestArray, p7);
        copy(tab, tab + sizeOfTestArray, p8);

        startCounter();
        InsertionSort::sortFloat(p1, sizeOfTestArray);
        timeCounter[0] += getCounter();

        if (checkData(p1, sizeOfTestArray) == 1)
            passCounter[0]--;

        startCounter();
        HeapSort::sortFloat(p2, sizeOfTestArray);
        timeCounter[1] += getCounter();

        if (checkData(p2, sizeOfTestArray) == 1)
            passCounter[1]--;

        startCounter();
        QuickSort::sortFloat(p3, sizeOfTestArray);
        timeCounter[2] += getCounter();

        if (checkData(p3, sizeOfTestArray) == 1)
            passCounter[2]--;

        startCounter();
        QuickSortRight::sortFloat(p4, sizeOfTestArray);
        timeCounter[3] += getCounter();

        if (checkData(p4, sizeOfTestArray) == 1)
            passCounter[3]--;

        startCounter();
        QuickSortLeft::sortFloat(p5, sizeOfTestArray);
        timeCounter[4] += getCounter();

        if (checkData(p5, sizeOfTestArray) == 1)
            passCounter[4]--;

        startCounter();
        QuickSortRandom::sortFloat(p6, sizeOfTestArray);
        timeCounter[5] += getCounter();

        if (checkData(p6, sizeOfTestArray) == 1)
            passCounter[5]--;

        startCounter();
        ShellNotOptimal::sortFloat(p7, sizeOfTestArray);
        timeCounter[6] += getCounter();

        if (checkData(p7, sizeOfTestArray) == 1)
            passCounter[6]--;

        startCounter();
        ShellSort::sortFloat(p8, sizeOfTestArray);
        timeCounter[7] += getCounter();

        if (checkData(p8, sizeOfTestArray) == 1)
            passCounter[7]--;
    }

}

void Tester::testInt(int *passCounter, double *timeCounter, int gentype) {
    int *tab;

    int *p1 = new int[sizeOfTestArray];
    int *p2 = new int[sizeOfTestArray];
    int *p3 = new int[sizeOfTestArray];
    int *p4 = new int[sizeOfTestArray];
    int *p5 = new int[sizeOfTestArray];
    int *p6 = new int[sizeOfTestArray];
    int *p7 = new int[sizeOfTestArray];
    int *p8 = new int[sizeOfTestArray];

    if (gentype == 1) {
        GenerateData generateData;
    } else if (gentype == 2) {
        GenerateSortedData sortedData(1);
    } else if (gentype == 3) {
        GenerateSortedData sortedData(0);
    } else if (gentype == 4) {
        GeneratePartialySortedData partialySortedData(33);
    } else if (gentype == 5) {
        GeneratePartialySortedData partialySortedData(66);
    }


    for (int i = 0; i < 100; i++) {
        if (gentype == 1) {
            tab = GenerateData::generateInt(sizeOfTestArray);
        } else if (gentype == 2 || gentype == 3) {
            tab = GenerateSortedData::generateInt(sizeOfTestArray);
        }  else if (gentype == 4 || gentype == 5) {
            tab = GeneratePartialySortedData::generateInt(sizeOfTestArray);
        }


        copy(tab, tab + sizeOfTestArray, p1);
        copy(tab, tab + sizeOfTestArray, p2);
        copy(tab, tab + sizeOfTestArray, p3);
        copy(tab, tab + sizeOfTestArray, p4);
        copy(tab, tab + sizeOfTestArray, p5);
        copy(tab, tab + sizeOfTestArray, p6);
        copy(tab, tab + sizeOfTestArray, p7);
        copy(tab, tab + sizeOfTestArray, p8);


        startCounter();
        InsertionSort::sortInt(p1, sizeOfTestArray);
        timeCounter[0] += getCounter();

        if (checkData(p1, sizeOfTestArray) == 1)
            passCounter[0]--;

        startCounter();
        HeapSort::sortInt(p2, sizeOfTestArray);
        timeCounter[1] += getCounter();

        if (checkData(p2, sizeOfTestArray) == 1)
            passCounter[1]--;

        startCounter();
        QuickSort::sortInt(p3, sizeOfTestArray);
        timeCounter[2] += getCounter();

        if (checkData(p3, sizeOfTestArray) == 1)
            passCounter[2]--;

        startCounter();
        QuickSortRight::sortInt(p4, sizeOfTestArray);
        timeCounter[3] += getCounter();

        if (checkData(p4, sizeOfTestArray) == 1)
            passCounter[3]--;

        startCounter();
        QuickSortLeft::sortInt(p5, sizeOfTestArray);
        timeCounter[4] += getCounter();

        if (checkData(p5, sizeOfTestArray) == 1)
            passCounter[4]--;

        startCounter();
        QuickSortRandom::sortInt(p6, sizeOfTestArray);
        timeCounter[5] += getCounter();

        if (checkData(p6, sizeOfTestArray) == 1)
            passCounter[5]--;

        startCounter();
        ShellNotOptimal::sortInt(p7, sizeOfTestArray);
        timeCounter[6] += getCounter();

        if (checkData(p7, sizeOfTestArray) == 1)
            passCounter[6]--;

        startCounter();
        ShellSort::sortInt(p8, sizeOfTestArray);
        timeCounter[7] += getCounter();

        if (checkData(p8, sizeOfTestArray) == 1)
            passCounter[7]--;
    }

}