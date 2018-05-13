#include "binarySearch.hh"
#include "bloomFilter.hh"
#include "hashTable.hh"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int nElemDic;
int nHashes;
clock_t t = 0;
clock_t tb = 0;
clock_t ttotal;

ifstream arx1, arx2;
ofstream resAdd;
ofstream resBF, resBS, resHT;


void init(){
	cout << "numero de Elementos que formaran parte del diccionario    &    numero de hashes que se realizaran en el Bloom Filter" << endl << "ejemplo  1000    4" << endl;
	cin >> nElemDic >> nHashes;
	//system("python3 randomDictionaryCreator.py 5000 1000");
	string spy = "python3 randomDictionaryCreator.py "+to_string(nElemDic*5)+" "+to_string(nElemDic);
	//cout << spy << endl;
	system(&spy[0u]);
}

void addingElements(bloomFilter* bf, binarySearch* bs, hashTable* hs){
	//ADDING ELEMENTS
	resAdd.open("./results/resultsOfAddingElements.txt");
	arx1.open("arxiu1.txt");
	if(arx1.is_open()){
		string lineOfArxiu; int index = 0;
		getline(arx1, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        tb +=bf->addElement(stoi(lineOfArxiu));
                        bs->addElement(stoi(lineOfArxiu), index);
                        t += hs->addElement(hs->formkey(stod(lineOfArxiu)),stoi(lineOfArxiu));
			getline(arx1, lineOfArxiu);
			++index;
		}
                resAdd << "la media de hs de añadir es " << t/nElemDic << " clicks y "<< (((float)t)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;

                resAdd << "la media de bf de añadir es " << tb/nElemDic << " clicks y "<< (((float)tb)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;
	}
	arx1.close();
	resAdd.close();
}

void findBF(bloomFilter* bf){
	//BLOOMFILTER

	resBF.open("./results/resultsBF.txt");
    arx2.open("arxiu2.txt");
    clock_t ttotal = 0;
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(bf->findElement(stoi(lineOfArxiu))) resBF << "bf: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else resBF << "bf: " << stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
                        tpuntual = clock() - t;
                        ttotal += t;
		}
        resBF << "la media de bf de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
	}
	arx2.close();
    resBF << endl;
    resBF.close();
	//bf.output();
}

void findHT(hashTable* hs){
	//HASHTABLE
    ttotal = 0;
    resHT.open("./results/resultsHT.txt");
    arx2.open("arxiu2.txt");
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(hs->findElement(hs->formkey(stoi(lineOfArxiu))) != -1) resHT << "ht: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else resHT << "ht: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
		}
                resHT << "la media de hs de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
	}
    arx2.close();
    resHT << endl;
    resHT.close();
}

void findBS(binarySearch* bs){
	//BINARYSEARCH
    ttotal = 0;
    resBS.open("./results/resultsBS.txt");
	arx2.open("arxiu2.txt");
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(bs->findElement(stoi(lineOfArxiu))) resBS << "bs: " <<stoi(lineOfArxiu) << " it is in the dictionary" << endl;
                        else resBS << "bs: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
		}
                resBS << "la media de bs de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
	}
    arx2.close();
    resBS.close();
}

int main(){

	init();
	bloomFilter bf = bloomFilter(nElemDic*10, nHashes);
	binarySearch bs = binarySearch(nElemDic);
	hashTable hs = hashTable(nElemDic);

	addingElements(&bf, &bs, &hs);

	findBF(&bf);
	findHT(&hs);
	findBS(&bs);
}


