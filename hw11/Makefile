FLAGS = -std=c++14 -Wall
CC = g++

all: hw11

hw08: hw11.cpp
	$(CC) $(FLAGS) hw11.cpp -o hw11

clean:
	rm -f run *.o *~ hw11 hw11.tar hw11.scr 

tar: 
	tar cf hw11.tar hw11.scr Makefile hw11.cpp 