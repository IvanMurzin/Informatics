CC=gcc
CFLAGS= -c -fPIC -std=c99

SOURCES=StackVector.c StackList.c ../point/Point.c
OBJECTS=$(SOURCES:.c=.o)
DIRS=-I../point
LDFLAGS=-shared

all: $(OBJECTS) log

dynvector: StackVector.o ../point/Point.o
	$(CC) $(DIRS) StackVector.o ../point/Point.o -shared -o libstackvector.so

dynlist: StackList.o ../point/Point.o
	$(CC) $(DIRS) StackList.o ../point/Point.o -shared -o libstacklist.so

.c.o:
	$(CC) $(DIRS) $(CFLAGS) $< -o $@

