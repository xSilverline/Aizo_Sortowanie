//
// Created by Silver on 10.04.2024.
//

#ifndef AIZO_SORTOWANIE_CHARMENU_H
#define AIZO_SORTOWANIE_CHARMENU_H


class CharMenu {
public:
    CharMenu();
    void showMenu();

private:
    int sizeOfArray;
    char *charDataArray;
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


#endif //AIZO_SORTOWANIE_CHARMENU_H
