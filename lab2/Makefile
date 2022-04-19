CC=gcc
CFLAGS= -Iconsole -Ifield -Igame -Imath -Istack -c -std=c99

all: program

program: Color.o KeyboardInput.o ConsoleUtil.o Field.o Game.o Math.o main.o
	$(CC) Color.o KeyboardInput.o ConsoleUtil.o Field.o Game.o Math.o main.o -lreadline -Llib -Wl,-Rlib -lstacklist -o program

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

clean:
	rm -rf *.o program
// не должно быть двух массивов - новая структура данных для координат
// убрать глобальные переменные
// добавить ошибку при вставке
// генерировать поле для пятнашек без запрещенных ситуаций
// makefile не рабоче-крестьянский(добавить общие правила)
// добавить библиотечную компиляцию make -C lib static VECTOR=1