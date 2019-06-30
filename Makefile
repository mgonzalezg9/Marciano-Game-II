TARGET = run
LIBS = -lSDL2main -lSDL2 -lSDL2_ttf -lm
CFLAGS = -g -Wall -lSDL2 -std=c99

SOURCES = $(wildcard modulos/*.c)
HEADERS = $(wildcard modulos/*.h)

OBJECTS = $(SOURCES:.c=.o)

default: $(TARGET)
all: default

print-%  : ; @echo $* = $($*)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	gcc $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f $(OBJECTS) $(TARGET) record.txt
