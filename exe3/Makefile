CC = gcc

all: libpoisson.so exe3

exe3: main.c Poisson.h libpoisson.so
	$(CC) -o exe3 main.c -L. -lpoisson -lm

libpoisson.so: Poisson.c Poisson.h
	$(CC) -shared -fPIC -o libpoisson.so Poisson.c -lm

.PHONY: all clean


clean:
	$(RM) libpoisson.so main exe3

