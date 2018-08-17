triangle:  triangle.o main.o
	g++ -o triangle triangle.o main.o

main.o: main.cpp triangle.h
	g++ -c main.cpp

triangle.o: triangle.cpp triangle.h
	g++ -c triangle.cpp

clean:  
	rm *.o triangle
