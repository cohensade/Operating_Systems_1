CC = gcc
CFLAGS = -std=c11 -Wall -g

all: main

main: main.o memory.o stack_over_flow.o divide_by_zero.o
	$(CC) $(CFLAGS) -o main main.o memory.o stack_over_flow.o divide_by_zero.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c

stack_over_flow.o: stack_over_flow.c stack_over_flow.h
	$(CC) $(CFLAGS) -c stack_over_flow.c

divide_by_zero.o: divide_by_zero.c divide_by_zero.h
	$(CC) $(CFLAGS) -c divide_by_zero.c


clean:
	rm -f *.o main core

