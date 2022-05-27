CC=gcc
CFLAGS=-c -std=c99
DIRS=-I./ -Imodel/table -Imodel/keyspace/container -Imodel/keyspace/node -Imodel/keyspace/keyspace1 -Imodel/keyspace/keyspace2 -Imodel/table/item -Imodel/keyspace/key -Icontroller/dialog -Iview -Icontroller/iterator
SOURCES=Errors.h main.c model/keyspace/keyspace1/KeySpace1.c model/table/CompositeKey.c model/table/item/Item.c model/keyspace/key/Key.c model/keyspace/node/Node.c model/keyspace/container/Container.c model/keyspace/keyspace2/KeySpace2.c model/table/Table.c view/Logger.c controller/iterator/Iterator.c controller/dialog/Dialog.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program

all: $(SOURCES)  $(EXECUTABLE)

.c.o:
	$(CC) $(DIRS) $(CFLAGS) $< -o $@

clean:
	find . -type f -name '*.o' -delete

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -lreadline -o $@