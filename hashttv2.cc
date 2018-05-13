#include "hashttv2.hh"



bool Primev2(int n){
        for(int i=2; i<sqrt(n); ++i) if(!(n%i)) return false;
        return true;
}

int takePrimev2(int size){
        int i;
        for(i = size; !Primev2(i);i++){
        }
        return i;
}


hashttv2::hashttv2(int size){
    this->size = size;
    std::pair <long,int> aux(-1,-1);

    this->table = std::vector <std::pair <long,int>>(size,aux);

    this->table2 = table;

    this->prime = takePrimev2(size);


}

long hashttv2::formkey (int elem){
    double n, ir = 1+pow(5,0.5)/2;
    ir = ir*elem;
    double fractir = std::modf(ir,&n);
    return int(size*fractir);
}

long hashttv2::formkey2(int elem){

     return (elem % prime);
}

clock_t hashttv2::addElement(long key,long key2, int elem){
    clock_t t;
    t = clock();
    int hash = formkey(key);
    int hash2 = 0;
    if(table[hash].first != -1){
            hash2 = formkey2(key2)%size;
            while(table2[hash2].first != -1){

                hash2 = (hash2+1)%size;
            }
            table2[hash2].first = key2;
            table2[hash2].second = elem;
    }
    else {
        table[hash].first = key;
        table[hash].second = elem;
    }
    t = clock() - t;
    return t;
}

int hashttv2::findElement(long key,long key2){
    int hash = formkey(key);
    int hash2 = formkey2(key2)%size;

        if(table[hash].first != -1 && table[hash].first == key){
                return table[hash].second;
        }
        else{
            for(int x=0;x<table2.size();x++){
                if(table2[hash2].first != -1 && table2[hash2].first == key2){
                    return table2[hash2].second;
                }

                hash2 = (hash2+1)%size;
            }
        }
    return -1;
}

void hashttv2::out(){

    for(int i=0;i<table.size();i++){
         std::cout << table[i].first << "/" << table[i].second << "  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    for(int i=0;i<table2.size();i++){
         std::cout << table2[i].first << "/" << table2[i].second << "  ";
    }
    std::cout << std::endl;


}
