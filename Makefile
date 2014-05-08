CC=gcc

all: typemachine clean

typemachine: game.o
	$(CC) game.o -o typemachine

game.o: game.c
	$(CC) -c game.c

.PHONY: clean
clean:
	rm -rf *.o
