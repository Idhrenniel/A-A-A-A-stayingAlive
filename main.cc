#include "binarySearch.hh"
#include "bloomFilter.hh"
#include "hashTable.hh"
#include "hashTableTable.hh"
#include "hashttv2.hh"
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
        hashTable ht = hashTable(nElemDic);
        if(nElemDic < 12000) hashTableTable htt = hashTableTable(nElemDic);
        hashttv2 httv2 = hashttv2(nElemDic);

	//ADDING ELEMENTS
        clock_t tbs = 0;
        clock_t tbf = 0;
        clock_t tht = 0;
        clock_t thtt = 0;
        clock_t thttv2 = 0;

	ifstream arx1, arx2;
	arx1.open("arxiu1.txt");
	if(arx1.is_open()){
		string lineOfArxiu; int index = 0;
		getline(arx1, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        /*tbf +=bf.addElement(stoi(lineOfArxiu));
                        tbs +=bs.addElement(stoi(lineOfArxiu), index);
                        tht += ht.addElement(stod(lineOfArxiu),stoi(lineOfArxiu));

                        thtt += htt.addElement(stod(lineOfArxiu),stod(lineOfArxiu),stod(lineOfArxiu));*/

                    thttv2 += httv2.addElement(stod(lineOfArxiu),stod(lineOfArxiu),stod(lineOfArxiu));


			getline(arx1, lineOfArxiu);
                        ++index;
		}
                cout << "la media de bs de añadir es " << tbs/nElemDic << " clicks y "<< (((float)tbs)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;

                cout << "la media de ht de añadir es " << tht/nElemDic << " clicks y "<< (((float)tht)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;
                if(nElemDic < 12000) cout << "la media de htt de añadir es " << thtt/nElemDic << " clicks y "<< (((float)thtt)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;
                cout << "la media de httv2 de añadir es " << thttv2/nElemDic << " clicks y "<< (((float)thttv2)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;

                cout << "la media de bf de añadir es " << tbf/nElemDic << " clicks y "<< (((float)tbf)/CLOCKS_PER_SEC)/nElemDic<< " segundos." << endl;
	}


	arx1.close();
        clock_t ttotal = 0;
	//BLOOMFILTER

        /*arx2.open("arxiu2.txt");
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
        /*ttotal = 0;
        arx2.open("arxiu2.txt");
	if(arx2.is_open()){
		string lineOfArxiu;
		getline(arx2, lineOfArxiu);
		while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(ht.findElement(stoi(lineOfArxiu)) == elem) cout << "ht: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else cout << "ht: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
			getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
		}
                cout << "la media de ht de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
	}
        arx2.close();*/

        //HASHTABLETABLE
        if(nElemDic < 12000){/*ttotal = 0;
        arx2.open("arxiu2.txt");
        if(arx2.is_open()){
                string lineOfArxiu;
                getline(arx2, lineOfArxiu);
                while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(htt.findElement(stod(lineOfArxiu),stod(lineOfArxiu)) == stod(lineOfArxiu))  cout << "htt: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else cout << "htt: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
                        getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
                }
                cout << "la media de htt de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
        }
        arx2.close();*/
        }


        //HASHTTV2
        ttotal = 0;
        arx2.open("arxiu2.txt");
        if(arx2.is_open()){
                string lineOfArxiu;
                getline(arx2, lineOfArxiu);
                while(lineOfArxiu != "endfile"){
                        clock_t tpuntual;
                        tpuntual = clock();
                        if(httv2.findElement(stod(lineOfArxiu),stod(lineOfArxiu)) == stod(lineOfArxiu))  cout << "httv2: "<< stoi(lineOfArxiu) << " can be in the dictionary" << endl;
                        else cout << "httv2: "<< stoi(lineOfArxiu) << " is not in the dictionary" << endl;
                        getline(arx2, lineOfArxiu);
                        tpuntual = clock() - tpuntual;
                        ttotal += tpuntual;
                }
                cout << "la media de httv2 de buscar es " << ttotal/nElemDic << " clicks y "<< ((((float)ttotal)/CLOCKS_PER_SEC)/nElemDic)*100<< " milisegundos." << endl;
        }
        arx2.close();



        /*cout << endl;
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
        arx2.close();*/
}
