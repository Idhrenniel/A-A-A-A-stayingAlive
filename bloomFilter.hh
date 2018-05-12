#ifndef _BLOOMFILTER_HH
#define _BLOOMFILTER_HH

#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;


class bloomFilter {
	private:
		int size;
		int nHashes;
		vector<bool> bf;
		vector<int>  primes;
	public:
		bloomFilter(int size, int nHashes);

                clock_t addElement(int elem);
		bool findElement(int elem);
		void output();
};

#endif
