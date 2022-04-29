CC=gcc
CFLAGS=-c -std=c99
LDFLAGS=-lreadline
LIBFLAGS=-Llib -Wl,-Rlib
DIRS=-Iconsole -Ifield -Igame -Ipoint -Istack
SOURCES=main.c game/Game.c console/ConsoleUtil.c field/Field.c console/Color.c console/KeyboardInput.c point/Point.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program
LIBS=libs

all: $(SOURCES) $(EXECUTABLE)

.c.o:
	$(CC) $(DIRS) $(CFLAGS) $< -o $@

clean:
	find . -type f -name '*.o' -delete

$(EXECUTABLE): $(OBJECTS)
ifdef vector
	@echo 'dynamic vector build'
	make -C lib dynamic vector=1
	$(CC) $(OBJECTS) $(LDFLAGS) $(LIBFLAGS) -lstackvector -o $@
else
	@echo 'dynamic list build'
	make -C lib dynamic
	$(CC) $(OBJECTS) $(LDFLAGS) $(LIBFLAGS) -lstacklist -o $@
endif


static: $(OBJECTS)
ifdef vector
	@echo 'static vector build'
	make -C lib static vector=1
	$(CC) $(OBJECTS) $(LDFLAGS) lib/stackvector.a -o program
else
	@echo 'static list build'
	make -C lib static
	$(CC) $(OBJECTS) $(LDFLAGS) lib/stacklist.a -o program
endif
