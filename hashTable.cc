#include "hashTable.hh"



hashTable::hashTable(int size){
    this->size = size;
    std::pair <long,int> aux(-1,-1);
    this->table = std::vector< std::pair <long,int>>(size,aux);

}

long hashTable::formkey (int elem){
    double n, ir = 1+pow(5,0.5)/2;
    ir = ir*elem;
    double fractir = std::modf(ir,&n);
    for(int i=0;i<8;i++){
      fractir*=10;
    }
    return int(fractir);
}

clock_t hashTable::addElement(long key, int elem){
    clock_t t;
    t = clock();
    int hash = formkey(key)%size;
    while(table[hash].first != -1 && table[hash].first != key){
            hash = (hash+1) % size;
    }
    table[hash].first = key;
    table[hash].second = elem;


    t = clock() - t;
    return t;
}

int hashTable::findElement(int key){
    int hash = formkey(key)%size;
    for(int x=0;x<table.size();x++){
        if(table[hash].first != -1 && table[hash].first == key){
                return table[hash].second;
        }
        hash = (hash+1)%size;
    }
    return -1;
}

void hashTable::out(){

    for(int i=0;i<table.size();i++){
        std::cout << table[i].first << "/" << table[i].second << " ";
    }
    std::cout << std::endl;

}
