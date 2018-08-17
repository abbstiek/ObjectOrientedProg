main: main.o flist.o frac.o
	g++ -o main flist.o frac.o  main.o

main.o: main.cpp flist.h frac.h
	g++ -c main.cpp

frac.o: frac.cpp frac.h 
	g++ -c frac.cpp

flist.o: flist.cpp flist.h frac.h
	g++ -c flist.cpp

clean:
	rm -f *.o frac flist *.gch

