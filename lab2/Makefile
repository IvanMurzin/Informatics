CC=gcc
CFLAGS= -Iconsole -Ifield -Igame -Imath -Istack -c -std=c99

all: program

program: Color.o KeyboardInput.o ConsoleUtil.o Field.o Game.o Math.o main.o StackVector.o
	$(CC) Color.o KeyboardInput.o ConsoleUtil.o Field.o Game.o Math.o main.o StackVector.o -lreadline -o program

main.o: main.c
	$(CC) $(CFLAGS) main.c

Color.o: console/Color.c
	$(CC) $(CFLAGS) console/Color.c

KeyboardInput.o: console/KeyboardInput.c
	$(CC) $(CFLAGS) console/KeyboardInput.c

ConsoleUtil.o: console/ConsoleUtil.c
	$(CC) $(CFLAGS) console/ConsoleUtil.c

Field.o: field/Field.c
	$(CC) $(CFLAGS) field/Field.c

Game.o: game/Game.c
	$(CC) $(CFLAGS) game/Game.c

Math.o: math/Math.c
	$(CC) $(CFLAGS) math/Math.c
StackVector.o: stack/StackVector.c
	$(CC) $(CFLAGS) stack/StackVector.c

clean:
	rm -rf *.o program
