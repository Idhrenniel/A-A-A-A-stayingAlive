#include "bloomFilter.hh"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
	cout << "numeroElementosDiccionario   nhashes  //  1000 " << endl;
	int nElemDic, nHashes; cin >> nElemDic >> nHashes;
	//system("python3 randomDictionaryCreator.py 5000 1000");
	string spy = "python3 randomDictionaryCreator.py "+to_string(nElemDic*5)+" "+to_string(nElemDic);
	//cout << spy << endl;
	system(&spy[0u]);
}