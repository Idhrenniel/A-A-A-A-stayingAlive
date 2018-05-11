makefile: all

all: prog clean

prog: main.o bloomFilter.o
	g++ -std=c++11 -o prog main.o bloomFilter.o

main.o: main.cc
	g++ -std=c++11 -c main.cc

bloomFilter.o: bloomFilter.cc
	g++ -std=c++11 -c bloomFilter.cc

clean:
	rm *.o

ultraclean:
	rm *.o *.txt prog