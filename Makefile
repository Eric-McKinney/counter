CC=gcc
CFLAGS=-Wall -O2


counter: counter.o

counter.o: counter.h counter.c

clean: 
	rm counter.o counter