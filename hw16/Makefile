FLAGS = -std=c++14 -Wall
CC = g++

all: hw16

hw08: hw16.cpp
	$(CC) $(FLAGS) hw16.cpp -o hw16 

clean:
	rm -f run *.o *~ hw16 hw16.tar hw16.scr 

tar: 
	tar cf hw16.tar hw16.scr Makefile hw16.cpp