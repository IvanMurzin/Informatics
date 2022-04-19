CC=gcc
CFLAGS= -c -fPIC -std=c99

all: libstackvector libstacklist



libstackvector: StackVector.o
	$(CC) StackVector.o -shared -o libstackvector.so

libstacklist: StackList.o
	$(CC) StackList.o -shared -o libstacklist.so

StackVector.o: StackVector.c
	$(CC) $(CFLAGS) StackVector.c

StackList.o: StackList.c
	$(CC) $(CFLAGS) StackList.c