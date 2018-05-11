#include "binarySearch.hh"
#include "bloomFilter.hh"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
	cout << "numero de Elementos que formaran parte del diccionario    &    numero de hashes" << endl << "ejemplo  1000    4" << endl;
	int nElemDic, nHashes; cin >> nElemDic >> nHashes;
	//system("python3 randomDictionaryCreator.py 5000 1000");
	string spy = "python3 randomDictionaryCreator.py "+to_string(nElemDic*5)+" "+to_string(nElemDic);
	//cout << spy << endl;
	system(&spy[0u]);


	bloomFilter  bf = bloomFilter(nElemDic*10, nHashes);
	binarySearch bs = binarySearch(nElemDic);

	//ADDING ELEMENTS

	ifstream arx1, arx2;
	arx1.open("arxiu1.txt");
	if(arx1.is_open()){
		string lineOfArxiu; int index = 0;
		getline(arx1, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
			bf.addElement(stoi(lineOfArxiu));
			bs.addElement(stoi(lineOfArxiu), index);
			getline(arx1, lineOfArxiu);
			++index;
		}
	}
	arx1.close();
	
	//BLOOMFILTER
	/*
	arx2.open("arxiu2.txt");
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
			if(bf.findElement(stoi(lineOfArxiu))) cout << stoi(lineOfArxiu) << " can be in the dictionary" << endl;
			else cout << stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
		}
	}
	arx2.close();
	//bf.output();
	*/
	//BINARY SEARCH
	//bs.output();
	/*int elem;
	while(true){
		cin >> elem;
		if(bs.findElement(elem)) cout << "it is" << endl;
		else cout << "it is not" << endl;
	}*/
	arx2.open("arxiu2.txt");
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
			if(bs.findElement(stoi(lineOfArxiu))) cout << stoi(lineOfArxiu) << " it is in the dictionary" << endl;
			else cout << stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
		}
	}
	arx2.close();
}