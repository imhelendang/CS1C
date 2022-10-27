FLAGS = -std=c++14 -Wall
CC = g++

all: hw15

hw08: hw15.cpp
	$(CC) $(FLAGS) hw15.cpp -o hw15 

clean:
	rm -f run *.o *~ hw15 hw15.tar hw15.scr 

tar: 
	tar cf hw15.tar hw15.scr Makefile hw15.cpp