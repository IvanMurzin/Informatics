CC=gcc
CFLAGS=-c -std=c99
DIRS=-Imodel/table -Imodel/keyspace/keyspace1 -Imodel/keyspace/keyspace2 -Imodel/keyspace/item -Imodel/keyspace/key -Iview -I./ -Icontroller/iterator -Icontroller/dialog
SOURCES=Errors.h main.c model/table/Table.c model/keyspace/keyspace1/KeySpace1.c model/keyspace/keyspace2/KeySpace2.c model/table/CompositeKey.c model/keyspace/item/Item.c view/Logger.c model/keyspace/key/Key.c controller/iterator/IteratorKS.c model/keyspace/item/Waymark.c controller/dialog/Dialog.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program

all: $(SOURCES)  $(EXECUTABLE)

.c.o:
	$(CC) $(DIRS) $(CFLAGS) $< -o $@

clean:
	find . -type f -name '*.o' -delete

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -lreadline -o $@