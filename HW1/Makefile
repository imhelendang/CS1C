CFLAGS = -Wall -Werror -Wpedantic -std=gnu99 -O0 -g
CC = g++
OBJECTS = main.o function.o

default: run

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp 

function.o: function.cpp function.h

clean:
	rm -f run *.o *~