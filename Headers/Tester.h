//
// Created by Silver on 07.04.2024.
//

#ifndef AIZO_SORTOWANIE_TESTER_H
#define AIZO_SORTOWANIE_TESTER_H


class Tester
        {
        public:
            Tester(int s,int t);
            void testSorting();

        private:
            static void testInt(int *passCounter, double *timeCounter,int gentype);
            static void testFloat(int *passCounter, double *timeCounter,int gentype);
            static void testDouble(int *passCounter, double *timeCounter,int gentype);
            static void testChar(int *passCounter, double *timeCounter,int gentype);
            static void startCounter();
            static double getCounter();

};


#endif //AIZO_SORTOWANIE_TESTER_H
