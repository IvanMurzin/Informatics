CC=gcc
CFLAGS= -c -fPIC -std=c99

SOURCES=StackVector.c StackList.c ../point/Point.c
OBJECTS=$(SOURCES:.c=.o)
DIRS=-I../point
LDFLAGS=-shared

all: $(OBJECTS)

dynamic: $(OBJECTS)
ifdef vector
	@echo 'dynamic vector lib'
	$(CC) StackVector.o ../point/Point.o -shared -o libstackvector.so
else
	@echo 'dynamic list lib'
	$(CC) StackList.o ../point/Point.o -shared -o libstacklist.so
endif

static: $(OBJECTS)
ifdef vector
	@echo 'static vector lib'
	ar rcs stackvector.a StackVector.o ../point/Point.o
else
	@echo 'static list lib'
	ar rcs stacklist.a StackList.o ../point/Point.o
endif

.c.o:
	$(CC) $(DIRS) $(CFLAGS) $< -o $@

