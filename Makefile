TARGET = run
LIBS = -Wall -lSDL2main -lSDL2 -lm -lX11
CFLAGS = -g -Wall -lSDL2 -std=c99

SOURCES = $(wildcard modulos/*.c)
HEADERS = $(wildcard modulos/*.h)
OBJECTS = $(SOURCES:.c=.o)

DESKTOP_ICON = marciano-Default.desktop
BIN_NAME = marciano-game

$(TARGET): $(OBJECTS)
	gcc $(OBJECTS) $(LIBS) -o $@

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJECTS) $(TARGET) record.txt

install: $(TARGET)
	-cp $(TARGET) /usr/bin/$(BIN_NAME)
# TODO Fix the desktop icon as it is not working
	-xdg-desktop-menu install $(DESKTOP_ICON)

uninstall:
	-rm /usr/bin/$(BIN_NAME)
	-xdg-desktop-menu uninstall $(DESKTOP_ICON)