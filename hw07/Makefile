FLAGS = -std=c++14 -Wall -g
CC = g++
OBJECTS = ManageInventory.o

all: hw07

hw07: hw07.cpp ManageInventory.o
	$(CC) $(FLAGS) hw07.cpp -o hw07 $(OBJECTS)

ManageInventory.o: ManageInventory.cpp ManageInventory.h
	$(CC) $(FLAGS) -c ManageInventory.cpp -o ManageInventory.o 

clean:
	rm -f run *.o *~ hw07 hw07.tar hw07.scr 

tar: 
	tar cf hw07.tar hw07.scr Makefile hw07.cpp ManageInventory.cpp ManageInventory.h text.txt