time: time.o main.o
	g++ -o time time.o main.o

main.o: main.cpp time.h
	g++ -c main.cpp

time.o: time.cpp time.h
	g++ -c time.cpp

clean:
	rm *.o time


