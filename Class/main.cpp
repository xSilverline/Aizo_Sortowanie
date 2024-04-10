#include <iostream>


#include "../Headers/IntMenu.h"
#include "../Headers/FloatMenu.h"
#include "../Headers/DoubleMenu.h"
#include "../Headers/CharMenu.h"

using namespace std;


void getDataType();



int main()
{
    cout<<"Ustawienia Wstepne Programu"<<endl;
    getDataType();

}


void getDataType() // FUNKCJA PYTAJĄCA O TYP DANYCH WEJŚCIOWYCH
{
    int type = 0;

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

    if(type == 1)
    {
        IntMenu menu;
        menu.showMenu();
    }
    else if(type == 2)
    {
        FloatMenu menu;
        menu.showMenu();
    }
    else if(type == 3)
    {
        DoubleMenu menu;
        menu.showMenu();
    }
    else if(type == 4)
    {
        CharMenu menu;
        menu.showMenu();
    }

}





