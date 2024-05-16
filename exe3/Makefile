CC = gcc

all: libpoisson.so main

main: main.c Poisson.h libpoisson.so
	$(CC) -o main main.c -L. -lpoisson -lm

libpoisson.so: Poisson.c Poisson.h
	$(CC) -shared -fPIC -o libpoisson.so Poisson.c -lm

.PHONY: all clean


clean:
	$(RM) libpoisson.so main

