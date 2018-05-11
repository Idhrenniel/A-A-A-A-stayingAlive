#include "bloomFilter.hh"

bool isPrime(int n){
	for(int i=2; i<sqrt(n); ++i) if(!(n%i)) return false;
	return true;
}

vector<int> takePrimes(int nHashes, int size){
	int num = 0;
	int i = size;
	vector<int> v(nHashes);
	while(num != nHashes){
		if(isPrime(i)){
			v[num] = i;
			++num;
		}
		++i;
	}
	return v;
}

bloomFilter::bloomFilter(int size, int nHashes){
	this->size = size; this->nHashes = nHashes;
	this->bf = vector<bool>(size, false);
	primes = takePrimes(nHashes, size);
}

int parsingHashFunction(int elem, int prime, int size){
	return ((((elem*elem)+1) % prime) % size);
}

void bloomFilter::addElement(int elem){
	for(int i=0; i<this->nHashes; ++i){
		int indexBloomFilter = parsingHashFunction(elem, primes[i], this->size);
		this->bf[indexBloomFilter] = true;
	}
}

bool bloomFilter::findElement(int elem){
	for(int i=0; i<this->nHashes; ++i){
		int indexBloomFilter = parsingHashFunction(elem, primes[i], this->size);
		if(!bf[indexBloomFilter]) return false;
	}
	return true;
}

void bloomFilter::output(){
	cout << this->bf[0];
	for(int i=1; i<this->size; ++i) cout << " " << this->bf[i];
	cout << endl;
}