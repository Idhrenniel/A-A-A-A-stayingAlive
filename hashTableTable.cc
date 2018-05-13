#include "hashTableTable.hh"



bool Prime(int n){
        for(int i=2; i<sqrt(n); ++i) if(!(n%i)) return false;
        return true;
}

int takePrime(int size){
        int i;
        for(i = size; !Prime(i);i++){
            std::cout << "no es primo" << std::endl;
        }
        return i;
}


hashTableTable::hashTableTable(int size){
    std::cout << "vamos alla" << std::endl;
    this->size = size;
    std::cout << "metimos size" << std::endl;
    std::pair <long,int> aux(-1,-1);
    std::cout << "creamos aux" << std::endl;
    pair aux1(-1,aux);
    std::cout << "creamos aux1" << std::endl;
    std::vector<pair> aux2(size,aux1);
    std::cout << "creamos aux2" << std::endl;
    this->table = std::vector <std::vector<pair>>(size,aux2);
    std::cout << "metimos tablero" << std::endl;
    prime = takePrime(size);
    std::cout << "prime" << std::endl;

}

long hashTableTable::formkey (int elem){
    double n, ir = 1+pow(5,0.5)/2;
    ir = ir*elem;
    double fractir = std::modf(ir,&n);
    for(int i=0;i<8;i++){
      fractir*=10;
    }
    return int(fractir);
}

long hashTableTable::formkey2(int elem){

     return ((elem % prime) % size);
}

clock_t hashTableTable::addElement(long key,long key2, int elem){
    clock_t t;
    t = clock();
    int hash = key%size;
    int hash2 = 0;
    if(table[hash][hash2].first != -1){
            hash2 = key2%size;
            while(table[hash][hash2].first != -1){
                hash2 = (hash2+1)%size;
            }
    }
    table[hash][hash2].first = key;
    table[hash][hash2].second.first = key2;
    table[hash][hash2].second.second = elem;


    t = clock() - t;
    return t;
}

int hashTableTable::findElement(long key,long key2){
    int hash = key%size;
    int hash2 = key2%size;
    for(int x=0;x<table[0].size();x++){
        if(table[hash][hash2].first != -1 && table[hash][hash2].first == key){
                return table[hash][hash2].second.second;
        }
        hash2 = (hash2+1)%size;
    }
    return -1;
}

void hashTableTable::out(){

    for(int i=0;i<table.size();i++){
      for(int j = 0; j<table[0].size();j++){
         std::cout << table[i][j].first << "," << table[i][j].second.first << "/" << table[i][j].second.second << "  ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;

}