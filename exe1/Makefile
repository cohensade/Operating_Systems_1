CC = gcc
CFLAGS = -std=c11 -Wall

all: main divide_by_zero memory stack_over_flow

main: main.o divide_by_zero.o memory.o stack_over_flow.o
	$(CC) $(CFLAGS) -o main main.o divide_by_zero.o memory.o stack_over_flow.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

divide_by_zero.o: divide_by_zero.c divide_by_zero.h
	$(CC) $(CFLAGS) -c divide_by_zero.c

memory.o: memory.c memory.h
	$(CC) $(CFLAGS) -c memory.c

stack_over_flow.o: stack_over_flow.c stack_over_flow.h
	$(CC) $(CFLAGS) -c stack_over_flow.c

clean:
	rm -f *.o main
