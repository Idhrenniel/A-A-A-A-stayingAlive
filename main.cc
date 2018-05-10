#include "bloomFilter.hh"
#include <iostream>
#include <fstream>
using namespace std;


int main(){
	cout << "size nhashes" << endl;
	int size, nHashes; cin >> size >> nHashes;

	bloomFilter bf = bloomFilter(size, nHashes);

	//arx 1 -> size    arx 2 -> 2*size
	/*
	cout << "fileName.txt" << endl;
	string fileName, line; cin >> fileName;
	std::ifstream keyFile; keyFile.open(fileName, std::ifstream::in);
	while(getline(keyFile, line)){
		cout << line << endl;
	}*/
}