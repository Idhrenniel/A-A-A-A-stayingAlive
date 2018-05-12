#include "binarySearch.hh"
#include "bloomFilter.hh"
#include "hashTable.hh"
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
	hashTable hs = hashTable(nElemDic);

	//ADDING ELEMENTS
        clock_t t = 0;
        clock_t tb = 0;

	ifstream arx1, arx2;
	arx1.open("arxiu1.txt");
	if(arx1.is_open()){
		string lineOfArxiu; int index = 0;
		getline(arx1, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        tb +=bf.addElement(stoi(lineOfArxiu));
                        bs.addElement(stoi(lineOfArxiu), index);
                        t += hs.addElement(hs.formkey(stod(lineOfArxiu)),stoi(lineOfArxiu));
			getline(arx1, lineOfArxiu);
			++index;
		}
                cout << "la media de hs de añadir es " << t/nElemDic << " clicks y "<< (((float)t)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;

                cout << "la media de bf de añadir es " << tb/nElemDic << " clicks y "<< (((float)tb)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;
	}
	arx1.close();
	//BLOOMFILTER

        arx2.open("arxiu2.txt");
        clock_t ttotal = 0;
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(bf.findElement(stoi(lineOfArxiu))) cout << "bf: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else cout << "bf: " << stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
                        tpuntual = clock() - t;
                        ttotal += t;
		}
                cout << "la media de bf de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
	}
	arx2.close();
        cout << endl;
	//bf.output();

	//BINARY SEARCH
	//bs.output();
        /*int elem;
	while(true){
		cin >> elem;
		if(bs.findElement(elem)) cout << "it is" << endl;
		else cout << "it is not" << endl;
	}*/

	//HASHTABLE
        ttotal = 0;
        arx2.open("arxiu2.txt");
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(hs.findElement(hs.formkey(stoi(lineOfArxiu))) != -1) cout << "ht: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else cout << "ht: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
		}
                cout << "la media de hs de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
	}
        arx2.close();

        cout << endl;
        ttotal = 0;
	arx2.open("arxiu2.txt");
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(bs.findElement(stoi(lineOfArxiu))) cout << "bs: " <<stoi(lineOfArxiu) << " it is in the dictionary" << endl;
                        else cout << "bs: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
		}
                cout << "la media de bs de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
	}
        arx2.close();
}


