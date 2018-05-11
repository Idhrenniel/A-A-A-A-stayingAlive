#include "binarySearch.hh"

binarySearch::binarySearch(int size){
	this->size = size; this->table = vector<int>(size);
}

void binarySearch::addElement(int elem, int index){
	this->table[index] = elem;
}

bool findElementBinarySearch(int elem, int left, int right, const vector<int>& table){
	int mid =  (left+right)/2;
	if(elem == table[mid]) 	return true;
	if(left >=  right) 		return false;
	if(elem >  table[mid]) 	return findElementBinarySearch(elem, mid+1, right, table);
	if(elem <  table[mid]) 	return findElementBinarySearch(elem, left, mid, table);
}

bool binarySearch::findElement(int elem){
	return findElementBinarySearch(elem, 0, this->size, this->table);
}

void binarySearch::output(){
	cout << this->table[0];
	for(int i=1; i<this->size; ++i) cout << " " << table[i];
	cout << endl;
}