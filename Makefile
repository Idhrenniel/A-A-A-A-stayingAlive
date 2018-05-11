makefile: all

all: prog clean

prog: main.o bloomFilter.o binarySearch.o
	g++ -std=c++11 -o prog main.o bloomFilter.o binarySearch.o

main.o: main.cc
	g++ -std=c++11 -c main.cc

bloomFilter.o: bloomFilter.cc
	g++ -std=c++11 -c bloomFilter.cc

binarySearch.o: binarySearch.cc
	g++ -std=c++11 -c binarySearch.cc

clean:
	rm *.o

ultraclean:
	rm *.o *.txt prog