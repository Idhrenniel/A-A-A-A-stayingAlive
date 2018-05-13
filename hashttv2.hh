#ifndef _HASHTTV2_HH
#define _HASHTTV2_HH

#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>


class hashttv2 {
    private:
        int size;
        std::vector<std::pair<long,int>> table;
        std::vector<std::pair<long,int>> table2;
        int prime;

    public:
        hashttv2(int size);

        clock_t addElement(long key, long key2, int elem);
        int findElement(long key, long key2);
        long formkey(int elem);
        long formkey2(int elem);
        void out();
};

#endif
