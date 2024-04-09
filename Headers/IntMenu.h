//
// Created by Silver on 10.04.2024.
//

#ifndef AIZO_SORTOWANIE_INTMENU_H
#define AIZO_SORTOWANIE_INTMENU_H


class IntMenu
        {
public:
            IntMenu();
            void showMenu();

private:
    int sizeOfArray;
    int *intDataArray;
    int type;
    double freq;
    long long int counterStart;
    static void printData(auto *tab, int s);
    int checkData(auto *tab,int size);
    double getCounter();
    void startCounter();
    void readData(auto array);
    void generateRandomData();
    void generateSortedData(int flag);
    void generatePartialySortedData(int part);

};


#endif //AIZO_SORTOWANIE_INTMENU_H
