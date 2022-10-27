FLAGS = -std=c++14 -Wall
CC = g++
OBJECTS = queue.o

all: hw13

hw08: hw13.cpp queue.o
	$(CC) $(FLAGS) hw13.cpp -o hw13 $(OBJECTS)

queue.o: queue.h
	$(CC) $(FLAGS) -o queue.o 

clean:
	rm -f run *.o *~ hw13 hw13.tar hw13.scr 

tar: 
	tar cf hw13.tar hw13.scr Makefile hw13.cpp queue.h