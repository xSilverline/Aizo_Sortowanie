#include <iostream>
#include <cstdlib>
#include "../Headers/GenerateData.h"
#include "../Headers/InsertionSort.h"
#include "../Headers/HeapSort.h"
#include "../Headers/QuickSort.h"
#include "../Headers/ShellSort.h"

using namespace std;

int sizeOfArray = 0;
int *intDataArray;
float *floatDataArray;
double *doubleDataArray;
char *charDataArray;
int type;

void getDataType();
void showMenu();
void printData(auto *tab,int s);
int checkData(auto *tab,int size);
void testSorting();


int main()
{

    cout<<"Ustawienia Wstepne Programu"<<endl;
    getDataType();
    showMenu();


}

void printData(auto *tab,int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<tab[i]<<" ";

    }
    cout<<endl;
}

void showMenu()
{
    int action = 0;
    while(true)
    {
        cout<<"Podaj numer akcji do wykonania:\n";
        cout<<"1. Wygeneruj nowe dane\n2. Sortowanie przez wstawianie\n3. Sortowanie przez kopcowanie\n4. Sortowanie szybkie\n5. Sortowanie Shella\n6. Wczytaj dane z pliku\n";
        cin>>action;
        if(cin.fail())
        {
            cout << "Blad danych wejsciowych\n";
            cin.clear();
            cin.ignore();
        }

        if(action == 1)
        {

            cout<<"Generowanie nowych danych\nPodaj rozmiar tablicy:  ";
            cin>>sizeOfArray;
            if(sizeOfArray < 0 || cin.fail())
            {
                cin.clear();
                cin.ignore();

                cout<<"Błąd danych! \n\n";
                break;
            }
            GenerateData dataGen;

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
//                printData(charDataArray, sizeOfArray);
            }



            cout<<"Wygenerowano!\n\n";

        }
        else if(action == 2)
        {
            cout<<"Sortowanie przez wstawianie\n";



            if(type == 1 && intDataArray != nullptr)
            {
                printData(intDataArray, sizeOfArray);
                InsertionSort::sortInt(intDataArray,sizeOfArray);
                printData(intDataArray,sizeOfArray);
                checkData(intDataArray,sizeOfArray);
            }
            else if(type == 2 && floatDataArray != nullptr)
            {
                printData(floatDataArray, sizeOfArray);
                InsertionSort::sortFloat(floatDataArray, sizeOfArray);
                printData(floatDataArray, sizeOfArray);
            }
            else if(type == 3 && doubleDataArray != nullptr)
            {
                printData(doubleDataArray, sizeOfArray);
                InsertionSort::sortDouble(doubleDataArray, sizeOfArray);
                printData(doubleDataArray, sizeOfArray);
            }
            else if(type == 4 && charDataArray != nullptr)
            {
                printData(charDataArray, sizeOfArray);
                InsertionSort::sortChar(charDataArray, sizeOfArray);
                printData(charDataArray, sizeOfArray);
            }
            else
                cout<<"Brak danych"<<endl;


        }
        else if(action == 3)
        {
            cout<<"Sortowanie przez kopcowanie"<<endl;

            if(type == 1 && intDataArray != nullptr)
            {
                printData(intDataArray, sizeOfArray);
                HeapSort::sortInt(intDataArray,sizeOfArray);
                printData(intDataArray,sizeOfArray);
                checkData(intDataArray,sizeOfArray);
            }
            else if(type == 2 && floatDataArray != nullptr)
            {
                printData(floatDataArray, sizeOfArray);
                HeapSort::sortFloat(floatDataArray, sizeOfArray);
                printData(floatDataArray, sizeOfArray);
            }
            else if(type == 3 && doubleDataArray != nullptr)
            {
                printData(doubleDataArray, sizeOfArray);
                HeapSort::sortDouble(doubleDataArray, sizeOfArray);
                printData(doubleDataArray, sizeOfArray);
            }
            else if(type == 4 && charDataArray != nullptr)
            {
                printData(charDataArray, sizeOfArray);
                HeapSort::sortChar(charDataArray, sizeOfArray);
                printData(charDataArray, sizeOfArray);
            }
            else
                cout<<"Brak danych"<<endl;

        }
        else if(action == 4)
        {
            cout<<"Sortowanie szybkie"<<endl;

            if(type == 1 && intDataArray != nullptr)
            {
                printData(intDataArray, sizeOfArray);
                QuickSort::sortInt(intDataArray,sizeOfArray);
                printData(intDataArray,sizeOfArray);
                checkData(intDataArray,sizeOfArray);
            }
            else if(type == 2 && floatDataArray != nullptr)
            {
                printData(floatDataArray, sizeOfArray);
                QuickSort::sortFloat(floatDataArray, sizeOfArray);
                printData(floatDataArray, sizeOfArray);
            }
            else if(type == 3 && doubleDataArray != nullptr)
            {
                printData(doubleDataArray, sizeOfArray);
                QuickSort::sortDouble(doubleDataArray, sizeOfArray);
                printData(doubleDataArray, sizeOfArray);
            }
            else if(type == 4 && charDataArray != nullptr)
            {
                printData(charDataArray, sizeOfArray);
                QuickSort::sortChar(charDataArray, sizeOfArray);
                printData(charDataArray, sizeOfArray);
            }
            else
                cout<<"Brak danych"<<endl;
        }
        else if(action == 5)
        {
            cout<<"Sortowanie Shella"<<endl;

            if(type == 1 && intDataArray != nullptr)
            {
                printData(intDataArray, sizeOfArray);
                ShellSort::sortInt(intDataArray,sizeOfArray);
                printData(intDataArray,sizeOfArray);
                checkData(intDataArray,sizeOfArray);
            }
            else if(type == 2 && floatDataArray != nullptr)
            {
                printData(floatDataArray, sizeOfArray);
                ShellSort::sortFloat(floatDataArray, sizeOfArray);
                printData(floatDataArray, sizeOfArray);
            }
            else if(type == 3 && doubleDataArray != nullptr)
            {
                printData(doubleDataArray, sizeOfArray);
                ShellSort::sortDouble(doubleDataArray, sizeOfArray);
                printData(doubleDataArray, sizeOfArray);
            }
            else if(type == 4 && charDataArray != nullptr)
            {
                printData(charDataArray, sizeOfArray);
                ShellSort::sortChar(charDataArray, sizeOfArray);
                printData(charDataArray, sizeOfArray);
            }
            else
                cout<<"Brak danych"<<endl;

        }
        else if(action == 6)
        {

        }
        else if(action == 7)
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

int checkData(auto *tab,int size)
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

    if(n == size)
    {
        return 1;
    }

}


