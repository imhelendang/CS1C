CFLAGS = -Wall -Werror -Wpedantic -std=gnu99 -O0 -g
CC = g++
OBJECTS = hw02.o cDeck.o card.o

default: run

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

hw02.o: hw02.cpp 

cDeck.o: cDeck.cpp cDeck.h

card.o: card.cpp card.h

clean:
	rm -f run *.o *~ hw02.tar

tar: 
	tar cf hw02.tar hw02.scr Makefile hw02.cpp cDeck.h cDeck.cpp card.h card.cpp