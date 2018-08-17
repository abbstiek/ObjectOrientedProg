bitarray: main7.o bitarray.o
	g++ -o bitarray main7.o bitarray.o

main7.o: main7.cpp bitarray.h sieve.h
	g++ -o main7.o -c main7.cpp

bitarray.o: bitarray.cpp bitarray.h
	g++ -c bitarray.cpp

clean: 	rm -f *.o bitarray
