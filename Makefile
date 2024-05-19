CC = gcc
CFLAGS =  -Wall -Wextra -std=c99 -pg 
TARGET = main
SRC = maxsum.c
OBJ = $(SRC:.c=.o)
DEPS = maxsum.h

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

prof: 
	gprof main gmon.out > gprof_report.txt
		

clean:
	rm -f $(OBJ) $(TARGET) gprof_report.txt gmon.out


