CC=gcc
CFLAGS=-c -std=c99
DIRS=-Imodel/tree/binary -Icontroller/graph
SOURCES=main.c model/tree/binary/BinaryTree.c model/tree/binary/BNode.c controller/graph/GraphGenerator.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program

all: $(SOURCES)  $(EXECUTABLE)

.c.o:
	@($(CC) $(DIRS) $(CFLAGS) $< -o $@)

clean:
	find . -type f -name '*.o' -delete

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@]