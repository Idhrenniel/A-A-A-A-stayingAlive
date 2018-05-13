makefile: all

all: prog clean result

prog: main2.o bloomFilter.o binarySearch.o hashTable.o hashTableTable.o hashttv2.o
	g++ -std=c++11 -o prog main2.o bloomFilter.o binarySearch.o hashTable.o hashTableTable.o hashttv2.o

main2.o: main2.cc
	g++ -std=c++11 -c main2.cc

bloomFilter.o: bloomFilter.cc
	g++ -std=c++11 -c bloomFilter.cc

binarySearch.o: binarySearch.cc
	g++ -std=c++11 -c binarySearch.cc

hashTable.o: hashTable.cc
	g++ -std=c++11 -c hashTable.cc

hashTableTable.o: hashTableTable.cc
	g++ -std=c++11 -c hashTableTable.cc

hashttv2.o: hashttv2.cc
	g++ -std=c++11 -c hashttv2.cc

clean:
	rm *.o

result:
	mkdir results

ultraclean:
	rm *.o *.txt prog
