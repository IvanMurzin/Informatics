CC=gcc
CFLAGS= -Imodel -Icontroller -c -std=c99

all: program

program: ConsoleController.o IntDynamicArray.o IntHashSet.o Matrix.o main.o
	$(CC) -lreadline ConsoleController.o IntDynamicArray.o IntHashSet.o Matrix.o main.o -o program

main.o: main.c
	$(CC) $(CFLAGS) main.c

ConsoleController.o: controller/ConsoleController.c
	$(CC) $(CFLAGS) controller/ConsoleController.c

IntDynamicArray.o: model/IntDynamicArray.c
	$(CC) $(CFLAGS) model/IntDynamicArray.c

IntHashSet.o: model/IntHashSet.c
	$(CC) $(CFLAGS) model/IntHashSet.c

Matrix.o: model/Matrix.c
	$(CC) $(CFLAGS) model/Matrix.c

clean:
	rm -rf *.o program
