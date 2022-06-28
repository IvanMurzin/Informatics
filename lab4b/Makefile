CC=gcc
CFLAGS=-c -std=c99
DIRS=-Itest -Imodel/tree -Imodel/key -Imodel/item -Imodel/node -Icontroller/graph -Icontroller/dialog
SOURCES=main.c test/test.c model/tree/Tree.c model/item/Item.c controller/graph/GraphGenerator.c controller/dialog/Dialog.c model/key/Key.c model/node/Node.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program

all: $(SOURCES)  $(EXECUTABLE)

.c.o:
	@($(CC) $(DIRS) $(CFLAGS) $< -o $@)

clean:
	find . -type f -name '*.o' -delete

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -lreadline -o $@