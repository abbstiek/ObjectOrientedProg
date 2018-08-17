student: student.o main.o
	g++ -o student student.o main.o

main.o: main.cpp student.h
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

clean: 
	rm *.o student 
