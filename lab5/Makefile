CC=gcc
CFLAGS=-c -std=c99
DIRS=-Icontroller/dialog -Icontroller/graph -Imodel/container -Imodel/edge -Imodel/matrix -Imodel/node -Imodel/vertex -Iview
SOURCES=main.c model/matrix/Matrix.c model/vertex/Vertex.c model/container/Container.c view/Logger.c model/edge/Edge.c controller/graph/GraphGenerator.c model/node/Node.c  controller/dialog/Dialog.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=program

all: $(SOURCES)  $(EXECUTABLE)

.c.o:
	@($(CC) $(DIRS) $(CFLAGS) $< -o $@)

clean:
	find . -type f -name '*.o' -delete

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -lm -o $@