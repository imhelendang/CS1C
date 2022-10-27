FLAGS = -std=c++14 -Wall -g
CC = g++
OBJECTS = shape.o triangle.o rectangle.o

all: hw09

hw09: hw09.cpp shape.o triangle.o rectangle.o
	$(CC) $(FLAGS) hw09.cpp -o hw09 $(OBJECTS)

shape.o: shape.h

triangle.o: triangle.cpp triangle.h
	$(CC) $(FLAGS) -c triangle.cpp -o triangle.o 

rectangle.o: rectangle.cpp rectangle.h
	$(CC) $(FLAGS) -c rectangle.cpp -o rectangle.o 

clean:
	rm -f run *.o *~ hw09 hw09.tar hw09.scr 

tar: 
	tar cf hw09.tar hw09.scr Makefile hw09.cpp shape.cpp shape.h triangle.cpp triangle.h rectangle.cpp rectangle.h