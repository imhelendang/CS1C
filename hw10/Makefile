FLAGS = -std=c++14 -Wall
CC = g++

all: hw10

hw08: hw10.cpp
	$(CC) $(FLAGS) hw10.cpp -o hw10 

clean:
	rm -f run *.o *~ hw10 hw10.tar hw10.scr 

tar: 
	tar cf hw10.tar hw10.scr Makefile hw10.cpp 