CC = cc
CFLAGS = -Wall -Wextra -pedantic
TARGET = timer
SOURCES = timer.c parse.c time_utils.c ui.c

.PHONY: all build run clean

all: build

build: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
