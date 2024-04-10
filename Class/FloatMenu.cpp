//
// Created by Silver on 09.04.2024.
//
#include <iostream>
#include "../Headers/FloatMenu.h"
#include "../Headers/GenerateData.h"
#include "../Headers/GenerateSortedData.h"
#include "../Headers/GeneratePartialySortedData.h"
#include "../Headers/InsertionSort.h"
#include "../Headers/HeapSort.h"
#include "../Headers/QuickSort.h"
#include "../Headers/ShellSort.h"
#include "../Headers/Tester.h"
#include "../Headers/ShellNotOptimal.h"
#include "../Headers/QuickSortRight.h"
#include "../Headers/QuickSortLeft.h"
#include "../Headers/QuickSortRandom.h"
#include <chrono>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

FloatMenu::FloatMenu()
{
    type = 2;
    sizeOfArray = 0;
    freq = 0.0;
    counterStart = 0;

}

void FloatMenu::startCounter() // FUNKCJA STARTUJaCA LICZNIK DO POMIARU CZASU
{
    LARGE_INTEGER largeInteger;
    if(!QueryPerformanceFrequency(& largeInteger))
        cout<<"Blad zliczania czasu"<<endl;

    freq = double(largeInteger.QuadPart) / 1000.0;

    QueryPerformanceCounter(& largeInteger);
    counterStart = largeInteger.QuadPart;
}

double FloatMenu::getCounter() // FUNKCJA ZWRACAJaCA OBECNY STAN LICZNIKA
{
    LARGE_INTEGER largeInteger;
    QueryPerformanceCounter(& largeInteger);
    return double(largeInteger.QuadPart-counterStart)/freq;
}

void FloatMenu::printData(auto *tab,int s) // FUNKCJA WYŚWIETLAJaCA DANE Z TABLICY
{
    for(int i=0;i<s;i++)
    {
        cout<<tab[i]<<" ";

    }
    cout<<endl<<endl;
}


