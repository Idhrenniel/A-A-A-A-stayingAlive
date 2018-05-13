#ifndef _HASHTABLETABLE_HH
#define _HASHTABLETABLE_HH

#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>

typedef std::pair<long,std::pair<long,int>> pair;

class hashTableTable {
    private:
        int size;
        std::vector< std::vector <std::pair<long,std::pair<long,int>>>> table;
        int prime;

    public:
        hashTableTable(int size);

        clock_t addElement(long key, long key2, int elem);
        int findElement(long key, long key2);
        long formkey(int elem);
        long formkey2(int elem);
        void out();
};

#endif
