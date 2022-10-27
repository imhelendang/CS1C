FLAGS = -std=c++14 -Wall -g
CC = g++

all: hw08

hw08: hw08.cpp
	$(CC) $(FLAGS) hw08.cpp -o hw08 

clean:
	rm -f run *.o *~ hw08 hw08.tar hw08.scr 

tar: 
	tar cf hw08.tar hw08.scr Makefile hw08.cpp 