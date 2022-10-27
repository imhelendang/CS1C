FLAGS = -std=c++14 -Wall -g
CC = g++

all: hw06

hw06: hw06.cpp
	$(CC) $(FLAGS) hw06.cpp -o hw06

clean:
	rm -f run *.o *~ hw06 hw06.tar hw06.scr 

tar: 
	tar cf hw06.tar hw06.scr Makefile hw06.cpp