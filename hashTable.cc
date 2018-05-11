#include "hashTable.hh"

hashTable::hashTable(int size){
	this->size = size; this->table(size);
}

void addElement(int elem);

bool findElement(int elem);

void output(){
	if(size > 0){
		cout << v[0];
		for(int i=1; i<this->size; ++i) cout << " " << v[i];
		cout << endl;
	}
}