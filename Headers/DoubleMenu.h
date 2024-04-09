//
// Created by Silver on 09.04.2024.
//

#ifndef AIZO_SORTOWANIE_DOUBLEMENU_H
#define AIZO_SORTOWANIE_DOUBLEMENU_H


class DoubleMenu {
public:
    DoubleMenu();
    void showMenu();

private:
    int sizeOfArray;
    double *doubleDataArray;
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


#endif //AIZO_SORTOWANIE_DOUBLEMENU_H
