temperature:  temperature.o main.o
	g++ -o temperature temperature.o main.o

main.o: main.cpp temperature.h
	g++ -c main.cpp

temperature.o: temperature.cpp temperature.h
	g++ -c temperature.cpp

clean:
	rm *.o temperature
