//
// Created by Silver on 10.04.2024.
//

#ifndef AIZO_SORTOWANIE_FLOATMENU_H
#define AIZO_SORTOWANIE_FLOATMENU_H


class FloatMenu
        {
public:
            FloatMenu();
            void showMenu();

private:
    int sizeOfArray;

    float *floatDataArray;

    int type;
    double freq ;
    long long int counterStart;



    void printData(auto *tab,int s);
    int checkData(auto *tab,int size);
    double getCounter();
    void startCounter();
    void readData(auto array);
    void generateRandomData();
    void generateSortedData(int flag);
    void generatePartialySortedData(int part);

};


#endif //AIZO_SORTOWANIE_FLOATMENU_H
