myint: myint.o main.o
	g++ -o myint myint.o main.o

main.o: main.cpp myint.h
	g++ -c main.cpp

myint.o: myint.cpp myint.h
	g++ -c myint.cpp

clean: 
	rm *.o myint
