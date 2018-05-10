#ifndef _BLOOMFILTER_HH
#define _BLOOMFILTER_HH

#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>

using namespace std;


class bloomFilter {
	private:
		int size;
		int nHashes;
		vector<bool> bf;
		vector<int>  primes;
	public:
		bloomFilter(int size, int nHashes);

		void addElement(int elem);
		bool findElement(int elem);
		void output();
};

#endif