void FloatMenu::showMenu() {

    int action = 0;

    while(true)
    {
        cout<<"Podaj numer akcji do wykonania:\n";
        cout<<"1. Wygeneruj nowe dane\n2. Sortowanie przez wstawianie\n3. Sortowanie przez kopcowanie\n4. Sortowanie szybkie\n5. Sortowanie Shella\n6. Wczytaj dane z pliku\n7. PELNE TESTOWANIE\n8. Sortowanie szybkie (prawy pivot)\n9. Sortowanie szybkie (lewy pivot)\n10. Sortowanie szybkie (Random pivot)\n11. Sortowanie shella (N/2^k)\n";
        cin>>action;
        if(cin.fail())
        {
            cout << "Blad danych wejsciowych\n";
            cin.clear();
            cin.ignore();
        }

        if(action == 1) // GENEROWANIE NOWEJ TABLICY DANYCH DLA ZADANEGO TYPU
        {

            int gentype=0;
            cout<<"Generowanie nowych danych\nPodaj rozmiar tablicy:  ";
            cin>>sizeOfArray;
            if(sizeOfArray < 0 || cin.fail())
            {
                cin.clear();
                cin.ignore();

                cout<<"Blad danych! \n\n";
                break;
            }

            cout<<"Rodzaj danych do wygenerowania: "<<endl;
            cout<<"1. Losowe\n2. Posortowane rosnaco\n3. Posortowane malejaco\n4. Czesciowo posortowane (33%)\n5. Czesciowo posortowane (66%)"<<endl;
            cin>>gentype;
            if(gentype < 0 || cin.fail())
            {
                cin.clear();
                cin.ignore();

                cout<<"Blad danych! \n\n";
                break;
            }

            if(gentype == 1)
            {
                generateRandomData();
            }
            else if(gentype == 2)
            {
                generateSortedData(1);
            }
            else if(gentype == 3)
            {
                generateSortedData(0);
            }
            else if(gentype == 4)
            {
                generatePartialySortedData(33);
            }
            else if(gentype == 5)
            {
                generatePartialySortedData(66);
            }
            else
            {
                cout<<"Dane nie zostaly wygenerowane"<<endl;
            }


            cout<<"Wygenerowano!\n\n";

        }
        else if(action == 2) //     SORTOWANIE PRZEZ WSTAWIANIE - WYWOlANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie przez wstawianie\n";
            double algoTime = 0.0;

            float *tempArray = new float [sizeOfArray];
            copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
            printData(tempArray, sizeOfArray);
            startCounter();
            InsertionSort::sortFloat(tempArray,sizeOfArray);
            algoTime = getCounter();
            printData(tempArray,sizeOfArray);

            cout<<endl<<"Czas dzialania: "<<algoTime<<endl;
            if(checkData(tempArray,sizeOfArray))
            {
                cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
            }
            else
                cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

            delete[] tempArray;

        }
        else if(action == 3) //     SORTOWANIE PRZEZ KOPCOWANIE - WYWOlANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie przez kopcowanie"<<endl;

            double algoTime = 0.0;

            float *tempArray = new float [sizeOfArray];
            copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
            printData(tempArray, sizeOfArray);
            startCounter();
            HeapSort::sortFloat(tempArray,sizeOfArray);
            algoTime = getCounter();
            printData(tempArray,sizeOfArray);
            checkData(tempArray,sizeOfArray);

            cout<<endl<<"Czas dzialania: "<<algoTime<<endl;
            if(checkData(tempArray,sizeOfArray))
            {
                cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
            }
            else
                cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

            delete[] tempArray;


        }
        else if(action == 4) //     SORTOWANIE SZYBKIE - WYWOlANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie szybkie"<<endl;
            double algoTime = 0.0;


            float *tempArray = new float [sizeOfArray];
            copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
            printData(tempArray, sizeOfArray);
            startCounter();
            QuickSort::sortFloat(tempArray,sizeOfArray);
            algoTime = getCounter();
            printData(tempArray,sizeOfArray);
            checkData(tempArray,sizeOfArray);

            cout<<endl<<"Czas dzialania: "<<algoTime<<endl;
            if(checkData(tempArray,sizeOfArray))
            {
                cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
            }
            else
                cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;
            delete[] tempArray;


        }
        else if(action == 5) //     SORTOWANIE SHELLA - WYWOlANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie Shella"<<endl;
            double algoTime = 0.0;

            float *tempArray = new float[sizeOfArray];
            copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
            printData(tempArray, sizeOfArray);
            startCounter();
            ShellSort::sortFloat(tempArray,sizeOfArray);
            algoTime = getCounter();
            printData(tempArray,sizeOfArray);
            checkData(tempArray,sizeOfArray);

            cout<<endl<<"Czas dzialania: "<<algoTime<<endl;
            if(checkData(tempArray,sizeOfArray))
            {
                cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
            }
            else
                cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

            delete[] tempArray;



        }
        else if(action == 6) // WCZYTANIE DANYCH Z PLIKU
        {
            floatDataArray = new float[sizeOfArray];
            readData(floatDataArray);
            printData(floatDataArray,sizeof(floatDataArray));

        }
        else if(action == 7) // PElNE TESTOWANIE Z POWTÓRZENIEM 100 RAZY, POMIAR CZASU ŚREDNIEGO, SPRAWDZENIE POPRAWNOŚCI SORTOWANIA
        {
            cout<<"Podaj rozmiar danych: ";
            cin>>sizeOfArray;

            if(sizeOfArray < 0 || cin.fail())
            {
                cin.clear();
                cin.ignore();

                cout<<"Blad danych! \n\n";
                break;
            }
            Tester tester(sizeOfArray,type);
            tester.testSorting();

        }
        else if(action == 8) //     SORTOWANIE SZYBKIE - WYWOlANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie szybkie (prawy pivot)"<<endl;
            double algoTime = 0.0;


            float *tempArray = new float[sizeOfArray];
            copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
            printData(tempArray, sizeOfArray);
            startCounter();
            QuickSortRight::sortFloat(tempArray,sizeOfArray);
            algoTime = getCounter();
            printData(tempArray,sizeOfArray);
            checkData(tempArray,sizeOfArray);

            cout<<endl<<"Czas dzialania: "<<algoTime<<endl;
            if(checkData(tempArray,sizeOfArray))
            {
                cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
            }
            else
                cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;
            delete[] tempArray;


        }
        else if(action == 9) //     SORTOWANIE SZYBKIE - WYWOlANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie szybkie (lewy pivot)"<<endl;
            double algoTime = 0.0;


            float *tempArray = new float[sizeOfArray];
            copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
            printData(tempArray, sizeOfArray);
            startCounter();
            QuickSortLeft::sortFloat(tempArray,sizeOfArray);
            algoTime = getCounter();
            printData(tempArray,sizeOfArray);
            checkData(tempArray,sizeOfArray);

            cout<<endl<<"Czas dzialania: "<<algoTime<<endl;
            if(checkData(tempArray,sizeOfArray))
            {
                cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
            }
            else
                cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;
            delete[] tempArray;


        }
        else if(action == 10) //     SORTOWANIE SZYBKIE - WYWOlANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie szybkie (random pivot)"<<endl;
            double algoTime = 0.0;


            float *tempArray = new float[sizeOfArray];
            copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
            printData(tempArray, sizeOfArray);
            startCounter();
            QuickSortRandom::sortFloat(tempArray,sizeOfArray);
            algoTime = getCounter();
            printData(tempArray,sizeOfArray);
            checkData(tempArray,sizeOfArray);

            cout<<endl<<"Czas dzialania: "<<algoTime<<endl;
            if(checkData(tempArray,sizeOfArray))
            {
                cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
            }
            else
                cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;
            delete[] tempArray;


        }
        else if(action == 11) //     SORTOWANIE SHELLA - WYWOlANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie Shella"<<endl;
            double algoTime = 0.0;

            float *tempArray = new float[sizeOfArray];
            copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
            printData(tempArray, sizeOfArray);
            startCounter();
            ShellNotOptimal::sortFloat(tempArray,sizeOfArray);
            algoTime = getCounter();
            printData(tempArray,sizeOfArray);
            checkData(tempArray,sizeOfArray);

            cout<<endl<<"Czas dzialania: "<<algoTime<<endl;
            if(checkData(tempArray,sizeOfArray))
            {
                cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
            }
            else
                cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

            delete[] tempArray;

        }


    }
}

