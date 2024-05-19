CC = gcc
CFLAGS = -Wall -Wextra -g -fprofile-arcs -ftest-coverage

TARGET = dj

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.gcda *.gcno *.gcov

coverage: $(TARGET)
	./$(TARGET)
	gcov $(TARGET).c

.PHONY: all run clean coverage
