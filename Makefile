TARGET = run
LIBS = -Wall -lSDL2main -lSDL2 -lm -lX11
CFLAGS = -g -Wall -lSDL2 -std=c99

SOURCES = $(wildcard modulos/*.c)
HEADERS = $(wildcard modulos/*.h)
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	gcc $(OBJECTS) $(LIBS) -o $@

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJECTS) $(TARGET) record.txt
