FLAGS = -std=c++14 -Wall
CC = g++
OBJECTS = doublyLinkedList.o

all: hw14

hw08: hw14.cpp doublyLinkedList.o 
	$(CC) $(FLAGS) hw14.cpp -o hw14 $(OBJECTS)

doublyLinkedList.o: doublyLinkedList.h
	$(CC) $(FLAGS) -o doublyLinkedList.o 

clean:
	rm -f run *.o *~ hw14 hw14.tar hw14.scr 

tar: 
	tar cf hw14.tar hw14.scr Makefile hw14.cpp doublyLinkedList.h 