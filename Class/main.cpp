#include <iostream>
#include "../Headers/GenerateData.h"
#include "../Headers/GenerateSortedData.h"
#include "../Headers/GeneratePartialySortedData.h"
#include "../Headers/InsertionSort.h"
#include "../Headers/HeapSort.h"
#include "../Headers/QuickSort.h"
#include "../Headers/ShellSort.h"
#include <chrono>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

int sizeOfArray = 0;
int *intDataArray;
float *floatDataArray;
double *doubleDataArray;
char *charDataArray;
int type;
double freq = 0.0;
long long int counterStart = 0;

void getDataType();
void showMenu();
void printData(auto *tab,int s);
int checkData(auto *tab,int size);
void testSorting();
double getCounter();
void startCounter();
void readData(auto array);
void generateRandomData();
void generateSortedData(int flag);
void generatePartialySortedData(int part);
void testInt(int *passCounter, double *timeCounter,int gentype);
void testFloat(int *passCounter, double *timeCounter,int gentype);


int main()
{
    cout<<"Ustawienia Wstepne Programu"<<endl;
    getDataType();
    showMenu();
}

void startCounter() // FUNKCJA STARTUJĄCA LICZNIK DO POMIARU CZASU
{
    LARGE_INTEGER largeInteger;
    if(!QueryPerformanceFrequency(& largeInteger))
        cout<<"Blad zliczania czasu"<<endl;

    freq = double(largeInteger.QuadPart) / 1000.0;

    QueryPerformanceCounter(& largeInteger);
    counterStart = largeInteger.QuadPart;
}

double getCounter() // FUNKCJA ZWRACAJĄCA OBECNY STAN LICZNIKA
{
    LARGE_INTEGER largeInteger;
    QueryPerformanceCounter(& largeInteger);
    return double(largeInteger.QuadPart-counterStart)/freq;
}

void printData(auto *tab,int s) // FUNKCJA WYŚWIETLAJĄCA DANE Z TABLICY
{
    for(int i=0;i<s;i++)
    {
        cout<<tab[i]<<" ";

    }
    cout<<endl<<endl;
}

