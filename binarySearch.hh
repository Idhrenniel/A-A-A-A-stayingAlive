#ifndef _BINARYSEARCH_HH
#define _BINARYSEARCH_HH

#include <iostream>
#include <vector>

using namespace std;


class binarySearch {
	private:
		int size;

		vector<int> table;
	public:
		binarySearch(int size);

		void addElement(int elem, int index);
		bool findElement(int elem);
		void output();
};


#endif