void getDataType()
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

void testSorting()
{
    int n = 100;
    int counter1 = n;
    int counter2 = n;
    int counter3 = n;
    int counter4 = n;

    while(n)
    {
        int *tab = GenerateData::generateInt(sizeOfArray);
        int *p1 = new int [sizeOfArray];
        int *p2 = new int [sizeOfArray];
        int *p3 = new int [sizeOfArray];
        int *p4 = new int [sizeOfArray];
        copy(tab,tab+sizeOfArray,p1);
        copy(tab,tab+sizeOfArray,p2);
        copy(tab,tab+sizeOfArray,p3);
        copy(tab,tab+sizeOfArray,p4);

        InsertionSort::sortInt(p1,sizeOfArray);
        if(checkData(p1,sizeOfArray) == 1)
            counter1--;

        HeapSort::sortInt(p2,sizeOfArray);
        if(checkData(p2,sizeOfArray) == 1)
            counter2--;

        QuickSort::sortInt(p3,sizeOfArray);
        if(checkData(p3,sizeOfArray) == 1)
            counter3--;

        ShellSort::sortInt(p4,sizeOfArray);
        if(checkData(p4,sizeOfArray) == 1)
            counter4--;

        n--;

    }

    if(counter1 == 0)
        cout<<"Insertion sort -> OK"<<endl;
    else
        cout<<"Insertion sort -> FAIL"<<endl;

    if(counter2 == 0)
        cout<<"Heap sort -> OK"<<endl;
    else
        cout<<"Heap sort -> FAIL"<<endl;

    if(counter3 == 0)
        cout<<"Quick sort -> OK"<<endl;
    else
        cout<<"Quick sort -> FAIL"<<endl;

    if(counter4 == 0)
        cout<<"Shell sort -> OK"<<endl;
    else
        cout<<"Shell sort -> FAIL"<<endl;

}