void showMenu() // MENU PROGRAMU
{
    int action = 0;

    while(true)
    {
        cout<<"Podaj numer akcji do wykonania:\n";
        cout<<"1. Wygeneruj nowe dane\n2. Sortowanie przez wstawianie\n3. Sortowanie przez kopcowanie\n4. Sortowanie szybkie\n5. Sortowanie Shella\n6. Wczytaj dane z pliku\n7. PELNE TESTOWANIE\n";
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
        else if(action == 2) //     SORTOWANIE PRZEZ WSTAWIANIE - WYWOŁANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie przez wstawianie\n";
            double algoTime = 0.0;


            if(type == 1 && intDataArray != nullptr)
            {
                int *tempArray = new int[sizeOfArray];
                copy(intDataArray,intDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                InsertionSort::sortInt(tempArray,sizeOfArray);
                algoTime = getCounter();
                printData(tempArray,sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;



                delete[] tempArray;

            }
            else if(type == 2 && floatDataArray != nullptr)
            {
                float *tempArray = new float[sizeOfArray];
                copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);

                printData(tempArray, sizeOfArray);
                startCounter();
                InsertionSort::sortFloat(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 3 && doubleDataArray != nullptr)
            {
                double *tempArray = new double[sizeOfArray];
                copy(doubleDataArray,doubleDataArray+sizeOfArray,tempArray);

                printData(tempArray, sizeOfArray);
                startCounter();
                InsertionSort::sortDouble(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 4 && charDataArray != nullptr)
            {
                char *tempArray = new char[sizeOfArray];
                copy(charDataArray,charDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                InsertionSort::sortChar(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else
                cout<<"Brak danych"<<endl;


        }
        else if(action == 3) //     SORTOWANIE PRZEZ KOPCOWANIE - WYWOŁANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie przez kopcowanie"<<endl;

            double algoTime = 0.0;

            if(type == 1 && intDataArray != nullptr)
            {
                int *tempArray = new int[sizeOfArray];
                copy(intDataArray,intDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                HeapSort::sortInt(tempArray,sizeOfArray);
                algoTime = getCounter();
                printData(tempArray,sizeOfArray);
                checkData(tempArray,sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 2 && floatDataArray != nullptr)
            {
                float *tempArray = new float[sizeOfArray];
                copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                HeapSort::sortFloat(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 3 && doubleDataArray != nullptr)
            {
                double *tempArray = new double[sizeOfArray];
                copy(doubleDataArray,doubleDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                HeapSort::sortDouble(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 4 && charDataArray != nullptr)
            {
                char *tempArray = new char[sizeOfArray];
                copy(charDataArray,charDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                HeapSort::sortChar(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else
                cout<<"Brak danych"<<endl;

        }
        else if(action == 4) //     SORTOWANIE SZYBKIE - WYWOŁANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie szybkie"<<endl;
            double algoTime = 0.0;

            if(type == 1 && intDataArray != nullptr)
            {
                int *tempArray = new int[sizeOfArray];
                copy(intDataArray,intDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                QuickSort::sortInt(tempArray,sizeOfArray);
                algoTime = getCounter();
                printData(tempArray,sizeOfArray);
                checkData(tempArray,sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 2 && floatDataArray != nullptr)
            {
                float *tempArray = new float[sizeOfArray];
                copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                QuickSort::sortFloat(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 3 && doubleDataArray != nullptr)
            {
                double *tempArray = new double[sizeOfArray];
                copy(doubleDataArray,doubleDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                QuickSort::sortDouble(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 4 && charDataArray != nullptr)
            {
                char *tempArray = new char[sizeOfArray];
                copy(charDataArray,charDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                QuickSort::sortChar(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else
                cout<<"Brak danych"<<endl;
        }
        else if(action == 5) //     SORTOWANIE SHELLA - WYWOŁANIE,POMIAR CZASU,SPRAWDZENIE POPRAWNOŚCI
        {
            cout<<"Sortowanie Shella"<<endl;
            double algoTime = 0.0;

            if(type == 1 && intDataArray != nullptr)
            {
                int *tempArray = new int[sizeOfArray];
                copy(intDataArray,intDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                ShellSort::sortInt(tempArray,sizeOfArray);
                algoTime = getCounter();
                printData(tempArray,sizeOfArray);
                checkData(tempArray,sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 2 && floatDataArray != nullptr)
            {
                float *tempArray = new float[sizeOfArray];
                copy(floatDataArray,floatDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                ShellSort::sortFloat(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 3 && doubleDataArray != nullptr)
            {
                double *tempArray = new double[sizeOfArray];
                copy(doubleDataArray,doubleDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                ShellSort::sortDouble(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else if(type == 4 && charDataArray != nullptr)
            {
                char *tempArray = new char[sizeOfArray];
                copy(charDataArray,charDataArray+sizeOfArray,tempArray);
                printData(tempArray, sizeOfArray);
                startCounter();
                ShellSort::sortChar(tempArray, sizeOfArray);
                algoTime = getCounter();
                printData(tempArray, sizeOfArray);

                cout<<endl<<"Czas działania: "<<algoTime<<endl;
                if(checkData(tempArray,sizeOfArray))
                {
                    cout<<endl<<"Sortowanie -> OK"<<endl<<endl;
                }
                else
                    cout<<endl<<"Sortowanie -> FAILED"<<endl<<endl;

                delete[] tempArray;
            }
            else
                cout<<"Brak danych"<<endl;

        }
        else if(action == 6) // WCZYTANIE DANYCH Z PLIKU
        {

            if(type == 1)
            {
                intDataArray = new int[sizeOfArray];
                readData(intDataArray);
                printData(intDataArray,sizeof(intDataArray));

            }
            else if(type == 2)
            {
                floatDataArray = new float[sizeOfArray];
                readData(floatDataArray);
                printData(floatDataArray,sizeof(floatDataArray));
            }
            else if(type == 3)
            {
                doubleDataArray = new double[sizeOfArray];
                readData(doubleDataArray);
                printData(doubleDataArray,sizeof(doubleDataArray));
            }
            else
            {
                charDataArray = new char[sizeOfArray];
                readData(charDataArray);
                printData(charDataArray,sizeof(charDataArray));
            }

        }
        else if(action == 7) // PEŁNE TESTOWANIE Z POWTÓRZENIEM 100 RAZY, POMIAR CZASU ŚREDNIEGO, SPRAWDZENIE POPRAWNOŚCI SORTOWANIA
        {
            cout<<"Podaj rozmiar danych: ";
            cin>>sizeOfArray;

            if(sizeOfArray < 0 || cin.fail())
            {
                cin.clear();
                cin.ignore();

                cout<<"Błąd danych! \n\n";
                break;
            }

            testSorting();
        }


    }
}

void generateRandomData()
{
    GenerateData generateData;

    if(type == 1)
    {
        intDataArray = GenerateData::generateInt(sizeOfArray);
        printData(intDataArray, sizeOfArray);

    }
    else if(type == 2)
    {
        floatDataArray = GenerateData::generateFloat(sizeOfArray);
        printData(floatDataArray, sizeOfArray);
    }
    else if(type == 3)
    {
        doubleDataArray = GenerateData::generateDouble(sizeOfArray);
        printData(doubleDataArray, sizeOfArray);
    }
    else
    {
        charDataArray = GenerateData::generateChar(sizeOfArray);
        printData(charDataArray, sizeOfArray);
    }
}

void generateSortedData(int flag)
{
    GenerateSortedData sortedData(flag);

    if(type == 1)
    {
        intDataArray = GenerateSortedData::generateInt(sizeOfArray);
        printData(intDataArray, sizeOfArray);

    }
    else if(type == 2)
    {
        floatDataArray = GenerateSortedData::generateFloat(sizeOfArray);
        printData(floatDataArray, sizeOfArray);
    }
    else if(type == 3)
    {
        doubleDataArray = GenerateSortedData::generateDouble(sizeOfArray);
        printData(doubleDataArray, sizeOfArray);

    }
    else
    {
        charDataArray = GenerateSortedData::generateChar(sizeOfArray);
        printData(charDataArray, sizeOfArray);
    }
}

void generatePartialySortedData(int part)
{
    GeneratePartialySortedData partialySortedData(part);

    if(type == 1)
    {
        intDataArray = GeneratePartialySortedData::generateInt(sizeOfArray);
        printData(intDataArray, sizeOfArray);

    }
    else if(type == 2)
    {
        floatDataArray = GeneratePartialySortedData::generateFloat(sizeOfArray);
        printData(floatDataArray, sizeOfArray);
    }
    else if(type == 3)
    {
        doubleDataArray = GeneratePartialySortedData::generateDouble(sizeOfArray);
        printData(doubleDataArray, sizeOfArray);

    }
    else
    {
        charDataArray = GeneratePartialySortedData::generateChar(sizeOfArray);
        printData(charDataArray, sizeOfArray);
    }
}

void readData(auto array)
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


void getDataType() // FUNKCJA PYTAJĄCA O TYP DANYCH WEJŚCIOWYCH
{
    type = 0;

    while (true)
    {
        cout << "Prosze podac typ testowanych danych: \n1. Int\n2. Float\n3. Double\n4. Char" << endl;
        cin >> type;

        if(cin.fail())
        {
            cout << "Blad danych wejsciowych\n";
            cin.clear();
            cin.ignore();
        }
        else if(type != 1 && type != 2 && type != 3 && type != 4)
        {
            cout<<"Nieprawidlowy numer funkcji\n";
            cin.clear();
            cin.ignore();
        }
        else
            break;

    }

}



void testDouble(int *passCounter, double *timeCounter, int gentype)
{
    double *tab = new double [sizeOfArray];
    double *p1 = new double [sizeOfArray];
    double *p2 = new double [sizeOfArray];
    double *p3 = new double [sizeOfArray];
    double *p4 = new double [sizeOfArray];

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
            tab = GenerateData::generateDouble(sizeOfArray);
        } else if (gentype == 2) {
            tab = GenerateSortedData::generateDouble(sizeOfArray);
        } else if (gentype == 3) {
            tab = GenerateSortedData::generateDouble(sizeOfArray);
        } else if (gentype == 4) {
            tab = GeneratePartialySortedData::generateDouble(sizeOfArray);
        } else if (gentype == 5) {
            tab = GeneratePartialySortedData::generateDouble(sizeOfArray);
        }


        copy(tab, tab + sizeOfArray, p1);
        copy(tab, tab + sizeOfArray, p2);
        copy(tab, tab + sizeOfArray, p3);
        copy(tab, tab + sizeOfArray, p4);

        startCounter();
        InsertionSort::sortDouble(p1, sizeOfArray);
        timeCounter[0] += getCounter();

        if (checkData(p1, sizeOfArray) == 1)
            passCounter[0]--;

        startCounter();
        HeapSort::sortDouble(p2, sizeOfArray);
        timeCounter[1] += getCounter();

        if (checkData(p2, sizeOfArray) == 1)
            passCounter[1]--;

        startCounter();
        QuickSort::sortDouble(p3, sizeOfArray);
        timeCounter[2] += getCounter();

        if (checkData(p3, sizeOfArray) == 1)
            passCounter[2]--;

        startCounter();
        ShellSort::sortDouble(p4, sizeOfArray);
        timeCounter[3] += getCounter();

        if (checkData(p4, sizeOfArray) == 1)
            passCounter[3]--;
    }

}
void testChar(int *passCounter, double *timeCounter, int gentype)
{
    char *tab = new char [sizeOfArray];
    char *p1 = new char [sizeOfArray];
    char *p2 = new char [sizeOfArray];
    char *p3 = new char [sizeOfArray];
    char *p4 = new char [sizeOfArray];

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
            tab = GenerateData::generateChar(sizeOfArray);
        } else if (gentype == 2) {
            tab = GenerateSortedData::generateChar(sizeOfArray);
        } else if (gentype == 3) {
            tab = GenerateSortedData::generateChar(sizeOfArray);
        } else if (gentype == 4) {
            tab = GeneratePartialySortedData::generateChar(sizeOfArray);
        } else if (gentype == 5) {
            tab = GeneratePartialySortedData::generateChar(sizeOfArray);
        }


        copy(tab, tab + sizeOfArray, p1);
        copy(tab, tab + sizeOfArray, p2);
        copy(tab, tab + sizeOfArray, p3);
        copy(tab, tab + sizeOfArray, p4);

        startCounter();
        InsertionSort::sortChar(p1, sizeOfArray);
        timeCounter[0] += getCounter();

        if (checkData(p1, sizeOfArray) == 1)
            passCounter[0]--;

        startCounter();
        HeapSort::sortChar(p2, sizeOfArray);
        timeCounter[1] += getCounter();

        if (checkData(p2, sizeOfArray) == 1)
            passCounter[1]--;

        startCounter();
        QuickSort::sortChar(p3, sizeOfArray);
        timeCounter[2] += getCounter();

        if (checkData(p3, sizeOfArray) == 1)
            passCounter[2]--;

        startCounter();
        ShellSort::sortChar(p4, sizeOfArray);
        timeCounter[3] += getCounter();

        if (checkData(p4, sizeOfArray) == 1)
            passCounter[3]--;
    }

}

void testSorting() // FUNKCJA TESTUJĄCA Z POWTÓRZENIEM 100 RAZY, POMIAREM CZASU ŚREDNIEGO, SPRAWDZENIEM POPRAWNOŚCI SORTOWANIA
{
    int n = 100;
    int c = n;

    int * passCounter = new int[4];
    passCounter[0] = n;
    passCounter[1] = n;
    passCounter[2] = n;
    passCounter[3] = n;

    double *timeCounter = new double [4];
    timeCounter[0] = timeCounter[1] = timeCounter[2] = timeCounter[3] = 0;
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

    if(type == 1)
    {
        testInt(passCounter,timeCounter,gentype);
    }
    else if (type == 2)
    {
        testFloat(passCounter,timeCounter,gentype);
    }
    else if (type == 3)
    {
        testDouble(passCounter,timeCounter,gentype);
    }
    else if (type == 4)
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
        cout<<"Quick sort -> OK"<<endl;
    else
        cout<<"Quick sort -> FAIL"<<endl;

    if(passCounter[3] == 0)
        cout<<"Shell sort -> OK"<<endl;
    else
        cout<<"Shell sort -> FAIL"<<endl;
    cout<<endl<<"Sredni czas dzialania algorytmow ("<<c<<" powtorzen) : "<<endl<<endl;
    cout<<"Sortowanie przez wstawianie: "<<timeCounter[0]/100<<endl;
    cout<<"Sortowanie przez kopcowanie: "<<timeCounter[1]/100<<endl;
    cout<<"Sortowanie szybkie: "<<timeCounter[2]/100<<endl;
    cout<<"Sortowanie shella: "<<timeCounter[3]/100<<endl<<endl;

    cout<<"TEST"<<endl;
    startCounter();
    Sleep(1000);
    double test = getCounter();
    cout<<"Dokladnosc zegara (1000): "<<test<<endl<<endl;

    delete[] passCounter;
    delete[] timeCounter;


}

void testFloat(int *passCounter, double *timeCounter, int gentype) {
    float *tab = new float [sizeOfArray];
    float *p1 = new float [sizeOfArray];
    float *p2 = new float [sizeOfArray];
    float *p3 = new float [sizeOfArray];
    float *p4 = new float [sizeOfArray];

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
            tab = GenerateData::generateFloat(sizeOfArray);
        } else if (gentype == 2) {
            tab = GenerateSortedData::generateFloat(sizeOfArray);
        } else if (gentype == 3) {
            tab = GenerateSortedData::generateFloat(sizeOfArray);
        } else if (gentype == 4) {
            tab = GeneratePartialySortedData::generateFloat(sizeOfArray);
        } else if (gentype == 5) {
            tab = GeneratePartialySortedData::generateFloat(sizeOfArray);
        }


        copy(tab, tab + sizeOfArray, p1);
        copy(tab, tab + sizeOfArray, p2);
        copy(tab, tab + sizeOfArray, p3);
        copy(tab, tab + sizeOfArray, p4);

        startCounter();
        InsertionSort::sortFloat(p1, sizeOfArray);
        timeCounter[0] += getCounter();

        if (checkData(p1, sizeOfArray) == 1)
            passCounter[0]--;

        startCounter();
        HeapSort::sortFloat(p2, sizeOfArray);
        timeCounter[1] += getCounter();

        if (checkData(p2, sizeOfArray) == 1)
            passCounter[1]--;

        startCounter();
        QuickSort::sortFloat(p3, sizeOfArray);
        timeCounter[2] += getCounter();

        if (checkData(p3, sizeOfArray) == 1)
            passCounter[2]--;

        startCounter();
        ShellSort::sortFloat(p4, sizeOfArray);
        timeCounter[3] += getCounter();

        if (checkData(p4, sizeOfArray) == 1)
            passCounter[3]--;
    }

}

void testInt(int *passCounter, double *timeCounter, int gentype) {
    int *tab = new int [sizeOfArray];
    int *p1 = new int [sizeOfArray];
    int *p2 = new int [sizeOfArray];
    int *p3 = new int [sizeOfArray];
    int *p4 = new int [sizeOfArray];

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
            tab = GenerateData::generateInt(sizeOfArray);
        } else if (gentype == 2) {
            tab = GenerateSortedData::generateInt(sizeOfArray);
        } else if (gentype == 3) {
            tab = GenerateSortedData::generateInt(sizeOfArray);
        } else if (gentype == 4) {
            tab = GeneratePartialySortedData::generateInt(sizeOfArray);
        } else if (gentype == 5) {
            tab = GeneratePartialySortedData::generateInt(sizeOfArray);
        }


        copy(tab, tab + sizeOfArray, p1);
        copy(tab, tab + sizeOfArray, p2);
        copy(tab, tab + sizeOfArray, p3);
        copy(tab, tab + sizeOfArray, p4);

        startCounter();
        InsertionSort::sortInt(p1, sizeOfArray);
        timeCounter[0] += getCounter();

        if (checkData(p1, sizeOfArray) == 1)
            passCounter[0]--;

        startCounter();
        HeapSort::sortInt(p2, sizeOfArray);
        timeCounter[1] += getCounter();

        if (checkData(p2, sizeOfArray) == 1)
            passCounter[1]--;

        startCounter();
        QuickSort::sortInt(p3, sizeOfArray);
        timeCounter[2] += getCounter();

        if (checkData(p3, sizeOfArray) == 1)
            passCounter[2]--;

        startCounter();
        ShellSort::sortInt(p4, sizeOfArray);
        timeCounter[3] += getCounter();

        if (checkData(p4, sizeOfArray) == 1)
            passCounter[3]--;
    }

}
