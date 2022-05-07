CC=gcc
CFLAGS=-c -std=c99
DIRS=-I./ -Imodel/table -Imodel/keyspace/keyspace1 -Imodel/keyspace/keyspace2 -Imodel/keyspace/item -Imodel/keyspace/key -Imodel/keyspace/keyspace2 -Iview -Icontroller/keyspace
SOURCES=Errors.h main.c model/table/Table.c model/keyspace/keyspace1/KeySpace1.c model/keyspace/keyspace2/KeySpace2.c model/keyspace/key/Key.c model/keyspace/item/Item.c view/Logger.c controller/keyspace/KeySpaceController.c controller/keyspace/IteratorKS.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program

all: $(SOURCES) $(EXECUTABLE)

.c.o:
	$(CC) $(DIRS) $(CFLAGS) $< -o $@

clean:
	find . -type f -name '*.o' -delete

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@