FLAGS = -std=c++14 -Wall -g
CC = g++
OBJECTS = date.o employee.o programmer.o software.o

all: hw04 

hw04: hw04.cpp date.o employee.o programmer.o software.o
	$(CC) $(FLAGS) hw04.cpp -o hw04 $(OBJECTS)

date.o: date.cpp date.h
	$(CC) $(FLAGS) -c date.cpp -o date.o 

employee.o: employee.cpp employee.h
	$(CC) $(FLAGS) -c employee.cpp -o employee.o

programmer.o: programmer.cpp programmer.h
	$(CC) $(FLAGS) -c programmer.cpp -o programmer.o

software.o: software.cpp software.h
	$(CC) $(FLAGS) -c software.cpp -o software.o

clean:
	rm -f run *.o *~ hw04 hw04.tar

tar: 
	tar cf hw04.tar hw04.scr Makefile hw04.cpp date.h date.cpp employee.h employee.cpp programmer.h programmer.cpp software.h software.cpp text.txt output.txt newOutput.txt