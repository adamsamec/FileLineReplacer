TARGET = bin/regex-replacer
HEADERS = src/*.h
SOURCES = src/*.cpp
CFLAGS = -municode -g -static-libgcc -static-libstdc++ #-Wall -Werror -pedantic -pedantic-errors
CC = g++

.PHONY: run clean

all: $(TARGET)

$(TARGET): main.cpp $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp $(SOURCES)

run: $(TARGET)
	./$(TARGET)

clean:
	rm $(TARGET)

