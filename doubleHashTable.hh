#ifndef _DOUBLEHASHTABLE_HH
#define _DOUBLEHASHTABLE_HH

#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>



class hashTable {
    private:
        int size;
        std::vector< std::pair <double,int>> firstTable;
        std::vector< std::pair <double,int>> secondTable;

    public:
        hashTable(int size);

        clock_t addElement(int key, int elem);
        int findElement(int key);
        int formkey (int elem);
        void out();
};

#endif