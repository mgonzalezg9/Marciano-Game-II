TARGET = run
LIBS = -lSDL2main -lSDL2 -lSDL2_ttf -lm
CC = gcc
CL = g++
CFLAGS = -g -Wall -lSDL2 -std=c99

SOURCES = $(wildcard *.c) $(wildcard */*.c)
HEADERS = $(wildcard *.h) $(wildcard */*.h)

OBJECTS = $(SOURCES:.c=.o)

default: $(TARGET)
all: default

print-%  : ; @echo $* = $($*)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f $(OBJECTS) $(TARGET)