void FloatMenu::generateRandomData()
{
    GenerateData generateData;

    floatDataArray = GenerateData::generateFloat(sizeOfArray);
    printData(floatDataArray, sizeOfArray);


}

void FloatMenu::generateSortedData(int flag)
{
    GenerateSortedData sortedData(flag);

    floatDataArray = GenerateSortedData::generateFloat(sizeOfArray);
    printData(floatDataArray, sizeOfArray);

}

void FloatMenu::generatePartialySortedData(int part)
{
    GeneratePartialySortedData partialySortedData(part);

    floatDataArray = GeneratePartialySortedData::generateFloat(sizeOfArray);
    printData(floatDataArray, sizeOfArray);

}

void FloatMenu::readData(auto array)
{
    string fileName;
    cout<<"Wczytywanie danych z pliku\nPodaj nazwe pliku:  ";
    cin>>fileName;

    ifstream fileWithData(fileName);

    if(fileWithData.is_open())
    {
        int i = 0;
        fileWithData >> sizeOfArray;
        for(i; i<sizeOfArray && fileWithData.good();i++)
        {
            fileWithData>>array[i];
        }

        if(i == sizeOfArray)
            cout<<"Wczytywanie zakonczone prawidlowo!"<<endl<<endl;
        else
            cout<<"Blad wczytywania danych!"<<endl<<endl;
    }

}

int FloatMenu::checkData(auto *tab,int size) // FUNKCJA SPRAWDZAJaCA POPRAWNOŚC SORTOWANIA
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


