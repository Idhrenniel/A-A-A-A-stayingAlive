#include "binarySearch.hh"
#include "bloomFilter.hh"
#include "hashTable.hh"
#include "hashTableTable.hh"
#include "hashttv2.hh"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int nElemDic;
int nHashes;
clock_t tht = 0;
clock_t tbf = 0;
clock_t thtt = 0;
clock_t thttv2 = 0;
clock_t ttotal;

ifstream arx1, arx2;
ofstream resAdd;
ofstream resBF, resBS, resHT, resHTT, resHTTV2;


void init(){
	cout << "numero de Elementos que formaran parte del diccionario    &    numero de hashes que se realizaran en el Bloom Filter" << endl << "ejemplo  1000    4" << endl;
	cin >> nElemDic >> nHashes;
	//system("python3 randomDictionaryCreator.py 5000 1000");
	string spy = "python3 randomDictionaryCreator.py "+to_string(nElemDic*5)+" "+to_string(nElemDic);
	//cout << spy << endl;
	system(&spy[0u]);
}

void addingElements(bloomFilter* bf, binarySearch* bs, hashTable* hs,hashttv2* httv2){
	//ADDING ELEMENTS
	arx1.open("arxiu1.txt");
	if(arx1.is_open()){
		string lineOfArxiu; int index = 0;
		getline(arx1, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        tbf +=bf->addElement(stoi(lineOfArxiu));
                        bs->addElement(stoi(lineOfArxiu), index);
                        tht += hs->addElement(stod(lineOfArxiu),stoi(lineOfArxiu));
                        thtt += httv2->addElement(stod(lineOfArxiu),stoi(lineOfArxiu),stoi(lineOfArxiu));
			getline(arx1, lineOfArxiu);
			++index;
		}
                resAdd << "la media de ht de añadir es " << tht/nElemDic << " clicks y "<< (((float)tht)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;

                resAdd << "la media de httv2 de añadir es " << thttv2/nElemDic << " clicks y "<< (((float)thttv2)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;

                resAdd << "la media de bf de añadir es " << tbf/nElemDic << " clicks y "<< (((float)tbf)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;
	}
	arx1.close();
}

void addingElementshtt(hashTableTable* htt){
        //ADDING ELEMENTS
        arx1.open("arxiu1.txt");
        if(arx1.is_open()){
                string lineOfArxiu; int index = 0;
                getline(arx1, lineOfArxiu);
                while(lineOfArxiu != "endfile"){
                        thtt += htt->addElement(stod(lineOfArxiu),stod(lineOfArxiu),stoi(lineOfArxiu));
                        getline(arx1, lineOfArxiu);
                        ++index;
                }
                resAdd << "la media de htt de añadir es " << thtt/nElemDic << " clicks y "<< (((float)thtt)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;
        }
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
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
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
                        if(hs->findElement(stoi(lineOfArxiu)) == stoi(lineOfArxiu)) resHT << "ht: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
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

void findHTTV2(hashttv2* httv2){
        //HASHTABLE
    ttotal = 0;
    resHTTV2.open("./results/resultsHTTV2.txt");
    arx2.open("arxiu2.txt");
        if(arx2.is_open()){
                string lineOfArxiu;
                getline(arx2, lineOfArxiu);
                while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(httv2->findElement(stoi(lineOfArxiu),stoi(lineOfArxiu)) == stoi(lineOfArxiu)) resHTTV2 << "httv2: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else resHTTV2 << "httv2: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
                        getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
                }
                resHTTV2 << "la media de httv2 de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
        }
    arx2.close();
    resHTTV2 << endl;
    resHTTV2.close();
}

void findHTT(hashTableTable* htt){
        //HASHTABLE
    ttotal = 0;
    resHTT.open("./results/resultsHTT.txt");
    arx2.open("arxiu2.txt");
        if(arx2.is_open()){
                string lineOfArxiu;
                getline(arx2, lineOfArxiu);
                while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(htt->findElement(stoi(lineOfArxiu),stoi(lineOfArxiu)) == stoi(lineOfArxiu)) resHTT << "htt: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else resHTT << "htt: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
                        getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
                }
                resHTT << "la media de htt de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
        }
    arx2.close();
    resHTT << endl;
    resHTT.close();
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
        hashttv2 httv2 = hashttv2(nElemDic);
        resAdd.open("./results/resultsOfAddingElements.txt");
        addingElements(&bf, &bs, &hs,&httv2);
        if(nElemDic <= 12000) {
            hashTableTable htt = hashTableTable(nElemDic);
            addingElementshtt(&htt);
            findHTT(&htt);

        }
        resAdd.close();

        findBF(&bf);
        findHT(&hs);
        findHTTV2(&httv2);
        findBS(&bs);
}
