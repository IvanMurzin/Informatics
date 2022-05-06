CC=gcc
CFLAGS=-c -std=c99
DIRS=-I./ -Imodel/table -Imodel/keyspace/keyspace1 -Imodel/keyspace/keyspace2 -Imodel/table/item -Iview -Icontroller/keyspace
SOURCES=Errors.h main.c model/table/Table.c model/keyspace/keyspace1/KeySpace1.c model/keyspace/keyspace2/KeySpace2.c model/keyspace/keyspace2/Key2.c model/table/CompositeKey.c model/table/item/Item.c model/table/item/Info.c view/Logger.c controller/keyspace/KeySpace1Controller.c model/keyspace/keyspace1/Item1.c model/keyspace/keyspace1/Key1.c controller/keyspace/IteratorKS1.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program

all: $(SOURCES) $(EXECUTABLE)

.c.o:
	$(CC) $(DIRS) $(CFLAGS) $< -o $@

clean:
	find . -type f -name '*.o' -delete

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@