CC = gcc
CFLAGS = -Wall -Wextra -g -fprofile-arcs -ftest-coverage

TARGET = dj

all: exe4

exe4: $(TARGET).c
	$(CC) $(CFLAGS) -o exe4 $(TARGET).c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.gcda *.gcno *.gcov

coverage: $(TARGET)
	./$(TARGET)
	gcov $(TARGET).c

.PHONY: all run clean coverage exe4
