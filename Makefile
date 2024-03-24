CC=gcc
CFLAGS=-g -Wall -Wextra
SDLFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf -I/opt/local/include -L/opt/local/lib

main: main.o graphe.o sdl.o
	${CC} ${CFLAGS} main.o graphe.o sdl.o -o main ${SDLFLAGS}
main.o: main.c
	${CC} ${CFLAGS} main.c -c
graphe.o: graphe.c
	${CC} ${CFLAGS} graphe.c -c
sdl.o: sdl.c
	${CC} ${CFLAGS} sdl.c -c ${SDLFLAGS}

clean:
	rm -f *.o *.gch
