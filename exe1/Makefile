CC = gcc
CFLAGS = -std=c11 -Wall -g

all: exe1

exe1: exe1.o memory.o stack_over_flow.o divide_by_zero.o
	$(CC) $(CFLAGS) -o exe1 exe1.o memory.o stack_over_flow.o divide_by_zero.o

exe1.o: exe1.c
	$(CC) $(CFLAGS) -c exe1.c

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c

stack_over_flow.o: stack_over_flow.c stack_over_flow.h
	$(CC) $(CFLAGS) -c stack_over_flow.c

divide_by_zero.o: divide_by_zero.c divide_by_zero.h
	$(CC) $(CFLAGS) -c divide_by_zero.c


clean:
	rm -f *.o exe1 core

